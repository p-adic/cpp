// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Array/Nest/a_Macro.hpp

#pragma once

#define NEST( TYPE_NAME , RET )					\
								\
  using TYPE_NAME = NestedArrayTypeOfComputableFunction< RET >;	\
  DEFINITION_OF_DUMMY_CLASS( TYPE_NAME );			\
								\

