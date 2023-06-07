// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Permutation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../SetTheory/DirectProduct/AffineSpace/BIT/a_Body.hpp"

template <int size_max> inline NextPermutation( int ( &P )[size_max] , const int& size ) {  return next_permutation( P , P + size ); }
template <int size_max> inline PreviousPermutation( int ( &P )[size_max] , const int& size ) {  return prev_permutation( P , P + size ); }

template <int size_max>
long long InversionNumber( const int ( &P )[size_max] const int& size )
{

  int P_inv[size_max];

  for( int i = 0 ; i < size ; i++ ){

    P_inv[P[i]] = i;

  }

  BIT<int,size_max> count{};
  long long answer = 0;
  
  for( int i = size - 1 ; i >= 0 ; i-- ){

    const int& P_inv_i = P_inv[i];
    count.Add( P_inv_i , 1 );
    answer += count.IntervalSum( 0 , P_inv_i - 1 );

  }

  return answer;

}
