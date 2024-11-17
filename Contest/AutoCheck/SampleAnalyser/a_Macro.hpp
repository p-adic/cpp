// c:/Users/user/Documents/Programming/Contest/AutoCheck/SampleAnalyser/a_Macro.hpp

#pragma once

#pragma GCC optimize ( "O3" )
#pragma GCC optimize ( "unroll-loops" )
#pragma GCC target ( "sse4.2,fma,avx2,popcnt,lzcnt,bmi2" )

#define SET( ... ) VariadicCin( cin , __VA_ARGS__ )
#define CIN( LL , ... ) LL __VA_ARGS__; SET( __VA_ARGS__ )
#define SET_A( I , N , ... ) VariadicResize( N + I , __VA_ARGS__ ); FOR( VARIABLE_FOR_SET_A , 0 , N ){ VariadicSet( cin , VARIABLE_FOR_SET_A + I , __VA_ARGS__ ); }
#define CIN_A( LL , I , N , ... ) vector<LL> __VA_ARGS__; SET_A( I , N , __VA_ARGS__ )
#define CIN_AA( LL , I0 , N0 , I1 , N1 , VAR ) vector<vector<LL>> VAR( N0 + I0 ); FOR( VARIABLE_FOR_CIN_AA , 0 , N0 ){ SET_A( I1 , N1 , VAR[VARIABLE_FOR_CIN_AA + I0] ); }

#define START_WATCH chrono::system_clock::time_point watch = chrono::system_clock::now(); double loop_average_time = 0.0 , loop_start_time = 0.0 , current_time = 0.0; int loop_count = 0; assert( loop_average_time < 1.0 && loop_start_time < 1.0 && loop_count == 0 )
#define CURRENT_TIME ( current_time = static_cast<double>( chrono::duration_cast<chrono::microseconds>( chrono::system_clock::now() - watch ).count() / 1000.0 ) )
#define CHECK_WATCH( TL_MS ) ( CURRENT_TIME , loop_count == 0 ? loop_start_time = current_time : loop_average_time = ( current_time - loop_start_time ) / loop_count , ++loop_count , current_time < TL_MS - loop_average_time * 2 - 100.0 )
#define CEXPR( LL , BOUND , VALUE ) constexpr LL BOUND = VALUE
#define SET_A_ASSERT( I , N , A , MIN , MAX ) FOR( VARIABLE_FOR_SET_A , 0 , N ){ SET_ASSERT( A[VARIABLE_FOR_SET_A + I] , MIN , MAX ); }
#define SET_AA_ASSERT( I0 , N0 , I1 , N1 , A , MIN , MAX ) FOR( VARIABLE_FOR_SET_AA0 , 0 , N0 ){ FOR( VARIABLE_FOR_SET_AA1 , 0 , N1 ){ SET_ASSERT( A[VARIABLE_FOR_SET_AA0 + I0][VARIABLE_FOR_SET_AA1 + I1] , MIN , MAX ); } }
#define CIN_ASSERT( A , MIN , MAX ) decldecay_t( MAX ) A; SET_ASSERT( A , MIN , MAX )
#define CIN_A_ASSERT( I , N , A , MIN , MAX ) vector<decldecay_t( MAX )> A( N + I ); SET_A_ASSERT( I , N , A , MIN , MAX )
#define CIN_AA_ASSERT( I0 , N0 , I1 , N1 , A , MIN , MAX ) vector A( N0 + I0 , vector<decldecay_t( MAX )>( N1 + I1 ) ); SET_AA_ASSERT( I0 , N0 , I1 , N1 , A , MIN , MAX )
#define FOR( VAR , INITIAL , FINAL_PLUS_ONE ) for( decldecay_t( FINAL_PLUS_ONE ) VAR = INITIAL ; VAR < FINAL_PLUS_ONE ; VAR ++ )
#define FOREQ( VAR , INITIAL , FINAL ) for( decldecay_t( FINAL ) VAR = INITIAL ; VAR <= FINAL ; VAR ++ )
#define FOREQINV( VAR , INITIAL , FINAL ) for( decldecay_t( INITIAL ) VAR = INITIAL ; VAR + 1 > FINAL ; VAR -- )
#define RUN( ARRAY , ... ) for( auto&& __VA_ARGS__ : ARRAY )
#define REPEAT( HOW_MANY_TIMES ) FOR( VARIABLE_FOR_REPEAT_ ## HOW_MANY_TIMES , 0 , HOW_MANY_TIMES )
#define SET_PRECISION( DECIMAL_DIGITS ) cout << fixed << setprecision( DECIMAL_DIGITS ); cerr << fixed << setprecision( DECIMAL_DIGITS )
