// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Basic/bool/a.cpp

#include "../../../Header.hpp"
#include "a_Body.hpp"


ConditionOfComputableFunction NegSymbolApplication( const ConditionOfComputableFunction& b )
{

  auto itr = ( b.Get() ).LeftMostNode();

  if( ! itr.IsValid() ){

    ERR_CODE;

  }
  
  if( *itr == FunctionString() ){

    itr++;
    itr++;
    itr++;
    
    if( ! itr.IsValid() ){

      ERR_CODE;

    }
    
    if( *itr == NegString() ){

      auto b_copy = b;
      VLTree<string>& t = b_copy.Ref();
      t = t.RightMostSubTreeCopy();
      return b_copy;

    }

  }

  return NegSymbol()( b );

}
