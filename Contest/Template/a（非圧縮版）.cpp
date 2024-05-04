// 想定解に用いるので削除しない。
#ifndef INCLUDE_MODE
  #define INCLUDE_MODE
  // #define REACTIVE
  // #define USE_GETLINE
#endif

#ifdef INCLUDE_MAIN

inline void Solve()
{
  // // 数・配列・文字列
  // CIN( ll , N );
  // CIN_A( ll , N , A );
  // // CIN( string , S );

  // // グラフ
  // CIN( int , N , M );
  // // CIN( int , N ); int M = N - 1;
  // vector<vector<int>> e( N );
  // // UnionFindForest uff{ N };
  // FOR( j , 0 , M ){
  //   CIN( int , uj , vj ); --uj; --vj;
  //   e[uj].push_back( vj ); e[vj].push_back( uj );
  //   // uff.Graft( uj , vj );
  // }
  // Graph graph{ N , Get( e ) };
  // BreadthFirstSearch bfs{ graph , -1 , 0 }; vector<int> d = bfs.GetDistance();
  // // DepthFirstSearchOnTree dfst{ graph , 0 };
  // // auto [ts,ts_inv,prev,dir_edge] = TopologicalSortedTree( graph , 0 );
  // // Graph graph_dir{ N , Get( dir_edge ) }; // 無向木をトポロジカルソートで0が根の有向化
  // // Graph graph_dir_rev{ N , [&]( const int& i ){ return vector( prev[i] >= 0 ? 1 : 0 , prev[i] ); } };
  
  // // 重み付きグラフ
  // CIN( int , N , M );
  // // CIN( int , N ); int M = N - 1;
  // CEXPR( ll , infty , 1e18 );
  // vector<vector<path>> e( N );
  // // vector w( N , vector( N , infty ) ); FOR( i , 0 , N ){ w[i][i] = 0; }
  // // UnionFindForest uff{ N };
  // FOR( j , 0 , M ){
  //   CIN( ll , uj , vj , wj ); --uj; --vj;
  //   e[uj].push_back( { vj , wj } ); e[vj].push_back( { uj , wj } );
  //   // w[uj][vj] = w[vj][uj] = wj;
  //   // uff.Graft( uj , vj , wj );
  // }
  // // auto edge = [&]( const int& i ){
  // //   vector<path> answer = e[i];
  // //   return answer;
  // // };
  // Graph graph{ N , Get( e ) };
  // Dijkstra dijk{ graph }; vector<ll> d = dijk.GetDistance( 0 );
  // // FloydWarshall fw{ infty , w }; vector<vector<ll>> d = fw.GetDistance();
 
  // 一般のクエリ
  // CIN( int , Q );
  // // BIT t{ N };
  // // IntervalMultiplyLazySqrtDecomposition t{ MultiplicativeMonoid<ll>( 1 ) , Module<ll,ll>() , N };
  // FOR( q , 0 , Q ){
  //   CIN( int , type );
  //   if( type == 1 ){
  //     CIN( ll , l , r , x ); --l; --r;
  //   } else if( type == 2 ){
  //     CIN( ll , l , r ); --l; --r;
  //     COUT( t.IntervalSum( l , r ) );
  //   }
  // }
  // // CIN_A( T3<int>> , Q , query );
  // // sort( query );
  // // Mo mo{ query };
  
  // // グリッド
  // cin >> H >> W; H_minus = H - 1; W_minus = W - 1; HW = H * W;
  // FOR( i , 0 , H ){
  //   SetWallStringOnGrid( i , grid ); // grid[i][j]に'.'や'#'を格納
  // }
  // // EnumerationGraph graph{ HW , EnumHW , EnumHW_inv , WEdgeOnGrid };
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
ll Naive( ll N , ll M , ll K )
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
  // }
}

// 圧縮時は中身だけ削除する。
inline void RandomTest()
{
  // CEXPR( int , bound_N , 1e5 ); CIN_ASSERT( N , 1 , bound_N );
  // CEXPR( ll , bound_M , 1e18 ); CIN_ASSERT( M , 1 , bound_M );
  // CEXPR( ll , bound_K , 1e9 ); CIN_ASSERT( K , 1 , bound_K );
  // COMPARE( N , M , N );
}

#define INCLUDE_MAIN
#include __FILE__

#else // INCLUDE_SUB

#ifdef INCLUDE_LIBRARY

/*
AdicExhausiveSearch/BFS (11KB)
c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/AdicExhausiveSearch/compress.txt

CommutativeDualSqrtDecomposition (6KB)
c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/Commutative/compress.txt

CoordinateCompress (3KB)
c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/compress.txt

DFSOnTree (11KB)
c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/compress.txt

DifferenceSequence (9KB)
c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/compress.txt

Divisor/Prime (4KB)
c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/compress.txt

IntervalAddBIT (9KB)
c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/compress.txt

IntervalMaxBIT (9KB)
c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/compress.txt

IntervalMultiplyLazySqrtDecomposition (18KB)
c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/LazyEvaluation/IntervalMultiply/compress.txt

Knapsack (8KB)
c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/compress.txt

MinimumCostFlow/PotentialisedDijkstra/Dijkstra (16KB)
c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/Potentialised/MinimumCostFlow/compress.txt

Polynomial (21KB)
c:/Users/user/Documents/Programming/Mathematics/Polynomial/compress.txt

TwoByOneMatrix/TwoByTwoMatrix (9KB)
C:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByOne/compress.txt

UnionFind (3KB)
c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/UnionFindForest/compress.txt
*/

// VVV 常設でないライブラリは以下に挿入する。












// AAA 常設でないライブラリは以上に挿入する。

#define INCLUDE_SUB
#include __FILE__

#else // INCLUDE_LIBRARY

