// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Difference/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Permutation/a_Body.hpp"
#include "../../../../../Utility/BinarySearch/Set/a_Body.hpp"

template <typename INT>
INT CostfreeDifferenceKnapsack( const vector<INT>& value , const INT& value_bound , int size_diff_bound )
{

  const int N = value.size();
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
  vector<set<int>> S_non_empty( N_back + 1 );
  vector<set<int>> S_empty( N_back + 1 );
  vector<int> lower_bound( N_back , -1 ) , upper_bound( N_back , 1 ) , index = lower_bound;
  INT answer = value_bound;

  while( true ){

    INT temp = 0;
    int size_diff = 0;
    bool non_empty = false;

    for( int i = 0 ; i < N_back ; i++ ){

      temp += value[i + N_front] * index[i];
      size_diff += index[i];
      non_empty |= index[i] == -1;

    }

    if( size_diff >= 0 ){

      ( non_empty ? S_non_empty : S_empty )[size_diff].insert( temp );

      if( size_diff == 0 && non_empty ){

        answer = min( answer , abs( temp ) );

      }
      
    }

    if( !NextLoopEq( lower_bound , upper_bound , index ) ){

      break;

    }
    
  }
  
  lower_bound.resize( N_front , -1 ) , upper_bound.resize( N_front , 1 ) , index = lower_bound;

  while( true ){

    INT temp = 0;
    int size_diff = 0;
    bool non_empty = false;

    for( int i = 0 ; i < N_front ; i++ ){

      temp += value[i] * index[i];
      size_diff += index[i];
      non_empty |= index[i] == -1;

    }

    const int size_min = max( 0 , -size_diff - size_diff_bound );
    const int size_max = min( N_back , -size_diff + size_diff_bound );

    for( int size = size_min ; size <= size_max ; size++ ){

      const set<int>& s_non_empty = S_non_empty[size];
      auto itr = MaximumLeq( s_non_empty , -temp );
      auto end = s_non_empty.end();

      if( itr != end ){

        answer = min( answer , abs( *itr + temp ) );

      }

      itr = MinimumGeq( s_non_empty , -temp );

      if( itr != end ){

        answer = min( answer , abs( *itr + temp ) );

      }

      if( non_empty ){

        const set<int>& s_empty = S_empty[size];
        itr = MaximumLeq( s_empty , -temp );
        end = s_empty.end();

        if( itr != end ){

          answer = min( answer , abs( *itr + temp ) );

        }

        itr = MinimumGeq( s_empty , -temp );

        if( itr != end ){

          answer = min( answer , abs( *itr + temp ) );

        }

      }
      
    }

    if( size_diff == 0 && non_empty ){

      answer = min( answer , abs( temp ) );

    }

    if( !NextLoopEq( lower_bound , upper_bound , index ) ){

      break;

    }
    
  }

  return answer;

  // if( size_diff_bound == 0 ){

  //   return CostfreeDifferenceKnapsackSameSize( N , value , value_bound , value_sum_bound );

  // }

  // const int size_max = size_min + size_diff_bound;
  // vector<bool> S( N );

  // for( int i = N - size_min + 1 ; i < N ; i++ ){

  //   S[i] = true;

  // }

  // vector<bool> found( value_sum_bound + 1 );

  // for( int size = size_min ; size <= size_max ; size++ ){

  //   S[N - size] = 1;

  //   while( true ){

  //     INT temp = 0;

  //     for( int i = 0 ; i < N ; i++ ){

  //       S[i] ? temp += value[i] : temp;

  //     }

  //     if( !next_permutation( S.begin() , S.end() ) ){

  //       break;

  //     }

  //   }

  // }

}
