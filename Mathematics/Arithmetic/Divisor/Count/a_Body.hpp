// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Count/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Prime/Factorisation/a_Body.hpp"

template <typename INT> INT CountDivisorBody( vector<int>& E ) noexcept
{
  
  const int length = E.size();
  INT answer = 1;

  for( int i = 0 ; i < length ; i++ ){

    answer *= ++E[i];

  }

  return answer;

}

template <typename INT>
INT CountDivisor( INT n ) noexcept
{

  auto [P,E] = PrimeFactorisation( move( n ) );
  return CountDivisorBody<INT>( E );

}

template <typename PE , typename INT>
INT CountDivisor( const PE& pe , INT n ) noexcept
{

  auto [P,E] = PrimeFactorisation( pe , move( n ) );
  return CountDivisorBody<INT>( E );

}

// 不使用だがどうせincludeする。
#include "../../Prime/Enumeration/a_Body.hpp"
#include "../../Prime/Enumeration/Heap/a_Body.hpp"
#include "../Least/a_Body.hpp"
#include "../Least/Heap/a_Body.hpp"
