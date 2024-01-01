#ifndef INCLUDE_MODE
  #define INCLUDE_MODE
  // #define REACTIVE
  // #define USE_GETLINE
#endif

#ifdef INCLUDE_MAIN

inline void Solve()
{
  // // 数
  // DEXPR( ll , bound_N , 1e5 , 10 );
  // CEXPR( TYPE_OF( bound_N ) , bound_M , bound_N );
  // CIN( ll , N , M , K );
  // CIN_ASSERT( N , 1 , bound_N ); // ランダムテスト用。
  // ll answer = 0;
  // RETURN( answer );

  // // 配列
  // using value_type = ll;
  // using value_type = MP;
  // CIN( uint , N ); CIN_A( value_type , A , N ); CIN_A( value_type , B , N );
  // CIN( uint , N ); vector<value_type> A( N ) , B( N );
  // CIN( uint , N ); value_type A[bound_N] , B[bound_N]; // 関数の引数に使う。
  // FOR( i , 0 , N ){ cin >> A[i] >> B[i]; }
  // FOR( i , 0 , N * 2 ){ cin >> ( i < N ? A[i] : B[i-N] ); }
  // value_type answer = 0;
  // COUT_A( A , N );
  // RETURN( answer );

  // // 文字列
  // CIN( uint , N ); CIN( string , S , T );
  // ll answer = 0;
  // RETURN( answer );

  // // 順列
  // CIN( uint , N ); vector<int> A( N ) , A_inv( N );
  // FOR( i , 0 , N ){ cin >> A[i]; A_inv[--A[i]] = i; }
  // ll answer = 0;
  // RETURN( answer );
  
  // // グラフ
  // DEXPR( uint , bound_N , 1e5 , 10 );
  // CIN( uint , N , M );
  // CIN( uint , N ); uint M = N - 1;
  // gE<int>.resize( N );
  // gE<path>.resize( N );
  // uint M = N - 1;
  // FOR( j , 0 , M ){
  //   CIN_ASSERT( uj , 1 , N ); CIN_ASSERT( vj , 1 , N );
  //   uj--; vj--;
  //   gE<int>[uj].push_back( vj ); gE<int>[vj].push_back( uj );
  //   // CIN( ll , wj );
  //   // gE<path>[uj].push_back( { vj , wj } ); gE<path>[vj].push_back( { uj , wj } );
  // }
  // BreadthFirstSearch<bound_N,GetgE<int>> bfs{ N , 0 };
  // DepthFirstSearch<bound_N,GetgE<int>> dfs{ N , 0 };
  // DepthFirstSearchOnTree<bound_N,GetgE<int>> dfst{ N , 0 };
  // Dijkstra<GetgE<path>,bound_N> dijk{ N };
  // ll answer = 0;
  // MP answer = 0;
  // RETURN( answer );
 
  // // 一般のクエリ
  // DEXPR( int , bound_Q , 1e5 , 100 );
  // CIN( int , Q );
  // vector<T3<int> > query( Q );
  // vector<T2<int> > query( Q );
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
  // DEXPR( int , bound_H , 2e3 , 30 );
  // CEXPR( int , bound_W , bound_H );
  // static_assert( ll( bound_H ) * bound_W < ll( 1 ) << 31 );
  // CEXPR( int , bound_HW , bound_H * bound_W );
  // cin >> H >> W;
  // SET_ASSERT( H , 1 , bound_H ); SET_ASSERT( W , 1 , bound_W ); // ランダムテスト用。
  // H_minus = H - 1; W_minus = W - 1; HW = H * W;
  // vector<string> S( H );
  // FOR( i , 0 , H ){
  //   cin >> S[i];
  //   // SetEdgeOnGrid( S[i] , i , e<int> );
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

template <typename PATH> list<PATH> GetgE( const int& i )
{
  // list<PATH> answer{};
  list<PATH> answer = gE<PATH>[i];
  // VVV 入力によらない処理は以下に挿入する。

  // AAA 入力によらない処理は以上に挿入する。
  return answer;
}

template <typename T> inline T GetgF( const T& t ){ return gF<T>[t]; }
template <typename T> inline T GetgA( const int& i ){ return gA<T>[i]; }

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

Polynomial
c:/Users/user/Documents/Programming/Mathematics/Polynomial/compress.txt

UnionFind
c:/Users/user/Documents/Programming/Utility/VLTree/UnionFindForest/compress.txt

*/

// VVV 常設でないライブラリは以下に挿入する。














// AAA 常設でないライブラリは以上に挿入する。

#define INCLUDE_SUB
#include __FILE__

#else // INCLUDE_LIBRARY

#ifdef DEBUG
  #define _GLIBCXX_DEBUG
  #define REPEAT_MAIN( BOUND ) START_MAIN; signal( SIGABRT , &AlertAbort ); AutoCheck( exec_mode , use_getline ); if( exec_mode == sample_debug_mode || exec_mode == submission_debug_mode || exec_mode == library_search_mode ){ return 0; } else if( exec_mode == experiment_mode ){ Experiment(); return 0; } else if( exec_mode == small_test_mode ){ SmallTest(); return 0; }; DEXPR( int , bound_test_case_num , BOUND , min( BOUND , 100 ) ); int test_case_num = 1; if( exec_mode == solve_mode ){ if constexpr( bound_test_case_num > 1 ){ SET_ASSERT( test_case_num , 1 , bound_test_case_num ); } } else if( exec_mode == random_test_mode ){ CERR( "ランダムテストを行う回数を指定してください。" ); SET_LL( test_case_num ); } FINISH_MAIN
  #define DEXPR( LL , BOUND , VALUE , DEBUG_VALUE ) CEXPR( LL , BOUND , DEBUG_VALUE )
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
  #define DEXPR( LL , BOUND , VALUE , DEBUG_VALUE ) CEXPR( LL , BOUND , VALUE )
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
  #define SET_A( A , N ) SOLVE_ONLY; FOR( VARIABLE_FOR_CIN_A , 0 , N ){ cin >> A[VARIABLE_FOR_CIN_A]; }
  #define CIN_A( LL , A , N ) vector<LL> A( N ); SET_A( A , N );
#endif
#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using lld = __float128;
template <typename INT> using T2 = pair<INT,INT>;
template <typename INT> using T3 = tuple<INT,INT,INT>;
template <typename INT> using T4 = tuple<INT,INT,INT,INT>;
using path = pair<int,ll>;
#define ATT __attribute__( ( target( "sse4.2,fma,avx2,popcnt,lzcnt,bmi2" ) ) )
#define START_MAIN int main(){ ios_base::sync_with_stdio( false ); cin.tie( nullptr )
#define FINISH_MAIN REPEAT( test_case_num ){ if constexpr( bound_test_case_num > 1 ){ CERR( "testcase " , VARIABLE_FOR_REPEAT_test_case_num , ":" ); } Solve(); CERR( "" ); } }
#define START_WATCH chrono::system_clock::time_point watch = chrono::system_clock::now()
#define CURRENT_TIME static_cast<double>( chrono::duration_cast<chrono::microseconds>( chrono::system_clock::now() - watch ).count() / 1000.0 )
#define CHECK_WATCH( TL_MS ) ( CURRENT_TIME < TL_MS - 100.0 )
#define TYPE_OF( VAR ) decay_t<decltype( VAR )>
#define CEXPR( LL , BOUND , VALUE ) constexpr LL BOUND = VALUE
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
#define RETURN( ... ) SOLVE_ONLY; COUT( __VA_ARGS__ ); return
#define COMPARE( ... ) auto naive = Naive( __VA_ARGS__ ); auto answer = Answer( __VA_ARGS__ ); bool match = naive == answer; COUT( "(" , #__VA_ARGS__ , ") == (" , __VA_ARGS__ , ") : Naive == " , naive , match ? "==" : "!=" , answer , "== Answer" ); if( !match ){ return; }

// 入出力用
template <class Traits> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is ) { return is; }
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is , Arg& arg , ARGS&... args ) { return VariadicCin( is >> arg , args... ); }
template <class Traits> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator ) { return is; }
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator , Arg& arg , ARGS&... args ) { return VariadicGetline( getline( is , arg , separator ) , separator , args... ); }
template <class Traits , typename Arg> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const vector<Arg>& arg ) { auto begin = arg.begin() , end = arg.end(); auto itr = begin; while( itr != end ){ ( itr == begin ? os : os << " " ) << *itr; itr++; } return os; }
template <class Traits , typename Arg> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , const Arg& arg ) { return os << arg; }
template <class Traits , typename Arg1 , typename Arg2 , typename... ARGS> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , const Arg1& arg1 , const Arg2& arg2 , const ARGS&... args ) { return VariadicCout( os << arg1 << " " , arg2 , args... ); }

