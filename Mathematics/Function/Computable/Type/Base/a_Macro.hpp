// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Base/a_Macro.hpp

#pragma once

#define DEFINITION_OF_BASE_TYPE( RET )		\
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



