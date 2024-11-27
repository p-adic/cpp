// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Valid/a_Macro.hpp

#pragma once

#define DEFINITION_OF_IS_PRIMITIVE( TYPE , NAME )			\
									\
  template <>								\
  class IsPrimitiveType< TYPE > :					\
    public EmptySet							\
  {									\
									\
  public:								\
    static constexpr const bool value = true;				\
    static inline const string& GetName() noexcept { return CONNECT( NAME , String )(); }; \
									\
  };									\
									\

