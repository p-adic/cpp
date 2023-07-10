// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Counting/IncreasingSubsequence/Subwalk/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , list<T> E_inv(const T&) , int V_max> ll CountSubwalk( const T ( &a )[V_max] , const int& V )
{

  COUNT_SUBWALK( count_temp += count_curr , count_i += count_temp , count_temp += itr->second );

}

template <typename T , list<T> E_inv(const T&) , int V_max> ll CountSubwalk( const T ( &a )[V_max] , const int& V , const ll& mod )
{

  COUNT_SUBWALK( ( count_temp += count_curr ) < mod ? count_temp : count_temp -= mod , ( count_i += count_temp ) < mod ? count_i : count_i -= mod , ( count_temp += itr->second ) < mod ? count_temp : count_temp -= mod );

}

template <typename T , list<T> E_inv(const T&) , int V_max>
int LongestSubwalk( const T ( &a )[V_max] , const int& V )
{

  assert( V <= V_max );
  map<T,int> length_max{};

  for( int i = 0 ; i < V ; i++ ){

    const T& a_i = a[i];
    const list<T> edge_inv_i = E_inv( a_i );
    int length_temp = 0;

    for( auto itr = edge_inv_i.begin() , end = edge_inv_i.end() ; itr != end ; itr++ ){

      const int& length_curr = length_max[*itr];
      length_temp < length_curr ? length_temp = length_curr : length_temp;

    }

    int& length_max_i = length_max[a_i];
    length_max_i <= length_temp ? length_max_i = length_temp + 1 : length_max_i;

  }
  
  int length_temp = 0;
  
  for( auto itr = length_max.begin() , end = length_max.end() ; itr != end ; itr++ ){

    length_temp < itr->second ? length_temp = itr->second : length_temp;

  }

  return length_temp;
  
}

