// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/OnDo/SetTouji/a_Macro.hpp

#pragma once
#include "../../../../../Utility/String/a_Macro.hpp"

#define DEFINITION_OF_SETTOUJI_OF_ONDO( SETTOUJI )		\
  const SetTouJiOfOnDo& SetTouJiOfOnDo:: SETTOUJI () noexcept	\
  {								\
								\
    static const SetTouJiOfOnDo s{ TO_STRING( SETTOUJI ) };	\
    return s;							\
								\
  }								\
								\

