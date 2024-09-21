// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Mod/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename MODINT>
int RowEchelonForm( vector<vector<MODINT>>& A )
{

  const MODINT& zero = MODINT::zero();
  const int L = A.size() , M = L == 0 ? 0 : A[0].size();
  int i_min = 0 , i_curr , j_curr = 0;

  while( i_min < L && j_curr < M ){

    i_curr = i_min;

    while( i_curr < L && A[i_curr][j_curr] == zero ){

      i_curr++;

    }

    if( i_curr < L ){

      swap( A[i_min] , A[i_curr] );
      auto& A_i_min = A[i_min];
      MODINT inv = 1 / A_i_min[j_curr];
      
      for( int j = j_curr ; j < M ; j++ ){

	A_i_min[j] *= inv;

      }
      
      for( int i = i_min + 1 ; i < L ; i++ ){

	auto& A_i = A[i];
	const MODINT& A_i_j_curr = A_i[j_curr];

        if( A_i_j_curr != zero ){

          for( int j = M - 1 ; j >= j_curr ; j-- ){

            A_i[j] -= A_i_j_curr * A_i_min[j];

          }

        }

      }

      i_min++;

    }

    j_curr++;

  }
  
  return i_min;

}

template <typename MODINT>
pair<int,vector<MODINT>> ExtendedReducedRowEchelonForm( vector<vector<MODINT>>& A )
{

  const int L = A.size();
  constexpr int N = 1;
  vector<int> left( L , -1 );
  const MODINT& zero = MODINT::zero();
  const int M_N = L == 0 ? 0 : A[0].size() , M = M_N - N;
  assert( M >= 0 );
  int rank = RowEchelonForm( A );
  vector<bool> solvable( N , true );
  int i = rank;

  while( --i >= 0 ){

    auto& A_i = A[i];
    int& j = left[i];

    while( ++j < M ){

      if( A_i[j] != zero ){

	break;

      }

    }

    if( j == M ){

      while( j < M_N ){

	solvable[j] = solvable[j] && A_i[j] == zero;
        j++;

      }

      rank--;

    } else {

      int i_curr = i;

      while( --i_curr >= 0 ){

	auto& A_i_curr = A[i_curr];
	const MODINT A_i_curr_j = A_i_curr[j];

	for( int j_curr = j ; j_curr < M_N ; j_curr++ ){

	  A_i_curr[j_curr] -= A_i_curr_j * A_i[j_curr];

	}

      }

    }

  }

  vector<MODINT> solution{};

  if( solvable[0] ){

    solution.resize( M );
    i = rank;
  
    while( --i >= 0 ){

      auto& A_i = A[i];
      const int& j = left[i];
      solution[j] = A_i[M];

    }

  }

  return { rank , move( solution ) };

}

template <typename MODINT>
tuple<int,vector<bool>,vector<vector<MODINT>>> MultiExtendedReducedRowEchelonForm( vector<vector<MODINT>>& A , const int& N )
{

  const int L = A.size();
  vector<int> left( L , -1 );
  const MODINT& zero = MODINT::zero();
  const int M_N = L == 0 ? 0 : A[0].size() , M = M_N - N;
  assert( M >= 0 );
  int rank = RowEchelonForm( A );
  vector<bool> solvable( N , true );
  int i = rank;

  while( --i >= 0 ){

    auto& A_i = A[i];
    int& j = left[i];

    while( ++j < M ){

      if( A_i[j] != zero ){

	break;

      }

    }

    if( j == M ){

      while( j < M_N ){

	solvable[j] = solvable[j] && A_i[j] == zero;
        j++;

      }

      rank--;

    } else {

      int i_curr = i;

      while( --i_curr >= 0 ){

	auto& A_i_curr = A[i_curr];
	const MODINT A_i_curr_j = A_i_curr[j];

	for( int j_curr = j ; j_curr < M_N ; j_curr++ ){

	  A_i_curr[j_curr] -= A_i_curr_j * A_i[j_curr];

	}

      }

    }

  }

  vector<vector<MODINT>> solutions( M , vector<MODINT>( N ) );
  i = rank;
  
  while( --i >= 0 ){

    auto& A_i = A[i];
    const int& j = left[i];
    auto& solutions_j = solutions[j];
      
    for( int k = 0 ; k < N ; k++ ){

      solutions_j[k] = A_i[M + k];

    }

  }

  return { rank , move( solvable ) , move( solutions ) };

}

template <typename MODINT> inline int ReducedRowEchelonForm( vector<vector<MODINT>>& A ) { return get<0>( MultiExtendedReducedRowEchelonForm( A , 0 ) ); }

template <typename MODINT>
vector<vector<MODINT>> Inverse( const vector<vector<MODINT>>& A )
{

  const int L = A.size();
  vector A_copy( L , vector<MODINT>( L + L ) );

  for( int i = 0 ; i < L ; i++ ){

    auto& A_i = A[i];
    auto& A_copy_i = A_copy[i];

    for( int j = 0 ; j < L ; j++ ){

      A_copy_i[j] = A_i[j];

    }

    for( int j = 0 ; j < L ; j++ ){

      A_copy_i[L + j] = i == j ? 1 : 0;

    }
    
  }

  auto [rank,solvable,answer] = MultiExtendedReducedRowEchelonForm( A_copy , answer , L );
  if( rank != L ){

    answer.clear();

  }

  return answer;

}

template <typename MODINT>
pair<int,vector<MODINT>> LinearRelation( vector<vector<MODINT>>& A )
{

  const int L = A.size();
  const int M = A.empty() ? 0 : A[0].size();
  const int rank = ReducedRowEchelonForm( A );
  vector<MODINT> coeff{};

  if( rank < M ){
  
    coeff.resize( M );
    const MODINT& zero = MODINT::zero();
    int j = 0;
  
    while( j < L && A[j][j] != zero ){

      j++;

    }

    for( int i = 0 ; i < j ; i++ ){

      coeff[i] = -A[i][j];

    }

    coeff[j] = 1;

  }

  return { rank , move( coeff ) };

}
