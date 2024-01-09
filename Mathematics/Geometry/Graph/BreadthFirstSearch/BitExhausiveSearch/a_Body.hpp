// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/BitExhausiveSearch/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <int digit> unordered_map<int,int> BitExhausiveSearch<digit>::g_v{};

template <int digit> inline BitExhausiveSearch<digit>::BitExhausiveSearch( const int& V ) : BreadthFirstSearch_Body( V , 0 ) { static_assert( 0 <= digit && digit <= 30 ); assert( ( V >> digit ) <= 1 ); }

template <int digit> inline list<int> BitExhausiveSearch<digit>::UnreachedAdjacentSupsetOf( const int& t ) noexcept { return e( t ); }
template <int digit> inline list<int> BitExhausiveSearch<digit>::e( const int& t ) { DEFINITION_OF_ADJACENT_SET( ~t , | , BreadthFirstSearch_Body::m_V , if( ! BreadthFirstSearch_Body::found( t_next ) ){ answer.push_back( t_next ); } ); }
template <int digit> inline list<int> BitExhausiveSearch<digit>::UnreachedProperSupsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( ++ , |= , BreadthFirstSearch_Body::m_V , if( ! BreadthFirstSearch_Body::found( t_next ) ){ answer.push_back( t_next ); } ); }
template <int digit> inline list<int> BitExhausiveSearch<digit>::AdjacentSupsetOf( const int& t ) noexcept { DEFINITION_OF_ADJACENT_SET( ~t , | , BreadthFirstSearch_Body::m_V , answer.push_back( t_next ) ); }
template <int digit> inline list<int> BitExhausiveSearch<digit>::ProperSupsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( ++ , |= , BreadthFirstSearch_Body::m_V , answer.push_back( t_next ); ); }

template <int digit> inline list<int> BitExhausiveSearch<digit>::UnreachedAdjacentSubsetOf( const int& t ) noexcept { DEFINITION_OF_ADJACENT_SET( t , ^ , t , if( ! BreadthFirstSearch_Body::found( t_next ) ){ answer.push_back( t_next ); } ); }
template <int digit> inline list<int> BitExhausiveSearch<digit>::UnreachedProperSubsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( -- , ^= , t , if( ! BreadthFirstSearch_Body::found( t_next ) ){ answer.push_back( t_next ); } ); }
template <int digit> inline list<int> BitExhausiveSearch<digit>::AdjacentSubsetOf( const int& t ) noexcept { DEFINITION_OF_ADJACENT_SET( t , ^ , t , answer.push_back( t_next ) ); }
template <int digit> inline list<int> BitExhausiveSearch<digit>::ProperSubsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( -- , ^= , t , answer.push_back( t_next ); ); }

template <int digit> inline bool BitExhausiveSearch<digit>::NextSubset( int& t , const int& V ) noexcept { int S[digit]; for( int d = 0 ; d < digit ; d++ ){ S[d] = ( ( t >> ( digit - d - 1 ) ) & 1 ); } bool b = next_permutation( S , S + digit ); t = 0; for( int d = 0 ; d < digit ; d++ ){ t |= S[d] << ( digit - d - 1 ); b = b && t < V; } return b; }

template <int digit> inline const int& BitExhausiveSearch<digit>::ValuationOf( const int& t ) noexcept
{

  if( g_v.empty() ){

    for( int d = 0 ; d < digit ; d++ ){

      g_v[ 1 << d ] = d;

    }

  }

  return g_v[t];
  
}
