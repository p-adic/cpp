// c:/Users/user/Documents/Programming/Utility/String/Z-Algorithm/a_Body.hpp

#pragma once
#include "a.hpp"

vector<int> LCP( const string& S )
{

  const int size = S.size();
  vector<int> answer( size + 1 );
  answer[0] = size;
  int j_curr = 0;
  int j_lim , j_sub , answer_j_sub;
  
  for( int i = 1 ; i <= size ; i++ ){

    int& answer_i = answer[i];
    j_lim = size - i;
    answer_i = j_lim;

    while( j_curr < j_lim ){

      if( S[j_curr] != S[i + j_curr] ){

	answer_i = j_curr;
	break;

      }

      j_curr++;

    }

    if( j_curr != 0 ){

      j_sub = 1;
      answer_j_sub = answer[j_sub];

      while( j_sub + answer_j_sub < j_curr ){

	answer[++i] = answer_j_sub;
	j_sub++;
	answer_j_sub = answer[j_sub];

      }

      j_curr -= j_sub;

    }

  }

  return answer;

}
