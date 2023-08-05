// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Bitset/a_Body.hpp

#pragma once
#include "a.hpp"

template <int bound_L , int bound_M>
int RowEchelonForm( bitset<bound_M> ( &A )[bound_L] , const int& L , const int& M )
{

  assert( L <= bound_L );
  assert( M <= bound_M );
  int i_min = 0;
  int i_curr;
  int j_curr = 0;

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

template <int bound_L , int bound_M_N>
pair<int,bool> ExtendedReducedRowEchelonForm( bitset<bound_M_N> ( &A )[bound_L] , const int& L , const int& M , const int& N )
{

  DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_BITSET( int j = -1 );
  return { rank , solvable };

}

template <int bound_L , int bound_M , int bound_N , int bound_M_N>
pair<int,bool> ExtendedReducedRowEchelonForm( bitset<bound_M_N> ( &A )[bound_L] , bitset<bound_N> ( &solution )[bound_M] , const int& L , const int& M , const int& N )
{

  assert( M <= bound_M );
  assert( N <= bound_N );
  int left[bound_L];
  DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_BITSET( int& j = left[i] = -1 );

  if( solvable ){

    for( int j = 0 ; j < M ; j++ ){

      bitset<bound_N>& solution_j = solution[j];
      
      for( int k = 0 ; k < N ; k++ ){

	solution_j[k] = 0;

      }

    }
  
    i = rank;
  
    while( --i >= 0 ){

      const bitset<bound_M + bound_N>& A_i = A[i];
      const int& j = left[i];
      bitset<bound_N>& solution_j = solution[j];
      
      for( int k = 0 ; k < N ; k++ ){

	solution_j[k] = A_i[M + k];

      }

    }

  }

  return { rank , solvable };

}

template <int bound_L , int bound_M>
inline int ReducedRowEchelonForm( bitset<bound_M> ( &A )[bound_L] , const int& L , const int& M ) { bitset<1> dummy[bound_L] = {}; return ExtendedReducedRowEchelonForm( A , dummy , L , M , 0 ).first; }

template <int bound_L>
bool Invertible( const bitset<bound_L> ( &A )[bound_L] , bitset<bound_L> ( &A_inv )[bound_L] , const int& L )
{

  bitset<bound_L + bound_L> A_copy[bound_L];

  for( int i = 0 ; i < L ; i++ ){

    const bitset<bound_L>& A_i = A[i];
    bitset<bound_L + bound_L>& A_copy_i = A_copy[i];

    for( int j = 0 ; j < L ; j++ ){

      A_copy_i[j] = A_i[j];

    }

    for( int j = 0 ; j < L ; j++ ){

      A_copy_i[L + j] = i == j ? 1 : 0;

    }
    
  }

  return ExtendedReducedRowEchelonForm( A_copy , A_inv , L , L , L ).second;

}
