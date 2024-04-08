// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/ValueSumBound/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U , typename COMM_MONOID>
U AbstractValueSumBound( COMM_MONOID M , const vector<U>& value )
{

  const U& one = M.One();
  U answer = one;

  for( auto& v : value ){

    one < v ? answer = M.Product( move( answer ) , v ) : answer;

  }

  return answer;

}

template <typename INT> inline INT ValueSumBound( const vector<INT>& value ) { return AbstractValueSumBound( AdditiveMonoid<INT>() , value ); }
