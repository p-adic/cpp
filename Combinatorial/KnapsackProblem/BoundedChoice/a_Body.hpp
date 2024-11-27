// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/a_Body.hpp

#pragma once
#include "a.hpp"

// BoundedChoiceKnapsackFewItemsÇ…égÇ§ÅB
#include "ValueSumBound/a_Body.hpp"
#include "../a_Body.hpp"

template <typename U1 , typename N_MODULE1 , typename U2 , typename N_MODULE2 , typename INT>
void SetIteratedItem( N_MODULE1 M1 , N_MODULE2 M2 , const int& N , const vector<U1>& value , vector<U1>& value_new , const vector<U2>& cost , vector<U2>& cost_new , const vector<INT>& choice_num_bound )
{

  static_assert( !is_same_v<U1,int> && !is_same_v<U1,uint> );
  static_assert( !is_same_v<U2,int> && !is_same_v<U2,uint> );

  for( int i = 0 ; i < N ; i++ ){

    auto value_i = value[i];
    auto cost_i = cost[i];
    ll m = choice_num_bound[i];
    ll p = 1;

    while( p <= m ){

      m -= p;
      value_new.push_back( value_i );
      cost_new.push_back( cost_i );
      value_i = M1.Product( value_i , value_i );
      cost_i = M2.Product( cost_i , cost_i );
      p <<= 1;

    }

    if( m > 0 ){

      value_new.push_back( M1.Power( value[i] , m ) );
      cost_new.push_back( M2.Power( cost[i] , m ) );

    }

  }

  return;

}

template <typename INT1 , typename INT2 , typename INT3> inline pair<INT1,INT2> BoundedChoiceKnapsackFewItems( const int& N , const vector<INT1>& value , const vector<INT2>& cost , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound ) { vector<INT1> value_new; vector<INT2> cost_new; SetIteratedItem( Module<int,INT1>() , Module<int,INT2>() , N , value , value_new , cost , cost_new , move( choice_num_bound ) ); return Knapsack( value_new , cost_new , cost_sum_bound ); }

template <typename INT1 , typename INT2 , typename INT3>
pair<INT1,INT2> BoundedChoiceKnapsackFewValues( const int& N , const vector<INT1>& value , const INT1& value_bound , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound )
{

  const INT1 value_sum_range = min( value_sum_bound , value_bound * value_bound * INT1( N ) );
  vector<INT1> value_new{};
  vector<INT2> cost_new{};
  vector<int> choice_num_bound_new( N );
  
  for( int i = 0 ; i < N ; i++ ){

    assert( value[i] >= 0 );
    choice_num_bound_new[i] = value[i] > 0 ? int( min( ll( choice_num_bound[i] ) , ll( value_bound ) ) ) : 0;

  }
  
  SetIteratedItem( Module<int,INT1>() , Module<int,INT2>() , N , value , value_new , cost , cost_new , choice_num_bound_new );
  auto cost_min = NegativeCostBoundedValueSumValuewiseKnapsack( value_new , value_sum_range , cost_new , INT2( 0 ) , INT2( -1 ) );

  pair<INT1,INT2> answer = { 0 , 0 };
  vector<pair<double,int>> item( N );

  for( int i = 0 ; i < N ; i++ ){

    item[i] = { double( cost[i] ) / value[i] , i };
    value[i] > 0 ? choice_num_bound_new[i] = choice_num_bound[i] - choice_num_bound_new[i] : 0;

  }

  sort( item.begin() , item.end() );

  for( INT1 v = 0 ; v <= value_sum_range ; v++ ){

    auto& c_v = cost_min[v];
    
    if( c_v != -1 && c_v <= cost_sum_bound ){
      
      ll value_rest = value_sum_bound - v;
      ll cost_rest = cost_sum_bound - c_v;

      for( int j = 0 ; j < N ; j++ ){

	const int& i = item[j].second;
	ll num = choice_num_bound_new[i];
	num = min( num , value_rest / ll( value[i] ) );
	cost[i] > 0 ? num = min( num , cost_rest / ll( cost[i] ) ) : num;
	value_rest -= ll( value[i] ) * num;
	cost_rest -= ll( cost[i] ) * num;
	
      }

      pair<INT1,INT2> temp = { value_sum_bound - value_rest , cost_sum_bound - cost_rest };
      answer.first < temp.first || ( answer.first == temp.first && temp.second < answer.second ) ? answer = move( temp ) : answer;

    }

  }

  return answer;

}

template <typename INT1 , typename INT2 , typename INT3> inline pair<INT1,INT2> BoundedChoiceKnapsack( const vector<INT1>& value , const vector<INT2>& cost , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound ) { const int N = value.size(); const INT1 value_sum_bound = BoundedChoiceValueSumBound( value , cost_sum_bound , choice_num_bound ); INT1 v_max = 0; ll cn_max = 0; for( int i = 0 ; i < N ; i++ ){ v_max = max( v_max , value[i] ); value[i] > 0 ? cn_max = max( cn_max , min( ll( choice_num_bound[i] ) , value_sum_bound ) ) : cn_max; } const ll log_N = Log( N ) , log_v_max = Log( ll( v_max ) ) , log_cn_max = Log( cn_max ); return log_N + min( Log( min( ll( cost_sum_bound ) , ll( value_sum_bound ) ) ) , log_cn_max + ( N >> 1 ) ) + Log( log_cn_max ) < ( log_N << 1 ) + ( log_v_max << 1 ) + Log( log_v_max ) ? BoundedChoiceKnapsackFewItems( N , value , cost , cost_sum_bound , choice_num_bound ) : BoundedChoiceKnapsackFewValues( N , value , v_max , value_sum_bound , cost , cost_sum_bound , choice_num_bound ); }
