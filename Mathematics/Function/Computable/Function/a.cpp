// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/a.cpp

#include "../../../Header.hpp"
#include "a_Body.hpp"

const FunctionSymbol<bool,bool>& NegSymbol()
{

  static const FunctionSymbol<bool,bool> f( "neg" , VariableSymbol<bool>( "x" ) );
    return f;

}

ConditionOfComputableFunction NegSymbolApplication( const ConditionOfComputableFunction& b )
{

  if( b.Name() == "neg" ){

    auto b_copy = b;
    VLTree<string>& t = b_copy.Ref();
    t = t.RightMostSubTreeCopy();
    return b_copyl;

  }

  return NegSymbol()( b );

}


DEFINITION_OF_LOGICAL_CONNECTIVE( To );
DEFINITION_OF_LOGICAL_CONNECTIVE( Equiv );
