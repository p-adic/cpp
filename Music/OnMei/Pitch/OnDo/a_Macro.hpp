// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/OnDo/a_Macro.hpp

#pragma once

#define DEFINITION_OF_SETTOUJI_OF_ONDO( SETTOUJI )	\
  const string& OnDo:: SETTOUJI () noexcept		\
  {							\
							\
    static const string s = TO_STRING( SETTOUJI );	\
    return s;						\
							\
  }							\
							\

