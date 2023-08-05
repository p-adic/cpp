// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Bitset/a_Macro.hpp

#pragma once

#define DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_BITSET( DECL_J ) \
  const int M_N = M + N;						\
  assert( L <= bound_L );						\
  assert( M_N <= bound_M_N );						\
  int rank = RowEchelonForm( A , L , M_N );				\
  bool solvable = true;							\
  int i = rank;								\
									\
  while( --i >= 0 ){							\
									\
    const bitset<bound_M + bound_N>& A_i = A[i];			\
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
	bitset<bound_M + bound_N>& A_i_curr = A[i_curr];		\
									\
	if( A_i_curr[j] == 1 ){						\
									\
	  A_i_curr ^= A_i;						\
									\
	}								\
									\
      }									\
									\
    }									\
									\
  }									\


