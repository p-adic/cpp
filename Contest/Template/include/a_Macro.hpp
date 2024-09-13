// c:/Users/user/Documents/Programming/Contest/Template/include/a_Macro.hpp

#pragma once


#ifdef SAMPLE_CHECK
  #define INPUT ifs
  #define DEBUG_OUTPUT ofs_err
  #define COUT( ... ) VariadicCout( ofs , __VA_ARGS__ ) << endl
  #define COUTNS( ... ) VariadicCoutNonSep( ofs , __VA_ARGS__ ) << flush
  #define COUT_A( I , N , A ) CoutArray( ofs , I , N , A ) << endl
#else
  #define INPUT cin
  #define DEBUG_OUTPUT cerr
  #define COUT( ... ) VariadicCout( cout << "出力" << __LINE__ << "：" , __VA_ARGS__ ) << endl
  #define COUTNS( ... ) VariadicCoutNonSep( cout << "出力" << __LINE__ << "： " , __VA_ARGS__ ) << flush
  #define COUT_A( I , N , A ) CoutArray( cout << "出力： " , I , N , A ) << endl
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
        SET_LL( test_case_num );                                  \
        RandomTest( test_case_num );                              \
      }                                                           \
      RE 0;                                                       \
    }                                                             \
    CEXPR( int , bound_test_case_num , BOUND );                   \
  FINISH_MAIN                                                   \


#ifdef SAMPLE_CHECK

  #define FINISH_MAIN                                                     \
      int sample_repetition_num; sample_count >> sample_repetition_num;       \
      REPEAT( sample_repetition_num ){                                           \
        sample_count >> sample_num;                                    \
        ofs_err << "サンプル" << sample_num << "を実行します。" << endl; \
        ofs_err << endl;                                                \
        ifs = ifstream{ input_path + sample_num + ".txt" };            \
        ofs = ofstream{ output_path + sample_num + ".txt" , ios::trunc }; \
        if constexpr( bound_test_case_num > 1 ){             \
          SET_ASSERT( test_case_num , 1 , bound_test_case_num );          \
        }                                                             \
        REPEAT( test_case_num ){                                           \
          Solve();                                                         \
        }                                                               \
        CompareAnswer( sample_path , problem_order , sample_num );    \
        ofs_err << "サンプル" << sample_num << "の実行を終了しました。" << endl; \
        ofs_err << endl;                                                \
      }                                                                 \
    }                                                                 \

#else

  #define FINISH_MAIN                                                    \
      if constexpr( bound_test_case_num > 1 ){             \
        CERR( "テストケースの個数を入力してください。" );               \
        SET_ASSERT( test_case_num , 1 , bound_test_case_num );    \
        REPEAT( test_case_num ){                                                \
          CERR( "testcase " , VARIABLE_FOR_REPEAT_test_case_num , ":" ); \
          Solve();                                                         \
          CERR( "" );                                                      \
        }                                                                  \
      } else {                                              \
        Solve();                                                         \
        CERR( "" );                                                      \
      }                                                                  \
    }                                                                    \

#endif

#define DEXPR( LL , BOUND , VALUE1 , VALUE2 ) CEXPR( LL , BOUND , VALUE2 )

#define ASSERT( A , MIN , MAX )                                         \
  CERR( "ASSERTチェック： " , ( MIN ) , ( ( MIN ) <= A ? "<=" : ">" ) , A , ( A <= ( MAX ) ? "<=" : ">" ) , ( MAX ) ); \
  AS( ( MIN ) <= A && A <= ( MAX ) )                                    \

#ifdef USE_GETLINE
  #define GETLINE_SEPARATE( SEPARATOR , ... ) string __VA_ARGS__; VariadicGetline( INPUT , SEPARATOR , __VA_ARGS__ )
  #define GETLINE( ... ) GETLINE_SEPARATE( '\n' , __VA_ARGS__ )
  #define SET_LL( A ) { GETLINE( A ## _str ); A = stoll( A ## _str ); }
#else
  #define CIN( LL , ... ) LL __VA_ARGS__; VariadicCin( INPUT , __VA_ARGS__ )
  #define SET_A( I , N , ... ) VariadicResize( N + I , __VA_ARGS__ ); FOR( VARIABLE_FOR_SET_A , 0 , N ){ VariadicSet( INPUT , VARIABLE_FOR_SET_A + I , __VA_ARGS__ ); }
  #define CIN_A( LL , I , N , ... ) VE<LL> __VA_ARGS__; SET_A( I , N , __VA_ARGS__ )
  #define CIN_AA( LL , I0 , N0 , I1 , N1 , VAR ) VE<VE<LL>> VAR( N0 + I0 ); FOR( VARIABLE_FOR_CIN_AA , 0 , N0 ){ SET_A( I1 , N1 , VAR[VARIABLE_FOR_CIN_AA + I0] ); }
  #define SET_LL( A ) INPUT >> A
#endif

#define CERR( ... ) VariadicCout( cerr , __VA_ARGS__ ) << endl
#define CERRNS( ... ) VariadicCoutNonSep( cerr , __VA_ARGS__ ) << flush
#define CERR_A( I , N , A ) CoutArray( cerr , I , N , A ) << endl

#define SET_ASSERT( A , MIN , MAX )                     \
  if( exec_mode == solve_mode ){                        \
    SET_LL( A );                                        \
    ASSERT( A , MIN , MAX );                            \
  } else if( exec_mode == random_test_mode ){           \
    CERR( #A , " = " , ( A = GetRand( MIN , MAX ) ) );  \
  } else { AS( false ); }                               \

#define SOLVE_ONLY ST_AS( __FUNCTION__[0] == 'S' )
