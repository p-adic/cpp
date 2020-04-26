// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Basic/string/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"
#include "../../../Type/Basic/a_Body.hpp"

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

inline const PrettyFunction<string,string,nat>& EntryAccessSymbol()
{

  static const PrettyFunction<string,string,nat> f
  {

     LbrackString() + RbrackString() ,
     SeparatorOfComputableFunction
     (

      0 ,
      EmptyString() ,
      LbrackString() ,
      RbrackString()

      ) ,
     GetTypeName<string>() ,
     VariableSymbol<string>( "s" ) ,
     VariableSymbol<int>( "n" , GetTypeName<nat>() )

       };

  return f;

}

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
