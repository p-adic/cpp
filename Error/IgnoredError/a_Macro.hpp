// c:/Users/user/Documents/Programming/Error/IgnoredError/a_Macro.hpp

#pragma once

#include "../a_Macro.hpp"

#define IGNORED_ERR( ... ) IndicateIgnoredError( POSITION , ARGUMENTS( __VA_ARGS__ ) ) 
