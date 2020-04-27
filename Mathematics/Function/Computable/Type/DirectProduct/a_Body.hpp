// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/DirectProduct/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Function/a_Body.hpp"
#include "../../Relation/a_Body.hpp"
#include "../../../../SetTheory/DirectProduct/a_Body.hpp"
#include "../../../../../Utility/WrappedType/Int/a_Body.hpp"

#include "../TypeName/a_Body.hpp"

template <typename... Args> inline DirectProductTypeOfComputableFunction<Args...>::DirectProductTypeOfComputableFunction() noexcept : TypeOfComputableFunction( GetName() , GetName() ) {}

template <typename... Args> inline const string& DirectProductTypeOfComputableFunction<Args...>::GetName() noexcept { return GetSyntax().GetNodeString( 2 ); }

template <typename... Args> inline const SyntaxOfComputableFunction& DirectProductTypeOfComputableFunction<Args...>::GetSyntax() noexcept
{

  static const SyntaxOfComputableFunction t
  {

    TypeString() ,
      DirectProductString() ,
      GetName_Body_ForDirectProduct( WrappedTypes<Args...>() ) ,
      GetTypeSyntax<Args>()...

      };

  return t;

}

template <typename... Args> template <uint i> auto DirectProductTypeOfComputableFunction<Args...>::ProjectionSymbol_Body( const WrappedUInt<i>& ) noexcept -> typename enable_if<! is_same<typename BaseTypeOf<type<i> >::type,bool>::value,const PrettyFunction<type<i>,DirectProductTypeOfComputableFunction<Args...> >&>::type
{

  static const PrettyFunction<type<i>,DirectProductTypeOfComputableFunction<Args...> > f
  {

    ProjectionString() + to_string( i ) ,
      
      SeparatorOfComputableFunction
      (

       0 ,
       ProjectionString() + SubString() + LbraceString() + to_string( i ) + RbraceString() + LparenString() ,
       RparenString()

       ) ,

      GetTypeName<type<i> >() ,
      VariableSymbol<typename BaseTypeOf<Args>::type>( "x" + SubString() + LbraceString() + GetTypeName<Args>() + RbraceString() , GetTypeName<Args>() )...

      };

  return f;

}

template <typename... Args> template <uint i> auto DirectProductTypeOfComputableFunction<Args...>::ProjectionSymbol_Body( const WrappedUInt<i>& ) noexcept -> typename enable_if<is_same<typename BaseTypeOf<type<i> >::type,bool>::value,const PrettyRelation<DirectProductTypeOfComputableFunction<Args...> > &>::type
{

  static const PrettyRelation<DirectProductTypeOfComputableFunction<Args...> > r
  {

    ProjectionString() + to_string( i ) ,
      
      SeparatorOfComputableFunction
      (

       0 ,
       ProjectionString() + SubString() + LbraceString() + to_string( i ) + RbraceString() + LparenString() ,
       RparenString()

       ) ,

      GetTypeName<bool>() ,
      VariableSymbol<typename BaseTypeOf<Args>::type>( "x" + SubString() + LbraceString() + GetTypeName<Args>() + RbraceString() , GetTypeName<Args>() )...

      };

  return r;

}


inline string GetName_Body_ForDirectProduct( const WrappedTypes<>& ) noexcept { return EscapeString() + LbraceString() + "\\ast" + EscapeString() + RbraceString(); }

template <typename Arg> inline string GetName_ForDirectProduct( const WrappedTypes<Arg>& ) noexcept { return GetTypeName<Arg>(); }

template <typename Arg1, typename Arg2, typename... Args> inline string GetName_ForDirectProduct( const WrappedTypes<Arg1,Arg2,Args...>& ) noexcept { return GetTypeName<Arg1> + SpaceString() + TimesString() + SpaceString() + GetName_ForDirectProduct( WrappedTypes<Arg2,Args...>() ); }


template <uint i, typename... Args> inline auto ProjectionSymbol() noexcept -> decltype( DirectProductTypeOfComputableFunction<Args...>::ProjectionSymbol_Body( WrappedUInt<i>() ) ) { return DirectProductTypeOfComputableFunction<Args...>::ProjectionSymbol_Body( WrappedUInt<i>() ); }
