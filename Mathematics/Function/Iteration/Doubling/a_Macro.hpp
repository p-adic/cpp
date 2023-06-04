// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/Doubling/a_Macro.hpp

#pragma once
#define SFINAE_FOR_DOUBLING_BODY( DEFAULT ) enable_if_t<is_convertible_v<U,T> >* DEFAULT
