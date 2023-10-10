// c:/Users/user/Documents/Programming/Error/UnknownError/a_Macro.hpp

#pragma once

#include "../a_Macro.hpp"

#ifdef DEBUG

  #define ERR_UNKNOWN( ... ) BREAK( "ERR_UNKNOWN" , __VA_ARGS__ ); ThrowUnknownError( POSITION , ARGUMENTS( __VA_ARGS__ ) ) 

#else

  #define ERR_UNKNOWN( ... ) ThrowUnknownError( POSITION , ARGUMENTS( __VA_ARGS__ ) ) 

#endif

