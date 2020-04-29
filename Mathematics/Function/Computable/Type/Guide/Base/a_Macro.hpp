// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Guide/Base/a_Macro.hpp

#pragma once

#define DEFINITION_OF_BASE_TYPE( TYPE_NAME , DEFINITION )		\
									\
  template <> inline const TypeOfComputableFunction& BaseType< TYPE_NAME >() { static const TypeOfComputableFunction base_type{ Plainise( TO_STRING( TYPE_NAME ) ) , DEFINITION }; return base_type; } \

