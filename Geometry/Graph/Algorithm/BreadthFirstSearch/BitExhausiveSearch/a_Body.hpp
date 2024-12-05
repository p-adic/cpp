// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/BitExhausiveSearch/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"

inline vector<int> BitExhausiveEdge::operator()( const int& t ) { assert( 0 <= t && t < *m_p_V ); DEFINITION_OF_ADJACENT_SET( ~t , | , *m_p_V , answer.push_back( t_next ); ); }

inline BitExhausiveSearch::BitExhausiveSearch( const int& V ) : BreadthFirstSearch<int,Graph<BitExhausiveEdge>>( m_G , -1 ) , m_G( V , BitExhausiveEdge() ) , m_p_V( &( m_G.size() ) ) , m_digit( DigitOf( V ) ) { m_G.edge().m_p_V = m_p_V; }

inline vector<int> BitExhausiveSearch::to_vec( const int& t ) { assert( 0 <= t && t < *m_p_V ); vector<int> answer( m_digit ); for( int d = 0 ; d < m_digit ; d++ ){ answer[d] = ( ( t >> d ) & 1 ); } return answer; }
inline int BitExhausiveSearch::to_int( const vector<int>& a ) { int answer = 0; const int size = a.size(); assert( size <= m_digit ); for( int d = 0 ; d < size ; d++ ){ answer |= ( a[d] << d ); } return answer; }

inline vector<int> BitExhausiveSearch::UnreachedAdjacentSupsetOf( const int& t ) { assert( 0 <= t && t < *m_p_V ); DEFINITION_OF_ADJACENT_SET( ~t , | , *m_p_V , if( ! this->found( t_next ) ){ this->found( t_next ) = true; answer.push_back( t_next ); } ); }
inline vector<int> BitExhausiveSearch::UnreachedProperSupsetOf( const int& t ) { assert( 0 <= t && t < *m_p_V ); DEFINITION_OF_PROPER_SET( ++ , |= , *m_p_V , if( ! this->found( t_next ) ){ this->found( t_next ) = true; answer.push_back( t_next ); } ); }
inline vector<int> BitExhausiveSearch::UnreachedAdjacentSubsetOf( const int& t ) { assert( 0 <= t && t < *m_p_V ); DEFINITION_OF_ADJACENT_SET( t , ^ , t , if( ! this->found( t_next ) ){ this->found( t_next ) = true; answer.push_back( t_next ); } ); }
inline vector<int> BitExhausiveSearch::UnreachedProperSubsetOf( const int& t ) { assert( 0 <= t && t < *m_p_V ); DEFINITION_OF_PROPER_SET( -- , &= , t , if( ! this->found( t_next ) ){ this->found( t_next ) = true; answer.push_back( t_next ); } ); }

inline vector<int> BitExhausiveSearch::AdjacentSupsetOf( const int& t ) { assert( 0 <= t && t < *m_p_V ); DEFINITION_OF_ADJACENT_SET( ~t , | , *m_p_V , answer.push_back( t_next ) ); }
inline vector<int> BitExhausiveSearch::ProperSupsetOf( const int& t ) { assert( 0 <= t && t < *m_p_V ); DEFINITION_OF_PROPER_SET( ++ , |= , *m_p_V , answer.push_back( t_next ); ); }
inline vector<int> BitExhausiveSearch::AdjacentSubsetOf( const int& t ) { assert( 0 <= t ); DEFINITION_OF_ADJACENT_SET( t , ^ , t , answer.push_back( t_next ) ); }
inline vector<int> BitExhausiveSearch::ProperSubsetOf( const int& t ) { assert( 0 <= t ); DEFINITION_OF_PROPER_SET( -- , &= , t , answer.push_back( t_next ); ); }

inline bool BitExhausiveSearch::NextSubset( int& t ) { auto S = to_vec( t ); return prev_permutation( S.begin() , S.end() ) ? ( t = to_int( S ) ) < *m_p_V : false; }
inline bool BitExhausiveSearch::NextSubset( vector<int>& S ) { return prev_permutation( S.begin() , S.end() ) ? to_int( S ) < *m_p_V : false; }

inline int BitExhausiveSearch::DigitOf( const int& t ) { assert( 0 <= t ); int l = 0 , r = 31; while( l + 1 < r ){ int m = ( l + r ) >> 1; ( t >> m > 0 ? r : l ) = m; } return l; }

inline const int& BitExhausiveSearch::ValuationOf( const int& t )
{

  static unordered_map<int,int> g_v;
  static int length = 0;

  while( g_v.count( t ) == 0 ){

    assert( t >> length > 0 );
    g_v[ 1 << length ] = length;
    length++;

  }

  return g_v[t];
  
}

