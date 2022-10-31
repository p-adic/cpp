// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Euler/a.cpp

#pragma once
#include "../../../Header.hpp"
#include "a_Body.hpp"

#include "../CRT/a_Body.hpp"

void CarmichaelTransformation( vector<uint>& exponent )
{

  uint size = exponent.size();
  vector<uint> exponent_answer( size );
  
  for( uint i = 0 ; i < size ; i++ ){

    uint& exponent_i = exponent[i];

    if( exponent_i != 0 ){

      exponent_i--;
      const uint& P_i = GetPrime( i );
      uint& exponent_answer_i = exponent_answer[i];

      if( exponent_answer_i < exponent_i ){

	exponent_answer_i = exponent_i;

      }

      uint new_factor = P_i - 1;

      for( uint j = 0 ; j < i ; j++ ){

	const uint& P_j = GetPrime( j );

	if( new_factor % P_j == 0 ){

	  new_factor /= P_j;
	  uint new_exponent = 1;

	  while( new_factor % P_j == 0 ){

	    new_factor /= P_j;
	    new_exponent++;

	  }

	  uint& exponent_answer_j = exponent_answer[j];

	  if( exponent_answer_j < new_exponent ){
	  
	    exponent_answer_j = new_exponent;

	  }

	}

	if( new_factor == 1 ){

	  break;
	
	}

      }

    }
   
  }

  exponent = move( exponent_answer );  
  return;

}
