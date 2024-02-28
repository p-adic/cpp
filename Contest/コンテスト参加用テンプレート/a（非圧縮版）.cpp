// 想定解に用いるので削除しない。
#ifndef INCLUDE_MODE
  #define INCLUDE_MODE
  // #define REACTIVE
  // #define USE_GETLINE
#endif

#ifdef INCLUDE_MAIN

inline void Solve()
{
  // // 数
  // // CEXPR( ll , bound_N , 1e5 ); CIN_ASSERT( N , 1 , bound_N );
  // CIN( ll , N , M , K );
  // ll answer = 0;
  // RETURN( answer );

  // // 配列
  // using value_type = ll;
  // // using value_type = MP;
  // CIN( int , N );
  // CIN_A( value_type , A , N ); CIN_A( value_type , B , N );
  // // vector<value_type> A( N ) , B( N ); FOR( i , 0 , N ){ cin >> A[i] >> B[i]; }

  // // 文字列
  // CIN( int , N ); CIN( string , S , T );

  // // 順列
  // CIN( int , N ); vector<int> A( N ) , A_inv( N );
  // FOR( i , 0 , N ){ cin >> A[i]; A_inv[--A[i]] = i; }
  
  // // グラフ
  // CIN( int , N , M );
  // // CIN( int , N ); int M = N - 1;
  // vector<list<int>> e( N );
  // // UnionFindForest uff{ N };
  // FOR( j , 0 , M ){
  //   CIN( int , uj , vj ); uj--; vj--;
  //   e[uj].push_back( vj ); e[vj].push_back( uj );
  //   // uff.Graft( uj , vj );
  // }
  // Graph graph{ N , Get( e ) };
  // BreadthFirstSearch bfs{ graph , 0 };
  // // DepthFirstSearchOnTree dfst{ graph , 0 };
  
  // // 重み付きグラフ
  // CIN( int , N , M );
  // // CIN( int , N ); int M = N - 1;
  // vector<list<path>> e( N );
  // // vector<vector<ll>> d( N ); FOR( i , 0 , N ){ d[i].resize( N , 1e18 ); d[i][i] = 0; }
  // // UnionFindForest uff{ N };
  // FOR( j , 0 , M ){
  //   CIN( ll , uj , vj , wj ); uj--; vj--;
  //   e[uj].push_back( { vj , wj } ); e[vj].push_back( { uj , wj } );
  //   // d[uj][vj] = d[vj][uj] = wj;
  //   // uff.Graft( uj , vj , wj );
  // }
  // auto edge = [&]( const int& i ){
  //   list<path> answer = e[i];
  //   return answer;
  // };
  // Graph graph{ N , edge };
  // Dijkstra dijk{ graph };
  // // vector<vector<ll>> weight; FloydWarshall( AdditiveTropicalSemirng( ll( 1e18 ) ) , d , weight );
 
  // // 一般のクエリ
  // CIN( int , Q );
  // // BIT t{ N };
  // // vector<T3<int>> query( Q );
  // FOR( q , 0 , Q ){
  //   CIN( ll , x , y ); x--; y--;
  //   // query[q] = { x , y , q };
  //   // CIN( int , type );
  //   // if( type == 1 ){
  //   //   CIN( ll , x , y ); x--; y--;
  //   //   t.Set( x , y );
  //   //   // query[q] = { type , x , y };
  //   // } else if( type == 2 ){
  //   //   CIN( ll , x , y ); x--; y--;
  //   //   // query[q] = { type , x , y };
  //   //   COUT( t.IntervalSum( x , y ) );
  //   // }
  // }
  // // sort( query.begin() , query.end() );
  // // Mo mo{ query };
  
  // // グリッド
  // // CEXPR( int , bound_H , 2e3 ); CEXPR( int , bound_W , bound_H );
  // // ST_AS( ll( bound_H ) * bound_W < ll( 1 ) << 31 );
  // // CEXPR( int , bound_HW , bound_H * bound_W );
  // // SET_ASSERT( H , 1 , bound_H ); SET_ASSERT( W , 1 , bound_W );
  // cin >> H >> W; H_minus = H - 1; W_minus = W - 1; HW = H * W;
  // vector<string> S( H );
  // // vector<list<int>> e( HW );
  // FOR( i , 0 , H ){
  //   cin >> S[i];
  //   // SetEdgeOnGrid( S[i] , i , e );
  //   // SetWallOnGrid( S[i] , i , non_wall );
  // }
  // // {i,j}へデコード: EnumHW( v )
  // // {i,j}をコード: EnumHW_inv( { i , j } );
  // // (i,j)->(k,h)の方向番号を取得: DirectionNumberOnGrid( i , j , k , h );
  // // v->wの方向番号を取得: DirectionNumberOnGrid( v , w );
  // // 方向番号の反転U<->D、R<->L: ReverseDirectionNumberOnGrid( n );
}
REPEAT_MAIN(1);

#else // INCLUDE_MAIN

#ifdef INCLUDE_SUB

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
inline void Experiment()
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
inline void SmallTest()
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

IntervalAddBIT
c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/compress.txt

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
  #define REPEAT_MAIN( BOUND ) START_MAIN; signal( SIGABRT , &AlertAbort ); AutoCheck( exec_mode , use_getline ); if( exec_mode == sample_debug_mode || exec_mode == submission_debug_mode || exec_mode == library_search_mode ){ return 0; } else if( exec_mode == experiment_mode ){ Experiment(); return 0; } else if( exec_mode == small_test_mode ){ SmallTest(); return 0; }; CEXPR( int , bound_test_case_num , BOUND ); int test_case_num = 1; if( exec_mode == solve_mode ){ if constexpr( bound_test_case_num > 1 ){ SET_ASSERT( test_case_num , 1 , bound_test_case_num ); } } else if( exec_mode == random_test_mode ){ CERR( "ランダムテストを行う回数を指定してください。" ); SET_LL( test_case_num ); } FINISH_MAIN
  #define ASSERT( A , MIN , MAX ) CERR( "ASSERTチェック： " , ( MIN ) , ( ( MIN ) <= A ? "<=" : ">" ) , A , ( A <= ( MAX ) ? "<=" : ">" ) , ( MAX ) ); assert( ( MIN ) <= A && A <= ( MAX ) )
  #define SET_ASSERT( A , MIN , MAX ) if( exec_mode == solve_mode ){ SET_LL( A ); ASSERT( A , MIN , MAX ); } else if( exec_mode == random_test_mode ){ CERR( #A , " = " , ( A = GetRand( MIN , MAX ) ) ); } else { assert( false ); }
  #define SOLVE_ONLY static_assert( __FUNCTION__[0] == 'S' )
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
  #define REPEAT_MAIN( BOUND ) START_MAIN; CEXPR( int , bound_test_case_num , BOUND ); int test_case_num = 1; if constexpr( bound_test_case_num > 1 ){ SET_ASSERT( test_case_num , 1 , bound_test_case_num ); } FINISH_MAIN
  #define ASSERT( A , MIN , MAX ) assert( ( MIN ) <= A && A <= ( MAX ) )
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
  #define SET_A( A , N ) SOLVE_ONLY; FOR( VARIABLE_FOR_SET_A , 0 , N ){ cin >> A[VARIABLE_FOR_SET_A]; }
  #define CIN_A( LL , A , N ) vector<LL> A( N ); SET_A( A , N );
