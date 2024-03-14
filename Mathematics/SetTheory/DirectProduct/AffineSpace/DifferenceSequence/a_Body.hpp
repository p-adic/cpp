// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Graph/Array/a_Body.hpp"

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::AbstractDifferenceSequence( FOREST G , PREV Prev , GROUP M ) : m_G( move( G ) ) , m_Prev( move( Prev ) ) , m_M( move( M ) ) , m_a( m_G.size() , m_M.Zero() ) , m_lazy_addition( m_a ) , m_updated( false ) { static_assert( is_invocable_r_v<T,PREV,const T&> ); }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::AbstractDifferenceSequence( FOREST G , PREV Prev , GROUP M , vector<U> a ) : m_G( move( G ) ) , m_Prev( move( m_Prev ) ) , m_M( move( M ) ) , m_a( move( a ) ) , m_lazy_addition( m_G.size() , m_M.Zero() ) , m_updated( false ) { static_assert( !is_same_v<U,int> && is_invocable_r_v<T,PREV,const T&> ); }

template <typename U> inline DifferenceSequence<U>::DifferenceSequence( const int& size ) : DifferenceSequence( vector<U>( size ) ) {}
template <typename U> inline DifferenceSequence<U>::DifferenceSequence( vector<U> a ) : AbstractDifferenceSequence<int,LinearGraph,int(const int&)noexcept,U,AdditiveGroup<U>>( LinearGraph( a.size() , true ) , PrevOf , AdditiveGroup<U>() , move( a ) ) {}

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::Initialise( vector<U> a ) { *this = AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>( move( m_G ) , move( m_Prev ) , move( m_M ) , move( a ) ); }
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::Set( const T& t , const U& u ) { Update(); m_a[m_G.Enumeration_inv(t)] = u; }
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline const U& AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::Get( const T& t ) { Update(); return m_a[m_G.Enumeration_inv(t)]; }
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline U& AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::Ref( const T& t ) { return m_a[m_G.Enumeration_inv(t)]; }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::Add( const T& t , const U& u ) { U& a_t = m_a[m_G.Enumeration_inv(t)]; a_t = m_M.Sum( a_t , u ); }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP>
void AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::SubTreeAdd( const T& t_start , const list<T>& t_final , const U& u )
{

  if( u == m_M.Zero() ){

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

template <typename U> inline void DifferenceSequence<U>::InitialSegmentAdd( const int& t_start , const U& u ) { SubTreeAdd( t_start , {} , u ); }
template <typename U> inline void DifferenceSequence<U>::FinalSegmentAdd( const int& t_final , const U& u ) { IntervalAdd( 0 , t_final , u ); }
template <typename U> inline void DifferenceSequence<U>::IntervalAdd( const int& t_start , const int& t_final , const U& u ) { SubTreeAdd( t_start , { t_final } , u ); }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP>
AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>& AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::operator+=( const vector<U>& a )
{

  const int& size = m_G.size();
  assert( size == int( a.size() ) );

  for( int i = 0 ; i < size ; i++ ){

    m_a[i] = m_M.Sum( m_a[i] , a[i] );
    
  }

  return *this;
  
}

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP>
void AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::Update()
{

  if( !m_updated ){

    return;

  }

  const int& size = m_G.size();

  for( int i = 0 ; i < size ; i++ ){

    auto& m_lazy_addition_i = m_lazy_addition[i];
    // listを経由すると定数倍重い。
    auto&& j = m_G.Enumeration_inv( m_Prev( m_G.Enumeration( i ) ) );

    if( j != i ){
      
      assert( j < i );
      auto& m_lazy_addition_j = m_lazy_addition[j];
      m_lazy_addition_i = m_M.Sum( m_lazy_addition_j , m_lazy_addition_i );

    }

  }
  
  const U& zero = m_M.Zero();

  for( int i = 0 ; i < size ; i++ ){

    auto& m_lazy_addition_i = m_lazy_addition[i];
    U& m_ai = m_a[i];
    m_ai = m_M.Sum( m_lazy_addition_i , m_ai );
    m_lazy_addition_i = zero;

  }

  m_updated = false;
  return;
  
}

template <typename U> inline int DifferenceSequence<U>::PrevOf( const int& t_start ) noexcept { return max( t_start - 1 , 0 ); }
