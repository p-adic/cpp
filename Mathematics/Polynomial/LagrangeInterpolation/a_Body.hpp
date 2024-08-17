// c:/Users/user/Documents/Programming/Mathematics/Polynomial/LagrangeInterpolation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "../MultipointEvaluation/a_Body.hpp"

template <typename T>
Polynomial<T> LagrangeInterpolation( const vector<T>& arg , const vector<T>& val )
{

  const int size = arg.size();
  assert( size > 0 && int( val.size() ) == size );

  // SeDifferenceProductそのものだが、top.front()を流用するために実装をコピーする。
  list<vector<Polynomial<T> > > pt{};
  SetPointTree( arg , pt );
  const vector<Polynomial<T> >& top = pt.front();
  auto& f = top.front();
  Polynomial<T> g{ Differential( 1 , f ) };
  vector<T> coef{};
  SetPointTreeEvaluation( g , pt , coef );
  auto itr = pt.back().begin();

  Polynomial<T> answer{};
  
  for( int i = 0 ; i < size ; i++ ){

    answer += f / *( itr++ ) * ( val[i] / coef[i] );

  }

  return answer;

}
