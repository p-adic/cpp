// c:/Users/user/Documents/Programming/Utility/TwoPointerApproach/Debug/a_Macro.hpp

#pragma once
#include "../../../../Utility/StdStream/a_Macro.hpp"

#ifndef decldecay_t
  #define decldecay_t( VAR ) decay_t<decltype( VAR )>
#endif

#ifndef TPA
/* // 尺取り法用
VAR_TPAは尺取り法用の変数名の接頭辞で、実際の変数名ではなく、_Lと_Rと_infoがつく。
ANSWER ## _temp = {VAR_TPA ## _L,VAR_TPA ## _R,VPA_TPA ## _info}を{INIT,INIT,INFO_init}で初期化する。VPA_TPA ## _infoは区間和など。
ANSWER ## _tempがCONTINUE_CONDITIONを満たす限り、ANSWER ## _tempが条件ON_CONDITIONを満たすか否かを判定し、
それがtrueになるかVAR_TAR ## _LがVAR_TAR ## _Rに追い付くまでVAR_TPA ## _LとVPA_TPA ## _infoの更新操作UPDATE_Lを繰り返し、
その後VAR_TPA ## _RとVPA_TPA ## _infoの更新操作UPDATE_Rを行う。（マクロとコンマの制約上、関数オブジェクトを用いる）
ON_CONDITIONがtrueとなる極大閉区間とその時点でのinfoをANSWERに格納する。
例えば長さNの非負整数値配列Aで極大な正値区間とそこでの総和を取得したい場合
auto update_L = [&]( int& i_L , auto& i_info ){ i_info -= A[i_L++]; };
auto update_R = [&]( int& i_R , auto& i_info ){ if( ++i_R < N ){ i_info += A[i_R]; } };
TPA( interval , i , 0 , i_R < N , update_L( i_L , i_info ) , update_R( i_R , i_info ) , A[i_L] > 0 && A[i_R] > 0 , ll( A[0] ) );
とすればtuple<int,int,ll>値配列intervalに{左端,右端,総和}の列が格納される。
VAR_TPA ## _infoもintervalにコピーされるので、setやvectorなどのコピーのコストが
大きいデータを用いてon,off判定する時はTPAより前に宣言して使う。*/
#define TPA( ANSWER , VAR_TPA , INIT , CONTINUE_CONDITION , UPDATE_L , UPDATE_R , ON_CONDITION , INFO_init ) \
  vector<tuple<decldecay_t( INIT ),decldecay_t( INIT ),decldecay_t( INFO_init )>> ANSWER{}; \
  {									\
    auto init_TPA = INIT;						\
    decldecay_t( ANSWER.front() ) ANSWER ## _temp = { init_TPA , init_TPA , INFO_init }; \
    auto ANSWER ## _prev = ANSWER ## _temp;				\
    auto& VAR_TPA ## _L = get<0>( ANSWER ## _temp );			\
    auto& VAR_TPA ## _R = get<1>( ANSWER ## _temp );			\
    auto& VAR_TPA ## _info = get<2>( ANSWER ## _temp );			\
    bool on_TPA_prev = false;						\
    while( true ){                                                      \
      bool continuing = CONTINUE_CONDITION;				\
      bool on_TPA = continuing && ( ON_CONDITION );			\
      DERR( continuing ? "尺取り中" : "尺取り終了" , ": [L,R] = [" , VAR_TPA ## _L , "," , VAR_TPA ## _R , "] ," , on_TPA_prev ? "on" : "off" , "->" , on_TPA ? "on" : "off" , ", info =" , VAR_TPA ## _info ); \
      if( on_TPA_prev && ! on_TPA ){					\
	ANSWER.push_back( ANSWER ## _prev );				\
	DERR( #ANSWER , "に" , ANSWER ## _prev , "を格納します。" );	\
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

