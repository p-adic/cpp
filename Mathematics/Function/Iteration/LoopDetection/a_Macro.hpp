// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/LoopDetection/a_Macro.hpp

#pragma once
#define SFINAE_FOR_LOOP_DETECTION_BODY( DEFAULT ) enable_if_t<is_convertible_v<U,T> >* DEFAULT
