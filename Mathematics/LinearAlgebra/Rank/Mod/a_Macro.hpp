// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Mod/a_Macro.hpp

#pragma once

#define DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_MOD( DECL_J ) \
  const int M_N = M + N;						\
  assert( L <= bound_L );						\
  assert( M_N <= bound_M_N );						\
  int rank = RowEchelonForm( A , L , M_N , P );				\
  bool solvable = true;							\
  int i = rank;								\
									\
  while( --i >= 0 ){							\
									\
    const INT1 ( &A_i )[bound_M_N] = A[i];				\
    DECL_J;								\
									\
    while( ++j < M ){							\
									\
      if( A_i[j] != 0 ){						\
									\
	break;								\
									\
      }									\
									\
    }									\
									\
    if( j == M ){							\
									\
      solvable = false;							\
      rank--;								\
									\
    } else {								\
									\
      int i_curr = i;							\
									\
      while( --i_curr >= 0 ){						\
									\
	INT1 ( &A_i_curr )[bound_M_N] = A[i_curr];			\
	const INT1 A_i_curr_j = A_i_curr[j];				\
									\
	for( int j_curr = j ; j_curr < M_N ; j_curr++ ){		\
									\
	  INT1& A_i_curr_j_curr = A_i_curr[j_curr];			\
	  ( A_i_curr_j_curr -= A_i_curr_j * A_i[j_curr] ) %= P;		\
	  A_i_curr_j_curr < 0 ? A_i_curr_j_curr += P : A_i_curr_j_curr;	\
									\
	}								\
									\
      }									\
									\
    }									\
									\
  }									\



