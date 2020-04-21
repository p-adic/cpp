// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Basic/a_Macro.hpp

#pragma once

#define DEFINITION_OF_IS_BASIC( TYPE , NAME )				\
									\
  template <>								\
  class IsBasicType< TYPE > :						\
    public EmptySet							\
  {									\
									\
  public:								\
    static constexpr const bool value = true;				\
    static inline const string& GetName() noexcept { static const string name = TO_STRING( NAME ); return name; }; \
									\
  };									\
									\

