// c:/Users/user/Documents/Programming/Utility/BinarySearch/a_Macro.hpp

#pragma once
#include "../Stdstream/a_Macro.hpp"

#ifndef decldecay_t
  #define decldecay_t( VAR ) decay_t<decltype( VAR )>
#endif

#ifndef BS
/* 二分探索用 */
/* EXPRESSIONがANSWERの広義単調関数の時、EXPRESSION >= CONST_TARGETの整数解を格納。*/
#define BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , DESIRED_INEQUALITY , CONST_TARGET , INEQUALITY_FOR_CHECK , UPDATE_U , UPDATE_L , UPDATE_ANSWER ) \
  static_assert( ! is_same<decldecay_t( CONST_TARGET ),uint>::value && ! is_same<decldecay_t( CONST_TARGET ),ull>::value ); \
  ll ANSWER = MINIMUM;							\
  {									\
    ll ANSWER ## _L = MINIMUM;                                          \
    ll ANSWER ## _R = MAXIMUM;                                          \
    ANSWER = UPDATE_ANSWER;						\
    ll EXPRESSION_BS;							\
    const ll CONST_TARGET_BS = ( CONST_TARGET );			\
    ll DIFFERENCE_BS;							\
    while( ANSWER ## _L < ANSWER ## _R ){                               \
      DIFFERENCE_BS = ( EXPRESSION_BS = ( EXPRESSION ) ) - CONST_TARGET_BS; \
      CERR( "二分探索中:" , string{ #ANSWER } + "_L" , "=" , ANSWER ## _L , "<=" , #ANSWER , "=" , ANSWER , "<=" , ANSWER ## _R , "=" , string{ #ANSWER } + "_R" , ":" , #EXPRESSION , "=" , EXPRESSION_BS , DIFFERENCE_BS > 0 ? ">" : DIFFERENCE_BS < 0 ? "<" : "=" , CONST_TARGET_BS , "=" , #CONST_TARGET ); \
      if( DIFFERENCE_BS INEQUALITY_FOR_CHECK 0 ){			\
	ANSWER ## _R = UPDATE_U;                                        \
      } else {								\
	ANSWER ## _L = UPDATE_L;                                        \
      }									\
      ANSWER = UPDATE_ANSWER;						\
    }									\
    if( ANSWER ## _L > ANSWER ## _R ){                                  \
      CERR( "二分探索失敗:" , string{ #ANSWER } + "_L" , "=" , ANSWER ## _L , ">" , ANSWER ## _R , "=" , string{ #ANSWER } + "_R" , ":" , #ANSWER , ":=" , #MAXIMUM , "+ 1 =" , MAXIMUM + 1  ); \
      CERR( "二分探索マクロにミスがある可能性があります。変更前の版に戻してください。" ); \
      ANSWER = MAXIMUM + 1;						\
    } else {								\
      CERR( "二分探索終了:" , string{ #ANSWER } + "_L" , "=" , ANSWER ## _L , "<=" , #ANSWER , "=" , ANSWER , "<=" , ANSWER ## _R , "=" , string{ #ANSWER } + "_R" ); \
      CERR( "二分探索が成功したかを確認するために" , #EXPRESSION , "を計算します。" ); \
      CERR( "成功判定が不要な場合はこの計算を削除しても構いません。" );	\
      EXPRESSION_BS = ( EXPRESSION );					\
      CERR( "二分探索結果:" , #EXPRESSION , "=" , EXPRESSION_BS , ( EXPRESSION_BS > CONST_TARGET_BS ? ">" : EXPRESSION_BS < CONST_TARGET_BS ? "<" : "=" ) , CONST_TARGET_BS ); \
      if( EXPRESSION_BS DESIRED_INEQUALITY CONST_TARGET_BS ){		\
	CERR( "二分探索成功:" , #ANSWER , ":=" , ANSWER );		\
      } else {								\
	CERR( "二分探索失敗:" , #ANSWER , ":=" , #MAXIMUM , "+ 1 =" , MAXIMUM + 1 ); \
	CERR( "単調でないか、単調増加性と単調減少性を逆にしてしまったか、探索範囲内に解が存在しません。" ); \
	ANSWER = MAXIMUM + 1;						\
      }									\
    }									\
  }									\

/* 単調増加の時にEXPRESSION >= CONST_TARGETの最小解を格納。*/
#define BS1( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CONST_TARGET , >= , ANSWER , ANSWER + 1 , ( ANSWER ## _L + ANSWER ## _R ) / 2 )
/* 単調増加の時にEXPRESSION <= CONST_TARGETの最大解を格納。*/
#define BS2( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CONST_TARGET , > , ANSWER - 1 , ANSWER , ( ANSWER ## _L + 1 + ANSWER ## _R ) / 2 )
/* 単調減少の時にEXPRESSION >= CONST_TARGETの最大解を格納。*/
#define BS3( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CONST_TARGET , < , ANSWER - 1 , ANSWER , ( ANSWER ## _L + 1 + ANSWER ## _R ) / 2 )
/* 単調減少の時にEXPRESSION <= CONST_TARGETの最小解を格納。*/
#define BS4( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CONST_TARGET , <= , ANSWER , ANSWER + 1 , ( ANSWER ## _L + ANSWER ## _R ) / 2 )

#endif

