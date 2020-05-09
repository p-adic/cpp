// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Array/Nest/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"


template <typename Ret> inline NestedArrayTypeOfComputableFunction<Ret>::NestedArrayTypeOfComputableFunction() noexcept : TypeOfComputableFunction( GetName() , GetName() ) {}

template <typename Ret> inline const string& NestedArrayTypeOfComputableFunction<Ret>::GetName() noexcept { return GetSyntax().GetNodeString( 2 ); }

template <typename Ret> inline const SyntaxOfComputableFunction& NestedArrayTypeOfComputableFunction<Ret>::GetSyntax() noexcept
{

  static const SyntaxOfComputableFunction t
  {

    TypeString() ,
      NestedArrayString() ,
      GetTypeString<Ret>() + SupString() + LbraceString() + "< \\omega^{\\omega}" + RbraceString() ,
      GetTypeSyntax<Ret>().Get()

      };

  return t;
  
}

template <typename Ret> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( NestedArrayTypeOfComputableFunction<Ret> , NestedConcatenate , Frown );
template <typename Ret> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( NestedArrayTypeOfComputableFunction<Ret> , NestedConcatenate );
template <typename Ret, typename... Args> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( NestedArrayTypeOfComputableFunction<Ret> , NestedConcatenate , Symbol<Ret> );


template <typename Ret> inline const PrettyFunction<nat,NestedArrayTypeOfComputableFunction<Ret> >& NestedLengthSymbol()
{

  static const FunctionSymbol<nat,NestedArrayTypeOfComputableFunction<Ret> > f
    {

    "Lng" ,
     SeparatorOfComputableFunction
     (

      0 ,
      Plainise( "Lng" ) + LparenString() ,
      RparenString()

      ) ,
     GetTypeName<nat>() ,
     VariableSymbol<ArrayTypeOfComputableFunction<Ret> >( "a" ) ,

      };

  return f;

}

template <typename Ret> inline PrettyExpression<nat> LengthSymbolApplication( const ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> >& a ) { return NestedLengthSymbol<Ret>()( a ); }


template <typename Ret> inline const PrettyOperator<NestedArrayTypeOfComputableFunction<Ret>,NestedArrayTypeOfComputableFunction<Ret>,nat>& NestedEntryAccessSymbol()
{

  static const PrettyOperator<NestedArrayTypeOfComputableFunction<Ret>,NestedArrayTypeOfComputableFunction<Ret>,nat> f
  {

     LbrackString() + RbrackString() ,
     SeparatorOfComputableFunction
     (

      0 ,
      EmptyString() ,
      LbrackString() ,
      RbrackString()

      ) ,
     GetTypeName<NestedArrayTypeOfComputableFunction<Ret> >() ,
     VariableSymbol<NestedArrayTypeOfComputableFunction<Ret> >( "a" ) ,
     VariableSymbol<int>( "n" , GetTypeName<nat>() )
       
  };

  return f;

}

template <typename Ret> inline ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> > EntryAccessSymbolApplication( const ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> >& a , const PrettyExpression<nat>& n ) { return NestedEntryAccessSymbol<Ret>()( a , n ); }

template <typename Ret> inline const PrettyFunction<NestedArrayTypeOfComputableFunction<Ret>,NestedArrayTypeOfComputableFunction<Ret>,nat>& NestedInitialSegmentSymbol()
{

  static const FunctionSymbol<NestedArrayTypeOfComputableFunction<Ret>,NestedArrayTypeOfComputableFunction<Ret>,nat> f
  {

     "IniSeg" ,
     SeparatorOfComputableFunction
     (

      0 ,
      Plainise( "IniSeg" ) + LparenString() ,
      CommaString() ,
      RparenString()

      ) ,
     GetTypeName<NestedArrayTypeOfComputableFunction<Ret> >() ,
     VariableSymbol<NestedArrayTypeOfComputableFunction<Ret> >( "a" ) ,
     VariableSymbol<int>( "n" , GetTypeName<nat>() )

       };

  return f;

}

template <typename Ret> inline ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> > InitialSegmentSymbolApplication( const ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> >& a , PrettyExpression<nat> n ) { return NestedInitialSegmentSymbol<Ret>()( a , n ); }


template <typename Ret> inline const PrettyFunction<NestedArrayTypeOfComputableFunction<Ret>,NestedArrayTypeOfComputableFunction<Ret>,nat>& NestedFinalSegmentSymbol()
{

  static const FunctionSymbol<NestedArrayTypeOfComputableFunction<Ret>,NestedArrayTypeOfComputableFunction<Ret>,nat> f
  {

     "FinSeg" ,
     SeparatorOfComputableFunction
     (

      0 ,
      Plainise( "FinSeg" ) + LparenString() ,
      CommaString() ,
      RparenString()

      ) ,
     GetTypeName<NestedArrayTypeOfComputableFunction<Ret> >() ,
     VariableSymbol<NestedArrayTypeOfComputableFunction<Ret> >( "a" ) ,
     VariableSymbol<int>( "n" , GetTypeName<nat>() )

       };

  return f;

}

template <typename Ret> inline ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> > FinalSegmentSymbolApplication( const ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> >& a , PrettyExpression<nat> n ) { return NestedFinalSegmentSymbol<Ret>()( a , n ); }

template <typename Ret> inline const PrettyFunction<NestedArrayTypeOfComputableFunction<Ret>,ArrayTypeOfComputableFunction<Ret> >& ToNestedArraySymbol()
{

  static const FunctionSymbol<NestedArrayTypeOfComputableFunction<Ret>,NestedArrayTypeOfComputableFunction<Ret>,nat> f
  {

     "ToNestedArray" ,
     SeparatorOfComputableFunction
     (

      0 ,
      EmptyString() ,
      EmptyString()

      ) ,
     GetTypeName<NestedArrayTypeOfComputableFunction<Ret> >() ,
     VariableSymbol<ArrayTypeOfComputableFunction<Ret> >( "a" )

       };

  return f;

}

template <typename Ret> inline const PrettyFunction<NestedArrayTypeOfComputableFunction<Ret>,NestedArrayTypeOfComputableFunction<Ret> >& NestedWrapSymbol()
{

  static const FunctionSymbol<NestedArrayTypeOfComputableFunction<Ret>,NestedArrayTypeOfComputableFunction<Ret>,nat> f
  {

     "NestedWrap" ,
     SeparatorOfComputableFunction
     (

      0 ,
      LparenString() ,
      RparenString()

      ) ,
     GetTypeName<NestedArrayTypeOfComputableFunction<Ret> >() ,
     VariableSymbol<NestedArrayTypeOfComputableFunction<Ret> >( "a" )

       };

  return f;

}

template <typename Ret> inline ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> > NestifySymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a ) { return ToNestedArraySymbol<Ret>()( a ); }

template <typename Ret> inline ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> > NestifySymbolApplication( const ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> >& a ) { return NestedWrapSymbol<Ret>()( a ); }
