// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Basic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Expression/Primitive/a.hpp"
#include "int/a_Body.hpp"
#include "string/a_Body.hpp"
#include "bool/a_Body.hpp"

namespace QpBasic
{

  #include "QpBasic/a_Body.hpp"

}


template <typename Ret> DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( Ret , + , Plus );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , + , Plus );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( string , + , Plus );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( bool , + , Plus );

template <typename Ret> DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( Ret , - , Minus );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , - , Minus );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( bool , - , Minus );

template <typename Ret> DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( Ret , * , Times );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , * , Times );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( bool , * , Times );

template <typename Ret> DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( Ret , / , Slash );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , / , Slash );

template <typename Ret> DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( Ret , % , Mod );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , % , Mod );

template <typename Ret> DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( Ret , ^ , Power );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , ^ , Power );


inline const ExpressionOfComputableFunction<int>& InftySymbol(){ static const ExpressionOfComputableFunction<int> n = ExpressionOfComputableFunction<int>( infty() ); return n; }
