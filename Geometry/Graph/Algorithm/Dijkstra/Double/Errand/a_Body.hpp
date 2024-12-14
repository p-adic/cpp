// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Double/Errand/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "../../../../Linear/a_Body.hpp"

template <typename T , typename GRAPH> inline ErrandEnumeration<T,GRAPH>::ErrandEnumeration( GRAPH& G ) : m_p_G( &G ) {}
template <typename T , typename GRAPH> inline pair<int,T> ErrandEnumeration<T,GRAPH>::operator()( const int& i ) { const int& size = m_p_G->size(); return { i / size , m_p_G->Enumeration( i % size ) }; }

template <typename T , typename GRAPH> inline ErrandEnumeration_inv<T,GRAPH>::ErrandEnumeration_inv( GRAPH& G ) : m_p_G( &G ) {}
template <typename T , typename GRAPH> inline int ErrandEnumeration_inv<T,GRAPH>::operator()( const pair<int,T>& v ) { const int& size = m_p_G->size(); auto& [i,t] = v; return i * size + m_p_G->Enumeration_inv( t ); }


template <typename T , typename U , typename GRAPH , typename SUBGOAL> inline ErrandEdge<T,U,GRAPH,SUBGOAL>::ErrandEdge( GRAPH& G , SUBGOAL subgoal , const U& one , const int& goal_num ) : m_p_G( &G ) , m_subgoal( move( subgoal ) ) , m_one( one ) , m_goal_num( goal_num ) { static_assert( is_invocable_r_v<bool,SUBGOAL,int,T> ); }

template <typename T , typename U , typename GRAPH , typename SUBGOAL> inline vector<pair<pair<int,T>,U>> ErrandEdge<T,U,GRAPH,SUBGOAL>::operator()( const pair<int,T>& v ) { auto& [i,t] = v; const bool b = i < m_goal_num ? m_subgoal( i , t ) : false; auto&& e_t = m_p_G->Edge( t ); vector<pair<pair<int,T>,U>> answer{}; answer.reserve( e_t.size() + ( b ? 1 : 0 ) ); if( b ){ answer.push_back( { { i + 1 , t } , m_one } ); } for( auto&& p : e_t ){ answer.push_back( { { i , get<0>( p ) } , get<1>( p ) } ); } return answer; }


template <typename T , typename GRAPH> inline ErrandVertex<T,GRAPH>::ErrandVertex( GRAPH& G ) : m_p_G( &G ) , m_vertex() { static_assert( !is_same_v<GRAPH,MemorisationGraph<T,decldecay_t(declval<GRAPH>().edge())>> ); }
template <typename T , typename GRAPH> inline const vector<T>& ErrandVertex<T,GRAPH>::operator()( const int& ){ if( m_vertex.empty() ){ const int& size = m_p_G->size(); m_vertex.resize( size ); for( int i = 0 ; i < size ; i++ ){ m_vertex[i] = m_p_G->Enumeration( i ); } } return m_vertex; }


template <typename T , typename GRAPH , typename U , typename COMM_MONOID , typename SUBGOAL> inline ErrandDijkstra<T,GRAPH,U,COMM_MONOID,SUBGOAL>::ErrandDijkstra( GRAPH G , COMM_MONOID M , SUBGOAL subgoal , const int& goal_num , const U& infty , const int& direction ) : DoubleDijkstra<int,LinearGraph,T,U,EnumerationGraph<pair<int,T>,ErrandEnumeration<T,GRAPH>,ErrandEnumeration_inv<T,GRAPH>,ErrandEdge<T,U,GRAPH,SUBGOAL>>,ErrandVertex<T,GRAPH>>( LinearGraph( goal_num , direction ) , EnumerationGraph<pair<int,T>,ErrandEnumeration<T,GRAPH>,ErrandEnumeration_inv<T,GRAPH>,ErrandEdge<T,U,GRAPH,SUBGOAL>>( G.size() * ( goal_num + 1 ) , ErrandEnumeration<T,GRAPH>( m_G ) , ErrandEnumeration_inv<T,GRAPH>( m_G ) , ErrandEdge<T,U,GRAPH,SUBGOAL>( m_G , move( subgoal ) , M.One() , goal_num ) ) , ErrandVertex<T,GRAPH>( m_G ) ) , m_G( move( G ) ) , m_M( move( M ) ) , m_infty( infty ) { static_assert( is_same_v<U,decldecay_t( declval<GRAPH>().Edge( declval<inner_t<GRAPH>>() ).front().second )> ); assert( direction == 1 || direction == 2 ); }

template <typename T , typename GRAPH , typename U , typename COMM_MONOID , typename SUBGOAL> inline const U& ErrandDijkstra<T,GRAPH,U,COMM_MONOID,SUBGOAL>::infty() const noexcept { return m_infty; }

template <typename T , typename GRAPH , typename U , typename COMM_MONOID , typename SUBGOAL> inline vector<U> ErrandDijkstra<T,GRAPH,U,COMM_MONOID,SUBGOAL>::GetDistance( const vector<T>& t_starts , const bool& many_edges ) { const int starts_size = t_starts.size(); vector<pair<int,T>> v_starts( starts_size ); for( int i = 0 ; i < starts_size ; i++ ){ v_starts[i] = { 0 , t_starts[i] }; } auto full =  DoubleDijkstra<int,LinearGraph,T,U,EnumerationGraph<pair<int,T>,ErrandEnumeration<T,GRAPH>,ErrandEnumeration_inv<T,GRAPH>,ErrandEdge<T,U,GRAPH,SUBGOAL>>,ErrandVertex<T,GRAPH>>::GetDistance( v_starts , m_M , m_infty , many_edges ); const int& size = m_G.size(); const int shift = full.size() - size; vector<U> answer( size ); for( int i = 0 ; i < size ; i++ ){ answer[i] = move( full[shift + i] ); } return answer; }
