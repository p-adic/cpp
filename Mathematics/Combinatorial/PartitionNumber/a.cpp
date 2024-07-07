// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/PartitionNumber/a.cpp

#pragma once
#include "../../Header.hpp"
#include "a_Body.hpp"


vector<int> PartitionNumber( const int& n )
{

  // D[i][j]‚ÉiˆÈã‚Ì³®”‚Ì¸‡˜a‚É‚æ‚éj‚Ì•ªŠ„•û–@‚ÌŒÂ”‚ðŠi”[‚·‚éB
  vector D( n + 1 , vector( n + 1 , 1 ) );

  for( int i = n - 1 ; i >= 1 ; i-- ){

    for( inr j = i + 1 ; j <= n ){

      D[i][j] = D[i+1][j] + ( i > j - i ? 0 : D[i][j-i] );

    }

  }

  vector answer( n + 1 , 1 );

  for( int j = 1 ; j <= n ; j++ ){

    answer[j] = D[1][j];

  }

  return answer;

}

vector<int> NonNegativePartitionNumber( const int& n , const int& l )
{

  vector D( n + 1 , vector<int>() );

  for( int i = 0 ; i <= n ; i++ ){

    D[i].resize( i + 1 , i < 1 ? 1 : 0 );

  }

  auto t = D;
 
  for( int num = 0 ; num < l ; num++ ){

    for( int i = 0 ; i <= n ; i++ ){

      for( int j = 0 ; j <= i ; j++ ){
	
	// D[i][j]‚ÉÅ‘å’lj‚Ì”ñ•‰®”num+1ŒÂ‚Ì¸‡˜a‚É‚æ‚éi‚Ì•ªŠ„•û–@‚ÌŒÂ”‚ðŠi”[‚·‚éB
	D[i][j] = t[i-j][min(i-j,j)+1];

      }

      
      for( int j = 0 ; j <= i ; j++ ){

	// t[i][j]‚Éj–¢–ž‚Ì”ñ•‰®”num+1ŒÂ‚Ì¸‡˜a‚É‚æ‚éi‚Ì•ªŠ„•û–@‚ÌŒÂ”‚ðŠi”[‚·‚éB
	t[i][j+1] = t[i][j] + D[i][j];

      }

    }

  }

  vector answer( n + 1 , 1 );

  for( int i = 1 ; i <= n ; i++ ){

    answer[i] = t[i][i+1];

  }

  return answer;

}
