// IllegalCall/a_Macro.hpp

#pragma once
#include "../a_Macro.hpp"

#define ERR_CALL IndicateIllegalCall( POSITION ) 

#define g_OCCURRENCE_OF_ILLEGAL_CALL ( *GLOBAL_VARIABLE( bool , OCCURRENCE_OF_ILLEGAL_CALL , false ) ) 
