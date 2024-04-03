// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Restrictive/a_Body.hpp

#pragma once
#include "a.hpp"


template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2>
pair<U1,U2> AbstractNegativeRestrictiveBoundedValueSumKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const U1& value_sum_ubound , const U1& exceptional , const vector<U2>& cost , const U2& cost_sum_lbound , const U2& cost_sum_ubound )
{

  const int N = value.size();
  assert( int( cost.size() ) == N );
  const U1& one1 = M1.One();
  assert( !( value_sum_ubound < one1 ) );
  const U2& one2 = M2.One();
  assert( !( one2 < cost_sum_lbound ) && !( cost_sum_ubound < one2 ) );
  pair<U1,U2> answer = { one1 , one2 };
  const int power = 1 << N;
  vector<pair<U1,U2>> sum( power , { exceptional , one2 } );
  sum[0] = { one1 , one2 };

  for( int s = 1 ; s < power ; s++ ){

    auto& sum_s = sum[s];

    for( int i = 0 ; i < N ; i++ ){

      if( ( ( s >> i ) & 1 ) == 0 ){

	continue;
	
      }
      
      auto& sum_s_minus = sum[s ^ ( 1 << i )];

      if( sum_s_minus.first != exceptional &&
	  !( sum_s_minus.second < cost_sum_lbound ) &&
	  !( cost_sum_ubound < sum_s_minus.second ) ){

	sum_s.first = M1.Product( sum_s_minus.first , value[i] );
	sum_s.second = M2.Product( sum_s_minus.second , cost[i] );
	!( value_sum_ubound < sum_s.first )&&
	  !( sum_s.second < cost_sum_lbound ) && !( cost_sum_ubound < sum_s.second ) &&
	  ( answer.first < sum_s.first || ( answer.first == sum_s.first && sum_s.second < answer.second ) ) ? answer = sum_s : answer;
	break;

      }

    }

  }

  return answer;
  
}

template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeRestrictiveBoundedValueSumKnapsack( const vector<INT1>& value , const INT1& value_sum_ubound , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_lbound , const INT2& cost_sum_ubound ) { return AbstractNegativeRestrictiveBoundedValueSumKnapsack( AdditiveMonoid<INT1>() , AdditiveMonoid<INT2>() , value , value_sum_ubound , exceptional , cost , cost_sum_lbound , cost_sum_ubound ); }

