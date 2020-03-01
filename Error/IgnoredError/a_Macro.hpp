// c:/Users/user/Documents/Programming/Error/IgnoredError/a_Macro.hpp

#pragma once

#include "../a_Macro.hpp"

#ifdef DEBUG

  #define IGNORED_ERR( ... ) \
    BreakPoint(); \
    IndicateIgnoredError( POSITION , ARGUMENTS( __VA_ARGS__ ) ) 

#else

  #define IGNORED_ERR( ... ) IndicateIgnoredError( POSITION , ARGUMENTS( __VA_ARGS__ ) ) 

#endif

