// 想定解に用いるので削除しない。
#ifndef INCLUDE_MODE
  #define INCLUDE_MODE
  // #define REACTIVE
  // #define USE_GETLINE
  /* #define SUBMIT_ONLY */
  #define DEBUG_OUTPUT
  #define SAMPLE_CHECK dummy
#endif
#ifdef INCLUDE_MAIN

void Solve()
{
  // 数 ../Contest/Template/Solve/Number.txt
  // 配列 ../Contest/Template/Solve/Array.txt
  // 文字列 ../Contest/Template/Solve/String.txt
  // グリッド ../Contest/Template/Solve/Grid.txt
  // グラフ ../Contest/Template/Solve/Graph.txt
  // 重み付きグラフ ../Contest/Template/Solve/WeightedGraph.txt
  // 区間クエリ ../Contest/Template/Solve/IntervalQuery.txt
  // 多種クエリ ../Contest/Template/Solve/MultiTypeQuery.txt

}
REPEAT_MAIN(1);

#else /* INCLUDE_MAIN */
#ifdef INCLUDE_SUB

/* COMPAREに使用。圧縮時は削除する。*/
MP Naive( const int& N , const int& M , const int& K , const bool& experiment = false )
{
  MP answer{};
  return answer;
}

/* COMPAREに使用。圧縮時は削除する。*/
MP Answer( const ll& N , const ll& M , const ll& K )
{
  MP answer{};
  return answer;
}

/* 圧縮時は中身だけ削除する。*/
inline void Experiment()
{
  /* // 1変数 ../Contest/Template/Experiment/OneVariable.txt */
  /* // 2変数 ../Contest/Template/Experiment/TwoVariable.txt */
  /* // 3変数 ../Contest/Template/Experiment/ThreeVariable.txt */

}

/* 圧縮時は中身だけ削除する。*/
inline void SmallTest()
{
  /* // 数 ../Contest/Template/SmallTest/Number.txt */
  /* // 配列 ../Contest/Template/SmallTest/Array.txt */
  /* // 順列 ../Contest/Template/SmallTest/Permutation.txt */
  /* // 文字列 ../Contest/Template/SmallTest/String.txt */
  /* // グリッド ../Contest/Template/SmallTest/Grid.txt */
  /* // グラフ ../Contest/Template/SmallTest/Graph.txt */
  /* // 重み付きグラフ ../Contest/Template/SmallTest/WeightedGraph.txt */
  /* // 区間クエリ ../Contest/Template/SmallTest/IntervalQuery.txt */
  
}

/* 圧縮時は中身だけ削除する。*/
inline void RandomTest( const int& test_case_num )
{
  /* // 数 ../Contest/Template/SmallTest/Number.txt */
  /* // 配列 ../Contest/Template/SmallTest/Array.txt */
  /* // 順列 ../Contest/Template/SmallTest/Permutation.txt */
  /* // 文字列 ../Contest/Template/SmallTest/String.txt */
  /* // グリッド ../Contest/Template/SmallTest/Grid.txt */
  /* // グラフ ../Contest/Template/SmallTest/Graph.txt */
  /* // 重み付きグラフ ../Contest/Template/SmallTest/WeightedGraph.txt  */
  /* // 区間クエリ ../Contest/Template/SmallTest/IntervalQuery.txt  */
  /* // 多種クエリ ../Contest/Template/SmallTest/MultiTypeQuery.txt */
  REPEAT( test_case_num ){

  }  
}

#define INCLUDE_MAIN
#include __FILE__
#else // INCLUDE_SUB
#ifdef INCLUDE_LIBRARY

/*
- BFS (6KB)
  Geometry/Graph/Algorithm/BreadthFirstSearch/compress.txt
  - AdicExhausiveSearch (11KB)
    Geometry/Graph/Algorithm/BreadthFirstSearch/AdicExhausiveSearch/compress.txt
  - BitExhausiveSearch (10KB)
    Geometry/Graph/Algorithm/BreadthFirstSearch/BitExhausiveSearch/compress.txt
  - ZeroOneBreadthFirstSearch (4KB)
    Geometry/Graph/Algorithm/BreadthFirstSearch/01/compress.txt
- BIT (5KB)
  SetTheory/DirectProduct/AffineSpace/BIT/compress.txt
  - IntervalAdd (9KB)
    SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/compress.txt
  - IntervalMax (9KB)
    SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/compress.txt
- CoordinateCompress (3KB)
  SetTheory/DirectProduct/CoordinateCompress/compress.txt
- DFS (6KB)
  Geometry/Graph/Algorithm/DepthFirstSearch/compress.txt
  - Tree (11KB)
    Geometry/Graph/Algorithm/DepthFirstSearch/Tree/compress.txt
- DifferenceSequence (9KB)
  SetTheory/DirectProduct/AffineSpace/DifferenceSequence/compress.txt
  - TwoDimensional (5KB)
    SetTheory/DirectProduct/AffineSpace/DifferenceSequence/TwoDimensional/compress.txt
- Dijkstra (6KB)
  Geometry/Graph/Algorithm/Dijkstra/compress.txt
  - MinimumCostFlow (16KB)
    Geometry/Graph/Algorithm/Dijkstra/Potentialised/MinimumCostFlow/compress.txt
- Divisor/Prime/Factorisation (4KB)
  Arithmetic/Divisor/Enumeration/compress.txt
- Knapsack (8KB)
  Combinatorial/KnapsackProblem/compress.txt
- LineSubset (7KB)
  SetTheory/Line/compress.txt
  - NonNegative (15KB)
    SetTheory/Line/NonNegative/compress.txt
  - Bounded (15KB)
    SetTheory/Line/Bounded/compress.txt
  - Compressed (15KB)
    SetTheory/Line/Compressed/compress.txt
- SqrtDecomposition
  - Monoid (5KB)
    SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/compress.txt
  - CommutativeDual (6KB)
    SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/Commutative/compress.txt
  - IntervalMultiplyLazy (18KB)
    SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/LazyEvaluation/IntervalMultiply/compress.txt
- TruncatedPolynomial (31KB)
  Polynomial/Truncate/compress.txt
  - NonProth (34KB)
    Polynomial/Truncate/NonProth/compress.txt
- Matrix (6KB)
  LinearAlgebra/compress.txt
  - TwoByTwo/TwoByOne (9KB)
    LinearAlgebra/TwoByOne/compress.txt
  - Rank (3KB)
    LinearAlgebra/Rank/Mod/compress.txt
- UnionFind (3KB)
  Geometry/Graph/Algorithm/UnionFindForest/compress.txt
*/
/* VVV 常設でないライブラリは以下に挿入する。*/


/* AAA 常設でないライブラリは以上に挿入する。*/

#define INCLUDE_SUB
#include __FILE__
#else /* INCLUDE_LIBRARY */
#ifdef DEBUG
  #define _GLIBCXX_DEBUG
#else
  #pragma GCC optimize ( "O3" )
  #pragma GCC optimize ( "unroll-loops" )
  #pragma GCC target ( "sse4.2,fma,avx2,popcnt,lzcnt,bmi2" )
  #define REPEAT_MAIN( BOUND ) START_MAIN; CEXPR( int , bound_test_case_num , BOUND ); int test_case_num = 1; if CE( bound_test_case_num > 1 ){ SET_ASSERT( test_case_num , 1 , bound_test_case_num ); } FINISH_MAIN
  #define FINISH_MAIN REPEAT( test_case_num ){ if CE( bound_test_case_num > 1 ){ CERR( "testcase " , VARIABLE_FOR_REPEAT_test_case_num , ":" ); } Solve(); CERR( "" ); } }
  #define DEXPR( LL , BOUND , VALUE1 , VALUE2 ) CEXPR( LL , BOUND , VALUE1 )
  #define ASSERT( A , MIN , MAX ) AS( ( MIN ) <= A && A <= ( MAX ) )
  #ifdef USE_GETLINE
    #define GETLINE_SEPARATE( SEPARATOR , ... ) string __VA_ARGS__; VariadicGetline( cin , SEPARATOR , __VA_ARGS__ )
    #define GETLINE( ... ) GETLINE_SEPARATE( '\n' , __VA_ARGS__ )
    #define SET_LL( A ) { GETLINE( A ## _str ); A = stoll( A ## _str ); }
  #else
    #define CIN( LL , ... ) LL __VA_ARGS__; VariadicCin( cin , __VA_ARGS__ )
    #define SET_A( I , N , ... ) VariadicResize( N + I , __VA_ARGS__ ); FOR( VARIABLE_FOR_SET_A , 0 , N ){ VariadicSet( cin , VARIABLE_FOR_SET_A + I , __VA_ARGS__ ); }
    #define CIN_A( LL , I , N , ... ) VE<LL> __VA_ARGS__; SET_A( I , N , __VA_ARGS__ )
    #define CIN_AA( LL , I0 , N0 , I1 , N1 , VAR ) VE<VE<LL>> VAR( N0 + I0 ); FOR( VARIABLE_FOR_CIN_AA , 0 , N0 ){ SET_A( I1 , N1 , VAR[VARIABLE_FOR_CIN_AA + I0] ); }
    #define SET_LL( A ) cin >> A
  #endif
  #define SET_ASSERT( A , MIN , MAX ) SET_LL( A ); ASSERT( A , MIN , MAX )
  #define SOLVE_ONLY 
  #define COUT( ... ) VariadicCout( cout , __VA_ARGS__ ) << ENDL
  #define COUTNS( ... ) VariadicCoutNonSep( cout , __VA_ARGS__ )
  #define CERR( ... ) 
  #define CERRNS( ... ) 
  #define COUT_A( I , N , A ) CoutArray( cout , I , N , A ) << ENDL
  #define CERR_A( I , N , A ) 
