// c:/Users/user/Documents/Programming/Music/Chou/OnKai/a_Macro.hpp

#pragma once
#include "../../../Utility/Macro.hpp"

#define DEFINITION_OF_GLOBAL_CONST_ON_KAI( FUNCTION , I , II , III , IV , V , VI , VII ) \
  const OnKai& FUNCTION () noexcept					\
  {									\
									\
    static const OnKai N( to_string( TO_STRING( FUNCTION ) ) , I , II , III , IV , V , VI , VII ); \
    return N;								\
									\
  }									\
									\

