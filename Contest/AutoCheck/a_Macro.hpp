// c:/Users/user/Documents/Programming/Contest/AutoCheck/a_Macro.hpp

#pragma once

#define CERR( MESSAGE ) cerr << MESSAGE << endl;

#define ASK_NUMBER( ... )						\
  CERR( "" );								\
  CERR( "何番を選択しますか？" );					\
  problems = { __VA_ARGS__ };						\
  problems_size = problems.size();					\
  for( int i = 0 ; i < problems_size ; i++ ){				\
    CERR( i << ": " << problems[i] );					\
  }									\
  cin >> num;								\
  CERR( "" );								\
  if( num < 0 || num >= problems_size ){				\
    CERR( "返答は" << problems_size - 1 << "以下の非負整数にしてください。" ); \
    CERR( "終了します。" );						\
    CERR( "" );								\
    return;								\
  }									\
  num_temp = 0;								\
  
#define ASK_YES_NO( QUESTION )			\
  CERR( "" );					\
  CERR( QUESTION  << "[y/n]" );			\
  cin >> reply;					\
  if( reply != "y" && reply != "n" ){		\
    CERR( "y/nのいずれかで答えてください。" );	\
    CERR( "終了します。" );			\
    CERR( "" );					\
    return;					\
  }						\
  CERR( "" );					\

#define AC( BRANCH ) void BRANCH ## AutoCheck( int& num , int& num_temp , string& reply , vector<string>& problems , int& problems_size )
#define CALL_AC( BRANCH ) BRANCH ## AutoCheck( num , num_temp , reply , problems , problems_size )

