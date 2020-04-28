// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Basic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Variadic/a_Body.hpp"

// 矢印表記
inline const PrettyFunction<nat,nat,nat,nat>& ArrowSymbol() noexcept
{

  static const PrettyFunction<nat,nat,nat,nat> f
  {

    "\\uparrow" ,
      SeparatorOfComputableFunction
      (

       0 ,
       EmptyString() ,
       SpaceString() + "\\uparrow" + SupString() + LbraceString() ,
       RbraceString() + SpaceString() ,
       EmptyString()

       ) ,
      GetTypeSyntax<nat>() ,
      PrettyVariable<nat>( "a" ) ,
      PrettyVariable<nat>( "c" ) ,
      PrettyVariable<nat>( "b" )

      };

  return f;

}

inline PrettyExpression<nat> Arrow( const PrettyExpression<nat>& a , const PrettyExpression<nat>& b , const PrettyExpression<nat>& c ) noexcept { return ArrowSymbol()( a , c , b ); }


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
      GetTypeSyntax<nat>() ,
      PrettyVariable<nat>( "a" )

      };
  
  return f;

}

template <typename... Args> inline PrettyExpression<nat> Chain( const PrettyExpression<nat>& a , const Args&... args ) noexcept { return ChainSymbol()( a , args... ); }


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
      GetTypeSyntax<nat>() ,
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
      GetTypeSyntax<nat>() ,
      VariableSymbol<string>( "NvA" ) ,
      PrettyVariable<nat>( "a" )

      };
  return f;

}

template <typename... Args> inline PrettyExpression<nat> N( const ExpressionOfComputableFunction<string>& version , const PrettyExpression<nat>& a , const Args&... args ) noexcept { return NPrimitiveSymbol_Body_2()( NPrimitiveSymbol_Body_1()( version , args... ) , a ); }
