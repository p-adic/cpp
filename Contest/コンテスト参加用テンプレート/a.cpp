#ifndef INCLUDE_MODE
  #define INCLUDE_MODE
  // #define REACTIVE
  // #define USE_GETLINE
#endif

#ifdef INCLUDE_MAIN

IN VO Solve()
{
  // // 数
  // // DEXPR( ll , bound_N , 1e5 , 10 );
  // // CIN_ASSERT( N , 1 , bound_N ); // ランダムテスト用。
  // CIN( ll , N , M , K );
  // ll answer = 0;
  // RETURN( answer );

  // // 配列
  // using value_type = ll;
  // // using value_type = MP;
  // CIN( int , N ); CIN_A( value_type , A , N ); CIN_A( value_type , B , N );
  // FOR( i , 0 , N ){ cin >> A[i] >> B[i]; }
  // // FOR( i , 0 , N * 2 ){ cin >> ( i < N ? A[i] : B[i-N] ); }
  // value_type answer = 0;
  // RETURN( answer );

  // // 文字列
  // CIN( int , N ); CIN( string , S , T );
  // ll answer = 0;
  // RETURN( answer );

  // // 順列
  // CIN( int , N ); vector<int> A( N ) , A_inv( N );
  // FOR( i , 0 , N ){ cin >> A[i]; A_inv[--A[i]] = i; }
  // ll answer = 0;
  // RETURN( answer );
  
  // // グラフ
  // CIN( int , N , M );
  // // CIN( int , N ); int M = N - 1;
  // gE<int>.resize( N );
  // // UnionFindForest uff{ N };
  // FOR( j , 0 , M ){
  //   CIN( int , uj , vj ); uj--; vj--;
  //   gE<int>[uj].push_back( vj ); gE<int>[vj].push_back( uj );
  //   // uff.Graft( uj , vj );
  // }
  // // auto edge = [&]( CO int& i ){
  // //   list<int> answer{};
  // //   RE answer;
  // // };
  // BreadthFirstSearch bfs{ N , Get( gE<int> ) , 0 };
  // // DepthFirstSearchOnTree dfst{ N , Get( gE<int> ) , 0 };
  // ll answer = 0;
  // RETURN( answer );
  
  // // 重み付きグラフ
  // CIN( int , N , M );
  // // CIN( int , N ); int M = N - 1;
  // gE<path>.resize( N );
  // // UnionFindForest uff{ N };
  // FOR( j , 0 , M ){
  //   CIN( ll , uj , vj , wj ); uj--; vj--;
  //   gE<path>[uj].push_back( { vj , wj } ); gE<path>[vj].push_back( { uj , wj } );
  //   // uff.Graft( uj , vj , wj );
  // }
  // auto edge = [&]( CO int& i ){
  //   list<path> answer{};
  //   return answer;
  // };
  // Dijkstra dijk{ N , Get( gE<path> ) };
  // ll answer = 0;
  // RETURN( answer );
 
  // // 一般のクエリ
  // CIN( int , Q );
  // vector<T3<int>> query( Q );
  // // vector<T2<int>> query( Q );
  // FOR( q , 0 , Q ){
  //   CIN( int , type );
  //   if( type == 1 ){
  //     CIN( ll , x , y );
  //     // query[q] = { type , x , y };
  //   } else if( type == 2 ){
  //     CIN( ll , x , y );
  //     // query[q] = { type , x , y };
  //     COUT( x + y );
  //   }
  //   // CIN( ll , x , y );
  //   // // query[q] = { x , y };
  //   // COUT( x + y );
  // }
  // // sort( query , query + Q );
  // // FOR( q , 0 , Q ){
  // //   auto& [x,y] = query[q];
  // //   // auto& [type,x,y] = query[q];
  // // }
  // ll answer = 0;
  // RETURN( answer );
  
  // // グリッド
  // // DEXPR( int , bound_H , 2e3 , 30 ); CEXPR( int , bound_W , bound_H );
  // // ST_AS( ll( bound_H ) * bound_W < ll( 1 ) << 31 );
  // // CEXPR( int , bound_HW , bound_H * bound_W );
  // // SET_ASSERT( H , 1 , bound_H ); SET_ASSERT( W , 1 , bound_W ); // ランダムテスト用。
  // cin >> H >> W; H_minus = H - 1; W_minus = W - 1; HW = H * W;
  // vector<string> S( H );
  // FOR( i , 0 , H ){
  //   cin >> S[i];
  //   // SetEdgeOnGrid( S[i] , i , gE<int> );
  //   // SetWallOnGrid( S[i] , i , non_wall );
  // }
  // // {h,w}へデコード: EnumHW( v )
  // // {h,w}をコード: EnumHW_inv( h , w );
  // // (i,j)->(k,h)の方向番号を取得: DirectionNumberOnGrid( i , j , k , h );
  // // v->wの方向番号を取得: DirectionNumberOnGrid( v , w );
  // // 方向番号の反転U<->D、R<->L: ReverseDirectionNumberOnGrid( n );
  // ll answer = 0;
  // RETURN( answer );
}
REPEAT_MAIN(1);

#else // INCLUDE_MAIN

#ifdef INCLUDE_SUB

// グラフ用
TE <TY T> Map<T,T> gF;
TE <TY T> VE<T> gA;
TE <TY PATH> VE<LI<PATH>> gE;
TE <TY T , TE <TY...> TY V> IN auto Get( CO V<T>& a ) { RE [&]( CRI i ){ RE a[i]; }; }

// COMPAREに使用。圧縮時は削除する。
ll Naive( int N , int M , int K )
{
  ll answer = N + M + K;
  return answer;
}

// COMPAREに使用。圧縮時は削除する。
ll Answer( ll N , ll M , ll K )
{
  // START_WATCH;
  ll answer = N + M + K;

  // // TLに準じる乱択や全探索。デフォルトの猶予は100.0[ms]。
  // CEXPR( double , TL , 2000.0 );
  // while( CHECK_WATCH( TL ) ){

  // }
  return answer;
}

// 圧縮時は中身だけ削除する。
IN VO Experiment()
{
  // CEXPR( int , bound , 10 );
  // FOREQ( N , 0 , bound ){
  //   FOREQ( M , 0 , bound ){
  //     FOREQ( K , 0 , bound ){
  //   	COUT( N , M , K , ":" , Naive( N , M , K ) );
  //     }
  //   }
  //   // cout << Naive( N ) << ",\n"[N==bound];
  // }
}

// 圧縮時は中身だけ削除する。
IN VO SmallTest()
{
  // CEXPR( int , bound , 10 );
  // FOREQ( N , 0 , bound ){
  //   FOREQ( M , 0 , bound ){
  //     FOREQ( K , 0 , bound ){
  //   	COMPARE( N , M , K );
  //     }
  //   }
  //   // COMPARE( N );
  // }
}

#define INCLUDE_MAIN
#include __FILE__

#else // INCLUDE_SUB

#ifdef INCLUDE_LIBRARY

/*

C-x 3 C-x o C-x C-fによるファイル操作用

BFS:
c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/compress.txt

CoordinateCompress:
c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/compress.txt

DFSOnTree
c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a.hpp

Divisor:
c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/compress.txt

Polynomial
c:/Users/user/Documents/Programming/Mathematics/Polynomial/compress.txt

UnionFind
c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/UnionFindForest/compress.txt

*/

// VVV 常設でないライブラリは以下に挿入する。












// AAA 常設でないライブラリは以上に挿入する。

#define INCLUDE_SUB
#include __FILE__

#else // INCLUDE_LIBRARY

#ifdef DEBUG
  #define _GLIBCXX_DEBUG
  #define REPEAT_MAIN( BOUND ) START_MAIN; signal( SIGABRT , &AlertAbort ); AutoCheck( exec_mode , use_getline ); if( exec_mode == sample_debug_mode || exec_mode == submission_debug_mode || exec_mode == library_search_mode ){ RE 0; } else if( exec_mode == experiment_mode ){ Experiment(); RE 0; } else if( exec_mode == small_test_mode ){ SmallTest(); RE 0; }; DEXPR( int , bound_test_case_num , BOUND , min( BOUND , 100 ) ); int test_case_num = 1; if( exec_mode == solve_mode ){ if CE( bound_test_case_num > 1 ){ SET_ASSERT( test_case_num , 1 , bound_test_case_num ); } } else if( exec_mode == random_test_mode ){ CERR( "ランダムテストを行う回数を指定してください。" ); SET_LL( test_case_num ); } FINISH_MAIN
  #define DEXPR( LL , BOUND , VALUE , DEBUG_VALUE ) CEXPR( LL , BOUND , DEBUG_VALUE )
  #define ASSERT( A , MIN , MAX ) CERR( "ASSERTチェック： " , ( MIN ) , ( ( MIN ) <= A ? "<=" : ">" ) , A , ( A <= ( MAX ) ? "<=" : ">" ) , ( MAX ) ); AS( ( MIN ) <= A && A <= ( MAX ) )
  #define SET_ASSERT( A , MIN , MAX ) if( exec_mode == solve_mode ){ SET_LL( A ); ASSERT( A , MIN , MAX ); } else if( exec_mode == random_test_mode ){ CERR( #A , " = " , ( A = GetRand( MIN , MAX ) ) ); } else { AS( false ); }
  #define SOLVE_ONLY ST_AS( __FUNCTION__[0] == 'S' )
  #define CERR( ... ) VariadicCout( cerr , __VA_ARGS__ ) << endl
  #define COUT( ... ) VariadicCout( cout << "出力： " , __VA_ARGS__ ) << endl
  #define CERR_A( A , N ) OUTPUT_ARRAY( cerr , A , N ) << endl
  #define COUT_A( A , N ) cout << "出力： "; OUTPUT_ARRAY( cout , A , N ) << endl
  #define CERR_ITR( A ) OUTPUT_ITR( cerr , A ) << endl
  #define COUT_ITR( A ) cout << "出力： "; OUTPUT_ITR( cout , A ) << endl
#else
  #pragma GCC optimize ( "O3" )
  #pragma GCC optimize ( "unroll-loops" )
  #pragma GCC target ( "sse4.2,fma,avx2,popcnt,lzcnt,bmi2" )
  #define REPEAT_MAIN( BOUND ) START_MAIN; CEXPR( int , bound_test_case_num , BOUND ); int test_case_num = 1; if CE( bound_test_case_num > 1 ){ SET_ASSERT( test_case_num , 1 , bound_test_case_num ); } FINISH_MAIN
  #define DEXPR( LL , BOUND , VALUE , DEBUG_VALUE ) CEXPR( LL , BOUND , VALUE )
  #define ASSERT( A , MIN , MAX ) AS( ( MIN ) <= A && A <= ( MAX ) )
  #define SET_ASSERT( A , MIN , MAX ) SET_LL( A ); ASSERT( A , MIN , MAX )
  #define SOLVE_ONLY 
  #define CERR( ... ) 
  #define COUT( ... ) VariadicCout( cout , __VA_ARGS__ ) << ENDL
  #define CERR_A( A , N ) 
  #define COUT_A( A , N ) OUTPUT_ARRAY( cout , A , N ) << ENDL
  #define CERR_ITR( A ) 
  #define COUT_ITR( A ) OUTPUT_ITR( cout , A ) << ENDL
