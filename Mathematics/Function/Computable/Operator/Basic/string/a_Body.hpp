// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Basic/string/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"
#include "../../../Type/Basic/a_Body.hpp"


template <> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( string , Plus , Frown );


inline DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( string , + , Plus );

inline const PrettyFunction<nat,string>& LengthSymbol()
{

  static const PrettyFunction<nat,string> f
    {

    "Lng" ,
     SeparatorOfComputableFunction
     (

      0 ,
      Plainise( "Lng" ) + LparenString() ,
      RparenString()

      ) ,
     GetTypeName<nat>() ,
     VariableSymbol<string>( "s" ) ,

      };

  return f;

}

inline PrettyExpression<nat> LengthSymbolApplication( const ExpressionOfComputableFunction<string>& s ) { return LengthSymbol()( s ); }

inline const PrettyFunction<string,string,nat>& EntryAccessSymbol()
{

  static const PrettyFunction<string,string,nat> f
  {

     LbrackString() + RbrackString() ,
     SeparatorOfComputableFunction
     (

      0 ,
      LparenString() ,
      RparenString() + SubString() + LbraceString() ,
      RbraceString()

      ) ,
     GetTypeName<string>() ,
     VariableSymbol<string>( "s" ) ,
     VariableSymbol<int>( "n" , GetTypeName<nat>() )

       };

  return f;

}

inline ExpressionOfComputableFunction<string> EntryAccessSymbolApplication( const ExpressionOfComputableFunction<string>& s , const PrettyExpression<nat>& n ) { return EntryAccessSymbol()( s , n ); }


inline const PrettyFunction<string,string,nat>& InitialSegmentSymbol()
{

  static const PrettyFunction<string,string,nat> f
  {

     "IniSeg" ,
     SeparatorOfComputableFunction
     (

      0 ,
      Plainise( "IniSeg" ) + LparenString() ,
      CommaString() ,
      RparenString()

      ) ,
     GetTypeName<string>() ,
     VariableSymbol<string>( "s" ) ,
     VariableSymbol<int>( "n" , GetTypeName<nat>() )

       };

  return f;

}

inline ExpressionOfComputableFunction<string> InitialSegmentSymbolApplication( const ExpressionOfComputableFunction<string>& s , PrettyExpression<nat> n ) { return InitialSegmentSymbol()( s , n ); }


inline const PrettyFunction<string,string,nat>& FinalSegmentSymbol()
{

  static const PrettyFunction<string,string,nat> f
  {

     "FinSeg" ,
     SeparatorOfComputableFunction
     (

      0 ,
      Plainise( "FinSeg" ) + LparenString() ,
      CommaString() ,
      RparenString()

      ) ,
     GetTypeName<string>() ,
     VariableSymbol<string>( "s" ) ,
     VariableSymbol<int>( "n" , GetTypeName<nat>() )

       };

  return f;

}

inline ExpressionOfComputableFunction<string> FinalSegmentSymbolApplication( const ExpressionOfComputableFunction<string>& s , PrettyExpression<nat> n ) { return FinalSegmentSymbol()( s , n ); }

