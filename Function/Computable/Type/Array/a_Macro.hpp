// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Array/a_Macro.hpp

#pragma once

#define ARRAY( TYPE_NAME , RET )				\
								\
  using TYPE_NAME = ArrayTypeOfComputableFunction< RET >;	\
  DEFINITION_OF_DUMMY_CLASS( TYPE_NAME );			\
								\