#endif
#ifdef REACTIVE
  #ifdef DEBUG
    #define RSET( A , ... ) A = __VA_ARGS__
  #else
    #define RSET( A , ... ) cin >> A
  #endif
  #define RCIN( LL , A , ... ) LL A; RSET( A , __VA_ARGS__ )
  #define ENDL endl
#else
  #define ENDL "\n"
#endif
#include <bits/stdc++.h>
using namespace std;
#define ATT __attribute__( ( target( "sse4.2,fma,avx2,popcnt,lzcnt,bmi2" ) ) )
#define START_MAIN int main(){ ios_base::sync_with_stdio( false ); cin.tie( nullptr )
#define START_WATCH chrono::system_clock::time_point watch = chrono::system_clock::now(); double loop_average_time = 0.0 , loop_start_time = 0.0 , current_time = 0.0; int loop_count = 0
#define CURRENT_TIME ( current_time = static_cast<double>( chrono::duration_cast<chrono::microseconds>( chrono::system_clock::now() - watch ).count() / 1000.0 ) )
#define CHECK_WATCH( TL_MS ) ( CURRENT_TIME , loop_count == 0 ? loop_start_time = current_time : loop_average_time = ( current_time - loop_start_time ) / loop_count , ++loop_count , current_time < TL_MS - loop_average_time * 2 - 100.0 )
#define CEXPR( LL , BOUND , VALUE ) constexpr LL BOUND = VALUE
#define SET_A_ASSERT( I , N , A , MIN , MAX ) FOR( VARIABLE_FOR_SET_A , 0 , N ){ SET_ASSERT( A[VARIABLE_FOR_SET_A + I] , MIN , MAX ); }
#define SET_AA_ASSERT( I0 , N0 , I1 , N1 , A , MIN , MAX ) FOR( VARIABLE_FOR_SET_AA0 , 0 , N0 ){ FOR( VARIABLE_FOR_SET_AA1 , 0 , N1 ){ SET_ASSERT( A[VARIABLE_FOR_SET_AA0 + I0][VARIABLE_FOR_SET_AA1 + I1] , MIN , MAX ); } }
#define CIN_ASSERT( A , MIN , MAX ) decldecay_t( MAX ) A; SET_ASSERT( A , MIN , MAX )
#define CIN_A_ASSERT( I , N , A , MIN , MAX ) vector<decldecay_t( MAX )> A( N + I ); SET_A_ASSERT( I , N , A , MIN , MAX )
#define CIN_AA_ASSERT( I0 , N0 , I1 , N1 , A , MIN , MAX ) vector A( N0 + I0 , vector<decldecay_t( MAX )>( N1 + I1 ) ); SET_AA_ASSERT( I0 , N0 , I1 , N1 , A , MIN , MAX )
#define OUTPUT_ARRAY( C , I , N , A ) FOR( VARIABLE_FOR_OUTPUT_ARRAY , I , N ){ C << A[VARIABLE_FOR_OUTPUT_ARRAY] << " \n"[VARIABLE_FOR_OUTPUT_ARRAY==(N)-1]; }
#define FOR( VAR , INITIAL , FINAL_PLUS_ONE ) for( decldecay_t( FINAL_PLUS_ONE ) VAR = INITIAL ; VAR < FINAL_PLUS_ONE ; VAR ++ )
#define FOREQ( VAR , INITIAL , FINAL ) for( decldecay_t( FINAL ) VAR = INITIAL ; VAR <= FINAL ; VAR ++ )
#define FOREQINV( VAR , INITIAL , FINAL ) for( decldecay_t( INITIAL ) VAR = INITIAL ; VAR + 1 > FINAL ; VAR -- )
#define ITR( ARRAY ) auto begin_ ## ARRAY = ARRAY .BE() , itr_ ## ARRAY = begin_ ## ARRAY , end_ ## ARRAY = ARRAY .EN()
#define FOR_ITR( ARRAY ) for( ITR( ARRAY ) , itr = itr_ ## ARRAY ; itr_ ## ARRAY != end_ ## ARRAY ; itr_ ## ARRAY ++ , itr++ )
#define RUN( ARRAY , ... ) for( auto&& __VA_ARGS__ : ARRAY )
#define REPEAT( HOW_MANY_TIMES ) FOR( VARIABLE_FOR_REPEAT_ ## HOW_MANY_TIMES , 0 , HOW_MANY_TIMES )
#define SET_PRECISION( DECIMAL_DIGITS ) cout << fixed << setprecision( DECIMAL_DIGITS ); cerr << fixed << setprecision( DECIMAL_DIGITS )
#define RETURN( ... ) SOLVE_ONLY; COUT( __VA_ARGS__ ); return;
#define COMPARE( ... ) auto naive = Naive( __VA_ARGS__ , true ); auto answer = Answer( __VA_ARGS__ ); bool match = naive == answer; CERR( "(" , #__VA_ARGS__ , ") == (" , __VA_ARGS__ , ") : Naive == " , naive , match ? "==" : "!=" , answer , "== Answer" ); if( !match ){ return; }

/* 型のエイリアス */
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

/* 圧縮用 */
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

/* VVV 常設ライブラリは以下に挿入する。*/
#ifdef DEBUG
  #include "C:/Users/user/Documents/Programming/Contest/Template/Local/a_Body.hpp"
