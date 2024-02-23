// c:/Users/user/Documents/Programming/Error/IllegalAccess/a_Macro.hpp

#pragma once

#include "../a_Macro.hpp"

#define ACCESS( ... ) SafeAccess( POSITION , ARGUMENTS( __VA_ARGS__ ) ) 

#ifdef DEBUG

  #define UNINITIALISED( ... ) BREAK( "UNINITIALISED" , __VA_ARGS__ ); IndicateUninitialisedAccess( POSITION , ARGUMENTS( __VA_ARGS__ ) ) 

#else

  #define UNINITIALISED( ... ) IndicateUninitialisedAccess( POSITION , ARGUMENTS( __VA_ARGS__ ) ) 

#endif

#define g_OCCURRENCE_OF_ILLEGAL_ACCESS ( *GLOBAL_VARIABLE( bool , OCCURRENCE_OF_ILLEGAL_ACCESS , false ) ) 
