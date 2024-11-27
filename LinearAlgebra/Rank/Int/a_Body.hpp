// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Int/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , int bound_L , int bound_M>
int EuclideanRowEchelonForm( INT ( &A )[bound_L][bound_M] , const int& L , const int& M );
{

  assert( L <= bound_L );
  assert( M <= bound_M );
  int i_min = 0;
  int i_gcd;
  int i_curr;
  int j_curr = 0;
  INT a[2][2];
  INT ( &a_0 )[2] = a[0];
  INT ( &a_1 )[2] = a[1];
  INT b[2];
  INT& b_0 = b[0];
  INT& b_1 = b[1];
  int i[2];
  int i_0;
  int i_1;
  INT A_temp[2];
  INT& A_temp_0 = A_temp[0];
  INT& A_temp_1 = A_temp[1];
  INT q;

  while( i_min < L && j_curr < M ){

    i_gcd = i_min;
    i_curr = i_min + 1;
    b_0 = A[i_gcd][j_curr];

    while( i_curr < L ){
      
      b_1 = A[i_curr][j_curr];
      i[0] = i_gcd;
      i[1] = i_curr;
      i_0 = ( b_0 >= b_1 ? 0 : 1 );
      i_1 = 1 - i_0;

      for( int i = 0 ; i < 2 ; i++ ){

	INT ( &ai )[2] = a[i];

	for( int j = 0 ; j < 2 ; j++ ){

	  ai[j] = ( i == j ? 1 : 0 );

	}

      }

      while( b[i_1] != 0 ){

	INT& b_i_0 = b[i_0];
	INT& b_i_1 = b[i_1];
	INT ( &a_i_0 )[2] = a[i_0];
	INT ( &a_i_1 )[2] = a[i_1];
	q = b_i_0 / b_i_1;
	a_i_0[i_0] -= q * a_i_1[i_0];
	a_i_0[i_1] -= q * a_i_1[i_1];
	b_i_0 %= b_i_1;
	swap( i_0 , i_1 );

      }

      INT ( &A_i_0 )[bound_M] = A[i[0]];
      INT ( &A_i_1 )[bound_M] = A[i[1]];

      for( int j = j_curr ; j < M ; j++ ){

	INT& A_i_0_j = A_i_0[j];
	INT& A_i_1_j = A_i_1[j];
	A_temp_0 = a_0[0] * A_i_0_j + a_0[1] * A_i_1_j;
	A_temp_1 = a_1[0] * A_i_0_j + a_1[1] * A_i_1_j;
	A_i_0_j = A_temp_0;
	A_i_1_j = A_temp_1;

      }

      i_gcd = i[i_0];
      b_0 = A[i_gcd][j_curr];
      i_curr++;

    }

    if( b_0 != 0 ){

      swap( A[i_min] , A[i_gcd] );
      i_min++;

    }

    j_curr++;

  }

  return i_min;

}
