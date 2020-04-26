// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/Basic/int/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"

const PrettyRelation<int>& NonNegativeSymbol()
{

  static const PrettyRelation<int> r
  {

    "\\geq 0" ,
      SeparatorOfComputableFunction
      (

       0 ,
       EmptyString() ,
       SpaceString() + "\\geq 0" + SpaceString()

       ) ,
      GetTypeName<bool>() ,
      VariableSymbol<int>( "n" )

      };

  return r;

}
