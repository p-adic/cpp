// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Guide/Expression/a_Macro.hpp

#pragma once

#define DEFINITION_OF_EXPRESSION_TYPE_OF( RET ) \
						\
  template <>					\
  class ExpressionTypeOf< RET > :		\
    public EmptySet				\
  {						\
						\
  public:					\
    using type = RET ;				\
						\
  };						\
						\


