// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Loop/a_Body.hpp

#pragma once
#include "a.hpp"

bool NextLoop( const int& size , const vector<int>& lower_bound , const vector<int>& upper_limit , vector<int>& index )
{

  int depth = 0;
  
  while( depth < size ){

    if( ++index[depth] < upper_limit[depth] ){

      break;

    }

    index[depth] = lower_bound[depth];
    depth++;

  }

  return depth < size;

}
