// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/UnionFindForest/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Discrete/a_Body.hpp"
#include "../../../Algebra/Monoid/Group/a_Body.hpp"

template <typename T , typename GRAPH , typename U , typename ABEL_GROUP>
AbstractUnionFindForest<T,GRAPH,U,ABEL_GROUP>::AbstractUnionFindForest( GRAPH& G , ABEL_GROUP M ) : m_G( G ) , m_M( move( M ) ) , m_root_size( m_G.size() ) , m_pred( m_root_size ) , m_height( m_root_size , 1 ) , m_w( m_root_size , m_M.Zero() )
{

  const int& size = m_G.size();

  for( int i = 0 ; i < size ; i++ ){

    m_pred[i] = i;

  }

  for( int i = 0 ; i < size ; i++ ){

    auto&& s = m_G.Enumeration( i );

    for( auto& t : m_G.Edge( s ) ){

      Graft( s , t );

    }

  }

}
template <typename U> inline UnionFindForest<U>::UnionFindForest( const int& size ) : AbstractUnionFindForest<int,DiscreteGraph,U,AdditiveGroup<U>>( DiscreteGraph( size ) , AdditiveGroup<U>() ) {}

template <typename T , typename GRAPH , typename U , typename ABEL_GROUP>
const decltype( ( declval<GRAPH>().Enumeration(0) ) ) AbstractUnionFindForest<T,GRAPH,U,ABEL_GROUP>::RootOfNode( const T& t )
{

  auto&& num = m_G.Enumeration_inv( t );
  int& pred1 = m_pred[num];

  while( true ){
    
    int& pred2 = m_pred[pred1];

    if( pred1 == pred2 ){

      break;

    }

    m_w[num] = m_M.Sum( m_w[num] , m_w[pred1] = m_M.Sum( m_w[pred1] , m_w[pred2] ) );
    pred1 = pred2 = m_pred[pred2];

  }

  return m_G.Enumeration( pred1 );

}

template <typename T , typename GRAPH , typename U , typename ABEL_GROUP> template <template <typename...> typename V>
vector<T> AbstractUnionFindForest<T,GRAPH,U,ABEL_GROUP>::GetRoot() const
{

  vector<T> answer{};
  answer.reserve( m_root_size );
  const int& size = m_G.size();

  for( int i = 0 ; i < size ; i++ ){

    if( i == m_pred[i] ){
      
      answer.push_back( m_G.Enumeration( i ) );

    }

  }

  return answer;

}

template <typename T , typename GRAPH , typename U , typename ABEL_GROUP>
U AbstractUnionFindForest<T,GRAPH,U,ABEL_GROUP>::Potential( const T& t0 , const T& t1 )
{

  const T& root0 = RootOfNode( t0 );
  const T& root1 = RootOfNode( t1 );
  assert( root0 == root1 );
  return m_M.Sum( m_w[m_G.Enumeration_inv( t0 )] , m_M.Inverse( m_w[m_G.Enumeration_inv( t1 )] ) );

}

template <typename T , typename GRAPH , typename U , typename ABEL_GROUP> inline const int& AbstractUnionFindForest<T,GRAPH,U,ABEL_GROUP>::size( const bool& node ) const noexcept { return node ? m_G.size() : m_root_size; }

template <typename T , typename GRAPH , typename U , typename ABEL_GROUP>
bool AbstractUnionFindForest<T,GRAPH,U,ABEL_GROUP>::Graft( const T& t0 , const T& t1 , const U& w )
{

  const T& root0 = RootOfNode( t0 );
  const T& root1 = RootOfNode( t1 );

  if( root0 == root1 ){

    return Potential( t0 , t1 ) == w;
    
  }

  auto&& num0 = m_G.Enumeration_inv( t0 );
  auto&& num1 = m_G.Enumeration_inv( t1 );
  auto&& rnum0 = m_G.Enumeration_inv( root0 );
  auto&& rnum1 = m_G.Enumeration_inv( root1 );
  int& height0 = m_height[rnum0];
  const int& height1 = m_height[rnum1];
  const int* p_removed_root;
  const int* p_removed_node;
  const int* p_kept_root;

  if( height0 < height1 ){

    p_removed_root = &rnum0;
    p_removed_node = &num0;
    p_kept_root = &rnum1;
    m_w[*p_removed_root] = m_M.Sum( m_w[*p_removed_root] , m_M.Sum( m_M.Sum( m_w[num1] , w ) , m_M.Inverse( m_w[num0] ) ) );

  } else {

    if( height0 == height1 ){

      height0++;

    }

    p_removed_root = &rnum1;
    p_removed_node = &num1;
    p_kept_root = &rnum0;
    m_w[*p_removed_root] = m_M.Sum( m_w[*p_removed_root] , m_M.Sum( m_M.Inverse( m_M.Sum( m_w[num1] , w ) ) , m_w[num0] ) );

  }

  if( *p_removed_node != *p_removed_root ){

    m_w[*p_removed_node] = m_M.Sum( m_w[*p_removed_node] , m_w[*p_removed_root] );

  }
  
  m_pred[*p_removed_node] = m_pred[*p_removed_root] = *p_kept_root;
  m_root_size--;
  return true;

}

template <typename T , typename GRAPH , typename U , typename ABEL_GROUP> template <typename PATH> inline bool AbstractUnionFindForest<T,GRAPH,U,ABEL_GROUP>::Graft( const T& t0 , const PATH& t1 ) { return Graft( t0 , get<0>( t1 ) , get<1>( t1 ) ); }
