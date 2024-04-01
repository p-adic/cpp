// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Multichoice/Unbounded/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Algebra/Monoid/a_Body.hpp"

template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractUnboundedChoiceMulticaseKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound )
{

  const int N = value.size();
  assert( int( cost.size() ) == N );
  auto& one = M.One();
  vector<U> value_max( cost_sum_bound + 1 , exceptional );
  value_max[0] = one;

  for( int i = 0 ; i < N ; i++ ){

    auto& value_i = value[i];
    auto& cost_i = cost[i];
    assert( ( cost_i > 0 && !( value_i < one ) ) || ( cost_i == 0 && value_i == one ) );

    if( cost_sum_bound < cost_i || value_sum_bound < value_i ){

      continue;

    }

    auto& value_max_i = value_max[cost_i];
    value_max_i = value_max_i == exceptional ? value_i : max( value_max[cost_i] , value_i );

  }

  auto answer = value_max;

  for( INT d = 1 ; d < cost_sum_bound ; d++ ){

    auto& value_max_d = value_max[d];

    if( value_max_d == exceptional ){

      continue;
      
    }
    
    for( INT c = d + d ; c <= cost_sum_bound ; c++ ){

      auto temp = M.Product( answer[c - d] , value_max_d );

      if( temp <= value_sum_bound ){
	
	assert( temp != exceptional );
	auto& answer_c = answer[c];
	answer_c = answer_c == exceptional ? move( temp ) : max( answer_c , temp );

      }
      
    }

  }

  return answer;

}

template <typename INT1 , typename INT2> inline vector<INT1> UnboundedChoiceMulticaseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound ) { return AbstractUnboundedChoiceMulticaseKnapsack( AdditiveMonoid<INT1>() , value , value_sum_bound , INT1( -1 ) , cost , cost_sum_bound ); }
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractUnboundedChoiceKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound ) { pair<U,INT> answer = { M.One() , 0 }; auto value_max = AbstractUnboundedChoiceMulticaseKnapsack( move( M ) , value , value_sum_bound , exceptional , cost , cost_sum_bound ); for( INT c = 0 ; c <= cost_sum_bound ; c++ ){ auto& v_c = value_max[c]; v_c != exceptional && answer.first < v_c ? answer = { move( v_c ) , c } : answer; } return answer; }
template <typename INT1 , typename INT2> inline pair<INT1,INT2> UnboundedChoiceKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound ) { return AbstractUnboundedChoiceKnapsack( AdditiveMonoid<INT1>() , value , value_sum_bound , INT1( -1 ) , cost , cost_sum_bound ); }

template <typename INT>
vector<bool> UnboundedChoiceCostfreeConstructibiilityKnapsack( const vector<INT>& value , const INT& value_sum_bound )
{

  const int N = value.size();
  vector<bool> valid( value_sum_bound + 1 );

  for( int i = 0 ; i < N ; i++ ){

    auto& value_i = value[i];
    assert( value_i >= 0 );

    if( value_sum_bound < value_i ){

      continue;

    }
    
    valid[value_i] = true;

  }

  auto answer = valid;

  for( INT d = 1 ; d < value_sum_bound ; d++ ){

    if( !valid[d] ){

      continue;
      
    }
    
    for( INT v = d + d ; v <= value_sum_bound ; v++ ){

      answer[v] |= answer[v - d];

    }

  }

  return answer;

}

template <typename INT> inline INT UnboundedChoiceCostfreeKnapsack( const vector<INT>& value , const INT& value_sum_bound ) { INT answer = 0; auto constructible = UnboundedChoiceCostfreeMulticaseKnapsack( value , value_sum_bound ); for( INT v = 0 ; v <= value_sum_bound ; v++ ){ constructible[v] ? answer = v : answer; } return answer; }
