// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Loop/Recursion/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , typename Arg , typename BEFORE , typename AFTER>
Arg ExecuteLoop( const int& size , const vector<INT>& lower_bound , const vector<INT>& upper_limit , const int& d , Arg&& arg , const BEFORE& before , const AFTER& after )
{

  static_assert( is_invocable_r_v<Arg,BEFORE,const int&,const int&,const Arg&> && is_invocable_v<AFTER,const int&,const int&,const Arg&> );

  if( d + 1 < size ){

    for( INT i = lower_bound[d] ; i < upper_limit[d] ; i++ ){

      after( d , i , ExecuteLoop( size , lower_bound , upper_limit , d + 1 , before( d , i , arg ) , before , after ) );

    }

  } else {
  
    for( INT i = lower_bound[d] ; i < upper_limit[d] ; i++ ){

      after( d , i , before( d , i , arg ) );

    }

  }

  return move( arg );

}

template <typename INT , typename Arg , typename BEFORE , typename AFTER> inline Arg ExecuteLoop( const vector<INT>& lower_bound , const vector<INT>& upper_limit , Arg&& arg , const BEFORE& before , const AFTER& after ) { return ExecuteLoop( lower_bound.size() , lower_bound , upper_limit , 0 , move( arg ) , before , after ); }

template <typename INT , typename Arg , typename BEFORE , typename AFTER>
Arg ExecuteLoopEq( const int& size , const vector<INT>& lower_bound , const vector<INT>& upper_bound , const int& d , Arg&& arg , const BEFORE& before , const AFTER& after )
{

  static_assert( is_invocable_r_v<Arg,BEFORE,const int&,const int&,const Arg&> && is_invocable_v<AFTER,const int&,const int&,const Arg&> );

  if( d + 1 < size ){

    for( INT i = lower_bound[d] ; i <= upper_bound[d] ; i++ ){

      after( d , i , ExecuteLoopEq( size , lower_bound , upper_bound , d + 1 , before( d , i , arg ) , before , after ) );

    }

  } else {
  
    for( INT i = lower_bound[d] ; i <= upper_bound[d] ; i++ ){

      after( d , i , before( d , i , arg ) );

    }

  }

  return move( arg );

}

template <typename INT , typename Arg , typename BEFORE , typename AFTER> inline Arg ExecuteLoopEq( const vector<INT>& lower_bound , const vector<INT>& upper_bound , Arg&& arg , const BEFORE& before , const AFTER& after ) { return ExecuteLoopEq( lower_bound.size() , lower_bound , upper_bound , 0 , move( arg ) , before , after ); }
