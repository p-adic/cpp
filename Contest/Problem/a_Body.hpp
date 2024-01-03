// c:/Users/user/Documents/Programming/Contest/Problem/a_Body.hpp

#pragma once
#include "a.hpp"

#include "ExecuteSolution/a_Body.hpp"
#include "GenerateSamples/a_Body.hpp"
#include "RearrangeSamples/a_Body.hpp"
#include "WriteInSamples/a_Body.hpp"

// 入出力用関数は../../Utility/StdStream/で定義。
// GetgEたちの定義はグラフ用関数の位置に移動。

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

template <typename PATH> list<PATH> GetgE( const int& i )
{
  list<PATH> answer = gE<PATH>[i];
  // VVV 入力によらない処理は以下に挿入する。

  // AAA 入力によらない処理は以上に挿入する。
  return answer;
}

template <typename T> inline T GetgF( const T& t ){ return gF<T>[t]; }
template <typename T> inline T GetgA( const int& i ){ return gA<T>[i]; }

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
