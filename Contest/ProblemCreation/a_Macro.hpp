// c:/Users/user/Documents/Programming/Contest/ProblemCreation/a_Macro.hpp

// 想定解用マクロのうち
// ifdef DEBUGのうち_GLIBCXX_DEBUGからDEXPRまでと
// ifndef DEBUGのうちASSERTからCOUT_ITRまで
// ifdef REACTIVE, ifndef USE_GETLINE
// を残し
// COUTからCERR_Aまで
// のundefを追加し
// ITRとFOR_ITR
// を削除し
// REPEAT_MAIN
// を変更する。

// テスト出力生成のために、CERR系は再定義しない。
#pragma once
#define _GLIBCXX_DEBUG
#define SIGNAL signal( SIGABRT , &AlertAbort );
#define DEXPR( LL , BOUND , VALUE1 , VALUE2 ) CEXPR( LL , BOUND , VALUE2 )
#define ASSERT( A , MIN , MAX ) assert( ( MIN ) <= A && A <= ( MAX ) )
#undef COUT
#undef COUTNS
#undef CERR
#undef CERRNS
#undef COUT_A
#undef CERR_A
#define COUT( ... ) VariadicCout( cout , __VA_ARGS__ ) << ENDL
#define CERR( ... ) 
#define COUTNS( ... ) VariadicCoutNonSep( cout , __VA_ARGS__ ) << flush
#define CERRNS( ... ) 
#define COUT_A( I , N , A ) CoutArray( cout , I , N , A ) << ENDL
#define CERR_A( I , N , A ) 
#define RSET( A , ... ) A = __VA_ARGS__
#define RCIN( LL , A , ... ) LL A; RSET( A , __VA_ARGS__ )
#define ENDL endl
#define SET_LL( A ) cin >> A
#define CIN( LL , ... ) LL __VA_ARGS__; VariadicCin( cin , __VA_ARGS__ )
#define SET_A( I , N , ... ) VariadicResize( N + I , __VA_ARGS__ ); FOR( VARIABLE_FOR_SET_A , 0 , N ){ VariadicSet( cin , VARIABLE_FOR_SET_A + I , __VA_ARGS__ ); }
#define CIN_A( LL , I , N , ... ) VE<LL> __VA_ARGS__; SET_A( I , N , __VA_ARGS__ )
#define CIN_AA( LL , I0 , N0 , I1 , N1 , VAR ) VE<VE<LL>> VAR( N0 + I0 ); FOR( VARIABLE_FOR_CIN_AA , 0 , N0 ){ SET_A( I1 , N1 , VAR[VARIABLE_FOR_CIN_AA + I0] ); }
#include <bits/stdc++.h>
using namespace std;
#define REPEAT_MAIN( BOUND ) void ExecuteSolution_Body(){ signal( SIGABRT , &AlertAbort ); CEXPR( int , bound_test_case_num , BOUND ); int test_case_num = 1; if constexpr( bound_test_case_num > 1 ){ CERR( "テストケースの個数を入力してください。" ); SET_ASSERT( test_case_num , 1 , bound_test_case_num ); } REPEAT( test_case_num ){ if constexpr( bound_test_case_num > 1 ){ CERR( "testcase " , VARIABLE_FOR_REPEAT_test_case_num , ":" ); } Solve(); } }
#define START_WATCH chrono::system_clock::time_point watch = chrono::system_clock::now()
#define CURRENT_TIME static_cast<double>( chrono::duration_cast<chrono::microseconds>( chrono::system_clock::now() - watch ).count() / 1000.0 )
#define CHECK_WATCH( TL_MS ) ( CURRENT_TIME < TL_MS - 100.0 )
#define TYPE_OF( VAR ) decay_t<decltype( VAR )>
#define CEXPR( LL , BOUND , VALUE ) constexpr LL BOUND = VALUE
#define SET_ASSERT( A , MIN , MAX ) SET_LL( A ); ASSERT( A , MIN , MAX )
#define SET_A_ASSERT( I , N , A , MIN , MAX ) FOR( VARIABLE_FOR_SET_A , 0 , N ){ SET_ASSERT( A[VARIABLE_FOR_SET_A + I] , MIN , MAX ); }
#define SET_AA_ASSERT( I0 , N0 , I1 , N1 , A , MIN , MAX ) FOR( VARIABLE_FOR_SET_AA0 , 0 , N0 ){ FOR( VARIABLE_FOR_SET_AA1 , 0 , N1 ){ SET_ASSERT( A[VARIABLE_FOR_SET_AA0 + I0][VARIABLE_FOR_SET_AA1 + I1] , MIN , MAX ); } }
#define CIN_ASSERT( A , MIN , MAX ) decldecay_t( MAX ) A; SET_ASSERT( A , MIN , MAX )
#define CIN_A_ASSERT( I , N , A , MIN , MAX ) vector<decldecay_t( MAX )> A( N + I ); SET_A_ASSERT( I , N , A , MIN , MAX )
#define CIN_AA_ASSERT( I0 , N0 , I1 , N1 , A , MIN , MAX ) vector A( N0 + I0 , vector<decldecay_t( MAX )>( N1 + I1 ) ); SET_AA_ASSERT( I0 , N0 , I1 , N1 , A , MIN , MAX )
#define OUTPUT_ARRAY( C , I , N , A ) FOR( VARIABLE_FOR_OUTPUT_ARRAY , I , N ){ C << A[VARIABLE_FOR_OUTPUT_ARRAY] << " \n"[VARIABLE_FOR_OUTPUT_ARRAY==(N)-1]; }
#define FOR( VAR , INITIAL , FINAL_PLUS_ONE ) for( decldecay_t( FINAL_PLUS_ONE ) VAR = INITIAL ; VAR < FINAL_PLUS_ONE ; VAR ++ )
#define FOREQ( VAR , INITIAL , FINAL ) for( decldecay_t( FINAL ) VAR = INITIAL ; VAR <= FINAL ; VAR ++ )
#define FOREQINV( VAR , INITIAL , FINAL ) for( decldecay_t( INITIAL ) VAR = INITIAL ; VAR + 1 > FINAL ; VAR -- )
// #define ITR( ARRAY ) auto begin_ ## ARRAY = ARRAY .BE() , itr_ ## ARRAY = begin_ ## ARRAY , end_ ## ARRAY = ARRAY .EN()
// #define FOR_ITR( ARRAY ) for( ITR( ARRAY ) , itr = itr_ ## ARRAY ; itr_ ## ARRAY != end_ ## ARRAY ; itr_ ## ARRAY ++ , itr++ )
#define RUN( ARRAY , ... ) for( auto&& __VA_ARGS__ : ARRAY )
#define REPEAT( HOW_MANY_TIMES ) FOR( VARIABLE_FOR_REPEAT_ ## HOW_MANY_TIMES , 0 , HOW_MANY_TIMES )
#define SET_PRECISION( DECIMAL_DIGITS ) cout << fixed << setprecision( DECIMAL_DIGITS ); cerr << fixed << setprecision( DECIMAL_DIGITS )
#define RETURN( ... ) COUT( __VA_ARGS__ ); return

