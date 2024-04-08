// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/Unstable/a_Body,hpp

#pragma once
#include "a.hpp"

template <typename U , typename COMM_MONOID , typename VALUE , typename INT1 , typename COST , typename INT2>
vector<U> AbstractValueBoundedChoiceUnstableCostwiseKnapsack( COMM_MONOID M , const int& N , VALUE value , const U& exceptional , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound )
{

  static_assert( is_invocable_r_v<U,VALUE,const int&,const ll&> && is_invocable_r_v<INT1,COST,const int&,const ll&> );
  auto& one = M.One();
  vector answer( cost_sum_bound + 1 , exceptional );
  answer[0] = one;

  for( int i = 0 ; i < N ; i++ ){

    auto& choice_num_bound_i = choice_num_bound[i];
    INT c_min = 0;
    auto temp = answer;

    for( int choice_num = 0 ; choice_num < choice_num_bound_i && c_min < cost_sum_bound ; choice_num++ ){

      auto&& v_i = value( i , choice_num );
      assert( !( v_i < M.One() ) );
      auto&& c_i = cost( i , choice_num );
      assert( c_i >= 0 );
      c_min += c_i;

      for( INT c = cost_sum_bound ; c >= c_min ; c-- ){

	auto& answer_c = answer[c];
	auto& temp_c_i = temp[c - c_i];

	if( temp_c_i != exceptional ){
	  
	  auto& temp_c = temp[c] = M.Product( temp_c_i , v_i );
	  answer_c = answer_c == exceptional ? temp_c : max( answer_c , temp_c );

	}
	
      }

    }

  }

  return answer;

}

template <typename VALUE , typename INT1 , typename COST , typename INT2> inline vector<ret_t<VALUE,int,int>> BoundedChoiceUnstableCostwiseKnapsack( const int& N , VALUE value , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound ) { return AbstractValueBoundedChoiceUnstablewiseCostKnapsack( AdditiveMonoid<ret_t<VALUE,int,int>>() , N , move( value ) , ret_t<VALUE,int,int>( -1 ) , move( cost ) , cost_sum_bound , choice_num_bound ); }
template <typename U , typename COMM_MONOID , typename VALUE , typename INT1 , typename COST , typename INT2> inline pair<U,INT1> AbstractBoundedChoiceUnstableKnapsack( COMM_MONOID M , const int& N , VALUE value , const U& exceptional , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound ) { pair<U,INT1> answer = { M.One() , 0 }; auto value_max = AbstractValueBoundedChoiceUnstableCostwiseKnapsack( move( M ) , N , move( value ) , exceptional , move( cost ) , cost_sum_bound , choice_num_bound ); for( INT c = 0 ; c <= cost_sum_bound ; c++ ){ auto& v_c = value_max[c]; v_c != exceptional && answer.first < v_c ? answer = { move( v_c ) , c } : answer; } return answer; }
template <typename VALUE , typename INT1 , typename COST , typename INT2> inline pair<ret_t<VALUE,int,int>,INT1> BoundedChoiceUnstableKnapsack( const int& N , VALUE value , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound ) { return AbstractBoundedChoiceUnstableKnapsack( AdditiveMonoid<ret_t<VALUE,int,int>>() , N , move( value ) , ret_t<VALUE,int,int>( -1 ) , move( cost ) , cost_sum_bound , choice_num_bound ); }
