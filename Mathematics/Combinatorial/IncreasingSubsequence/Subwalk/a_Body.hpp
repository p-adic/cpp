// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/IncreasingSubsequence/Subwalk/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Utility/Set/a_Body.hpp"

template <typename T , typename GRAPH , typename INT> INT CountSubwalk( GRAPH& G , const vector<T>& a , const INT& dummy )
{

  const int& size = a.size();
  Map<T,INT> count{};

  for( int i = 0 ; i < size ; i++ ){

    const T& a_i = a[i];
    auto&& edge_i = G.Edge( a_i );
    INT count_temp = 1;

    for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

      const INT& count_curr = count[*itr];
      count_temp += count_curr;

    }

    INT& count_i = count[a_i];
    count_i += count_temp;

  }

  INT count_temp = 0;

  for( auto itr = count.begin() , end = count.end() ; itr != end ; itr++ ){

    count_temp += itr->second;

  }

  return count_temp

}

template <typename T , typename GRAPH>
int LongestSubwalk( GRAPH& G , const vector<T>& a x)
{

  const int& size = a.size();
  Map<T,int> length_max{};

  for( int i = 0 ; i < size ; i++ ){

    const T& a_i = a[i];
    auto&& edge_i = G.Edge( a_i );
    int length_temp = 0;

    for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

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

