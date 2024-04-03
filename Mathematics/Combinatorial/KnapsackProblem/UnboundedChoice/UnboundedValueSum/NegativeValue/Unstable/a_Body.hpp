// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/UnboundedChoice/UnboundedValueSum/NegativeValue/Unstable/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U , typename COMM_MONOID , typename VALUE , typename INT1 , typename COST , typename INT2>
vector<U> AbstractNegativeValueUnboundedChoiceMulticaseUnboundedValueSumUnstableKnapsack( COMM_MONOID M , const int& N , VALUE value , const U& exceptional , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_stability_num )
{

  static_assert( is_invocable_r_v<U,VALUE,const int&,const int&> && is_invocable_r_v<INT1,COST,const int&,const int&> );
  auto& one = M.One();
  vector answer( cost_sum_bound + 1 , exceptional );
  answer[0] = one;

  for( int i = 0 ; i < N ; i++ ){

    int choice_stability_num_i = choice_stability_num[i];
    int choice_num = -1;
    INT c_min = 0;
    auto temp = answer;

    while( ++choice_num < choice_stability_num_i && c_min < cost_sum_bound ){

      vector temp_next( cost_sum_bound + 1 , exceptional );
      auto&& v_i = value( i , choice_num );
      auto&& c_i = cost( i , choice_num );
      assert( c_i >= 0 );
      c_min += c_i;

      for( INT c = cost_sum_bound ; c >= c_min ; c-- ){

	auto& temp_c_i = temp[c - c_i];

	if( temp_c_i != exceptional ){

	  auto& temp_next_c = temp_next[c] = M.Product( temp_c_i , value_i );
	  auto& answer_c = answer[c];
	  answer_c = answer_c == exceptional ? temp_next_c : max( answer_c , temp_next_c );

	}
	
      }

      temp = move( temp_next );

    }

    if( choice_num == choice_stability_num_i ){

      auto&& v_i = value( i , choice_num );
      auto&& c_i = cost( i , choice_num );
      assert( one < v_i ? c_i > 0 : c_i >= 0 );
      const INT c_max = c_i < cost_sum_bound ? cost_sum_bound - c_i : 0;

      for( INT c = c_min ; c <= c_max ; c++ ){

	auto& temp_c = temp[c];

	if( temp_c != exceptional ){
	  
	  auto& temp_c_i = temp[c + c_i];
	  auto temp_c_i_new = M.Product( temp_c , v_i );
	  temp_c_i = temp_c_i == exceptional ? move( temp_c_i_new ) : max( temp_c_i , temp_c_i_new );
	  auto& answer_c_i = answer[c + c_i];
	  answer_c_i = answer_c_i == exceptional ? temp_c_i : max( answer_c_i , temp_c_i );

	}

      }
	
    }
    
  }

  return answer;

}

template <typename VALUE , typename INT1 , typename COST , typename INT2> inline vector<ret_t<VALUE,int,int>> NegativeValueUnboundedChoiceMulticaseUnboundedValueSumUnstableKnapsack( const int& N , VALUE value , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_stability_num ) { return AbstractNegativeValueUnboundedChoiceMulticaseUnboundedValueSumUnstableKnapsack( AdditiveMonoid<ret_t<VALUE,int,int>>() , value , ret_t<VALUE,int,int>( -1 ) , move( cost ) , cost_sum_bound , choice_stability_num ); }
template <typename U , typename COMM_MONOID , typename VALUE , typename INT1 , typename COST , typename INT2> inline pair<U,INT1> AbstractNegativeValueUnboundedChoiceUnboundedValueSumUnstableKnapsack( COMM_MONOID M , const int& N , VALUE value , const U& exceptional , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_stability_num ) { pair<U,INT1> answer = { M.One() , 0 }; auto value_max = AbstractUnboundedChoiceMulticaseUnstableKnapsack( move( M ) , move( value ) , exceptional , move( cost ) , cost_sum_bound , choice_stability_num ); for( INT c = 0 ; c <= cost_sum_bound ; c++ ){ auto& v_c = value_max[c]; v_c != exceptional && answer.first < v_c ? answer = { move( v_c ) , c } : answer; } return answer; }
template <typename VALUE , typename INT1 , typename COST , typename INT2> inline pair<ret_t<VALUE,int,int>,INT1> NegativeValueUnboundedChoiceUnboundedValueSumUnstableKnapsack( const int& N , VALUE value , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_stability_num ) { return AbstractNegativeValueUnboundedChoiceUnboundedValueSumUnstableKnapsack( AdditiveMonoid<ret_t<VALUE,int,int>>() , move( value ) , ret_t<VALUE,int,int>( -1 ) , move( cost ) , cost_sum_bound , choice_stability_num ); }
