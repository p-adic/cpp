// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Mod/a_Macro.hpp

#pragma once

#define DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_MOD( DECL_J ) \
  const MODINT& zero = MODINT::zero();                                  \
  const int M_N = L == 0 ? 0 : A[0].size() , M = M_N - N;		\
  assert( M >= 0 );							\
  int rank = RowEchelonForm( A );					\
  vector<bool> solvable( N , true );                                    \
  int i = rank;								\
									\
  while( --i >= 0 ){							\
									\
    auto& A_i = A[i];							\
    DECL_J;								\
									\
    while( ++j < M ){							\
									\
      if( A_i[j] != zero ){						\
									\
	break;								\
									\
      }									\
									\
    }									\
									\
    if( j == M ){							\
									\
      while( j < M_N ){							\
									\
	solvable[j] = solvable[j] && A_i[j] == zero;                    \
        j++;                                                            \
									\
      }									\
									\
      rank--;								\
									\
    } else {								\
									\
      int i_curr = i;							\
									\
      while( --i_curr >= 0 ){						\
									\
	auto& A_i_curr = A[i_curr];					\
	const MODINT A_i_curr_j = A_i_curr[j];				\
									\
	for( int j_curr = j ; j_curr < M_N ; j_curr++ ){		\
									\
	  A_i_curr[j_curr] -= A_i_curr_j * A_i[j_curr];			\
									\
	}								\
									\
      }									\
									\
    }									\
									\
  }									\



