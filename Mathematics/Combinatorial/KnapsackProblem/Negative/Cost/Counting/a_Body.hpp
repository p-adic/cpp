// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Cost/Counting/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../../../../../SetTheory/Line/Bounded/Compressed/Multisubset/Debug/a_Body.hpp"
#else
  #include "../../../../../SetTheory/Line/Bounded/Compressed/Multisubset/a_Body.hpp"
#endif

template <typename INT , typename U , typename COMM_MONOID>
vector<ll> AbstractCountingNegativeCostBoundedValueSumKnapsack( COMM_MONOID M , const vector<INT>& value , const vector<pair<INT,INT>>& value_sum_bound , const vector<U>& cost , const U& cost_sum_bound )
{

  const int N = value.size();
  assert( int( cost.size() ) == N );
  const int N_half = N >> 1;
  const U& one = M.One();
  map<pair<U,INT>,int> count[2] = {};
  
  for( int b = 0 ; b < 2 ; b++ ){
  	
    const int i_min = b == 0 ? 0 : N_half;
    const int i_ulim = b == 0 ? N_half : N;
    count[b][{one,0}] = 1;
    
    for( int i = i_min ; i < i_ulim ; i++ ){
    	
      vector<pair<pair<U,INT>,int>> count_next{};
      
      for( auto& [key,num] : count[b] ){
      	
        count_next.push_back( { { M.Product( key.first , cost[i] ) , key.second + value[i] } , num } );
        
      }
      
      for( auto& [key,num] : count_next ){
      	
        count[b][key] += num;
        
      }
    
    }

  }

  const int Q = value_sum_bound.size(); 
  vector<ll> answer( Q ); 
  auto itr_0 = count[0].rbegin() , end_0 = count[0].rend();
  auto itr_1 = count[1].begin() , end_1 = count[1].end();
  vector<INT> query{};
  
  while( itr_0 != end_0 ){

    while( itr_1 != end_1 && M.Product( itr_0->first.first , itr_1->first.first ) <= cost_sum_bound ){
    	
      query.push_back( itr_1->first.second );
      ++itr_1;
      
    }
    
    ++itr_0;
  
  }

  CompressedSortedMultiSet<ll> S{ query };
  query.clear();
  itr_0 = count[0].rbegin();
  itr_1 = count[1].begin();
  auto end = S.end();
  
  while( itr_0 != end_0 ){

    while( itr_1 != end_1 && M.Product( itr_0->first.first , itr_1->first.first ) <= cost_sum_bound ){
    	
      S.insert( itr_1->first.second , itr_1->second );
      ++itr_1;
      
    }
    
    for( int q = 0 ; q < Q ; q++ ){
    	
      auto& [l,r] = value_sum_bound[q];
      auto itr_l = S.MinimumGeq( l - itr_0->first.second ) , itr_r = S.MaximumLeq( r - itr_0->first.second );

      if( itr_l != end && itr_r != end ){
        
        answer[q] += ll( itr_0->second ) * S.IntervalCount( *itr_l , *itr_r );

      }
      
    }
    
    ++itr_0;
  
  }
  
  return answer;

}

template <typename INT1 , typename INT2> inline vector<ll> CountingNegativeCostBoundedValueSumKnapsack( const vector<INT1>& value , const vector<pair<INT1,INT1>>& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound ) { return AbstractCountingNegativeCostBoundedValueSumKnapsack( AdditiveMonoid<INT2>() , value , value_sum_bound , cost , cost_sum_bound ); }

#include "../../../ValueSumBound/a_Body.hpp"
