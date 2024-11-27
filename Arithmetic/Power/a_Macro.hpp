// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/a_Macro.hpp

#pragma once

#ifndef decldecay_t
  #define decldecay_t( VAR ) decay_t<decltype( VAR )>
#endif

#ifndef POWER_MOD
  #define POWER_MOD( ANSWER , ARGUMENT , EXPONENT , MODULO )		\
    ll ANSWER{ 1 };							\
    {									\
      ll ARGUMENT_FOR_SQUARE_FOR_POWER = ( ( ARGUMENT ) % ( MODULO ) ) % ( MODULO ); \
      ARGUMENT_FOR_SQUARE_FOR_POWER < 0 ? ARGUMENT_FOR_SQUARE_FOR_POWER += ( MODULO ) : ARGUMENT_FOR_SQUARE_FOR_POWER; \
      decldecay_t( EXPONENT ) EXPONENT_FOR_SQUARE_FOR_POWER = ( EXPONENT ); \
      while( EXPONENT_FOR_SQUARE_FOR_POWER != 0 ){			\
        if( EXPONENT_FOR_SQUARE_FOR_POWER % 2 == 1 ){			\
          ANSWER = ( ANSWER * ARGUMENT_FOR_SQUARE_FOR_POWER ) % ( MODULO ); \
        }                                                               \
        ARGUMENT_FOR_SQUARE_FOR_POWER = ( ARGUMENT_FOR_SQUARE_FOR_POWER * ARGUMENT_FOR_SQUARE_FOR_POWER ) % ( MODULO ); \
        EXPONENT_FOR_SQUARE_FOR_POWER /= 2;				\
      }									\
    }									\

#endif

