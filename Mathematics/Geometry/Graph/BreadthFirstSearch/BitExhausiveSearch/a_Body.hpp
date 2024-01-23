// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/BitExhausiveSearch/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

inline list<int> BitExhausiveEdge::operator()( const int& t ) { DEFINITION_OF_ADJACENT_SET( ~t , | , *m_p_V , answer.push_back( t_next ); ); }

inline BitExhausiveSearch::BitExhausiveSearch( const int& digit , const int& V ) : BreadthFirstSearch<Graph<BitExhausiveEdge>>( m_G ) , m_G( V , BitExhausiveEdge() ) , m_V( m_G.size() ) , m_digit( digit ) { assert( 0 <= m_digit && m_digit <= 30 && ( m_V >> m_digit ) <= 1 ); m_G.edge().m_p_V = &( m_G.size() ); }
inline BitExhausiveSearch::BitExhausiveSearch( const int& digit ) : BitExhausiveSearch( digit , 1 << digit ) {}

inline list<int> BitExhausiveSearch::UnreachedAdjacentSupsetOf( const int& t ) noexcept { DEFINITION_OF_ADJACENT_SET( ~t , | , m_V , if( ! this->found( t_next ) ){ answer.push_back( t_next ); } ); }
inline list<int> BitExhausiveSearch::UnreachedProperSupsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( ++ , |= , m_V , if( ! this->found( t_next ) ){ answer.push_back( t_next ); } ); }
inline list<int> BitExhausiveSearch::AdjacentSupsetOf( const int& t ) noexcept { DEFINITION_OF_ADJACENT_SET( ~t , | , m_V , answer.push_back( t_next ) ); }
inline list<int> BitExhausiveSearch::ProperSupsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( ++ , |= , m_V , answer.push_back( t_next ); ); }

inline list<int> BitExhausiveSearch::UnreachedAdjacentSubsetOf( const int& t ) noexcept { DEFINITION_OF_ADJACENT_SET( t , ^ , t , if( ! this->found( t_next ) ){ answer.push_back( t_next ); } ); }
inline list<int> BitExhausiveSearch::UnreachedProperSubsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( -- , ^= , t , if( ! this->found( t_next ) ){ answer.push_back( t_next ); } ); }
inline list<int> BitExhausiveSearch::AdjacentSubsetOf( const int& t ) noexcept { DEFINITION_OF_ADJACENT_SET( t , ^ , t , answer.push_back( t_next ) ); }
inline list<int> BitExhausiveSearch::ProperSubsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( -- , ^= , t , answer.push_back( t_next ); ); }

inline bool BitExhausiveSearch::NextSubset( int& t ) noexcept { vector<int> S( m_digit ); for( int d = 0 ; d < m_digit ; d++ ){ S[d] = ( ( t >> ( m_digit - d - 1 ) ) & 1 ); } bool b = next_permutation( S.begin() , S.end() ); t = 0; for( int d = 0 ; d < m_digit ; d++ ){ t |= S[d] << ( m_digit - d - 1 ); b = b && t < m_V; } return b; }

inline const int& BitExhausiveSearch::ValuationOf( const int& t ) noexcept
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

