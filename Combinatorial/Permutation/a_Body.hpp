// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Permutation/a_Body.hpp

#pragma once
#include "a.hpp"

// NextPermutationとPreviousPermutationに使う。
#include <algorithm>

// InversionNumberに使う。
#ifdef DEBUG
  #include "../../SetTheory/DirectProduct/AffineSpace/BIT/Debug/a_Body.hpp"
#else
  #include "../../SetTheory/DirectProduct/AffineSpace/BIT/a_Body.hpp"
#endif

// PermtationOrderに使う。
#include "../../Arithmetic/Divisor/GCD/a_Body.hpp"

template <typename INT , int size_max> inline bool NextPermutation( INT ( &P )[size_max] , const int& size ) { return next_permutation( P , P + size ); }
template <typename INT> inline bool NextPermutation( vector<INT>& P ) {  return next_permutation( P.begin() , P.end() ); }
template <typename INT , int size_max> inline bool PreviousPermutation( INT ( &P )[size_max] , const int& size ) { return prev_permutation( P , P + size ); }
template <typename INT> inline bool PreviousPermutation( vector<INT>& P ) {  return prev_permutation( P.begin() , P.end() ); }

template <typename INT>
ll InversionNumber( const vector<INT>& P )
{

  const int size = P.size();
  BIT<int> count{ size };
  ll answer = 0;
  
  for( int i = size - 1 ; i >= 0 ; i-- ){

    answer += count.IntervalSum( 0 , P[i] - 1 );
    count.Add( P[i] , 1 );

  }

  return answer;

}

template <typename INT>
vector<vector<INT>> CyclicPermutationRepresentation( const vector<INT>& P , const bool& zero_indexed )
{

  if( !zero_indexed ){

    auto Q = P;

    for( auto& i : Q ){

      i--;

    }

    auto answer = CyclicPermutationRepresentation( Q );

    for( auto& C : answer ){

      for( auto& i : C ){

        i++;

      }

    }

    return answer;

  }
  
  const int size = P.size();
  vector<vector<INT>> answer{};
  vector<bool> found( size );

  for( int i = 0 ; i < size ; i++ ){

    if( found[i] ){

      continue;

    }

    vector<INT> temp = { i };
    found[i] = true;
    int j = P[i];

    while( j != i ){

      found[j] = true;
      temp.push_back( j );
      j = P[j];

    }

    if( temp.size() > 1 ){

      answer.push_back( move( temp ) );

    }

  }
  
  return answer;

}

template <typename INT>
vector<pair<INT,INT>> MinimalTranspositionRepresentation( const vector<INT>& P , const bool& zero_indexed )
{

  auto crp = CyclicPermutationRepresentation( P , zero_indexed );
  vector<pair<INT,INT>> answer{};

  for( auto& C : crp ){

    const int size = C.size();

    for( int i = size - 1 ; i > 0 ; i-- ){

      answer.push_back( { C[0] , C[i] } );

    }

  }

  return answer;

}

template <typename INT>
vector<pair<INT,INT>> MinimalAdjacentTranspositionRepresentation( vector<INT> P , const bool& zero_indexed )
{

  const int size = P.size();
  const INT d = zero_indexed ? 0 : 1;
  vector<pair<INT,INT>> answer{};
  
  for( int i = 0 ; i < size ; i++ ){

    for( int j = i - 1 ; j >= 0 ; j-- ){

      if( P[j] < P[j+1] ){

        break;
        
      }

      swap( P[j] , P[j+1] );
      answer.push_back( {d+j,d+j+1} );

    }

  }

  return answer;
  
}

template <typename INT>
ll PermutationOrder( const vector<INT>& P , const bool& zero_indexed )
{

  auto crp = CyclicPermutationRepresentation( P , zero_indexed );
  const int size = crp.size();
  vector<ll> order( size );

  for( int i = 0 ; i < size ; i++ ){

    order[i] = crp[i].size();

  }

  return LCM( order );

}

template <typename INT>
INT LeastSwapCount( const vector<INT>& P , const bool& zero_indexed )
{

  auto crp = CyclicPermutationRepresentation( P , zero_indexed );
  INT answer = 0;

  for( auto& C : crp ){

    answer += C.size() - 1;

  }

  return answer;

}

template <typename INT> inline ll LeastSwapCount( const vector<INT>& P ){ return InversionNumber( P ); }


