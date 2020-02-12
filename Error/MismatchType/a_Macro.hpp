// c:/Users/user/Documents/Programming/Error/MismatchType/a_Macro.hpp

#pragma once
#include "../a_Macro.hpp"

#define MISMATCH( ... ) ThrowMismatchType< __VA_ARGS__ >( POSITION ) 

#define g_OCCURRENCE_OF_MISMATCH_TYPE ( *GLOBAL_VARIABLE( bool , OCCURRENCE_OF_MISMATCH_TYPE , false ) ) 
