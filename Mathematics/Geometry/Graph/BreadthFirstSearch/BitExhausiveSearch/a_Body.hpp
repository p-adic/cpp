// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/BitExhausiveSearch/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

inline vector<int> BitExhausiveEdge::operator()( const int& t ) { DEFINITION_OF_ADJACENT_SET( ~t , | , *m_p_V , answer.push_back( t_next ); ); }

inline BitExhausiveSearch::BitExhausiveSearch( const int& V , const int& digit ) : BreadthFirstSearch<int,Graph<BitExhausiveEdge>>( m_G , -1 ) , m_G( V , BitExhausiveEdge() ) , m_p_V( &( m_G.size() ) ) , m_digit( digit ) { assert( 0 <= m_digit && m_digit <= 30 && ( *m_p_V >> m_digit ) <= 1 ); m_G.edge().m_p_V = m_p_V; }
inline BitExhausiveSearch::BitExhausiveSearch( const int& V ) : BitExhausiveSearch( V , DigitOf( V ) ) {}

inline vector<int> BitExhausiveSearch::UnreachedAdjacentSupsetOf( const int& t ) noexcept { DEFINITION_OF_ADJACENT_SET( ~t , | , *m_p_V , if( ! this->found( t_next ) ){ this->found( t_next ) = true; answer.push_back( t_next ); } ); }
inline vector<int> BitExhausiveSearch::UnreachedProperSupsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( ++ , |= , *m_p_V , if( ! this->found( t_next ) ){ this->found( t_next ) = true; answer.push_back( t_next ); } ); }
inline vector<int> BitExhausiveSearch::UnreachedAdjacentSubsetOf( const int& t ) noexcept { DEFINITION_OF_ADJACENT_SET( t , ^ , t , if( ! this->found( t_next ) ){ this->found( t_next ) = true; answer.push_back( t_next ); } ); }
inline vector<int> BitExhausiveSearch::UnreachedProperSubsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( -- , &= , t , if( ! this->found( t_next ) ){ this->found( t_next ) = true; answer.push_back( t_next ); } ); }

inline vector<int> BitExhausiveSearch::AdjacentSupsetOf( const int& t ) noexcept { DEFINITION_OF_ADJACENT_SET( ~t , | , *m_p_V , answer.push_back( t_next ) ); }
inline vector<int> BitExhausiveSearch::ProperSupsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( ++ , |= , *m_p_V , answer.push_back( t_next ); ); }
inline vector<int> BitExhausiveSearch::AdjacentSubsetOf( const int& t ) noexcept { DEFINITION_OF_ADJACENT_SET( t , ^ , t , answer.push_back( t_next ) ); }
inline vector<int> BitExhausiveSearch::ProperSubsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( -- , &= , t , answer.push_back( t_next ); ); }

inline bool BitExhausiveSearch::NextSubset( int& t ) noexcept { vector<int> S( m_digit ); for( int d = 0 ; d < m_digit ; d++ ){ S[d] = ( ( t >> ( m_digit - d - 1 ) ) & 1 ); } bool b = next_permutation( S.begin() , S.end() ); t = 0; for( int d = 0 ; d < m_digit ; d++ ){ t |= S[d] << ( m_digit - d - 1 ); b = b && t < *m_p_V; } return b; }

inline int BitExhausiveSearch::DigitOf( const int& t ) noexcept { int digit = 0; int power = 1; while( t > power ){ power <<= 1; digit++; } return digit; }

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

