// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/a_Macro.hpp

#pragma once

#define DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( FUNC )	\
									\
  inline const string& CONNECT( FUNC , String )() noexcept		\
									\
    

#define DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( FUNC , NAME )	\
									\
  DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( FUNC )		\
  { static const string name = TO_STRING( NAME ); return name; }	\
									\
  