// 算術用
template <typename T> constexpr T PositiveBaseResidue( const T& a , const T& p ){ return a >= 0 ? a % p : p - 1 - ( ( - ( a + 1 ) ) % p ); }
template <typename T> constexpr T Residue( const T& a , const T& p ){ return PositiveBaseResidue( a , p < 0 ? -p : p ); }
template <typename T> constexpr T PositiveBaseQuotient( const T& a , const T& p ){ return ( a - PositiveBaseResidue( a , p ) ) / p; }
template <typename T> constexpr T Quotient( const T& a , const T& p ){ return p < 0 ? PositiveBaseQuotient( -a , -p ) : PositiveBaseQuotient( a , p ); }

#define POWER( ANSWER , ARGUMENT , EXPONENT )				\
  static_assert( ! is_same<TYPE_OF( ARGUMENT ),int>::value && ! is_same<TYPE_OF( ARGUMENT ),uint>::value ); \
  TYPE_OF( ARGUMENT ) ANSWER{ 1 };					\
  {									\
    TYPE_OF( ARGUMENT ) ARGUMENT_FOR_SQUARE_FOR_POWER = ( ARGUMENT );	\
    TYPE_OF( EXPONENT ) EXPONENT_FOR_SQUARE_FOR_POWER = ( EXPONENT );	\
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
    TYPE_OF( EXPONENT ) EXPONENT_FOR_SQUARE_FOR_POWER = ( EXPONENT );	\
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
  static_assert( ! is_same<TYPE_OF( CONST_TARGET ),uint>::value && ! is_same<TYPE_OF( CONST_TARGET ),ull>::value ); \
  ll ANSWER = MINIMUM;							\
  {									\
  ll L_BS = MINIMUM;							\
  ll U_BS = MAXIMUM;							\
  ANSWER = UPDATE_ANSWER;						\
  ll EXPRESSION_BS;							\
  const ll CONST_TARGET_BS = ( CONST_TARGET );				\
  ll DIFFERENCE_BS;							\
  while( L_BS < U_BS ){							\
    DIFFERENCE_BS = ( EXPRESSION_BS = ( EXPRESSION ) ) - CONST_TARGET_BS; \
    CERR( "二分探索中：" , "L_BS =" , L_BS , "<=" , ANSWER , "<=" , U_BS , "= U_BS :" , #EXPRESSION , "-" , #CONST_TARGET , "=" , EXPRESSION_BS , "-" , CONST_TARGET_BS , "=" , DIFFERENCE_BS ); \
    if( DIFFERENCE_BS INEQUALITY_FOR_CHECK 0 ){				\
      U_BS = UPDATE_U;							\
    } else {								\
      L_BS = UPDATE_L;							\
    }									\
    ANSWER = UPDATE_ANSWER;						\
  }									\
  if( L_BS > U_BS ){							\
    CERR( "二分探索失敗：" , "L_BS =" , L_BS , ">" , U_BS , "= U_BS :" , #ANSWER , ":=" , #MAXIMUM , "+ 1 =" , MAXIMUM + 1  ); \
    CERR( "二分探索マクロにミスがある可能性があります。変更前の版に戻してください。" );	\
    ANSWER = MAXIMUM + 1;						\
  } else {								\
    CERR( "二分探索終了：" , "L_BS =" , L_BS , "<=" , ANSWER , "<=" , U_BS , "= U_BS" ); \
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
#define BS1( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET )	\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CONST_TARGET , >= , ANSWER , ANSWER + 1 , ( L_BS + U_BS ) / 2 ) \

// 単調増加の時にEXPRESSION <= CONST_TARGETの最大解を格納。
#define BS2( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET )	\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CONST_TARGET , > , ANSWER - 1 , ANSWER , ( L_BS + 1 + U_BS ) / 2 ) \

// 単調減少の時にEXPRESSION >= CONST_TARGETの最大解を格納。
#define BS3( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET )	\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CONST_TARGET , < , ANSWER - 1 , ANSWER , ( L_BS + 1 + U_BS ) / 2 ) \

// 単調減少の時にEXPRESSION <= CONST_TARGETの最小解を格納。
#define BS4( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET )	\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CONST_TARGET , <= , ANSWER , ANSWER + 1 , ( L_BS + U_BS ) / 2 ) \

// t以下の値が存在すればその最大値のiterator、存在しなければend()を返す。
template <typename T> inline typename set<T>::iterator MaximumLeq( set<T>& S , const T& t ) { const auto end = S.end(); if( S.empty() ){ return end; } auto itr = S.upper_bound( t ); return itr == end ? S.find( *( S.rbegin() ) ) : itr == S.begin() ? end : --itr; }
// t未満の値が存在すればその最大値のiterator、存在しなければend()を返す。
template <typename T> inline typename set<T>::iterator MaximumLt( set<T>& S , const T& t ) { const auto end = S.end(); if( S.empty() ){ return end; } auto itr = S.lower_bound( t ); return itr == end ? S.find( *( S.rbegin() ) ) : itr == S.begin() ? end : --itr; }
// t以上の値が存在すればその最小値のiterator、存在しなければend()を返す。
template <typename T> inline typename set<T>::iterator MinimumGeq( set<T>& S , const T& t ) { return S.lower_bound( t ); }
// tより大きい値が存在すればその最小値のiterator、存在しなければend()を返す。
template <typename T> inline typename set<T>::iterator MinimumGt( set<T>& S , const T& t ) { return S.upper_bound( t ); }

// データ構造用
template <typename T , template <typename...> typename V> inline T operator+( const T& t0 , const T& t1 ) { if( t0.empty() ){ return t1; } if( t1.empty() ){ return t0; } assert( t0.size() == t1.size() ); V<T> answer{}; for( auto itr0 = t0.begin() , itr1 = t1.begin() , end0 = t0.end(); itr0 != end0 ; itr0++ , itr1++ ){ answer.push_back( *itr0 + *itr1 ); } return answer; }
template <typename T> inline T operator+( const T2<T>& t0 , const T2<T>& t1 ) { return { t0.first + t1.first , t0.second + t1.second }; }
template <typename T> inline T operator+( const T3<T>& t0 , const T3<T>& t1 ) { return { get<0>( t0 ) + get<0>( t1 ) , get<1>( t0 ) + get<1>( t1 ) , get<2>( t0 ) + get<2>( t1 ) }; }
template <typename T> inline T operator+( const T4<T>& t0 , const T4<T>& t1 ) { return { get<0>( t0 ) + get<0>( t1 ) , get<1>( t0 ) + get<1>( t1 ) , get<2>( t0 ) + get<2>( t1 ) , get<3>( t0 ) + get<3>( t1 ) }; }
template <typename T> inline T Add( const T& t0 , const T& t1 ) { return t0 + t1; }
template <typename T> inline T XorAdd( const T& t0 , const T& t1 ){ return t0 ^ t1; }
template <typename T> inline T Multiply( const T& t0 , const T& t1 ) { return t0 * t1; }
template <typename T> inline const T& Zero() { static const T z = 0; return z; }
template <typename T> inline const T& One() { static const T o = 1; return o; }\
template <typename T> inline T AddInv( const T& t ) { return -t; }
template <typename T> inline T Id( const T& v ) { return v; }
template <typename T> inline T Min( const T& a , const T& b ){ return a < b ? a : b; }
template <typename T> inline T Max( const T& a , const T& b ){ return a < b ? b : a; }

// グリッド問題用
int H , W , H_minus , W_minus , HW;
vector<vector<bool> > non_wall;
inline T2<int> EnumHW( const int& v ) { return { v / W , v % W }; }
inline int EnumHW_inv( const int& h , const int& w ) { return h * W + w; }
const string direction[4] = {"U","R","D","L"};
// (i,j)->(k,h)の方向番号を取得
inline int DirectionNumberOnGrid( const int& i , const int& j , const int& k , const int& h ){return i<k?2:i>k?0:j<h?1:j>h?3:(assert(false),-1);}
// v->wの方向番号を取得
inline int DirectionNumberOnGrid( const int& v , const int& w ){auto [i,j]=EnumHW(v);auto [k,h]=EnumHW(w);return DirectionNumberOnGrid(i,j,k,h);}
// 方向番号の反転U<->D、R<->L
inline int ReverseDirectionNumberOnGrid( const int& n ){assert(0<=n&&n<4);return(n+2)%4;}
inline void SetEdgeOnGrid( const string& Si , const int& i , list<int> ( &e )[] , const char& walkable = '.' ){FOR(j,0,W){if(Si[j]==walkable){int v = EnumHW_inv(i,j);if(i>0){e[EnumHW_inv(i-1,j)].push_back(v);}if(i+1<H){e[EnumHW_inv(i+1,j)].push_back(v);}if(j>0){e[EnumHW_inv(i,j-1)].push_back(v);}if(j+1<W){e[EnumHW_inv(i,j+1)].push_back(v);}}}}
inline void SetEdgeOnGrid( const string& Si , const int& i , list<path> ( &e )[] , const char& walkable = '.' ){FOR(j,0,W){if(Si[j]==walkable){const int v=EnumHW_inv(i,j);if(i>0){e[EnumHW_inv(i-1,j)].push_back({v,1});}if(i+1<H){e[EnumHW_inv(i+1,j)].push_back({v,1});}if(j>0){e[EnumHW_inv(i,j-1)].push_back({v,1});}if(j+1<W){e[EnumHW_inv(i,j+1)].push_back({v,1});}}}}
inline void SetWallOnGrid( const string& Si , const int& i , vector<vector<bool> >& non_wall , const char& walkable = '.'  , const char& unwalkable = '#' ){non_wall.push_back(vector<bool>(W));auto& non_wall_i=non_wall[i];FOR(j,0,W){non_wall_i[j]=Si[j]==walkable?true:(assert(Si[j]==unwalkable),false);}}

// グラフ用
template <typename PATH> vector<list<PATH> > gE;
template <typename T> map<T,T> gF;
template <typename T> vector<T> gA;

// デバッグ用
#ifdef DEBUG
  inline void AlertAbort( int n ) { CERR( "abort関数が呼ばれました。assertマクロのメッセージが出力されていない場合はオーバーフローの有無を確認をしてください。" ); }
  void AutoCheck( int& exec_mode , const bool& use_getline );
  inline void Solve();
  inline void Experiment();
  inline void SmallTest();
  inline void RandomTest();
  ll GetRand( const ll& Rand_min , const ll& Rand_max );
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

// VVV 常設ライブラリは以下に挿入する。

// ConstexprModulo
// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/a.hpp
CEXPR(uint,P,998244353);TE <uint M,TY INT> CE INT& RS(INT& n)NE{RE n < 0?((((++n)*= -1)%= M)*= -1)+= M - 1:n %= M;}TE <uint M> CE uint& RS(uint& n)NE{RE n %= M;}TE <uint M> CE ull& RS(ull& n)NE{RE n %= M;}TE <TY INT> CE INT& RSP(INT& n)NE{CE CO uint trunc =(1 << 23)- 1;INT n_u = n >> 23;n &= trunc;INT n_uq =(n_u / 7)/ 17;n_u -= n_uq * 119;n += n_u << 23;RE n < n_uq?n += P - n_uq:n -= n_uq;}TE <> CE ull& RS<P,ull>(ull& n)NE{CE CO ull Pull = P;CE CO ull Pull2 =(Pull - 1)*(Pull - 1);RE RSP(n > Pull2?n -= Pull2:n);}TE <uint M,TY INT> CE INT RS(INT&& n)NE{RE MO(RS<M>(n));}TE <uint M,TY INT> CE INT RS(CO INT& n)NE{RE RS<M>(INT(n));}

#define SFINAE_FOR_MOD(DEFAULT)TY T,enable_if_t<is_constructible<uint,decay_t<T> >::value>* DEFAULT
#define DC_OF_CM_FOR_MOD(FUNC)CE bool OP FUNC(CO Mod<M>& n)CO NE
#define DC_OF_AR_FOR_MOD(FUNC)CE Mod<M> OP FUNC(CO Mod<M>& n)CO NE;TE <SFINAE_FOR_MOD(= nullptr)> CE Mod<M> OP FUNC(T&& n)CO NE;
#define DF_OF_CM_FOR_MOD(FUNC)TE <uint M> CE bool Mod<M>::OP FUNC(CO Mod<M>& n)CO NE{RE m_n FUNC n.m_n;}
#define DF_OF_AR_FOR_MOD(FUNC,FORMULA)TE <uint M> CE Mod<M> Mod<M>::OP FUNC(CO Mod<M>& n)CO NE{RE MO(Mod<M>(*TH)FUNC ## = n);}TE <uint M> TE <SFINAE_FOR_MOD()> CE Mod<M> Mod<M>::OP FUNC(T&& n)CO NE{RE FORMULA;}TE <uint M,SFINAE_FOR_MOD(= nullptr)> CE Mod<M> OP FUNC(T&& n0,CO Mod<M>& n1)NE{RE MO(Mod<M>(forward<T>(n0))FUNC ## = n1);}

TE <uint M>CL Mod{PU:uint m_n;CE Mod()NE;CE Mod(CO Mod<M>& n)NE;CE Mod(Mod<M>& n)NE;CE Mod(Mod<M>&& n)NE;TE <SFINAE_FOR_MOD(= nullptr)> CE Mod(CO T& n)NE;TE <SFINAE_FOR_MOD(= nullptr)> CE Mod(T& n)NE;TE <SFINAE_FOR_MOD(= nullptr)> CE Mod(T&& n)NE;CE Mod<M>& OP=(CO Mod<M>& n)NE;CE Mod<M>& OP=(Mod<M>&& n)NE;CE Mod<M>& OP+=(CO Mod<M>& n)NE;CE Mod<M>& OP-=(CO Mod<M>& n)NE;CE Mod<M>& OP*=(CO Mod<M>& n)NE;IN Mod<M>& OP/=(CO Mod<M>& n);CE Mod<M>& OP<<=(int n)NE;CE Mod<M>& OP>>=(int n)NE;CE Mod<M>& OP++()NE;CE Mod<M> OP++(int)NE;CE Mod<M>& OP--()NE;CE Mod<M> OP--(int)NE;DC_OF_CM_FOR_MOD(==);DC_OF_CM_FOR_MOD(!=);DC_OF_CM_FOR_MOD(<);DC_OF_CM_FOR_MOD(<=);DC_OF_CM_FOR_MOD(>);DC_OF_CM_FOR_MOD(>=);DC_OF_AR_FOR_MOD(+);DC_OF_AR_FOR_MOD(-);DC_OF_AR_FOR_MOD(*);DC_OF_AR_FOR_MOD(/);CE Mod<M> OP<<(int n)CO NE;CE Mod<M> OP>>(int n)CO NE;CE Mod<M> OP-()CO NE;CE Mod<M>& SignInvert()NE;CE Mod<M>& Double()NE;CE Mod<M>& Halve()NE;IN Mod<M>& Invert();TE <TY T> CE Mod<M>& PositivePW(T&& EX)NE;TE <TY T> CE Mod<M>& NonNegativePW(T&& EX)NE;TE <TY T> CE Mod<M>& PW(T&& EX);CE VO swap(Mod<M>& n)NE;CE CRUI RP()CO NE;ST CE Mod<M> DeRP(CRUI n)NE;ST CE uint& Normalise(uint& n)NE;ST IN CO Mod<M>& Inverse(CRUI n)NE;ST IN CO Mod<M>& Factorial(CRUI n)NE;ST IN CO Mod<M>& FactorialInverse(CRUI n)NE;ST IN Mod<M> Combination(CRUI n,CRUI i)NE;ST IN CO Mod<M>& zero()NE;ST IN CO Mod<M>& one()NE;TE <TY T> CE Mod<M>& Ref(T&& n)NE;};

#define SFINAE_FOR_MN(DEFAULT)TY T,enable_if_t<is_constructible<Mod<M>,decay_t<T> >::value>* DEFAULT
#define DC_OF_AR_FOR_MN(FUNC)IN MN<M> OP FUNC(CO MN<M>& n)CO NE;TE <SFINAE_FOR_MOD(= nullptr)> IN MN<M> OP FUNC(T&& n)CO NE;
#define DF_OF_CM_FOR_MN(FUNC)TE <uint M> IN bool MN<M>::OP FUNC(CO MN<M>& n)CO NE{RE m_n FUNC n.m_n;}
#define DF_OF_AR_FOR_MN(FUNC,FORMULA)TE <uint M> IN MN<M> MN<M>::OP FUNC(CO MN<M>& n)CO NE{RE MO(MN<M>(*TH)FUNC ## = n);}TE <uint M> TE <SFINAE_FOR_MOD()> IN MN<M> MN<M>::OP FUNC(T&& n)CO NE{RE FORMULA;}TE <uint M,SFINAE_FOR_MOD(= nullptr)> IN MN<M> OP FUNC(T&& n0,CO MN<M>& n1)NE{RE MO(MN<M>(forward<T>(n0))FUNC ## = n1);}

TE <uint M>CL MN:PU Mod<M>{PU:CE MN()NE;CE MN(CO MN<M>& n)NE;CE MN(MN<M>& n)NE;CE MN(MN<M>&& n)NE;TE <SFINAE_FOR_MN(= nullptr)> CE MN(CO T& n)NE;TE <SFINAE_FOR_MN(= nullptr)> CE MN(T&& n)NE;CE MN<M>& OP=(CO MN<M>& n)NE;CE MN<M>& OP=(MN<M>&& n)NE;CE MN<M>& OP+=(CO MN<M>& n)NE;CE MN<M>& OP-=(CO MN<M>& n)NE;CE MN<M>& OP*=(CO MN<M>& n)NE;IN MN<M>& OP/=(CO MN<M>& n);CE MN<M>& OP<<=(int n)NE;CE MN<M>& OP>>=(int n)NE;CE MN<M>& OP++()NE;CE MN<M> OP++(int)NE;CE MN<M>& OP--()NE;CE MN<M> OP--(int)NE;DC_OF_AR_FOR_MN(+);DC_OF_AR_FOR_MN(-);DC_OF_AR_FOR_MN(*);DC_OF_AR_FOR_MN(/);CE MN<M> OP<<(int n)CO NE;CE MN<M> OP>>(int n)CO NE;CE MN<M> OP-()CO NE;CE MN<M>& SignInvert()NE;CE MN<M>& Double()NE;CE MN<M>& Halve()NE;CE MN<M>& Invert();TE <TY T> CE MN<M>& PositivePW(T&& EX)NE;TE <TY T> CE MN<M>& NonNegativePW(T&& EX)NE;TE <TY T> CE MN<M>& PW(T&& EX);CE uint RP()CO NE;CE Mod<M> Reduce()CO NE;ST CE MN<M> DeRP(CRUI n)NE;ST IN CO MN<M>& Formise(CRUI n)NE;ST IN CO MN<M>& Inverse(CRUI n)NE;ST IN CO MN<M>& Factorial(CRUI n)NE;ST IN CO MN<M>& FactorialInverse(CRUI n)NE;ST IN MN<M> Combination(CRUI n,CRUI i)NE;ST IN CO MN<M>& zero()NE;ST IN CO MN<M>& one()NE;ST CE uint Form(CRUI n)NE;ST CE ull& Reduction(ull& n)NE;ST CE ull& ReducedMU(ull& n,CRUI m)NE;ST CE uint MU(CRUI n0,CRUI n1)NE;ST CE uint BaseSquareTruncation(uint& n)NE;TE <TY T> CE MN<M>& Ref(T&& n)NE;};TE <uint M> CE MN<M> Twice(CO MN<M>& n)NE;TE <uint M> CE MN<M> Half(CO MN<M>& n)NE;TE <uint M> CE MN<M> Inverse(CO MN<M>& n);TE <uint M,TY T> CE MN<M> PW(MN<M> n,T EX);TE <TY T> CE MN<2> PW(CO MN<2>& n,CO T& p);TE <TY T> CE T Square(CO T& t);TE <> CE MN<2> Square<MN<2> >(CO MN<2>& t);TE <uint M> CE VO swap(MN<M>& n0,MN<M>& n1)NE;TE <uint M> IN string to_string(CO MN<M>& n)NE;TE<uint M,CL Traits> IN basic_istream<char,Traits>& OP>>(basic_istream<char,Traits>& is,MN<M>& n);TE<uint M,CL Traits> IN basic_ostream<char,Traits>& OP<<(basic_ostream<char,Traits>& os,CO MN<M>& n);

TE <uint M>CL COantsForMod{PU:COantsForMod()= delete;ST CE CO bool g_even =((M & 1)== 0);ST CE CO uint g_memory_bound = 1000000;ST CE CO uint g_memory_LE = M < g_memory_bound?M:g_memory_bound;ST CE ull MNBasePW(ull&& EX)NE;ST CE uint g_M_minus = M - 1;ST CE uint g_M_minus_2 = M - 2;ST CE uint g_M_minus_2_neg = 2 - M;ST CE CO int g_MN_digit = 32;ST CE CO ull g_MN_base = ull(1)<< g_MN_digit;ST CE CO uint g_MN_base_minus = uint(g_MN_base - 1);ST CE CO uint g_MN_digit_half =(g_MN_digit + 1)>> 1;ST CE CO uint g_MN_base_sqrt_minus =(1 << g_MN_digit_half)- 1;ST CE CO uint g_MN_M_neg_inverse = uint((g_MN_base - MNBasePW((ull(1)<<(g_MN_digit - 1))- 1))& g_MN_base_minus);ST CE CO uint g_MN_base_mod = uint(g_MN_base % M);ST CE CO uint g_MN_base_square_mod = uint(((g_MN_base % M)*(g_MN_base % M))% M);};TE <uint M> CE ull COantsForMod<M>::MNBasePW(ull&& EX)NE{ull prod = 1;ull PW = M;WH(EX != 0){(EX & 1)== 1?(prod *= PW)&= g_MN_base_minus:prod;EX >>= 1;(PW *= PW)&= g_MN_base_minus;}RE prod;}

US MP = Mod<P>;US MNP = MN<P>;TE <uint M> CE uint MN<M>::Form(CRUI n)NE{ull n_copy = n;RE uint(MO(Reduction(n_copy *= COantsForMod<M>::g_MN_base_square_mod)));}TE <uint M> CE ull& MN<M>::Reduction(ull& n)NE{ull n_sub = n & COantsForMod<M>::g_MN_base_minus;RE((n +=((n_sub *= COantsForMod<M>::g_MN_M_neg_inverse)&= COantsForMod<M>::g_MN_base_minus)*= M)>>= COantsForMod<M>::g_MN_digit)< M?n:n -= M;}TE <uint M> CE ull& MN<M>::ReducedMU(ull& n,CRUI m)NE{RE Reduction(n *= m);}TE <uint M> CE uint MN<M>::MU(CRUI n0,CRUI n1)NE{ull n0_copy = n0;RE uint(MO(ReducedMU(ReducedMU(n0_copy,n1),COantsForMod<M>::g_MN_base_square_mod)));}TE <uint M> CE uint MN<M>::BaseSquareTruncation(uint& n)NE{CO uint n_u = n >> COantsForMod<M>::g_MN_digit_half;n &= COantsForMod<M>::g_MN_base_sqrt_minus;RE n_u;}TE <uint M> CE MN<M>::MN()NE:Mod<M>(){static_assert(! COantsForMod<M>::g_even);}TE <uint M> CE MN<M>::MN(CO MN<M>& n)NE:Mod<M>(n){}TE <uint M> CE MN<M>::MN(MN<M>& n)NE:Mod<M>(n){}TE <uint M> CE MN<M>::MN(MN<M>&& n)NE:Mod<M>(MO(n)){}TE <uint M> TE <SFINAE_FOR_MN()> CE MN<M>::MN(CO T& n)NE:Mod<M>(n){static_assert(! COantsForMod<M>::g_even);Mod<M>::m_n = Form(Mod<M>::m_n);}TE <uint M> TE <SFINAE_FOR_MN()> CE MN<M>::MN(T&& n)NE:Mod<M>(forward<T>(n)){static_assert(! COantsForMod<M>::g_even);Mod<M>::m_n = Form(Mod<M>::m_n);}TE <uint M> CE MN<M>& MN<M>::OP=(CO MN<M>& n)NE{RE Ref(Mod<M>::OP=(n));}TE <uint M> CE MN<M>& MN<M>::OP=(MN<M>&& n)NE{RE Ref(Mod<M>::OP=(MO(n)));}TE <uint M> CE MN<M>& MN<M>::OP+=(CO MN<M>& n)NE{RE Ref(Mod<M>::OP+=(n));}TE <uint M> CE MN<M>& MN<M>::OP-=(CO MN<M>& n)NE{RE Ref(Mod<M>::OP-=(n));}TE <uint M> CE MN<M>& MN<M>::OP*=(CO MN<M>& n)NE{ull m_n_copy = Mod<M>::m_n;RE Ref(Mod<M>::m_n = MO(ReducedMU(m_n_copy,n.m_n)));}TE <uint M> IN MN<M>& MN<M>::OP/=(CO MN<M>& n){RE OP*=(MN<M>(n).Invert());}TE <uint M> CE MN<M>& MN<M>::OP<<=(int n)NE{RE Ref(Mod<M>::OP<<=(n));}TE <uint M> CE MN<M>& MN<M>::OP>>=(int n)NE{RE Ref(Mod<M>::OP>>=(n));}TE <uint M> CE MN<M>& MN<M>::OP++()NE{RE Ref(Mod<M>::Normalise(Mod<M>::m_n += COantsForMod<M>::g_MN_base_mod));}TE <uint M> CE MN<M> MN<M>::OP++(int)NE{MN<M> n{*TH};OP++();RE n;}TE <uint M> CE MN<M>& MN<M>::OP--()NE{RE Ref(Mod<M>::m_n < COantsForMod<M>::g_MN_base_mod?((Mod<M>::m_n += M)-= COantsForMod<M>::g_MN_base_mod):Mod<M>::m_n -= COantsForMod<M>::g_MN_base_mod);}TE <uint M> CE MN<M> MN<M>::OP--(int)NE{MN<M> n{*TH};OP--();RE n;}DF_OF_AR_FOR_MN(+,MN<M>(forward<T>(n))+= *TH);DF_OF_AR_FOR_MN(-,MN<M>(forward<T>(n)).SignInvert()+= *TH);DF_OF_AR_FOR_MN(*,MN<M>(forward<T>(n))*= *TH);DF_OF_AR_FOR_MN(/,MN<M>(forward<T>(n)).Invert()*= *TH);TE <uint M> CE MN<M> MN<M>::OP<<(int n)CO NE{RE MO(MN<M>(*TH)<<= n);}TE <uint M> CE MN<M> MN<M>::OP>>(int n)CO NE{RE MO(MN<M>(*TH)>>= n);}TE <uint M> CE MN<M> MN<M>::OP-()CO NE{RE MO(MN<M>(*TH).SignInvert());}TE <uint M> CE MN<M>& MN<M>::SignInvert()NE{RE Ref(Mod<M>::m_n > 0?Mod<M>::m_n = M - Mod<M>::m_n:Mod<M>::m_n);}TE <uint M> CE MN<M>& MN<M>::Double()NE{RE Ref(Mod<M>::Double());}TE <uint M> CE MN<M>& MN<M>::Halve()NE{RE Ref(Mod<M>::Halve());}TE <uint M> CE MN<M>& MN<M>::Invert(){assert(Mod<M>::m_n > 0);RE PositivePW(uint(COantsForMod<M>::g_M_minus_2));}TE <uint M> TE <TY T> CE MN<M>& MN<M>::PositivePW(T&& EX)NE{MN<M> PW{*TH};(--EX)%= COantsForMod<M>::g_M_minus_2;WH(EX != 0){(EX & 1)== 1?OP*=(PW):*TH;EX >>= 1;PW *= PW;}RE *TH;}TE <uint M> TE <TY T> CE MN<M>& MN<M>::NonNegativePW(T&& EX)NE{RE EX == 0?Ref(Mod<M>::m_n = COantsForMod<M>::g_MN_base_mod):PositivePW(forward<T>(EX));}TE <uint M> TE <TY T> CE MN<M>& MN<M>::PW(T&& EX){bool neg = EX < 0;assert(!(neg && Mod<M>::m_n == 0));RE neg?PositivePW(forward<T>(EX *= COantsForMod<M>::g_M_minus_2_neg)):NonNegativePW(forward<T>(EX));}TE <uint M> CE uint MN<M>::RP()CO NE{ull m_n_copy = Mod<M>::m_n;RE MO(Reduction(m_n_copy));}TE <uint M> CE Mod<M> MN<M>::Reduce()CO NE{ull m_n_copy = Mod<M>::m_n;RE Mod<M>::DeRP(MO(Reduction(m_n_copy)));}TE <uint M> CE MN<M> MN<M>::DeRP(CRUI n)NE{RE MN<M>(Mod<M>::DeRP(n));}TE <uint M> IN CO MN<M>& MN<M>::Formise(CRUI n)NE{ST MN<M> memory[COantsForMod<M>::g_memory_LE] ={zero(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr] = DeRP(LE_curr);LE_curr++;}RE memory[n];}TE <uint M> IN CO MN<M>& MN<M>::Inverse(CRUI n)NE{ST MN<M> memory[COantsForMod<M>::g_memory_LE] ={zero(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr] = MN<M>(Mod<M>::Inverse(LE_curr));LE_curr++;}RE memory[n];}TE <uint M> IN CO MN<M>& MN<M>::Factorial(CRUI n)NE{ST MN<M> memory[COantsForMod<M>::g_memory_LE] ={one(),one()};ST uint LE_curr = 2;ST MN<M> val_curr{one()};ST MN<M> val_last{one()};WH(LE_curr <= n){memory[LE_curr++] = val_curr *= ++val_last;}RE memory[n];}TE <uint M> IN CO MN<M>& MN<M>::FactorialInverse(CRUI n)NE{ST MN<M> memory[COantsForMod<M>::g_memory_LE] ={one(),one()};ST uint LE_curr = 2;ST MN<M> val_curr{one()};ST MN<M> val_last{one()};WH(LE_curr <= n){memory[LE_curr] = val_curr *= Inverse(LE_curr);LE_curr++;}RE memory[n];}TE <uint M> IN MN<M> MN<M>::Combination(CRUI n,CRUI i)NE{RE i <= n?Factorial(n)*FactorialInverse(i)*FactorialInverse(n - i):zero();}TE <uint M> IN CO MN<M>& MN<M>::zero()NE{ST CE CO MN<M> z{};RE z;}TE <uint M> IN CO MN<M>& MN<M>::one()NE{ST CE CO MN<M> o{DeRP(1)};RE o;}TE <uint M> TE <TY T> CE MN<M>& MN<M>::Ref(T&& n)NE{RE *TH;}TE <uint M> CE MN<M> Twice(CO MN<M>& n)NE{RE MO(MN<M>(n).Double());}TE <uint M> CE MN<M> Half(CO MN<M>& n)NE{RE MO(MN<M>(n).Halve());}TE <uint M> CE MN<M> Inverse(CO MN<M>& n){RE MO(MN<M>(n).Invert());}TE <uint M,TY T> CE MN<M> PW(MN<M> n,T EX){RE MO(n.PW(EX));}TE <uint M> CE VO swap(MN<M>& n0,MN<M>& n1)NE{n0.swap(n1);}TE <uint M> IN string to_string(CO MN<M>& n)NE{RE to_string(n.RP())+ " + MZ";}TE<uint M,CL Traits> IN basic_istream<char,Traits>& OP>>(basic_istream<char,Traits>& is,MN<M>& n){ll m;is >> m;n = m;RE is;}TE<uint M,CL Traits> IN basic_ostream<char,Traits>& OP<<(basic_ostream<char,Traits>& os,CO MN<M>& n){RE os << n.RP();}

TE <uint M> CE Mod<M>::Mod()NE:m_n(){}TE <uint M> CE Mod<M>::Mod(CO Mod<M>& n)NE:m_n(n.m_n){}TE <uint M> CE Mod<M>::Mod(Mod<M>& n)NE:m_n(n.m_n){}TE <uint M> CE Mod<M>::Mod(Mod<M>&& n)NE:m_n(MO(n.m_n)){}TE <uint M> TE <SFINAE_FOR_MOD()> CE Mod<M>::Mod(CO T& n)NE:m_n(RS<M>(n)){}TE <uint M> TE <SFINAE_FOR_MOD()> CE Mod<M>::Mod(T& n)NE:m_n(RS<M>(decay_t<T>(n))){}TE <uint M> TE <SFINAE_FOR_MOD()> CE Mod<M>::Mod(T&& n)NE:m_n(RS<M>(forward<T>(n))){}TE <uint M> CE Mod<M>& Mod<M>::OP=(CO Mod<M>& n)NE{RE Ref(m_n = n.m_n);}TE <uint M> CE Mod<M>& Mod<M>::OP=(Mod<M>&& n)NE{RE Ref(m_n = MO(n.m_n));}TE <uint M> CE Mod<M>& Mod<M>::OP+=(CO Mod<M>& n)NE{RE Ref(Normalise(m_n += n.m_n));}TE <uint M> CE Mod<M>& Mod<M>::OP-=(CO Mod<M>& n)NE{RE Ref(m_n < n.m_n?(m_n += M)-= n.m_n:m_n -= n.m_n);}TE <uint M> CE Mod<M>& Mod<M>::OP*=(CO Mod<M>& n)NE{RE Ref(m_n = COantsForMod<M>::g_even?RS<M>(ull(m_n)* n.m_n):MN<M>::MU(m_n,n.m_n));}TE <> CE MP& MP::OP*=(CO MP& n)NE{ull m_n_copy = m_n;RE Ref(m_n = MO((m_n_copy *= n.m_n)< P?m_n_copy:RSP(m_n_copy)));}TE <uint M> IN Mod<M>& Mod<M>::OP/=(CO Mod<M>& n){RE OP*=(Mod<M>(n).Invert());}TE <uint M> CE Mod<M>& Mod<M>::OP<<=(int n)NE{WH(n-- > 0){Normalise(m_n <<= 1);}RE *TH;}TE <uint M> CE Mod<M>& Mod<M>::OP>>=(int n)NE{WH(n-- > 0){((m_n & 1)== 0?m_n:m_n += M)>>= 1;}RE *TH;}TE <uint M> CE Mod<M>& Mod<M>::OP++()NE{RE Ref(m_n < COantsForMod<M>::g_M_minus?++m_n:m_n = 0);}TE <uint M> CE Mod<M> Mod<M>::OP++(int)NE{Mod<M> n{*TH};OP++();RE n;}TE <uint M> CE Mod<M>& Mod<M>::OP--()NE{RE Ref(m_n == 0?m_n = COantsForMod<M>::g_M_minus:--m_n);}TE <uint M> CE Mod<M> Mod<M>::OP--(int)NE{Mod<M> n{*TH};OP--();RE n;}DF_OF_CM_FOR_MOD(==);DF_OF_CM_FOR_MOD(!=);DF_OF_CM_FOR_MOD(>);DF_OF_CM_FOR_MOD(>=);DF_OF_CM_FOR_MOD(<);DF_OF_CM_FOR_MOD(<=);DF_OF_AR_FOR_MOD(+,Mod<M>(forward<T>(n))+= *TH);DF_OF_AR_FOR_MOD(-,Mod<M>(forward<T>(n)).SignInvert()+= *TH);DF_OF_AR_FOR_MOD(*,Mod<M>(forward<T>(n))*= *TH);DF_OF_AR_FOR_MOD(/,Mod<M>(forward<T>(n)).Invert()*= *TH);TE <uint M> CE Mod<M> Mod<M>::OP<<(int n)CO NE{RE MO(Mod<M>(*TH)<<= n);}TE <uint M> CE Mod<M> Mod<M>::OP>>(int n)CO NE{RE MO(Mod<M>(*TH)>>= n);}TE <uint M> CE Mod<M> Mod<M>::OP-()CO NE{RE MO(Mod<M>(*TH).SignInvert());}TE <uint M> CE Mod<M>& Mod<M>::SignInvert()NE{RE Ref(m_n > 0?m_n = M - m_n:m_n);}TE <uint M> CE Mod<M>& Mod<M>::Double()NE{RE Ref(Normalise(m_n <<= 1));}TE <uint M> CE Mod<M>& Mod<M>::Halve()NE{RE Ref(((m_n & 1)== 0?m_n:m_n += M)>>= 1);}TE <uint M> IN Mod<M>& Mod<M>::Invert(){assert(m_n > 0);uint m_n_neg;RE m_n < COantsForMod<M>::g_memory_LE?Ref(m_n = Inverse(m_n).m_n):((m_n_neg = M - m_n)< COantsForMod<M>::g_memory_LE)?Ref(m_n = M - Inverse(m_n_neg).m_n):PositivePW(uint(COantsForMod<M>::g_M_minus_2));}TE <> IN Mod<2>& Mod<2>::Invert(){assert(m_n > 0);RE *TH;}TE <uint M> TE <TY T> CE Mod<M>& Mod<M>::PositivePW(T&& EX)NE{Mod<M> PW{*TH};EX--;WH(EX != 0){(EX & 1)== 1?OP*=(PW):*TH;EX >>= 1;PW *= PW;}RE *TH;}TE <> TE <TY T> CE Mod<2>& Mod<2>::PositivePW(T&& EX)NE{RE *TH;}TE <uint M> TE <TY T> CE Mod<M>& Mod<M>::NonNegativePW(T&& EX)NE{RE EX == 0?Ref(m_n = 1):Ref(PositivePW(forward<T>(EX)));}TE <uint M> TE <TY T> CE Mod<M>& Mod<M>::PW(T&& EX){bool neg = EX < 0;assert(!(neg && m_n == 0));neg?EX *= COantsForMod<M>::g_M_minus_2_neg:EX;RE m_n == 0?*TH:(EX %= COantsForMod<M>::g_M_minus)== 0?Ref(m_n = 1):PositivePW(forward<T>(EX));}TE <uint M> IN CO Mod<M>& Mod<M>::Inverse(CRUI n)NE{ST Mod<M> memory[COantsForMod<M>::g_memory_LE] ={zero(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr].m_n = M - MN<M>::MU(memory[M % LE_curr].m_n,M / LE_curr);LE_curr++;}RE memory[n];}TE <uint M> IN CO Mod<M>& Mod<M>::Factorial(CRUI n)NE{ST Mod<M> memory[COantsForMod<M>::g_memory_LE] ={one(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr] = MN<M>::Factorial(LE_curr).Reduce();LE_curr++;}RE memory[n];}TE <uint M> IN CO Mod<M>& Mod<M>::FactorialInverse(CRUI n)NE{ST Mod<M> memory[COantsForMod<M>::g_memory_LE] ={one(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr] = MN<M>::FactorialInverse(LE_curr).Reduce();LE_curr++;}RE memory[n];}TE <uint M> IN Mod<M> Mod<M>::Combination(CRUI n,CRUI i)NE{RE MN<M>::Combination(n,i).Reduce();}TE <uint M> CE VO Mod<M>::swap(Mod<M>& n)NE{std::swap(m_n,n.m_n);}TE <uint M> CE CRUI Mod<M>::RP()CO NE{RE m_n;}TE <uint M> CE Mod<M> Mod<M>::DeRP(CRUI n)NE{Mod<M> n_copy{};n_copy.m_n = n;RE n_copy;}TE <uint M> CE uint& Mod<M>::Normalise(uint& n)NE{RE n < M?n:n -= M;}TE <uint M> IN CO Mod<M>& Mod<M>::zero()NE{ST CE CO Mod<M> z{};RE z;}TE <uint M> IN CO Mod<M>& Mod<M>::one()NE{ST CE CO Mod<M> o{DeRP(1)};RE o;}TE <uint M> TE <TY T> CE Mod<M>& Mod<M>::Ref(T&& n)NE{RE *TH;}TE <uint M> CE Mod<M> Twice(CO Mod<M>& n)NE{RE MO(Mod<M>(n).Double());}TE <uint M> CE Mod<M> Half(CO Mod<M>& n)NE{RE MO(Mod<M>(n).Halve());}TE <uint M> IN Mod<M> Inverse(CO Mod<M>& n){RE MO(Mod<M>(n).Invert());}TE <uint M> CE Mod<M> Inverse_COrexpr(CRUI n)NE{RE MO(Mod<M>::DeRP(RS<M>(n)).NonNegativePW(M - 2));}TE <uint M,TY T> CE Mod<M> PW(Mod<M> n,T EX){RE MO(n.PW(EX));}TE <TY T>CE Mod<2> PW(Mod<2> n,const T& p){RE p == 0?Mod<2>::one():move(n);}TE <uint M> CE VO swap(Mod<M>& n0,Mod<M>& n1)NE{n0.swap(n1);}TE <uint M> IN string to_string(CO Mod<M>& n)NE{RE to_string(n.RP())+ " + MZ";}TE<uint M,CL Traits> IN basic_ostream<char,Traits>& OP<<(basic_ostream<char,Traits>& os,CO Mod<M>& n){RE os << n.RP();}

// IntervalAddBIT
// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/a.hpp
TE<int N>CL PWInverse_CE{PU:int m_val;CE PWInverse_CE();};
TE<int N>CE PWInverse_CE<N>::PWInverse_CE():m_val(1){WH(m_val < N){m_val <<= 1;}}
TE <TY T,int N>CL BIT{PU:T m_fenwick[N + 1];IN BIT();BIT(CO T(&a)[N]);IN T Get(CRI i)CO;IN VO Set(CRI i,CO T& n);IN VO Set(CO T(&a)[N]);IN VO Initialise();IN BIT<T,N>& OP+=(CO T(&a)[N]);VO Add(CRI i,CO T& n);T InitialSegmentSum(CRI i_final)CO;IN T IntervalSum(CRI i_start,CRI i_final)CO;int BinarySearch(CO T& n)CO;IN int BinarySearch(CRI i_start,CO T& n)CO;};
TE <TY T,int N> IN BIT<T,N>::BIT():m_fenwick(){static_assert(! is_same<T,int>::value);}TE <TY T,int N>BIT<T,N>::BIT(CO T(&a)[N]):m_fenwick(){static_assert(! is_same<T,int>::value);for(int j = 1;j <= N;j++){T& fenwick_j = m_fenwick[j];int i = j - 1;fenwick_j = a[i];int i_lim = j -(j & -j);WH(i != i_lim){fenwick_j += m_fenwick[i];i -=(i & -i);}}}TE <TY T,int N> IN T BIT<T,N>::Get(CRI i)CO{RE IntervalSum(i,i);}TE <TY T,int N> IN VO BIT<T,N>::Set(CRI i,CO T& n){Add(i,n - IntervalSum(i,i));}TE <TY T,int N> IN VO BIT<T,N>::Set(CO T(&a)[N]){BIT<T,N> a_copy{a};swap(m_fenwick,a_copy.m_fenwick);}TE <TY T,int N> IN VO BIT<T,N>::Initialise(){for(int j = 1;j <= N;j++){m_fenwick[j] = 0;}}TE <TY T,int N> IN BIT<T,N>& BIT<T,N>::OP+=(CO T(&a)[N]){for(int i = 0;i < N;i++){Add(i,a[i]);}RE *TH;}TE <TY T,int N>VO BIT<T,N>::Add(CRI i,CO T& n){int j = i + 1;WH(j <= N){m_fenwick[j] += n;j +=(j & -j);}RE;}TE <TY T,int N>T BIT<T,N>::InitialSegmentSum(CRI i_final)CO{T sum = 0;int j =(i_final < N?i_final:N - 1)+ 1;WH(j > 0){sum += m_fenwick[j];j -= j & -j;}RE sum;}TE <TY T,int N> IN T BIT<T,N>::IntervalSum(CRI i_start,CRI i_final)CO{RE InitialSegmentSum(i_final)- InitialSegmentSum(i_start - 1);}TE <TY T,int N>int BIT<T,N>::BinarySearch(CO T& n)CO{int j = 0;int PW = PWInverse_CE<N>().m_val;T sum{};T sum_next{};WH(PW > 0){int j_next = j | PW;if(j_next < N){sum_next += m_fenwick[j_next];if(sum_next < n){sum = sum_next;j = j_next;}else{sum_next = sum;}}PW >>= 1;}RE j;}TE <TY T,int N> IN int BIT<T,N>::BinarySearch(CRI i_start,CO T& n)CO{RE max(i_start,BinarySearch(InitialSegmentSum(i_start)+ n));}
TE <TY T,int N>CL IntervalAddBIT{PU:BIT<T,N> m_bit_0;BIT<T,N> m_bit_1;IN IntervalAddBIT();IN IntervalAddBIT(CO T(&a)[N]);IN T Get(CRI i)CO;IN VO Set(CRI i,CO T& n);IN VO Set(CO T(&a)[N]);IN VO Initialise();IN IntervalAddBIT<T,N>& OP+=(CO T(&a)[N]);IN VO Add(CRI i,CO T& n);IN VO IntervalAdd(CRI i_start,CRI i_final,CO T& n);IN T InitialSegmentSum(CRI i_final)CO;IN T IntervalSum(CRI i_start,CRI i_final)CO;};
TE <TY T,int N> IN IntervalAddBIT<T,N>::IntervalAddBIT():m_bit_0(),m_bit_1(){}TE <TY T,int N> IN IntervalAddBIT<T,N>::IntervalAddBIT(CO T(&a)[N]):m_bit_0(),m_bit_1(){OP+=(a);}TE <TY T,int N> IN T IntervalAddBIT<T,N>::Get(CRI i)CO{RE IntervalSum(i,i);}TE <TY T,int N> IN VO IntervalAddBIT<T,N>::Set(CRI i,CO T& n){Add(i,n - IntervalSum(i,i));}TE <TY T,int N> IN VO IntervalAddBIT<T,N>::Set(CO T(&a)[N]){IntervalAddBIT<T,N> a_copy{a};swap(m_bit_0,a_copy.m_bit_0);swap(m_bit_1,a_copy.m_bit_1);}TE <TY T,int N> IN VO IntervalAddBIT<T,N>::Initialise(){m_bit_0.Initialise();m_bit_1.Initialise();}TE <TY T,int N> IN IntervalAddBIT<T,N>& IntervalAddBIT<T,N>::OP+=(CO T(&a)[N]){for(int i = 0;i < N;i++){Add(i,a[i]);}RE *TH;}TE <TY T,int N> IN VO IntervalAddBIT<T,N>::Add(CRI i,CO T& n){IntervalAdd(i,i,n);}TE <TY T,int N> IN VO IntervalAddBIT<T,N>::IntervalAdd(CRI i_start,CRI i_final,CO T& n){m_bit_0.Add(i_start,-(i_start - 1)* n);m_bit_0.Add(i_final + 1,i_final * n);m_bit_1.Add(i_start,n);m_bit_1.Add(i_final + 1,- n);}TE <TY T,int N> IN T IntervalAddBIT<T,N>::InitialSegmentSum(CRI i_final)CO{RE m_bit_0.InitialSegmentSum(i_final)+ i_final * m_bit_1.InitialSegmentSum(i_final);}TE <TY T,int N> IN T IntervalAddBIT<T,N>::IntervalSum(CRI i_start,CRI i_final)CO{RE InitialSegmentSum(i_final)- InitialSegmentSum(i_start - 1);}

// AAA 常設ライブラリは以上に挿入する。

#define INCLUDE_LIBRARY
#include __FILE__

#endif // INCLUDE_LIBRARY

#endif // INCLUDE_SUB

#endif // INCLUDE_MAIN
