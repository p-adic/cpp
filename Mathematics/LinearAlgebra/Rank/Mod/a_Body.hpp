// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Mod/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename MODINT>
int RowEchelonForm( vector<vector<MODINT>>& A )
{

  const int L = A.size() , M = L == 0 ? 0 : A[0].size();
  int i_min = 0 , i_curr , j_curr = 0;

  while( i_min < L && j_curr < M ){

    i_curr = i_min;

    while( i_curr < L && A[i_curr][j_curr] == 0 ){

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
	const MODINT A_i_j_curr = A_i[j_curr];

	for( int j = j_curr ; j < M ; j++ ){

	  A_i[j] -= A_i_j_curr * A_i_min[j];

	}

      }

      i_min++;

    }

    j_curr++;

  }
  
  return i_min;

}

template <typename MODINT>
pair<int,bool> ExtendedReducedRowEchelonForm( vector<vector<MODINT>>& A , const int& N )
{

  const int L = A.size();
  DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_MOD( int j = -1 );
  return { rank , solvable };

}

template <typename MODINT>
pair<int,bool> ExtendedReducedRowEchelonForm( vector<vector<MODINT>>& A , vector<MODINT>& solution )
{

  const int L = A.size();
  constexpr int N = 1;
  vector<int> left( L , -1 );
  DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_MOD( int& j = left[i] );

  if( solvable ){

    solution = vector<MODINT>( M );
    i = rank;
  
    while( --i >= 0 ){

      auto& A_i = A[i];
      const int& j = left[i];
      solution[j] = A_i[M];

    }

  }

  return { rank , solvable };

}

template <typename MODINT>
pair<int,bool> ExtendedReducedRowEchelonForm( vector<vector<MODINT>>& A , vector<vector<MODINT>>& solutions , const int& N )
{

  const int L = A.size();
  vector<int> left( L , -1 );
  DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_MOD( int& j = left[i] );

  if( solvable ){

    solutions = vector( M , vector<MODINT>( N ) );
    i = rank;
  
    while( --i >= 0 ){

      auto& A_i = A[i];
      const int& j = left[i];
      auto& solutions_j = solutions[j];
      
      for( int k = 0 ; k < N ; k++ ){

	solutions_j[k] = A_i[M + k];

      }

    }

  }

  return { rank , solvable };

}

template <typename MODINT> inline int ReducedRowEchelonForm( vector<vector<MODINT>>& A ) { const int L = A.size() , M = L == 0 ? 0 : A[0].size(); vector dummy( L , vector<MODINT>( 1 ) ); return ExtendedReducedRowEchelonForm( A , dummy , 0 ).first; }

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

  vector<vector<MODINT>> answer{};
  ExtendedReducedRowEchelonForm( A_copy , answer , L );
  return answer;

}
