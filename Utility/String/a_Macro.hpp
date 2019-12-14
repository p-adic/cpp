// String/a_Macro.hpp

#pragma once
#include "../../SFINAE/MemberFunction/a_Macro.hpp"

#define ARGUMENTS( ... ) TO_STRING( __VA_ARGS__ ) , __VA_ARGS__ 
#define ECHO( ... ) IndicateArguments( ARGUMENTS( __VA_ARGS__ ) ) 
