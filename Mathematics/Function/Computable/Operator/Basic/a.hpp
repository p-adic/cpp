// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Basic/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../Expression/Primitive/a.hpp"
#include "int/a.hpp"
#include "string/a.hpp"
#include "bool/a.hpp"

namespace QpBasic
{

  #include "QpBasic/a.hpp"

}

template <typename Ret> DECLARATION_OF_TWO_ARY_BASIC_FUNCTION( Ret , + );
template <typename Ret> DECLARATION_OF_TWO_ARY_BASIC_FUNCTION( Ret , - );
template <typename Ret> DECLARATION_OF_TWO_ARY_BASIC_FUNCTION( Ret , * );
template <typename Ret> DECLARATION_OF_TWO_ARY_BASIC_FUNCTION( Ret , / );
template <typename Ret> DECLARATION_OF_TWO_ARY_BASIC_FUNCTION( Ret , % );
template <typename Ret> DECLARATION_OF_TWO_ARY_BASIC_FUNCTION( Ret , ^ );

inline const ExpressionOfComputableFunction<int>& InftySymbol();
