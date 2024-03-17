// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Bitset/a_Body.hpp

#pragma once
#include "a.hpp"

template <size_t bound_M>
size_t RowEchelonForm( vector<bitset<bound_M>>& A  , const size_t& M )
{

  assert( M <= bound_M );
  const size_t L = A.size();
  size_t i_min = 0;
  size_t i_curr;
  size_t j_curr = 0;

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

template <size_t bound_M_N>
pair<size_t,bool> ExtendedReducedRowEchelonForm( vector<bitset<bound_M_N>>& A , const size_t& M , const size_t& N )
{

  const size_t L = A.size();
  DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_BITSET( size_t j = 0 );
  return { rank , solvable };

}

template <size_t bound_N , size_t bound_M_N>
pair<size_t,bool> ExtendedReducedRowEchelonForm( vector<bitset<bound_M_N>>& A , vector<bitset<bound_N>>& solution , const size_t& M , const size_t& N )
{

  assert( N <= bound_N );
  const size_t L = A.size();
  vector<size_t> left( L );
  DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_BITSET( size_t& j = left[i] );

  if( solvable ){

    solution = vector( M , bitset<bound_N>() );
    i = rank;
  
    while( --i < rank ){

      const bitset<bound_M_N>& A_i = A[i];
      const size_t& j = left[i];
      bitset<bound_N>& solution_j = solution[j];
      
      for( size_t k = 0 ; k < N ; k++ ){

	solution_j[k] = A_i[M + k];

      }

    }

  }

  return { rank , solvable };

}

template <size_t bound_M> inline size_t ReducedRowEchelonForm( vector<bitset<bound_M>>& A , const size_t& M ) { const size_t L = A.size(); vector<bitset<0>> dummy( L ); return ExtendedReducedRowEchelonForm( A , dummy , M , 0 ).first; }

template <size_t bound_L , size_t bound_M> inline bool LinearlyIndependent( const vector<bitset<bound_M>>& A , const size_t& M ) { const size_t L = A.size(); return L <= M ? ReducedRowEchelonForm( A , M ) == L : false; }

template <size_t bound_L>
bool Invertible( const vector<bitset<bound_L>>& A , vector<bitset<bound_L>>& A_inv )
{

  const size_t L = A.size();
  vector<bitset<bound_L + bound_L>> A_copy( L );

  for( size_t i = 0 ; i < L ; i++ ){

    const bitset<bound_L>& A_i = A[i];
    bitset<bound_L + bound_L>& A_copy_i = A_copy[i];

    for( size_t j = 0 ; j < L ; j++ ){

      A_copy_i[j] = A_i[j];

    }

    for( size_t j = 0 ; j < L ; j++ ){

      A_copy_i[L + j] = i == j ? 1 : 0;

    }
    
  }

  return ExtendedReducedRowEchelonForm( A_copy , A_inv , L , L ).second;

}
