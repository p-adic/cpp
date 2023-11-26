// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/Divisor/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../../../Arithmetic/Prime/Divisor/a_Body.hpp"

template <typename INT , INT val_limit , int length_max> int TwoAryMoeviusFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const int& t0 , const int& t1 )
{

  constexpr int size_max = val_limit * val_limit;
  static int memory[size_max];
  static bool uninitialised = true;

  if( uninitialised ){

    vector<int> rest( size_max );
    
    for( int n = 0 ; n < size_max ; n++ ){

      memory[n] = 1;
      rest[n] = n;
      
    }

    for( int i = 0 ; i < prime.length() ; i++ ){

      const INT& p_i = prime[i];
      int n = 0;

      while( ( n += p_i ) < size_max ){

	int& rest_n = rest[n] /= p_i;
	memory[n] *= ( rest_n % p_i == 0 ? 0 : -1 );

      }
      
    }

    for( int n = val_limit ; n < size_max ; n++ ){

      if( rest[n] != 1 ){

	memory[n] *= -1;

      }
      
    }
      
    uninitialised = false;

  }

  assert( t1 % t0 == 0 );
  return memory[ t1 / t0 ];

}

template <typename INT , INT val_limit , int length_max> inline list<int> DivisorEdgeForZetaTransform( const PrimeEnumeration<INT,val_limit,length_max>& prime , const int& t_max , const int& t ) { assert( 0 <= t && t <= t_max ); list<int> answer{}; if( t != 0 ){ answer = EnumerateDivisor( prime , t ); answer.pop_back(); } return answer; }
inline list<int> MultipleEdgeForZetaTransform( const int& t_max , const int& t ) { assert( 0 <= t && t <= t_max ); list<int> answer{}; if( t != 0 ){ int temp = t; while( ( temp += t ) <= t_max ){ answer.push_back( temp ); } } return answer; }
