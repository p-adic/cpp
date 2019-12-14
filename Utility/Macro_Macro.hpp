// Macro_Macro.hpp

#pragma once

#define CONNECT( S1 , S2 ) SUBSTITUTE_CONNECT( S1 , S2 ) 
#define SUBSTITUTE_CONNECT( S1 , S2 ) S1 ## S2 

#define TO_STRING( ... ) SUBSTITUTE_TO_STRING( __VA_ARGS__ ) 
#define SUBSTITUTE_TO_STRING( ... ) to_string( #__VA_ARGS__ ) 
