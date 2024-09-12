// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Geometry/Graph/Linear/Prev/a_Body.hpp"

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::AbstractDifferenceSequence( FOREST G , PREV prev , GROUP M , int degree ) : AbstractDifferenceSequence( G , prev , M , vector( G.size() , M.Zero() ) , move( degree ) , 0 ) {}
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::AbstractDifferenceSequence( FOREST& G , PREV& prev , GROUP& M , vector<U> a , int degree , int dummy ) : AbstractDifferenceSequence( move( G ) , move( prev ) , move( M ) , move( a ) , move( degree ) ) {}
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::AbstractDifferenceSequence( FOREST G , PREV prev , GROUP M , vector<U> a , int degree ) : m_G( move( G ) ) , m_prev( move( prev ) ) , m_M( move( M ) ) , m_a( move( a ) ) , m_degree( move( degree ) ) { static_assert( is_invocable_r_v<int,PREV,const int&> ); }

template <typename U> inline DifferenceSequence<U>::DifferenceSequence( const int& size , int degree ) : DifferenceSequence( vector<U>( size ) , move( degree ) ) {}
template <typename U> inline DifferenceSequence<U>::DifferenceSequence( vector<U> a , int degree ) : DifferenceSequence<U>( a.size() , a , move( degree ) ) {}
template <typename U> inline DifferenceSequence<U>::DifferenceSequence( const int& size , vector<U>& a , int degree ) : AbstractDifferenceSequence<int,LinearGraph,LinearPrev,U,AdditiveGroup<U>>( LinearGraph( size , true ) , LinearPrev() , AdditiveGroup<U>() , move( a ) , move( degree ) ) {}

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> template <typename...Args> inline void AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::Initialise( Args&&... args ) { AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP> temp{ m_G , m_M , move( args )... }; m_a = move( temp.m_a ); m_degree = temp.m_degree; }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline const int& AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::size() const noexcept { return m_G.size(); }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::Set( const T& t , const U& u  , const int& degree ) { Add( t , m_M.Sum( m_M.Inverse( operator[]( t ) ) , u ) , degree ); }
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::Add( const T& t , const U& u , const int& degree ) { if( u == m_M.Zero() ){ return; } Shift( degree ); auto&& i = m_G.Enumeration_inv( t ); m_a[i] = m_M.Sum( move( m_a[i] ) , u ); }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::FinalSegmentAdd( const T& t_start , const U& u , const int& degree ) { if( u == m_M.Zero() ){ return; } Shift( degree + 1 ); U& m_a_i = m_a[m_G.Enumeration_inv( t_start )]; m_a_i = m_M.Sum( move( m_a_i ) , u ); }
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::SubtreeAdd( const T& t_start , const vector<T>& t_outsides , const U& u , const int& degree ) { FinalSegmentAdd( t_start , u , degree ); const U u_inv = m_M.Inverse( u ); for( auto& t_outside : t_outsides ){ FinalSegmentAdd( t_outside , u_inv , degree ); } }
template <typename U> inline void DifferenceSequence<U>::IntervalAdd( const int& t_start , const int& t_final , const U& u , const int& degree ) { if( t_start <= t_final ){ this->SubtreeAdd( t_start , vector( t_final + 1 < this->m_G.size() ? 1 : 0 , t_final + 1 ) , u , degree ); } }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline const U& AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::operator[]( const T& t ) { return Get( t , 0 ); }
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline const U& AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::Get( const T& t , const int& degree ) { Shift( degree ); return m_a[m_G.Enumeration_inv( t )]; }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline const U& AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::InitialSegmentSum( const T& t_final , const int& degree ) { return Get( t_final , degree - 1 ); }
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline U AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::IntervalSum( const T& t_start , const T& t_final , const int& degree ) { U answer = InitialSegmentSum( t_final , degree ); auto&& i_prev = m_prev( m_G.Enumeration_inv( t_start ) ); i_prev != -1 ? answer = m_M.Sum( move( answer ) , m_M.Inverse( m_a[i_prev] ) ): answer; return answer; }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::Shift( const int& degree ) { while( m_degree < degree ){ Differentiate(); } while( m_degree > degree ){ Integrate(); } }

template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::Integrate() { m_degree--; const int& N = size(); for( int i = 1; i < N ; i++ ){ auto&& i_prev = this->m_prev( i ); if( i_prev != -1 ){ m_a[i] = m_M.Sum( move( m_a[i] ) , m_a[i_prev] ); } } }
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline void AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>::Differentiate() { m_degree++; for( int i = size() - 1; i > 0 ; i-- ){ auto&& i_prev = this->m_prev( i ); if( i_prev != -1 ){ m_a[i] = m_M.Sum( move( m_a[i] ) , m_M.Inverse( m_a[i_prev] ) ); } } }

template <class Traits , typename T , typename FOREST , typename PREV , typename U , typename GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>& ds ){ auto&& size = ds.size(); for( int i = 0 ; i < size ; i++ ){ ( i == 0 ? os : os << " " ) << ds[i]; } return os; }


// —vŒ(4)‚ð–ž‚½‚³‚È‚¢Žž—pB
#include "../../../../Geometry/Graph/Acyclic/DirectedForest/a_Body.hpp"
