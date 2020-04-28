// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Array/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Basic/nat/a_Body.hpp"
#include "../../Function/Variadic/a_Body.hpp"

template <typename Ret> inline ArrayTypeOfComputableFunction<Ret>::ArrayTypeOfComputableFunction() noexcept : TypeOfComputableFunction( GetName() , GetName() ) {}

template <typename Ret> inline const string& ArrayTypeOfComputableFunction<Ret>::GetName() noexcept { return GetSyntax().GetNodeString( 2 ); }

template <typename Ret> inline const SyntaxOfComputableFunction& ArrayTypeOfComputableFunction<Ret>::GetSyntax() noexcept
{

  static const SyntaxOfComputableFunction t
  {

    TypeString() ,
      ArrayString() ,
      GetTypeString<Ret>() + SupString() + LbraceString() + "< \\omega" + RbraceString() ,
      GetTypeSyntax<Ret>()

      };

  return t;
  
}


template <typename Ret> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( ArrayTypeOfComputableFunction<Ret> , Plus , Frown );

template <typename Ret> inline const FunctionSymbol<nat,ArrayTypeOfComputableFunction<Ret> >& LengthSymbol()
{

  static const FunctionSymbol<nat,ArrayTypeOfComputableFunction<Ret>> f
    {

    "Lng" ,
     SeparatorOfComputableFunction
     (

      0 ,
      Plainise( "Lng" ) + LparenString() ,
      RparenString()

      ) ,
     GetTypeName<nat>() ,
     VariableSymbol<ArrayTypeOfComputableFunction<Ret>>( "a" ) ,

      };

  return f;

}

template <typename Ret> inline ExpressionOfComputableFunction<nat> LengthSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a ) { return LengthSymbol<Ret>( a ); }

template <typename Ret> inline const PrettyOperator<Ret,ArrayTypeOfComputableFunction<Ret>,nat>& EntryAccessSymbol()
{

  static const PrettyOperator<ArrayTypeOfComputableFunction<Ret>,Ret> f
  {

     LbrackString() + RbrackString() ,
     SeparatorOfComputableFunction
     (

      0 ,
      EmptyString() ,
      LbrackString() ,
      RbrackString()

      ) ,
     GetTypeName<Ret>() ,
     VariableSymbol<ArrayTypeOfComputableFunction<Ret> >( "a" ) ,
     VariableSymbol<int>( "n" , GetTypeName<nat>() )
       
  };

  return f;

}

template <typename Ret> inline ExpressionOfComputableFunction<Ret> EntryAccessSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a , const ExpressionOfComputableFunction<nat>& n ) { return EntryAccessSymbol<Ret>()( a , n ); }

template <typename Ret> inline const FunctionSymbol<ArrayTypeOfComputableFunction<Ret>,ArrayTypeOfComputableFunction<Ret>,nat>& InitialSegmentSymbol()
{

  static const FunctionSymbol<ArrayTypeOfComputableFunction<Ret>,ArrayTypeOfComputableFunction<Ret>,nat> f
  {

     "IniSeg" ,
     SeparatorOfComputableFunction
     (

      0 ,
      Plainise( "IniSeg" ) + LparenString() ,
      CommaString() ,
      RparenString()

      ) ,
     GetTypeName<ArrayTypeOfComputableFunction<Ret>>() ,
     VariableSymbol<ArrayTypeOfComputableFunction<Ret>>( "a" ) ,
     VariableSymbol<int>( "n" , GetTypeName<nat>() )

       };

  return f;

}

template <typename Ret> inline ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> > InitialSegmentSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a , ExpressionOfComputableFunction<nat> n ) { return InitialSegmentSymbol<Ret>()( a , n ); }


template <typename Ret> inline const FunctionSymbol<ArrayTypeOfComputableFunction<Ret>,ArrayTypeOfComputableFunction<Ret>,nat>& FinalSegmentSymbol()
{

  static const FunctionSymbol<ArrayTypeOfComputableFunction<Ret>,ArrayTypeOfComputableFunction<Ret>,nat> f
  {

     "FinSeg" ,
     SeparatorOfComputableFunction
     (

      0 ,
      Plainise( "FinSeg" ) + LparenString() ,
      CommaString() ,
      RparenString()

      ) ,
     GetTypeName<ArrayTypeOfComputableFunction<Ret>>() ,
     VariableSymbol<ArrayTypeOfComputableFunction<Ret>>( "a" ) ,
     VariableSymbol<int>( "n" , GetTypeName<nat>() )

       };

  return f;

}

template <typename Ret> inline ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> > FinalSegmentSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a , ExpressionOfComputableFunction<nat> n ) { return FinalSegmentSymbol<Ret>()( a , n ); }

template <typename Ret> inline FunctionSymbol<ArrayTypeOfComputableFunction<Ret>,nat> ArrayiseSymbol( const FunctionSymbol<Ret,nat>& f )
{

  return FunctionSymbol<ArrayTypeOfComputableFunction<Ret>,nat>
    (

     "ToArray" + LbrackString() + f.GetNodeString( 2 ) + RbrackString() ,
     GetTypeName<Ret>() ,
     VariableSymbol<int>( "n" , GetTypeName<nat>() )

     );

}
