// c:/Users/user/Documents/Programming/Mathematics/Graph/Algorithm/HeldKarp/a_Body.hpp

#pragma once
#include "a.hpp"

template <int NM , int P>
const ll& HeldKarp( const int& k_start , const int& k_goal , const int& s , const int (&k_valid)[P] , const int& P_valid , const ll (&path_E)[NM][NM] , const int (&near)[P][P][2] , const ll (&E_min)[P][P] , int (&k_mid)[P] )
{

  costexpr int S = ( 1 << 15 ) - 1;
  static ll answer_E[P][P][S];
  static int answer_mid[P][P][P];
  static bool solved[P][P][S];
  int (&answer_mid_kskg)[P] = answer_mid[k_start][k_goal]; 

  if( solved[k_start][k_goal][s] ){

    int P_valid_minus = P_valid - 1;

    for( int k = 0 ; k < P_valid_minus ; k++ ){

      k_mid[k] = answer_mid_kskg[k];

    }

    return answer_E[k_start][k_goal][s];

  }

  if( s == 0 ){

    k_mid[0] = answer_mid_kskg[0] = k_start;
    k_mid[1] = answer_mid_kskg[1] = k_goal;
    solved[k_start][k_goal][s] = true;
    return answer_E[k_start][k_goal][s] = answer_E[k_goal][k_start][s] = E_min[k_start][k_goal];

  }
  
  int card = 0;
  int k_s[P];
  int k_s_i = 0;

  while( s_copy != 0 ){

    if( ( s_copy & 1 ) == 1 ){

      k_s[card++] = k_s_i;

    }

    s_copy >>= 1;
    k_s_i++;

  }

  // \•ª‘å‚«‚¢’l
  ll E_current_min = ll( 1 ) << 62;
  int k_mid_current_min[P];
  int k_mid_current[P];
  int card_plus = card + 1;

  for( int i = 0 ; i < card ; i++ ){

    int& k = k_s[i];
    ll E_current = HeldKarp<NM,P>( k_start , k , 0 , k_valid , P_valid , path_E , near , E_min , k_mid );
    E_current += HeldKarp<NM,P>( k_start , k , s ^ ( 1 << k ) , k_valid , P_valid , path_E , near , E_min , k_mid_current );
    E_current += path_E[near[k_start][k][1]][near[k][k_mid_current[1]][0]];

    if( E_current_min > E_current ){

      E_current_min = E_current;

      for( int j = 0 ; j < card_plus ; j++ ){

	k_mid_current_min[j] = k_mid_current[j];

      }

    }

  }

  answer_mid_kskg[0] = k_start;

  for( int i = 0 ; i < card_plus ; i++ ){

    answer_mid_kskg[i+1] = k_mid[i+1] = k_mid_current_min[i];

  }

  solved[k_start][k_goal][s] = true;
  return answer_E[k_start][k_goal][s] = answer_E[k_goal][k_start][s] = E_current_min;

}

