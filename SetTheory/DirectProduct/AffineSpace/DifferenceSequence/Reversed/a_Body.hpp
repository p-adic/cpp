// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/Reversed/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Geometry/Graph/Linear/Prev/a_Body.hpp"

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::AbstractReversedDifferenceSequence( FOREST G , PREV prev , GROUP M , int degree ) : AbstractReversedDifferenceSequence( G , prev , M , vector( G.size() , M.Zero() ) , move( degree ) , 0 ) {}
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::AbstractReversedDifferenceSequence( FOREST& G , PREV& prev , GROUP& M , vector<U> a , int degree , int dummy ) : AbstractReversedDifferenceSequence( move( G ) , move( prev ) , move( M ) , move( a ) , move( degree ) ) {}
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::AbstractReversedDifferenceSequence( FOREST G , PREV prev , GROUP M , vector<U> a , int degree ) : m_G( move( G ) ) , m_prev( move( prev ) ) , m_M( move( M ) ) , m_a( move( a ) ) , m_degree( move( degree ) ) { static_assert( is_invocable_r_v<int,PREV,const int&> ); }

template <typename U> inline ReversedDifferenceSequence<U>::ReversedDifferenceSequence( const int& size , int degree ) : ReversedDifferenceSequence( vector<U>( size ) , move( degree ) ) {}
template <typename U> inline ReversedDifferenceSequence<U>::ReversedDifferenceSequence( vector<U> a , int degree ) : ReversedDifferenceSequence<U>( a.size() , a , move( degree ) ) {}
template <typename U> inline ReversedDifferenceSequence<U>::ReversedDifferenceSequence( const int& size , vector<U>& a , int degree ) : AbstractReversedDifferenceSequence<int,LinearGraph,LinearPrev,U,AdditiveGroup<U>>( LinearGraph( size , true ) , LinearPrev() , AdditiveGroup<U>() , move( a ) , move( degree ) ) {}

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> template <typename...Args> inline void AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::Initialise( Args&&... args ) { AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP> temp{ m_G , m_M , move( args )... }; m_a = move( temp.m_a ); m_degree = temp.m_degree; }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::Set( const T& t , const U& u  , const int& degree) { Add( t , m_M.Sum( m_M.Inverse( operator[]( t ) ) , u ) , degree ); }
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::Add( const T& t , const U& u , const int& degree ) { if( u == m_M.Zero() ){ return; } Shift( degree , degree + 1 ); auto&& i = m_G.Enumeration_inv( t ); m_a[i] = m_M.Sum( move( m_a[i] ) , u ); if( m_degree > degree ){ auto&& i_prev = m_prev( i ); if( i_prev != -1 ){ m_a[i_prev] = m_M.Sum( move( m_a[i_prev] ) , m_M.Inverse( u ) ); } } }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::InitialSegmentAdd( const T& t_final , const U& u , const int& degree ) { if( u == m_M.Zero() ){ return; } Shift( degree + 1 ); U& m_a_i = m_a[m_G.Enumeration_inv( t_final )]; m_a_i = m_M.Sum( move( m_a_i ) , u ); }
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::IntervalAdd( const T& t_start , const T& t_final , const U& u , const int& degree ) { InitialSegmentAdd( t_final , u , degree ); auto&& i_prev = m_prev( m_G.Enumeration_inv( t_start ) ); if( i_prev != -1 ){ InitialSegmentAdd( m_G.Enumeration( i_prev ) , m_M.Inverse( u ) , degree ); } }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline U AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::operator[]( const T& t ) { Shift( -1 , 0 ); auto&& i = m_G.Enumeration_inv( t ); U answer = m_a[i]; if( m_degree < 0 ){ auto&& edge_t = m_G.Edge( t ); for( auto& t_child : edge_t ){ answer = m_M.Sum( move( answer ) , m_M.Inverse( m_a[m_G.Enumeration_inv( t_child )] ) ); } } return answer; }
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline const U& AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::Get( const T& t , const int& degree ) { Shift( degree ); return m_a[m_G.Enumeration_inv( t )]; }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline const U& AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::FinalSegmentSum( const T& t_start , const int& degree ) { return Get( t_start , degree - 1 ); }
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline U AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::SubtreeSum( const T& t_start , const vector<T>& t_outsides , const int& degree ) { U answer = FinalSegmentSum( t_start , degree ); for( auto& t_outside : t_outsides ){ answer = m_M.Sum( move( answer ) , m_M.Inverse( m_a[m_G.Enumeration_inv( t_outside )] ) ); } return answer; }
template <typename U> inline U ReversedDifferenceSequence<U>::IntervalSum( const int& t_start , const int& t_final , const int& degree ) { return t_final < t_start ? this->m_M.Zero() : this->SubtreeSum( t_start , vector( t_final + 1 < this->m_G.size() ? 1 : 0 , t_final + 1 ) , degree ); }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::Shift( const int& degree ) { Shift( degree , degree ); }
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::Shift( const int& degree_min , const int& degree_max ) { while( m_degree < degree_min ){ Differentiate(); } while( m_degree > degree_max ){ Integrate(); } }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::Integrate() { m_degree--; for( int i = m_G.size() - 1 ; i > 0 ; i-- ){ auto&& i_prev = m_prev( i ); if( i_prev != -1 ){ m_a[i_prev] = m_M.Sum( move( m_a[i_prev] ) , m_a[i] ); } } }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractReversedDifferenceSequence<T,FOREST,PREV,U,GROUP>::Differentiate() { m_degree++; const int& size = m_G.size(); for( int i = 1 ; i < size ; i++ ){ auto&& i_prev = m_prev( i ); if( i_prev != -1 ){ m_a[i_prev] = m_M.Sum( move( m_a[i_prev] ) , m_M.Inverse( m_a[i] ) ); } } }

// —vŒ(4)‚ð–ž‚½‚³‚È‚¢Žž—pB
#include "../../../../../Geometry/Graph/Acyclic/DirectedForest/a_Body.hpp"
