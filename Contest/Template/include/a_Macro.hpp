// c:/Users/user/Documents/Programming/Contest/Template/include/a_Macro.hpp

#pragma once

#define _GLIBCXX_DEBUG
#define REPEAT_MAIN( BOUND ) START_MAIN; signal( SIGABRT , &AlertAbort ); AutoCheck( exec_mode , use_getline ); CEXPR( int , bound_test_case_num , BOUND ); int test_case_num = 1; if( exec_mode == solve_mode ){ if CE( bound_test_case_num > 1 ){ CERR( "テストケースの個数を入力してください。" ); SET_ASSERT( test_case_num , 1 , bound_test_case_num ); } } else { if( exec_mode == experiment_mode ){ Experiment(); } else if( exec_mode == small_test_mode ){ SmallTest(); } else if( exec_mode == random_test_mode ){ CERR( "ランダムテストを行う回数を指定してください。" ); SET_LL( test_case_num ); RandomTest( test_case_num ); } RE 0; } FINISH_MAIN
#define DEXPR( LL , BOUND , VALUE1 , VALUE2 ) CEXPR( LL , BOUND , VALUE2 )
#define ASSERT( A , MIN , MAX ) CERR( "ASSERTチェック： " , ( MIN ) , ( ( MIN ) <= A ? "<=" : ">" ) , A , ( A <= ( MAX ) ? "<=" : ">" ) , ( MAX ) ); AS( ( MIN ) <= A && A <= ( MAX ) )
#define SET_ASSERT( A , MIN , MAX ) if( exec_mode == solve_mode ){ SET_LL( A ); ASSERT( A , MIN , MAX ); } else if( exec_mode == random_test_mode ){ CERR( #A , " = " , ( A = GetRand( MIN , MAX ) ) ); } else { AS( false ); }
#define SOLVE_ONLY ST_AS( __FUNCTION__[0] == 'S' )
#define CERR( ... ) VariadicCout( cerr , __VA_ARGS__ ) << endl
#define COUT( ... ) VariadicCout( cout << "出力： " , __VA_ARGS__ ) << endl
#define CERR_A( I , N , A ) CoutArray( cerr , I , N , A ) << endl
#define COUT_A( I , N , A ) CoutArray( cout << "出力： " , I , N , A ) << endl
