// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/InitialSegment/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , typename VALUE>
int CostfreeInitialSegmentKnapsack( const ll& N , VALUE value , const INT& value_sum_bound , const bool& cumulative )
{

  static_assert( is_invocable_r_v<INT,VALUE,const ll&> );
  
  if( cumulative ){

    ll l = 0 , r = N;

    while( l < r - 1 ){

      ll m = ( l + r ) >> 1;
      ( value( m ) > value_sum_bound ? r : l ) = m;

    }

    return l;

  }
  
  INT temp = 0;
  int answer = -1;

  while( answer + 1 < N && ( temp += value( answer + 1 ) ) <= value_sum_bound ){

    ++answer;

  }

  return answer;
  
}

template <typename INT , typename VALUE>
INT CostfreeInitialSegmentDoubleKnapsackValueSumBound( const ll& N , VALUE value , const INT& value_sum_bound_0 , const INT& value_sum_bound_1 , const INT& unpresentable_max , const bool& cumulative )
{

  if( N == 0 ){

    return 0;

  }

  auto value_fixed = [&]( const ll& k ){ return value( k ) - ( cumulative && k > 0 ? value( k - 1 ) : 0 ); };
  const INT& V_min = value_sum_bound_0 > value_sum_bound_1 ? value_sum_bound_1 : value_sum_bound_0;
  const INT& V_max = value_sum_bound_0 > value_sum_bound_1 ? value_sum_bound_0 : value_sum_bound_1;
  const INT L = unpresentable_max << 1;
  ll l = 0 , N_1 = N;
 
  while( l < N_1 - 1 ){

    ll m = ( l + N_1 ) >> 1;
    ( value_fixed( m ) > L ? N_1 : l ) = m;

  }

  ll N_2;

  if( cumulative ){

    l = 0 , N_2 = N_1;

    while( l < N_2 - 1 ){

      ll m = ( l + N_2 ) >> 1;
      ( value( m ) > V_min ? N_2 : l ) = m;

    }

  } else {

    N_2 = 0;
    INT sum = 0;

    while( N_2 < N_1 && ( sum += value( N_2 ) ) <= V_min ){

      ++N_2;

    }

  }

  if( N_1 == N_2 && N_1 < N ){

    return V_min + V_max;

  }

  l = N_2;
  ll N_3 = N;

  while( l < N_3 - 1 ){

    ll m = ( l + N_3 ) >> 1;
    ( value_fixed( m ) > V_min ? N_3 : l ) = m;

  }
  
  vector<bool> dp( V_min + 1 ) , ndp( V_min + 1 );
  dp[0] = true;
  INT V = 0 , sum = 0;

  for( int i = 0 ; i < N_3 ; i++ ){

    auto&& value_i = value_fixed( i );
    sum += value_i;
    
    for( INT v = 0 ; v <= V_min ; v++ ){

      ( ndp[v] = ( ( dp[v] && sum - v <= V_max ) || ( v >= value_i && dp[v - value_i] ) ) ) && V < v ? V = v : V;

    }

    swap( dp , ndp );

  }

  return V + V_max;

}

template <typename INT , typename VALUE> inline int CostfreeInitialSegmentDoubleKnapsack( const ll& N , VALUE value , const INT& value_sum_bound_0 , const INT& value_sum_bound_1 , const INT& unpresentable_max , const bool& cumulative ) { return CostfreeInitialSegmentKnapsack( N , value , CostfreeInitialSegmentDoubleKnapsackValueSumBound( N , value , value_sum_bound_0 , value_sum_bound_1 , unpresentable_max , cumulative ) , cumulative ); }

