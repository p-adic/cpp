// c:/Users/user/Documents/Programming/Error/FaultInCoding/a_Macro.hpp

#pragma once

#include "../a_Macro.hpp"

#ifdef DEBUG

  #define ERR_CODE BREAK( "ERR_CODE" ); ThrowFaultInCoding( POSITION ) 

#else

  #define ERR_CODE ThrowFaultInCoding( POSITION ) 

#endif
