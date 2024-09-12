// c:/Users/user/Documents/Programming/Utility/Tuple/a_Body.hpp

#pragma once
#include "a.hpp"

#if !defined( SAMPLE_CHECK ) && defined( DEBUG )
  #include "StdStream/Debug/a.hpp"
#else
  #include "StdStream/a.hpp"
#endif

#include "Hash/a_Body.hpp"

DEFINITION_OF_ARITHMETIC_FOR_TUPLE( + );
DEFINITION_OF_ARITHMETIC_FOR_TUPLE( - );
DEFINITION_OF_ARITHMETIC_FOR_TUPLE( * );
DEFINITION_OF_ARITHMETIC_FOR_TUPLE( / );
DEFINITION_OF_ARITHMETIC_FOR_TUPLE( % );

DEFINITION_OF_INCREMENT_FOR_TUPLE( ++ );
DEFINITION_OF_INCREMENT_FOR_TUPLE( -- );

