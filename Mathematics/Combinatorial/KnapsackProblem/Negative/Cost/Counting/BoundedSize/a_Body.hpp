// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Cost/Counting/BoundedSize/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../../../../../../SetTheory/Line/Bounded/Compressed/Multisubset/Debug/a_Body.hpp"
#else
  #include "../../../../../../SetTheory/Line/Bounded/Compressed/Multisubset/a_Body.hpp"
#endif

template <typename INT , typename U , typename COMM_MONOID>
vector<vector<ll>> AbstractCountingNegativeCostBoundedValueSumBoundedSizeKnapsack( COMM_MONOID M , const vector<INT>& value , const vector<pair<INT,INT>>& value_sum_bound , const vector<U>& cost , const U& cost_sum_bound , const pair<int,int>& size_bound )
{

  const int N = value.size();
  assert( int( cost.size() ) == N );
  auto& [size_min,size_max] = size_bound;
  assert( 0 <= size_min && size_min <= size_max && size_max <= N );
  const int N_half = N >> 1;
  const int size_max_half[2] = { min( size_max , N_half ) , min( size_max , N - N_half ) };
  const U& one = M.One();
  vector<map<pair<U,INT>,int>> count[2] = {};
  
  for( int b = 0 ; b < 2 ; b++ ){
  	
    const int i_min = b == 0 ? 0 : N_half;
    const int i_ulim = b == 0 ? N_half : N;
    count[b].resize( size_max_half[b] + 1 );
    count[b][0][{one,0}] = 1;
      
    for( int i = i_min ; i < i_ulim ; i++ ){
    	
      for( int size = size_max_half[b] - 1 ; size >= 0 ; size-- ){
      
        for( auto& [key,num] : count[b][size] ){
      	
          count[b][size+1][{ M.Product( key.first , cost[i] ) , key.second + value[i] }] += num;
        
        }
      

      }
    
    }

  }

  const int Q = value_sum_bound.size();
  vector<CompressedSortedMultiSet<ll>> S{};

  for( int size_1 = 0 ; size_1 <= size_max_half[1] ; size_1++ ){

    vector<INT> query{};

    for( auto& [key,num] : count[1][size_1] ){
    	
      query.push_back( key.second );
  
    }

    S.push_back( query );

  }
      
  vector answer( size_max + 1 , vector<ll>( Q ) );

  for( int size_0 = 0 ; size_0 <= size_max_half[0] ; size_0++ ){

    const int size_1_max = min( size_max_half[1] , size_max - size_0 );

    for( int size_1 = max( 0 , size_min - size_0 ) ; size_1 <= size_1_max ; size_1++ ){

      const int size = size_0 + size_1;
      auto itr_0 = count[0][size_0].rbegin() , end_0 = count[0][size_0].rend();
      auto itr_1 = count[1][size_1].begin() , end_1 = count[1][size_1].end();
      itr_0 = count[0][size_0].rbegin();
      itr_1 = count[1][size_1].begin();
      S[size_1].clear();
      auto end = S[size_1].end();

      while( itr_0 != end_0 ){

        while( itr_1 != end_1 && M.Product( itr_0->first.first , itr_1->first.first ) <= cost_sum_bound ){
    	
          S[size_1].insert( itr_1->first.second , itr_1->second );
          ++itr_1;
      
        }
    
        for( int q = 0 ; q < Q ; q++ ){
    	
          auto& [l,r] = value_sum_bound[q];
          auto itr_l = S[size_1].MinimumGeq( l - itr_0->first.second ) , itr_r = S[size_1].MaximumLeq( r - itr_0->first.second );

          if( itr_l != end && itr_r != end ){

            answer[size][q] += ll( itr_0->second ) * S[size_1].IntervalCount( *itr_l , *itr_r );

          }
      
        }
    
        ++itr_0;
  
      }

    }

  }
  
  return answer;

}

template <typename INT1 , typename INT2> inline vector<vector<ll>> CountingNegativeCostBoundedValueSumBoundedSizeKnapsack( const vector<INT1>& value , const vector<pair<INT1,INT1>>& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound , const pair<int,int>& size_bound ) { return AbstractCountingNegativeCostBoundedValueSumBoundedSizeKnapsack( AdditiveMonoid<INT2>() , value , value_sum_bound , cost , cost_sum_bound , size_bound ); }

#include "../../../../ValueSumBound/a_Body.hpp"
