// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/BitExhausiveSearch/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <int digit> map<int,int> BitExhausiveSearch<digit>::g_v{};

template <int digit> inline BitExhausiveSearch<digit>::BitExhausiveSearch( const int& V ) : BASE_FOR_BIT_EXHAUSIVE_SEARCH( V , 0 ) {}

template <int digit> inline list<int> BitExhausiveSearch<digit>::UnreachedAdjacentSupsetOf( const int& t ) noexcept { return e( t ); }
template <int digit> inline list<int> BitExhausiveSearch<digit>::e( const int& t ) { DEFINITION_OF_ADJACENT_SET( ~t , | , BASE_FOR_BIT_EXHAUSIVE_SEARCH::m_V , if( ! BASE_FOR_BIT_EXHAUSIVE_SEARCH::found( t_next ) ){ answer.push_back( t_next ); } ); }
template <int digit> inline list<int> BitExhausiveSearch<digit>::UnreachedProperSupsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( ++ , |= , BASE_FOR_BIT_EXHAUSIVE_SEARCH::m_V , if( ! BASE_FOR_BIT_EXHAUSIVE_SEARCH::found( t_next ) ){ answer.push_back( t_next ); } ); }
template <int digit> inline list<int> BitExhausiveSearch<digit>::AdjacentSupsetOf( const int& t ) noexcept { DEFINITION_OF_ADJACENT_SET( ~t , | , BASE_FOR_BIT_EXHAUSIVE_SEARCH::m_V , answer.push_back( t_next ) ); }
template <int digit> inline list<int> BitExhausiveSearch<digit>::ProperSupsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( ++ , |= , BASE_FOR_BIT_EXHAUSIVE_SEARCH::m_V , answer.push_back( t_next ); ); }

template <int digit> inline list<int> BitExhausiveSearch<digit>::UnreachedAdjacentSubsetOf( const int& t ) noexcept { DEFINITION_OF_ADJACENT_SET( t , ^ , t , if( ! BASE_FOR_BIT_EXHAUSIVE_SEARCH::found( t_next ) ){ answer.push_back( t_next ); } ); }
template <int digit> inline list<int> BitExhausiveSearch<digit>::UnreachedProperSubsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( -- , ^= , t , if( ! BASE_FOR_BIT_EXHAUSIVE_SEARCH::found( t_next ) ){ answer.push_back( t_next ); } ); }
template <int digit> inline list<int> BitExhausiveSearch<digit>::AdjacentSubsetOf( const int& t ) noexcept { DEFINITION_OF_ADJACENT_SET( t , ^ , t , answer.push_back( t_next ) ); }
template <int digit> inline list<int> BitExhausiveSearch<digit>::ProperSubsetOf( const int& t ) noexcept { DEFINITION_OF_PROPER_SET( -- , ^= , t , answer.push_back( t_next ); ); }

template <int digit> inline const int& BitExhausiveSearch<digit>::ValuationOf( const int& t ) noexcept
{

  if( g_v.empty() ){

    for( int d = 0 ; d < digit ; d++ ){

      g_v[ 1 << d ] = d;

    }

  }

  return g_v[t];
  
}
