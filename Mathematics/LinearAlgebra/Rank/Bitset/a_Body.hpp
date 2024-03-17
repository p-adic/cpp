// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Bitset/a_Body.hpp

#pragma once
#include "a.hpp"

template <uint bound_L , uint bound_M>
uint RowEchelonForm( bitset<bound_M> ( &A )[bound_L] , const uint& L , const uint& M )
{

  assert( L <= bound_L );
  assert( M <= bound_M );
  uint i_min = 0;
  uint i_curr;
  uint j_curr = 0;

  while( i_min < L && j_curr < M ){

    i_curr = i_min;

    while( i_curr < L ? A[i_curr][j_curr] == 0 : false ){
      
      i_curr++;

    }

    if( i_curr < L ){

      swap( A[i_min] , A[i_curr] );
      const bitset<bound_M>& A_i_min = A[i_min++];

      while( ++i_curr < L ){

	bitset<bound_M>& A_i_curr = A[i_curr];
	
	if( A_i_curr[j_curr] == 1 ){

	  A_i_curr ^= A_i_min;

	}

      }

    }

    j_curr++;

  }

  return i_min;
  
}

template <uint bound_L , uint bound_M_N>
pair<uint,bool> ExtendedReducedRowEchelonForm( bitset<bound_M_N> ( &A )[bound_L] , const uint& L , const uint& M , const uint& N )
{

  DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_BITSET( uint j = 0 );
  return { rank , solvable };

}

template <uint bound_L , uint bound_M , uint bound_N , uint bound_M_N>
pair<uint,bool> ExtendedReducedRowEchelonForm( bitset<bound_M_N> ( &A )[bound_L] , bitset<bound_N> ( &solution )[bound_M] , const uint& L , const uint& M , const uint& N )
{

  assert( M <= bound_M );
  assert( N <= bound_N );
  uint left[bound_L];
  DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_BITSET( uint& j = left[i] = 0 );

  if( solvable ){

    for( uint j = 0 ; j < M ; j++ ){

      bitset<bound_N>& solution_j = solution[j];
      
      for( uint k = 0 ; k < N ; k++ ){

	solution_j[k] = 0;

      }

    }
  
    i = rank;
  
    while( --i < rank ){

      const bitset<bound_M_N>& A_i = A[i];
      const uint& j = left[i];
      bitset<bound_N>& solution_j = solution[j];
      
      for( uint k = 0 ; k < N ; k++ ){

	solution_j[k] = A_i[M + k];

      }

    }

  }

  return { rank , solvable };

}

template <uint bound_L , uint bound_M>
inline uint ReducedRowEchelonForm( bitset<bound_M> ( &A )[bound_L] , const uint& L , const uint& M ) { bitset<1> dummy[bound_L] = {}; return ExtendedReducedRowEchelonForm<bound_L,bound_L,1,bound_M>( A , dummy , L , M , 0 ).first; }

template <uint bound_L>
bool Invertible( const bitset<bound_L> ( &A )[bound_L] , bitset<bound_L> ( &A_inv )[bound_L] , const uint& L )
{

  bitset<bound_L + bound_L> A_copy[bound_L];

  for( uint i = 0 ; i < L ; i++ ){

    const bitset<bound_L>& A_i = A[i];
    bitset<bound_L + bound_L>& A_copy_i = A_copy[i];

    for( uint j = 0 ; j < L ; j++ ){

      A_copy_i[j] = A_i[j];

    }

    for( uint j = 0 ; j < L ; j++ ){

      A_copy_i[L + j] = i == j ? 1 : 0;

    }
    
  }

  return ExtendedReducedRowEchelonForm<bound_L,bound_L,bound_L+bound_L>( A_copy , A_inv , L , L , L ).second;

}
