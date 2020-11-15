// c:/Users/user/Documents/Programming/Error/IllegalImput/a_Macro.hpp

#pragma once

#include "../a_Macro.hpp"

#define g_OCCURRENCE_OF_ILLEGAL_IMPUT ( *GLOBAL_VARIABLE( bool , OCCURRENCE_OF_ERR_IMPUT , false ) )

#ifdef DEBUG

  #define ERR_IMPUT( ... ) \
    BREAK; \
    ThrowIllegalImput( POSITION , ARGUMENTS( __VA_ARGS__ ) ) 

#else

  #define ERR_IMPUT( ... ) ThrowIllegalImput( POSITION , ARGUMENTS( __VA_ARGS__ ) ) 

#endif
