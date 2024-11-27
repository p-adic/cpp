// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/DirectProduct/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Guide/Base/a_Body.hpp"

#include "../../Operator/a_Body.hpp"
#include "../../../../SetTheory/DirectProduct/a_Body.hpp"
#include "../../../../../Utility/WrappedType/Int/a_Body.hpp"

#include "../Guide/TypeName/a_Body.hpp"

template <typename... Args> inline DirectProductTypeOfComputableFunction<Args...>::DirectProductTypeOfComputableFunction() noexcept : TypeOfComputableFunction( GetName() , GetName() ) {}

template <typename... Args> inline const string& DirectProductTypeOfComputableFunction<Args...>::GetName() noexcept { return GetSyntax().GetNodeString( 2 ); }

template <typename... Args> inline const SyntaxOfComputableFunction& DirectProductTypeOfComputableFunction<Args...>::GetSyntax() noexcept
{

  static const SyntaxOfComputableFunction t
  {

    TypeString() ,
      DirectProductString() ,
      GetName_Body_ForDirectProduct( WrappedTypes<Args...>() ) ,
      GetTypeSyntax<Args>().Get()...

      };

  return t;

}


inline string GetName_Body_ForDirectProduct( const WrappedTypes<>& ) noexcept { return EscapeString() + LbraceString() + "\\ast" + EscapeString() + RbraceString(); }

template <typename Arg> inline string GetName_Body_ForDirectProduct( const WrappedTypes<Arg>& ) noexcept { return GetTypeString<Arg>(); }

template <typename Arg1, typename Arg2, typename... Args> inline string GetName_Body_ForDirectProduct( const WrappedTypes<Arg1,Arg2,Args...>& ) noexcept { return GetTypeString<Arg1>() + SpaceString() + TimesString() + SpaceString() + GetName_Body_ForDirectProduct( WrappedTypes<Arg2,Args...>() ); }



template <uint i, typename... Args> const PrettyOperator<typename DirectProductTypeOfComputableFunction<Args...>::template type<i>,DirectProductTypeOfComputableFunction<Args...> >& ProjectionSymbol_Body( const WrappedUInt<i>& , const WrappedTypes<Args...>& )
{

  static const PrettyOperator<typename DirectProductTypeOfComputableFunction<Args...>::template type<i>,DirectProductTypeOfComputableFunction<Args...> > f
  {

    ProjectionString() + to_string( i ) ,
      
      SeparatorOfComputableFunction
      (

       0 ,
       ProjectionString() + SubString() + LbraceString() + to_string( i ) + RbraceString() + LparenString() ,
       RparenString()

       ) ,

      GetTypeName<typename DirectProductTypeOfComputableFunction<Args...>::template type<i> >() ,
      VariableSymbol<typename BaseTypeOf<Args>::type>( "x" + SubString() + LbraceString() + GetTypeName<Args>() + RbraceString() , GetTypeName<Args>() )...

      };

  return f;

}

template <uint i, typename... Args> inline const PrettyOperator<decltype( ProjectionSymbol_Body( WrappedUInt<i>() , WrappedTypes<Args...>() ) ),DirectProductTypeOfComputableFunction<Args...> >& ProjectionSymbol() { return ProjectionSymbol_Body( WrappedUInt<i>() , WrappedTypes<Args...>() ); }

template <uint i, typename... Args> inline ExpressionOfComputableFunction<typename DirectProductTypeOfComputableFunction<Args...>::template type<i> > ProjectionSymbolApplication( const ExpressionOfComputableFunction<Args>&... args ) { return ProjectionSymbol<i,Args...>()( args...); }

template <typename... Args> inline const FunctionSymbol<DirectProductTypeOfComputableFunction<Args...>,Args...>& TupleSymbol()
{

  static const FunctionSymbol<DirectProductTypeOfComputableFunction<Args...>,Args...> f
  {

    EmptyString() ,

      GetTypeName<DirectProductTypeOfComputableFunction<Args...> >() ,
      VariableSymbol<Args>( AstString() + SubString() + LbraceString() + GetTypeString<Args>() + RbraceString() , GetTypeName<Args>() )...

      };

  return f;


}

template <typename... Args> inline ExpressionOfComputableFunction<DirectProductTypeOfComputableFunction<Args...> > TupleSymbolApplication( const ExpressionOfComputableFunction<Args>&... args ) { return TupleSymbol<Args...>()( args... ); }