#endif
#include <bits/stdc++.h>
using namespace std;
#define ATT __attribute__( ( target( "sse4.2,fma,avx2,popcnt,lzcnt,bmi2" ) ) )
#define START_MAIN int main(){ ios_base::sync_with_stdio( false ); cin.tie( nullptr )
#define FINISH_MAIN REPEAT( test_case_num ){ if constexpr( bound_test_case_num > 1 ){ CERR( "testcase " , VARIABLE_FOR_REPEAT_test_case_num , ":" ); } Solve(); CERR( "" ); } }
#define START_WATCH chrono::system_clock::time_point watch = chrono::system_clock::now()
#define CURRENT_TIME static_cast<double>( chrono::duration_cast<chrono::microseconds>( chrono::system_clock::now() - watch ).count() / 1000.0 )
#define CHECK_WATCH( TL_MS ) ( CURRENT_TIME < TL_MS - 100.0 )
#define CEXPR( LL , BOUND , VALUE ) constexpr LL BOUND = VALUE
#define SET_A_ASSERT( A , N , MIN , MAX ) FOR( VARIABLE_FOR_SET_A , 0 , N ){ SET_ASSERT( A[VARIABLE_FOR_SET_A] , MIN , MAX ); }
#define CIN_ASSERT( A , MIN , MAX ) decldecay_t( MAX ) A; SET_ASSERT( A , MIN , MAX )
#define FOR( VAR , INITIAL , FINAL_PLUS_ONE ) for( decldecay_t( FINAL_PLUS_ONE ) VAR = INITIAL ; VAR < FINAL_PLUS_ONE ; VAR ++ )
#define FOREQ( VAR , INITIAL , FINAL ) for( decldecay_t( FINAL ) VAR = INITIAL ; VAR <= FINAL ; VAR ++ )
#define FOREQINV( VAR , INITIAL , FINAL ) for( decldecay_t( INITIAL ) VAR = INITIAL ; VAR + 1 > FINAL ; VAR -- )
#define AUTO_ITR( ARRAY ) auto itr_ ## ARRAY = ARRAY .begin() , end_ ## ARRAY = ARRAY .end()
#define FOR_ITR( ARRAY ) for( AUTO_ITR( ARRAY ) , itr = itr_ ## ARRAY ; itr_ ## ARRAY != end_ ## ARRAY ; itr_ ## ARRAY ++ , itr++ )
#define REPEAT( HOW_MANY_TIMES ) FOR( VARIABLE_FOR_REPEAT_ ## HOW_MANY_TIMES , 0 , HOW_MANY_TIMES )
#define SET_PRECISION( DECIMAL_DIGITS ) cout << fixed << setprecision( DECIMAL_DIGITS )
#define OUTPUT_ARRAY( OS , A , N ) FOR( VARIABLE_FOR_OUTPUT_ARRAY , 0 , N ){ OS << A[VARIABLE_FOR_OUTPUT_ARRAY] << (VARIABLE_FOR_OUTPUT_ARRAY==N-1?"":" "); } OS
#define OUTPUT_ITR( OS , A ) { auto ITERATOR_FOR_OUTPUT_ITR = A.begin() , END_FOR_OUTPUT_ITR = A.end(); bool VARIABLE_FOR_OUTPUT_ITR = ITERATOR_FOR_COUT_ITR != END_FOR_COUT_ITR; while( VARIABLE_FOR_OUTPUT_ITR ){ OS << *ITERATOR_FOR_COUT_ITR; ( VARIABLE_FOR_OUTPUT_ITR = ++ITERATOR_FOR_COUT_ITR != END_FOR_COUT_ITR ) ? OS : OS << " "; } } OS
#define RETURN( ... ) SOLVE_ONLY; COUT( __VA_ARGS__ ); return
#define COMPARE( ... ) auto naive = Naive( __VA_ARGS__ ); auto answer = Answer( __VA_ARGS__ ); bool match = naive == answer; COUT( "(" , #__VA_ARGS__ , ") == (" , __VA_ARGS__ , ") : Naive == " , naive , match ? "==" : "!=" , answer , "== Answer" ); if( !match ){ return; }

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

// 入出力用
template <class Traits> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is ) { return is; }
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is , Arg& arg , ARGS&... args ) { return VariadicCin( is >> arg , args... ); }
template <class Traits> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator ) { return is; }
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator , Arg& arg , ARGS&... args ) { return VariadicGetline( getline( is , arg , separator ) , separator , args... ); }
template <class Traits , typename Arg> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const vector<Arg>& arg ) { auto begin = arg.begin() , end = arg.end(); auto itr = begin; while( itr != end ){ ( itr == begin ? os : os << " " ) << *itr; itr++; } return os; }
template <class Traits , typename Arg1 , typename Arg2> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const pair<Arg1,Arg2>& arg ) { return os << arg.first << " " << arg.second; }
template <class Traits , typename Arg> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , const Arg& arg ) { return os << arg; }
template <class Traits , typename Arg1 , typename Arg2 , typename... ARGS> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , const Arg1& arg1 , const Arg2& arg2 , const ARGS&... args ) { return VariadicCout( os << arg1 << " " , arg2 , args... ); }

// 算術用
template <typename T> constexpr T PositiveBaseResidue( const T& a , const T& p ){ return a >= 0 ? a % p : p - 1 - ( ( - ( a + 1 ) ) % p ); }
template <typename T> constexpr T Residue( const T& a , const T& p ){ return PositiveBaseResidue( a , p < 0 ? -p : p ); }
template <typename T> constexpr T PositiveBaseQuotient( const T& a , const T& p ){ return ( a - PositiveBaseResidue( a , p ) ) / p; }
template <typename T> constexpr T Quotient( const T& a , const T& p ){ return p < 0 ? PositiveBaseQuotient( -a , -p ) : PositiveBaseQuotient( a , p ); }

