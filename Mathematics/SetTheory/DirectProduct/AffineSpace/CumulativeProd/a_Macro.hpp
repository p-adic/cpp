// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/a_Macro.hpp

#pragma once
#define SFINAE_FOR_CUMULATIVE_PROD( DEFAULT ) enable_if_t<is_convertible_v<U,T> >* DEFAULT