#else
/* BinarySearch */
/* EXPRESSIONがANSWERの広義単調関数の時、EXPRESSION >= CONST_TARGETの整数解を格納。*/
#define BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , DESIRED_INEQUALITY , CONST_TARGET , INEQUALITY_FOR_CHECK , UPDATE_U , UPDATE_L , UPDATE_ANSWER ) \
  static_assert( ! is_same<decldecay_t( CONST_TARGET ),uint>::value && ! is_same<decldecay_t( CONST_TARGET ),ull>::value ); \
  ll ANSWER = MINIMUM;							\
  {									\
    ll ANSWER ## _L = MINIMUM;                                          \
    ll ANSWER ## _R = MAXIMUM;                                          \
    ANSWER = UPDATE_ANSWER;						\
    ll EXPRESSION_BS;							\
    const ll CONST_TARGET_BS = ( CONST_TARGET );			\
    ll DIFFERENCE_BS;							\
    while( ANSWER ## _L < ANSWER ## _R ){                               \
      DIFFERENCE_BS = ( EXPRESSION_BS = ( EXPRESSION ) ) - CONST_TARGET_BS; \
      CERR( "二分探索中:" , string{ #ANSWER } + "_L" , "=" , ANSWER ## _L , "<=" , #ANSWER , "=" , ANSWER , "<=" , ANSWER ## _R , "=" , string{ #ANSWER } + "_R" , ":" , #EXPRESSION , "=" , EXPRESSION_BS , DIFFERENCE_BS > 0 ? ">" : DIFFERENCE_BS < 0 ? "<" : "=" , CONST_TARGET_BS , "=" , #CONST_TARGET ); \
      if( DIFFERENCE_BS INEQUALITY_FOR_CHECK 0 ){			\
	ANSWER ## _R = UPDATE_U;                                        \
      } else {								\
	ANSWER ## _L = UPDATE_L;                                        \
      }									\
      ANSWER = UPDATE_ANSWER;						\
    }									\
    if( ANSWER ## _L > ANSWER ## _R ){                                  \
      CERR( "二分探索失敗:" , string{ #ANSWER } + "_L" , "=" , ANSWER ## _L , ">" , ANSWER ## _R , "=" , string{ #ANSWER } + "_R" , ":" , #ANSWER , ":=" , #MAXIMUM , "+ 1 =" , MAXIMUM + 1  ); \
      CERR( "二分探索マクロにミスがある可能性があります。変更前の版に戻してください。" ); \
      ANSWER = MAXIMUM + 1;						\
    } else {								\
      CERR( "二分探索終了:" , string{ #ANSWER } + "_L" , "=" , ANSWER ## _L , "<=" , #ANSWER , "=" , ANSWER , "<=" , ANSWER ## _R , "=" , string{ #ANSWER } + "_R" ); \
      CERR( "二分探索が成功したかを確認するために" , #EXPRESSION , "を計算します。" ); \
      CERR( "成功判定が不要な場合はこの計算を削除しても構いません。" );	\
      EXPRESSION_BS = ( EXPRESSION );					\
      CERR( "二分探索結果:" , #EXPRESSION , "=" , EXPRESSION_BS , ( EXPRESSION_BS > CONST_TARGET_BS ? ">" : EXPRESSION_BS < CONST_TARGET_BS ? "<" : "=" ) , CONST_TARGET_BS ); \
      if( EXPRESSION_BS DESIRED_INEQUALITY CONST_TARGET_BS ){		\
	CERR( "二分探索成功:" , #ANSWER , ":=" , ANSWER );		\
      } else {								\
	CERR( "二分探索失敗:" , #ANSWER , ":=" , #MAXIMUM , "+ 1 =" , MAXIMUM + 1 ); \
	CERR( "単調でないか、単調増加性と単調減少性を逆にしてしまったか、探索範囲内に解が存在しません。" ); \
	ANSWER = MAXIMUM + 1;						\
      }									\
    }									\
  }									\

/* 単調増加の時にEXPRESSION >= CONST_TARGETの最小解を格納。*/
#define BS1( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CONST_TARGET , >= , ANSWER , ANSWER + 1 , ( ANSWER ## _L + ANSWER ## _R ) / 2 )
/* 単調増加の時にEXPRESSION <= CONST_TARGETの最大解を格納。*/
#define BS2( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CONST_TARGET , > , ANSWER - 1 , ANSWER , ( ANSWER ## _L + 1 + ANSWER ## _R ) / 2 )
/* 単調減少の時にEXPRESSION >= CONST_TARGETの最大解を格納。*/
#define BS3( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CONST_TARGET , < , ANSWER - 1 , ANSWER , ( ANSWER ## _L + 1 + ANSWER ## _R ) / 2 )
/* 単調減少の時にEXPRESSION <= CONST_TARGETの最小解を格納。*/
#define BS4( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CONST_TARGET , <= , ANSWER , ANSWER + 1 , ( ANSWER ## _L + ANSWER ## _R ) / 2 )

/* TwoPoitnterApproach */
/* VAR_TPAは尺取り法用の変数名の接頭辞で、実際の変数名ではなく、_Lと_Rと_infoがつく。 */
/* ANSWER ## _temp = {VAR_TPA ## _L,VAR_TPA ## _R,VPA_TPA ## _info}を       */
/* {INIT,INIT,INFO_init}で初期化する。VPA_TPA ## _infoは区間和など。            */
/* ANSWER ## _tempがCONTINUE_CONDITIONを満たす限り、ANSWER ## _tempが          */
/* 条件ON_CONDITIONを満たすか否かを判定し、それがtrueになるか                     */
/* VAR_TAR ## _LがVAR_TAR ## _Rに追い付くまでVAR_TPA ## _LとVPA_TPA ## _infoの */
/* 更新操作UPDATE_Lを繰り返し、その後VAR_TPA ## _RとVPA_TPA ## _infoの           */
/* 更新操作UPDATE_Rを行う。（マクロとコンマの制約上、関数オブジェクトを用いる）        */
/* ON_CONDITIONがtrueとなる極大閉区間とその時点でのinfoをANSWERに格納する。         */
/* 例えば長さNの非負整数値配列Aで極大な正値区間とそこでの総和を取得したい場合           */
/* auto update_L = [&]( int& i_L , ll& i_info ){                             */
/*   i_info -= A[i_L++];                                                     */
/* };                                                                        */
/* auto update_R = [&]( int& i_R , ll& i_info ){                             */
/*   ++i_R < N ? i_info += A[i_R] : i_info;                                  */
/* };                                                                        */
/* TPA( interval , i , 0 , i_R < N , update_L( i_L , i_info ) , update_R( i_R , i_info ) , A[i_L] > 0 && A[i_R] > 0 , ll( A[0] ) ); */
/* とすればtuple<int,int,ll>値配列intervalに{左端,右端,総和}の列が格納される。      */
#define TPA( ANSWER , VAR_TPA , INIT , CONTINUE_CONDITION , UPDATE_L , UPDATE_R , ON_CONDITION , INFO_init ) \
  vector<tuple<decldecay_t( INIT ),decldecay_t( INIT ),decldecay_t( INFO_init )>> ANSWER{}; \
  {									\
    auto init_TPA = INIT;						\
    decldecay_t( ANSWER.front() ) ANSWER ## _temp = { init_TPA , init_TPA , INFO_init }; \
    auto ANSWER ## _prev = ANSWER ## _temp;				\
    auto& VAR_TPA ## _L = get<0>( ANSWER ## _temp );			\
    auto& VAR_TPA ## _R = get<1>( ANSWER ## _temp );			\
    auto& VAR_TPA ## _info = get<2>( ANSWER ## _temp );			\
    bool on_TPA_prev = false;						\
    while( true ){                                                      \
      bool continuing = CONTINUE_CONDITION;				\
      bool on_TPA = continuing && ( ON_CONDITION );			\
      CERR( continuing ? "尺取り中" : "尺取り終了" , ": [L,R] = [" , VAR_TPA ## _L , "," , VAR_TPA ## _R , "] ," , on_TPA_prev ? "on" : "off" , "->" , on_TPA ? "on" : "off" , ", info =" , VAR_TPA ## _info ); \
      if( on_TPA_prev && ! on_TPA ){					\
	ANSWER.push_back( ANSWER ## _prev );				\
	CERR( #ANSWER , "に" , ANSWER ## _prev , "を格納します。" );	\
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

/* Random (1KB)*/
ll GetRand(CRI Rand_min,CRI Rand_max){AS(Rand_min <= Rand_max);ll AN = time(NULL);RE AN * rand()%(Rand_max + 1 - Rand_min)+ Rand_min;}

/* Set (1KB)*/
#define DC_OF_HASH(...)struct hash<__VA_ARGS__>{IN size_t OP()(CO __VA_ARGS__& n)CO;};
CL is_ordered{PU:is_ordered()= delete;TE <TY T> ST CE auto Check(CO T& t)-> decltype(t < t,true_type());ST CE false_type Check(...);TE <TY T> ST CE CO bool value = is_same_v< decltype(Check(declval<T>())),true_type >;};
TE <TY T>US Set = conditional_t<is_COructible_v<unordered_set<T>>,unordered_set<T>,conditional_t<is_ordered::value<T>,set<T>,VO>>;

/* Tuple (5KB)*/
#define DF_OF_AR_FOR_TUPLE(OPR)TE <TY T,TY U,TE <TY...> TY V> IN auto OP OPR ## =(V<T,U>& t0,CO V<T,U>& t1)-> decltype((get<0>(t0),t0))&{get<0>(t0)OPR ## = get<0>(t1);get<1>(t0)OPR ## = get<1>(t1);RE t0;}TE <TY T,TY U,TY V> IN tuple<T,U,V>& OP OPR ## =(tuple<T,U,V>& t0,CO tuple<T,U,V>& t1){get<0>(t0)OPR ## = get<0>(t1);get<1>(t0)OPR ## = get<1>(t1);get<2>(t0)OPR ## = get<2>(t1);RE t0;}TE <TY T,TY U,TY V,TY W> IN tuple<T,U,V,W>& OP OPR ## =(tuple<T,U,V,W>& t0,CO tuple<T,U,V,W>& t1){get<0>(t0)OPR ## = get<0>(t1);get<1>(t0)OPR ## = get<1>(t1);get<2>(t0)OPR ## = get<2>(t1);get<3>(t0)OPR ## = get<3>(t1);RE t0;}TE <TY ARG,TY T,TY U,TE <TY...> TY V> IN auto OP OPR ## =(V<T,U>& t0,CO ARG& t1)-> decltype((get<0>(t0),t0))&{get<0>(t0)OPR ## = t1;get<1>(t0)OPR ## = t1;RE t0;}TE <TY ARG,TY T,TY U,TY V> IN tuple<T,U,V>& OP OPR ## =(tuple<T,U,V>& t0,CO ARG& t1){get<0>(t0)OPR ## = t1;get<1>(t0)OPR ## = t1;get<2>(t0)OPR ## = t1;RE t0;}TE <TY ARG,TY T,TY U,TY V,TY W> IN tuple<T,U,V,W>& OP OPR ## =(tuple<T,U,V,W>& t0,CO ARG& t1){get<0>(t0)OPR ## = t1;get<1>(t0)OPR ## = t1;get<2>(t0)OPR ## = t1;get<3>(t0)OPR ## = t1;RE t0;}TE <TE <TY...> TY V,TY...ARGS,TY ARG> IN auto OP OPR(CO V<ARGS...>& t0,CO ARG& t1)-> decldecay_t((get<0>(t0),t0)){auto t = t0;RE MO(t OPR ## = t1);}
#define DF_OF_INCREMENT_FOR_TUPLE(INCR)TE <TY T,TY U,TE <TY...> TY V> IN auto OP INCR(V<T,U>& t)-> decltype((get<0>(t),t))&{INCR get<0>(t);INCR get<1>(t);RE t;}TE <TY T,TY U,TY V> IN tuple<T,U,V>& OP INCR(tuple<T,U,V>& t){INCR get<0>(t);INCR get<1>(t);INCR get<2>(t);RE t;}TE <TY T,TY U,TY V,TY W> IN tuple<T,U,V,W>& OP INCR(tuple<T,U,V,W>& t){INCR get<0>(t);INCR get<1>(t);INCR get<2>(t);INCR get<3>(t);RE t;}
TE <CL Traits,TY T> IN IS& OP>>(IS& is,tuple<T>& arg){RE is >> get<0>(arg);}TE <CL Traits,TY T,TY U,TE <TY...> TY V> IN auto OP>>(IS& is,V<T,U>& arg)-> decltype((get<0>(arg),is))&{RE is >> get<0>(arg)>> get<1>(arg);}TE <CL Traits,TY T,TY U,TY V> IN IS& OP>>(IS& is,tuple<T,U,V>& arg){RE is >> get<0>(arg)>> get<1>(arg)>> get<2>(arg);}TE <CL Traits,TY T,TY U,TY V,TY W> IN IS& OP>>(IS& is,tuple<T,U,V,W>& arg){RE is >> get<0>(arg)>> get<1>(arg)>> get<2>(arg)>> get<3>(arg);}TE <CL Traits,TY T> IN OS& OP<<(OS& os,CO tuple<T>& arg){RE os << get<0>(arg);}TE <CL Traits,TY T,TY U,TE <TY...> TY V> IN auto OP<<(OS& os,CO V<T,U>& arg)-> decltype((get<0>(arg),os))&{RE os << get<0>(arg)<< " " << get<1>(arg);}TE <CL Traits,TY T,TY U,TY V> IN OS& OP<<(OS& os,CO tuple<T,U,V>& arg){RE os << get<0>(arg)<< " " << get<1>(arg)<< " " << get<2>(arg);}TE <CL Traits,TY T,TY U,TY V,TY W> IN OS& OP<<(OS& os,CO tuple<T,U,V,W>& arg){RE os << get<0>(arg)<< " " << get<1>(arg)<< " " << get<2>(arg)<< " " << get<3>(arg);}DF_OF_AR_FOR_TUPLE(+);TE <TY T,TY U,TE <TY...> TY V> IN auto OP-(CO V<T,U>& t)-> decltype(get<0>(t),t){RE{-get<0>(t),-get<1>(t)};}TE <TY T,TY U,TY V> IN tuple<T,U,V> OP-(CO tuple<T,U,V>& t){RE{-get<0>(t),-get<1>(t),-get<2>(t)};}TE <TY T,TY U,TY V,TY W> IN tuple<T,U,V,W> OP-(CO tuple<T,U,V,W>& t){RE{-get<0>(t),-get<1>(t),-get<2>(t),-get<3>(t)};}DF_OF_AR_FOR_TUPLE(-);DF_OF_AR_FOR_TUPLE(*);DF_OF_AR_FOR_TUPLE(/);DF_OF_AR_FOR_TUPLE(%);DF_OF_INCREMENT_FOR_TUPLE(++);DF_OF_INCREMENT_FOR_TUPLE(--);

#define DF_OF_HASH_FOR_TUPLE(PAIR)TE <TY T,TY U> IN size_t hash<PAIR<T,U>>::OP()(CO PAIR<T,U>& n)CO{ST CO size_t seed =(GetRand(1e3,1e8)<< 1)| 1;ST CO hash<T> h0;ST CO hash<U> h1;RE(h0(get<0>(n))* seed)^ h1(get<1>(n));}
TE <TY T> DC_OF_HASH(tuple<T>);TE <TY T,TY U> DC_OF_HASH(pair<T,U>);TE <TY T,TY U> DC_OF_HASH(tuple<T,U>);TE <TY T,TY U,TY V> DC_OF_HASH(tuple<T,U,V>);TE <TY T,TY U,TY V,TY W> DC_OF_HASH(tuple<T,U,V,W>);
TE <TY T> IN size_t hash<tuple<T>>::OP()(CO tuple<T>& n)CO{ST CO hash<T> h;RE h(get<0>(n));}DF_OF_HASH_FOR_TUPLE(pair);DF_OF_HASH_FOR_TUPLE(tuple);TE <TY T,TY U,TY V> IN size_t hash<tuple<T,U,V>>::OP()(CO tuple<T,U,V>& n)CO{ST CO size_t seed =(GetRand(1e3,1e8)<< 1)| 1;ST CO hash<pair<T,U>> h01;ST CO hash<V> h2;RE(h01({get<0>(n),get<1>(n)})* seed)^ h2(get<2>(n));}TE <TY T,TY U,TY V,TY W> IN size_t hash<tuple<T,U,V,W>>::OP()(CO tuple<T,U,V,W>& n)CO{ST CO size_t seed =(GetRand(1e3,1e8)<< 1)| 1;ST CO hash<pair<T,U>> h01;ST CO hash<pair<V,W>> h23;RE(h01({get<0>(n),get<1>(n)})* seed)^ h23({get<2>(n),get<3>(n)});}

/* Vector (2KB)*/
#define DF_OF_COUT_FOR_VE(V)TE <CL Traits,TY Arg> IN OS& OP<<(OS& os,CO V<Arg>& arg){auto BE = arg.BE(),EN = arg.EN();auto IT = BE;WH(IT != EN){(IT == BE?os:os << " ")<< *IT;IT++;}RE os;}
#define DF_OF_AR_FOR_VE(V,OPR)TE <TY T> IN V<T>& OP OPR ## =(V<T>& a,CO T& t){for(auto& s:a){s OPR ## = t;}RE a;}TE <TY T> IN V<T>& OP OPR ## =(V<T>& a0,CO V<T>& a1){AS(a0.SZ()<= a1.SZ());auto IT0 = a0.BE(),EN0 = a0.EN();auto IT1 = a1.BE();WH(IT0 != EN0){*(IT0++)OPR ## = *(IT1++);}RE a0;}TE <TY T,TY U> IN V<T> OP OPR(V<T> a,CO U& u){RE MO(a OPR ## = u);}
#define DF_OF_INCREMENT_FOR_VE(V,INCR)TE <TY T> IN V<T>& OP INCR(V<T>& a){for(auto& i:a){INCR i;}RE a;}
#define DF_OF_ARS_FOR_VE(V)DF_OF_AR_FOR_VE(V,+);DF_OF_AR_FOR_VE(V,-);DF_OF_AR_FOR_VE(V,*);DF_OF_AR_FOR_VE(V,/);DF_OF_AR_FOR_VE(V,%);DF_OF_INCREMENT_FOR_VE(V,++);DF_OF_INCREMENT_FOR_VE(V,--);TE <TY T> IN V<T> OP*(CO T& scalar,V<T> v){for(auto& t:v){t *= scalar;}RE MO(v);}
DF_OF_COUT_FOR_VE(VE);DF_OF_COUT_FOR_VE(LI);DF_OF_COUT_FOR_VE(set);DF_OF_COUT_FOR_VE(unordered_set);DF_OF_ARS_FOR_VE(VE);DF_OF_ARS_FOR_VE(LI);IN VO VariadicResize(CRI SZ){}TE <TY Arg,TY... ARGS> IN VO VariadicResize(CRI SZ,Arg& arg,ARGS&... args){arg.resize(SZ);VariadicResize(SZ,args...);}TE <TY V> IN auto Get(V& a){RE[&](CRI i = 0)-> CO decldecay_t(a[0])&{RE a[i];};}TE <TY T = int> IN VE<T> id(CRI SZ){VE<T> AN(SZ);FOR(i,0,SZ){AN[i]= i;}RE AN;}TE <TY T> VO Sort(VE<T>& a,CO bool& reversed = false){if(reversed){ST auto comp =[](CO T& t0,CO T& t1){RE t1 < t0;};sort(a.BE(),a.EN(),comp);}else{sort(a.BE(),a.EN());}}TE <TY T> IN VE<int> IndexSort(CO VE<T>& a,CO bool& reversed = false){auto index = id<int>(a.SZ());if(reversed){sort(index.BE(),index.EN(),[&](CRI i,CRI j){RE a[j]< a[i];});}else{sort(index.BE(),index.EN(),[&](CRI i,CRI j){RE a[i]< a[j];});}RE index;}

/* Map (1KB)*/
#define DF_OF_AR_FOR_MAP(MAP,OPR)TE <TY T,TY U> IN MAP<T,U>& OP OPR ## =(MAP<T,U>& a,CO pair<T,U>& v){a[v.first]OPR ## = v.second;RE a;}TE <TY T,TY U> IN MAP<T,U>& OP OPR ## =(MAP<T,U>& a0,CO MAP<T,U>& a1){for(auto&[t,u]:a1){a0[t]OPR ## = u;}RE a0;}TE <TY T,TY U,TY ARG> IN MAP<T,U> OP OPR(MAP<T,U> a,CO ARG& arg){RE MO(a OPR ## = arg);}
#define DF_OF_ARS_FOR_MAP(MAP)DF_OF_AR_FOR_MAP(MAP,+);DF_OF_AR_FOR_MAP(MAP,-);DF_OF_AR_FOR_MAP(MAP,*);DF_OF_AR_FOR_MAP(MAP,/);DF_OF_AR_FOR_MAP(MAP,%);
TE <TY T,TY U>US Map = conditional_t<is_COructible_v<unordered_map<T,int>>,unordered_map<T,U>,conditional_t<is_ordered::value<T>,map<T,U>,VO>>;
DF_OF_ARS_FOR_MAP(map);DF_OF_ARS_FOR_MAP(unordered_map);

/* StdStream (2KB)*/
TE <CL Traits> IN IS& VariadicCin(IS& is){RE is;}TE <CL Traits,TY Arg,TY... ARGS> IN IS& VariadicCin(IS& is,Arg& arg,ARGS&... args){RE VariadicCin(is >> arg,args...);}TE <CL Traits> IN IS& VariadicSet(IS& is,CRI i){RE is;}TE <CL Traits,TY Arg,TY... ARGS> IN IS& VariadicSet(IS& is,CRI i,Arg& arg,ARGS&... args){RE VariadicSet(is >> arg[i],i,args...);}TE <CL Traits> IN IS& VariadicGetline(IS& is,CO char& separator){RE is;}TE <CL Traits,TY Arg,TY... ARGS> IN IS& VariadicGetline(IS& is,CO char& separator,Arg& arg,ARGS&... args){RE VariadicGetline(getline(is,arg,separator),separator,args...);}TE <CL Traits,TY Arg> IN OS& VariadicCout(OS& os,Arg&& arg){RE os << forward<Arg>(arg);}TE <CL Traits,TY Arg1,TY Arg2,TY... ARGS> IN OS& VariadicCout(OS& os,Arg1&& arg1,Arg2&& arg2,ARGS&&... args){RE VariadicCout(os << forward<Arg1>(arg1)<< " ",forward<Arg2>(arg2),forward<ARGS>(args)...);}TE <CL Traits,TY Arg> IN OS& VariadicCoutNonSep(OS& os,Arg&& arg){RE os << forward<Arg>(arg);}TE <CL Traits,TY Arg1,TY Arg2,TY... ARGS> IN OS& VariadicCoutNonSep(OS& os,Arg1&& arg1,Arg2&& arg2,ARGS&&... args){RE VariadicCoutNonSep(os << forward<Arg1>(arg1),forward<Arg2>(arg2),forward<ARGS>(args)...);}TE <CL Traits,TY ARRAY> IN OS& CoutArray(OS& os,CRI i_start,CRI i_ulim,ARRAY&& a){for(int i = i_start;i < i_ulim;i++){(i == i_start?os:(os << " "))<< a[i];}RE os;}

/* Module (6KB)*/
#define DC_OF_CPOINT(POINT)IN CO U& POINT()CO NE
#define DC_OF_POINT(POINT)IN U& POINT()NE
#define DF_OF_CPOINT(POINT)TE <TY U> IN CO U& VirtualPointedSet<U>::POINT()CO NE{RE Point();}
#define DF_OF_POINT(POINT)TE <TY U> IN U& VirtualPointedSet<U>::POINT()NE{RE Point();}
TE <TY U>CL UnderlyingSet{PU:US type = U;};TE <TY U>CL VirtualPointedSet:VI PU UnderlyingSet<U>{PU:VI CO U& Point()CO NE = 0;VI U& Point()NE = 0;DC_OF_CPOINT(Unit);DC_OF_CPOINT(Zero);DC_OF_CPOINT(One);DC_OF_CPOINT(Infty);DC_OF_POINT(init);DC_OF_POINT(root);};TE <TY U>CL PointedSet:VI PU VirtualPointedSet<U>{PU:U m_b_U;IN PointedSet(U b_u = U());IN CO U& Point()CO NE;IN U& Point()NE;};TE <TY U>CL VirtualNSet:VI PU UnderlyingSet<U>{PU:VI U Transfer(CO U& u)= 0;IN U Inverse(CO U& u);};TE <TY U,TY F_U>CL AbstractNSet:VI PU VirtualNSet<U>{PU:F_U m_f_U;IN AbstractNSet(F_U f_U);IN AbstractNSet<U,F_U>& OP=(CO AbstractNSet&)NE;IN U Transfer(CO U& u);};TE <TY U>CL VirtualMagma:VI PU UnderlyingSet<U>{PU:VI U Product(U u0,CO U& u1)= 0;IN U Sum(U u0,CO U& u1);};TE <TY U = ll>CL AdditiveMagma:VI PU VirtualMagma<U>{PU:IN U Product(U u0,CO U& u1);};TE <TY U = ll>CL MultiplicativeMagma:VI PU VirtualMagma<U>{PU:IN U Product(U u0,CO U& u1);};TE <TY U,TY M_U>CL AbstractMagma:VI PU VirtualMagma<U>{PU:M_U m_m_U;IN AbstractMagma(M_U m_U);IN AbstractMagma<U,M_U>& OP=(CO AbstractMagma<U,M_U>&)NE;IN U Product(U u0,CO U& u1);};
TE <TY U> IN PointedSet<U>::PointedSet(U b_U):m_b_U(MO(b_U)){}TE <TY U> IN CO U& PointedSet<U>::Point()CO NE{RE m_b_U;}TE <TY U> IN U& PointedSet<U>::Point()NE{RE m_b_U;}DF_OF_CPOINT(Unit);DF_OF_CPOINT(Zero);DF_OF_CPOINT(One);DF_OF_CPOINT(Infty);DF_OF_POINT(init);DF_OF_POINT(root);TE <TY U,TY F_U> IN AbstractNSet<U,F_U>::AbstractNSet(F_U f_U):m_f_U(MO(f_U)){ST_AS(is_invocable_r_v<U,F_U,U>);}TE <TY U,TY F_U> IN AbstractNSet<U,F_U>& AbstractNSet<U,F_U>::operator=(CO AbstractNSet<U,F_U>&)NE{RE *TH;}TE <TY U,TY F_U> IN U AbstractNSet<U,F_U>::Transfer(CO U& u){RE m_f_U(u);}TE <TY U> IN U VirtualNSet<U>::Inverse(CO U& u){RE Transfer(u);}TE <TY U,TY M_U> IN AbstractMagma<U,M_U>::AbstractMagma(M_U m_U):m_m_U(MO(m_U)){ST_AS(is_invocable_r_v<U,M_U,U,U>);}TE <TY U,TY M_U> IN AbstractMagma<U,M_U>& AbstractMagma<U,M_U>::OP=(CO AbstractMagma<U,M_U>&)NE{RE *TH;}TE <TY U> IN U AdditiveMagma<U>::Product(U u0,CO U& u1){RE MO(u0 += u1);}TE <TY U> IN U MultiplicativeMagma<U>::Product(U u0,CO U& u1){RE MO(u0 *= u1);}TE <TY U,TY M_U> IN U AbstractMagma<U,M_U>::Product(U u0,CO U& u1){RE m_m_U(MO(u0),u1);}TE <TY U> IN U VirtualMagma<U>::Sum(U u0,CO U& u1){RE Product(MO(u0),u1);}

TE <TY U>CL VirtualMonoid:VI PU VirtualMagma<U>,VI PU VirtualPointedSet<U>{};TE <TY U = ll>CL AdditiveMonoid:VI PU VirtualMonoid<U>,PU AdditiveMagma<U>,PU PointedSet<U>{};TE <TY U = ll>CL MultiplicativeMonoid:VI PU VirtualMonoid<U>,PU MultiplicativeMagma<U>,PU PointedSet<U>{PU:IN MultiplicativeMonoid(U e_U);};TE <TY U,TY M_U>CL AbstractMonoid:VI PU VirtualMonoid<U>,PU AbstractMagma<U,M_U>,PU PointedSet<U>{PU:IN AbstractMonoid(M_U m_U,U e_U);};
TE <TY U> IN MultiplicativeMonoid<U>::MultiplicativeMonoid(U e_U):PointedSet<U>(MO(e_U)){}TE <TY U,TY M_U> IN AbstractMonoid<U,M_U>::AbstractMonoid(M_U m_U,U e_U):AbstractMagma<U,M_U>(MO(m_U)),PointedSet<U>(MO(e_U)){}

TE <TY U>CL VirtualGroup:VI PU VirtualMonoid<U>,VI PU VirtualPointedSet<U>,VI PU VirtualNSet<U>{};TE <TY U = ll>CL AdditiveGroup:VI PU VirtualGroup<U>,PU AdditiveMonoid<U>{PU:IN U Transfer(CO U& u);};TE <TY U,TY M_U,TY I_U>CL AbstractGroup:VI PU VirtualGroup<U>,PU AbstractMonoid<U,M_U>,PU AbstractNSet<U,I_U>{PU:IN AbstractGroup(M_U m_U,U e_U,I_U i_U);};
TE <TY U,TY M_U,TY I_U> IN AbstractGroup<U,M_U,I_U>::AbstractGroup(M_U m_U,U e_U,I_U i_U):AbstractMonoid<U,M_U>(MO(m_U),MO(e_U)),AbstractNSet<U,I_U>(MO(i_U)){}TE <TY U> IN U AdditiveGroup<U>::Transfer(CO U& u){RE -u;}

TE <TY R,TY U>CL VirtualRSet:VI PU UnderlyingSet<U>{PU:VI U Action(CO R& r,U u)= 0;IN U PW(U u,CO R& r);IN U ScalarProduct(CO R& r,U u);};TE <TY U,TY MAGMA>CL RegularRSet:VI PU VirtualRSet<U,U>,PU MAGMA{PU:IN RegularRSet(MAGMA magma);IN U Action(CO U& r,U u);};TE <TY MAGMA> RegularRSet(MAGMA magma)-> RegularRSet<inner_t<MAGMA>,MAGMA>;TE <TY R,TY U,TY O_U>CL AbstractRSet:VI PU VirtualRSet<R,U>{PU:O_U m_o_U;IN AbstractRSet(CO R& dummy0,CO U& dummy1,O_U o_U);IN AbstractRSet<R,U,O_U>& OP=(CO AbstractRSet<R,U,O_U>&)NE;IN U Action(CO R& r,U u);};TE <TY R,TY U,TY O_U,TY GROUP>CL AbstractModule:PU AbstractRSet<R,U,O_U>,PU GROUP{PU:IN AbstractModule(CO R& dummy,O_U o_U,GROUP M);};TE <TY R,TY O_U,TY GROUP> AbstractModule(CO R& dummy,O_U o_U,GROUP M)-> AbstractModule<R,inner_t<GROUP>,O_U,GROUP>;TE <TY R,TY U>CL Module:VI PU VirtualRSet<R,U>,PU AdditiveGroup<U>{PU:IN U Action(CO R& r,U u);};
TE <TY R,TY MAGMA> IN RegularRSet<R,MAGMA>::RegularRSet(MAGMA magma):MAGMA(MO(magma)){}TE <TY R,TY U,TY O_U> IN AbstractRSet<R,U,O_U>::AbstractRSet(CO R& dummy0,CO U& dummy1,O_U o_U):m_o_U(MO(o_U)){ST_AS(is_invocable_r_v<U,O_U,R,U>);}TE <TY R,TY U,TY O_U,TY GROUP> IN AbstractModule<R,U,O_U,GROUP>::AbstractModule(CO R& dummy,O_U o_U,GROUP M):AbstractRSet<R,U,O_U>(dummy,M.One(),MO(o_U)),GROUP(MO(M)){ST_AS(is_same_v<U,inner_t<GROUP>>);}TE <TY R,TY U,TY O_U> IN AbstractRSet<R,U,O_U>& AbstractRSet<R,U,O_U>::OP=(CO AbstractRSet<R,U,O_U>&)NE{RE *TH;}TE <TY U,TY MAGMA> IN U RegularRSet<U,MAGMA>::Action(CO U& r,U u){RE TH->Product(r,MO(u));}TE <TY R,TY U,TY O_U> IN U AbstractRSet<R,U,O_U>::Action(CO R& r,U u){RE m_o_U(r,MO(u));}TE <TY R,TY U> IN U Module<R,U>::Action(CO R& r,U u){RE MO(u *= r);}TE <TY R,TY U> IN U VirtualRSet<R,U>::PW(U u,CO R& r){RE Action(r,MO(u));}TE <TY R,TY U> IN U VirtualRSet<R,U>::ScalarProduct(CO R& r,U u){RE Action(r,MO(u));}

/* Graph (5KB)*/
TE <TY T,TY R1,TY R2,TY E>CL VirtualGraph:VI PU UnderlyingSet<T>{PU:VI R1 Enumeration(CRI i)= 0;IN R2 Enumeration_inv(CO T& t);TE <TY PATH> IN R2 Enumeration_inv(CO PATH& p);IN VO Reset();VI CRI SZ()CO NE = 0;VI E& edge()NE = 0;VI ret_t<E,T> Edge(CO T& t)= 0;TE <TY PATH> IN ret_t<E,T> Edge(CO PATH& p);ST IN CO T& Vertex(CO T& t)NE;TE <TY PATH> ST IN CO T& Vertex(CO PATH& e)NE;VI R2 Enumeration_inv_Body(CO T& t)= 0;};TE <TY T,TY R1,TY R2,TY E>CL EdgeImplimentation:VI PU VirtualGraph<T,R1,R2,E>{PU:int m_SZ;E m_edge;IN EdgeImplimentation(CRI SZ,E edge);IN CRI SZ()CO NE;IN E& edge()NE;IN ret_t<E,T> Edge(CO T& t);};TE <TY E>CL Graph:PU EdgeImplimentation<int,CRI,CRI,E>{PU:IN Graph(CRI SZ,E edge);IN CRI Enumeration(CRI i);TE <TY F> IN Graph<F> GetGraph(F edge)CO;IN CRI Enumeration_inv_Body(CRI t);};TE <TY T,TY Enum_T,TY Enum_T_inv,TY E>CL EnumerationGraph:PU EdgeImplimentation<T,ret_t<Enum_T,int>,ret_t<Enum_T_inv,T>,E>{PU:Enum_T m_enum_T;Enum_T_inv m_enum_T_inv;IN EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge);IN ret_t<Enum_T,int> Enumeration(CRI i);TE <TY F> IN EnumerationGraph<T,Enum_T,Enum_T_inv,F> GetGraph(F edge)CO;IN ret_t<Enum_T_inv,T> Enumeration_inv_Body(CO T& t);};TE <TY Enum_T,TY Enum_T_inv,TY E> EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge)-> EnumerationGraph<decldecay_t(declval<Enum_T>()(0)),Enum_T,Enum_T_inv,E>;TE <TY T,TY E>CL MemorisationGraph:PU EdgeImplimentation<T,T,CRI,E>{PU:int m_LE;VE<T> m_memory;Map<T,int> m_memory_inv;IN MemorisationGraph(CRI SZ,CO T& dummy,E edge);IN T Enumeration(CRI i);IN VO Reset();TE <TY F> IN MemorisationGraph<T,F> GetGraph(F edge)CO;IN CRI Enumeration_inv_Body(CO T& t);};
TE <TY T,TY R1,TY R2,TY E> IN EdgeImplimentation<T,R1,R2,E>::EdgeImplimentation(CRI SZ,E edge):m_SZ(SZ),m_edge(MO(edge)){ST_AS(is_COructible_v<T,R1> && is_COructible_v<int,R2> && is_invocable_v<E,T>);}TE <TY E> IN Graph<E>::Graph(CRI SZ,E edge):EdgeImplimentation<int,CRI,CRI,E>(SZ,MO(edge)){}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN EnumerationGraph<T,Enum_T,Enum_T_inv,E>::EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge):EdgeImplimentation<T,ret_t<Enum_T,int>,ret_t<Enum_T_inv,T>,E>(SZ,MO(edge)),m_enum_T(MO(enum_T)),m_enum_T_inv(MO(enum_T_inv)){}TE <TY T,TY E> IN MemorisationGraph<T,E>::MemorisationGraph(CRI SZ,CO T& dummy,E edge):EdgeImplimentation<T,T,CRI,E>(SZ,MO(edge)),m_LE(),m_memory(),m_memory_inv(){ST_AS(is_invocable_v<E,T>);}TE <TY E> IN CRI Graph<E>::Enumeration(CRI i){RE i;}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN ret_t<Enum_T,int> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::Enumeration(CRI i){RE m_enum_T(i);}TE <TY T,TY E> IN T MemorisationGraph<T,E>::Enumeration(CRI i){AS(0 <= i && i < m_LE);RE m_memory[i];}TE <TY T,TY R1,TY R2,TY E> IN R2 VirtualGraph<T,R1,R2,E>::Enumeration_inv(CO T& t){RE Enumeration_inv_Body(t);}TE <TY T,TY R1,TY R2,TY E> TE <TY PATH> IN R2 VirtualGraph<T,R1,R2,E>::Enumeration_inv(CO PATH& p){RE Enumeration_inv_Body(get<0>(p));}TE <TY E> IN CRI Graph<E>::Enumeration_inv_Body(CRI i){RE i;}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN ret_t<Enum_T_inv,T> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::Enumeration_inv_Body(CO T& t){RE m_enum_T_inv(t);}TE <TY T,TY E> IN CRI MemorisationGraph<T,E>::Enumeration_inv_Body(CO T& t){if(m_memory_inv.count(t)== 0){AS(m_LE < TH->SZ());m_memory.push_back(t);RE m_memory_inv[t]= m_LE++;}RE m_memory_inv[t];}TE <TY T,TY R1,TY R2,TY E> VO VirtualGraph<T,R1,R2,E>::Reset(){}TE <TY T,TY E> IN VO MemorisationGraph<T,E>::Reset(){m_LE = 0;m_memory.clear();m_memory_inv.clear();}TE <TY T,TY R1,TY R2,TY E> IN CRI EdgeImplimentation<T,R1,R2,E>::SZ()CO NE{RE m_SZ;}TE <TY T,TY R1,TY R2,TY E> IN E& EdgeImplimentation<T,R1,R2,E>::edge()NE{RE m_edge;}TE <TY T,TY R1,TY R2,TY E> IN ret_t<E,T> EdgeImplimentation<T,R1,R2,E>::Edge(CO T& t){RE m_edge(t);}TE <TY T,TY R1,TY R2,TY E> TE <TY PATH> IN ret_t<E,T> VirtualGraph<T,R1,R2,E>::Edge(CO PATH& p){RE Edge(get<0>(p));}TE <TY E> TE <TY F> IN Graph<F> Graph<E>::GetGraph(F edge)CO{RE Graph<F>(TH->SZ(),MO(edge));}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> TE <TY F> IN EnumerationGraph<T,Enum_T,Enum_T_inv,F> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::GetGraph(F edge)CO{RE EnumerationGraph<T,Enum_T,Enum_T_inv,F>(TH->SZ(),m_enum_T,m_enum_T_inv,MO(edge));}TE <TY T,TY E> TE <TY F> IN MemorisationGraph<T,F> MemorisationGraph<T,E>::GetGraph(F edge)CO{RE MemorisationGraph<T,F>(TH->SZ(),MO(edge));}TE <TY T,TY R1,TY R2,TY E> IN CO T& VirtualGraph<T,R1,R2,E>::Vertex(CO T& t)NE{RE t;}TE <TY T,TY R1,TY R2,TY E> TE <TY PATH> IN CO T& VirtualGraph<T,R1,R2,E>::Vertex(CO PATH& e)NE{RE Vertex(get<0>(e));}

/* Grid (2KB)*/
#define SET_GRID H_minus = H - 1;W_minus = W - 1;HW = ll(H)* W
#define SET_HW(h,w)H = h;W = w;SET_GRID
#define CIN_HW cin >> H >> W;SET_GRID
TE <TY E>CL GridGraph:PU EnumerationGraph<T2<int>,T2<int>(&)(CRI),int(&)(CO T2<int>&),E>{PU:IN GridGraph(E e);};int H,W,H_minus,W_minus;ll HW;VE<string> grid;char walkable = '.',unwalkable = '#';
IN T2<int> EnumHW(CRI v){RE{v / W,v % W};}IN int EnumHW_inv(CO T2<int>& ij){auto&[i,j]= ij;RE i * W + j;}TE <TY E> IN GridGraph<E>::GridGraph(E e):EnumerationGraph<T2<int>,T2<int>(&)(CRI),int(&)(CO T2<int>&),E>(HW,EnumHW,EnumHW_inv,MO(e)){AS(HW >> 31 == 0 && H * W == HW);}VE<T2<int>> EdgeOnGrid(CO T2<int>& v){VE<T2<int>> AN{};auto&[i,j]= v;if(grid[i][j]== walkable){if(i > 0 && grid[i-1][j]== walkable){AN.push_back({i-1,j});}if(i+1 < H && grid[i+1][j]== walkable){AN.push_back({i+1,j});}if(j > 0 && grid[i][j-1]== walkable){AN.push_back({i,j-1});}if(j+1 < W && grid[i][j+1]== walkable){AN.push_back({i,j+1});}}RE AN;}VE<pair<T2<int>,ll>> WEdgeOnGrid(CO T2<int>& v){VE<pair<T2<int>,ll>> AN{};auto&[i,j]= v;if(grid[i][j]== walkable){if(i>0 && grid[i-1][j]== walkable){AN.push_back({{i-1,j},1});}if(i+1 < H && grid[i+1][j]== walkable){AN.push_back({{i+1,j},1});}if(j>0 && grid[i][j-1]== walkable){AN.push_back({{i,j-1},1});}if(j+1 < W && grid[i][j+1]== walkable){AN.push_back({{i,j+1},1});}}RE AN;}IN VO SetWallStringOnGrid(CRI i,VE<string>& S){if(S.empty()){S.resize(H);}cin >> S[i];AS(int(S[i].SZ())== W);}CO string direction="URDL";IN int DirectionNumberOnGrid(CRI i,CRI j,CRI k,CRI h){RE i < k?2:i > k?0:j < h?1:(AS(j > h),3);}IN int DirectionNumberOnGrid(CO T2<int>& v,CO T2<int>& w){auto&[i,j]= v;auto&[k,h]= w;RE DirectionNumberOnGrid(i,j,k,h);}IN int DirectionNumberOnGrid(CRI v,CRI w){RE DirectionNumberOnGrid(EnumHW(v),EnumHW(w));}IN int ReverseDirectionNumberOnGrid(CRI n){AS(0 <= n && n<4);RE n ^ 2;}

/* ConstexprModulo (7KB)*/
CEXPR(uint,P,998244353);
#define RP Represent
#define DeRP Derepresent

TE <uint M,TY INT> CE INT Residue(INT n)NE{RE MO(n < 0?((((++n)*= -1)%= M)*= -1)+= M - 1:n < INT(M)?n:n %= M);}TE <TY INT> CE INT& ResidueP(INT& n)NE{CE CO uint trunc =(1 << 23)- 1;INT n_u = n >> 23;n &= trunc;INT n_uq =(n_u / 7)/ 17;n_u -= n_uq * 119;n += n_u << 23;RE n < n_uq?n += P - n_uq:n -= n_uq;}
TE <uint M> CL Mod;TE <uint M>CL COantsForMod{PU:COantsForMod()= delete;ST CE CO uint g_memory_bound = 1e6;ST CE CO uint g_memory_LE = M < g_memory_bound?M:g_memory_bound;ST CE uint g_M_minus = M - 1;ST CE int g_order_minus_1 = M - 2;ST CE int g_order_minus_1_neg = -g_order_minus_1;};
#define SFINAE_FOR_MOD enable_if_t<is_COructible_v<uint,decay_t<T>>>*
#define DC_OF_CM_FOR_MOD(OPR)CE bool OP OPR(CO Mod<M>& n)CO NE
#define DC_OF_AR_FOR_MOD(OPR,EX)CE Mod<M> OP OPR(Mod<M> n)CO EX;
#define DF_OF_CM_FOR_MOD(OPR)TE <uint M> CE bool Mod<M>::OP OPR(CO Mod<M>& n)CO NE{RE m_n OPR n.m_n;}
#define DF_OF_AR_FOR_MOD(OPR,EX,LEFT,OPR2)TE <uint M> CE Mod<M> Mod<M>::OP OPR(Mod<M> n)CO EX{RE MO(LEFT OPR2 ## = *TH);}TE <uint M,TY T,SFINAE_FOR_MOD = nullptr> CE Mod<M> OP OPR(T n0,CO Mod<M>& n1)EX{RE MO(Mod<M>(MO(n0))OPR ## = n1);}
TE <uint M>CL Mod{PU:uint m_n;CE Mod()NE;CE Mod(CO Mod<M>& n)NE;CE Mod(Mod<M>&& n)NE;TE <TY T,SFINAE_FOR_MOD = nullptr> CE Mod(T n)NE;CE Mod<M>& OP=(Mod<M> n)NE;CE Mod<M>& OP+=(CO Mod<M>& n)NE;CE Mod<M>& OP-=(CO Mod<M>& n)NE;CE Mod<M>& OP*=(CO Mod<M>& n)NE;IN Mod<M>& OP/=(Mod<M> n);TE <TY INT> CE Mod<M>& OP<<=(INT n);TE <TY INT> CE Mod<M>& OP>>=(INT n);CE Mod<M>& OP++()NE;CE Mod<M> OP++(int)NE;CE Mod<M>& OP--()NE;CE Mod<M> OP--(int)NE;DC_OF_CM_FOR_MOD(==);DC_OF_CM_FOR_MOD(!=);DC_OF_CM_FOR_MOD(<);DC_OF_CM_FOR_MOD(<=);DC_OF_CM_FOR_MOD(>);DC_OF_CM_FOR_MOD(>=);DC_OF_AR_FOR_MOD(+,NE);DC_OF_AR_FOR_MOD(-,NE);DC_OF_AR_FOR_MOD(*,NE);DC_OF_AR_FOR_MOD(/,);TE <TY INT> CE Mod<M> OP^(INT EX)CO;TE <TY INT> CE Mod<M> OP<<(INT n)CO;TE <TY INT> CE Mod<M> OP>>(INT n)CO;CE Mod<M> OP-()CO NE;CE Mod<M>& SignInvert()NE;IN Mod<M>& Invert();TE <TY INT> CE Mod<M>& PW(INT EX);CE VO swap(Mod<M>& n)NE;CE CRUI RP()CO NE;ST CE Mod<M> DeRP(uint n)NE;ST IN CO Mod<M>& Inverse(CRUI n);ST IN CO Mod<M>& Factorial(CRUI n);ST IN CO Mod<M>& FactorialInverse(CRUI n);ST IN Mod<M> Combination(CRUI n,CRUI i);ST IN CO Mod<M>& zero()NE;ST IN CO Mod<M>& one()NE;ST IN CE uint GetModulo()NE;TE <TY INT> CE Mod<M>& PositivePW(INT EX)NE;TE <TY INT> CE Mod<M>& NonNegativePW(INT EX)NE;US COants = COantsForMod<M>;};
US MP = Mod<P>;
TE <uint M> CE Mod<M>::Mod()NE:m_n(){}TE <uint M> CE Mod<M>::Mod(CO Mod<M>& n)NE:m_n(n.m_n){}TE <uint M> CE Mod<M>::Mod(Mod<M>&& n)NE:m_n(MO(n.m_n)){}TE <uint M> TE <TY T,SFINAE_FOR_MOD> CE Mod<M>::Mod(T n)NE:m_n(Residue<M>(MO(n))){}TE <uint M> CE Mod<M>& Mod<M>::OP=(Mod<M> n)NE{m_n = MO(n.m_n);RE *TH;}TE <uint M> CE Mod<M>& Mod<M>::OP+=(CO Mod<M>& n)NE{(m_n += n.m_n)< M?m_n:m_n -= M;RE *TH;}TE <uint M> CE Mod<M>& Mod<M>::OP-=(CO Mod<M>& n)NE{m_n < n.m_n?(m_n += M)-= n.m_n:m_n -= n.m_n;RE *TH;}TE <uint M> CE Mod<M>& Mod<M>::OP*=(CO Mod<M>& n)NE{m_n = MO(ull(m_n)* n.m_n)% M;RE *TH;}TE <> CE MP& MP::OP*=(CO MP& n)NE{ull m_n_copy = m_n;m_n = MO((m_n_copy *= n.m_n)< P?m_n_copy:ResidueP(m_n_copy));RE *TH;}TE <uint M> IN Mod<M>& Mod<M>::OP/=(Mod<M> n){RE OP*=(n.Invert());}TE <uint M> TE <TY INT> CE Mod<M>& Mod<M>::OP<<=(INT n){AS(n >= 0);RE *TH *= Mod<M>(2).NonNegativePW(MO(n));}TE <uint M> TE <TY INT> CE Mod<M>& Mod<M>::OP>>=(INT n){AS(n >=0);WH(n-- > 0){((m_n & 1)== 0?m_n:m_n += M)>>= 1;}RE *TH;}TE <uint M> CE Mod<M>& Mod<M>::OP++()NE{m_n < COants::g_M_minus?++m_n:m_n = 0;RE *TH;}TE <uint M> CE Mod<M> Mod<M>::OP++(int)NE{Mod<M> n{*TH};OP++();RE n;}TE <uint M> CE Mod<M>& Mod<M>::OP--()NE{m_n == 0?m_n = COants::g_M_minus:--m_n;RE *TH;}TE <uint M> CE Mod<M> Mod<M>::OP--(int)NE{Mod<M> n{*TH};OP--();RE n;}DF_OF_CM_FOR_MOD(==);DF_OF_CM_FOR_MOD(!=);DF_OF_CM_FOR_MOD(>);DF_OF_CM_FOR_MOD(>=);DF_OF_CM_FOR_MOD(<);DF_OF_CM_FOR_MOD(<=);DF_OF_AR_FOR_MOD(+,NE,n,+);DF_OF_AR_FOR_MOD(-,NE,n.SignInvert(),+);DF_OF_AR_FOR_MOD(*,NE,n,*);DF_OF_AR_FOR_MOD(/,,n.Invert(),*);TE <uint M> TE <TY INT> CE Mod<M> Mod<M>::OP^(INT EX)CO{RE MO(Mod<M>(*TH).PW(MO(EX)));}TE <uint M> TE <TY INT> CE Mod<M> Mod<M>::OP<<(INT n)CO{RE MO(Mod<M>(*TH)<<= MO(n));}TE <uint M> TE <TY INT> CE Mod<M> Mod<M>::OP>>(INT n)CO{RE MO(Mod<M>(*TH)>>= MO(n));}TE <uint M> CE Mod<M> Mod<M>::OP-()CO NE{RE MO(Mod<M>(*TH).SignInvert());}TE <uint M> CE Mod<M>& Mod<M>::SignInvert()NE{m_n > 0?m_n = M - m_n:m_n;RE *TH;}TE <uint M> IN Mod<M>& Mod<M>::Invert(){AS(m_n != 0);uint m_n_neg;RE m_n < COants::g_memory_LE?(m_n = Inverse(m_n).m_n,*TH):((m_n_neg = M - m_n)< COants::g_memory_LE)?(m_n = M - Inverse(m_n_neg).m_n,*TH):NonNegativePW(COants::g_order_minus_1);}TE <uint M> TE <TY INT> CE Mod<M>& Mod<M>::PositivePW(INT EX)NE{Mod<M> PW{*TH};EX--;WH(EX != 0){(EX & 1)== 1?*TH *= PW:*TH;EX >>= 1;PW *= PW;}RE *TH;}TE <uint M> TE <TY INT> CE Mod<M>& Mod<M>::NonNegativePW(INT EX)NE{RE EX == 0?(m_n = 1,*TH):PositivePW(MO(EX));}TE <uint M> TE <TY INT> CE Mod<M>& Mod<M>::PW(INT EX){bool neg = EX < 0;AS(!(neg && m_n == 0));RE neg?PositivePW(ll(MO(EX %= COants::g_M_minus))* COants::g_order_minus_1_neg %COants::g_M_minus):NonNegativePW(MO(EX));}TE <uint M> CE VO Mod<M>::swap(Mod<M>& n)NE{std::swap(m_n,n.m_n);}TE <uint M> IN CO Mod<M>& Mod<M>::Inverse(CRUI n){AS(n < M);ST VE<Mod<M>> memory ={zero(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory.push_back(DeRP(M - memory[M % LE_curr].m_n * ull(M / LE_curr)% M));LE_curr++;}RE memory[n];}TE <uint M> IN CO Mod<M>& Mod<M>::Factorial(CRUI n){if(M <= n){RE zero();}ST VE<Mod<M>> memory ={one(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory.push_back(memory[LE_curr - 1]* LE_curr);LE_curr++;}RE memory[n];}TE <uint M> IN CO Mod<M>& Mod<M>::FactorialInverse(CRUI n){ST VE<Mod<M>> memory ={one(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory.push_back(memory[LE_curr - 1]* Inverse(LE_curr));LE_curr++;}RE memory[n];}TE <uint M> IN Mod<M> Mod<M>::Combination(CRUI n,CRUI i){RE i <= n?Factorial(n)* FactorialInverse(i)* FactorialInverse(n - i):zero();}TE <uint M> CE CRUI Mod<M>::RP()CO NE{RE m_n;}TE <uint M> CE Mod<M> Mod<M>::DeRP(uint n)NE{Mod<M> n_copy{};n_copy.m_n = MO(n);RE n_copy;}TE <uint M> IN CO Mod<M>& Mod<M>::zero()NE{ST CE CO Mod<M> z{};RE z;}TE <uint M> IN CO Mod<M>& Mod<M>::one()NE{ST CE CO Mod<M> o{1};RE o;}TE <uint M> IN CE uint Mod<M>::GetModulo()NE{RE M;}TE <uint M> IN Mod<M> Inverse(CO Mod<M>& n){RE MO(Mod<M>(n).Invert());}TE <uint M,TY INT> CE Mod<M> PW(Mod<M> n,INT EX){RE MO(n.PW(MO(EX)));}TE <uint M> CE VO swap(Mod<M>& n0,Mod<M>& n1)NE{n0.swap(n1);}TE <uint M> IN string to_string(CO Mod<M>& n)NE{RE to_string(n.RP())+ " + " + to_string(M)+ "Z";}TE <uint M,CL Traits> IN IS& OP>>(IS& is,Mod<M>& n){ll m;is >> m;n = m;RE is;}TE <uint M,CL Traits> IN OS& OP<<(OS& os,CO Mod<M>& n){RE os << n.RP();}
#define DF_OF_HASH_FOR_MOD(MOD)IN size_t hash<MOD>::OP()(CO MOD& n)CO{ST CO hash<decldecay_t(n.RP())> h;RE h(n.RP());}
TE <uint M> DC_OF_HASH(Mod<M>); TE <uint M> DF_OF_HASH_FOR_MOD(Mod<M>);

/* Loop (1KB)*/
TE <TY INT> bool NextLoop(CRI SZ,CO VE<INT>& lower_bound,CO VE<INT>& upper_limit,VE<INT>& index){int depth = 0;WH(depth < SZ){if(++index[depth]< upper_limit[depth]){break;}index[depth]= lower_bound[depth];depth++;}RE depth < SZ;}TE <TY INT> bool NextLoop(CO VE<INT>& lower_bound,CO VE<INT>& upper_limit,VE<INT>& index){RE NextLoop(index.SZ(),lower_bound,upper_limit,index);}TE <TY INT> bool NextLoopEq(CRI SZ,CO VE<INT>& lower_bound,CO VE<INT>& upper_bound,VE<INT>& index){int depth = 0;WH(depth < SZ){if(++index[depth]<= upper_bound[depth]){break;}index[depth]= lower_bound[depth];depth++;}RE depth < SZ;}TE <TY INT> bool NextLoopEq(CO VE<INT>& lower_bound,CO VE<INT>& upper_bound,VE<INT>& index){RE NextLoopEq(index.SZ(),lower_bound,upper_bound,index);}

/* string (1KB)*/
TE <TY INT> IN char IntToChar(CO INT& i,CO char& c = 'a'){RE c + i;}TE <TY INT> IN INT CharToInt(CO char& i){RE i -(i < 'a'?'A':'a');}TE <TY INT>string ArrayToString(CO VE<INT>& A,CO char& c = 'a'){CO int N = A.SZ();string S(N,c);for(int i = 0;i < N;i++){S[i]= IntToChar<INT>(A[i],c);}RE S;}TE <TY INT>VE<INT> StringToArray(CO string& S){CO int N = S.SZ();VE<int> A(N);for(int i = 0;i < N;i++){A[i]= CharToInt<INT>(S[i]);}RE A;}
#endif
/* AAA 常設ライブラリは以上に挿入する。*/

#define INCLUDE_LIBRARY
#include __FILE__
#endif /* INCLUDE_LIBRARY */
#endif /* INCLUDE_SUB */
#endif /* INCLUDE_MAIN */
