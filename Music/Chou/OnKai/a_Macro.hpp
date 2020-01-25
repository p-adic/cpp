// c:/Users/user/Documents/Programming/Music/Chou/OnKai/a_Macro.hpp

#pragma once
#include "../../../Utility/Macro.hpp"

#define DEFINITION_OF_GLOBAL_CONST_ON_KAI( NAME , I , II , III , IV , V , VI , VII ) \
  const OnKai& NAME () noexcept						\
  {									\
									\
    static const OnKai N( to_string( TO_STRING( NAME ) ) , I , II , III , IV , V , VI , VII ); \
    return N;								\
									\
  }									\
									\

