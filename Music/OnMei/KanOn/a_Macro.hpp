// c:/Users/user/Documents/Programming/Music/OnMei/KanOn/a_Macro.hpp

#pragma once
#include "../../../Utility/Macro.hpp"

#define DEFINITION_OF_GLOBAL_CONST_KAN_ON( NAME , NUM )	\
							\
  const KanOn& NAME () noexcept				\
  {							\
							\
    static const KanOn N( NUM );			\
    return N;						\
							\
  }							\
							\

