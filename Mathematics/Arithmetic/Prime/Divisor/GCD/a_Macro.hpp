// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/GCD/a_Macro.hpp

#pragma once

#define DEFINITION_OF_UNSIGNED_GCD( UINT )			\
  UINT GCD( const UINT& b_0 , const UINT& b_1 )	\
  {								\
								\
    UINT a_0 = b_0;						\
    UINT a_1 = b_1;						\
								\
    while( a_1 != 0 ){						\
								\
      swap( a_0 %= a_1 , a_1 );					\
								\
    }								\
								\
    return a_0;							\
								\
  }								\


