// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Difference/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Permutation/a_Body.hpp"
#include "../../../../../Utility/BinarySearch/Set/a_Body.hpp"

template <typename INT>
INT CostfreeDifferenceKnapsack( const vector<INT>& value , const INT& value_bound , int size_diff_bound )
{

  const int N = value.size();
  assert( N >= 1 + max( 0 , 1 - size_diff_bound ) );
  INT value_sum_bound = 0;
  size_diff_bound = min( size_diff_bound , N );
  vector<ll> Comb( N + 1 , 1 );
  ll comb_sum = Comb[0];

  for( int i = 1 ; i <= size_diff_bound ; i++ ){

    if( ( comb_sum += Comb[i] = Comb[i-1] * ( N - 1 - i ) / i ) > ( value_sum_bound += value_bound ) ){

      return 0;

    }

  }

  for( int i = size_diff_bound + 1 ; i <= N ; i++ ){

    if( Comb[i - size_diff_bound - 1] < ( Comb[i] = Comb[i-1] * ( N - 1 - i ) / i ) ){
      
      if( ( comb_sum += Comb[i] - Comb[i - size_diff_bound - 1] ) > ( value_sum_bound += value_bound ) ){

        return 0;

      }

    } else {

      break;

    }

  }

  const int N_back = N / 2;
  const int N_front = N - N_back;
  vector<set<int>> S( N_back + 1 );
  vector<int> lower_bound( N_back , -1 ) , upper_bound( N_back , 1 ) , index = lower_bound , one( 1 , 1 );
  one.resize( N_back );
  INT answer = value_bound;
  bool valid = true;

  while( valid ){

    INT temp = 0;
    int size_diff = 0;

    for( int i = 0 ; i < N_back ; i++ ){

      temp += value[i + N_front] * index[i];
      size_diff += index[i];

    }

    valid = NextLoopEq( lower_bound , upper_bound , index );
    
    if( size_diff >= 0 ){

      if( size_diff == 0 && temp == 0 ){

        if( index == one ){

          continue;

        }

        return 0;

      }
      
      S[size_diff].insert( temp );

      if( size_diff <= size_diff_bound ){

        answer = min( answer , abs( temp ) );

      }
      
    }

  }
  
  lower_bound.resize( N_front , -1 ) , upper_bound.resize( N_front , 1 ) , index = lower_bound , one.resize( N_front );
  valid = true;

  while( valid ){

    INT temp = 0;
    int size_diff = 0;

    for( int i = 0 ; i < N_front ; i++ ){

      temp += value[i] * index[i];
      size_diff += index[i];

    }

    valid = NextLoopEq( lower_bound , upper_bound , index );

    if( size_diff == 0 && temp == 0 ){

      if( index == one ){

        continue;

      }

      return 0;

    }
    
    const int size_min = max( 0 , -size_diff - size_diff_bound );
    const int size_max = min( N_back , -size_diff + size_diff_bound );

    for( int size = size_min ; size <= size_max ; size++ ){

      const set<int>& s = S[size];
      auto itr = MaximumLeq( s , -temp );
      auto end = s.end();

      if( itr != end ){

        answer = min( answer , abs( *itr + temp ) );

      }

      itr = MinimumGeq( s , -temp );

      if( itr != end ){

        answer = min( answer , abs( *itr + temp ) );

      }
      
    }

    if( abs( size_diff ) <= size_diff_bound ){

      answer = min( answer , abs( temp ) );

    }

  }

  return answer;

}
