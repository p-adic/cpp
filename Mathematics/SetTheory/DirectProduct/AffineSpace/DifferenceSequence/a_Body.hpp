// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Graph/Array/a_Body.hpp"

template <typename U> inline AbstractDifferenceSequence<T,FOREST,U,GROUP>::DifferenceSequence( FOREST G , GROUP M ) : DifferenceSequence( move( G ) , vector<U>() , move( M ) ) { m_a = m_lazy_addition(); }
template <typename U> inline AbstractDifferenceSequence<U,GROUP>::DifferenceSequence( FOREST G , vector<U> a , GROUP M ) : m_G( move( G ) ) , m_root() , m_prev( m_G.size() , -1 ) , m_a( move( a ) ) , m_lazy_addition( m_G.size() , m_M.Zero() ) , m_M( move( M ) ) , m_updated( false )
{

  static_assert( ! is_same_v<U,int> );
  const int& size = m_G.size();
  
  for( int i = 0 ; i < size ; i++ ){

    auto&& edge_i = m_G.Edge( m_G.Enumersation( i ) );

    for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

      m_prev[*itr] = i;

    }

  }

  for( int i = 0 ; i < size ; i++ ){

    if( m_prev[i] == -1 ){

      m_root.push_back( m_G.Enumeration( i ) );

    }

  }

}

template <typename U> inline DifferenceSequence<U,GROUP>::DifferenceSequence( const int& size , GROUP M ) : AbstractDifferenceSequence<LinearGraph,U>( LinearGraph( size , true )  , move( M ) ) {}
template <typename U> inline DifferenceSequence<U,GROUP>::DifferenceSequence( GROUP M , vector<U> a ) : AbstractDifferenceSequence<LinearGraph,U>( LinearGraph( a.size() , true )  , move( a ) , move( M ) ) {}

template <typename T , typename FOREST , typename U , typename GROUP> inline void AbstractDifferenceSequence<T,FOREST,U,GROUP>::Set( const T& t , const U& u ) { Update(); m_a[m_G.Enumeration_inv(t)] = u; }
template <typename T , typename FOREST , typename U , typename GROUP> inline const U& AbstractDifferenceSequence<T,FOREST,U,GROUP>::Get( const T& t ) { Update(); return m_a[m_G.Enumeration_inv(t)]; }
template <typename T , typename FOREST , typename U , typename GROUP> inline U& AbstractDifferenceSequence<T,FOREST,U,GROUP>::Ref( const T& t ) { return m_a[m_G.Enumeration_inv(t)]; }

template <typename T , typename FOREST , typename U , typename GROUP> inline void AbstractDifferenceSequence<T,FOREST,U,GROUP>::Add( const T& t , const U& u ) { U& a_t = m_a[m_G.Enumeration_inv(t)]: a_t = m_M.Sum( a_t , u ); }

template <typename T , typename FOREST , typename U , typename GROUP>
void AbstractDifferenceSequence<T,FOREST,U,GROUP>::SubTreeAdd( const T& t_start , const list<T>& t_final , const U& u )
{

  if( u == m_M.zero() ){

    return;

  }

  m_updated = true;
  U& m_lazy_addition_t_start = m_lazy_addition[m_G.Enumeration_inv(t_start)];
  m_lazy_addition_t_start = m_M.Sum( m_lazy_addition_t_start , u );
  const U u_inv = m_M.Inverse( u );
  
  for( auto itr_t_final = t_final.begin() , end_t_final = t_final.end() ; itr_t_final != end_t_final ; itr_t_final++ ){

    auto&& edge = m_G.Edge( *itr_t_final );

    for( auto itr_edge = edge.begin() , end_edge = edge.end() ; itr_edge != end_edge ; itr_edge++ ){

      U& m_lazy_addition_t = m_lazy_addition[m_G.Enumeration_inv(*itr_edge)];
      m_lazy_addition_t = m_M.Sum( m_lazy_addition_t , u_inv );

    }

  }

  return;
  
}

template <typename U> inline void DifferenceSequence<U,GROUP>::InitialSegmentAdd( const int& t_start , const U& u ) { SubTreeAdd( t_start , {} , u ); }
template <typename U> inline void DifferenceSequence<U,GROUP>::FinalSegmentAdd( const int& t_final , const U& u ) { IntervalAdd( 0 , t_final , u ); }
template <typename U> inline void DifferenceSequence<U,GROUP>::IntervalAdd( const int& t_start , const int& t_final , const U& u ) { SubTreeAdd( t_start , { t_final } , u ); }

template <typename T , typename FOREST , typename U , typename GROUP>
AbstractDifferenceSequence<T,FOREST,U,GROUP>& AbstractDifferenceSequence<T,FOREST,U,GROUP>::operator+=( const AbstractDifferenceSequence<T,U>& a )
{

  for( int i = 0 ; i < m_size ; i++ ){

    m_a[i] = m_M.Sum( m_a[i] , a.m_a[i] );
    m_lazy_addition[i] = m_M.Sum( m_lazy_addition[i] , a.m_lazy_addition[i] );
    
  }

  Update();
  return *this;
  
}

template <typename T , typename FOREST , typename U , typename GROUP>
void AbstractDifferenceSequence<T,FOREST,U,GROUP>::Update()
{

  if( ! m_updated ){

    return;

  }

  const U& zero = m_M.Zero();

  for( auto itr_root = m_root.begin() , end_root = m_root.end() ; itr_root != end_root ; itr_root++ ){

    list<T> vertex{};
    vertex.push_back( *itr_root );

    while( !vertex.empty() ){

      const T& s = vertex.front();
      auto&& i = m_G.Enumeration_inv( s );
      auto&& edge = m_G.Edge( s );
      U& m_lazy_addition_s = m_lazy_addition[i];
      m_a[i] = m_M.Sum( m_a[i] , m_lazy_addition_s );

      for( auto itr_edge = edge.begin() , end_edge = edge.end() ; itr_edge != end_edge ; itr_edge++ ){

	U& m_lazy_addition_t = m_lazy_addition[m_G.Enumeration_inv(*itr_edge)];
	m_lazy_addition_t = m_M.Sum( m_lazy_addition_t , m_lazy_addition_s );
	vertex.push_back( *itr_edge );

      }

      m_lazy_addition_s = zero;
      vertex.pop_front();

    }

  }


  for( int i = 0 ; i < m_size ; i++ ){


  }

  m_updated = false;
  return;
  
}
