// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Loop/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> bool NextLoop( const int& size , const vector<INT>& lower_bound , const vector<INT>& upper_limit , vector<INT>& index )
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

template <typename INT> bool NextLoop( const vector<INT>& lower_bound , const vector<INT>& upper_limit , vector<INT>& index ) { return NextLoop( index.size() , lower_bound , upper_limit , index ); }

template <typename INT> bool NextLoopEq( const int& size , const vector<INT>& lower_bound , const vector<INT>& upper_bound , vector<INT>& index )
{

  int depth = 0;
  
  while( depth < size ){

    if( ++index[depth] <= upper_bound[depth] ){

      break;

    }

    index[depth] = lower_bound[depth];
    depth++;

  }

  return depth < size;

}

template <typename INT> bool NextLoopEq( const vector<INT>& lower_bound , const vector<INT>& upper_bound , vector<INT>& index ) { return NextLoopEq( index.size() , lower_bound , upper_bound , index ); }
