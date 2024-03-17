// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Bitset/a_Macro.hpp

#pragma once

#define DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_BITSET( DECL_J ) \
  const uint M_N = M + N;						\
  assert( L <= bound_L );						\
  assert( M_N <= bound_M_N );						\
  uint rank = RowEchelonForm<bound_L,bound_M_N>( A , L , M_N );		\
  bool solvable = true;							\
  uint i = rank;							\
									\
  while( --i < rank ){							\
									\
    const bitset<bound_M_N>& A_i = A[i];				\
    DECL_J;								\
									\
    while( j < M ){							\
									\
      if( A_i[j] != 0 ){						\
									\
	break;								\
									\
      }									\
									\
      j++;								\
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
      uint i_curr = i;							\
									\
      while( --i_curr < i ){						\
									\
	bitset<bound_M_N>& A_i_curr = A[i_curr];			\
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


