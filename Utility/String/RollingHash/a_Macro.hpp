// c:/Users/user/Documents/Programming/Utility/String/RollingHash/a_Macro.hpp

#pragma once

#ifndef decldecay_t
  #define decldecay_t( VAR ) decay_t<decltype( VAR )>
#endif
