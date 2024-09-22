// c:/Users/user/Documents/Programming/Contest/Template/include/a_Macro.hpp

#pragma once

// 提出時: INPUT_SOURCE -> 不使用, COUT -> cout, CERR -> 出力なし, DERR -> 不使用
// サンプル確認時: INPUT_SOURCE -> ifs, COUT -> ofs, CERR -> cerr, DERR -> ofs_err
// デバッグ出力時: INPUT_SOURCE -> cin, COUT -> cout, CERR -> cerr, DERR -> cerr
// 非デバッグ出力時: INPUT_SOURCE -> cin, COUT -> cout, CERR -> cerr, DERR -> 出力なし
#ifdef SAMPLE_CHECK
  #define INPUT_SOURCE ifs
  #define COUT_TARGET ofs
  #define DERR_TARGET ofs_err
#elif defined( DEBUG_OUTPUT )
  #define INPUT_SOURCE cin
  #define COUT_TARGET cout
  #define DERR_TARGET cerr
#else
  #define INPUT_SOURCE cin
  #define COUT_TARGET cout
#endif

#define COUT( ... ) VariadicCout( COUT_TARGET , __VA_ARGS__ ) << endl
#define COUTNS( ... ) VariadicCoutNonSep( COUT_TARGET , __VA_ARGS__ ) << flush
#define COUT_A( I , N , A ) CoutArray( COUT_TARGET , I , N , A ) << endl
#define CERR( ... ) VariadicCout( cerr , __VA_ARGS__ ) << endl
#define CERRNS( ... ) VariadicCoutNonSep( cerr , __VA_ARGS__ ) << flush
#define CERR_A( I , N , A ) CoutArray( cerr , I , N , A ) << endl

#ifdef DERR_TARGET
  #define DERR( ... ) VariadicCout( DERR_TARGET , __VA_ARGS__ ) << endl
  #define DERRNS( ... ) VariadicCoutNonSep( DERR_TARGET , __VA_ARGS__ ) << flush
  #define DERR_A( I , N , A ) CoutArray( DERR_TARGET , I , N , A ) << flush
#else
  #define DERR( ... ) 
  #define DERRNS( ... ) 
  #define DERR_A( I , N , A ) 
#endif

#define REPEAT_MAIN( BOUND )                                    \
  START_MAIN;                                                   \
    signal( SIGABRT , &AlertAbort );                              \
    if constexpr( !submit_only ){                                 \
      if( problem_order != "dummy" ){                            \
        CERR( "" );                                               \
        CERR( "提出用ファイル実行時は" + problem_order + "問題のサンプルを確認します。" ); \
      }                                                           \
      AutoCheck( exec_mode , use_getline );                       \
    }                                                             \
    int test_case_num = 1;                                        \
    if( exec_mode != solve_mode ){                                \
      if( exec_mode == experiment_mode ){                         \
        Experiment();                                             \
      } else if( exec_mode == small_test_mode ){                  \
        SmallTest();                                              \
      } else if( exec_mode == random_test_mode ){                 \
        CERR( "ランダムテストを行う回数を指定してください。" );          \
        cin >> test_case_num;                                         \
        RandomTest( test_case_num );                              \
      }                                                           \
      RE 0;                                                       \
    }                                                             \
    CEXPR( int , bound_test_case_num , BOUND );                   \
  FINISH_MAIN                                                   \


#ifdef SAMPLE_CHECK

  #define FINISH_MAIN                                                     \
      int sample_repetition_num; sample_count >> sample_repetition_num;       \
      REPEAT( sample_repetition_num ){                                  \
        sample_count >> sample_num;                                     \
        CERRNS( "サンプル" , stoi( sample_num ) , "を実行します。\n" ); \
        CERR( "" );                                                     \
        ifs = ifstream{ input_path + sample_num + ".txt" };             \
        ofs = ofstream{ output_path + sample_num + ".txt" , ios::trunc }; \
        if constexpr( bound_test_case_num > 1 ){                        \
          SET_ASSERT( test_case_num , 1 , bound_test_case_num );      \
        }                                                             \
        REPEAT( test_case_num ){                                        \
          Solve();                                                      \
        }                                                               \
        CompareAnswer( sample_path , problem_order , sample_num );      \
        CERRNS( "サンプル" , stoi( sample_num ) , "の実行を終了しました。\n" ); \
        CERR( "" );                                                     \
      }                                                                 \
    }                                                                 \

#else

  #define FINISH_MAIN                                                    \
      if constexpr( bound_test_case_num > 1 ){             \
        CERR( "テストケースの個数を入力してください。" );               \
        SET_ASSERT( test_case_num , 1 , bound_test_case_num );          \
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

#endif

#define DEXPR( LL , BOUND , VALUE1 , VALUE2 ) CEXPR( LL , BOUND , VALUE2 )

#define ASSERT( A , MIN , MAX )                                         \
  DERR( "ASSERTチェック:" , ( MIN ) , ( ( MIN ) <= A ? "<=" : ">" ) , A , ( A <= ( MAX ) ? "<=" : ">" ) , ( MAX ) ); \
  assert( ( MIN ) <= A && A <= ( MAX ) )                                    \

#ifdef USE_GETLINE
  #define GETLINE_SEPARATE( SEPARATOR , ... ) string __VA_ARGS__; VariadicGetline( INPUT_SOURCE , SEPARATOR , __VA_ARGS__ )
  #define GETLINE( ... ) GETLINE_SEPARATE( '\n' , __VA_ARGS__ )
  #define SET_LL( A ) { GETLINE( A ## _str ); A = stoll( A ## _str ); }
#else
  #define CIN( LL , ... ) LL __VA_ARGS__; VariadicCin( INPUT_SOURCE , __VA_ARGS__ )
  #define SET_A( I , N , ... ) VariadicResize( N + I , __VA_ARGS__ ); FOR( VARIABLE_FOR_SET_A , 0 , N ){ VariadicSet( INPUT_SOURCE , VARIABLE_FOR_SET_A + I , __VA_ARGS__ ); }
  #define CIN_A( LL , I , N , ... ) VE<LL> __VA_ARGS__; SET_A( I , N , __VA_ARGS__ )
  #define CIN_AA( LL , I0 , N0 , I1 , N1 , VAR ) VE<VE<LL>> VAR( N0 + I0 ); FOR( VARIABLE_FOR_CIN_AA , 0 , N0 ){ SET_A( I1 , N1 , VAR[VARIABLE_FOR_CIN_AA + I0] ); }
  #define SET_LL( A ) INPUT_SOURCE >> A
#endif

#define SET_ASSERT( A , MIN , MAX )                     \
  if( exec_mode == solve_mode ){                        \
    SET_LL( A );                                        \
    ASSERT( A , MIN , MAX );                            \
  } else if( exec_mode == random_test_mode ){           \
    A = GetRand( MIN , MAX );                           \
    DERR( #A , " = " , A );                             \
  } else { AS( false ); }                               \

#define SOLVE_ONLY static_assert( __FUNCTION__[0] == 'S' )