#ifndef DEBUG
  #pragma GCC optimize ( "O3" )
  #pragma GCC optimize ( "unroll-loops" )
  #pragma GCC target ( "sse4.2,fma,avx2,popcnt,lzcnt,bmi2" )
  #define REPEAT_MAIN( BOUND ) START_MAIN; CEXPR( int , bound_test_case_num , BOUND ); int test_case_num = 1; if constexpr( bound_test_case_num > 1 ){ SET_ASSERT( test_case_num , 1 , bound_test_case_num ); } FINISH_MAIN
  #define DEXPR( LL , BOUND , VALUE1 , VALUE2 ) CEXPR( LL , BOUND , VALUE1 )
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
  #define SET_A( N , ... ) SOLVE_ONLY; VariadicResize( N , __VA_ARGS__ ); FOR( VARIABLE_FOR_SET_A , 0 , N ){ VariadicSet( cin , VARIABLE_FOR_SET_A , __VA_ARGS__ ); }
  #define CIN_A( LL , N , ... ) VE<LL> __VA_ARGS__; SET_A( N , __VA_ARGS__ );
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
#define SET_A_ASSERT( N , A , MIN , MAX ) FOR( VARIABLE_FOR_SET_A , 0 , N ){ SET_ASSERT( A[VARIABLE_FOR_SET_A] , MIN , MAX ); }
#define CIN_ASSERT( A , MIN , MAX ) decldecay_t( MAX ) A; SET_ASSERT( A , MIN , MAX )
#define CIN_A_ASSERT( N , A , MIN , MAX ) vector<decldecay_t( MAX )> A( N ); SET_A_ASSERT( N , A , MIN , MAX )
#define FOR( VAR , INITIAL , FINAL_PLUS_ONE ) for( decldecay_t( FINAL_PLUS_ONE ) VAR = INITIAL ; VAR < FINAL_PLUS_ONE ; VAR ++ )
#define FOREQ( VAR , INITIAL , FINAL ) for( decldecay_t( FINAL ) VAR = INITIAL ; VAR <= FINAL ; VAR ++ )
#define FOREQINV( VAR , INITIAL , FINAL ) for( decldecay_t( INITIAL ) VAR = INITIAL ; VAR + 1 > FINAL ; VAR -- )
#define ITR( ARRAY ) auto begin_ ## ARRAY = ARRAY .BE() , itr_ ## ARRAY = begin_ ## ARRAY , end_ ## ARRAY = ARRAY .EN()
#define FOR_ITR( ARRAY ) for( ITR( ARRAY ) , itr = itr_ ## ARRAY ; itr_ ## ARRAY != end_ ## ARRAY ; itr_ ## ARRAY ++ , itr++ )
#define RUN( VAR , ARRAY ) for( auto&& VAR : ARRAY )
#define REPEAT( HOW_MANY_TIMES ) FOR( VARIABLE_FOR_REPEAT_ ## HOW_MANY_TIMES , 0 , HOW_MANY_TIMES )
#define SET_PRECISION( DECIMAL_DIGITS ) cout << fixed << setprecision( DECIMAL_DIGITS )
#define RETURN( ... ) SOLVE_ONLY; COUT( __VA_ARGS__ ); return;
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
      CERR( "二分探索中：" , "L_BS =" , L_BS , "<=" , #ANSWER , "=" , ANSWER , "<=" , U_BS , "= U_BS : (" , #EXPRESSION , ") =" , EXPRESSION_BS , DIFFERENCE_BS > 0 ? ">" : DIFFERENCE_BS < 0 ? "<" : "=" , CONST_TARGET_BS , "= (" , #CONST_TARGET , ")" ); \
      if( DIFFERENCE_BS INEQUALITY_FOR_CHECK 0 ){			\
	U_BS = UPDATE_U;						\
      } else {								\
	L_BS = UPDATE_L;						\
      }									\
      ANSWER = UPDATE_ANSWER;						\
    }									\
    if( L_BS > U_BS ){							\
      CERR( "二分探索失敗：" , "L_BS =" , L_BS , ">" , U_BS , "= U_BS :" , #ANSWER , ":= (" , #MAXIMUM , ") + 1 =" , MAXIMUM + 1  ); \
      CERR( "二分探索マクロにミスがある可能性があります。変更前の版に戻してください。" ); \
      ANSWER = MAXIMUM + 1;						\
    } else {								\
      CERR( "二分探索終了：" , "L_BS =" , L_BS , "<=" , #ANSWER , "=" , ANSWER , "<=" , U_BS , "= U_BS" ); \
      CERR( "二分探索が成功したかを確認するために" , #EXPRESSION , "を計算します。" ); \
      CERR( "成功判定が不要な場合はこの計算を削除しても構いません。" );	\
      EXPRESSION_BS = ( EXPRESSION );					\
      CERR( "二分探索結果： (" , #EXPRESSION , ") =" , EXPRESSION_BS , ( EXPRESSION_BS > CONST_TARGET_BS ? ">" : EXPRESSION_BS < CONST_TARGET_BS ? "<" : "=" ) , CONST_TARGET_BS ); \
      if( EXPRESSION_BS DESIRED_INEQUALITY CONST_TARGET_BS ){		\
	CERR( "二分探索成功：" , #ANSWER , ":=" , ANSWER );		\
      } else {								\
	CERR( "二分探索失敗：" , #ANSWER , ":= (" , #MAXIMUM , ") + 1 =" , MAXIMUM + 1 ); \
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

// 尺取り法用
// VAR_TPA_LとVAR_TPA_RをINITで初期化し、VAR_TPA_RがCONTINUE_CONDITIONを満たす限り、
// 閉区間[VAR_TPA_L,VAR_TPA_R]が条件ON_CONDITIONを満たすか否かを判定し、
// trueになるかVAR_TAR_LがVAR_TAR_Rに追い付くまでVAR_TPA_Lの更新操作UPDATE_Lを繰り返し、
// その後VAR_TPA_Rの更新操作UPDATE_Rを行う。
// ON_CONDITIONがtrueとなる極大閉区間とその時点でのINFOをANSWERに格納する。
#define TPA( ANSWER , VAR_TPA , INIT , CONTINUE_CONDITION , UPDATE_L , UPDATE_R , ON_CONDITION , INFO ) \
  vector<tuple<decldecay_t( INIT ),decldecay_t( INIT ),decldecay_t( INFO )>> ANSWER{}; \
  {									\
    auto init_TPA = INIT;						\
    decldecay_t( ANSWER.front() ) ANSWER ## _temp = { init_TPA , init_TPA , INFO }; \
    auto ANSWER ## _prev = ANSWER ## _temp;				\
    auto& VAR_TPA ## _L = get<0>( ANSWER ## _temp );			\
    auto& VAR_TPA ## _R = get<1>( ANSWER ## _temp );			\
    auto& VAR_TPA ## _info = get<2>( ANSWER ## _temp );			\
    bool on_TPA_prev = false;						\
    while( true ){							\
      bool continuing = CONTINUE_CONDITION;				\
      bool on_TPA = continuing && ( ON_CONDITION );			\
      CERR( continuing ? "尺取り中" : "尺取り終了" , "： [L,R] = [" , VAR_TPA ## _L , "," , VAR_TPA ## _R , "] ," , on_TPA_prev ? "on" : "off" , "->" , on_TPA ? "on" : "off" , ", info =" , VAR_TPA ## _info );	\
      if( on_TPA_prev && ! on_TPA ){					\
	ANSWER.push_back( ANSWER ## _prev );				\
      }									\
      if( continuing ){							\
	if( on_TPA || VAR_TPA ## _L == VAR_TPA ## _R ){			\
	  ANSWER ## _prev = ANSWER ## _temp;				\
	  UPDATE_R;							\
	} else {							\
	  UPDATE_L;							\
	}								\
      } else {								\
	break;								\
      }									\
      on_TPA_prev = on_TPA;						\
    }									\
  }									\

// データ構造用
template <typename T> inline T Addition( const T& t0 , const T& t1 ) { return t0 + t1; }
template <typename T> inline T Xor( const T& t0 , const T& t1 ){ return t0 ^ t1; }
template <typename T> inline T Multiplication( const T& t0 , const T& t1 ) { return t0 * t1; }
template <typename T> inline const T& Zero() { static const T z{}; return z; }
template <typename T> inline const T& One() { static const T o = 1; return o; }\
template <typename T> inline T AdditionInv( const T& t ) { return -t; }
template <typename T> inline T Id( const T& v ) { return v; }
template <typename T> inline T Min( const T& a , const T& b ){ return a < b ? a : b; }
template <typename T> inline T Max( const T& a , const T& b ){ return a < b ? b : a; }

// グラフ用
template <typename T , template <typename...> typename V> inline auto Get( const V<T>& a ) { return [&]( const int& i = 0 ) -> const T& { return a[i]; }; }
template <typename T = int> inline vector<T> id( const int& size ) { vector<T> answer( size ); FOR( i , 0 , size ){ answer[i] = i; } return answer; }

// グリッド問題用
int H , W , H_minus , W_minus , HW;
vector<string> grid;
char walkable = '.' , unwalkable = '#';
inline T2<int> EnumHW( const int& v ) { return { v / W , v % W }; }
inline int EnumHW_inv( const T2<int>& ij ) { auto& [i,j] = ij; return i * W + j; }
const string direction[4] = {"U","R","D","L"};
inline int DirectionNumberOnGrid( const int& i , const int& j , const int& k , const int& h ){return i<k?2:i>k?0:j<h?1:j>h?3:(assert(false),-1);}
inline int DirectionNumberOnGrid( const int& v , const int& w ){auto [i,j]=EnumHW(v);auto [k,h]=EnumHW(w);return DirectionNumberOnGrid(i,j,k,h);}
inline int ReverseDirectionNumberOnGrid( const int& n ){assert(0<=n&&n<4);return(n+2)%4;}
inline vector<T2<int>> EdgeOnGrid( const T2<int>& v ){vector<T2<int>>answer{};auto[i,j]=v;if(i>0&&grid[i-1][j]==walkable){answer.push_back({i-1,j});}if(i+1<H&&grid[i+1][j]==walkable){answer.push_back({i+1,j});}if(j>0&&grid[i][j-1]==walkable){answer.push_back({i,j-1});}if(j+1<W&&grid[i][j+1]==walkable){answer.push_back({i,j+1});}return answer;}
inline vector<pair<T2<int>,ll>> WEdgeOnGrid( const T2<int>& v ){vector<pair<T2<int>,ll>>answer{};auto[i,j]=v;if(i>0&&grid[i-1][j]==walkable){answer.push_back({{i-1,j},1});}if(i+1<H&&grid[i+1][j]==walkable){answer.push_back({{i+1,j},1});}if(j>0&&grid[i][j-1]==walkable){answer.push_back({{i,j-1},1});}if(j+1<W&&grid[i][j+1]==walkable){answer.push_back({{i,j+1},1});}return answer;}
inline void SetWallStringOnGrid( const int& i , vector<string>& S ){if(S.empty()){S.resize(H);}cin>>S[i];assert(int(S[i].size())==W):}

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
#define IS basic_istream<char,Traits>
#define OS basic_ostream<char,Traits>
#define ST_AS static_assert
#define reMO_CO remove_const
#define is_COructible_v is_constructible_v
#define rBE rbegin
#define reSZ resize

// VVV 常設ライブラリは以下に挿入する。
#ifdef DEBUG
  #include "C:/Users/user/Documents/Programming/Contest/Template/include/a_Body.hpp"
#else
// Random（1KB）
ll GetRand(CRI Rand_min,CRI Rand_max){ll AN = time(NULL);RE AN * rand()%(Rand_max + 1 - Rand_min)+ Rand_min;}

// Set (1KB)
#define DC_OF_HASH(...)struct hash<__VA_ARGS__>{IN size_t OP()(CO __VA_ARGS__& n)CO;};
CL is_ordered{PU:is_ordered()= delete;TE <TY T> ST CE auto Check(CO T& t)-> decltype(t < t,true_type());ST CE false_type Check(...);TE <TY T> ST CE CO bool value = is_same_v< decltype(Check(declval<T>())),true_type >;};
TE <TY T>US Set = conditional_t<is_COructible_v<unordered_set<T>>,unordered_set<T>,conditional_t<is_ordered::value<T>,set<T>,VO>>;TE <TY T,TY U>US Map = conditional_t<is_COructible_v<unordered_map<T,int>>,unordered_map<T,U>,conditional_t<is_ordered::value<T>,map<T,U>,VO>>;

// Tuple（3KB）
#define DF_OF_OP_FOR_TUPLE(OPR)TE <TY T,TY U,TE <TY...> TY V> IN auto OP OPR ## =(V<T,U>& t0,CO V<T,U>& t1)-> decltype((get<0>(t0),t0))&{get<0>(t0)OPR ## = get<0>(t1);get<1>(t0)OPR ## = get<1>(t1);RE t0;}TE <TY T,TY U,TY V> IN tuple<T,U,V>& OP OPR ## =(tuple<T,U,V>& t0,CO tuple<T,U,V>& t1){get<0>(t0)OPR ## = get<0>(t1);get<1>(t0)OPR ## = get<1>(t1);get<2>(t0)OPR ## = get<2>(t1);RE t0;}TE <TY T,TY U,TY V,TY W> IN tuple<T,U,V,W>& OP OPR ## =(tuple<T,U,V,W>& t0,CO tuple<T,U,V,W>& t1){get<0>(t0)OPR ## = get<0>(t1);get<1>(t0)OPR ## = get<1>(t1);get<2>(t0)OPR ## = get<2>(t1);get<3>(t0)OPR ## = get<3>(t1);RE t0;}TE <TE <TY...> TY V,TY...ARGS> IN auto OP OPR(CO V<ARGS...>& t0,CO V<ARGS...>& t1)-> decldecay_t((get<0>(t0),t0)){auto t = t0;RE MO(t OPR ## = t1);}
#define DF_OF_HASH_FOR_TUPLE(PAIR)TE <TY T,TY U> IN size_t hash<PAIR<T,U>>::OP()(CO PAIR<T,U>& n)CO{ST CO size_t seed =(GetRand(1e3,1e8)<< 1)| 1;ST CO hash<T> h0;ST CO hash<U> h1;RE(h0(get<0>(n))* seed)^ h1(get<1>(n));}#define DF_OF_INCREMENT_FOR_TUPLE(INCR)TE <TY T,TY U,TE <TY...> TY V> IN auto OP INCR(V<T,U>& t)-> decldecay_t((get<0>(t),t))&{INCR get<0>(t);INCR get<1>(t);RE t;}TE <TY T,TY U,TY V> IN tuple<T,U,V>& OP INCR(tuple<T,U,V>& t){INCR get<0>(t);INCR get<1>(t);INCR get<2>(t);RE t;}TE <TY T,TY U,TY V,TY W> IN tuple<T,U,V,W>& OP INCR(tuple<T,U,V,W>& t){INCR get<0>(t);INCR get<1>(t);INCR get<2>(t);INCR get<3>(t);RE t;}
TE <CL Traits,TY T,TY U,TE <TY...> TY V> IN auto OP>>(IS& is,V<T,U>& arg)-> decltype((get<0>(arg),is))&{RE is >> get<0>(arg)>> get<1>(arg);}TE <CL Traits,TY T,TY U,TY V> IN IS& OP>>(IS& is,tuple<T,U,V>& arg){RE is >> get<0>(arg)>> get<1>(arg)>> get<2>(arg);}TE <CL Traits,TY T,TY U,TY V,TY W> IN IS& OP>>(IS& is,tuple<T,U,V,W>& arg){RE is >> get<0>(arg)>> get<1>(arg)>> get<2>(arg)>> get<3>(arg);}TE <CL Traits,TY T,TY U,TE <TY...> TY V> IN auto OP<<(OS& os,CO V<T,U>& arg)-> decltype((get<0>(arg),os))&{RE os << get<0>(arg)<< " " << get<1>(arg);}TE <CL Traits,TY T,TY U,TY V> IN OS& OP<<(OS& os,CO tuple<T,U,V>& arg){RE os << get<0>(arg)<< " " << get<1>(arg)<< " " << get<2>(arg);}TE <CL Traits,TY T,TY U,TY V,TY W> IN OS& OP<<(OS& os,CO tuple<T,U,V,W>& arg){RE os << get<0>(arg)<< " " << get<1>(arg)<< " " << get<2>(arg)<< " " << get<3>(arg);}DF_OF_OP_FOR_TUPLE(+);DF_OF_OP_FOR_TUPLE(-);DF_OF_OP_FOR_TUPLE(*);DF_OF_OP_FOR_TUPLE(/);DF_OF_OP_FOR_TUPLE(%);DF_OF_INCREMENT_FOR_TUPLE(++);DF_OF_INCREMENT_FOR_TUPLE(--);
TE <TY T,TY U> DC_OF_HASH(pair<T,U>);TE <TY T,TY U> DC_OF_HASH(tuple<T,U>);TE <TY T,TY U,TY V> DC_OF_HASH(tuple<T,U,V>);TE <TY T,TY U,TY V,TY W> DC_OF_HASH(tuple<T,U,V,W>);
DF_OF_HASH_FOR_TUPLE(pair);DF_OF_HASH_FOR_TUPLE(tuple);TE <TY T,TY U,TY V> IN size_t hash<tuple<T,U,V>>::OP()(CO tuple<T,U,V>& n)CO{ST CO size_t seed =(GetRand(1e3,1e8)<< 1)| 1;ST CO hash<pair<T,U>> h01;ST CO hash<V> h2;RE(h01({get<0>(n),get<1>(n)})* seed)^ h2(get<2>(n));}TE <TY T,TY U,TY V,TY W> IN size_t hash<tuple<T,U,V,W>>::OP()(CO tuple<T,U,V,W>& n)CO{ST CO size_t seed =(GetRand(1e3,1e8)<< 1)| 1;ST CO hash<pair<T,U>> h01;ST CO hash<pair<V,W>> h23;RE(h01({get<0>(n),get<1>(n)})* seed)^ h23({get<2>(n),get<3>(n)});}

// Vector（2KB）
#define DF_OF_COUT_FOR_VE(V)TE <CL Traits,TY Arg> IN OS& OP<<(OS& os,CO V<Arg>& arg){auto BE = arg.BE(),EN = arg.EN();auto IT = BE;WH(IT != EN){(IT == BE?os:os << " ")<< *IT;IT++;}RE os;}
#define DF_OF_OP_FOR_VE(V,OPR)TE <TY T> IN V<T>& OP OPR ## =(V<T>& a,CO T& t){for(auto& s:a){s OPR ## = t;}RE a;}TE <TY T> IN V<T>& OP OPR ## =(V<T>& a0,CO V<T>& a1){CO size_t SZ = a0.SZ();AS(a0.SZ()<= a1.SZ());auto IT0 = a0.BE(),EN0 = a0.EN(),IT1 = a1.BE();WH(IT0 != EN0){IT0 OPR ## = IT1;}RE a0;}TE <TY T,TY U> IN V<T> OP OPR(V<T> a,CO U& u){RE MO(a OPR ## = u);}
#define DF_OF_INCREMENT_FOR_VE(V,INCR)TE <TY T> IN V<T>& OP INCR(V<T>& a){for(auto& i:a){INCR i;}RE a;}
#define DF_OF_OPS_FOR_VE(V)DF_OF_OP_FOR_VE(V,+);DF_OF_OP_FOR_VE(V,-);DF_OF_OP_FOR_VE(V,*);DF_OF_OP_FOR_VE(V,/);DF_OF_OP_FOR_VE(V,%);DF_OF_INCREMENT_FOR_VE(V,++);DF_OF_INCREMENT_FOR_VE(V,--)
DF_OF_COUT_FOR_VE(VE);DF_OF_COUT_FOR_VE(LI);DF_OF_COUT_FOR_VE(set);DF_OF_COUT_FOR_VE(unordered_set);DF_OF_OPS_FOR_VE(VE);IN VO VariadicResize(CRI SZ){}TE <TY Arg,TY... ARGS> IN VO VariadicResize(CRI SZ,Arg& arg,ARGS&... args){arg.resize(SZ);VariadicResize(SZ,args...);}TE <TY T> VO sort(VE<T>& a,CO bool& reversed = false){if(reversed){ST auto comp =[](CO T& t0,CO T& t1){RE t1 < t0;};sort(a.BE(),a.EN(),comp);}else{sort(a.BE(),a.EN());}}

// StdStream（1KB）
TE <CL Traits> IN IS& VariadicCin(IS& is){RE is;}TE <CL Traits,TY Arg,TY... ARGS> IN IS& VariadicCin(IS& is,Arg& arg,ARGS&... args){RE VariadicCin(is >> arg,args...);}TE <CL Traits> IN IS& VariadicSet(IS& is,CRI i){RE is;}TE <CL Traits,TY Arg,TY... ARGS> IN IS& VariadicSet(IS& is,CRI i,Arg& arg,ARGS&... args){RE VariadicSet(is >> arg[i],i,args...);}TE <CL Traits> IN IS& VariadicGetline(IS& is,CO char& separator){RE is;}TE <CL Traits,TY Arg,TY... ARGS> IN IS& VariadicGetline(IS& is,CO char& separator,Arg& arg,ARGS&... args){RE VariadicGetline(getline(is,arg,separator),separator,args...);}TE <CL Traits,TY Arg> IN OS& VariadicCout(OS& os,CO Arg& arg){RE os << arg;}TE <CL Traits,TY Arg1,TY Arg2,TY... ARGS> IN OS& VariadicCout(OS& os,CO Arg1& arg1,CO Arg2& arg2,CO ARGS&... args){RE VariadicCout(os << arg1 << " ",arg2,args...);}

// Algebra (4KB)
#define DC_OF_CPOINT(POINT)IN CO U& POINT()CO NE
#define DC_OF_POINT(POINT)IN U& POINT()NE
#define DF_OF_CPOINT(POINT)TE <TY U> IN CO U& VirtualPointedSet<U>::POINT()CO NE{RE Point();}
#define DF_OF_POINT(POINT)TE <TY U> IN U& VirtualPointedSet<U>::POINT()NE{RE Point();}
TE <TY U>CL UnderlyingSet{PU:US type = U;};TE <TY U>CL VirtualPointedSet:VI PU UnderlyingSet<U>{PU:VI CO U& Point()CO NE = 0;VI U& Point()NE = 0;DC_OF_CPOINT(Unit);DC_OF_CPOINT(Zero);DC_OF_CPOINT(One);DC_OF_CPOINT(Infty);DC_OF_POINT(init);DC_OF_POINT(root);};TE <TY U>CL PointedSet:VI PU VirtualPointedSet<U>{PU:U m_b_U;IN PointedSet(U b_u = U());IN CO U& Point()CO NE;IN U& Point()NE;};TE <TY U>CL VirtualNSet:VI PU UnderlyingSet<U>{PU:VI U Transfer(CO U& u)= 0;IN U Inverse(CO U& u);};TE <TY U,TY F_U>CL AbstractNSet:VI PU VirtualNSet<U>{PU:F_U m_f_U;IN AbstractNSet(F_U f_U);IN U Transfer(CO U& u);};TE <TY U>CL VirtualMagma:VI PU UnderlyingSet<U>{PU:VI U Product(U u0,CO U& u1)= 0;IN U Sum(U u0,CO U& u1);};TE <TY U = ll>CL AdditiveMagma:VI PU VirtualMagma<U>{PU:IN U Product(U u0,CO U& u1);};TE <TY U = ll>CL MultiplicativeMagma:VI PU VirtualMagma<U>{PU:IN U Product(U u0,CO U& u1);};TE <TY U,TY M_U>CL AbstractMagma:VI PU VirtualMagma<U>{PU:M_U m_m_U;IN AbstractMagma(M_U m_U);IN U Product(U u0,CO U& u1);};
TE <TY U> IN PointedSet<U>::PointedSet(U b_U):m_b_U(MO(b_U)){}TE <TY U> IN CO U& PointedSet<U>::Point()CO NE{RE m_b_U;}TE <TY U> IN U& PointedSet<U>::Point()NE{RE m_b_U;}DF_OF_CPOINT(Unit);DF_OF_CPOINT(Zero);DF_OF_CPOINT(One);DF_OF_CPOINT(Infty);DF_OF_POINT(init);DF_OF_POINT(root);TE <TY U,TY F_U> IN AbstractNSet<U,F_U>::AbstractNSet(F_U f_U):m_f_U(MO(f_U)){ST_AS(is_invocable_r_v<U,F_U,U>);}TE <TY U,TY F_U> IN U AbstractNSet<U,F_U>::Transfer(CO U& u){RE m_f_U(u);}TE <TY U> IN U VirtualNSet<U>::Inverse(CO U& u){RE Transfer(u);}TE <TY U,TY M_U> IN AbstractMagma<U,M_U>::AbstractMagma(M_U m_U):m_m_U(MO(m_U)){ST_AS(is_invocable_r_v<U,M_U,U,U>);}TE <TY U> IN U AdditiveMagma<U>::Product(U u0,CO U& u1){RE MO(u0 += u1);}TE <TY U> IN U MultiplicativeMagma<U>::Product(U u0,CO U& u1){RE MO(u0 *= u1);}TE <TY U,TY M_U> IN U AbstractMagma<U,M_U>::Product(U u0,CO U& u1){RE m_m_U(MO(u0),u1);}TE <TY U> IN U VirtualMagma<U>::Sum(U u0,CO U& u1){RE Product(MO(u0),u1);}TE <TY U>CL VirtualMonoid:VI PU VirtualMagma<U>,VI PU VirtualPointedSet<U>{};TE <TY U = ll>CL AdditiveMonoid:VI PU VirtualMonoid<U>,PU AdditiveMagma<U>,PU PointedSet<U>{};TE <TY U = ll>CL MultiplicativeMonoid:VI PU VirtualMonoid<U>,PU MultiplicativeMagma<U>,PU PointedSet<U>{PU:IN MultiplicativeMonoid(U e_U);};TE <TY U,TY M_U>CL AbstractMonoid:VI PU VirtualMonoid<U>,PU AbstractMagma<U,M_U>,PU PointedSet<U>{PU:IN AbstractMonoid(M_U m_U,U e_U);};TE <TY U> IN MultiplicativeMonoid<U>::MultiplicativeMonoid(U e_U):PointedSet<U>(MO(e_U)){}TE <TY U,TY M_U> IN AbstractMonoid<U,M_U>::AbstractMonoid(M_U m_U,U e_U):AbstractMagma<U,M_U>(MO(m_U)),PointedSet<U>(MO(e_U)){}TE <TY U>CL VirtualGroup:VI PU VirtualMonoid<U>,VI PU VirtualPointedSet<U>,VI PU VirtualNSet<U>{};TE <TY U = ll>CL AdditiveGroup:VI PU VirtualGroup<U>,PU AdditiveMonoid<U>{PU:IN U Transfer(CO U& u);};TE <TY U,TY M_U,TY I_U>CL AbstractGroup:VI PU VirtualGroup<U>,PU AbstractMonoid<U,M_U>,PU AbstractNSet<U,I_U>{PU:IN AbstractGroup(M_U m_U,U e_U,I_U i_U);};TE <TY U,TY M_U,TY I_U> IN AbstractGroup<U,M_U,I_U>::AbstractGroup(M_U m_U,U e_U,I_U i_U):AbstractMonoid<U,M_U>(MO(m_U),MO(e_U)),AbstractNSet<U,I_U>(MO(i_U)){}TE <TY U> IN U AdditiveGroup<U>::Transfer(CO U& u){RE -u;}

// Graph (5KB)
TE <TY T,TY R1,TY R2,TY E>CL VirtualGraph:VI PU UnderlyingSet<T>{PU:VI R1 Enumeration(CRI i)= 0;IN R2 Enumeration_inv(CO T& t);TE <TY PATH> IN R2 Enumeration_inv(CO PATH& p);IN VO Reset();VI CRI SZ()CO NE = 0;VI E& edge()NE = 0;VI ret_t<E,T> Edge(CO T& t)= 0;TE <TY PATH> IN ret_t<E,T> Edge(CO PATH& p);ST IN CO T& Vertex(CO T& t)NE;TE <TY PATH> ST IN CO T& Vertex(CO PATH& e)NE;VI R2 Enumeration_inv_Body(CO T& t)= 0;};TE <TY T,TY R1,TY R2,TY E>CL EdgeImplimentation:VI PU VirtualGraph<T,R1,R2,E>{PU:int m_SZ;E m_edge;IN EdgeImplimentation(CRI SZ,E edge);IN CRI SZ()CO NE;IN E& edge()NE;IN ret_t<E,T> Edge(CO T& t);};TE <TY E>CL Graph:PU EdgeImplimentation<int,CRI,CRI,E>{PU:IN Graph(CRI SZ,E edge);IN CRI Enumeration(CRI i);TE <TY F> IN Graph<F> GetGraph(F edge)CO;IN CRI Enumeration_inv_Body(CRI t);};TE <TY T,TY Enum_T,TY Enum_T_inv,TY E>CL EnumerationGraph:PU EdgeImplimentation<T,ret_t<Enum_T,int>,ret_t<Enum_T_inv,T>,E>{PU:Enum_T m_enum_T;Enum_T_inv m_enum_T_inv;IN EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge);IN ret_t<Enum_T,int> Enumeration(CRI i);TE <TY F> IN EnumerationGraph<T,Enum_T,Enum_T_inv,F> GetGraph(F edge)CO;IN ret_t<Enum_T_inv,T> Enumeration_inv_Body(CO T& t);};TE <TY Enum_T,TY Enum_T_inv,TY E> EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge)-> EnumerationGraph<decldecay_t(declval<Enum_T>()(0)),Enum_T,Enum_T_inv,E>;TE <TY T,TY E>CL MemorisationGraph:PU EdgeImplimentation<T,T,CRI,E>{PU:int m_LE;VE<T> m_memory;Map<T,int> m_memory_inv;IN MemorisationGraph(CRI SZ,CO T& dummy,E edge);IN T Enumeration(CRI i);IN VO Reset();TE <TY F> IN MemorisationGraph<T,F> GetGraph(F edge)CO;IN CRI Enumeration_inv_Body(CO T& t);};
TE <TY T,TY R1,TY R2,TY E> IN EdgeImplimentation<T,R1,R2,E>::EdgeImplimentation(CRI SZ,E edge):m_SZ(SZ),m_edge(MO(edge)){ST_AS(is_COructible_v<T,R1> && is_COructible_v<int,R2> && is_invocable_v<E,T>);}TE <TY E> IN Graph<E>::Graph(CRI SZ,E edge):EdgeImplimentation<int,CRI,CRI,E>(SZ,MO(edge)){}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN EnumerationGraph<T,Enum_T,Enum_T_inv,E>::EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge):EdgeImplimentation<T,ret_t<Enum_T,int>,ret_t<Enum_T_inv,T>,E>(SZ,MO(edge)),m_enum_T(MO(enum_T)),m_enum_T_inv(MO(enum_T_inv)){}TE <TY T,TY E> IN MemorisationGraph<T,E>::MemorisationGraph(CRI SZ,CO T& dummy,E edge):EdgeImplimentation<T,T,CRI,E>(SZ,MO(edge)),m_LE(),m_memory(),m_memory_inv(){ST_AS(is_invocable_v<E,T>);}TE <TY E> IN CRI Graph<E>::Enumeration(CRI i){RE i;}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN ret_t<Enum_T,int> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::Enumeration(CRI i){RE m_enum_T(i);}TE <TY T,TY E> IN T MemorisationGraph<T,E>::Enumeration(CRI i){AS(0 <= i && i < m_LE);RE m_memory[i];}TE <TY T,TY R1,TY R2,TY E> IN R2 VirtualGraph<T,R1,R2,E>::Enumeration_inv(CO T& t){RE Enumeration_inv_Body(t);}TE <TY T,TY R1,TY R2,TY E> TE <TY PATH> IN R2 VirtualGraph<T,R1,R2,E>::Enumeration_inv(CO PATH& p){RE Enumeration_inv_Body(get<0>(p));}TE <TY E> IN CRI Graph<E>::Enumeration_inv_Body(CRI i){RE i;}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN ret_t<Enum_T_inv,T> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::Enumeration_inv_Body(CO T& t){RE m_enum_T_inv(t);}TE <TY T,TY E> IN CRI MemorisationGraph<T,E>::Enumeration_inv_Body(CO T& t){if(m_memory_inv.count(t)== 0){AS(m_LE < TH->SZ());m_memory.push_back(t);RE m_memory_inv[t]= m_LE++;}RE m_memory_inv[t];}TE <TY T,TY R1,TY R2,TY E> VO VirtualGraph<T,R1,R2,E>::Reset(){}TE <TY T,TY E> IN VO MemorisationGraph<T,E>::Reset(){m_LE = 0;m_memory.clear();m_memory_inv.clear();}TE <TY T,TY R1,TY R2,TY E> IN CRI EdgeImplimentation<T,R1,R2,E>::SZ()CO NE{RE m_SZ;}TE <TY T,TY R1,TY R2,TY E> IN E& EdgeImplimentation<T,R1,R2,E>::edge()NE{RE m_edge;}TE <TY T,TY R1,TY R2,TY E> IN ret_t<E,T> EdgeImplimentation<T,R1,R2,E>::Edge(CO T& t){RE m_edge(t);}TE <TY T,TY R1,TY R2,TY E> TE <TY PATH> IN ret_t<E,T> VirtualGraph<T,R1,R2,E>::Edge(CO PATH& p){RE Edge(get<0>(p));}TE <TY E> TE <TY F> IN Graph<F> Graph<E>::GetGraph(F edge)CO{RE Graph<F>(TH->SZ(),MO(edge));}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> TE <TY F> IN EnumerationGraph<T,Enum_T,Enum_T_inv,F> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::GetGraph(F edge)CO{RE EnumerationGraph<T,Enum_T,Enum_T_inv,F>(TH->SZ(),m_enum_T,m_enum_T_inv,MO(edge));}TE <TY T,TY E> TE <TY F> IN MemorisationGraph<T,F> MemorisationGraph<T,E>::GetGraph(F edge)CO{RE MemorisationGraph<T,F>(TH->SZ(),MO(edge));}TE <TY T,TY R1,TY R2,TY E> IN CO T& VirtualGraph<T,R1,R2,E>::Vertex(CO T& t)NE{RE t;}TE <TY T,TY R1,TY R2,TY E> TE <TY PATH> IN CO T& VirtualGraph<T,R1,R2,E>::Vertex(CO PATH& e)NE{RE Vertex(get<0>(e));}

// ConstexprModulo (7KB)
CEXPR(uint,P,998244353);
#define RP Represent
#define DeRP Derepresent

TE <uint M,TY INT> CE INT RS(INT n)NE{RE MO(n < 0?((((++n)*= -1)%= M)*= -1)+= M - 1:n < INT(M)?n:n %= M);}TE <TY INT> CE INT& RSP(INT& n)NE{CE CO uint trunc =(1 << 23)- 1;INT n_u = n >> 23;n &= trunc;INT n_uq =(n_u / 7)/ 17;n_u -= n_uq * 119;n += n_u << 23;RE n < n_uq?n += P - n_uq:n -= n_uq;}
TE <uint M> CL Mod;TE <uint M>CL COantsForMod{PU:COantsForMod()= delete;ST CE CO uint g_memory_bound = 1e6;ST CE CO uint g_memory_LE = M < g_memory_bound?M:g_memory_bound;ST CE uint g_M_minus = M - 1;ST CE int g_order_minus_1 = M - 2;ST CE int g_order_minus_1_neg = -g_order_minus_1;};
#define DC_OF_CM_FOR_MOD(OPR)CE bool OP OPR(CO Mod<M>& n)CO NE
#define DC_OF_AR_FOR_MOD(OPR,EX)CE Mod<M> OP OPR(Mod<M> n)CO EX;
#define DF_OF_CM_FOR_MOD(OPR)TE <uint M> CE bool Mod<M>::OP OPR(CO Mod<M>& n)CO NE{RE m_n OPR n.m_n;}
#define DF_OF_AR_FOR_MOD(OPR,EX,LEFT,OPR2)TE <uint M> CE Mod<M> Mod<M>::OP OPR(Mod<M> n)CO EX{RE MO(LEFT OPR2 ## = *TH);}TE <uint M,TY T> CE Mod<M> OP OPR(T n0,CO Mod<M>& n1)EX{RE MO(Mod<M>(MO(n0))OPR ## = n1);}
TE <uint M>CL Mod{PU:uint m_n;CE Mod()NE;CE Mod(CO Mod<M>& n)NE;CE Mod(Mod<M>&& n)NE;TE <TY T> CE Mod(T n)NE;CE Mod<M>& OP=(Mod<M> n)NE;CE Mod<M>& OP+=(CO Mod<M>& n)NE;CE Mod<M>& OP-=(CO Mod<M>& n)NE;CE Mod<M>& OP*=(CO Mod<M>& n)NE;IN Mod<M>& OP/=(Mod<M> n);TE <TY INT> CE Mod<M>& OP<<=(INT n);TE <TY INT> CE Mod<M>& OP>>=(INT n);CE Mod<M>& OP++()NE;CE Mod<M> OP++(int)NE;CE Mod<M>& OP--()NE;CE Mod<M> OP--(int)NE;DC_OF_CM_FOR_MOD(==);DC_OF_CM_FOR_MOD(!=);DC_OF_CM_FOR_MOD(<);DC_OF_CM_FOR_MOD(<=);DC_OF_CM_FOR_MOD(>);DC_OF_CM_FOR_MOD(>=);DC_OF_AR_FOR_MOD(+,NE);DC_OF_AR_FOR_MOD(-,NE);DC_OF_AR_FOR_MOD(*,NE);DC_OF_AR_FOR_MOD(/,);TE <TY INT> CE Mod<M> OP^(INT EX)CO;TE <TY INT> CE Mod<M> OP<<(INT n)CO;TE <TY INT> CE Mod<M> OP>>(INT n)CO;CE Mod<M> OP-()CO NE;CE Mod<M>& SignInvert()NE;IN Mod<M>& Invert();TE <TY INT> CE Mod<M>& PW(INT EX);CE VO swap(Mod<M>& n)NE;CE CRUI RP()CO NE;ST CE Mod<M> DeRP(uint n)NE;ST IN CO Mod<M>& Inverse(CRUI n);ST IN CO Mod<M>& Factorial(CRUI n);ST IN CO Mod<M>& FactorialInverse(CRUI n);ST IN Mod<M> Combination(CRUI n,CRUI i);ST IN CO Mod<M>& zero()NE;ST IN CO Mod<M>& one()NE;TE <TY INT> CE Mod<M>& PositivePW(INT EX)NE;TE <TY INT> CE Mod<M>& NonNegativePW(INT EX)NE;US COants = COantsForMod<M>;};
US MP = Mod<P>;
TE <uint M> CE Mod<M>::Mod()NE:m_n(){}TE <uint M> CE Mod<M>::Mod(CO Mod<M>& n)NE:m_n(n.m_n){}TE <uint M> CE Mod<M>::Mod(Mod<M>&& n)NE:m_n(MO(n.m_n)){}TE <uint M> TE <TY T> CE Mod<M>::Mod(T n)NE:m_n(RS<M>(MO(n))){ST_AS(is_COructible_v<uint,decay_t<T> >);}TE <uint M> CE Mod<M>& Mod<M>::OP=(Mod<M> n)NE{m_n = MO(n.m_n);RE *TH;}TE <uint M> CE Mod<M>& Mod<M>::OP+=(CO Mod<M>& n)NE{(m_n += n.m_n)< M?m_n:m_n -= M;RE *TH;}TE <uint M> CE Mod<M>& Mod<M>::OP-=(CO Mod<M>& n)NE{m_n < n.m_n?(m_n += M)-= n.m_n:m_n -= n.m_n;RE *TH;}TE <uint M> CE Mod<M>& Mod<M>::OP*=(CO Mod<M>& n)NE{m_n = MO(ull(m_n)* n.m_n)% M;RE *TH;}TE <> CE MP& MP::OP*=(CO MP& n)NE{ull m_n_copy = m_n;m_n = MO((m_n_copy *= n.m_n)< P?m_n_copy:RSP(m_n_copy));RE *TH;}TE <uint M> IN Mod<M>& Mod<M>::OP/=(Mod<M> n){RE OP*=(n.Invert());}TE <uint M> TE <TY INT> CE Mod<M>& Mod<M>::OP<<=(INT n){AS(n >= 0);RE *TH *= Mod<M>(2).NonNegativePW(MO(n));}TE <uint M> TE <TY INT> CE Mod<M>& Mod<M>::OP>>=(INT n){AS(n >=0);WH(n-- > 0){((m_n & 1)== 0?m_n:m_n += M)>>= 1;}RE *TH;}TE <uint M> CE Mod<M>& Mod<M>::OP++()NE{m_n < COants::g_M_minus?++m_n:m_n = 0;RE *TH;}TE <uint M> CE Mod<M> Mod<M>::OP++(int)NE{Mod<M> n{*TH};OP++();RE n;}TE <uint M> CE Mod<M>& Mod<M>::OP--()NE{m_n == 0?m_n = COants::g_M_minus:--m_n;RE *TH;}TE <uint M> CE Mod<M> Mod<M>::OP--(int)NE{Mod<M> n{*TH};OP--();RE n;}DF_OF_CM_FOR_MOD(==);DF_OF_CM_FOR_MOD(!=);DF_OF_CM_FOR_MOD(>);DF_OF_CM_FOR_MOD(>=);DF_OF_CM_FOR_MOD(<);DF_OF_CM_FOR_MOD(<=);DF_OF_AR_FOR_MOD(+,NE,n,+);DF_OF_AR_FOR_MOD(-,NE,n.SignInvert(),+);DF_OF_AR_FOR_MOD(*,NE,n,*);DF_OF_AR_FOR_MOD(/,,n.Invert(),*);TE <uint M> TE <TY INT> CE Mod<M> Mod<M>::OP^(INT EX)CO{RE MO(Mod<M>(*TH).PW(MO(EX)));}TE <uint M> TE <TY INT> CE Mod<M> Mod<M>::OP<<(INT n)CO{RE MO(Mod<M>(*TH)<<= MO(n));}TE <uint M> TE <TY INT> CE Mod<M> Mod<M>::OP>>(INT n)CO{RE MO(Mod<M>(*TH)>>= MO(n));}TE <uint M> CE Mod<M> Mod<M>::OP-()CO NE{RE MO(Mod<M>(*TH).SignInvert());}TE <uint M> CE Mod<M>& Mod<M>::SignInvert()NE{m_n > 0?m_n = M - m_n:m_n;RE *TH;}TE <uint M> IN Mod<M>& Mod<M>::Invert(){AS(m_n != 0);uint m_n_neg;RE m_n < COants::g_memory_LE?(m_n = Inverse(m_n).m_n,*TH):((m_n_neg = M - m_n)< COants::g_memory_LE)?(m_n = M - Inverse(m_n_neg).m_n,*TH):NonNegativePW(COants::g_order_minus_1);}TE <uint M> TE <TY INT> CE Mod<M>& Mod<M>::PositivePW(INT EX)NE{Mod<M> PW{*TH};EX--;WH(EX != 0){(EX & 1)== 1?*TH *= PW:*TH;EX >>= 1;PW *= PW;}RE *TH;}TE <uint M> TE <TY INT> CE Mod<M>& Mod<M>::NonNegativePW(INT EX)NE{RE EX == 0?(m_n = 1,*TH):PositivePW(MO(EX));}TE <uint M> TE <TY INT> CE Mod<M>& Mod<M>::PW(INT EX){bool neg = EX < 0;AS(!(neg && m_n == 0));RE neg?PositivePW(MO(EX *= COants::g_order_minus_1_neg)):NonNegativePW(MO(EX));}TE <uint M> CE VO Mod<M>::swap(Mod<M>& n)NE{std::swap(m_n,n.m_n);}TE <uint M> IN CO Mod<M>& Mod<M>::Inverse(CRUI n){AS(n < COants::g_memory_LE);ST Mod<M> memory[COants::g_memory_LE]={zero(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory[LE_curr].m_n = M - memory[M % LE_curr].m_n * ull(M / LE_curr)% M;LE_curr++;}RE memory[n];}TE <uint M> IN CO Mod<M>& Mod<M>::Factorial(CRUI n){if(M <= n){RE zero();}AS(n < COants::g_memory_LE);ST Mod<M> memory[COants::g_memory_LE]={one(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){(memory[LE_curr]= memory[LE_curr - 1])*= LE_curr;LE_curr++;}RE memory[n];}TE <uint M> IN CO Mod<M>& Mod<M>::FactorialInverse(CRUI n){ST Mod<M> memory[COants::g_memory_LE]={one(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){(memory[LE_curr]= memory[LE_curr - 1])*= Inverse(LE_curr);LE_curr++;}RE memory[n];}TE <uint M> IN Mod<M> Mod<M>::Combination(CRUI n,CRUI i){RE i <= n?Factorial(n)* FactorialInverse(i)* FactorialInverse(n - i):zero();}TE <uint M> CE CRUI Mod<M>::RP()CO NE{RE m_n;}TE <uint M> CE Mod<M> Mod<M>::DeRP(uint n)NE{Mod<M> n_copy{};n_copy.m_n = MO(n);RE n_copy;}TE <uint M> IN CO Mod<M>& Mod<M>::zero()NE{ST CE CO Mod<M> z{};RE z;}TE <uint M> IN CO Mod<M>& Mod<M>::one()NE{ST CE CO Mod<M> o{1};RE o;}TE <uint M> IN Mod<M> Inverse(CO Mod<M>& n){RE MO(Mod<M>(n).Invert());}TE <uint M,TY INT> CE Mod<M> PW(Mod<M> n,INT EX){RE MO(n.PW(MO(EX)));}TE <uint M> CE VO swap(Mod<M>& n0,Mod<M>& n1)NE{n0.swap(n1);}TE <uint M> IN string to_string(CO Mod<M>& n)NE{RE to_string(n.RP())+ " + " + to_string(M)+ "Z";}TE <uint M,CL Traits> IN basic_istream<char,Traits>& OP>>(basic_istream<char,Traits>& is,Mod<M>& n){ll m;is >> m;n = m;RE is;}TE <uint M,CL Traits> IN basic_ostream<char,Traits>& OP<<(basic_ostream<char,Traits>& os,CO Mod<M>& n){RE os << n.RP();}
#define DF_OF_HASH_FOR_MOD(MOD)IN size_t hash<MOD>::OP()(CO MOD& n)CO{ST CO hash<decltype(n.RP())> h;RE h(n.RP());}
TE <uint M> DC_OF_HASH(Mod<M>);TE <uint M> DF_OF_HASH_FOR_MOD(Mod<M>);
#endif
// AAA 常設ライブラリは以上に挿入する。

#define INCLUDE_LIBRARY
#include __FILE__

#endif // INCLUDE_LIBRARY

#endif // INCLUDE_SUB

#endif // INCLUDE_MAIN
