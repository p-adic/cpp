// c:/Users/user/Documents/Programming/Utility/Tuple/a.hpp

#pragma once
#include "a_Macro.hpp"

#ifdef DEBUG
  #include "StdStream/Debug/a.hpp"
#else
  #include "StdStream/a.hpp"
#endif

DECLARATION_OF_ARITHMETIC_FOR_TUPLE( + );
DECLARATION_OF_ARITHMETIC_FOR_TUPLE( - );
DECLARATION_OF_ARITHMETIC_FOR_TUPLE( * );
DECLARATION_OF_ARITHMETIC_FOR_TUPLE( / );
DECLARATION_OF_ARITHMETIC_FOR_TUPLE( % );

DECLARATION_OF_INCREMENT_FOR_TUPLE( ++ );
DECLARATION_OF_INCREMENT_FOR_TUPLE( -- );
