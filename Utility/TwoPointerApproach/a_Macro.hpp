// c:/Users/user/Documents/Programming/Utility/TwoPointerApproach/a_Macro.hpp

#pragma once

#ifndef decldecay_t
  #define decldecay_t( VAR ) decay_t<decltype( VAR )>
#endif

#ifndef TPA
// 尺取り法用
// VAR_TPA_LとVAR_TPA_RをINITで初期化し、VAR_TPA_RがCONTINUE_CONDITIONを満たす限り、
// 閉区間[VAR_TPA_L,VAR_TPA_R]が条件ON_CONDITIONを満たすか否かを判定し、
// trueになるかVAR_TAR_LがVAR_TAR_Rに追い付くまでVAR_TPA_Lの更新操作UPDATE_Lを繰り返し、
// その後VAR_TPA_Rの更新操作UPDATE_Rを行う。
// ON_CONDITIONがtrueとなる極大閉区間とその時点でのINFOをANSWERに格納する。
#define TPA( ANSWER , VAR_TPA , INIT , CONTINUE_CONDITION , UPDATE_L , UPDATE_R , ON_CONDITION , INFO ) \
  vector<tuple<decldecay_t( INIT ),decldecay_t( INIT ),decldecay_t( INFO )>> ANSWER{}; \
  {									\
    auto init_TPA = INIT;						\
    decldecay_t( ANSWER.front() ) ANSWER ## _temp = { init_TPA , init_TPA , INFO }; \
    auto ANSWER ## _prev = ANSWER ## _temp;				\
    auto& VAR_TPA ## _L = get<0>( ANSWER ## _temp );			\
    auto& VAR_TPA ## _R = get<1>( ANSWER ## _temp );			\
    auto& VAR_TPA ## _info = get<2>( ANSWER ## _temp );			\
    bool on_TPA_prev = false;						\
    while( true ){							\
      bool continuing = CONTINUE_CONDITION;				\
      bool on_TPA = continuing && ( ON_CONDITION );			\
      CERR( continuing ? "尺取り中" : "尺取り終了" , "： [L,R] = [" , VAR_TPA ## _L , "," , VAR_TPA ## _R , "] ," , on_TPA_prev ? "on" : "off" , "->" , on_TPA ? "on" : "off" , ", info =" , VAR_TPA ## _info );	\
      if( on_TPA_prev && ! on_TPA ){					\
	ANSWER.push_back( ANSWER ## _prev );				\
      }									\
      if( continuing ){							\
	if( on_TPA || VAR_TPA ## _L == VAR_TPA ## _R ){			\
	  ANSWER ## _prev = ANSWER ## _temp;				\
	  UPDATE_R;							\
	} else {							\
	  UPDATE_L;							\
	}								\
      } else {								\
	break;								\
      }									\
      on_TPA_prev = on_TPA;						\
    }									\
  }									\

#endif
