// c:/Users/user/Documents/Programming/Utility/String/Palindrome/a_Body.hpp

#pragma once
#include "a.hpp"

// PalindromeÇ…égópÅB
#include "../RollingHash/a_Body.hpp"

vector<bool> Palindrome( const string& S , const bool& reversed )
{
  
  const int N = S.size();
  vector answer( N , true );
  RollingHash<MP,ll> rh{};
  auto code = rh.PointwiseEncode( S , reversed );
  auto left = code[0] , right = code[1];

  for( int r = 1 ; r < N ; r++ ){

    left = rh.Concatenate( move( left ) , code[r] );
    right = rh.Concatenate( code[r] , move( right ) );
    answer[reversed ? N - 1 - r : r] = left == right;

  }
  
  return answer;

}

vector<vector<bool>> TotalPalindrome( const string& S )
{
  
  const int N = S.size();
  vector answer( N , vector<bool>() );
  answer[0].resize( 1 , true );

  for( int r = 1 ; r < N ; r++ ){

    const vector<bool>& answer_r_minus = answer[r-1];
    vector<bool>& answer_r = answer[r];
    answer_r.resize( r + 1 , true );

    for( int l = 0 ; l <= r ; l++ ){
      
      answer_r[l] = ( S[l] == S[r] ) && answer_r_minus[l+1];

    }

  }

  return answer;

}
