// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/PartitionNumber/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
vector<vector<INT>> LowerBoundedPartitionNumber( const int& n )
{

  vector answer( n + 1 , vector<INT>( n + 1 ) );
  
  for( int i = 0 ; i <= n ; i++ ){

    answer[i][i] = 1;
    
    for( int j = i - 1 ; j >= 0 ; j-- ){

      answer[i][j] = answer[i][j+1] + answer[i-j][j];

    }

  }

  return answer;
  
}

template <typename INT>
vector<INT> PartitionNumber( const int& n )
{

  auto lbpn = LowerBoundedPartitionNumber<INT>( n );
  vector answer( n + 1 , INT{ 1 } );

  for( int i = 1 ; i <= n ; i++ ){

    answer[i] = lbpn[i][1];

  }

  return answer;

}

template <typename INT>
vector<vector<INT>> UpperBoundedPartitionNumber( const int& n )
{

  vector answer( n + 1 , vector<INT>( n + 1 ) );
  answer[0][0] = 1;
 
  for( int i = 0 ; i <= n ; i++ ){
    
    for( int j = 1 ; j <= i ; j++ ){

      // ‚Ü‚¸Å‘å’lj‚Ì‚à‚Ì‚ÌŒÂ”‚ðŒvŽZ‚·‚éB
      answer[i][j] = answer[i-j][j];

    }
      
    for( int j = 0 ; j < n ; j++ ){

      // ŽŸ‚É—ÝÏ˜a‚ðŽæ‚éB
      answer[i][j+1] += answer[i][j];

    }

  }

  return answer;    
  
}