#endif
#ifdef REACTIVE
  #define ENDL endl
#else
  #define ENDL "\n"
#endif
#ifdef USE_GETLINE
  #define SET_LL( A ) { GETLINE( A ## _str ); A = stoll( A ## _str ); }
  #define GETLINE_SEPARATE( SEPARATOR , ... ) SOLVE_ONLY; string __VA_ARGS__; VariadicGetline( cin , SEPARATOR , __VA_ARGS__ )
  #define GETLINE( ... ) SOLVE_ONLY; GETLINE_SEPARATE( '\n' , __VA_ARGS__ )
#else
  #define SET_LL( A ) cin >> A
  #define CIN( LL , ... ) SOLVE_ONLY; LL __VA_ARGS__; VariadicCin( cin , __VA_ARGS__ )
  #define SET_A( A , N ) SOLVE_ONLY; FOR( VARIABLE_FOR_CIN_A , 0 , N ){ cin >> A[VARIABLE_FOR_CIN_A]; }
  #define CIN_A( LL , A , N ) VE<LL> A( N ); SET_A( A , N );
#endif
#include <bits/stdc++.h>
using namespace std;
#define ATT __attribute__( ( target( "sse4.2,fma,avx2,popcnt,lzcnt,bmi2" ) ) )
#define START_MAIN int main(){ ios_base::sync_with_stdio( false ); cin.tie( nullptr )
#define FINISH_MAIN REPEAT( test_case_num ){ if CE( bound_test_case_num > 1 ){ CERR( "testcase " , VARIABLE_FOR_REPEAT_test_case_num , ":" ); } Solve(); CERR( "" ); } }
#define START_WATCH chrono::system_clock::time_point watch = chrono::system_clock::now()
#define CURRENT_TIME static_cast<double>( chrono::duration_cast<chrono::microseconds>( chrono::system_clock::now() - watch ).count() / 1000.0 )
#define CHECK_WATCH( TL_MS ) ( CURRENT_TIME < TL_MS - 100.0 )
#define CEXPR( LL , BOUND , VALUE ) CE LL BOUND = VALUE
#define CIN_ASSERT( A , MIN , MAX ) decldecay_t( MAX ) A; SET_ASSERT( A , MIN , MAX )
#define FOR( VAR , INITIAL , FINAL_PLUS_ONE ) for( decldecay_t( FINAL_PLUS_ONE ) VAR = INITIAL ; VAR < FINAL_PLUS_ONE ; VAR ++ )
#define FOREQ( VAR , INITIAL , FINAL ) for( decldecay_t( FINAL ) VAR = INITIAL ; VAR <= FINAL ; VAR ++ )
#define FOREQINV( VAR , INITIAL , FINAL ) for( decldecay_t( INITIAL ) VAR = INITIAL ; VAR + 1 > FINAL ; VAR -- )
#define AUTO_ITR( ARRAY ) auto itr_ ## ARRAY = ARRAY .BE() , end_ ## ARRAY = ARRAY .EN()
#define FOR_ITR( ARRAY ) for( AUTO_ITR( ARRAY ) , itr = itr_ ## ARRAY ; itr_ ## ARRAY != end_ ## ARRAY ; itr_ ## ARRAY ++ , itr++ )
#define REPEAT( HOW_MANY_TIMES ) FOR( VARIABLE_FOR_REPEAT_ ## HOW_MANY_TIMES , 0 , HOW_MANY_TIMES )
#define SET_PRECISION( DECIMAL_DIGITS ) cout << fixed << setprecision( DECIMAL_DIGITS )
#define OUTPUT_ARRAY( OS , A , N ) FOR( VARIABLE_FOR_OUTPUT_ARRAY , 0 , N ){ OS << A[VARIABLE_FOR_OUTPUT_ARRAY] << (VARIABLE_FOR_OUTPUT_ARRAY==N-1?"":" "); } OS
#define OUTPUT_ITR( OS , A ) { auto ITERATOR_FOR_OUTPUT_ITR = A.BE() , EN_FOR_OUTPUT_ITR = A.EN(); bool VARIABLE_FOR_OUTPUT_ITR = ITERATOR_FOR_COUT_ITR != END_FOR_COUT_ITR; WH( VARIABLE_FOR_OUTPUT_ITR ){ OS << *ITERATOR_FOR_COUT_ITR; ( VARIABLE_FOR_OUTPUT_ITR = ++ITERATOR_FOR_COUT_ITR != END_FOR_COUT_ITR ) ? OS : OS << " "; } } OS
#define RETURN( ... ) SOLVE_ONLY; COUT( __VA_ARGS__ ); RE
#define COMPARE( ... ) auto naive = Naive( __VA_ARGS__ ); auto answer = Answer( __VA_ARGS__ ); bool match = naive == answer; COUT( "(" , #__VA_ARGS__ , ") == (" , __VA_ARGS__ , ") : Naive == " , naive , match ? "==" : "!=" , answer , "== Answer" ); if( !match ){ RE; }

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
#define ST_AS static_assert
#define reMO_CO remove_const
#define is_COructible is_constructible
#define rBE rbegin
#define reSZ

// 型のエイリアス
#define decldecay_t( VAR ) decay_t<decltype( VAR )>
TE <TY F , TY...Args> US ret_t = decltype( declval<F>()( declval<Args>()... ) );
TE <TY T> US inner_t = TY T::type;
US uint = unsigned int;
US ll = long long;
US ull = unsigned long long;
US ld = long double;
US lld = __float128;
TE <TY INT> US T2 = pair<INT,INT>;
TE <TY INT> US T3 = tuple<INT,INT,INT>;
TE <TY INT> US T4 = tuple<INT,INT,INT,INT>;
US path = pair<int,ll>;

// 入出力用
TE <CL Traits> IN basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is ) { RE is; }
TE <CL Traits , TY Arg , TY... ARGS> IN basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is , Arg& arg , ARGS&... args ) { RE VariadicCin( is >> arg , args... ); }
TE <CL Traits> IN basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , CO char& separator ) { RE is; }
TE <CL Traits , TY Arg , TY... ARGS> IN basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , CO char& separator , Arg& arg , ARGS&... args ) { RE VariadicGetline( getline( is , arg , separator ) , separator , args... ); }
TE <CL Traits , TY Arg> IN basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , CO VE<Arg>& arg ) { auto BE = arg.BE() , EN = arg.EN(); auto itr = BE; WH( itr != EN ){ ( itr == BE ? os : os << " " ) << *itr; itr++; } RE os; }
TE <CL Traits , TY Arg> IN basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , CO Arg& arg ) { RE os << arg; }
TE <CL Traits , TY Arg1 , TY Arg2 , TY... ARGS> IN basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , CO Arg1& arg1 , CO Arg2& arg2 , CO ARGS&... args ) { RE VariadicCout( os << arg1 << " " , arg2 , args... ); }

// 算術用
TE <TY T> CE T PositiveBaseResidue( CO T& a , CO T& p ){ RE a >= 0 ? a % p : p - 1 - ( ( - ( a + 1 ) ) % p ); }
TE <TY T> CE T Residue( CO T& a , CO T& p ){ RE PositiveBaseResidue( a , p < 0 ? -p : p ); }
TE <TY T> CE T PositiveBaseQuotient( CO T& a , CO T& p ){ RE ( a - PositiveBaseResidue( a , p ) ) / p; }
TE <TY T> CE T Quotient( CO T& a , CO T& p ){ RE p < 0 ? PositiveBaseQuotient( -a , -p ) : PositiveBaseQuotient( a , p ); }

#define POWER( ANSWER , ARGUMENT , EXPONENT )				\
  ST_AS( ! is_same<decldecay_t( ARGUMENT ),int>::value && ! is_same<decldecay_t( ARGUMENT ),uint>::value ); \
  decldecay_t( ARGUMENT ) ANSWER{ 1 };					\
  {									\
    decldecay_t( ARGUMENT ) ARGUMENT_FOR_SQUARE_FOR_POWER = ( ARGUMENT ); \
    decldecay_t( EXPONENT ) EXPONENT_FOR_SQUARE_FOR_POWER = ( EXPONENT ); \
    WH( EXPONENT_FOR_SQUARE_FOR_POWER != 0 ){				\
      if( EXPONENT_FOR_SQUARE_FOR_POWER % 2 == 1 ){			\
	ANSWER *= ARGUMENT_FOR_SQUARE_FOR_POWER;			\
      }									\
      ARGUMENT_FOR_SQUARE_FOR_POWER *= ARGUMENT_FOR_SQUARE_FOR_POWER;	\
      EXPONENT_FOR_SQUARE_FOR_POWER /= 2;				\
    }									\
  }									\

#define POWER_MOD( ANSWER , ARGUMENT , EXPONENT , MODULO )		\
  ll ANSWER{ 1 };							\
  {									\
    ll ARGUMENT_FOR_SQUARE_FOR_POWER = ( ( ARGUMENT ) % ( MODULO ) ) % ( MODULO ); \
    ARGUMENT_FOR_SQUARE_FOR_POWER < 0 ? ARGUMENT_FOR_SQUARE_FOR_POWER += ( MODULO ) : ARGUMENT_FOR_SQUARE_FOR_POWER; \
    decldecay_t( EXPONENT ) EXPONENT_FOR_SQUARE_FOR_POWER = ( EXPONENT ); \
    WH( EXPONENT_FOR_SQUARE_FOR_POWER != 0 ){				\
      if( EXPONENT_FOR_SQUARE_FOR_POWER % 2 == 1 ){			\
	ANSWER = ( ANSWER * ARGUMENT_FOR_SQUARE_FOR_POWER ) % ( MODULO ); \
      }									\
      ARGUMENT_FOR_SQUARE_FOR_POWER = ( ARGUMENT_FOR_SQUARE_FOR_POWER * ARGUMENT_FOR_SQUARE_FOR_POWER ) % ( MODULO ); \
      EXPONENT_FOR_SQUARE_FOR_POWER /= 2;				\
    }									\
  }									\

#define FACTORIAL_MOD( ANSWER , ANSWER_INV , INVERSE , MAX_INDEX , CE_LENGTH , MODULO ) \
  ll ANSWER[CE_LENGTH];							\
  ll ANSWER_INV[CE_LENGTH];						\
  ll INVERSE[CE_LENGTH];						\
  {									\
    ll VARIABLE_FOR_PRODUCT_FOR_FACTORIAL = 1;				\
    ANSWER[0] = VARIABLE_FOR_PRODUCT_FOR_FACTORIAL;			\
    FOREQ( i , 1 , MAX_INDEX ){						\
      ANSWER[i] = ( VARIABLE_FOR_PRODUCT_FOR_FACTORIAL *= i ) %= ( MODULO ); \
    }									\
    ANSWER_INV[0] = ANSWER_INV[1] = INVERSE[1] = VARIABLE_FOR_PRODUCT_FOR_FACTORIAL = 1; \
    FOREQ( i , 2 , MAX_INDEX ){						\
      ANSWER_INV[i] = ( VARIABLE_FOR_PRODUCT_FOR_FACTORIAL *= INVERSE[i] = ( MODULO ) - ( ( ( ( MODULO ) / i ) * INVERSE[ ( MODULO ) % i ] ) % ( MODULO ) ) ) %= ( MODULO ); \
    }									\
  }									\

