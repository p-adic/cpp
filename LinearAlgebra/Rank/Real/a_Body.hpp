// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Int/a_Body.hpp

#pragma once
#include "a.hpp"

template <int bound_L , int bound_M>
int RowEchelonForm( double ( &A )[bound_L][bound_M] , const int& L , const int& M , const double& epsilon )
{

  assert( L <= bound_L );
  assert( M <= bound_M );
  int i_min = 0;
  int i_curr , i_curr_max;
  int j_curr = 0;

  while( i_min < L && j_curr < M ){

    i_curr = i_curr_max = i_min;
    double A_i_curr_max_j_curr = A[i_curr_max][j_curr];
    A_i_curr_max_j_curr < 0 ? A_i_curr_max_j_curr *= -1 : A_i_curr_max_j_curr;

    while( i_curr++ < L ){

      double A_i_curr_j_curr = A[i_curr][j_curr];
      A_i_curr_j_curr < 0 ? A_i_curr_j_curr *= -1 : A_i_curr_j_curr;

      if( A_i_curr_max_j_curr < A_i_curr_j_curr ){

	A_i_curr_max_j_curr = A_i_curr_j_curr;
	i_curr_max = i_curr;

      }

    }

    if( A_i_curr_max_j_curr >= epsilon ){

      swap( A[i_min] , A[i_curr_max] );
      double ( &A_i_min )[bound_M] = A[i_min];
      const double A_i_min_j_curr = A_i_min[j_curr];

      for( int j = j_curr ; j < M ; j++ ){

	A_i_min[j] /= A_i_min_j_curr;

      }

      for( int i = i_min + 1 ; i < L ; i++ ){

	double ( &A_i )[bound_M] = A[i];
	const double A_i_curr_j_curr = A_i[j_curr];

	for( int j = j_curr ; j < M ; j++ ){

	  A_i[j] -= A_i_curr_j_curr * A_i_min[j];

	}

      }

      i_min++;

    }

    j_curr++;

  }

  return i_min;

}
