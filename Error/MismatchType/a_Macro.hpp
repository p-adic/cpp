// c:/Users/user/Documents/Programming/Error/MismatchType/a_Macro.hpp

#pragma once
#include "../a_Macro.hpp"

#ifdef DEBUG

  #define MISMATCH( ... ) \
    BreakPoint(); \
    ThrowMismatchType< __VA_ARGS__ >( POSITION ) 

#else

  #define MISMATCH( ... ) ThrowMismatchType< __VA_ARGS__ >( POSITION ) 

#endif

#define g_OCCURRENCE_OF_MISMATCH_TYPE ( *GLOBAL_VARIABLE( bool , OCCURRENCE_OF_MISMATCH_TYPE , false ) ) 