// 型のエイリアス
#define decldecay_t( VAR ) decay_t<decltype( VAR )>
template <typename F , typename...Args> using ret_t = decltype( declval<F>()( declval<Args>()... ) );
template <typename T> using inner_t = typename T::type;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using lld = __float128;
template <typename INT> using T2 = pair<INT,INT>;
template <typename INT> using T3 = tuple<INT,INT,INT>;
template <typename INT> using T4 = tuple<INT,INT,INT,INT>;
using path = pair<int,ll>;

// 圧縮用
#define TE template
#define TY typename
#define US using
#define ST static
#define AS assert
#define IN inline
#define CL class
#define PU public
#define OP operator
#define CE constexpr
#define CO const
#define NE noexcept
#define RE return 
#define WH while
#define VO void
#define VE vector
#define LI list
#define BE begin
#define EN end
#define SZ size
#define LE length
#define PW Power
#define MO move
#define TH this
#define CRI CO int&
#define CRUI CO uint&
#define CRL CO ll&
#define VI virtual 
#define ST_AS static_assert
#define reMO_CO remove_const
#define is_COructible_v is_constructible_v
#define rBE rbegin
#define reSZ resize

#define OFS( ... ) VariadicCout( ofs_input_list , __VA_ARGS__ ) << endl
#define OFSNS( ... ) VariadicCoutNonSep( ofs_input_list , __VA_ARGS__ ) << endl
#define OFS_A( I , N , A ) CoutArray( ofs_input_list , I , N , A ) << endl

#define IFS( LL , ... ) LL __VA_ARGS__; VariadicCin( ifs_input_list , __VA_ARGS__ )
#define IFS_A( LL , I , N , A ) VE<LL> A( N + I ); FOR( VARIABLE_FOR_IFS_A , 0 , N ){ ifs_input_list >> A[VARIABLE_FOR_IFS_A + I]; }
