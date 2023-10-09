// c:/Users/user/Documents/Programming/Error/BreakPoint/a_Macro.hpp

#pragma once
#include "../Position/a_Macro.hpp"

#ifdef DEBUG

  #define COUNT_BODY( ... ) CountCall( __VA_ARGS__ ) 
  #define FLAG_BODY( ... ) CallFlagContainer( false , __VA_ARGS__  ) 
  #define BREAK( ... ) BreakPoint( POSITION , __VA_ARGS__ ) 
  #define BREAK_IF( CONDITION , ... ) if( CONDITION ){ BREAK( __VA_ARGS__ ); } 
 
#endif

#define COUNT( index , i0 , i1 ) CONNECT( COUNT , index )( i0 , i1 ) 
#define COUNT0( i0 , i1 ) COUNT_BODY( POSITION , i0 , i1 ) 
#define COUNT1( i0 , i1 ) COUNT_BODY( POSITION , i0 , i1 , 0 , 0 ) 
#define COUNT2( i0 , i1 ) COUNT_BODY( POSITION , i0 , i1 , 0 , 0 , 0 , 0 ) 
#define COUNT3( i0 , i1 ) COUNT_BODY( POSITION , i0 , i1 , 0 , 0 , 0 , 0 , 0 , 0 ) 
#define COUNT4( i0 , i1 ) COUNT_BODY( POSITION , i0 , i1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) 
#define COUNT5( i0 , i1 ) COUNT_BODY( POSITION , i0 , i1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) 
#define COUNT6( i0 , i1 ) COUNT_BODY( POSITION , i0 , i1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) 

#define FLAG( index , i0 , i1 ) CONNECT( FLAG , index )( i0 , i1 ) 
#define FLAG0( i0 , i1 ) FLAG_BODY( i0 , i1 ) 
#define FLAG1( i0 , i1 ) FLAG_BODY( i0 , i1 , 0 , 0 ) 
#define FLAG2( i0 , i1 ) FLAG_BODY( i0 , i1 , 0 , 0 , 0 , 0 ) 
#define FLAG3( i0 , i1 ) FLAG_BODY( i0 , i1 , 0 , 0 , 0 , 0 , 0 , 0 ) 
#define FLAG4( i0 , i1 ) FLAG_BODY( i0 , i1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) 
#define FLAG5( i0 , i1 ) FLAG_BODY( i0 , i1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) 

// 1重のブレークポイントだけを使いたい時はBREAKまたはCOUNT(0,-,-)を用いる。
// index+1重のブレークポイントだけを使いたい時はFLAG(0,-,-),…,FLAG(index,-,-)とCOUNT(index+1,-,-)を用いる。

// FLAG(0,-,-)を通るたびに第0カウントを1回行う。
// FLAG(index+1,-,-)を通るたび、FLAG(index,-,-)のフラグがtrueであれば第index+1カウントを1回行う。
// FLAG(index,i0,i1)はi0回目の第indexカウントからi1回の第indexカウントごとにフラグがtrueとなり、それ以外の時はフラグがfalseとなる。
// COUNT(0,-,-)を通るたびに第0カウントを行う。
// COUNT(index+1,-,-)を通るたび、FLAG(index,-,-)のフラグがtrueであれば第index+1カウントを行う。
// COUNT(index,i0,i1)はi0回目の第indexカウントからi1回の第indexカウントごとにBreakPoint()を呼び出す。
