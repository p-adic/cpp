// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Cost/Valuewise/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , typename U , typename COMM_MONOID>
vector<U> AbstractNegativeCostBoundedValueSumValuewiseKnapsack( COMM_MONOID M , const vector<INT>& value , const INT& value_sum_bound , const vector<U>& cost , const U& cost_sum_lbound , const U& exceptional )
{

  assert( value_sum_bound >= 0 );
  const int N = value.size();
  assert( int( cost.size() ) == N );
  vector cost_min( value_sum_bound + 1 , exceptional );
  const U& one = M.One();
  assert( !( one < cost_sum_lbound ) );
  cost_min[0] = one;

  for( int i = 0 ; i < N ; i++ ){

    auto& value_i = value[i];
    assert( value_i >= 0 );
    auto& cost_i = cost[i];

    for( INT v = value_sum_bound , v_plus = v + 1 ; v_plus > value_i ; v-- , v_plus-- ){

      auto& cost_min_v_i = cost_min[v - value_i];

      if( cost_min_v_i != exceptional ){

	auto temp = M.Product( cost_min[v - value_i] , cost_i );

	if( !( temp < cost_sum_lbound ) ){
	
	  auto& cost_min_v = cost_min[v];
	  cost_min_v = cost_min_v == exceptional ? move( temp ) : min( cost_min_v , temp );

	}

      }
      
    }

  }

  return cost_min;

}

template <typename INT1 , typename INT2> inline vector<INT2> NegativeCostBoundedValueSumValuewiseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_lbound , const INT2& exceptional ) { return AbstractNegativeCostBoundedValueSumValuewiseKnapsack( AdditiveMonoid<INT2>() , value , value_sum_bound , cost , cost_sum_lbound , exceptional ); }
