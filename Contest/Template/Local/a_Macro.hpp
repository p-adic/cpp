// c:/Users/user/Documents/Programming/Contest/Template/Local/a_Macro.hpp

#pragma once

// 提出時: CIN -> cin, COUT -> cout, CERR -> 出力なし, DERR -> 不使用
// サンプル確認時: CIN -> ifs, COUT -> ofs, CERR -> cerr, DERR -> ofs_err
// デバッグ出力時: CIN -> cin, COUT -> cout, CERR -> cerr, DERR -> cerr
// 非デバッグ出力時: CIN -> cin, COUT -> cout, CERR -> cerr, DERR -> 出力なし
#ifdef DEBUG_OUTPUT
  #define COUT_TARGET cout << "出力 " << __LINE__ << ": "
  #define DERR2( ... ) VariadicCout( cerr , __VA_ARGS__ ) << endl
  #define DERRNS2( ... ) VariadicCoutNonSep( cerr , __VA_ARGS__ ) << flush
  #define DERR_A2 CoutArray( cerr , I , N , A ) << flush
#else
  #define COUT_TARGET cout
  #define DERR2( ... )
  #define DERRNS2( ... )
  #define DERR_A2
#endif

#ifdef SAMPLE_CHECK
  #define DERR1( ... ) VariadicCout( ofs_err , __VA_ARGS__ ) << endl
  #define DERRNS1( ... ) VariadicCoutNonSep( ofs_err , __VA_ARGS__ ) << flush
  #define DERR_A1 CoutArray( ofs_err , I , N , A ) << flush
#else
  #define DERR1( ... )
  #define DERRNS1( ... )
  #define DERR_A1
#endif

#define COUT( ... ) if( exec_mode == sample_check_mode ){ VariadicCout( ofs , __VA_ARGS__ ) << endl; } else { VariadicCout( COUT_TARGET , __VA_ARGS__ ) << endl; }
#define COUTNS( ... ) if( exec_mode == sample_check_mode ){ VariadicCoutNonSep( ofs , __VA_ARGS__ ) << flush; } else { VariadicCoutNonSep( COUT_TARGET , __VA_ARGS__ ) << flush; }
#define COUT_A( I , N , A ) if( exec_mode == sample_check_mode ){ CoutArray( ofs , I , N , A ) << endl; } else { CoutArray( COUT_TARGET , I , N , A ) << endl; }
#define CERR( ... ) VariadicCout( cerr , __VA_ARGS__ ) << endl
#define CERRNS( ... ) VariadicCoutNonSep( cerr , __VA_ARGS__ ) << flush
#define CERR_A( I , N , A ) CoutArray( cerr , I , N , A ) << endl
#define DERR( ... ) if( exec_mode == sample_check_mode ){ DERR1( __VA_ARGS__ ); } else { DERR2( __VA_ARGS__ ); }
#define DERRNS( ... ) if( exec_mode == sample_check_mode ){ DERRNS1( __VA_ARGS__ ); } else { DERRNS2( __VA_ARGS__ ); }
#define DERR_A( I , N , A ) if( exec_mode == sample_check_mode ){ DERR_A1; } else { DERR_A2; }

#define REPEAT_MAIN( BOUND )                                    \
  START_MAIN;                                                   \
    signal( SIGABRT , &AlertAbort );                              \
    if constexpr( !submit_only ){                                 \
      AutoCheck( use_getline , sample_check , problem_order );    \
    }                                                             \
    CEXPR( int , test_case_num_bound , BOUND );                   \
    if( exec_mode != solve_mode ){                                \
      if( exec_mode == sample_check_mode ){                         \
        SampleCheck( sample_path , input_path , output_path , problem_order , test_case_num_bound , ifs , ofs ); \
      } else if( exec_mode == experiment_mode ){                  \
        Experiment();                                             \
      } else if( exec_mode == small_test_mode ){                  \
        SmallTest();                                              \
      } else if( exec_mode == random_test_mode ){                 \
        CERR( "ランダムテストを行う回数を指定してください。" );          \
        CIN( int , test_case_num );                                     \
        RandomTest( test_case_num );                              \
      }                                                           \
      RE 0;                                                       \
    }                                                             \
  FINISH_MAIN                                                   \


#define FINISH_MAIN                                                    \
    if constexpr( test_case_num_bound > 1 ){             \
      CERR( "テストケースの個数を入力してください。" );               \
      CIN_ASSERT( test_case_num , 1 , test_case_num_bound );          \
      REPEAT( test_case_num ){                                        \
        CERR( "testcase" , VARIABLE_FOR_REPEAT_test_case_num , ":" ); \
        Solve();                                                      \
        CERR( "" );                                                   \
      }                                                               \
    } else {                                              \
      Solve();                                                        \
      CERR( "" );                                                     \
    }                                                                 \
  }                                                                 \

#define DEXPR( LL , BOUND , VALUE1 , VALUE2 ) CEXPR( LL , BOUND , VALUE2 )

#define ASSERT( A , MIN , MAX )                                         \
  DERR( "ASSERTチェック:" , ( MIN ) , ( ( MIN ) <= A ? "<=" : ">" ) , A , ( A <= ( MAX ) ? "<=" : ">" ) , ( MAX ) ); \
  assert( ( MIN ) <= A && A <= ( MAX ) )                                    \

#ifdef USE_GETLINE
  #define SET_SEPARATE( SEPARATOR , ... ) if( exec_mode == sample_check_mode ){ VariadicGetline( ifs , SEPARATOR , __VA_ARGS__ ); } else { VariadicGetline( cin , SEPARATOR , __VA_ARGS__ ); }
  #define SET( ... ) SET_SEPARATE( '\n' , __VA_ARGS__ )
  #define GETLINE_SEPARATE( SEPARATOR , ... ) string __VA_ARGS__; SET_SEPARATE( SEPARATOR , __VA_ARGS__ )
  #define GETLINE( ... ) GETLINE_SEPARATE( '\n' , __VA_ARGS__ )
#else
  #define SET( ... ) if( exec_mode == sample_check_mode ){ VariadicCin( ifs , __VA_ARGS__ ); } else { VariadicCin( cin , __VA_ARGS__ ); }
  #define CIN( LL , ... ) LL __VA_ARGS__; SET( __VA_ARGS__ )
  #define SET_A( I , N , ... ) VariadicResize( N + I , __VA_ARGS__ ); FOR( VARIABLE_FOR_SET_A , 0 , N ){ if( exec_mode == sample_check_mode ){ VariadicSet( ifs , VARIABLE_FOR_SET_A + I , __VA_ARGS__ ); } else { VariadicSet( cin , VARIABLE_FOR_SET_A + I , __VA_ARGS__ ); } }
  #define CIN_A( LL , I , N , ... ) VE<LL> __VA_ARGS__; SET_A( I , N , __VA_ARGS__ )
  #define CIN_AA( LL , I0 , N0 , I1 , N1 , VAR ) VE<VE<LL>> VAR( N0 + I0 ); FOR( VARIABLE_FOR_CIN_AA , 0 , N0 ){ SET_A( I1 , N1 , VAR[VARIABLE_FOR_CIN_AA + I0] ); }
#endif

#define SET_ASSERT( A , MIN , MAX )                     \
  if( exec_mode == solve_mode ){                        \
    SET( A );                                           \
    ASSERT( A , MIN , MAX );                            \
  } else if( exec_mode == random_test_mode ){           \
    A = GetRand( MIN , MAX );                           \
    DERR( #A , " = " , A );                             \
  } else { AS( false ); }                               \

#define SOLVE_ONLY static_assert( __FUNCTION__[0] == 'S' )
