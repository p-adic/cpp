// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Cost/a_Body.hpp

#pragma once
#include "a.hpp"

// AbstractNegativeCostKnapsackÇ…égÇ§ÅB
#include "../a_Body.hpp"
#include "../../../../Arithmetic/Power/Constexpr/Log/a_Body.hpp"

template <typename INT , typename U , typename COMM_MONOID>
vector<U> AbstractDualMulticaseNegativeCostKnapsack( COMM_MONOID M , const vector<INT>& value , const INT& value_sum_bound , const vector<U>& cost , const U& cost_sum_lbound , const U& exceptional )
{

  assert( value_sum_bound >= 0 );
  const int N = value.size();
  assert( int( cost.size() ) == N );
  vector cost_min( value_sum_bound + 1 , exceptional );
  const U& one = M.One();
  assert( !( cost_sum_lbound < exceptional ) && !( one < cost_sum_lbound ) );
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

template <typename INT1 , typename INT2> inline vector<INT2> DualMulticaseNegativeCostKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_lbound , const INT2& exceptional ) { return AbstractDualMulticaseNegativeCostKnapsack( AdditiveMonoid<INT2>() , value , value_sum_bound , cost , cost_sum_lbound , exceptional ); }

template <typename INT , typename U , typename COMM_MONOID> inline pair<INT,U> AbstractNegativeCostKnapsackFewValues( COMM_MONOID M , const vector<INT>& value , const INT& value_sum_bound , const vector<U>& cost , const U& cost_sum_bound , const U& exceptional ) { pair<INT,U> answer = { 0 , M.One() }; auto cost_min = AbstractDualMulticaseNegativeCostKnapsack( move( M ) , value , value_sum_bound , cost , exceptional , exceptional ); for( INT v = 0 ; v <= value_sum_bound ; v++ ){ auto& c_v = cost_min[v]; c_v == exceptional || cost_sum_bound < c_v ? answer : answer = { v , move( c_v ) }; } return answer; }
template <typename INT , typename U , typename COMM_MONOID> inline pair<INT,U> AbstractNegativeCostKnapsack( COMM_MONOID M , const vector<INT>& value , const INT& value_sum_bound , const vector<U>& cost , const U& cost_sum_bound , const U& exceptional ) { const int N = value.size(); return Log( ll( value_sum_bound ) ) < ll( N >> 1 ) ? AbstractNegativeCostKnapsackFewValues( move( M ) , value , value_sum_bound , cost , cost_sum_bound , exceptional ) : AbstractNegativeKnapsack( move( M ) , value , value_sum_bound , cost , cost_sum_bound ); }
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeCostKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound , const INT2& exceptional ) { return AbstractNegativeCostKnapsack( AdditiveMonoid<INT2>() , value , value_sum_bound , cost , cost_sum_bound , exceptional ); }
