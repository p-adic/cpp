// UnknownError/a_Macro.hpp

#pragma once
#include "../a_Macro.hpp"

#define ERR_UNKNOWN( ... ) ThrowUnknownError( POSITION , ARGUMENTS( __VA_ARGS__ ) ) 