// 二分探索用
// EXPRESSIONがANSWERの広義単調関数の時、EXPRESSION >= CO_TARGETの整数解を格納。
#define BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , DESIRED_INEQUALITY , CO_TARGET , INEQUALITY_FOR_CHECK , UPDATE_U , UPDATE_L , UPDATE_ANSWER ) \
  ST_AS( ! is_same<decldecay_t( CO_TARGET ),uint>::value && ! is_same<decldecay_t( CO_TARGET ),ull>::value ); \
  ll ANSWER = MINIMUM;							\
  {									\
    ll L_BS = MINIMUM;							\
    ll U_BS = MAXIMUM;							\
    ANSWER = UPDATE_ANSWER;						\
    ll EXPRESSION_BS;							\
    CO ll CO_TARGET_BS = ( CO_TARGET );			\
    ll DIFFERENCE_BS;							\
    WH( L_BS < U_BS ){						\
      DIFFERENCE_BS = ( EXPRESSION_BS = ( EXPRESSION ) ) - CO_TARGET_BS; \
      CERR( "二分探索中：" , "L_BS =" , L_BS , "<=" , #ANSWER , "=" , ANSWER , "<=" , U_BS , "= U_BS :" , #EXPRESSION , "-" , #CO_TARGET , "=" , EXPRESSION_BS , "-" , CO_TARGET_BS , "=" , DIFFERENCE_BS ); \
      if( DIFFERENCE_BS INEQUALITY_FOR_CHECK 0 ){			\
	U_BS = UPDATE_U;						\
      } else {								\
	L_BS = UPDATE_L;						\
      }									\
      ANSWER = UPDATE_ANSWER;						\
    }									\
    if( L_BS > U_BS ){							\
      CERR( "二分探索失敗：" , "L_BS =" , L_BS , ">" , U_BS , "= U_BS :" , #ANSWER , ":=" , #MAXIMUM , "+ 1 =" , MAXIMUM + 1  ); \
      CERR( "二分探索マクロにミスがある可能性があります。変更前の版に戻してください。" ); \
      ANSWER = MAXIMUM + 1;						\
    } else {								\
      CERR( "二分探索終了：" , "L_BS =" , L_BS , "<=" , #ANSWER , "=" , ANSWER , "<=" , U_BS , "= U_BS" ); \
      CERR( "二分探索が成功したかを確認するために" , #EXPRESSION , "を計算します。" ); \
      CERR( "成功判定が不要な場合はこの計算を削除しても構いません。" );	\
      EXPRESSION_BS = ( EXPRESSION );					\
      CERR( "二分探索結果：" , #EXPRESSION , "=" , EXPRESSION_BS , ( EXPRESSION_BS > CO_TARGET_BS ? ">" : EXPRESSION_BS < CO_TARGET_BS ? "<" : "=" ) , CO_TARGET_BS ); \
      if( EXPRESSION_BS DESIRED_INEQUALITY CO_TARGET_BS ){		\
	CERR( "二分探索成功：" , #ANSWER , ":=" , ANSWER );		\
      } else {								\
	CERR( "二分探索失敗：" , #ANSWER , ":=" , #MAXIMUM , "+ 1 =" , MAXIMUM + 1 ); \
	CERR( "単調でないか、単調増加性と単調減少性を逆にしてしまったか、探索範囲内に解が存在しません。" ); \
	ANSWER = MAXIMUM + 1;						\
      }									\
    }									\
  }									\

// 単調増加の時にEXPRESSION >= CO_TARGETの最小解を格納。
#define BS1( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CO_TARGET )	\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CO_TARGET , >= , ANSWER , ANSWER + 1 , ( L_BS + U_BS ) / 2 ) \

// 単調増加の時にEXPRESSION <= CO_TARGETの最大解を格納。
#define BS2( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CO_TARGET )	\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CO_TARGET , > , ANSWER - 1 , ANSWER , ( L_BS + 1 + U_BS ) / 2 ) \

// 単調減少の時にEXPRESSION >= CO_TARGETの最大解を格納。
#define BS3( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CO_TARGET )	\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CO_TARGET , < , ANSWER - 1 , ANSWER , ( L_BS + 1 + U_BS ) / 2 ) \

// 単調減少の時にEXPRESSION <= CO_TARGETの最小解を格納。
#define BS4( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CO_TARGET )	\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CO_TARGET , <= , ANSWER , ANSWER + 1 , ( L_BS + U_BS ) / 2 ) \

// t以下の値が存在すればその最大値のiterator、存在しなければend()を返す。
TE <TY T> IN TY set<T>::iterator MaximumLeq( set<T>& S , CO T& t ) { CO auto EN = S.EN(); if( S.empty() ){ RE EN; } auto itr = S.upper_bound( t ); RE itr == EN ? S.find( *( S.rBE() ) ) : itr == S.BE() ? EN : --itr; }
// t未満の値が存在すればその最大値のiterator、存在しなければend()を返す。
TE <TY T> IN TY set<T>::iterator MaximumLt( set<T>& S , CO T& t ) { CO auto EN = S.EN(); if( S.empty() ){ RE EN; } auto itr = S.lower_bound( t ); RE itr == EN ? S.find( *( S.rBE() ) ) : itr == S.BE() ? EN : --itr; }
// t以上の値が存在すればその最小値のiterator、存在しなければend()を返す。
TE <TY T> IN TY set<T>::iterator MinimumGeq( set<T>& S , CO T& t ) { RE S.lower_bound( t ); }
// tより大きい値が存在すればその最小値のiterator、存在しなければend()を返す。
TE <TY T> IN TY set<T>::iterator MinimumGt( set<T>& S , CO T& t ) { RE S.upper_bound( t ); }

// データ構造用
TE <TY T , TE <TY...> TY V> IN V<T> OP+( CO V<T>& a0 , CO V<T>& a1 ) { if( a0.empty() ){ RE a1; } if( a1.empty() ){ RE a0; } AS( a0.SZ() == a1.SZ() ); V<T> answer{}; for( auto itr0 = a0.BE() , itr1 = a1.BE() , EN0 = a0.EN(); itr0 != EN0 ; itr0++ , itr1++ ){ answer.push_back( *itr0 + *itr1 ); } RE answer; }
TE <TY T , TY U> IN pair<T,U> OP+( CO pair<T,U>& t0 , CO pair<T,U>& t1 ) { RE { t0.first + t1.first , t0.second + t1.second }; }
TE <TY T , TY U , TY V> IN tuple<T,U,V> OP+( CO tuple<T,U,V>& t0 , CO tuple<T,U,V>& t1 ) { RE { get<0>( t0 ) + get<0>( t1 ) , get<1>( t0 ) + get<1>( t1 ) , get<2>( t0 ) + get<2>( t1 ) }; }
TE <TY T , TY U , TY V , TY W> IN tuple<T,U,V,W> OP+( CO tuple<T,U,V,W>& t0 , CO tuple<T,U,V,W>& t1 ) { RE { get<0>( t0 ) + get<0>( t1 ) , get<1>( t0 ) + get<1>( t1 ) , get<2>( t0 ) + get<2>( t1 ) , get<3>( t0 ) + get<3>( t1 ) }; }
TE <TY T> IN T Add( CO T& t0 , CO T& t1 ) { RE t0 + t1; }
TE <TY T> IN T XorAdd( CO T& t0 , CO T& t1 ){ RE t0 ^ t1; }
TE <TY T> IN T Multiply( CO T& t0 , CO T& t1 ) { RE t0 * t1; }
TE <TY T> IN CO T& Zero() { ST CO T z{}; RE z; }
TE <TY T> IN CO T& One() { ST CO T o = 1; RE o; }\
TE <TY T> IN T AddInv( CO T& t ) { RE -t; }
TE <TY T> IN T Id( CO T& v ) { RE v; }
TE <TY T> IN T Min( CO T& a , CO T& b ){ RE a < b ? a : b; }
TE <TY T> IN T Max( CO T& a , CO T& b ){ RE a < b ? b : a; }

// グリッド問題用
int H , W , H_minus , W_minus , HW;
VE<VE<bool>> non_wall;
IN T2<int> EnumHW( CRI v ) { RE { v / W , v % W }; }
IN int EnumHW_inv( CRI h , CRI w ) { RE h * W + w; }
CO string direction[4] = {"U","R","D","L"};
// (i,j)->(k,h)の方向番号を取得
IN int DirectionNumberOnGrid( CRI i , CRI j , CRI k , CRI h ){RE i<k?2:i>k?0:j<h?1:j>h?3:(AS(false),-1);}
// v->wの方向番号を取得
IN int DirectionNumberOnGrid( CRI v , CRI w ){auto [i,j]=EnumHW(v);auto [k,h]=EnumHW(w);RE DirectionNumberOnGrid(i,j,k,h);}
// 方向番号の反転U<->D、R<->L
IN int ReverseDirectionNumberOnGrid( CRI n ){AS(0<=n&&n<4);RE(n+2)%4;}
IN VO SetEdgeOnGrid( CO string& Si , CRI i , LI<int> ( &e )[] , CO char& walkable = '.' ){FOR(j,0,W){if(Si[j]==walkable){int v = EnumHW_inv(i,j);if(i>0){e[EnumHW_inv(i-1,j)].push_back(v);}if(i+1<H){e[EnumHW_inv(i+1,j)].push_back(v);}if(j>0){e[EnumHW_inv(i,j-1)].push_back(v);}if(j+1<W){e[EnumHW_inv(i,j+1)].push_back(v);}}}}
IN VO SetEdgeOnGrid( CO string& Si , CRI i , LI<path> ( &e )[] , CO char& walkable = '.' ){FOR(j,0,W){if(Si[j]==walkable){CO int v=EnumHW_inv(i,j);if(i>0){e[EnumHW_inv(i-1,j)].push_back({v,1});}if(i+1<H){e[EnumHW_inv(i+1,j)].push_back({v,1});}if(j>0){e[EnumHW_inv(i,j-1)].push_back({v,1});}if(j+1<W){e[EnumHW_inv(i,j+1)].push_back({v,1});}}}}
IN VO SetWallOnGrid( CO string& Si , CRI i , VE<VE<bool>>& non_wall , CO char& walkable = '.'  , CO char& unwalkable = '#' ){non_wall.push_back(VE<bool>(W));auto& non_wall_i=non_wall[i];FOR(j,0,W){non_wall_i[j]=Si[j]==walkable?true:(assert(Si[j]==unwalkable),false);}}

// デバッグ用
#ifdef DEBUG
  IN VO AlertAbort( int n ) { CERR( "abort関数が呼ばれました。assertマクロのメッセージが出力されていない場合はオーバーフローの有無を確認をしてください。" ); }
  VO AutoCheck( int& exec_mode , CO bool& use_getline );
  IN VO Solve();
  IN VO Experiment();
  IN VO SmallTest();
  IN VO RandomTest();
  ll GetRand( CRL Rand_min , CRL Rand_max );
  IN VO BreakPoint( CRI LINE ) {}
  int exec_mode;
  CEXPR( int , solve_mode , 0 );
  CEXPR( int , sample_debug_mode , 1 );
  CEXPR( int , submission_debug_mode , 2 );
  CEXPR( int , library_search_mode , 3 );
  CEXPR( int , experiment_mode , 4 );
  CEXPR( int , small_test_mode , 5 );
  CEXPR( int , random_test_mode , 6 );
  #ifdef USE_GETLINE
    CEXPR( bool , use_getline , true );
  #else
    CEXPR( bool , use_getline , false );
  #endif
#else
  ll GetRand( CRL Rand_min , CRL Rand_max ) { ll answer = time( NULL ); RE answer * rand() % ( Rand_max + 1 - Rand_min ) + Rand_min; }
#endif

// VVV 常設ライブラリは以下に挿入する。
// Map
// c:/Users/user/Documents/Programming/Mathematics/Function/Map/compress.txt
CL is_ordered{PU:is_ordered()= delete;TE <TY T> ST CE auto Check(CO T& t)-> decltype(t < t,true_type());ST CE false_type Check(...);TE <TY T> ST CE CO bool value = is_same_v< decltype(Check(declval<T>())),true_type >;};
TE <TY T , TY U>US Map = conditional_t<is_COructible_v<unordered_map<T,int>>,unordered_map<T,U>,conditional_t<is_ordered::value<T>,map<T,U>,VO>>;

// Algebra
// c:/Users/user/Documents/Programming/Mathematics/Algebra/compress.txt
TE <TY U>CL VirtualPointedSet{PU:virtual CO U& Point()CO NE = 0;IN CO U& Unit()CO NE;IN CO U& Zero()CO NE;IN CO U& One()CO NE;IN CO U& Infty()CO NE;IN CO U& SZ()CO NE;};TE <TY U>CL PointedSet:virtual PU VirtualPointedSet<U>{PU:U m_b_U;IN PointedSet(CO U& b_u = U());IN CO U& Point()CO NE;};TE <TY U>CL VirtualNSet{PU:virtual U Transfer(CO U& u)= 0;IN U Inverse(CO U& u);};TE <TY U,TY F_U>CL AbstractNSet:virtual PU VirtualNSet<U>{PU:F_U m_f_U;IN AbstractNSet(F_U f_U);IN U Transfer(CO U& u);};TE <TY U>CL VirtualMagma{PU:virtual U Product(CO U& u0,CO U& u1)= 0;IN U Sum(CO U& u0,CO U& u1);};TE <TY U,TY M_U>CL AbstractMagma:virtual PU VirtualMagma<U>{PU:M_U m_m_U;IN AbstractMagma(M_U m_U);IN U Product(CO U& u0,CO U& u1);};
TE <TY U> IN PointedSet<U>::PointedSet(CO U& b_U):m_b_U(b_U){}TE <TY U> IN CO U& PointedSet<U>::Point()CO NE{RE m_b_U;}TE <TY U> IN CO U& VirtualPointedSet<U>::Unit()CO NE{RE Point();}TE <TY U> IN CO U& VirtualPointedSet<U>::Zero()CO NE{RE Point();}TE <TY U> IN CO U& VirtualPointedSet<U>::One()CO NE{RE Point();}TE <TY U> IN CO U& VirtualPointedSet<U>::Infty()CO NE{RE Point();}TE <TY U> IN CO U& VirtualPointedSet<U>::SZ()CO NE{RE Point();}TE <TY U,TY F_U> IN AbstractNSet<U,F_U>::AbstractNSet(F_U f_U):m_f_U(MO(f_U)){ST_AS(is_invocable_r_v<U,F_U,U>);}TE <TY U,TY F_U> IN U AbstractNSet<U,F_U>::Transfer(CO U& u){RE m_f_U(u);}TE <TY U> IN U VirtualNSet<U>::Inverse(CO U& u){RE Transfer(u);}TE <TY U,TY M_U> IN AbstractMagma<U,M_U>::AbstractMagma(M_U m_U):m_m_U(MO(m_U)){ST_AS(is_invocable_r_v<U,M_U,U,U>);}TE <TY U,TY M_U> IN U AbstractMagma<U,M_U>::Product(CO U& u0,CO U& u1){RE m_m_U(u0,u1);}TE <TY U> IN U VirtualMagma<U>::Sum(CO U& u0,CO U& u1){RE Product(u0,u1);}

TE <TY U>CL VirtualMonoid:virtual PU VirtualMagma<U>,virtual PU VirtualPointedSet<U>{};TE <TY U = ll>CL AdditiveMonoid:virtual PU VirtualMonoid<U>,PU PointedSet<U>{PU:IN U Product(CO U& u0,CO U& u1);};TE <TY U = ll>CL MultiplicativeMonoid:virtual PU VirtualMonoid<U>,PU PointedSet<U>{PU:IN MultiplicativeMonoid(CO U& e_U);IN U Product(CO U& u0,CO U& u1);};TE <TY U,TY M_U>CL AbstractMonoid:virtual PU VirtualMonoid<U>,PU AbstractMagma<U,M_U>,PU PointedSet<U>{PU:IN AbstractMonoid(M_U m_U,CO U& e_U);IN U Product(CO U& u0,CO U& u1);};
TE <TY U> IN MultiplicativeMonoid<U>::MultiplicativeMonoid(CO U& e_U):PointedSet<U>(e_U){}TE <TY U,TY M_U> IN AbstractMonoid<U,M_U>::AbstractMonoid(M_U m_U,CO U& e_U):AbstractMagma<U,M_U>(MO(m_U)),PointedSet<U>(e_U){}TE <TY U> IN U AdditiveMonoid<U>::Product(CO U& u0,CO U& u1){RE u0 + u1;}TE <TY U> IN U MultiplicativeMonoid<U>::Product(CO U& u0,CO U& u1){RE u0 * u1;}TE <TY U,TY M_U> IN U AbstractMonoid<U,M_U>::Product(CO U& u0,CO U& u1){RE m_m_U(u0,u1);}

TE <TY U>CL VirtualGroup:virtual PU VirtualMonoid<U>,virtual PU VirtualPointedSet<U>,virtual PU VirtualNSet<U>{};TE <TY U = ll>CL AdditiveGroup:virtual PU VirtualGroup<U>,PU AdditiveMonoid<U>{PU:IN U Transfer(CO U& u);};TE <TY U,TY M_U,TY I_U>CL AbstractGroup:virtual PU VirtualGroup<U>,PU AbstractMonoid<U,M_U>,PU AbstractNSet<U,I_U>{PU:IN AbstractGroup(M_U m_U,CO U& e_U,I_U i_U);IN U Transfer(CO U& u);};TE <TY U,TY M_U,TY I_U> IN AbstractGroup<U,M_U,I_U>::AbstractGroup(M_U m_U,CO U& e_U,I_U i_U):AbstractMonoid<U,M_U>(MO(m_U),e_U),AbstractNSet<U,I_U>(MO(i_U)){}TE <TY U,TY M_U,TY I_U> IN U AbstractGroup<U,M_U,I_U>::Transfer(CO U& u){RE m_i_U(u);}TE <TY U> IN U AdditiveGroup<U>::Transfer(CO U& u){RE -u;}

TE <TY U,TY GROUP,TY MONOID>CL VirtualRing{PU:GROUP m_R0;MONOID m_R1;IN VirtualRing(GROUP R0,MONOID R1);IN U Sum(CO U& u0,CO U& u1);IN CO U& Zero()CO NE;IN U Inverse(CO U& u);IN U Product(CO U& u0,CO U& u1);IN CO U& One()CO NE;IN GROUP& AdditiveGroup()NE;IN MONOID& MultiplicativeMonoid()NE;};TE <TY U = ll>CL Ring:virtual PU VirtualRing<U,AdditiveGroup<U>,MultiplicativeMonoid<U>>{PU:IN Ring(CO U& one_U);};TE <TY U,TY A_U,TY I_U,TY M_U>CL AbstractRing:virtual PU VirtualRing<U,AbstractGroup<U,A_U,I_U>,AbstractMonoid<U,M_U>>{PU:IN AbstractRing(A_U a_U,CO U& z_U,I_U i_U,M_U m_U,CO U& e_U);};
TE <TY U,TY GROUP,TY MONOID> IN VirtualRing<U,GROUP,MONOID>::VirtualRing(GROUP R0,MONOID R1):m_R0(MO(R0)),m_R1(MO(R1)){}TE <TY U> IN Ring<U>::Ring(CO U& one_U):VirtualRing<U,AdditiveGroup<U>,MultiplicativeMonoid<U>>(AdditiveGroup<U>(),MultiplicativeMonoid<U>(one_U)){}TE <TY U,TY A_U,TY I_U,TY M_U> IN AbstractRing<U,A_U,I_U,M_U>::AbstractRing(A_U a_U,CO U& z_U,I_U i_U,M_U m_U,CO U& e_U):VirtualRing<U,AbstractGroup<U,A_U,I_U>,AbstractMonoid<U,M_U>>(AbstractGroup<U,A_U,I_U>(MO(a_U),z_U,MO(i_U)),AbstractMonoid<U,M_U>(MO(m_U),e_U)){}TE <TY U,TY GROUP,TY MONOID> IN U VirtualRing<U,GROUP,MONOID>::Sum(CO U& u0,CO U& u1){RE m_R0.Sum(u0,u1);}TE <TY U,TY GROUP,TY MONOID> IN CO U& VirtualRing<U,GROUP,MONOID>::Zero()CO NE{RE m_R0.Zero();}TE <TY U,TY GROUP,TY MONOID> IN U VirtualRing<U,GROUP,MONOID>::Inverse(CO U& u){RE m_R0.Inverse(u);}TE <TY U,TY GROUP,TY MONOID> IN U VirtualRing<U,GROUP,MONOID>::Product(CO U& u0,CO U& u1){RE m_R1.Product(u0,u1);}TE <TY U,TY GROUP,TY MONOID> IN CO U& VirtualRing<U,GROUP,MONOID>::One()CO NE{RE m_R1.One();}TE <TY U,TY GROUP,TY MONOID> IN GROUP& VirtualRing<U,GROUP,MONOID>::AdditiveGroup()NE{RE m_R0;}TE <TY U,TY GROUP,TY MONOID> IN MONOID& VirtualRing<U,GROUP,MONOID>::MultiplicativeMonoid()NE{RE m_R1;}

// Graph
// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/compress.txt
TE <TY T,TY R1,TY R2,TY E>CL VirtualGraph:PU PointedSet<int>{PU:E m_edge;IN VirtualGraph(CRI SZ,E edge);virtual R1 Enumeration(CRI i)= 0;virtual R2 Enumeration_inv(CO T& t)= 0;IN VO Reset();ret_t<E,T> Edge(CO T& t);US type = T;};TE <TY E>CL Graph:virtual PU VirtualGraph<int,CRI,CRI,E>{PU:IN Graph(CRI SZ,E edge);IN CRI Enumeration(CRI i);IN CRI Enumeration_inv(CRI t);TE <TY F> IN Graph<F> GetGraph(F edge)CO;};TE <TY T,TY Enum_T,TY Enum_T_inv,TY E>CL EnumerationGraph:virtual PU VirtualGraph<T,ret_t<Enum_T,int>,ret_t<Enum_T_inv,T>,E>{PU:Enum_T m_enum_T;Enum_T_inv m_enum_T_inv;IN EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge);IN ret_t<Enum_T,int> Enumeration(CRI i);IN ret_t<Enum_T_inv,T> Enumeration_inv(CO T& t);TE <TY F> IN EnumerationGraph<T,Enum_T,Enum_T_inv,F> GetGraph(F edge)CO;};TE <TY Enum_T,TY Enum_T_inv,TY E> EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge)-> EnumerationGraph<decldecay_t(get<0>(declval<E>()(0).back())),Enum_T,Enum_T_inv,E>;TE <TY T,TY E>CL MemorisationGraph:virtual PU VirtualGraph<T,T,CRI,E>{PU:int m_LE;VE<T> m_memory;Map<T,int> m_memory_inv;IN MemorisationGraph(CRI SZ,E edge);IN T Enumeration(CRI i);IN CRI Enumeration_inv(CO T& t);IN VO Reset();TE <TY F> IN MemorisationGraph<T,F> GetGraph(F edge)CO;};TE <TY E> MemorisationGraph(CRI SZ,E edge)-> MemorisationGraph<decldecay_t(get<0>(declval<E>()().back())),E>;
TE <TY T,TY R1,TY R2,TY E> IN VirtualGraph<T,R1,R2,E>::VirtualGraph(CRI SZ,E edge):PointedSet<int>(SZ),m_edge(MO(edge)){ST_AS(is_COructible_v<T,R1> && is_COructible_v<int,R2> && is_invocable_v<E,T>);}TE <TY E> IN Graph<E>::Graph(CRI SZ,E edge):VirtualGraph<int,CRI,CRI,E>(SZ,MO(edge)){}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN EnumerationGraph<T,Enum_T,Enum_T_inv,E>::EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge):VirtualGraph<T,ret_t<Enum_T,int>,ret_t<Enum_T_inv,T>,E>(SZ,MO(edge)),m_enum_T(MO(enum_T)),m_enum_T_inv(MO(enum_T_inv)){}TE <TY T,TY E> IN MemorisationGraph<T,E>::MemorisationGraph(CRI SZ,E edge):VirtualGraph<T,T,CRI,E>(SZ,MO(edge)),m_LE(),m_memory(),m_memory_inv(){}TE <TY T,TY R1,TY R2,TY E> IN ret_t<E,T> VirtualGraph<T,R1,R2,E>::Edge(CO T& t){RE m_edge(t);}TE <TY E> IN CRI Graph<E>::Enumeration(CRI i){RE i;}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN ret_t<Enum_T,int> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::Enumeration(CRI i){RE m_enum_T(i);}TE <TY T,TY E> IN T MemorisationGraph<T,E>::Enumeration(CRI i){AS(0 <= i && i < m_LE);RE m_memory[i];}TE <TY E> IN CRI Graph<E>::Enumeration_inv(CRI i){RE i;}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN ret_t<Enum_T_inv,T> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::Enumeration_inv(CO T& t){RE m_enum_T_inv(t);}TE <TY T,TY E> IN CRI MemorisationGraph<T,E>::Enumeration_inv(CO T& t){if(m_memory_inv.count(t)== 0){AS(m_LE < TH->SZ());m_memory.push_back(t);RE m_memory_inv[t]= m_LE++;}RE m_memory_inv[t];}TE <TY T,TY R1,TY R2,TY E> VO VirtualGraph<T,R1,R2,E>::Reset(){}TE <TY T,TY E> IN VO MemorisationGraph<T,E>::Reset(){m_LE = 0;m_memory.clear();m_memory_inv.clear();}TE <TY E> TE <TY F> IN Graph<F> Graph<E>::GetGraph(F edge)CO{RE Graph<F>(TH->SZ(),MO(edge));}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> TE <TY F> IN EnumerationGraph<T,Enum_T,Enum_T_inv,F> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::GetGraph(F edge)CO{RE EnumerationGraph(TH->SZ(),m_enum_T,m_enum_T_inv,MO(edge));}TE <TY T,TY E> TE <TY F> IN MemorisationGraph<T,F> MemorisationGraph<T,E>::GetGraph(F edge)CO{RE MemorisationGraph(TH->SZ(),MO(edge));}

// ConstexprModulo
// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/compress.txt
CEXPR(uint,P,998244353);TE <uint M,TY INT> CE INT& RS(INT& n)NE{RE n < 0?((((++n)*= -1)%= M)*= -1)+= M - 1:n %= M;}TE <uint M> CE uint& RS(uint& n)NE{RE n %= M;}TE <uint M> CE ull& RS(ull& n)NE{RE n %= M;}TE <TY INT> CE INT& RSP(INT& n)NE{CE CO uint trunc =(1 << 23)- 1;INT n_u = n >> 23;n &= trunc;INT n_uq =(n_u / 7)/ 17;n_u -= n_uq * 119;n += n_u << 23;RE n < n_uq?n += P - n_uq:n -= n_uq;}TE <> CE ull& RS<P,ull>(ull& n)NE{CE CO ull Pull = P;CE CO ull Pull2 =(Pull - 1)*(Pull - 1);RE RSP(n > Pull2?n -= Pull2:n);}TE <uint M,TY INT> CE INT RS(INT&& n)NE{RE MO(RS<M>(n));}TE <uint M,TY INT> CE INT RS(CO INT& n)NE{RE RS<M>(INT(n));}

#define SFINAE_FOR_MOD(DEFAULT)TY T,enable_if_t<is_COructible<uint,decay_t<T>>::value>* DEFAULT
#define DC_OF_CM_FOR_MOD(FUNC)CE bool OP FUNC(CO Mod<M>& n)CO NE
#define DC_OF_AR_FOR_MOD(FUNC)CE Mod<M> OP FUNC(CO Mod<M>& n)CO NE;TE <SFINAE_FOR_MOD(= nullptr)> CE Mod<M> OP FUNC(T&& n)CO NE;
#define DF_OF_CM_FOR_MOD(FUNC)TE <uint M> CE bool Mod<M>::OP FUNC(CO Mod<M>& n)CO NE{RE m_n FUNC n.m_n;}
#define DF_OF_AR_FOR_MOD(FUNC,FORMULA)TE <uint M> CE Mod<M> Mod<M>::OP FUNC(CO Mod<M>& n)CO NE{RE MO(Mod<M>(*TH)FUNC ## = n);}TE <uint M> TE <SFINAE_FOR_MOD()> CE Mod<M> Mod<M>::OP FUNC(T&& n)CO NE{RE FORMULA;}TE <uint M,SFINAE_FOR_MOD(= nullptr)> CE Mod<M> OP FUNC(T&& n0,CO Mod<M>& n1)NE{RE MO(Mod<M>(forward<T>(n0))FUNC ## = n1);}

TE <uint M>CL Mod{PU:uint m_n;CE Mod()NE;CE Mod(CO Mod<M>& n)NE;CE Mod(Mod<M>& n)NE;CE Mod(Mod<M>&& n)NE;TE <SFINAE_FOR_MOD(= nullptr)> CE Mod(CO T& n)NE;TE <SFINAE_FOR_MOD(= nullptr)> CE Mod(T& n)NE;TE <SFINAE_FOR_MOD(= nullptr)> CE Mod(T&& n)NE;CE Mod<M>& OP=(CO Mod<M>& n)NE;CE Mod<M>& OP=(Mod<M>&& n)NE;CE Mod<M>& OP+=(CO Mod<M>& n)NE;CE Mod<M>& OP-=(CO Mod<M>& n)NE;CE Mod<M>& OP*=(CO Mod<M>& n)NE;IN Mod<M>& OP/=(CO Mod<M>& n);CE Mod<M>& OP<<=(int n)NE;CE Mod<M>& OP>>=(int n)NE;CE Mod<M>& OP++()NE;CE Mod<M> OP++(int)NE;CE Mod<M>& OP--()NE;CE Mod<M> OP--(int)NE;DC_OF_CM_FOR_MOD(==);DC_OF_CM_FOR_MOD(!=);DC_OF_CM_FOR_MOD(<);DC_OF_CM_FOR_MOD(<=);DC_OF_CM_FOR_MOD(>);DC_OF_CM_FOR_MOD(>=);DC_OF_AR_FOR_MOD(+);DC_OF_AR_FOR_MOD(-);DC_OF_AR_FOR_MOD(*);DC_OF_AR_FOR_MOD(/);CE Mod<M> OP<<(int n)CO NE;CE Mod<M> OP>>(int n)CO NE;CE Mod<M> OP-()CO NE;CE Mod<M>& SignInvert()NE;CE Mod<M>& Double()NE;CE Mod<M>& Halve()NE;IN Mod<M>& Invert();TE <TY T> CE Mod<M>& PositivePW(T&& EX)NE;TE <TY T> CE Mod<M>& NonNegativePW(T&& EX)NE;TE <TY T> CE Mod<M>& PW(T&& EX);CE VO swap(Mod<M>& n)NE;CE CRUI RP()CO NE;ST CE Mod<M> DeRP(CRUI n)NE;ST CE uint& Normalise(uint& n)NE;ST IN CO Mod<M>& Inverse(CRUI n)NE;ST IN CO Mod<M>& Factorial(CRUI n)NE;ST IN CO Mod<M>& FactorialInverse(CRUI n)NE;ST IN Mod<M> Combination(CRUI n,CRUI i)NE;ST IN CO Mod<M>& zero()NE;ST IN CO Mod<M>& one()NE;TE <TY T> CE Mod<M>& Ref(T&& n)NE;};

#define SFINAE_FOR_MN(DEFAULT)TY T,enable_if_t<is_COructible<Mod<M>,decay_t<T>>::value>* DEFAULT
#define DC_OF_AR_FOR_MN(FUNC)IN MN<M> OP FUNC(CO MN<M>& n)CO NE;TE <SFINAE_FOR_MOD(= nullptr)> IN MN<M> OP FUNC(T&& n)CO NE;
#define DF_OF_CM_FOR_MN(FUNC)TE <uint M> IN bool MN<M>::OP FUNC(CO MN<M>& n)CO NE{RE m_n FUNC n.m_n;}
#define DF_OF_AR_FOR_MN(FUNC,FORMULA)TE <uint M> IN MN<M> MN<M>::OP FUNC(CO MN<M>& n)CO NE{RE MO(MN<M>(*TH)FUNC ## = n);}TE <uint M> TE <SFINAE_FOR_MOD()> IN MN<M> MN<M>::OP FUNC(T&& n)CO NE{RE FORMULA;}TE <uint M,SFINAE_FOR_MOD(= nullptr)> IN MN<M> OP FUNC(T&& n0,CO MN<M>& n1)NE{RE MO(MN<M>(forward<T>(n0))FUNC ## = n1);}

TE <uint M>CL MN:PU Mod<M>{PU:CE MN()NE;CE MN(CO MN<M>& n)NE;CE MN(MN<M>& n)NE;CE MN(MN<M>&& n)NE;TE <SFINAE_FOR_MN(= nullptr)> CE MN(CO T& n)NE;TE <SFINAE_FOR_MN(= nullptr)> CE MN(T&& n)NE;CE MN<M>& OP=(CO MN<M>& n)NE;CE MN<M>& OP=(MN<M>&& n)NE;CE MN<M>& OP+=(CO MN<M>& n)NE;CE MN<M>& OP-=(CO MN<M>& n)NE;CE MN<M>& OP*=(CO MN<M>& n)NE;IN MN<M>& OP/=(CO MN<M>& n);CE MN<M>& OP<<=(int n)NE;CE MN<M>& OP>>=(int n)NE;CE MN<M>& OP++()NE;CE MN<M> OP++(int)NE;CE MN<M>& OP--()NE;CE MN<M> OP--(int)NE;DC_OF_AR_FOR_MN(+);DC_OF_AR_FOR_MN(-);DC_OF_AR_FOR_MN(*);DC_OF_AR_FOR_MN(/);CE MN<M> OP<<(int n)CO NE;CE MN<M> OP>>(int n)CO NE;CE MN<M> OP-()CO NE;CE MN<M>& SignInvert()NE;CE MN<M>& Double()NE;CE MN<M>& Halve()NE;CE MN<M>& Invert();TE <TY T> CE MN<M>& PositivePW(T&& EX)NE;TE <TY T> CE MN<M>& NonNegativePW(T&& EX)NE;TE <TY T> CE MN<M>& PW(T&& EX);CE uint RP()CO NE;CE Mod<M> Reduce()CO NE;ST CE MN<M> DeRP(CRUI n)NE;ST IN CO MN<M>& Formise(CRUI n)NE;ST IN CO MN<M>& Inverse(CRUI n)NE;ST IN CO MN<M>& Factorial(CRUI n)NE;ST IN CO MN<M>& FactorialInverse(CRUI n)NE;ST IN MN<M> Combination(CRUI n,CRUI i)NE;ST IN CO MN<M>& zero()NE;ST IN CO MN<M>& one()NE;ST CE uint Form(CRUI n)NE;ST CE ull& Reduction(ull& n)NE;ST CE ull& ReducedMU(ull& n,CRUI m)NE;ST CE uint MU(CRUI n0,CRUI n1)NE;ST CE uint BaseSquareTruncation(uint& n)NE;TE <TY T> CE MN<M>& Ref(T&& n)NE;};TE <uint M> CE MN<M> Twice(CO MN<M>& n)NE;TE <uint M> CE MN<M> Half(CO MN<M>& n)NE;TE <uint M> CE MN<M> Inverse(CO MN<M>& n);TE <uint M,TY T> CE MN<M> PW(MN<M> n,T EX);TE <TY T> CE MN<2> PW(CO MN<2>& n,CO T& p);TE <TY T> CE T Square(CO T& t);TE <> CE MN<2> Square<MN<2>>(CO MN<2>& t);TE <uint M> CE VO swap(MN<M>& n0,MN<M>& n1)NE;TE <uint M> IN string to_string(CO MN<M>& n)NE;TE<uint M,CL Traits> IN basic_istream<char,Traits>& OP>>(basic_istream<char,Traits>& is,MN<M>& n);TE<uint M,CL Traits> IN basic_ostream<char,Traits>& OP<<(basic_ostream<char,Traits>& os,CO MN<M>& n);

TE <uint M>CL COantsForMod{PU:COantsForMod()= delete;ST CE CO bool g_even =((M & 1)== 0);ST CE CO uint g_memory_bound = 1000000;ST CE CO uint g_memory_LE = M < g_memory_bound?M:g_memory_bound;ST CE ull MNBasePW(ull&& EX)NE;ST CE uint g_M_minus = M - 1;ST CE uint g_M_minus_2 = M - 2;ST CE uint g_M_minus_2_neg = 2 - M;ST CE CO int g_MN_digit = 32;ST CE CO ull g_MN_base = ull(1)<< g_MN_digit;ST CE CO uint g_MN_base_minus = uint(g_MN_base - 1);ST CE CO uint g_MN_digit_half =(g_MN_digit + 1)>> 1;ST CE CO uint g_MN_base_sqrt_minus =(1 << g_MN_digit_half)- 1;ST CE CO uint g_MN_M_neg_inverse = uint((g_MN_base - MNBasePW((ull(1)<<(g_MN_digit - 1))- 1))& g_MN_base_minus);ST CE CO uint g_MN_base_mod = uint(g_MN_base % M);ST CE CO uint g_MN_base_square_mod = uint(((g_MN_base % M)*(g_MN_base % M))% M);};TE <uint M> CE ull COantsForMod<M>::MNBasePW(ull&& EX)NE{ull prod = 1;ull PW = M;WH(EX != 0){(EX & 1)== 1?(prod *= PW)&= g_MN_base_minus:prod;EX >>= 1;(PW *= PW)&= g_MN_base_minus;}RE prod;}

US MP = Mod<P>;US MNP = MN<P>;TE <uint M> CE uint MN<M>::Form(CRUI n)NE{ull n_copy = n;RE uint(MO(Reduction(n_copy *= COantsForMod<M>::g_MN_base_square_mod)));}TE <uint M> CE ull& MN<M>::Reduction(ull& n)NE{ull n_sub = n & COantsForMod<M>::g_MN_base_minus;RE((n +=((n_sub *= COantsForMod<M>::g_MN_M_neg_inverse)&= COantsForMod<M>::g_MN_base_minus)*= M)>>= COantsForMod<M>::g_MN_digit)< M?n:n -= M;}TE <uint M> CE ull& MN<M>::ReducedMU(ull& n,CRUI m)NE{RE Reduction(n *= m);}TE <uint M> CE uint MN<M>::MU(CRUI n0,CRUI n1)NE{ull n0_copy = n0;RE uint(MO(ReducedMU(ReducedMU(n0_copy,n1),COantsForMod<M>::g_MN_base_square_mod)));}TE <uint M> CE uint MN<M>::BaseSquareTruncation(uint& n)NE{CO uint n_u = n >> COantsForMod<M>::g_MN_digit_half;n &= COantsForMod<M>::g_MN_base_sqrt_minus;RE n_u;}TE <uint M> CE MN<M>::MN()NE:Mod<M>(){ST_AS(! COantsForMod<M>::g_even);}TE <uint M> CE MN<M>::MN(CO MN<M>& n)NE:Mod<M>(n){}TE <uint M> CE MN<M>::MN(MN<M>& n)NE:Mod<M>(n){}TE <uint M> CE MN<M>::MN(MN<M>&& n)NE:Mod<M>(MO(n)){}TE <uint M> TE <SFINAE_FOR_MN()> CE MN<M>::MN(CO T& n)NE:Mod<M>(n){ST_AS(! COantsForMod<M>::g_even);Mod<M>::m_n = Form(Mod<M>::m_n);}TE <uint M> TE <SFINAE_FOR_MN()> CE MN<M>::MN(T&& n)NE:Mod<M>(forward<T>(n)){ST_AS(! COantsForMod<M>::g_even);Mod<M>::m_n = Form(Mod<M>::m_n);}TE <uint M> CE MN<M>& MN<M>::OP=(CO MN<M>& n)NE{RE Ref(Mod<M>::OP=(n));}TE <uint M> CE MN<M>& MN<M>::OP=(MN<M>&& n)NE{RE Ref(Mod<M>::OP=(MO(n)));}TE <uint M> CE MN<M>& MN<M>::OP+=(CO MN<M>& n)NE{RE Ref(Mod<M>::OP+=(n));}TE <uint M> CE MN<M>& MN<M>::OP-=(CO MN<M>& n)NE{RE Ref(Mod<M>::OP-=(n));}TE <uint M> CE MN<M>& MN<M>::OP*=(CO MN<M>& n)NE{ull m_n_copy = Mod<M>::m_n;RE Ref(Mod<M>::m_n = MO(ReducedMU(m_n_copy,n.m_n)));}TE <uint M> IN MN<M>& MN<M>::OP/=(CO MN<M>& n){RE OP*=(MN<M>(n).Invert());}TE <uint M> CE MN<M>& MN<M>::OP<<=(int n)NE{RE Ref(Mod<M>::OP<<=(n));}TE <uint M> CE MN<M>& MN<M>::OP>>=(int n)NE{RE Ref(Mod<M>::OP>>=(n));}TE <uint M> CE MN<M>& MN<M>::OP++()NE{RE Ref(Mod<M>::Normalise(Mod<M>::m_n += COantsForMod<M>::g_MN_base_mod));}TE <uint M> CE MN<M> MN<M>::OP++(int)NE{MN<M> n{*TH};OP++();RE n;}TE <uint M> CE MN<M>& MN<M>::OP--()NE{RE Ref(Mod<M>::m_n < COantsForMod<M>::g_MN_base_mod?((Mod<M>::m_n += M)-= COantsForMod<M>::g_MN_base_mod):Mod<M>::m_n -= COantsForMod<M>::g_MN_base_mod);}TE <uint M> CE MN<M> MN<M>::OP--(int)NE{MN<M> n{*TH};OP--();RE n;}DF_OF_AR_FOR_MN(+,MN<M>(forward<T>(n))+= *TH);DF_OF_AR_FOR_MN(-,MN<M>(forward<T>(n)).SignInvert()+= *TH);DF_OF_AR_FOR_MN(*,MN<M>(forward<T>(n))*= *TH);DF_OF_AR_FOR_MN(/,MN<M>(forward<T>(n)).Invert()*= *TH);TE <uint M> CE MN<M> MN<M>::OP<<(int n)CO NE{RE MO(MN<M>(*TH)<<= n);}TE <uint M> CE MN<M> MN<M>::OP>>(int n)CO NE{RE MO(MN<M>(*TH)>>= n);}TE <uint M> CE MN<M> MN<M>::OP-()CO NE{RE MO(MN<M>(*TH).SignInvert());}TE <uint M> CE MN<M>& MN<M>::SignInvert()NE{RE Ref(Mod<M>::m_n > 0?Mod<M>::m_n = M - Mod<M>::m_n:Mod<M>::m_n);}TE <uint M> CE MN<M>& MN<M>::Double()NE{RE Ref(Mod<M>::Double());}TE <uint M> CE MN<M>& MN<M>::Halve()NE{RE Ref(Mod<M>::Halve());}TE <uint M> CE MN<M>& MN<M>::Invert(){assert(Mod<M>::m_n > 0);RE PositivePW(uint(COantsForMod<M>::g_M_minus_2));}TE <uint M> TE <TY T> CE MN<M>& MN<M>::PositivePW(T&& EX)NE{MN<M> PW{*TH};(--EX)%= COantsForMod<M>::g_M_minus_2;WH(EX != 0){(EX & 1)== 1?OP*=(PW):*TH;EX >>= 1;PW *= PW;}RE *TH;}TE <uint M> TE <TY T> CE MN<M>& MN<M>::NonNegativePW(T&& EX)NE{RE EX == 0?Ref(Mod<M>::m_n = COantsForMod<M>::g_MN_base_mod):PositivePW(forward<T>(EX));}TE <uint M> TE <TY T> CE MN<M>& MN<M>::PW(T&& EX){bool neg = EX < 0;assert(!(neg && Mod<M>::m_n == 0));RE neg?PositivePW(forward<T>(EX *= COantsForMod<M>::g_M_minus_2_neg)):NonNegativePW(forward<T>(EX));}TE <uint M> CE uint MN<M>::RP()CO NE{ull m_n_copy = Mod<M>::m_n;RE MO(Reduction(m_n_copy));}TE <uint M> CE Mod<M> MN<M>::Reduce()CO NE{ull m_n_copy = Mod<M>::m_n;RE Mod<M>::DeRP(MO(Reduction(m_n_copy)));}TE <uint M> CE MN<M> MN<M>::DeRP(CRUI n)NE{RE MN<M>(Mod<M>::DeRP(n));}TE <uint M> IN CO MN<M>& MN<M>::Formise(CRUI n)NE{ST MN<M> memory[COantsForMod<M>::g_memory_LE] ={zero(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr] = DeRP(LE_curr);LE_curr++;}RE memory[n];}TE <uint M> IN CO MN<M>& MN<M>::Inverse(CRUI n)NE{ST MN<M> memory[COantsForMod<M>::g_memory_LE] ={zero(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr] = MN<M>(Mod<M>::Inverse(LE_curr));LE_curr++;}RE memory[n];}TE <uint M> IN CO MN<M>& MN<M>::Factorial(CRUI n)NE{ST MN<M> memory[COantsForMod<M>::g_memory_LE] ={one(),one()};ST uint LE_curr = 2;ST MN<M> val_curr{one()};ST MN<M> val_last{one()};WH(LE_curr <= n){memory[LE_curr++] = val_curr *= ++val_last;}RE memory[n];}TE <uint M> IN CO MN<M>& MN<M>::FactorialInverse(CRUI n)NE{ST MN<M> memory[COantsForMod<M>::g_memory_LE] ={one(),one()};ST uint LE_curr = 2;ST MN<M> val_curr{one()};ST MN<M> val_last{one()};WH(LE_curr <= n){memory[LE_curr] = val_curr *= Inverse(LE_curr);LE_curr++;}RE memory[n];}TE <uint M> IN MN<M> MN<M>::Combination(CRUI n,CRUI i)NE{RE i <= n?Factorial(n)*FactorialInverse(i)*FactorialInverse(n - i):zero();}TE <uint M> IN CO MN<M>& MN<M>::zero()NE{ST CE CO MN<M> z{};RE z;}TE <uint M> IN CO MN<M>& MN<M>::one()NE{ST CE CO MN<M> o{DeRP(1)};RE o;}TE <uint M> TE <TY T> CE MN<M>& MN<M>::Ref(T&& n)NE{RE *TH;}TE <uint M> CE MN<M> Twice(CO MN<M>& n)NE{RE MO(MN<M>(n).Double());}TE <uint M> CE MN<M> Half(CO MN<M>& n)NE{RE MO(MN<M>(n).Halve());}TE <uint M> CE MN<M> Inverse(CO MN<M>& n){RE MO(MN<M>(n).Invert());}TE <uint M,TY T> CE MN<M> PW(MN<M> n,T EX){RE MO(n.PW(EX));}TE <uint M> CE VO swap(MN<M>& n0,MN<M>& n1)NE{n0.swap(n1);}TE <uint M> IN string to_string(CO MN<M>& n)NE{RE to_string(n.RP())+ " + MZ";}TE<uint M,CL Traits> IN basic_istream<char,Traits>& OP>>(basic_istream<char,Traits>& is,MN<M>& n){ll m;is >> m;n = m;RE is;}TE<uint M,CL Traits> IN basic_ostream<char,Traits>& OP<<(basic_ostream<char,Traits>& os,CO MN<M>& n){RE os << n.RP();}

TE <uint M> CE Mod<M>::Mod()NE:m_n(){}TE <uint M> CE Mod<M>::Mod(CO Mod<M>& n)NE:m_n(n.m_n){}TE <uint M> CE Mod<M>::Mod(Mod<M>& n)NE:m_n(n.m_n){}TE <uint M> CE Mod<M>::Mod(Mod<M>&& n)NE:m_n(MO(n.m_n)){}TE <uint M> TE <SFINAE_FOR_MOD()> CE Mod<M>::Mod(CO T& n)NE:m_n(RS<M>(n)){}TE <uint M> TE <SFINAE_FOR_MOD()> CE Mod<M>::Mod(T& n)NE:m_n(RS<M>(decay_t<T>(n))){}TE <uint M> TE <SFINAE_FOR_MOD()> CE Mod<M>::Mod(T&& n)NE:m_n(RS<M>(forward<T>(n))){}TE <uint M> CE Mod<M>& Mod<M>::OP=(CO Mod<M>& n)NE{RE Ref(m_n = n.m_n);}TE <uint M> CE Mod<M>& Mod<M>::OP=(Mod<M>&& n)NE{RE Ref(m_n = MO(n.m_n));}TE <uint M> CE Mod<M>& Mod<M>::OP+=(CO Mod<M>& n)NE{RE Ref(Normalise(m_n += n.m_n));}TE <uint M> CE Mod<M>& Mod<M>::OP-=(CO Mod<M>& n)NE{RE Ref(m_n < n.m_n?(m_n += M)-= n.m_n:m_n -= n.m_n);}TE <uint M> CE Mod<M>& Mod<M>::OP*=(CO Mod<M>& n)NE{RE Ref(m_n = COantsForMod<M>::g_even?RS<M>(ull(m_n)* n.m_n):MN<M>::MU(m_n,n.m_n));}TE <> CE MP& MP::OP*=(CO MP& n)NE{ull m_n_copy = m_n;RE Ref(m_n = MO((m_n_copy *= n.m_n)< P?m_n_copy:RSP(m_n_copy)));}TE <uint M> IN Mod<M>& Mod<M>::OP/=(CO Mod<M>& n){RE OP*=(Mod<M>(n).Invert());}TE <uint M> CE Mod<M>& Mod<M>::OP<<=(int n)NE{WH(n-- > 0){Normalise(m_n <<= 1);}RE *TH;}TE <uint M> CE Mod<M>& Mod<M>::OP>>=(int n)NE{WH(n-- > 0){((m_n & 1)== 0?m_n:m_n += M)>>= 1;}RE *TH;}TE <uint M> CE Mod<M>& Mod<M>::OP++()NE{RE Ref(m_n < COantsForMod<M>::g_M_minus?++m_n:m_n = 0);}TE <uint M> CE Mod<M> Mod<M>::OP++(int)NE{Mod<M> n{*TH};OP++();RE n;}TE <uint M> CE Mod<M>& Mod<M>::OP--()NE{RE Ref(m_n == 0?m_n = COantsForMod<M>::g_M_minus:--m_n);}TE <uint M> CE Mod<M> Mod<M>::OP--(int)NE{Mod<M> n{*TH};OP--();RE n;}DF_OF_CM_FOR_MOD(==);DF_OF_CM_FOR_MOD(!=);DF_OF_CM_FOR_MOD(>);DF_OF_CM_FOR_MOD(>=);DF_OF_CM_FOR_MOD(<);DF_OF_CM_FOR_MOD(<=);DF_OF_AR_FOR_MOD(+,Mod<M>(forward<T>(n))+= *TH);DF_OF_AR_FOR_MOD(-,Mod<M>(forward<T>(n)).SignInvert()+= *TH);DF_OF_AR_FOR_MOD(*,Mod<M>(forward<T>(n))*= *TH);DF_OF_AR_FOR_MOD(/,Mod<M>(forward<T>(n)).Invert()*= *TH);TE <uint M> CE Mod<M> Mod<M>::OP<<(int n)CO NE{RE MO(Mod<M>(*TH)<<= n);}TE <uint M> CE Mod<M> Mod<M>::OP>>(int n)CO NE{RE MO(Mod<M>(*TH)>>= n);}TE <uint M> CE Mod<M> Mod<M>::OP-()CO NE{RE MO(Mod<M>(*TH).SignInvert());}TE <uint M> CE Mod<M>& Mod<M>::SignInvert()NE{RE Ref(m_n > 0?m_n = M - m_n:m_n);}TE <uint M> CE Mod<M>& Mod<M>::Double()NE{RE Ref(Normalise(m_n <<= 1));}TE <uint M> CE Mod<M>& Mod<M>::Halve()NE{RE Ref(((m_n & 1)== 0?m_n:m_n += M)>>= 1);}TE <uint M> IN Mod<M>& Mod<M>::Invert(){assert(m_n > 0);uint m_n_neg;RE m_n < COantsForMod<M>::g_memory_LE?Ref(m_n = Inverse(m_n).m_n):((m_n_neg = M - m_n)< COantsForMod<M>::g_memory_LE)?Ref(m_n = M - Inverse(m_n_neg).m_n):PositivePW(uint(COantsForMod<M>::g_M_minus_2));}TE <> IN Mod<2>& Mod<2>::Invert(){assert(m_n > 0);RE *TH;}TE <uint M> TE <TY T> CE Mod<M>& Mod<M>::PositivePW(T&& EX)NE{Mod<M> PW{*TH};EX--;WH(EX != 0){(EX & 1)== 1?OP*=(PW):*TH;EX >>= 1;PW *= PW;}RE *TH;}TE <> TE <TY T> CE Mod<2>& Mod<2>::PositivePW(T&& EX)NE{RE *TH;}TE <uint M> TE <TY T> CE Mod<M>& Mod<M>::NonNegativePW(T&& EX)NE{RE EX == 0?Ref(m_n = 1):Ref(PositivePW(forward<T>(EX)));}TE <uint M> TE <TY T> CE Mod<M>& Mod<M>::PW(T&& EX){bool neg = EX < 0;assert(!(neg && Mod<M>::m_n == 0));RE neg?PositivePW(forward<T>(EX *= COantsForMod<M>::g_M_minus_2_neg)):NonNegativePW(forward<T>(EX));}TE <uint M> IN CO Mod<M>& Mod<M>::Inverse(CRUI n)NE{ST Mod<M> memory[COantsForMod<M>::g_memory_LE] ={zero(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr].m_n = M - MN<M>::MU(memory[M % LE_curr].m_n,M / LE_curr);LE_curr++;}RE memory[n];}TE <uint M> IN CO Mod<M>& Mod<M>::Factorial(CRUI n)NE{ST Mod<M> memory[COantsForMod<M>::g_memory_LE] ={one(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr] = MN<M>::Factorial(LE_curr).Reduce();LE_curr++;}RE memory[n];}TE <uint M> IN CO Mod<M>& Mod<M>::FactorialInverse(CRUI n)NE{ST Mod<M> memory[COantsForMod<M>::g_memory_LE] ={one(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr] = MN<M>::FactorialInverse(LE_curr).Reduce();LE_curr++;}RE memory[n];}TE <uint M> IN Mod<M> Mod<M>::Combination(CRUI n,CRUI i)NE{RE MN<M>::Combination(n,i).Reduce();}TE <uint M> CE VO Mod<M>::swap(Mod<M>& n)NE{std::swap(m_n,n.m_n);}TE <uint M> CE CRUI Mod<M>::RP()CO NE{RE m_n;}TE <uint M> CE Mod<M> Mod<M>::DeRP(CRUI n)NE{Mod<M> n_copy{};n_copy.m_n = n;RE n_copy;}TE <uint M> CE uint& Mod<M>::Normalise(uint& n)NE{RE n < M?n:n -= M;}TE <uint M> IN CO Mod<M>& Mod<M>::zero()NE{ST CE CO Mod<M> z{};RE z;}TE <uint M> IN CO Mod<M>& Mod<M>::one()NE{ST CE CO Mod<M> o{DeRP(1)};RE o;}TE <uint M> TE <TY T> CE Mod<M>& Mod<M>::Ref(T&& n)NE{RE *TH;}TE <uint M> CE Mod<M> Twice(CO Mod<M>& n)NE{RE MO(Mod<M>(n).Double());}TE <uint M> CE Mod<M> Half(CO Mod<M>& n)NE{RE MO(Mod<M>(n).Halve());}TE <uint M> IN Mod<M> Inverse(CO Mod<M>& n){RE MO(Mod<M>(n).Invert());}TE <uint M> CE Mod<M> Inverse_COrexpr(CRUI n)NE{RE MO(Mod<M>::DeRP(RS<M>(n)).NonNegativePW(M - 2));}TE <uint M,TY T> CE Mod<M> PW(Mod<M> n,T EX){RE MO(n.PW(EX));}TE <TY T>CE Mod<2> PW(Mod<2> n,CO T& p){RE p == 0?Mod<2>::one():MO(n);}TE <uint M> CE VO swap(Mod<M>& n0,Mod<M>& n1)NE{n0.swap(n1);}TE <uint M> IN string to_string(CO Mod<M>& n)NE{RE to_string(n.RP())+ " + MZ";}TE<uint M,CL Traits> IN basic_istream<char,Traits>& OP>>(basic_istream<char,Traits>& is,Mod<M>& n){ll m;is >> m;n = m;RE is;}TE<uint M,CL Traits> IN basic_ostream<char,Traits>& OP<<(basic_ostream<char,Traits>& os,CO Mod<M>& n){RE os << n.RP();}

// IntervalAddBIT
// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/compress.txt
TE <TY T>CL BIT{PU:int m_SZ;VE<T> m_fenwick;int m_PW;IN BIT(CRI SZ = 0);BIT(CO VE<T>& a);IN BIT<T>& OP=(BIT<T>&& a);IN VO Set(CRI i,CO T& n);IN VO Set(CO VE<T>& a);IN VO Initialise(CRI SZ = 0);IN BIT<T>& OP+=(CO VE<T>& a);VO Add(CRI i,CO T& n);IN T OP[](CRI i)CO;IN T Get(CRI i)CO;IN CO T& LSBSegmentSum(CRI j)CO;T InitialSegmentSum(CRI i_final)CO;IN T IntervalSum(CRI i_start,CRI i_final)CO;IN CRI SZ()CO NE;int BinarySearch(CO T& n)CO;IN int BinarySearch(CRI i_start,CO T& n)CO;};
TE <TY T> IN BIT<T>::BIT(CRI SZ):m_SZ(SZ),m_fenwick(m_SZ+1),m_PW(1){ST_AS(! is_same<T,int>::value);WH(m_PW < m_SZ){m_PW <<= 1;}}TE <TY T>BIT<T>::BIT(CO VE<T>& a):BIT(a.SZ()){for(int j = 1;j <= m_SZ;j++){T& fenwick_j = m_fenwick[j];int i = j - 1;fenwick_j = a[i];int i_lim = j -(j & -j);WH(i > i_lim){fenwick_j += m_fenwick[i];i -=(i & -i);}}}TE <TY T> IN BIT<T>& BIT<T>::OP=(BIT<T>&& a){m_SZ = a.m_SZ;m_fenwick = MO(a.m_fenwick);m_PW = a.m_PW;RE *TH;}TE <TY T> IN VO BIT<T>::Set(CRI i,CO T& n){Add(i,n - IntervalSum(i,i));}TE <TY T> IN VO BIT<T>::Set(CO VE<T>& a){*TH = BIT<T>{a};}TE <TY T> IN VO BIT<T>::Initialise(CRI SZ){*TH = BIT<T>(SZ);}TE <TY T> IN BIT<T>& BIT<T>::OP+=(CO VE<T>&a){ BIT<T> a_copy{ a }; assert(m_SZ == a.m_SZ);for(int j = 1;j <= m_SZ;j++){m_fenwick[j] += a.m_fenwick[j];}RE *TH;}TE <TY T>VO BIT<T>::Add(CRI i,CO T& n){int j = i + 1;WH(j <= m_SZ){m_fenwick[j] += n;j +=(j & -j);}RE;}TE <TY T> IN T BIT<T>::OP[](CRI i)CO{assert(0 <= i && i < m_SZ);RE IntervalSum(i,i);}TE <TY T> IN T BIT<T>::Get(CRI i)CO{RE OP[](i);}TE <TY T> IN CO T& BIT<T>::LSBSegmentSum(CRI j)CO{assert(0 < j && j <= m_SZ);RE m_fenwick[j];}TE <TY T>T BIT<T>::InitialSegmentSum(CRI i_final)CO{T sum = 0;int j =(i_final < m_SZ?i_final:m_SZ - 1)+ 1;WH(j > 0){sum += m_fenwick[j];j -= j & -j;}RE sum;}TE <TY T> IN T BIT<T>::IntervalSum(CRI i_start,CRI i_final)CO{RE InitialSegmentSum(i_final)- InitialSegmentSum(i_start - 1);}TE <TY T>int BIT<T>::BinarySearch(CO T& n)CO{int PW = m_PW;int j = 0;T sum{};T sum_next{};WH(PW > 0){int j_next = j | PW;if(j_next < m_SZ){sum_next += m_fenwick[j_next];if(sum_next < n){sum = sum_next;j = j_next;}else{sum_next = sum;}}PW >>= 1;}RE j;}TE <TY T> IN CRI BIT<T>::SZ()CO NE{RE m_SZ;};TE <TY T> IN int BIT<T>::BinarySearch(CRI i_start,CO T& n)CO{RE max(i_start,BinarySearch(InitialSegmentSum(i_start)+ n));}

TE <TY T>CL IntervalAddBIT{PU:BIT<T> m_bit_0;BIT<T> m_bit_1;IN IntervalAddBIT(CRI SZ = 0);IN IntervalAddBIT(CO VE<T>& a);IN IntervalAddBIT<T>& OP=(IntervalAddBIT<T>&& a);IN VO Set(CRI i,CO T& n);IN VO Set(CO VE<T>& a);IN VO Initialise(CRI SZ = 0);IN IntervalAddBIT<T>& OP+=(CO VE<T>& a);IN VO Add(CRI i,CO T& n);IN VO IntervalAdd(CRI i_start,CRI i_final,CO T& n);IN T OP[](CRI i)CO;IN T Get(CRI i)CO;IN T InitialSegmentSum(CRI i_final)CO;IN T IntervalSum(CRI i_start,CRI i_final)CO;};
TE <TY T> IN IntervalAddBIT<T>::IntervalAddBIT(CRI SZ):m_bit_0(SZ),m_bit_1(SZ){}TE <TY T> IN IntervalAddBIT<T>::IntervalAddBIT(CO VE<T>& a):m_bit_0(),m_bit_1(){CO int SZ = a.SZ();VE<T> diff(SZ);diff[0]= a[0];for(int i = 1;i < SZ;i++){diff[i] = a[i] - a[i-1];}m_bit_0.Set(diff);for(int i = 1;i < SZ;i++){(diff[i]*= 1 - i)-= a[i];}m_bit_1.Set(diff);}TE <TY T> IN IntervalAddBIT<T>& IntervalAddBIT<T>::OP=(IntervalAddBIT<T>&& a){m_bit_0 = MO(a.m_bit_0);m_bit_1 = MO(a.m_bit_1);}TE <TY T> IN VO IntervalAddBIT<T>::Set(CRI i,CO T& n){Add(i,n - IntervalSum(i,i));}TE <TY T> IN VO IntervalAddBIT<T>::Set(CO VE<T>& a){*TH = IntervalAddBIT<T>(a);}TE <TY T> IN VO IntervalAddBIT<T>::Initialise(CRI SZ){m_bit_0.Initialise(SZ);m_bit_1.Initialise(SZ);}TE <TY T> IN IntervalAddBIT<T>& IntervalAddBIT<T>::OP+=(CO VE<T>& a){IntervalAddBIT<T> a_copy{a};CO int SZ = a.SZ();for(int i = 1;i < SZ;i++){m_bit_0[i] += a_copy.m_bit_0[i];m_bit_1[i] += a_copy.m_bit_1[i];}RE *TH;}TE <TY T> IN VO IntervalAddBIT<T>::Add(CRI i,CO T& n){IntervalAdd(i,i,n);}TE <TY T> IN VO IntervalAddBIT<T>::IntervalAdd(CRI i_start,CRI i_final,CO T& n){m_bit_0.Add(i_start,-(i_start - 1)* n);m_bit_0.Add(i_final + 1,i_final * n);m_bit_1.Add(i_start,n);m_bit_1.Add(i_final + 1,- n);}TE <TY T> IN T IntervalAddBIT<T>::OP[](CRI i)CO{assert(0 <= i && i < m_bit_0.SZ());RE IntervalSum(i,i);}TE <TY T> IN T IntervalAddBIT<T>::Get(CRI i)CO{RE OP[](i);}TE <TY T> IN T IntervalAddBIT<T>::InitialSegmentSum(CRI i_final)CO{RE m_bit_0.InitialSegmentSum(i_final)+ i_final * m_bit_1.InitialSegmentSum(i_final);}TE <TY T> IN T IntervalAddBIT<T>::IntervalSum(CRI i_start,CRI i_final)CO{RE InitialSegmentSum(i_final)- InitialSegmentSum(i_start - 1);}

// AAA 常設ライブラリは以上に挿入する。

#define INCLUDE_LIBRARY
#include __FILE__

#endif // INCLUDE_LIBRARY

#endif // INCLUDE_SUB

#endif // INCLUDE_MAIN
