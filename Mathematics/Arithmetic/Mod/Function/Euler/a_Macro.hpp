// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Euler/a_Macro.hpp

#pragma once

#define EULER_FUNCTION				\
  exponent.clear();				\
  INT answer = n;				\
  const INT size = P.size();			\
						\
  for( INT i = 0 ; i < size ; i++ ){		\
						\
    answer -= answer / P[i];			\
						\
  }						\
						\
  return answer;				\

#define CARMICHAEL_FUNCTION					\
  exponent.clear();						\
  INT answer = 1;						\
  INT size = P.size();						\
								\
  for( INT i = 0 ; i < size ; i++ ){				\
								\
    const INT& P_i = P[i];					\
    const INT& P_power_i = P_power[i];				\
    answer = LCM( answer , ( P_power_i - P_power_i / P_i ) );	\
								\
  }								\
								\
  return answer;						\

