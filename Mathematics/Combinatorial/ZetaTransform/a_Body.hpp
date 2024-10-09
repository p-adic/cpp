// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG> inline VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>::VirtualZetaTransform( GRAPH G , GRAPH_INV G_inv , Z_ALG R ) : m_G( move( G ) ) , m_G_inv( move( G_inv ) ) , m_R( move( R ) ) , m_val( m_G.size() , m_R.Zero() ) { static_assert( is_same_v<T,inner_t<GRAPH>> && is_same_v<T,inner_t<GRAPH_INV>> && is_same_v<U,inner_t<Z_ALG>> ); assert( m_G_inv.size() == m_G.size() ); }
template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG> inline VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>::VirtualZetaTransform( GRAPH G , GRAPH_INV G_inv , Z_ALG R , vector<U> a , const bool& transformed ) : m_G( move( G ) ) , m_G_inv( move( G_inv ) ) , m_R( move( R ) ) , m_val( move( a ) )
{

  static_assert( is_same_v<T,inner_t<GRAPH>> && is_same_v<T,inner_t<GRAPH_INV>> && is_same_v<U,inner_t<Z_ALG>> );
  const int& size = m_G.size();
  assert( m_G_inv.size() == size && int( m_val.size() ) == size );

  if( !transformed ){

    a = m_val;

    for( int i = 0 ; i < size ; i++ ){

      U& m_val_i = m_val[i];
      auto&& sub_i = m_G.Edge( i );

      for( auto& j : sub_i ){

	j == i ? m_val_i : m_val_i = m_R.Sum( move( m_val_i ) , a[j] );

      }

    }

  }

}

template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG , typename MU> template <typename...Args> inline AbstractZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG,MU>::AbstractZetaTransform( GRAPH G , GRAPH_INV G_inv , Z_ALG R , MU mu , Args&&... args ) : VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>( move( G ) , move( G_inv ) , move( R ) , forward<Args>( args )... ) , m_mu( move( mu ) ) { static_assert( is_invocable_r_v<int,MU,const T&,const T&> ); }

template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG>
template <typename...Args> void VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>::Initialise( Args&&... args ) { VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG> temp{ m_G , m_G_inv , m_R , forward<Args>( args )... }; m_val = move( temp.m_val ); }


template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG>
void VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>::Add( const T& t , const U& u ) { auto&& sup = m_G_inv.Edge( t ); for( auto& s : sup ){ U& m_val_i = m_val[m_G.Enumeration_inv( s )]; m_val_i = m_R.Sum( move( m_val_i ) , u ); }  }
template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG> inline void VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>::TotalAdd( const U& u ) { const int& size = m_G.size(); for( int i = 0 ; i < size ; i++ ){ U& m_val_i = m_val[i]; m_val_i = m_R.Sum( move( m_val_i ) , m_R.ScalarProduct( m_G.Edge( m_G.Enumeration( i ) ).size() , u ) ); } }
template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG> inline VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>& VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>::operator+=( const VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>& a ) { const int& size = m_G.size(); for( int i = 0 ; i < size ; i++ ){ U& m_val_i = m_val[i]; m_val_i = Sum( move( m_val_i ) , a.m_val[i] ); } return *this; }

template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG> inline void VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>::TotalMultiply( const U& u ) { const int& size = m_G.size(); for( int i = 0 ; i < size ; i++ ){ U& m_val_i = m_val[i]; m_val_i = m_R.Product( move( m_val_i ) , u ); } }
template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG> inline VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>& VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>::operator*=( const VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>& a ) { const int& size = m_G.size(); for( int i = 0 ; i < size ; i++ ){ U& m_val_i = m_val[i]; m_val_i = m_R.Product( move( m_val_i ) , a.m_val[i] ); } return *this; }

template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG>
U VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>::operator[]( const T& t )
{

  auto&& sub = m_G.Edge( t );
  U answer = m_R.Zero();
  const int& size = m_G.size();

  for( auto& s : sub ){

    auto&& i = m_G.Enumeration_inv( s );
    assert( i < size );
    answer = m_R.Sum( move( answer ) , m_R.ScalarProduct( Moevius( s , t ) , m_val[i] ) );

  }

  return answer;

}

template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG> inline U VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>::Get( const T& t ) { return operator[]( t ); }

template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG> inline const U& VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>::InitialSegmentSum( const T& t ) { auto&& i = m_G.Enumeration_inv( t ); assert( i < m_G.size() ); return m_val[i]; }

template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG> template <typename F_INV_MAX , typename RANGE>
U VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>::InverseImageSum( F_INV_MAX&& f_inv_max , RANGE&& range , const T& s )
{

  static_assert( is_invocable_r_v<T,F_INV_MAX,const T&> && is_invocable_r_v<vector<T>,RANGE,const T&> );
  auto&& t = f_inv_max( s );
  auto&& sub = range( s );
  U answer = m_R.Zero();
  const int& size = m_G.size();

  for( auto& s_sub : sub ){

    auto&& t_sub = f_inv_max( s_sub );
    auto&& i = m_G.Enumeration_inv( t_sub );
    assert( i < size );
    answer = m_R.Sum( move( answer ) , m_R.ScalarProduct( Moevius( s_sub , s ) , m_val[i] ) );

  }

  return answer;

}

template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG> template <typename F_INV_MAX> inline const U& VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>::InitialSegmentInverseImageSum( F_INV_MAX&& f_inv_max , const T& s ) { return m_val[m_G.Enumeration_inv( f_inv_max( s ) )]; }


template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG>
int VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>::Moevius( const T& t0 , const T& t1 )
{

  static vector<unordered_map<int,int>> memory( m_G.size() );
  auto&& i = m_G.Enumeration_inv( t0 );
  auto&& j = m_G.Enumeration_inv( t1 );
  unordered_map<int,int>& memory_t0 = memory[i];
  const bool found = memory_t0.count( j ) == 1;
  int& answer = memory_t0[j];

  if( ! found ){

    if( i == j ){

      answer = 1;

    } else {

      answer = 0;
      auto&& sub = m_G.Edge( t1 );

      for( auto& s : sub ){

	s == t1 ? answer : answer -= Moevius( t0 , s );

      }

    }

  }

  return answer;

}

template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG , typename MU> inline int AbstractZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG,MU>::Moevius( const T& t0 , const T& t1 ) { return m_mu( t0 , t1 ); }

