// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Array/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Basic/nat/a_Body.hpp"
#include "../../Operator/a_Body.hpp"

template <typename Ret> inline ArrayTypeOfComputableFunction<Ret>::ArrayTypeOfComputableFunction() noexcept : TypeOfComputableFunction( GetName() , GetName() ) {}

template <typename Ret> inline const string& ArrayTypeOfComputableFunction<Ret>::GetName() noexcept { return GetSyntax().GetNodeString( 2 ); }

template <typename Ret> inline const SyntaxOfComputableFunction& ArrayTypeOfComputableFunction<Ret>::GetSyntax() noexcept
{

  static const SyntaxOfComputableFunction t
  {

    TypeString() ,
      ArrayString() ,
      GetTypeString<Ret>() + SupString() + LbraceString() + "< \\omega" + RbraceString() ,
      GetTypeSyntax<Ret>().Get()

      };

  return t;
  
}


template <typename Ret> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( ArrayTypeOfComputableFunction<Ret> , Concatenate , Frown );
template <typename Ret> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( ArrayTypeOfComputableFunction<Ret> , Concatenate );
template <typename Ret, typename... Args> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( ArrayTypeOfComputableFunction<Ret> , Concatenate , Symbol<Ret> );

template <typename Ret> inline DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( ArrayTypeOfComputableFunction<Ret> , + , Concatenate );



template <typename Ret> inline const FunctionSymbol<nat,ArrayTypeOfComputableFunction<Ret> >& LengthSymbol()
{

  static const FunctionSymbol<nat,ArrayTypeOfComputableFunction<Ret> > f
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

template <typename Ret> inline PrettyExpression<nat> LengthSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a ) { return LengthSymbol<Ret>()( a ); }

template <typename Ret> inline const PrettyOperator<Ret,ArrayTypeOfComputableFunction<Ret>,nat>& EntryAccessSymbol()
{

  static const PrettyOperator<Ret,ArrayTypeOfComputableFunction<Ret>,nat> f
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

template <typename Ret> inline ExpressionOfComputableFunction<Ret> EntryAccessSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a , const PrettyExpression<nat>& n ) { return EntryAccessSymbol<Ret>()( a , n ); }

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
     GetTypeName<ArrayTypeOfComputableFunction<Ret> >() ,
     VariableSymbol<ArrayTypeOfComputableFunction<Ret> >( "a" ) ,
     VariableSymbol<int>( "n" , GetTypeName<nat>() )

       };

  return f;

}

template <typename Ret> inline ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> > InitialSegmentSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a , PrettyExpression<nat> n ) { return InitialSegmentSymbol<Ret>()( a , n ); }


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
     GetTypeName<ArrayTypeOfComputableFunction<Ret> >() ,
     VariableSymbol<ArrayTypeOfComputableFunction<Ret> >( "a" ) ,
     VariableSymbol<int>( "n" , GetTypeName<nat>() )

       };

  return f;

}

template <typename Ret> inline ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> > FinalSegmentSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a , PrettyExpression<nat> n ) { return FinalSegmentSymbol<Ret>()( a , n ); }

template <typename Ret> inline const PrettyFunction<ArrayTypeOfComputableFunction<Ret>,Ret>& WrapSymbol()
{

  static const FunctionSymbol<ArrayTypeOfComputableFunction<Ret>,Ret> f
  {

     "Wrap" ,
     SeparatorOfComputableFunction
     (

      0
      ,
      LparenString() ,
      RparenString()
      
      ) ,
     GetTypeName<ArrayTypeOfComputableFunction<Ret> >() ,
     VariableSymbol<Ret>( "x" )

       };

  return f;

}

template <typename Ret> inline ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> > WrapSymbolApplication( const ExpressionOfComputableFunction<Ret>& x ) { return WrapSymbol<Ret>()( x ); }

template <typename Ret> inline PrettyFunction<ArrayTypeOfComputableFunction<Ret>,nat> ArrayiseSymbol( const FunctionSymbol<Ret,int>& f , const PrettyVariable<nat>& n )
{

  return FunctionSymbol<ArrayTypeOfComputableFunction<Ret>,int>
    (

     "Arrayised_" + f.GetNodeString( 2 ) ,
     SeparatorOfComputableFunction
     (

      0
      ,
      LparenString() +
      f.GetNodeString( 6 ) +
      RparenString() +
      SubString() +
      LbraceString() +
      f.GetNodeString( 4 , 2 ) +
      SpaceString() +
      EqString() +
      SpaceString() +
      to_string( 0 ) +
      RbraceString() +
      SupString() +
      LbraceString()
      ,
      SpaceString() +
      "- 1" +
      RbraceString()
      
      ) ,
     GetTypeName<Ret>() ,
     n

     );

}

inline PrettyFunction<ArrayTypeOfComputableFunction<bool>,nat> ArrayiseSymbol( const RelationSymbol<int>& r , const PrettyVariable<nat>& n )
{

  return FunctionSymbol<ArrayTypeOfComputableFunction<bool>,int>
    (

     "Arrayised_" + r.GetNodeString( 2 ) ,
     SeparatorOfComputableFunction
     (

      0
      ,
      LparenString() +
      r.GetNodeString( 6 ) +
      RparenString() +
      SubString() +
      LbraceString() +
      r.GetNodeString( 4 , 2 ) +
      SpaceString() +
      EqString() +
      SpaceString() +
      to_string( 0 ) +
      RbraceString() +
      SupString() +
      LbraceString()
      ,
      SpaceString() +
      "- 1" +
      RbraceString()
      
      ) ,
     GetTypeName<bool>() ,
     n

     );

}

