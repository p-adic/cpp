// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Weighted/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

// ファイル容量削減のため極力vectorの成分を参照するだけの変数を用いない。

template <typename TREE , typename U , typename MONOID> inline DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::DepthFirstSearchOnWeightedTree( TREE& T , MONOID M , const int& root , const int& digit ) :
  DepthFirstSearchOnTree<TREE>( T , root , digit ) , m_M( move( M ) ) , m_wprev( this->size() , m_M.One() ) , m_wdepth_r() , m_wdepth_l() , m_set_wdepth() , m_wheight_max_r() , m_wheight_max_l() , m_wheight_min_r() , m_wheight_min_l() , m_set_wheight() , m_wheaviness() , m_set_wheaviness() , m_wdoubling( this->m_digit ) , m_set_wdoubling()
{

  static_assert( is_same_v<U,inner_t<MONOID>> );
  const int& V = this->size();
  
  for( int i = 0 ; i < V ; i++ ){

    auto&& edge_i = this->m_G.Edge( i );

    for( auto& p : edge_i ){

      const int& j = get<0>( p );

      if( i == this->Parent( j ) ){

	m_wprev[j] = get<1>( p );

      }

    }

  }

}

template <typename TREE , typename U , typename MONOID> inline const U& DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::WDepth( const int& i , const bool& right ) { assert( i < this->size() ); if( !m_set_wdepth ){ SetWDepth(); } return ( right ? m_wdepth_r : m_wdepth_l )[i]; }
template <typename TREE , typename U , typename MONOID> inline const U& DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::WHeight( const int& i , const bool& maximum , const bool& right ) { assert( i < this->size() ); if( !m_set_wheight ){ SetWHeight(); } return ( maximum ? ( right ? m_wheight_max_r : m_wheight_max_l ) : ( right ? m_wheight_min_r : m_wheight_min_l ) )[i]; }
template <typename TREE , typename U , typename MONOID> inline const U& DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::WHeaviness( const int& i ) { assert( i < this->size() ); if( !m_set_wheaviness ){ SetWHeaviness(); } return m_wheaviness[i]; }

template <typename TREE , typename U , typename MONOID>
pair<int,U> DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::WAncestor( int i , int n , const bool& right )
{

  if( ! m_set_wdoubling ){

    SetWDoubling();

  }

  assert( ( n >> this->m_digit ) == 0 );
    
  int d = 0;
  U temp = m_M.One();
  
  while( n != 0 ){

    if( ( n & 1 ) == 1 ){

      auto& [j,u_r,u_l] = m_wdoubling[d][i];
      assert( ( i = j ) != -1 );
      temp = right ? m_M.Product( temp , u_r ) : m_M.Product( u_l , temp );

    }
    
    d++;
    n >>= 1;

  }

  return { i , move( temp ) };

}

template <typename TREE , typename U , typename MONOID> inline tuple<int,U,U> DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::WLCA( int i , int j ) { int i_prev; int j_prev; return WLCA( i , j , i_prev , j_prev ); }

template <typename TREE , typename U , typename MONOID>
tuple<int,U,U> DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::WLCA( int i , int j , int& i_prev , int& j_prev )
{

  i_prev = j_prev = -1;
  const int diff = this->Depth( i ) - this->Depth( j );
  U u_ir = m_M.One();
  U u_jl = u_ir;
  
  if( diff > 0 ){

    auto [k,v] = WAncestor( i , diff - 1 , true );
    u_ir = m_M.Product( v , m_wprev[k] );
    assert( ( i = this->Parent( i_prev = k ) ) != -1 );
    
  } else if( diff < 0 ){

    auto [k,v] = WAncestor( j , - diff - 1 , false );
    u_jl = m_M.Product( m_wprev[k] , v );
    assert( ( j = this->Parent( j_prev = k ) ) != -1 );

  }

  if( i != j ){

    if( !m_set_wdoubling ){

      SetWDoubling();

    }
  
    int d = this->m_digit;

    while( --d >= 0 ){

      auto& [k_i,v_ir,v_il] = m_wdoubling[d][i];
      auto& [k_j,v_jr,v_jl] = m_wdoubling[d][j];

      if( k_i != k_j ){

	assert( ( i = k_i ) != -1 && ( j = k_j ) != -1 );
	u_ir = m_M.Product( u_ir , v_ir );
	u_jl = m_M.Product( v_jl , u_jl );

      }

    }

    u_ir = m_M.Product( u_ir , m_wprev[i] );
    u_jl = m_M.Product( m_wprev[j] , u_jl );
    assert( ( i = this->Parent( i_prev = i ) ) == ( j = this->Parent( j_prev = j ) ) );

  }
  
  return { i , move( u_ir ) , move( u_jl ) };

}

