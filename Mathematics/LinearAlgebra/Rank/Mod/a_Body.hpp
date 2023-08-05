// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Mod/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT1 , typename INT2 , int bound_L , int bound_M>
int RowEchelonForm( INT1 ( &A )[bound_L][bound_M] , const int& L , const int& M , const INT2& P )
{

  assert( L <= bound_L );
  assert( M <= bound_M );
  int i_min = 0;
  int i_curr;
  int j_curr = 0;

  while( i_min < L && j_curr < M ){

    i_curr = i_min;

    while( i_curr < L ? A[i_curr][j_curr] % P == 0 : false ){

      i_curr++;

    }

    if( i_curr < L ){

      swap( A[i_min] , A[i_curr] );
      INT1 ( &A_i_min )[bound_M] = A[i_min];
      INT1 inv = 1;
      INT1 exponent = P - 2;
      INT1 power = A_i_min[j_curr];

      while( exponent > 0 ){

	( exponent & 1 ) == 1 ? ( inv *= power ) %= P : inv;
	( power *= power ) %= P;
	exponent >>= 1;

      }
      
      for( int j = j_curr ; j < M ; j++ ){

	INT1& A_i_min_j = A_i_min[j];
	( A_i_min_j *= inv ) %= P;
	A_i_min_j < 0 ? A_i_min_j += P : A_i_min_j;

      }
      
      for( int i = i_min + 1 ; i < L ; i++ ){

	INT1 ( &A_i )[bound_M] = A[i];
	const INT1 A_i_j_curr = A_i[j_curr];

	for( int j = j_curr ; j < M ; j++ ){

	  INT1& A_i_j = A_i[j];
	  ( A_i_j -= A_i_j_curr * A_i_min[j] ) %= P;
	  A_i_j < 0 ? A_i_j += P : A_i_j;

	}

      }

      i_min++;

    }

    j_curr++;

  }
  
  return i_min;

}

template <typename INT1 , typename INT2 , int bound_L , int bound_M_N>
pair<int,bool> ExtendedReducedRowEchelonForm( INT1 ( &A )[bound_L][bound_M_N] , const int& L , const int& M , const int& N , const INT2& P )
{

  DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_MOD(int j = -1 );
  return { rank , solvable };

}

template <typename INT1 , typename INT2 , int bound_L , int bound_M , int bound_N , int bound_M_N>
pair<int,bool> ExtendedReducedRowEchelonForm( INT1 ( &A )[bound_L][bound_M_N] , INT1 ( &solution )[bound_M][bound_N] , const int& L , const int& M , const int& N , const INT2& P )
{

  assert( M <= bound_M );
  assert( N <= bound_N );
  int left[bound_L];
  DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_MOD( int& j = left[i] = -1 );

  if( solvable ){
    
    for( int j = 0 ; j < M ; j++ ){

      INT1 ( &solution_j )[bound_N] = solution[j];
      
      for( int k = 0 ; k < N ; k++ ){

	solution_j[k] = 0;

      }

    }
  
    i = rank;
  
    while( --i >= 0 ){

      const INT1 ( &A_i )[bound_M_N] = A[i];
      const int& j = left[i];
      INT1 ( &solution_j )[bound_N] = solution[j];
      
      for( int k = 0 ; k < N ; k++ ){

	solution_j[k] = A_i[M + k];

      }

    }

  }

  return { rank , solvable };

}

template <typename INT1 , typename INT2 , int bound_L , int bound_M> inline int ReducedRowEchelonForm( INT1 ( &A )[bound_L][bound_M] , const int& L , const int& M , const INT2& P ) { INT1 dummy[bound_L][1] = {}; return ExtendedReducedRowEchelonForm( A , dummy , L , M , 0 , P ).first; }

template <typename INT1 , typename INT2 , int bound_L>
bool Invertible( const INT1 ( &A )[bound_L][bound_L] , INT1 ( &A_inv )[bound_L][bound_L] , const int& L , const INT2& P )
{

  INT1 A_copy[bound_L][bound_L + bound_L];

  for( int i = 0 ; i < L ; i++ ){

    const INT1 ( &A_i )[bound_L] = A[i];
    INT1 ( &A_copy_i )[bound_L + bound_L] = A_copy[i];

    for( int j = 0 ; j < L ; j++ ){

      A_copy_i[j] = A_i[j];

    }

    for( int j = 0 ; j < L ; j++ ){

      A_copy_i[L + j] = i == j ? 1 : 0;

    }
    
  }

  return ExtendedReducedRowEchelonForm( A_copy , A_inv , L , L , L , P ).second;

}
