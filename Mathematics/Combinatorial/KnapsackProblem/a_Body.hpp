// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Algebra/Monoid/a_Body.hpp"
// KnapsackFewItemsとCostfreeKnapsackFewItemsに使う。
#include "../../../Utility/BinarySearch/a_Body.hpp"
// Knapsackに使う。
#include "../../Arithmetic/Power/Constexpr/Log/a_Body.hpp"

template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractMulticaseKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound )
{

  const int N = value.size();
  assert( int( cost.size() ) == N );
  auto& one = M.One();
  vector answer( cost_sum_bound + 1 , exceptional );
  answer[0] = one;

  for( int i = 0 ; i < N ; i++ ){

    auto& value_i = value[i];
    assert( !( value_i < one ) );
    auto& cost_i = cost[i];
    assert( cost_i >= 0 );

    if( cost_sum_bound < cost_i || value_sum_bound < value_i ){

      continue;

    }

    for( INT c = cost_sum_bound ; c >= cost_i ; c-- ){

      auto temp = M.Product( answer[c - cost_i] , value_i );

      if( temp <= value_sum_bound ){
	
	assert( temp != exceptional );
	auto& answer_c = answer[c];
	answer_c = answer_c == exceptional ? move( temp ) : max( answer_c , temp );

      }
      
    }

  }

  return answer;

}

template <typename INT1 , typename INT2> inline vector<INT1> MulticaseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound ) { return Knapsack( AdditiveMonoid<INT1>() , value , value_sum_bound , INT1( -1 ) , cost , cost_sum_bound ); }
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound ) { pair<U,INT> answer = { M.One() , 0 }; auto value_max = AbstractMulticaseKnapsack( move( M ) , value , value_sum_bound , exceptional , cost , cost_sum_bound ); for( INT c = 0 ; c <= cost_sum_bound ; c++ ){ auto& v_c = value_max[c]; v_c != exceptional && ( answer.first < v_c || ( answer.first == v_c && c < answer.second ) ) ? answer = { move( v_c ) , c } : answer; } return answer; }

template <typename INT1 , typename INT2>
vector<INT2> DualMulticaseKnapsackFewValues( const int& N , const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound )
{

  vector cost_min( value_sum_bound + 1 , INT2( -1 ) );
  cost_min[0] = 0;

  for( int i = 0 ; i < N ; i++ ){

    auto& value_i = value[i];
    assert( value_i >= 0 );
    auto& cost_i = cost[i];
    assert( cost_i >= 0 );

    if( cost_sum_bound < cost_i || value_sum_bound < value_i ){

      continue;

    }

    for( INT1 v = value_sum_bound , v_plus = v + 1 ; v_plus > value_i ; v-- , v_plus-- ){

      auto& cost_min_v_i = cost_min[v - value_i];

      if( cost_min_v_i != -1 ){

	auto temp = cost_min[v - value_i] + cost_i;

	if( temp <= cost_sum_bound ){
	
	  auto& cost_min_v = cost_min[v];
	  cost_min_v = cost_min_v == -1 ? move( temp ) : min( cost_min_v , temp );

	}

      }
      
    }

  }

  return cost_min;

}

template <typename INT1 , typename INT2> inline pair<INT1,INT2> KnapsackFewValues( const int& N , const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound ) { auto cost_min = DualMulticaseKnapsackFewValues( N , value , value_sum_bound , cost , cost_sum_bound ); pair<INT1,INT2> answer = { 0 , 0 }; for( INT2 v = 0 ; v <= value_sum_bound ; v++ ){ auto& c_v = cost_min[v]; c_v == -1 ? answer : answer = { v , move( c_v ) }; } return answer; }

template <typename INT1 , typename INT2>
pair<INT1,INT2> KnapsackFewItems( const int& N , const vector<INT2>& value , const INT2& value_sum_bound , const vector<INT1>& cost , const INT1& cost_sum_bound )
{

  pair<INT1,INT2> answer = { 0 , 0 };

  if( N == 1 ){

    if( cost[0] <= cost_sum_bound && value[0] <= value_sum_bound ){
      
      answer = { value[0] , cost[0] };

    }

  } else if( N > 1 ){

    const int N_half_left = N >> 1;
    const int N_half_right = N - N_half_left;
    unordered_map<int,int> valuation{};

    for( int i = 0 ; i < N_half_right ; i++ ){

      valuation[1<<i] = i;

    }
    
    const int power_left = 1 << N_half_left;
    vector<pair<INT2,INT1>> sum_left( power_left );

    for( int s = 1 ; s < power_left ; s++ ){

      const int lsb = s & -s;
      const int& i = valuation[lsb];
      auto& sum_left_s = sum_left[s];
      auto& sum_left_s_minus = sum_left[s ^ lsb];
      sum_left_s.first = sum_left_s_minus.first + cost[i];
      sum_left_s.second = sum_left_s_minus.second + value[i];

    }

    const int power_right = 1 << N_half_right;
    vector<pair<INT2,INT1>> sum_right( power_right );

    for( int s = 1 ; s < power_right ; s++ ){

      const int lsb = s & -s;
      const int i = N_half_left + valuation[lsb];
      auto& sum_right_s = sum_right[s];
      auto& sum_right_s_minus = sum_right[s ^ lsb];
      sum_right_s.first = sum_right_s_minus.first + cost[i];
      sum_right_s.second = sum_right_s_minus.second + value[i];

    }

    sort( sum_right.begin() , sum_right.end() );

    for( int s = 1 ; s < power_right ; s++ ){

      sum_right[s].second = max( sum_right[s].second , sum_right[s-1].second );

    }

    for( int s = 0 ; s < power_left ; s++ ){

      auto& sum_left_s = sum_left[s];
      const pair<INT2,INT1> diff = { cost_sum_bound - sum_left_s.first , value_sum_bound - sum_left_s.second };

      if( diff.first >= 0 && diff.second >= 0 ){
	
	BS2( t , 0 , power_right - 1 , sum_right[t].first <= diff.first && sum_right[t].second <= diff.second ? 0 : 1 , 0 );

	if( answer.first <= sum_left_s.second + sum_right[t].second ){

	  BS1( u , 0 , t , sum_right[u].second , sum_right[t].second );
	  pair<INT1,INT2> temp = { sum_left_s.second + sum_right[u].second , sum_left_s.first + sum_right[u].first };
	  answer.first < temp.first || ( answer.first == temp.first && temp.second < answer.second ) ? answer = move( temp ) : answer;

	}

      }

    }
    
  }

  return answer;
  
}

template <typename INT1 , typename INT2> inline pair<INT1,INT2> Knapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound ) { const int N = value.size(); return Log( N ) + Log( min( ll( cost_sum_bound ) , ll( value_sum_bound ) ) ) < ll( N >> 1 ) ? cost_sum_bound < value_sum_bound ? AbstractKnapsack( AdditiveMonoid<INT1>() , value , value_sum_bound , INT2( -1 ) , cost , cost_sum_bound ) : KnapsackFewValues( N , value , value_sum_bound , cost , cost_sum_bound ) : KnapsackFewItems( N , value , value_sum_bound , cost , cost_sum_bound ); }

