// IllegalCall/a_Macro.hpp

#pragma once
#include "../a_Macro.hpp"

#ifdef DEBUG

  #define ERR_CALL \
    BreakPoint(); \
    IndicateIllegalCall( POSITION ) 

#else

  #define ERR_CALL IndicateIllegalCall( POSITION ) 

#endif

#define g_OCCURRENCE_OF_ILLEGAL_CALL ( *GLOBAL_VARIABLE( bool , OCCURRENCE_OF_ILLEGAL_CALL , false ) ) 