template <typename TREE , typename U , typename MONOID>
void DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::SetWDepth()
{

  assert( !m_set_wdepth );
  m_set_wdepth = true;
  const int& V = this->size();
  const U& one = m_M.One();
  m_wdepth_r.resize( V , one );
  m_wdepth_l.resize( V , one );

  for( int n = 1 ; n < V ; n++ ){

    const int& i = this->m_node_num[n];
    const int& j = this->Parent( i );
    assert( j != -1 );
    m_wdepth_r[i] = m_M.Product( m_wdepth_r[j] , m_wprev[i] );
    m_wdepth_l[i] = m_M.Product( m_wprev[i] , m_wdepth_l[j]  );

  }

  return;

}

template <typename TREE , typename U , typename MONOID>
void DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::SetWHeight()
{

  assert( !m_set_wheight );
  m_set_wheight = true;
  const int& V = this->size();
  const U& one = m_M.One();
  m_wheight_max_r.resize( V , one );
  m_wheight_max_l.resize( V , one );
  m_wheight_min_r.resize( V , one );
  m_wheight_min_l.resize( V , one );
  vector<bool> found( V );
  
  for( int n = V - 1 ; n > 0 ; n-- ){

    const int& i = this->m_node_num[n];
    const int& j = this->Parent( i );
    assert( j != -1 );
    m_wheight_max_r[j] = max( m_wheight_max_r[j] , m_M.Product( m_wheight_max_r[i] , m_wprev[i] ) );
    m_wheight_max_l[j] = max( m_wheight_max_l[j] , m_M.Product( m_wprev[i] , m_wheight_max_l[i] ) );

    if( found[j] ){

      m_wheight_min_r[j] = min( m_wheight_min_r[j] , m_M.Product( m_wheight_min_r[i] , m_wprev[i] ) );
      m_wheight_min_l[j] = min( m_wheight_min_l[j] , m_M.Product( m_wprev[i] , m_wheight_min_l[i] ) );

    } else {

      m_wheight_min_r[j] = m_M.Product( m_wheight_min_r[i] , m_wprev[i] );
      m_wheight_min_l[j] = m_M.Product( m_wprev[i] , m_wheight_min_l[i] );
      found[j] = true;

    }

  }

  return;

}

template <typename TREE , typename U , typename MONOID>
void DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::SetWHeaviness()
{

  assert( !m_set_wheaviness );
  m_set_wheaviness = true;
  const int& V = this->size();
  m_wheaviness.resize( V , m_M.One() );
  
  for( int n = V - 1 ; n > 0 ; n-- ){

    const int& i = this->m_node_num[n];
    const int& j = this->Parent( i );
    assert( j != -1 );
    m_wheaviness[j] = m_M.Product( m_wheaviness[j] , m_M.Product( m_wheaviness[i] , m_wprev[i] ) );

  }

  return;

}

template <typename TREE , typename U , typename MONOID>
void DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::SetWDoubling()
{

  assert( !m_set_wdoubling );
  m_set_wdoubling = true;
  const int& V = this->size();
  
  {
    
    m_wdoubling[0].reserve( V );

    for( int i = 0 ; i < V ; i++ ){

      m_wdoubling[0].push_back( { this->Parent( i ) , m_wprev[i] , m_wprev[i] } );

    }

  }
  
  for( int d = 1 ; d < this->m_digit ; d++ ){

    m_wdoubling[d].reserve( V );

    for( int i = 0 ; i < V ; i++ ){

      auto [j,u_ir,u_il] = m_wdoubling[d-1][i];

      if( j != -1 ){

	auto& [k,v_jr,v_jl] = m_wdoubling[d-1][j];
	j = k;
	u_ir = m_M.Product( u_ir , v_jr );
	u_il = m_M.Product( v_jl , u_il );

      }
      
      m_wdoubling[d].push_back( { j , u_ir , u_il } );

    }

  }

  return;

}

