// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/Basic/int/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"


template <> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( int , Plus , Plus );
template <> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( int , Times , Times );


inline DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , + , Plus );
inline DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , - , Minus );
inline DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , * , Times );
inline DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , / , Slash );
inline DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , % , Mod );
inline DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , ^ , Power );

inline const FunctionSymbol<string,int>& StringiseSymbol()
{

  static const FunctionSymbol<string,int> r
  {

    "stringise" ,
      SeparatorOfComputableFunction
      (

       0 ,
       EmptyString() ,
       EmptyString()

       ) ,
      GetTypeName<string>() ,
      VariableSymbol<int>( "n" )

      };

  return f;

}

inline const PrettyRelation<int>& NonNegativeSymbol()
{

  static const PrettyRelation<int> r
  {

    "\\geq 0" ,
      SeparatorOfComputableFunction
      (

       0 ,
       EmptyString() ,
       SpaceString() + "\\geq 0"

       ) ,
      GetTypeName<bool>() ,
      VariableSymbol<int>( "n" )

      };

  return r;

}
