// c:/Users/user/Documents/Programming/Error/IllegalInput/a_Macro.hpp

#pragma once

#include "../a_Macro.hpp"

#define g_OCCURRENCE_OF_ILLEGAL_INPUT ( *GLOBAL_VARIABLE( bool , OCCURRENCE_OF_ERR_INPUT , false ) )

#ifdef DEBUG

  #define ERR_INPUT( ... ) \
    BREAK; \
    ThrowIllegalInput( POSITION , ARGUMENTS( __VA_ARGS__ ) ) 

#else

  #define ERR_INPUT( ... ) ThrowIllegalInput( POSITION , ARGUMENTS( __VA_ARGS__ ) ) 

#endif
