// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Base/a_Macro.hpp

#pragma once

#define DEFINITION_OF_BASE_TYPE( TYPE_NAME , DEFINITION )		\
									\
  template <> inline const TypeOfComputableFunction& BaseType< TYPE_NAME >() { static const TypeOfComputableFunction base_type{ TO_STRING( TYPE_NAME ) , DEFINITION }; return base_type; } \
									\


#define DEFINITION_OF_BASE_TYPE_OF( RET )	\
						\
  template <>					\
  class BaseTypeOf< RET > :			\
    public EmptySet				\
  {						\
						\
  public:					\
    using type = RET ;				\
						\
  };						\
						\



