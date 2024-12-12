// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Difference/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Loop/a_Body.hpp"
#include "../../../../../Utility/BinarySearch/Set/a_Body.hpp"

// 多重ループの非再帰版
template <typename INT>
INT CostfreeDifferenceKnapsack( const vector<INT>& value , int size_diff_bound )
{

  const int N = value.size();
  assert( N >= 1 + max( 0 , 1 - size_diff_bound ) );
  INT value_bound = 0;

  for( int i = 0 ; i < N ; i++ ){

    assert( 0 <= value[i] );
    value_bound = max( value_bound , value[i] );

  }
  
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

// #include "../../../Loop/Recursion/a_Body.hpp"

// 多重ループの再帰版（遲い）
// template <typename INT>
// INT CostfreeDifferenceKnapsack( const vector<INT>& value , int size_diff_bound )
// {

//   const int N = value.size();
//   assert( N >= 1 + max( 0 , 1 - size_diff_bound ) );
//   INT value_bound = 0;

//   for( int i = 0 ; i < N ; i++ ){

//     assert( 0 <= value[i] );
//     value_bound = max( value_bound , value[i] );

//   }

//   INT value_sum_bound = 0;
//   size_diff_bound = min( size_diff_bound , N );
//   vector<ll> Comb( N + 1 , 1 );
//   ll comb_sum = Comb[0];

//   for( int i = 1 ; i <= size_diff_bound ; i++ ){

//     if( ( comb_sum += Comb[i] = Comb[i-1] * ( N - 1 - i ) / i ) > ( value_sum_bound += value_bound ) ){

//       return 0;

//     }

//   }

//   for( int i = size_diff_bound + 1 ; i <= N ; i++ ){

//     if( Comb[i - size_diff_bound - 1] < ( Comb[i] = Comb[i-1] * ( N - 1 - i ) / i ) ){
      
//       if( ( comb_sum += Comb[i] - Comb[i - size_diff_bound - 1] ) > ( value_sum_bound += value_bound ) ){

//         return 0;

//       }

//     } else {

//       break;

//     }

//   }

//   const int N_back = N / 2;
//   const int N_front = N - N_back;
//   vector<set<int>> S( N_back + 1 );
//   vector<int> lower_bound( N_back , -1 ) , upper_bound( N_back , 1 );
//   INT answer = value_bound;
//   int count = 0;
//   auto before_back = [&]( const int& i , const int& sign , const T2<int>& v ){ return T2<int>{ v.first + value[i+N_front] * sign , v.second + sign }; };
//   auto after_back = [&]( const int& i , const int& sign , const T2<int>& v ){

//     if( i < N_back - 1 ){

//       return;

//     }

//     auto& [temp,size_diff] = v;
    
//     if( size_diff < 0 ){

//       return;

//     }

//     if( size_diff == 0 && temp == 0 ){

//       if( count++ != 0 ){

//         answer = 0;

//       }

//       return;

//     }
      
//     S[size_diff].insert( temp );

//     if( size_diff <= size_diff_bound ){

//       answer = min( answer , abs( temp ) );

//     }

//     return;
    
//   };

//   ExecuteLoopEq( lower_bound , upper_bound , T2<int>{0,0} , before_back , after_back );
//   lower_bound.resize( N_front , -1 ) , upper_bound.resize( N_front , 1 );
//   count = 0;
//   auto before_front = [&]( const int& i , const int& sign , const T2<int>& v ){ return T2<int>{ v.first + value[i] * sign , v.second + sign }; };
//   auto after_front = [&]( const int& i , const int& sign , const T2<int>& v ){

//     if( i < N_front - 1 ){

//       return;

//     }

//     auto& [temp,size_diff] = v;
    
//     if( size_diff == 0 && temp == 0 ){

//       if( count++ != 0 ){

//         answer = 0;

//       }

//       return;

//     }

//     const int size_min = max( 0 , -size_diff - size_diff_bound );
//     const int size_max = min( N_back , -size_diff + size_diff_bound );

//     for( int size = size_min ; size <= size_max ; size++ ){

//       const set<int>& s = S[size];
//       auto itr = MaximumLeq( s , -temp );
//       auto end = s.end();

//       if( itr != end ){

//         answer = min( answer , abs( *itr + temp ) );

//       }

//       itr = MinimumGeq( s , -temp );

//       if( itr != end ){

//         answer = min( answer , abs( *itr + temp ) );

//       }
      
//     }

//     if( abs( size_diff ) <= size_diff_bound ){

//       answer = min( answer , abs( temp ) );

//     }

//     return;
                                                                             
//   };
     
//   ExecuteLoopEq( lower_bound , upper_bound , T2<int>{0,0} , before_front , after_front );
//   return answer;

// }