#define POWER( ANSWER , ARGUMENT , EXPONENT )				\
  static_assert( ! is_same<decldecay_t( ARGUMENT ),int>::value && ! is_same<decldecay_t( ARGUMENT ),uint>::value ); \
  decldecay_t( ARGUMENT ) ANSWER{ 1 };					\
  {									\
    decldecay_t( ARGUMENT ) ARGUMENT_FOR_SQUARE_FOR_POWER = ( ARGUMENT );	\
    decldecay_t( EXPONENT ) EXPONENT_FOR_SQUARE_FOR_POWER = ( EXPONENT );	\
    while( EXPONENT_FOR_SQUARE_FOR_POWER != 0 ){			\
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
    decldecay_t( EXPONENT ) EXPONENT_FOR_SQUARE_FOR_POWER = ( EXPONENT );	\
    while( EXPONENT_FOR_SQUARE_FOR_POWER != 0 ){			\
      if( EXPONENT_FOR_SQUARE_FOR_POWER % 2 == 1 ){			\
	ANSWER = ( ANSWER * ARGUMENT_FOR_SQUARE_FOR_POWER ) % ( MODULO ); \
      }									\
      ARGUMENT_FOR_SQUARE_FOR_POWER = ( ARGUMENT_FOR_SQUARE_FOR_POWER * ARGUMENT_FOR_SQUARE_FOR_POWER ) % ( MODULO ); \
      EXPONENT_FOR_SQUARE_FOR_POWER /= 2;				\
    }									\
  }									\

#define FACTORIAL_MOD( ANSWER , ANSWER_INV , INVERSE , MAX_INDEX , CONSTEXPR_LENGTH , MODULO ) \
  ll ANSWER[CONSTEXPR_LENGTH];						\
  ll ANSWER_INV[CONSTEXPR_LENGTH];					\
  ll INVERSE[CONSTEXPR_LENGTH];						\
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
// EXPRESSIONがANSWERの広義単調関数の時、EXPRESSION >= CONST_TARGETの整数解を格納。
#define BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , DESIRED_INEQUALITY , CONST_TARGET , INEQUALITY_FOR_CHECK , UPDATE_U , UPDATE_L , UPDATE_ANSWER ) \
  static_assert( ! is_same<decldecay_t( CONST_TARGET ),uint>::value && ! is_same<decldecay_t( CONST_TARGET ),ull>::value ); \
  ll ANSWER = MINIMUM;							\
  {									\
    ll L_BS = MINIMUM;							\
    ll U_BS = MAXIMUM;							\
    ANSWER = UPDATE_ANSWER;						\
    ll EXPRESSION_BS;							\
    const ll CONST_TARGET_BS = ( CONST_TARGET );			\
    ll DIFFERENCE_BS;							\
    while( L_BS < U_BS ){						\
      DIFFERENCE_BS = ( EXPRESSION_BS = ( EXPRESSION ) ) - CONST_TARGET_BS; \
      CERR( "二分探索中：" , "L_BS =" , L_BS , "<=" , #ANSWER , "=" , ANSWER , "<=" , U_BS , "= U_BS :" , #EXPRESSION , "-" , #CONST_TARGET , "=" , EXPRESSION_BS , "-" , CONST_TARGET_BS , "=" , DIFFERENCE_BS ); \
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
      CERR( "二分探索結果：" , #EXPRESSION , "=" , EXPRESSION_BS , ( EXPRESSION_BS > CONST_TARGET_BS ? ">" : EXPRESSION_BS < CONST_TARGET_BS ? "<" : "=" ) , CONST_TARGET_BS ); \
      if( EXPRESSION_BS DESIRED_INEQUALITY CONST_TARGET_BS ){		\
	CERR( "二分探索成功：" , #ANSWER , ":=" , ANSWER );		\
      } else {								\
	CERR( "二分探索失敗：" , #ANSWER , ":=" , #MAXIMUM , "+ 1 =" , MAXIMUM + 1 ); \
	CERR( "単調でないか、単調増加性と単調減少性を逆にしてしまったか、探索範囲内に解が存在しません。" ); \
	ANSWER = MAXIMUM + 1;						\
      }									\
    }									\
  }									\

// 単調増加の時にEXPRESSION >= CONST_TARGETの最小解を格納。
#define BS1( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CONST_TARGET , >= , ANSWER , ANSWER + 1 , ( L_BS + U_BS ) / 2 )
// 単調増加の時にEXPRESSION <= CONST_TARGETの最大解を格納。
#define BS2( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CONST_TARGET , > , ANSWER - 1 , ANSWER , ( L_BS + 1 + U_BS ) / 2 )
// 単調減少の時にEXPRESSION >= CONST_TARGETの最大解を格納。
#define BS3( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CONST_TARGET , < , ANSWER - 1 , ANSWER , ( L_BS + 1 + U_BS ) / 2 )
// 単調減少の時にEXPRESSION <= CONST_TARGETの最小解を格納。
#define BS4( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CONST_TARGET , <= , ANSWER , ANSWER + 1 , ( L_BS + U_BS ) / 2 )
// t以下の値が存在すればその最大値のiterator、存在しなければend()を返す。
template <typename T> inline typename set<T>::iterator MaximumLeq( set<T>& S , const T& t ) { const auto end = S.end(); if( S.empty() ){ return end; } auto itr = S.upper_bound( t ); return itr == end ? S.find( *( S.rbegin() ) ) : itr == S.begin() ? end : --itr; }
// t未満の値が存在すればその最大値のiterator、存在しなければend()を返す。
template <typename T> inline typename set<T>::iterator MaximumLt( set<T>& S , const T& t ) { const auto end = S.end(); if( S.empty() ){ return end; } auto itr = S.lower_bound( t ); return itr == end ? S.find( *( S.rbegin() ) ) : itr == S.begin() ? end : --itr; }
// t以上の値が存在すればその最小値のiterator、存在しなければend()を返す。
template <typename T> inline typename set<T>::iterator MinimumGeq( set<T>& S , const T& t ) { return S.lower_bound( t ); }
// tより大きい値が存在すればその最小値のiterator、存在しなければend()を返す。
template <typename T> inline typename set<T>::iterator MinimumGt( set<T>& S , const T& t ) { return S.upper_bound( t ); }

// 尺取り法用
// VAR_TPAがINITからUPDATEを繰り返しCONTINUE_CONDITIONを満たす限り、ON_CONDITIONを判定して
// trueならON、falseならOFFとなる。直近のONの区間を[VAR_TPA_L,VAR_TPA_R)で管理する。
#define TPA( VAR_TPA , INIT , UPDATE , CONTINUE_CONDITION , ON_CONDITION , ONON , ONOFF , OFFON , OFFOFF , FINISH ) \
  {									\
    auto VAR_TPA = INIT;						\
    auto VAR_TPA ## _L = VAR_TPA;					\
    auto VAR_TPA ## _R = VAR_TPA;					\
    bool on_TPA = false;						\
    int state_TPA = 3;							\
    while( CONTINUE_CONDITION ){					\
      bool on_TPA_next = ON_CONDITION;					\
      state_TPA = ( ( on_TPA ? 1 : 0 ) << 1 ) | ( on_TPA_next ? 1 : 0 ); \
      CERR( "尺取り中： [L,R) = [" , VAR_TPA ## _L , "," , VAR_TPA ## _R , ") ," , #VAR_TPA , "=" , VAR_TPA , "," , ( ( state_TPA >> 1 ) & 1 ) == 1 ? "on" : "off" , " ->" , ( state_TPA & 1 ) == 1 ? "on" : "off" ); \
      if( state_TPA == 0 ){						\
	OFFOFF; VAR_TPA ## _L = VAR_TPA ## _R = VAR_TPA; UPDATE;	\
      } else if( state_TPA == 1 ){					\
	OFFON; VAR_TPA ## _L = VAR_TPA; UPDATE; VAR_TPA ## _R = VAR_TPA; \
      } else if( state_TPA == 2 ){					\
	ONOFF; VAR_TPA ## _L = VAR_TPA ## _R = VAR_TPA; UPDATE;		\
      } else {								\
	ONON; UPDATE; VAR_TPA ## _R = VAR_TPA;				\
      }									\
      on_TPA = on_TPA_next;						\
    }									\
    CERR( "尺取り終了： [L,R) = [" , VAR_TPA ## _L , "," , VAR_TPA ## _R , ") ," , #VAR_TPA , "=" , VAR_TPA ); \
    FINISH;								\
  }									\

// データ構造用
template <typename T , template <typename...> typename V> inline V<T> operator+( const V<T>& a0 , const V<T>& a1 ) { if( a0.empty() ){ return a1; } if( a1.empty() ){ return a0; } assert( a0.size() == a1.size() ); V<T> answer{}; for( auto itr0 = a0.begin() , itr1 = a1.begin() , end0 = a0.end(); itr0 != end0 ; itr0++ , itr1++ ){ answer.push_back( *itr0 + *itr1 ); } return answer; }
template <typename T , typename U> inline pair<T,U> operator+( const pair<T,U>& t0 , const pair<T,U>& t1 ) { return { t0.first + t1.first , t0.second + t1.second }; }
template <typename T , typename U , typename V> inline tuple<T,U,V> operator+( const tuple<T,U,V>& t0 , const tuple<T,U,V>& t1 ) { return { get<0>( t0 ) + get<0>( t1 ) , get<1>( t0 ) + get<1>( t1 ) , get<2>( t0 ) + get<2>( t1 ) }; }
template <typename T , typename U , typename V , typename W> inline tuple<T,U,V,W> operator+( const tuple<T,U,V,W>& t0 , const tuple<T,U,V,W>& t1 ) { return { get<0>( t0 ) + get<0>( t1 ) , get<1>( t0 ) + get<1>( t1 ) , get<2>( t0 ) + get<2>( t1 ) , get<3>( t0 ) + get<3>( t1 ) }; }
template <typename T> inline T Add( const T& t0 , const T& t1 ) { return t0 + t1; }
template <typename T> inline T XorAdd( const T& t0 , const T& t1 ){ return t0 ^ t1; }
template <typename T> inline T Multiply( const T& t0 , const T& t1 ) { return t0 * t1; }
template <typename T> inline const T& Zero() { static const T z{}; return z; }
template <typename T> inline const T& One() { static const T o = 1; return o; }\
template <typename T> inline T AddInv( const T& t ) { return -t; }
template <typename T> inline T Id( const T& v ) { return v; }
template <typename T> inline T Min( const T& a , const T& b ){ return a < b ? a : b; }
template <typename T> inline T Max( const T& a , const T& b ){ return a < b ? b : a; }

// グラフ用
template <typename T , template <typename...> typename V> inline auto Get( const V<T>& a ) { return [&]( const int& i = 0 ){ return a[i]; }; }

// グリッド問題用
int H , W , H_minus , W_minus , HW;
vector<vector<bool> > non_wall;
inline T2<int> EnumHW( const int& v ) { return { v / W , v % W }; }
inline int EnumHW_inv( const T2<int>& ij ) { auto& [i,j] = ij; return i * W + j; }
const string direction[4] = {"U","R","D","L"};
// (i,j)->(k,h)の方向番号を取得
inline int DirectionNumberOnGrid( const int& i , const int& j , const int& k , const int& h ){return i<k?2:i>k?0:j<h?1:j>h?3:(assert(false),-1);}
// v->wの方向番号を取得
inline int DirectionNumberOnGrid( const int& v , const int& w ){auto [i,j]=EnumHW(v);auto [k,h]=EnumHW(w);return DirectionNumberOnGrid(i,j,k,h);}
// 方向番号の反転U<->D、R<->L
inline int ReverseDirectionNumberOnGrid( const int& n ){assert(0<=n&&n<4);return(n+2)%4;}
inline void SetEdgeOnGrid( const string& Si , const int& i , vector<list<int>>& e , const char& walkable = '.' ){FOR(j,0,W){if(Si[j]==walkable){int v = EnumHW_inv({i,j});if(i>0){e[EnumHW_inv({i-1,j})].push_back(v);}if(i+1<H){e[EnumHW_inv({i+1,j})].push_back(v);}if(j>0){e[EnumHW_inv({i,j-1})].push_back(v);}if(j+1<W){e[EnumHW_inv({i,j+1})].push_back(v);}}}}
inline void SetEdgeOnGrid( const string& Si , const int& i , vector<list<path>>& e , const char& walkable = '.' ){FOR(j,0,W){if(Si[j]==walkable){const int v=EnumHW_inv({i,j});if(i>0){e[EnumHW_inv({i-1,j})].push_back({v,1});}if(i+1<H){e[EnumHW_inv({i+1,j})].push_back({v,1});}if(j>0){e[EnumHW_inv({i,j-1})].push_back({v,1});}if(j+1<W){e[EnumHW_inv({i,j+1})].push_back({v,1});}}}}
inline void SetWallOnGrid( const string& Si , const int& i , vector<vector<bool> >& non_wall , const char& walkable = '.'  , const char& unwalkable = '#' ){non_wall.push_back(vector<bool>(W));auto& non_wall_i=non_wall[i];FOR(j,0,W){non_wall_i[j]=Si[j]==walkable?true:(assert(Si[j]==unwalkable),false);}}

// デバッグ用
#ifdef DEBUG
  inline void AlertAbort( int n ) { CERR( "abort関数が呼ばれました。assertマクロのメッセージが出力されていない場合はオーバーフローの有無を確認をしてください。" ); }
  void AutoCheck( int& exec_mode , const bool& use_getline );
  inline void Solve();
  inline void Experiment();
  inline void SmallTest();
  inline void RandomTest();
  ll GetRand( const ll& Rand_min , const ll& Rand_max );
  inline void BreakPoint( const int& LINE ) {}
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
  ll GetRand( const ll& Rand_min , const ll& Rand_max ) { ll answer = time( NULL ); return answer * rand() % ( Rand_max + 1 - Rand_min ) + Rand_min; }
#endif

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

// VVV 常設ライブラリは以下に挿入する。
// Map
// c:/Users/user/Documents/Programming/Mathematics/Function/Map/compress.txt
CL is_ordered{PU:is_ordered()= delete;TE <TY T> ST CE auto Check(CO T& t)-> decltype(t < t,true_type());ST CE false_type Check(...);TE <TY T> ST CE CO bool value = is_same_v< decltype(Check(declval<T>())),true_type >;};
TE <TY T , TY U>US Map = conditional_t<is_COructible_v<unordered_map<T,int>>,unordered_map<T,U>,conditional_t<is_ordered::value<T>,map<T,U>,VO>>;

// Algebra
// c:/Users/user/Documents/Programming/Mathematics/Algebra/compress.txt
#define DC_OF_CPOINT(POINT)IN CO U& POINT()CO NE
#define DC_OF_POINT(POINT)IN U& POINT()NE
#define DF_OF_CPOINT(POINT)TE <TY U> IN CO U& VirtualPointedSet<U>::POINT()CO NE{RE Point();}
#define DF_OF_POINT(POINT)TE <TY U> IN U& VirtualPointedSet<U>::POINT()NE{RE Point();}
TE <TY U>CL UnderlyingSet{PU:US type = U;};TE <TY U>CL VirtualPointedSet:VI PU UnderlyingSet<U>{PU:VI CO U& Point()CO NE = 0;VI U& Point()NE = 0;DC_OF_CPOINT(Unit);DC_OF_CPOINT(Zero);DC_OF_CPOINT(One);DC_OF_CPOINT(Infty);DC_OF_POINT(init);DC_OF_POINT(root);};TE <TY U>CL PointedSet:VI PU VirtualPointedSet<U>{PU:U m_b_U;IN PointedSet(CO U& b_u = U());IN CO U& Point()CO NE;IN U& Point()NE;};TE <TY U>CL VirtualNSet:VI PU UnderlyingSet<U>{PU:VI U Transfer(CO U& u)= 0;IN U Inverse(CO U& u);};TE <TY U,TY F_U>CL AbstractNSet:VI PU VirtualNSet<U>{PU:F_U m_f_U;IN AbstractNSet(F_U f_U);IN U Transfer(CO U& u);};TE <TY U>CL VirtualMagma:VI PU UnderlyingSet<U>{PU:VI U Product(CO U& u0,CO U& u1)= 0;IN U Sum(CO U& u0,CO U& u1);};TE <TY U = ll>CL AdditiveMagma:VI PU VirtualMagma<U>{PU:IN U Product(CO U& u0,CO U& u1);};TE <TY U = ll>CL MultiplicativeMagma:VI PU VirtualMagma<U>{PU:IN U Product(CO U& u0,CO U& u1);};TE <TY U,TY M_U>CL AbstractMagma:VI PU VirtualMagma<U>{PU:M_U m_m_U;IN AbstractMagma(M_U m_U);IN U Product(CO U& u0,CO U& u1);};
TE <TY U> IN PointedSet<U>::PointedSet(CO U& b_U):m_b_U(b_U){}TE <TY U> IN CO U& PointedSet<U>::Point()CO NE{RE m_b_U;}TE <TY U> IN U& PointedSet<U>::Point()NE{RE m_b_U;}DF_OF_CPOINT(Unit);DF_OF_CPOINT(Zero);DF_OF_CPOINT(One);DF_OF_CPOINT(Infty);DF_OF_POINT(init);DF_OF_POINT(root);TE <TY U,TY F_U> IN AbstractNSet<U,F_U>::AbstractNSet(F_U f_U):m_f_U(MO(f_U)){ST_AS(is_invocable_r_v<U,F_U,U>);}TE <TY U,TY F_U> IN U AbstractNSet<U,F_U>::Transfer(CO U& u){RE m_f_U(u);}TE <TY U> IN U VirtualNSet<U>::Inverse(CO U& u){RE Transfer(u);}TE <TY U,TY M_U> IN AbstractMagma<U,M_U>::AbstractMagma(M_U m_U):m_m_U(MO(m_U)){ST_AS(is_invocable_r_v<U,M_U,U,U>);}TE <TY U> IN U AdditiveMagma<U>::Product(CO U& u0,CO U& u1){RE u0 + u1;}TE <TY U> IN U MultiplicativeMagma<U>::Product(CO U& u0,CO U& u1){RE u0 * u1;}TE <TY U,TY M_U> IN U AbstractMagma<U,M_U>::Product(CO U& u0,CO U& u1){RE m_m_U(u0,u1);}TE <TY U> IN U VirtualMagma<U>::Sum(CO U& u0,CO U& u1){RE Product(u0,u1);}

TE <TY U>CL VirtualMonoid:VI PU VirtualMagma<U>,VI PU VirtualPointedSet<U>{};TE <TY U = ll>CL AdditiveMonoid:VI PU VirtualMonoid<U>,PU AdditiveMagma<U>,PU PointedSet<U>{};TE <TY U = ll>CL MultiplicativeMonoid:VI PU VirtualMonoid<U>,PU MultiplicativeMagma<U>,PU PointedSet<U>{PU:IN MultiplicativeMonoid(CO U& e_U);};TE <TY U,TY M_U>CL AbstractMonoid:VI PU VirtualMonoid<U>,PU AbstractMagma<U,M_U>,PU PointedSet<U>{PU:IN AbstractMonoid(M_U m_U,CO U& e_U);};
TE <TY U> IN MultiplicativeMonoid<U>::MultiplicativeMonoid(CO U& e_U):PointedSet<U>(e_U){}TE <TY U,TY M_U> IN AbstractMonoid<U,M_U>::AbstractMonoid(M_U m_U,CO U& e_U):AbstractMagma<U,M_U>(MO(m_U)),PointedSet<U>(e_U){}

TE <TY U>CL VirtualGroup:VI PU VirtualMonoid<U>,VI PU VirtualPointedSet<U>,VI PU VirtualNSet<U>{};TE <TY U = ll>CL AdditiveGroup:VI PU VirtualGroup<U>,PU AdditiveMonoid<U>{PU:IN U Transfer(CO U& u);};TE <TY U,TY M_U,TY I_U>CL AbstractGroup:VI PU VirtualGroup<U>,PU AbstractMonoid<U,M_U>,PU AbstractNSet<U,I_U>{PU:IN AbstractGroup(M_U m_U,CO U& e_U,I_U i_U);};
TE <TY U,TY M_U,TY I_U> IN AbstractGroup<U,M_U,I_U>::AbstractGroup(M_U m_U,CO U& e_U,I_U i_U):AbstractMonoid<U,M_U>(MO(m_U),e_U),AbstractNSet<U,I_U>(MO(i_U)){}TE <TY U> IN U AdditiveGroup<U>::Transfer(CO U& u){RE -u;}

// Graph
// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/compress.txt
TE <TY T,TY R1,TY R2,TY E>CL VirtualGraph:VI PU UnderlyingSet<T>{PU:VI R1 Enumeration(CRI i)= 0;VI R2 Enumeration_inv(CO T& t)= 0;IN VO Reset();VI CRI SZ()CO NE = 0;VI E& edge()NE = 0;VI ret_t<E,T> Edge(CO T& t)= 0;};TE <TY T,TY R1,TY R2,TY E>CL EdgeImplimentation:VI PU VirtualGraph<T,R1,R2,E>{PU:int m_SZ;E m_edge;IN EdgeImplimentation(CRI SZ,E edge);IN CRI SZ()CO NE;IN E& edge()NE;IN ret_t<E,T> Edge(CO T& t);};TE <TY E>CL Graph:PU EdgeImplimentation<int,CRI,CRI,E>{PU:IN Graph(CRI SZ,E edge);IN CRI Enumeration(CRI i);IN CRI Enumeration_inv(CRI t);TE <TY F> IN Graph<F> GetGraph(F edge)CO;};TE <TY T,TY Enum_T,TY Enum_T_inv,TY E>CL EnumerationGraph:PU EdgeImplimentation<T,ret_t<Enum_T,int>,ret_t<Enum_T_inv,T>,E>{PU:Enum_T m_enum_T;Enum_T_inv m_enum_T_inv;IN EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge);IN ret_t<Enum_T,int> Enumeration(CRI i);IN ret_t<Enum_T_inv,T> Enumeration_inv(CO T& t);TE <TY F> IN EnumerationGraph<T,Enum_T,Enum_T_inv,F> GetGraph(F edge)CO;};TE <TY Enum_T,TY Enum_T_inv,TY E> EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge)-> EnumerationGraph<decldecay_t(declval<Enum_T>()(0)),Enum_T,Enum_T_inv,E>;TE <TY T,TY E>CL MemorisationGraph:PU EdgeImplimentation<T,T,CRI,E>{PU:int m_LE;VE<T> m_memory;Map<T,int> m_memory_inv;IN MemorisationGraph(CRI SZ,E edge);IN T Enumeration(CRI i);IN CRI Enumeration_inv(CO T& t);IN VO Reset();TE <TY F> IN MemorisationGraph<T,F> GetGraph(F edge)CO;};TE <TY E> MemorisationGraph(CRI SZ,E edge)-> MemorisationGraph<decldecay_t(declval<E>()().back()),E>;TE <TY E> MemorisationGraph(CRI SZ,E edge)-> MemorisationGraph<decldecay_t(get<0>(declval<E>()().back())),E>;
TE <TY T,TY R1,TY R2,TY E> IN EdgeImplimentation<T,R1,R2,E>::EdgeImplimentation(CRI SZ,E edge):m_SZ(SZ),m_edge(MO(edge)){ST_AS(is_COructible_v<T,R1> && is_COructible_v<int,R2> && is_invocable_v<E,T>);}TE <TY E> IN Graph<E>::Graph(CRI SZ,E edge):EdgeImplimentation<int,CRI,CRI,E>(SZ,MO(edge)){}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN EnumerationGraph<T,Enum_T,Enum_T_inv,E>::EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge):EdgeImplimentation<T,ret_t<Enum_T,int>,ret_t<Enum_T_inv,T>,E>(SZ,MO(edge)),m_enum_T(MO(enum_T)),m_enum_T_inv(MO(enum_T_inv)){}TE <TY T,TY E> IN MemorisationGraph<T,E>::MemorisationGraph(CRI SZ,E edge):EdgeImplimentation<T,T,CRI,E>(SZ,MO(edge)),m_LE(),m_memory(),m_memory_inv(){ST_AS(is_invocable_v<E> && is_invocable_v<E,T>);}TE <TY E> IN CRI Graph<E>::Enumeration(CRI i){RE i;}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN ret_t<Enum_T,int> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::Enumeration(CRI i){RE m_enum_T(i);}TE <TY T,TY E> IN T MemorisationGraph<T,E>::Enumeration(CRI i){AS(0 <= i && i < m_LE);RE m_memory[i];}TE <TY E> IN CRI Graph<E>::Enumeration_inv(CRI i){RE i;}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN ret_t<Enum_T_inv,T> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::Enumeration_inv(CO T& t){RE m_enum_T_inv(t);}TE <TY T,TY E> IN CRI MemorisationGraph<T,E>::Enumeration_inv(CO T& t){if(m_memory_inv.count(t)== 0){AS(m_LE < TH->SZ());m_memory.push_back(t);RE m_memory_inv[t]= m_LE++;}RE m_memory_inv[t];}TE <TY T,TY R1,TY R2,TY E> VO VirtualGraph<T,R1,R2,E>::Reset(){}TE <TY T,TY E> IN VO MemorisationGraph<T,E>::Reset(){m_LE = 0;m_memory.clear();m_memory_inv.clear();}TE <TY T,TY R1,TY R2,TY E> IN CRI EdgeImplimentation<T,R1,R2,E>::SZ()CO NE{RE m_SZ;}TE <TY T,TY R1,TY R2,TY E> IN E& EdgeImplimentation<T,R1,R2,E>::edge()NE{RE m_edge;}TE <TY T,TY R1,TY R2,TY E> IN ret_t<E,T> EdgeImplimentation<T,R1,R2,E>::Edge(CO T& t){RE m_edge(t);}TE <TY E> TE <TY F> IN Graph<F> Graph<E>::GetGraph(F edge)CO{RE Graph<F>(TH->SZ(),MO(edge));}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> TE <TY F> IN EnumerationGraph<T,Enum_T,Enum_T_inv,F> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::GetGraph(F edge)CO{RE EnumerationGraph(TH->SZ(),m_enum_T,m_enum_T_inv,MO(edge));}TE <TY T,TY E> TE <TY F> IN MemorisationGraph<T,F> MemorisationGraph<T,E>::GetGraph(F edge)CO{RE MemorisationGraph(TH->SZ(),MO(edge));}

// ConstexprModulo
// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/compress.txt
CEXPR(uint,P,998244353);TE <uint M,TY INT> CE INT& RS(INT& n)NE{RE n < 0?((((++n)*= -1)%= M)*= -1)+= M - 1:n %= M;}TE <uint M> CE uint& RS(uint& n)NE{RE n %= M;}TE <uint M> CE ull& RS(ull& n)NE{RE n %= M;}TE <TY INT> CE INT& RSP(INT& n)NE{CE CO uint trunc =(1 << 23)- 1;INT n_u = n >> 23;n &= trunc;INT n_uq =(n_u / 7)/ 17;n_u -= n_uq * 119;n += n_u << 23;RE n < n_uq?n += P - n_uq:n -= n_uq;}TE <> CE ull& RS<P,ull>(ull& n)NE{CE CO ull Pull = P;CE CO ull Pull2 =(Pull - 1)*(Pull - 1);RE RSP(n > Pull2?n -= Pull2:n);}TE <uint M,TY INT> CE INT RS(INT&& n)NE{RE MO(RS<M>(n));}TE <uint M,TY INT> CE INT RS(CO INT& n)NE{RE RS<M>(INT(n));}

#define SFINAE_FOR_MOD(DEFAULT)TY T,enable_if_t<is_COructible_v<uint,decay_t<T>>>* DEFAULT
#define DC_OF_CM_FOR_MOD(FUNC)CE bool OP FUNC(CO Mod<M>& n)CO NE
#define DC_OF_AR_FOR_MOD(FUNC)CE Mod<M> OP FUNC(CO Mod<M>& n)CO NE;TE <SFINAE_FOR_MOD(= nullptr)> CE Mod<M> OP FUNC(T&& n)CO NE;
#define DF_OF_CM_FOR_MOD(FUNC)TE <uint M> CE bool Mod<M>::OP FUNC(CO Mod<M>& n)CO NE{RE m_n FUNC n.m_n;}
#define DF_OF_AR_FOR_MOD(FUNC,FORMULA)TE <uint M> CE Mod<M> Mod<M>::OP FUNC(CO Mod<M>& n)CO NE{RE MO(Mod<M>(*TH)FUNC ## = n);}TE <uint M> TE <SFINAE_FOR_MOD()> CE Mod<M> Mod<M>::OP FUNC(T&& n)CO NE{RE FORMULA;}TE <uint M,SFINAE_FOR_MOD(= nullptr)> CE Mod<M> OP FUNC(T&& n0,CO Mod<M>& n1)NE{RE MO(Mod<M>(forward<T>(n0))FUNC ## = n1);}

TE <uint M>CL Mod{PU:uint m_n;CE Mod()NE;CE Mod(CO Mod<M>& n)NE;CE Mod(Mod<M>& n)NE;CE Mod(Mod<M>&& n)NE;TE <SFINAE_FOR_MOD(= nullptr)> CE Mod(CO T& n)NE;TE <SFINAE_FOR_MOD(= nullptr)> CE Mod(T& n)NE;TE <SFINAE_FOR_MOD(= nullptr)> CE Mod(T&& n)NE;CE Mod<M>& OP=(CO Mod<M>& n)NE;CE Mod<M>& OP=(Mod<M>&& n)NE;CE Mod<M>& OP+=(CO Mod<M>& n)NE;CE Mod<M>& OP-=(CO Mod<M>& n)NE;CE Mod<M>& OP*=(CO Mod<M>& n)NE;IN Mod<M>& OP/=(CO Mod<M>& n);CE Mod<M>& OP<<=(int n)NE;CE Mod<M>& OP>>=(int n)NE;CE Mod<M>& OP++()NE;CE Mod<M> OP++(int)NE;CE Mod<M>& OP--()NE;CE Mod<M> OP--(int)NE;DC_OF_CM_FOR_MOD(==);DC_OF_CM_FOR_MOD(!=);DC_OF_CM_FOR_MOD(<);DC_OF_CM_FOR_MOD(<=);DC_OF_CM_FOR_MOD(>);DC_OF_CM_FOR_MOD(>=);DC_OF_AR_FOR_MOD(+);DC_OF_AR_FOR_MOD(-);DC_OF_AR_FOR_MOD(*);DC_OF_AR_FOR_MOD(/);CE Mod<M> OP<<(int n)CO NE;CE Mod<M> OP>>(int n)CO NE;CE Mod<M> OP-()CO NE;CE Mod<M>& SignInvert()NE;CE Mod<M>& Double()NE;CE Mod<M>& Halve()NE;IN Mod<M>& Invert();TE <TY T> CE Mod<M>& PositivePW(T&& EX)NE;TE <TY T> CE Mod<M>& NonNegativePW(T&& EX)NE;TE <TY T> CE Mod<M>& PW(T&& EX);CE VO swap(Mod<M>& n)NE;CE CRUI RP()CO NE;ST CE Mod<M> DeRP(CRUI n)NE;ST CE uint& Normalise(uint& n)NE;ST IN CO Mod<M>& Inverse(CRUI n)NE;ST IN CO Mod<M>& Factorial(CRUI n)NE;ST IN CO Mod<M>& FactorialInverse(CRUI n)NE;ST IN Mod<M> Combination(CRUI n,CRUI i)NE;ST IN CO Mod<M>& zero()NE;ST IN CO Mod<M>& one()NE;TE <TY T> CE Mod<M>& Ref(T&& n)NE;};

#define SFINAE_FOR_MN(DEFAULT)TY T,enable_if_t<is_COructible_v<Mod<M>,decay_t<T>>>* DEFAULT
#define DC_OF_AR_FOR_MN(FUNC)IN MN<M> OP FUNC(CO MN<M>& n)CO NE;TE <SFINAE_FOR_MOD(= nullptr)> IN MN<M> OP FUNC(T&& n)CO NE;
#define DF_OF_CM_FOR_MN(FUNC)TE <uint M> IN bool MN<M>::OP FUNC(CO MN<M>& n)CO NE{RE m_n FUNC n.m_n;}
#define DF_OF_AR_FOR_MN(FUNC,FORMULA)TE <uint M> IN MN<M> MN<M>::OP FUNC(CO MN<M>& n)CO NE{RE MO(MN<M>(*TH)FUNC ## = n);}TE <uint M> TE <SFINAE_FOR_MOD()> IN MN<M> MN<M>::OP FUNC(T&& n)CO NE{RE FORMULA;}TE <uint M,SFINAE_FOR_MOD(= nullptr)> IN MN<M> OP FUNC(T&& n0,CO MN<M>& n1)NE{RE MO(MN<M>(forward<T>(n0))FUNC ## = n1);}

TE <uint M>CL MN:PU Mod<M>{PU:CE MN()NE;CE MN(CO MN<M>& n)NE;CE MN(MN<M>& n)NE;CE MN(MN<M>&& n)NE;TE <SFINAE_FOR_MN(= nullptr)> CE MN(CO T& n)NE;TE <SFINAE_FOR_MN(= nullptr)> CE MN(T&& n)NE;CE MN<M>& OP=(CO MN<M>& n)NE;CE MN<M>& OP=(MN<M>&& n)NE;CE MN<M>& OP+=(CO MN<M>& n)NE;CE MN<M>& OP-=(CO MN<M>& n)NE;CE MN<M>& OP*=(CO MN<M>& n)NE;IN MN<M>& OP/=(CO MN<M>& n);CE MN<M>& OP<<=(int n)NE;CE MN<M>& OP>>=(int n)NE;CE MN<M>& OP++()NE;CE MN<M> OP++(int)NE;CE MN<M>& OP--()NE;CE MN<M> OP--(int)NE;DC_OF_AR_FOR_MN(+);DC_OF_AR_FOR_MN(-);DC_OF_AR_FOR_MN(*);DC_OF_AR_FOR_MN(/);CE MN<M> OP<<(int n)CO NE;CE MN<M> OP>>(int n)CO NE;CE MN<M> OP-()CO NE;CE MN<M>& SignInvert()NE;CE MN<M>& Double()NE;CE MN<M>& Halve()NE;CE MN<M>& Invert();TE <TY T> CE MN<M>& PositivePW(T&& EX)NE;TE <TY T> CE MN<M>& NonNegativePW(T&& EX)NE;TE <TY T> CE MN<M>& PW(T&& EX);CE uint RP()CO NE;CE Mod<M> Reduce()CO NE;ST CE MN<M> DeRP(CRUI n)NE;ST IN CO MN<M>& Formise(CRUI n)NE;ST IN CO MN<M>& Inverse(CRUI n)NE;ST IN CO MN<M>& Factorial(CRUI n)NE;ST IN CO MN<M>& FactorialInverse(CRUI n)NE;ST IN MN<M> Combination(CRUI n,CRUI i)NE;ST IN CO MN<M>& zero()NE;ST IN CO MN<M>& one()NE;ST CE uint Form(CRUI n)NE;ST CE ull& Reduction(ull& n)NE;ST CE ull& ReducedMU(ull& n,CRUI m)NE;ST CE uint MU(CRUI n0,CRUI n1)NE;ST CE uint BaseSquareTruncation(uint& n)NE;TE <TY T> CE MN<M>& Ref(T&& n)NE;};TE <uint M> CE MN<M> Twice(CO MN<M>& n)NE;TE <uint M> CE MN<M> Half(CO MN<M>& n)NE;TE <uint M> CE MN<M> Inverse(CO MN<M>& n);TE <uint M,TY T> CE MN<M> PW(MN<M> n,T EX);TE <TY T> CE MN<2> PW(CO MN<2>& n,CO T& p);TE <TY T> CE T Square(CO T& t);TE <> CE MN<2> Square<MN<2>>(CO MN<2>& t);TE <uint M> CE VO swap(MN<M>& n0,MN<M>& n1)NE;TE <uint M> IN string to_string(CO MN<M>& n)NE;TE<uint M,CL Traits> IN basic_istream<char,Traits>& OP>>(basic_istream<char,Traits>& is,MN<M>& n);TE<uint M,CL Traits> IN basic_ostream<char,Traits>& OP<<(basic_ostream<char,Traits>& os,CO MN<M>& n);

TE <uint M>CL COantsForMod{PU:COantsForMod()= delete;ST CE CO bool g_even =((M & 1)== 0);ST CE CO uint g_memory_bound = 1000000;ST CE CO uint g_memory_LE = M < g_memory_bound?M:g_memory_bound;ST CE ull MNBasePW(ull&& EX)NE;ST CE uint g_M_minus = M - 1;ST CE uint g_M_minus_2 = M - 2;ST CE uint g_M_minus_2_neg = 2 - M;ST CE CO int g_MN_digit = 32;ST CE CO ull g_MN_base = ull(1)<< g_MN_digit;ST CE CO uint g_MN_base_minus = uint(g_MN_base - 1);ST CE CO uint g_MN_digit_half =(g_MN_digit + 1)>> 1;ST CE CO uint g_MN_base_sqrt_minus =(1 << g_MN_digit_half)- 1;ST CE CO uint g_MN_M_neg_inverse = uint((g_MN_base - MNBasePW((ull(1)<<(g_MN_digit - 1))- 1))& g_MN_base_minus);ST CE CO uint g_MN_base_mod = uint(g_MN_base % M);ST CE CO uint g_MN_base_square_mod = uint(((g_MN_base % M)*(g_MN_base % M))% M);};TE <uint M> CE ull COantsForMod<M>::MNBasePW(ull&& EX)NE{ull prod = 1;ull PW = M;WH(EX != 0){(EX & 1)== 1?(prod *= PW)&= g_MN_base_minus:prod;EX >>= 1;(PW *= PW)&= g_MN_base_minus;}RE prod;}

US MP = Mod<P>;US MNP = MN<P>;TE <uint M> CE uint MN<M>::Form(CRUI n)NE{ull n_copy = n;RE uint(MO(Reduction(n_copy *= COantsForMod<M>::g_MN_base_square_mod)));}TE <uint M> CE ull& MN<M>::Reduction(ull& n)NE{ull n_sub = n & COantsForMod<M>::g_MN_base_minus;RE((n +=((n_sub *= COantsForMod<M>::g_MN_M_neg_inverse)&= COantsForMod<M>::g_MN_base_minus)*= M)>>= COantsForMod<M>::g_MN_digit)< M?n:n -= M;}TE <uint M> CE ull& MN<M>::ReducedMU(ull& n,CRUI m)NE{RE Reduction(n *= m);}TE <uint M> CE uint MN<M>::MU(CRUI n0,CRUI n1)NE{ull n0_copy = n0;RE uint(MO(ReducedMU(ReducedMU(n0_copy,n1),COantsForMod<M>::g_MN_base_square_mod)));}TE <uint M> CE uint MN<M>::BaseSquareTruncation(uint& n)NE{CO uint n_u = n >> COantsForMod<M>::g_MN_digit_half;n &= COantsForMod<M>::g_MN_base_sqrt_minus;RE n_u;}TE <uint M> CE MN<M>::MN()NE:Mod<M>(){ST_AS(! COantsForMod<M>::g_even);}TE <uint M> CE MN<M>::MN(CO MN<M>& n)NE:Mod<M>(n){}TE <uint M> CE MN<M>::MN(MN<M>& n)NE:Mod<M>(n){}TE <uint M> CE MN<M>::MN(MN<M>&& n)NE:Mod<M>(MO(n)){}TE <uint M> TE <SFINAE_FOR_MN()> CE MN<M>::MN(CO T& n)NE:Mod<M>(n){ST_AS(! COantsForMod<M>::g_even);Mod<M>::m_n = Form(Mod<M>::m_n);}TE <uint M> TE <SFINAE_FOR_MN()> CE MN<M>::MN(T&& n)NE:Mod<M>(forward<T>(n)){ST_AS(! COantsForMod<M>::g_even);Mod<M>::m_n = Form(Mod<M>::m_n);}TE <uint M> CE MN<M>& MN<M>::OP=(CO MN<M>& n)NE{RE Ref(Mod<M>::OP=(n));}TE <uint M> CE MN<M>& MN<M>::OP=(MN<M>&& n)NE{RE Ref(Mod<M>::OP=(MO(n)));}TE <uint M> CE MN<M>& MN<M>::OP+=(CO MN<M>& n)NE{RE Ref(Mod<M>::OP+=(n));}TE <uint M> CE MN<M>& MN<M>::OP-=(CO MN<M>& n)NE{RE Ref(Mod<M>::OP-=(n));}TE <uint M> CE MN<M>& MN<M>::OP*=(CO MN<M>& n)NE{ull m_n_copy = Mod<M>::m_n;RE Ref(Mod<M>::m_n = MO(ReducedMU(m_n_copy,n.m_n)));}TE <uint M> IN MN<M>& MN<M>::OP/=(CO MN<M>& n){RE OP*=(MN<M>(n).Invert());}TE <uint M> CE MN<M>& MN<M>::OP<<=(int n)NE{RE Ref(Mod<M>::OP<<=(n));}TE <uint M> CE MN<M>& MN<M>::OP>>=(int n)NE{RE Ref(Mod<M>::OP>>=(n));}TE <uint M> CE MN<M>& MN<M>::OP++()NE{RE Ref(Mod<M>::Normalise(Mod<M>::m_n += COantsForMod<M>::g_MN_base_mod));}TE <uint M> CE MN<M> MN<M>::OP++(int)NE{MN<M> n{*TH};OP++();RE n;}TE <uint M> CE MN<M>& MN<M>::OP--()NE{RE Ref(Mod<M>::m_n < COantsForMod<M>::g_MN_base_mod?((Mod<M>::m_n += M)-= COantsForMod<M>::g_MN_base_mod):Mod<M>::m_n -= COantsForMod<M>::g_MN_base_mod);}TE <uint M> CE MN<M> MN<M>::OP--(int)NE{MN<M> n{*TH};OP--();RE n;}DF_OF_AR_FOR_MN(+,MN<M>(forward<T>(n))+= *TH);DF_OF_AR_FOR_MN(-,MN<M>(forward<T>(n)).SignInvert()+= *TH);DF_OF_AR_FOR_MN(*,MN<M>(forward<T>(n))*= *TH);DF_OF_AR_FOR_MN(/,MN<M>(forward<T>(n)).Invert()*= *TH);TE <uint M> CE MN<M> MN<M>::OP<<(int n)CO NE{RE MO(MN<M>(*TH)<<= n);}TE <uint M> CE MN<M> MN<M>::OP>>(int n)CO NE{RE MO(MN<M>(*TH)>>= n);}TE <uint M> CE MN<M> MN<M>::OP-()CO NE{RE MO(MN<M>(*TH).SignInvert());}TE <uint M> CE MN<M>& MN<M>::SignInvert()NE{RE Ref(Mod<M>::m_n > 0?Mod<M>::m_n = M - Mod<M>::m_n:Mod<M>::m_n);}TE <uint M> CE MN<M>& MN<M>::Double()NE{RE Ref(Mod<M>::Double());}TE <uint M> CE MN<M>& MN<M>::Halve()NE{RE Ref(Mod<M>::Halve());}TE <uint M> CE MN<M>& MN<M>::Invert(){assert(Mod<M>::m_n > 0);RE PositivePW(uint(COantsForMod<M>::g_M_minus_2));}TE <uint M> TE <TY T> CE MN<M>& MN<M>::PositivePW(T&& EX)NE{MN<M> PW{*TH};(--EX)%= COantsForMod<M>::g_M_minus_2;WH(EX != 0){(EX & 1)== 1?OP*=(PW):*TH;EX >>= 1;PW *= PW;}RE *TH;}TE <uint M> TE <TY T> CE MN<M>& MN<M>::NonNegativePW(T&& EX)NE{RE EX == 0?Ref(Mod<M>::m_n = COantsForMod<M>::g_MN_base_mod):PositivePW(forward<T>(EX));}TE <uint M> TE <TY T> CE MN<M>& MN<M>::PW(T&& EX){bool neg = EX < 0;assert(!(neg && Mod<M>::m_n == 0));RE neg?PositivePW(forward<T>(EX *= COantsForMod<M>::g_M_minus_2_neg)):NonNegativePW(forward<T>(EX));}TE <uint M> CE uint MN<M>::RP()CO NE{ull m_n_copy = Mod<M>::m_n;RE MO(Reduction(m_n_copy));}TE <uint M> CE Mod<M> MN<M>::Reduce()CO NE{ull m_n_copy = Mod<M>::m_n;RE Mod<M>::DeRP(MO(Reduction(m_n_copy)));}TE <uint M> CE MN<M> MN<M>::DeRP(CRUI n)NE{RE MN<M>(Mod<M>::DeRP(n));}TE <uint M> IN CO MN<M>& MN<M>::Formise(CRUI n)NE{ST MN<M> memory[COantsForMod<M>::g_memory_LE] ={zero(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr] = DeRP(LE_curr);LE_curr++;}RE memory[n];}TE <uint M> IN CO MN<M>& MN<M>::Inverse(CRUI n)NE{ST MN<M> memory[COantsForMod<M>::g_memory_LE] ={zero(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr] = MN<M>(Mod<M>::Inverse(LE_curr));LE_curr++;}RE memory[n];}TE <uint M> IN CO MN<M>& MN<M>::Factorial(CRUI n)NE{ST MN<M> memory[COantsForMod<M>::g_memory_LE] ={one(),one()};ST uint LE_curr = 2;ST MN<M> val_curr{one()};ST MN<M> val_last{one()};WH(LE_curr <= n){memory[LE_curr++] = val_curr *= ++val_last;}RE memory[n];}TE <uint M> IN CO MN<M>& MN<M>::FactorialInverse(CRUI n)NE{ST MN<M> memory[COantsForMod<M>::g_memory_LE] ={one(),one()};ST uint LE_curr = 2;ST MN<M> val_curr{one()};ST MN<M> val_last{one()};WH(LE_curr <= n){memory[LE_curr] = val_curr *= Inverse(LE_curr);LE_curr++;}RE memory[n];}TE <uint M> IN MN<M> MN<M>::Combination(CRUI n,CRUI i)NE{RE i <= n?Factorial(n)*FactorialInverse(i)*FactorialInverse(n - i):zero();}TE <uint M> IN CO MN<M>& MN<M>::zero()NE{ST CE CO MN<M> z{};RE z;}TE <uint M> IN CO MN<M>& MN<M>::one()NE{ST CE CO MN<M> o{DeRP(1)};RE o;}TE <uint M> TE <TY T> CE MN<M>& MN<M>::Ref(T&& n)NE{RE *TH;}TE <uint M> CE MN<M> Twice(CO MN<M>& n)NE{RE MO(MN<M>(n).Double());}TE <uint M> CE MN<M> Half(CO MN<M>& n)NE{RE MO(MN<M>(n).Halve());}TE <uint M> CE MN<M> Inverse(CO MN<M>& n){RE MO(MN<M>(n).Invert());}TE <uint M,TY T> CE MN<M> PW(MN<M> n,T EX){RE MO(n.PW(EX));}TE <uint M> CE VO swap(MN<M>& n0,MN<M>& n1)NE{n0.swap(n1);}TE <uint M> IN string to_string(CO MN<M>& n)NE{RE to_string(n.RP())+ " + MZ";}TE<uint M,CL Traits> IN basic_istream<char,Traits>& OP>>(basic_istream<char,Traits>& is,MN<M>& n){ll m;is >> m;n = m;RE is;}TE<uint M,CL Traits> IN basic_ostream<char,Traits>& OP<<(basic_ostream<char,Traits>& os,CO MN<M>& n){RE os << n.RP();}

TE <uint M> CE Mod<M>::Mod()NE:m_n(){}TE <uint M> CE Mod<M>::Mod(CO Mod<M>& n)NE:m_n(n.m_n){}TE <uint M> CE Mod<M>::Mod(Mod<M>& n)NE:m_n(n.m_n){}TE <uint M> CE Mod<M>::Mod(Mod<M>&& n)NE:m_n(MO(n.m_n)){}TE <uint M> TE <SFINAE_FOR_MOD()> CE Mod<M>::Mod(CO T& n)NE:m_n(RS<M>(n)){}TE <uint M> TE <SFINAE_FOR_MOD()> CE Mod<M>::Mod(T& n)NE:m_n(RS<M>(decay_t<T>(n))){}TE <uint M> TE <SFINAE_FOR_MOD()> CE Mod<M>::Mod(T&& n)NE:m_n(RS<M>(forward<T>(n))){}TE <uint M> CE Mod<M>& Mod<M>::OP=(CO Mod<M>& n)NE{RE Ref(m_n = n.m_n);}TE <uint M> CE Mod<M>& Mod<M>::OP=(Mod<M>&& n)NE{RE Ref(m_n = MO(n.m_n));}TE <uint M> CE Mod<M>& Mod<M>::OP+=(CO Mod<M>& n)NE{RE Ref(Normalise(m_n += n.m_n));}TE <uint M> CE Mod<M>& Mod<M>::OP-=(CO Mod<M>& n)NE{RE Ref(m_n < n.m_n?(m_n += M)-= n.m_n:m_n -= n.m_n);}TE <uint M> CE Mod<M>& Mod<M>::OP*=(CO Mod<M>& n)NE{RE Ref(m_n = COantsForMod<M>::g_even?RS<M>(ull(m_n)* n.m_n):MN<M>::MU(m_n,n.m_n));}TE <> CE MP& MP::OP*=(CO MP& n)NE{ull m_n_copy = m_n;RE Ref(m_n = MO((m_n_copy *= n.m_n)< P?m_n_copy:RSP(m_n_copy)));}TE <uint M> IN Mod<M>& Mod<M>::OP/=(CO Mod<M>& n){RE OP*=(Mod<M>(n).Invert());}TE <uint M> CE Mod<M>& Mod<M>::OP<<=(int n)NE{WH(n-- > 0){Normalise(m_n <<= 1);}RE *TH;}TE <uint M> CE Mod<M>& Mod<M>::OP>>=(int n)NE{WH(n-- > 0){((m_n & 1)== 0?m_n:m_n += M)>>= 1;}RE *TH;}TE <uint M> CE Mod<M>& Mod<M>::OP++()NE{RE Ref(m_n < COantsForMod<M>::g_M_minus?++m_n:m_n = 0);}TE <uint M> CE Mod<M> Mod<M>::OP++(int)NE{Mod<M> n{*TH};OP++();RE n;}TE <uint M> CE Mod<M>& Mod<M>::OP--()NE{RE Ref(m_n == 0?m_n = COantsForMod<M>::g_M_minus:--m_n);}TE <uint M> CE Mod<M> Mod<M>::OP--(int)NE{Mod<M> n{*TH};OP--();RE n;}DF_OF_CM_FOR_MOD(==);DF_OF_CM_FOR_MOD(!=);DF_OF_CM_FOR_MOD(>);DF_OF_CM_FOR_MOD(>=);DF_OF_CM_FOR_MOD(<);DF_OF_CM_FOR_MOD(<=);DF_OF_AR_FOR_MOD(+,Mod<M>(forward<T>(n))+= *TH);DF_OF_AR_FOR_MOD(-,Mod<M>(forward<T>(n)).SignInvert()+= *TH);DF_OF_AR_FOR_MOD(*,Mod<M>(forward<T>(n))*= *TH);DF_OF_AR_FOR_MOD(/,Mod<M>(forward<T>(n)).Invert()*= *TH);TE <uint M> CE Mod<M> Mod<M>::OP<<(int n)CO NE{RE MO(Mod<M>(*TH)<<= n);}TE <uint M> CE Mod<M> Mod<M>::OP>>(int n)CO NE{RE MO(Mod<M>(*TH)>>= n);}TE <uint M> CE Mod<M> Mod<M>::OP-()CO NE{RE MO(Mod<M>(*TH).SignInvert());}TE <uint M> CE Mod<M>& Mod<M>::SignInvert()NE{RE Ref(m_n > 0?m_n = M - m_n:m_n);}TE <uint M> CE Mod<M>& Mod<M>::Double()NE{RE Ref(Normalise(m_n <<= 1));}TE <uint M> CE Mod<M>& Mod<M>::Halve()NE{RE Ref(((m_n & 1)== 0?m_n:m_n += M)>>= 1);}TE <uint M> IN Mod<M>& Mod<M>::Invert(){assert(m_n > 0);uint m_n_neg;RE m_n < COantsForMod<M>::g_memory_LE?Ref(m_n = Inverse(m_n).m_n):((m_n_neg = M - m_n)< COantsForMod<M>::g_memory_LE)?Ref(m_n = M - Inverse(m_n_neg).m_n):PositivePW(uint(COantsForMod<M>::g_M_minus_2));}TE <> IN Mod<2>& Mod<2>::Invert(){assert(m_n > 0);RE *TH;}TE <uint M> TE <TY T> CE Mod<M>& Mod<M>::PositivePW(T&& EX)NE{Mod<M> PW{*TH};EX--;WH(EX != 0){(EX & 1)== 1?OP*=(PW):*TH;EX >>= 1;PW *= PW;}RE *TH;}TE <> TE <TY T> CE Mod<2>& Mod<2>::PositivePW(T&& EX)NE{RE *TH;}TE <uint M> TE <TY T> CE Mod<M>& Mod<M>::NonNegativePW(T&& EX)NE{RE EX == 0?Ref(m_n = 1):Ref(PositivePW(forward<T>(EX)));}TE <uint M> TE <TY T> CE Mod<M>& Mod<M>::PW(T&& EX){bool neg = EX < 0;assert(!(neg && Mod<M>::m_n == 0));RE neg?PositivePW(forward<T>(EX *= COantsForMod<M>::g_M_minus_2_neg)):NonNegativePW(forward<T>(EX));}TE <uint M> IN CO Mod<M>& Mod<M>::Inverse(CRUI n)NE{ST Mod<M> memory[COantsForMod<M>::g_memory_LE] ={zero(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr].m_n = M - MN<M>::MU(memory[M % LE_curr].m_n,M / LE_curr);LE_curr++;}RE memory[n];}TE <uint M> IN CO Mod<M>& Mod<M>::Factorial(CRUI n)NE{ST Mod<M> memory[COantsForMod<M>::g_memory_LE] ={one(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr] = MN<M>::Factorial(LE_curr).Reduce();LE_curr++;}RE memory[n];}TE <uint M> IN CO Mod<M>& Mod<M>::FactorialInverse(CRUI n)NE{ST Mod<M> memory[COantsForMod<M>::g_memory_LE] ={one(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr] = MN<M>::FactorialInverse(LE_curr).Reduce();LE_curr++;}RE memory[n];}TE <uint M> IN Mod<M> Mod<M>::Combination(CRUI n,CRUI i)NE{RE MN<M>::Combination(n,i).Reduce();}TE <uint M> CE VO Mod<M>::swap(Mod<M>& n)NE{std::swap(m_n,n.m_n);}TE <uint M> CE CRUI Mod<M>::RP()CO NE{RE m_n;}TE <uint M> CE Mod<M> Mod<M>::DeRP(CRUI n)NE{Mod<M> n_copy{};n_copy.m_n = n;RE n_copy;}TE <uint M> CE uint& Mod<M>::Normalise(uint& n)NE{RE n < M?n:n -= M;}TE <uint M> IN CO Mod<M>& Mod<M>::zero()NE{ST CE CO Mod<M> z{};RE z;}TE <uint M> IN CO Mod<M>& Mod<M>::one()NE{ST CE CO Mod<M> o{DeRP(1)};RE o;}TE <uint M> TE <TY T> CE Mod<M>& Mod<M>::Ref(T&& n)NE{RE *TH;}TE <uint M> CE Mod<M> Twice(CO Mod<M>& n)NE{RE MO(Mod<M>(n).Double());}TE <uint M> CE Mod<M> Half(CO Mod<M>& n)NE{RE MO(Mod<M>(n).Halve());}TE <uint M> IN Mod<M> Inverse(CO Mod<M>& n){RE MO(Mod<M>(n).Invert());}TE <uint M> CE Mod<M> Inverse_COrexpr(CRUI n)NE{RE MO(Mod<M>::DeRP(RS<M>(n)).NonNegativePW(M - 2));}TE <uint M,TY T> CE Mod<M> PW(Mod<M> n,T EX){RE MO(n.PW(EX));}TE <TY T>CE Mod<2> PW(Mod<2> n,CO T& p){RE p == 0?Mod<2>::one():MO(n);}TE <uint M> CE VO swap(Mod<M>& n0,Mod<M>& n1)NE{n0.swap(n1);}TE <uint M> IN string to_string(CO Mod<M>& n)NE{RE to_string(n.RP())+ " + MZ";}TE<uint M,CL Traits> IN basic_istream<char,Traits>& OP>>(basic_istream<char,Traits>& is,Mod<M>& n){ll m;is >> m;n = m;RE is;}TE<uint M,CL Traits> IN basic_ostream<char,Traits>& OP<<(basic_ostream<char,Traits>& os,CO Mod<M>& n){RE os << n.RP();}
// AAA 常設ライブラリは以上に挿入する。

#define INCLUDE_LIBRARY
#include __FILE__

#endif // INCLUDE_LIBRARY

#endif // INCLUDE_SUB

#endif // INCLUDE_MAIN
