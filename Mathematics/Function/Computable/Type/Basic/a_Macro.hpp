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
    static inline const string& GetName() noexcept { return CONNECT( NAME , String )(); }; \
									\
  };									\
									\

#define DEFINITION_OF_BASIC_TYPE( TYPE_NAME , DEFINITION )		\
									\
  template <> inline const TypeOfComputableFunction& BasicType< TYPE_NAME >() { static const TypeOfComputableFunction basic_type{ TO_STRING( TYPE_NAME ) , DEFINITION }; return basic_type; } \
									\

