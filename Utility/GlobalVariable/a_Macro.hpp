// GlobalVariable/a_Macro.hpp

#pragma once
#include "../../Error/IllegalAccess/a_Macro.hpp"

// __VA_ARGS__ には ARGUMENTS か FUNCTION_NAME , ARGUMENTS を代入する。
#define GLOBAL_CONSTANT( TYPENAME , CONSTANT_NAME , ... ) ( to_GlobalConstant< TYPENAME >( TO_STRING( CONSTANT_NAME ) , __VA_ARGS__ ) ) 
#define GLOBAL_VARIABLE( TYPENAME , VARIABLE_NAME , ... ) ( to_GlobalVariable< TYPENAME >( TO_STRING( VARIABLE_NAME ) , __VA_ARGS__ ) ) 
#define GLOBAL_POINTER( TYPENAME , POINTER_NAME , ... ) ( to_GlobalPointer< TYPENAME >( TO_STRING( POINTER_NAME ) , __VA_ARGS__ ) ) 
