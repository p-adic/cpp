// IllegalImput/a_Macro.hpp

#pragma once
#include "../a_Macro.hpp"

#define g_OCCURRENCE_OF_ILLEGAL_IMPUT ( *GLOBAL_VARIABLE( bool , OCCURRENCE_OF_ERR_IMPUT , false ) ) 
#define ERR_IMPUT( ... ) ThrowIllegalImput( POSITION , ARGUMENTS( __VA_ARGS__ ) ) 
