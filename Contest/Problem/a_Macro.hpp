// c:/Users/user/Documents/Programming/Contest/Problem/a_Macro.hpp

// 想定解用マクロのうち
// ifdef DEBUG, ifdef REACTIVE, ifndef USE_GETLINE
// を残し
// REPEAT_MAIN
// を変更する。
#pragma once
#define _GLIBCXX_DEBUG
#define SIGNAL signal( SIGABRT , &AlertAbort );
#define DEXPR( LL , BOUND , VALUE , DEBUG_VALUE ) CEXPR( LL , BOUND , DEBUG_VALUE )
#define ASSERT( A , MIN , MAX ) CERR( "ASSERTチェック： " , ( MIN ) , ( ( MIN ) <= A ? "<=" : ">" ) , A , ( A <= ( MAX ) ? "<=" : ">" ) , ( MAX ) ); assert( ( MIN ) <= A && A <= ( MAX ) )
#define CERR( ... ) VariadicCout( cerr , __VA_ARGS__ ) << endl
#define COUT( ... ) VariadicCout( cout << "出力： " , __VA_ARGS__ ) << endl
#define CERR_A( A , N ) OUTPUT_ARRAY( cerr , A , N ) << endl
#define COUT_A( A , N ) cout << "出力： "; OUTPUT_ARRAY( cout , A , N ) << endl
#define CERR_ITR( A ) OUTPUT_ITR( cerr , A ) << endl
#define COUT_ITR( A ) cout << "出力： "; OUTPUT_ITR( cout , A ) << endl
#define ENDL endl
#define SET_LL( A ) cin >> A
#define CIN( LL , ... ) LL __VA_ARGS__; VariadicCin( cin , __VA_ARGS__ )
#define SET_A( A , N ) FOR( VARIABLE_FOR_CIN_A , 0 , N ){ cin >> A[VARIABLE_FOR_CIN_A]; }
#define CIN_A( LL , A , N ) vector<LL> A( N ); SET_A( A , N );
#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using lld = __float128;
using lld = __float128;
template <typename INT> using T2 = pair<INT,INT>;
template <typename INT> using T3 = tuple<INT,INT,INT>;
template <typename INT> using T4 = tuple<INT,INT,INT,INT>;
using path = pair<int,ll>;
#define REPEAT_MAIN( BOUND ) void ExecuteSolution_Body(){ signal( SIGABRT , &AlertAbort ); CEXPR( int , bound_test_case_num , BOUND ); int test_case_num = 1; if constexpr( bound_test_case_num > 1 ){ SET_ASSERT( test_case_num , 1 , bound_test_case_num ); } REPEAT( test_case_num ){ if constexpr( bound_test_case_num > 1 ){ CERR( "testcase " , VARIABLE_FOR_REPEAT_test_case_num , ":" ); } Solve(); } }
#define START_WATCH chrono::system_clock::time_point watch = chrono::system_clock::now()
#define CURRENT_TIME static_cast<double>( chrono::duration_cast<chrono::microseconds>( chrono::system_clock::now() - watch ).count() / 1000.0 )
#define CHECK_WATCH( TL_MS ) ( CURRENT_TIME < TL_MS - 100.0 )
#define TYPE_OF( VAR ) decay_t<decltype( VAR )>
#define CEXPR( LL , BOUND , VALUE ) constexpr LL BOUND = VALUE
#define SET_ASSERT( A , MIN , MAX ) SET_LL( A ); ASSERT( A , MIN , MAX )
#define CIN_ASSERT( A , MIN , MAX ) TYPE_OF( MAX ) A; SET_ASSERT( A , MIN , MAX )
#define FOR( VAR , INITIAL , FINAL_PLUS_ONE ) for( TYPE_OF( FINAL_PLUS_ONE ) VAR = INITIAL ; VAR < FINAL_PLUS_ONE ; VAR ++ )
#define FOREQ( VAR , INITIAL , FINAL ) for( TYPE_OF( FINAL ) VAR = INITIAL ; VAR <= FINAL ; VAR ++ )
#define FOREQINV( VAR , INITIAL , FINAL ) for( TYPE_OF( INITIAL ) VAR = INITIAL ; VAR + 1 > FINAL ; VAR -- )
#define AUTO_ITR( ARRAY ) auto itr_ ## ARRAY = ARRAY .begin() , end_ ## ARRAY = ARRAY .end()
#define FOR_ITR( ARRAY ) for( AUTO_ITR( ARRAY ) , itr = itr_ ## ARRAY ; itr_ ## ARRAY != end_ ## ARRAY ; itr_ ## ARRAY ++ , itr++ )
#define REPEAT( HOW_MANY_TIMES ) FOR( VARIABLE_FOR_REPEAT_ ## HOW_MANY_TIMES , 0 , HOW_MANY_TIMES )
#define SET_PRECISION( DECIMAL_DIGITS ) cout << fixed << setprecision( DECIMAL_DIGITS )
#define OUTPUT_ARRAY( OS , A , N ) FOR( VARIABLE_FOR_OUTPUT_ARRAY , 0 , N ){ OS << A[VARIABLE_FOR_OUTPUT_ARRAY] << (VARIABLE_FOR_OUTPUT_ARRAY==N-1?"":" "); } OS
#define OUTPUT_ITR( OS , A ) { auto ITERATOR_FOR_OUTPUT_ITR = A.begin() , END_FOR_OUTPUT_ITR = A.end(); bool VARIABLE_FOR_OUTPUT_ITR = ITERATOR_FOR_COUT_ITR != END_FOR_COUT_ITR; while( VARIABLE_FOR_OUTPUT_ITR ){ OS << *ITERATOR_FOR_COUT_ITR; ( VARIABLE_FOR_OUTPUT_ITR = ++ITERATOR_FOR_COUT_ITR != END_FOR_COUT_ITR ) ? OS : OS << " "; } } OS
#define RETURN( ... ) COUT( __VA_ARGS__ ); return

// 圧縮用
#define TE template
#define TY typename
#define US using
#define ST static
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
#define MO move
#define TH this
#define CRI CO int&
#define CRUI CO uint&
#define CRL CO ll&

#define OFS( ... ) VariadicCout( ofs_input_list , __VA_ARGS__ ) << endl
#define OFS_A( A , N ) OUTPUT_ARRAY( ofs_input_list , A , N ) << endl
#define OFS_ITR( A ) OUTPUT_ITR( ofs_input_list , A ) << endl

#define IFS( LL , ... ) LL __VA_ARGS__; VariadicCin( ifs_input_list , __VA_ARGS__ )
#define IFS_A( LL , A , N ) LL A[N]; FOR( VARIABLE_FOR_IFS_A , 0 , N ){ ifs_input_list >> A[VARIABLE_FOR_CIN_A]; }
