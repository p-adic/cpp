// c:/Users/user/Documents/Programming/Utility/GlobalVariable/a_Macro.hpp

#pragma once
#include "../String/a_Macro.hpp"

// __VA_ARGS__ Ç…ÇÕ ARGUMENTS Ç© FUNCTION_NAME , ARGUMENTS Çë„ì¸Ç∑ÇÈÅB
#define GLOBAL_CONSTANT( TYPENAME , CONSTANT_NAME , ... ) ( to_GlobalConstant< TYPENAME >( TO_STRING( CONSTANT_NAME ) , __VA_ARGS__ ) ) 
#define GLOBAL_VARIABLE( TYPENAME , VARIABLE_NAME , ... ) ( to_GlobalVariable< TYPENAME >( TO_STRING( VARIABLE_NAME ) , __VA_ARGS__ ) ) 
#define GLOBAL_POINTER( TYPENAME , POINTER_NAME , ... ) ( to_GlobalPointer< TYPENAME >( TO_STRING( POINTER_NAME ) , __VA_ARGS__ ) ) 


#define DECLARATION_OF_GLOBAL_CONSTANT_STRING( FUNC )	\
							\
  inline const string& FUNC() noexcept;			\
							\

#define DEFINITION_OF_GLOBAL_CONSTANT_STRING( FUNC , NAME )		\
									\
  inline const string& FUNC() noexcept { static const string s = TO_STRING( NAME ); return s; } \
									\

