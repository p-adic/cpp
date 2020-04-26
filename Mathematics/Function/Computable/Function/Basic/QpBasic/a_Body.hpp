// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Basic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Syntax/Basic/a_Body.hpp"

// 矢印表記
inline const FunctionSymbol<int,int,int,int>& ArrowSymbol() noexcept
{

  static const FunctionSymbol<int,int,int,int> f
  {

    ArrowString() ,
      SeparatorOfComputableFunction
      (

       0 ,
       EmptyString() ,
       SpaceString() + ArrowString() + SupString() + LbraceString() ,
       RbraceString() + SpaceString() ,
       EmptyString()

       ) ,
      GetSyntax<int>() ,
      VariableSymbol<int>( "a" ) ,
      VariableSymbol<int>( "c" ) ,
      VariableSymbol<int>( "b" )

      };

  return f;

}

inline ExpressionOfComputableFunction<int> Arrow( const ExpressionOfComputableFunction<int>& a , const ExpressionOfComputableFunction<int>& b , const ExpressionOfComputableFunction<int>& c ) noexcept { return ArrowSymbol()( a , c , b ); }


// チェーン表記
inline const VariadicFunctionSymbol<int,int,int>& ChainSymbol() noexcept
{

  static const VariadicFunctionSymbol<int,int,int> f
  {

    ToString() ,
      SeparatorOfComputableFunction
      (

       0 ,
       EmptyString() ,
       SpaceString() + ToString() + SupString() ,
       LdotsString() ,
       SpaceString() + ToString() + SupString() ,
       EmptyString()

       ) ,
      GetSyntax<int>() ,
      VariableSymbol<int>( "a" )

      };
  
  return f;

}

template <typename... Args> inline ExpressionOfComputableFunction<int> Chain( const ExpressionOfComputableFunction<int>& a , const Args&... args ) noexcept { return ChainSymbol()( a , args... ); }


// N原始
inline const VariadicFunctionSymbol<string,int,string>& NPrimitiveSymbol_Body_1() noexcept
{

  static const VariadicFunctionSymbol<string,int,string> f
  {

    to_string( "N_1" ) ,
      SeparatorOfComputableFunction
      (

       0 ,
       to_string( Plainise( "N" ) ) ,
       LbrackString() ,
       LdotsString() ,
       CommaString() ,
       RbrackString()

       ) ,
      GetSyntax<int>() ,
      VariableSymbol<string>( "version" )

      };

  return f;

}

inline const FunctionSymbol<int,string,int>& NPrimitiveSymbol_Body_2() noexcept
{

  static const FunctionSymbol<int,string,int> f
  {

    to_string( "N_2" ) ,
      SeparatorOfComputableFunction
      (

       0 ,
       EmptyString() ,
       LparenString() ,
       RparenString()

       ) ,
      GetSyntax<int>() ,
      VariableSymbol<string>( "NvA" ) ,
      VariableSymbol<int>( "a" )

      };
  return f;

}

template <typename... Args> inline ExpressionOfComputableFunction<int> N( const ExpressionOfComputableFunction<string>& version , const ExpressionOfComputableFunction<int>& a , const Args&... args ) noexcept { return NPrimitiveSymbol_Body_2()( NPrimitiveSymbol_Body_1()( version , args... ) , a ); }
