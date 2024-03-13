// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Montgomery/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "a_Alias.hpp"

// 非常によくバグるので、更新したら必ずverifyすること！
// verify:
// https://yukicoder.me/submissions/959351
// （Derepresent,+=,-=,*,Combination,one）
// #ifndef INCLUDE_MODE
  #define INCLUDE_MODE
  // #define REACTIVE
  // #define USE_GETLINE
#endif

#ifdef INCLUDE_MAIN

CEXPR( uint , Q , 1000000007 );
using MOD = Montgomery<Q>;
MOD A1( ull& M , uint& K );
MOD A2( ull& M , uint& K );
MOD A3( ull& M , uint& K );

IN VO Solve()
{
  CIN( int , N );
  CIN( ull , M );
  CIN( uint , K );
  RETURN( N * M < K ? 0 : K == 1 ? N * M == 1 ? 1 : 0 : N == 1 ? A1( M , K ) : N == 2 ? A2( M , K ) : A3( M , K ) );
}
REPEAT_MAIN(1);

MOD A1( ull& M , uint& K )
{
  MOD answer = MOD::zero();
  ( --M ) %= ( Q - 1 );
  K--;
  MOD k_mod = MOD::zero();
  FOREQ( k , 0 , K ){
    const MOD d = MOD::Combination( K , k ) * ( k_mod ^ M );
    ( k & 1 ) == 0 ? answer += d : answer -= d;
    k_mod++;
  }
  return move( ( ( K & 1 ) == 1 ? answer.SignInvert() : answer ) *= k_mod );
}

MOD A2( ull& M , uint& K )
{
  MOD answer = MOD::zero();
  ( --M ) %= ( Q - 1 );
  K -= 2;
  MOD k_mod = MOD::zero();
  FOREQ( k , 0 , K ){
    MOD temp = k_mod;
    const MOD d = MOD::Combination( K , k ) * ( ( ++( ( ++temp ) *= k_mod ) ) ^ M );
    ( k & 1 ) == 0 ? answer += d : answer -= d;
    k_mod++;
  }
  answer *= k_mod;
  return move( ( ( K & 1 ) == 1 ? answer.SignInvert() : answer ) *= ++k_mod );
}

MOD A3( ull& M , uint& K )
{
  TwoByOneMatrix<MOD> answer_vec{ 0 , 0 };
  const MOD& one = MOD::one();
  M--;
  K -= 2;
  MOD k_mod = MOD::zero();
  FOREQ( k , 0 , K ){
    MOD k_copy = k_mod;
    k_copy--;
    MOD k_copy2 = k_mod * k_mod;
    k_copy2++;
    const MOD k_copy3 = k_copy2 * k_mod;
    TwoByOneMatrix<MOD> d{ one , k_mod };
    TwoByTwoMatrix<MOD> Transfer{
      k_copy2 + k_mod , k_copy2 ,
  	k_copy3 , k_copy3 + k_copy
  	};
    ( d.Act( Transfer , M ) *= MOD::FactorialInverse( k ) ) *= MOD::FactorialInverse( K - k );
    ( k & 1 ) == 0 ? answer_vec += d : answer_vec -= d;
    k_mod++;
  }
  MOD answer = answer_vec.Get( 0 ) + answer_vec.Get( 1 ) ;
  ( answer *= MOD::Factorial( K ) ) *= k_mod;
  return move( ( ( K & 1 ) == 1 ? answer.SignInvert() : answer ) *= ++k_mod );
}

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

BFS (5KB)
c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/compress.txt

CoordinateCompress (3KB)
c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/compress.txt

DFSOnTree (11KB)
c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a.hpp

Divisor (4KB)
c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/compress.txt

IntervalAddBIT (9KB)
c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/compress.txt

Polynomial (21KB)
c:/Users/user/Documents/Programming/Mathematics/Polynomial/compress.txt

UnionFind (3KB)
c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/UnionFindForest/compress.txt

*/

// VVV 常設でないライブラリは以下に挿入する。
#define TTMA TwoByTwoMatrix
#define SFINAE_FOR_MA(DEFAULT)TY Arg,enable_if_t<is_COructible_v<T,Arg>>* DEFAULT
TE <TY T>CL TTMA{PU:T m_M00;T m_M01;T m_M10;T m_M11;CE TTMA(T M00,T M01,T M10,T M11)NE;CE TTMA(CO T& scalar = T())NE;TE <SFINAE_FOR_MA(= nullptr)> CE TTMA(CO Arg& scalar)NE;CE TTMA(CO TTMA<T>& mat)NE;CE TTMA(TTMA<T>&& mat)NE;CE TTMA<T>& OP=(TTMA<T> mat)NE;CE TTMA<T>& OP+=(CO TTMA<T>& mat)NE;CE TTMA<T>& OP-=(CO TTMA<T>& mat)NE;CE TTMA<T>& OP*=(CO TTMA<T>& mat)NE;CE TTMA<T>& OP*=(CO T& scalar)NE;TE <SFINAE_FOR_MA(= nullptr)> CE TTMA<T>& OP*=(CO Arg& scalar)NE;IN TTMA<T>& OP/=(CO TTMA<T>& mat);IN TTMA<T>& OP/=(CO T& scalar);TE <SFINAE_FOR_MA(= nullptr)> IN TTMA<T>& OP/=(CO Arg& scalar);IN TTMA<T>& OP%=(CO T& scalar);IN TTMA<T>& Invert();IN TTMA<T> Inverse()CO;CE bool OP==(CO TTMA<T>& mat)CO NE;CE bool OP!=(CO TTMA<T>& mat)CO NE;CE TTMA<T> OP+(TTMA<T> mat)CO NE;CE TTMA<T> OP-()CO NE;CE TTMA<T> OP-(CO TTMA<T>& mat)CO NE;CE TTMA<T> OP*(CO TTMA<T>& mat)CO NE;TE <SFINAE_FOR_MA(= nullptr)> CE TTMA<T> OP*(CO Arg& scalar)CO NE;IN TTMA<T> OP/(CO TTMA<T>& mat)CO;TE <SFINAE_FOR_MA(= nullptr)> IN TTMA<T> OP/(CO Arg& scalar)CO;IN TTMA<T> OP%(CO T& scalar)CO;TE <TY INT> CE TTMA<T> OP^(INT EX)CO;CE T tr()CO NE;CE T det()CO NE;CE VO swap(TTMA<T>& mat)NE;CE CO T& Get(CRUI y,CRUI x)CO NE;CE T& Ref(CRUI y,CRUI x)NE;CE TTMA<T> Square()CO NE;};
TE <TY T,SFINAE_FOR_MA(= nullptr)> CE TTMA<T> OP*(CO Arg& scalar,CO TTMA<T>& mat)NE;TE <TY T,TY INT> CE TTMA<T> PW(CO TTMA<T>& mat,INT EX)NE;TE <TY T> CE VO swap(TTMA<T>& mat1,TTMA<T>& mat2)NE;TE <TY T> CE TTMA<T>::TTMA(T M00,T M01,T M10,T M11)NE:m_M00(MO(M00)),m_M01(MO(M01)),m_M10(MO(M10)),m_M11(MO(M11)){}TE <TY T> CE TTMA<T>::TTMA(CO T& scalar)NE:m_M00(scalar),m_M01(),m_M10(),m_M11(scalar){}TE <TY T> TE <SFINAE_FOR_MA()> CE TTMA<T>::TTMA(CO Arg& scalar)NE:TTMA(T(scalar)){}TE <TY T> CE TTMA<T>::TTMA(CO TTMA<T>& mat)NE:m_M00(mat.m_M00),m_M01(mat.m_M01),m_M10(mat.m_M10),m_M11(mat.m_M11){}TE <TY T> CE TTMA<T>::TTMA(TTMA<T>&& mat)NE:m_M00(MO(mat.m_M00)),m_M01(MO(mat.m_M01)),m_M10(MO(mat.m_M10)),m_M11(MO(mat.m_M11)){}TE <TY T> CE TTMA<T>& TTMA<T>::OP=(TTMA<T> mat)NE{m_M00 = MO(mat.m_M00);m_M01 = MO(mat.m_M01);m_M10 = MO(mat.m_M10);m_M11 = MO(mat.m_M11);RE *TH;}TE <TY T> CE TTMA<T>& TTMA<T>::OP+=(CO TTMA<T>& mat)NE{m_M00 += mat.m_M00;m_M01 += mat.m_M01;m_M10 += mat.m_M10;m_M11 += mat.m_M11;RE *TH;}TE <TY T> CE TTMA<T>& TTMA<T>::OP-=(CO TTMA<T>& mat)NE{m_M00 -= mat.m_M00;m_M01 -= mat.m_M01;m_M10 -= mat.m_M10;m_M11 -= mat.m_M11;RE *TH;}TE <TY T> CE TTMA<T>& TTMA<T>::OP*=(CO TTMA<T>& mat)NE{RE *TH = *TH * mat;}TE <TY T> CE TTMA<T>& TTMA<T>::OP*=(CO T& scalar)NE{m_M00 *= scalar;m_M01 *= scalar;m_M10 *= scalar;m_M11 *= scalar;RE *TH;}TE <TY T> TE <SFINAE_FOR_MA()> CE TTMA<T>& TTMA<T>::OP*=(CO Arg& scalar)NE{RE *TH *= T(scalar);}TE <TY T> IN TTMA<T>& TTMA<T>::OP/=(CO TTMA<T>& mat){RE *TH = *TH / mat;}TE <TY T> IN TTMA<T>& TTMA<T>::OP/=(CO T& scalar){RE *TH *= T(1)/ scalar;}TE <TY T> TE <SFINAE_FOR_MA()> IN TTMA<T>& TTMA<T>::OP/=(CO Arg& scalar){RE *TH /= T(scalar);}TE <TY T> IN TTMA<T>& TTMA<T>::OP%=(CO T& scalar){m_M00 %= scalar;m_M01 %= scalar;m_M10 %= scalar;m_M11 %= scalar;RE *TH;}TE <TY T> IN TTMA<T>& TTMA<T>::Invert(){::swap(m_M00,m_M11);m_M01 = -m_M01;m_M10 = -m_M10;RE *TH /= det();}TE <TY T> TTMA<T> TTMA<T>::Inverse()CO{RE MO(TTMA<T>(*TH).invert());}TE <TY T> CE bool TTMA<T>::OP==(CO TTMA<T>& mat)CO NE{RE m_M00 == mat.m_M00 && m_M01 == mat.m_M01 && m_M10 == mat.m_M10 && m_M11 == mat.m_M11;}TE <TY T> CE bool TTMA<T>::OP!=(CO TTMA<T>& mat)CO NE{RE !(*TH == mat);}TE <TY T> CE TTMA<T> TTMA<T>::OP+(TTMA<T> mat)CO NE{RE MO(mat += *TH);}TE <TY T> CE TTMA<T> TTMA<T>::OP-()CO NE{RE TTMA<T>(-m_M00,-m_M01,-m_M10,-m_M11);}TE <TY T> CE TTMA<T> TTMA<T>::OP-(CO TTMA<T>& mat)CO NE{RE MO(-mat += *TH);}TE <TY T> CE TTMA<T> TTMA<T>::OP*(CO TTMA<T>& mat)CO NE{RE TTMA<T>(m_M00 * mat.m_M00 + m_M01 * mat.m_M10,m_M00 * mat.m_M01 + m_M01 * mat.m_M11,m_M10 * mat.m_M00 + m_M11 * mat.m_M10,m_M10 * mat.m_M01 + m_M11 * mat.m_M11);}TE <TY T> TE <SFINAE_FOR_MA()> CE TTMA<T> TTMA<T>::OP*(CO Arg& scalar)CO NE{RE MO(TTMA<T>(*TH)*= scalar);}TE <TY T> IN TTMA<T> TTMA<T>::OP/(CO TTMA<T>& mat)CO{CO T det_inv{T(1)/(mat.m_M00 * mat.m_M11 - mat.m_M01 * mat.m_M10)};RE TTMA<T>((m_M00 * mat.m_M11 - m_M01 * mat.m_M10)* det_inv,(m_M01 * mat.m_M00 - m_M00 * mat.m_M01)* det_inv,(m_M10 * mat.m_M11 - m_M11 * mat.m_M10)* det_inv,(m_M11 * mat.m_M00 - m_M10 * mat.m_M01)* det_inv);}TE <TY T> TE <SFINAE_FOR_MA()> IN TTMA<T> TTMA<T>::OP/(CO Arg& scalar)CO{RE MO(TTMA<T>(*TH)/= scalar);}TE <TY T> IN TTMA<T> TTMA<T>::OP%(CO T& scalar)CO{RE MO(TTMA<T>(*TH)%= scalar);}TE <TY T> TE <TY INT> CE TTMA<T> TTMA<T>::OP^(INT EX)CO{TTMA<T> AN{1},PW{*TH};EX < 0?(EX *= -1,PW.Invert()):*TH;WH(EX > 0){(EX & 1)== 1?AN *= PW:AN;PW = PW.Square();EX >>= 1;}RE AN;}TE <TY T> CE TTMA<T> TTMA<T>::Square()CO NE{RE TTMA<T>(m_M00 * m_M00 + m_M01 * m_M10,(m_M00 + m_M11)* m_M01,m_M10 *(m_M00 + m_M11),m_M10 * m_M01 + m_M11 * m_M11);}TE <TY T> CE T TTMA<T>::tr()CO NE{RE m_M00 + m_M11;}TE <TY T> CE T TTMA<T>::det()CO NE{RE m_M00 * m_M11 - m_M01 * m_M10;}TE <TY T> CE VO TTMA<T>::swap(TTMA<T>& mat)NE{std::swap(m_M00,mat.m_M00);std::swap(m_M01,mat.m_M01);std::swap(m_M10,mat.m_M10);std::swap(m_M11,mat.m_M11);}TE <TY T> CE CO T& TTMA<T>::Get(CRUI y,CRUI x)CO NE{RE y == 0?x == 0?m_M00:m_M01:x == 0?m_M10:m_M11;}TE <TY T> CE T& TTMA<T>::Ref(CRUI y,CRUI x)NE{RE y == 0?x == 0?m_M00:m_M01:x == 0?m_M10:m_M11;}TE <TY T,SFINAE_FOR_MA()> CE TTMA<T> OP*(CO Arg& scalar,CO TTMA<T>& mat)NE{RE MO(TTMA<T>(mat)*= scalar);}TE <TY T,TY INT> CE TTMA<T> PW(CO TTMA<T>& mat,INT EX)NE{RE mat ^ MO(EX);}TE <TY T> CE VO swap(TTMA<T>& mat1,TTMA<T>& mat2)NE{mat1.swap(mat2);}

#define TOMA TwoByOneMatrix
TE <TY T>CL TOMA{PU:T m_M0;T m_M1;CE TOMA(T M0 = T(),T M1 = T())NE;CE TOMA(CO TOMA<T>& mat)NE;CE TOMA(TOMA<T>&& mat)NE;CE TOMA<T>& OP=(TOMA<T> mat)NE;CE TOMA<T>& OP+=(CO TOMA<T>& mat)NE;CE TOMA<T>& OP-=(CO TOMA<T>& mat)NE;CE TOMA<T>& OP*=(CO T& scalar)NE;IN TOMA<T>& OP/=(CO T& scalar);IN TOMA<T>& OP%=(CO T& scalar);TE <TY INT> CE TOMA<T>& Act(TTMA<T> mat,INT EX = 1);TE <TY INT> CE TOMA<T> Action(TTMA<T> mat,INT EX = 1)CO;CE TOMA<T> OP+(TOMA<T> mat)CO NE;CE TOMA<T> OP-(TOMA<T> mat)CO NE;CE TOMA<T> OP*(CO T& scalar)CO NE;IN TOMA<T> OP/(CO T& scalar)CO;IN TOMA<T> OP%(CO T& scalar)CO;CE CO T& Get(CRUI y)CO NE;CE T& Ref(CRUI y)NE;};
TE <TY T> CE TOMA<T>::TOMA(T M0,T M1)NE:m_M0(MO(M0)),m_M1(MO(M1)){}TE <TY T> CE TOMA<T>::TOMA(CO TOMA<T>& mat)NE:m_M0(mat.m_M0),m_M1(mat.m_M1){}TE <TY T> CE TOMA<T>::TOMA(TOMA<T>&& mat)NE:m_M0(MO(mat.m_M0)),m_M1(MO(mat.m_M1)){}TE <TY T> CE TOMA<T>& TOMA<T>::OP=(TOMA<T> mat)NE{m_M0 = MO(mat.m_M0);m_M1 = MO(mat.m_M1);RE *TH;}TE <TY T> CE TOMA<T>& TOMA<T>::OP+=(CO TOMA<T>& mat)NE{m_M0 += mat.m_M0;m_M1 += mat.m_M1;RE *TH;}TE <TY T> CE TOMA<T>& TOMA<T>::OP-=(CO TOMA<T>& mat)NE{m_M0 -= mat.m_M0;m_M1 -= mat.m_M1;RE *TH;}TE <TY T> CE TOMA<T>& TOMA<T>::OP*=(CO T& scalar)NE{m_M0 *= scalar;m_M1 *= scalar;RE *TH;}TE <TY T> IN TOMA<T>& TOMA<T>::OP/=(CO T& scalar){m_M0 /= scalar;m_M1 /= scalar;RE *TH;}TE <TY T> IN TOMA<T>& TOMA<T>::OP%=(CO T& scalar){m_M0 %= scalar;m_M1 %= scalar;RE *TH;}TE <TY T> TE <TY INT> CE TOMA<T>& TOMA<T>::Act(TTMA<T> mat,INT EX){EX < 0?(EX = -EX,mat.Invert()):mat;WH(EX > 0){if((EX & 1)== 1){T M0 = mat.m_M00 * m_M0 + mat.m_M01 * m_M1;m_M1 = mat.m_M10 * m_M0 + mat.m_M11 * m_M1;m_M0 = MO(M0);}mat = mat.Square();EX >>= 1;}RE *TH;}TE <TY T> TE <TY INT> CE TOMA<T> TOMA<T>::Action(TTMA<T> mat,INT EX)CO{RE TOMA<T>(*TH).Act(MO(mat),MO(EX));}TE <TY T> CE TOMA<T> TOMA<T>::OP+(TOMA<T> mat)CO NE{RE MO(mat += *TH);}TE <TY T> CE TOMA<T> TOMA<T>::OP-(TOMA<T> mat)CO NE{RE MO(mat -= *TH);}TE <TY T> CE TOMA<T> TOMA<T>::OP*(CO T& scalar)CO NE{RE MO(TOMA<T>(*TH)*= scalar);}TE <TY T> IN TOMA<T> TOMA<T>::OP/(CO T& scalar)CO{RE MO(TOMA<T>(*TH)/ scalar);}TE <TY T> IN TOMA<T> TOMA<T>::OP%(CO T& scalar)CO{RE MO(TOMA<T>(*TH)% scalar);}TE <TY T> CE CO T& TOMA<T>::Get(CRUI y)CO NE{RE y == 0?m_M0:m_M1;}TE <TY T> CE T& TOMA<T>::Ref(CRUI y)NE{RE y == 0?m_M0:m_M1;}TE <TY T> CE TOMA<T> OP*(CO TTMA<T>& mat1,CO TOMA<T>& mat2)NE{RE mat2.Action(mat1);}
// AAA 常設でないライブラリは以上に挿入する。

#define INCLUDE_SUB
#include __FILE__

#else // INCLUDE_LIBRARY

#ifdef DEBUG
  #define _GLIBCXX_DEBUG
  #define REPEAT_MAIN( BOUND ) START_MAIN; signal( SIGABRT , &AlertAbort ); AutoCheck( exec_mode , use_getline ); if( exec_mode == sample_debug_mode || exec_mode == submission_debug_mode || exec_mode == library_search_mode ){ RE 0; } else if( exec_mode == experiment_mode ){ Experiment(); RE 0; } else if( exec_mode == small_test_mode ){ SmallTest(); RE 0; }; CEXPR( int , bound_test_case_num , BOUND ); int test_case_num = 1; if( exec_mode == solve_mode ){ if CE( bound_test_case_num > 1 ){ CERR( "テストケースの個数を入力してください。" ); SET_ASSERT( test_case_num , 1 , bound_test_case_num ); } } else if( exec_mode == random_test_mode ){ CERR( "ランダムテストを行う回数を指定してください。" ); SET_LL( test_case_num ); } FINISH_MAIN
  #define DEXPR( LL , BOUND , VALUE1 , VALUE2 ) CEXPR( LL , BOUND , VALUE2 )
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
  #define DEXPR( LL , BOUND , VALUE1 , VALUE2 ) CEXPR( LL , BOUND , VALUE1 )
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
  #define SET_A( A , N ) SOLVE_ONLY; FOR( VARIABLE_FOR_SET_A , 0 , N ){ cin >> A[VARIABLE_FOR_SET_A]; }
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
#define SET_A_ASSERT( A , N , MIN , MAX ) FOR( VARIABLE_FOR_SET_A , 0 , N ){ SET_ASSERT( A[VARIABLE_FOR_SET_A] , MIN , MAX ); }
#define CIN_ASSERT( A , MIN , MAX ) decldecay_t( MAX ) A; SET_ASSERT( A , MIN , MAX )
#define CIN_A_ASSERT( A , N , MIN , MAX ) vector<decldecay_t( MAX )> A( N ); SET_A_ASSERT( A , N , MIN , MAX )
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
#define VI virtual 
#define ST_AS static_assert
#define reMO_CO remove_const
#define is_COructible_v is_constructible_v
#define rBE rbegin
#define reSZ resize

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
TE <CL Traits , TY Arg1 , TY Arg2> IN basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , CO pair<Arg1,Arg2>& arg ) { RE os << arg.first << " " << arg.second; }
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
      CERR( "二分探索中：" , "L_BS =" , L_BS , "<=" , #ANSWER , "=" , ANSWER , "<=" , U_BS , "= U_BS :" , #EXPRESSION , "=" , EXPRESSION_BS , DIFFERENCE_BS > 0 ? ">" : DIFFERENCE_BS < 0 ? "<" : "=" , CO_TARGET_BS , "=" , #CO_TARGET ); \
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
#define BS1( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CO_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CO_TARGET , >= , ANSWER , ANSWER + 1 , ( L_BS + U_BS ) / 2 )
// 単調増加の時にEXPRESSION <= CO_TARGETの最大解を格納。
#define BS2( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CO_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CO_TARGET , > , ANSWER - 1 , ANSWER , ( L_BS + 1 + U_BS ) / 2 )
// 単調減少の時にEXPRESSION >= CO_TARGETの最大解を格納。
#define BS3( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CO_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CO_TARGET , < , ANSWER - 1 , ANSWER , ( L_BS + 1 + U_BS ) / 2 )
// 単調減少の時にEXPRESSION <= CO_TARGETの最小解を格納。
#define BS4( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CO_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CO_TARGET , <= , ANSWER , ANSWER + 1 , ( L_BS + U_BS ) / 2 )
// t以下の値が存在すればその最大値のiterator、存在しなければend()を返す。
TE <TY T> IN TY set<T>::iterator MaximumLeq( set<T>& S , CO T& t ) { CO auto EN = S.EN(); if( S.empty() ){ RE EN; } auto itr = S.upper_bound( t ); RE itr == EN ? S.find( *( S.rBE() ) ) : itr == S.BE() ? EN : --itr; }
// t未満の値が存在すればその最大値のiterator、存在しなければend()を返す。
TE <TY T> IN TY set<T>::iterator MaximumLt( set<T>& S , CO T& t ) { CO auto EN = S.EN(); if( S.empty() ){ RE EN; } auto itr = S.lower_bound( t ); RE itr == EN ? S.find( *( S.rBE() ) ) : itr == S.BE() ? EN : --itr; }
// t以上の値が存在すればその最小値のiterator、存在しなければend()を返す。
TE <TY T> IN TY set<T>::iterator MinimumGeq( set<T>& S , CO T& t ) { RE S.lower_bound( t ); }
// tより大きい値が存在すればその最小値のiterator、存在しなければend()を返す。
TE <TY T> IN TY set<T>::iterator MinimumGt( set<T>& S , CO T& t ) { RE S.upper_bound( t ); }

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
    WH( CONTINUE_CONDITION ){						\
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
TE <TY T , TE <TY...> TY V> IN auto Get( CO V<T>& a ) { return [&]( CRI i = 0 ){ RE a[i]; }; }

// グリッド問題用
int H , W , H_minus , W_minus , HW;
VE<VE<bool>> non_wall;
IN T2<int> EnumHW( CRI v ) { RE { v / W , v % W }; }
IN int EnumHW_inv( CO T2<int>& ij ) { auto& [i,j] = ij; RE i * W + j; }
CO string direction[4] = {"U","R","D","L"};
// (i,j)->(k,h)の方向番号を取得
IN int DirectionNumberOnGrid( CRI i , CRI j , CRI k , CRI h ){RE i<k?2:i>k?0:j<h?1:j>h?3:(AS(false),-1);}
// v->wの方向番号を取得
IN int DirectionNumberOnGrid( CRI v , CRI w ){auto [i,j]=EnumHW(v);auto [k,h]=EnumHW(w);RE DirectionNumberOnGrid(i,j,k,h);}
// 方向番号の反転U<->D、R<->L
IN int ReverseDirectionNumberOnGrid( CRI n ){AS(0<=n&&n<4);RE(n+2)%4;}
IN VO SetEdgeOnGrid( CO string& Si , CRI i , VE<LI<int>>& e , CO char& walkable = '.' ){FOR(j,0,W){if(Si[j]==walkable){int v = EnumHW_inv({i,j});if(i>0){e[EnumHW_inv({i-1,j})].push_back(v);}if(i+1<H){e[EnumHW_inv({i+1,j})].push_back(v);}if(j>0){e[EnumHW_inv({i,j-1})].push_back(v);}if(j+1<W){e[EnumHW_inv({i,j+1})].push_back(v);}}}}
IN VO SetEdgeOnGrid( CO string& Si , CRI i , VE<LI<path>>& e , CO char& walkable = '.' ){FOR(j,0,W){if(Si[j]==walkable){CO int v=EnumHW_inv({i,j});if(i>0){e[EnumHW_inv({i-1,j})].push_back({v,1});}if(i+1<H){e[EnumHW_inv({i+1,j})].push_back({v,1});}if(j>0){e[EnumHW_inv({i,j-1})].push_back({v,1});}if(j+1<W){e[EnumHW_inv({i,j+1})].push_back({v,1});}}}}
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
// ConstexprModulo (7KB)
// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/compress.txt
#define RP Represent
#define DeRP Derepresent
#define MN Montgomery
CEXPR(int,P,998244353);
TE <uint M,TY INT> CE INT RS(INT n)NE{RE MO(n < 0?((((++n)*= -1)%= M)*= -1)+= M - 1:n < INT(M)?n:n %= M);}
#define DC_OF_CM_FOR_MN(OPR)CE bool OP OPR(CO MN<M>& n)CO NE
#define DC_OF_AR_FOR_MN(OPR,EX)IN MN<M> OP OPR(MN<M> n)CO EX;
#define DF_OF_CM_FOR_MN(OPR)TE <uint M> CE bool MN<M>::OP OPR(CO MN<M>& n)CO NE{RE m_n OPR n.m_n;}
#define DF_OF_AR_FOR_MN(OPR,EX,LEFT,OPR2)TE <uint M> IN MN<M> MN<M>::OP OPR(MN<M> n)CO EX{RE MO(LEFT OPR2 ## = *TH);}TE <uint M,TY T> IN MN<M> OP OPR(T n0,CO MN<M>& n1)EX{RE MO(MN<M>(MO(n0))OPR ## = n1);}
TE <uint M>CL MN{PU:uint m_n;CE MN()NE;CE MN(CO MN<M>& n)NE;CE MN(MN<M>&& n)NE;TE <TY T> CE MN(T n)NE;CE MN<M>& OP=(MN<M> n)NE;CE MN<M>& OP+=(CO MN<M>& n)NE;CE MN<M>& OP-=(CO MN<M>& n)NE;CE MN<M>& OP*=(CO MN<M>& n)NE;IN MN<M>& OP/=(MN<M> n);TE <TY INT> CE MN<M>& OP<<=(INT n);TE <TY INT> CE MN<M>& OP>>=(INT n);CE MN<M>& OP++()NE;CE MN<M> OP++(int)NE;CE MN<M>& OP--()NE;CE MN<M> OP--(int)NE;DC_OF_CM_FOR_MN(==);DC_OF_CM_FOR_MN(!=);DC_OF_AR_FOR_MN(+,NE);DC_OF_AR_FOR_MN(-,NE);DC_OF_AR_FOR_MN(*,NE);DC_OF_AR_FOR_MN(/,);TE <TY INT> CE MN<M> OP^(INT EX)CO;TE <TY INT> CE MN<M> OP<<(INT n)CO;TE <TY INT> CE MN<M> OP>>(INT n)CO;CE MN<M> OP-()CO NE;CE MN<M>& SignInvert()NE;CE MN<M>& Invert();TE <TY INT> CE MN<M>& PW(INT EX);CE VO swap(MN<M>& n)NE;CE uint RP()CO NE;ST CE MN<M> DeRP(CO uint& n)NE;ST IN CO MN<M>& Inverse(CO uint& n);ST IN CO MN<M>& Factorial(CO uint& n);ST IN CO MN<M>& FactorialInverse(CO uint& n);ST IN MN<M> Combination(CO uint& n,CO uint& i);ST IN CO MN<M>& zero()NE;ST IN CO MN<M>& one()NE;ST IN CO MN<M>& two()NE;ST CE uint Form(CO uint& n)NE;ST CE ull& Reduction(ull& n)NE;ST CE ull& ReducedMU(ull& n,CO uint& m)NE;ST CE uint BaseSquareTruncation(uint& n)NE;TE <TY INT> CE MN<M>& PositivePW(INT EX)NE;TE <TY INT> CE MN<M>& NonNegativePW(INT EX)NE;TE <TY T> CE MN<M>& Ref(T&& n)NE;ST CE uint& Normalise(uint& n)NE;};
US MP = MN<P>;
TE <uint M>CL COantsForMN{PU:COantsForMN()= delete;ST CE CO bool g_even =((M & 1)== 0);ST CE CO uint g_memory_bound =
#ifdef DEBUG
1e3;
#else
1e6;
#endif
ST CE CO uint g_memory_LE = M < g_memory_bound?M:g_memory_bound;ST CE uint g_M_minus_2 = M - 2;ST CE uint g_M_minus_2_neg = 2 - M;ST CE ull MNBasePW(ull&& EX)NE;ST CE CO int g_MN_digit = 32;ST CE CO ull g_MN_base = ull(1)<< g_MN_digit;ST CE CO uint g_MN_base_minus = uint(g_MN_base - 1);ST CE CO uint g_MN_digit_half =(g_MN_digit + 1)>> 1;ST CE CO uint g_MN_base_sqrt_minus =(1 << g_MN_digit_half)- 1;ST CE CO uint g_MN_M_neg_inverse = uint((g_MN_base - MNBasePW((ull(1)<<(g_MN_digit - 1))- 1))& g_MN_base_minus);ST CE CO uint g_MN_base_mod = uint(g_MN_base % M);ST CE CO uint g_MN_base_square_mod = uint(((g_MN_base % M)*(g_MN_base % M))% M);};
TE <uint M> CE ull COantsForMN<M>::MNBasePW(ull&& EX)NE{ull prod = 1;ull PW = M;WH(EX != 0){(EX & 1)== 1?(prod *= PW)&= g_MN_base_minus:prod;EX >>= 1;(PW *= PW)&= g_MN_base_minus;}RE prod;}TE <uint M> CE MN<M>::MN()NE:m_n(){ST_AS(!COantsForMN<M>::g_even);}TE <uint M> CE MN<M>::MN(CO MN<M>& n)NE:m_n(n.m_n){}TE <uint M> CE MN<M>::MN(MN<M>&& n)NE:m_n(MO(n.m_n)){}TE <uint M> TE <TY T> CE MN<M>::MN(T n)NE:m_n(Form(RS<M>(MO(n)))){ST_AS(!COantsForMN<M>::g_even && is_COructible_v<uint,decay_t<T> >);}TE <uint M> CE MN<M>& MN<M>::OP=(MN<M> n)NE{RE Ref(m_n = MO(n.m_n));}TE <uint M> CE MN<M>& MN<M>::OP+=(CO MN<M>& n)NE{RE Ref(Normalise(m_n += n.m_n));}TE <uint M> CE MN<M>& MN<M>::OP-=(CO MN<M>& n)NE{RE Ref(m_n < n.m_n?(m_n += M)-= n.m_n:m_n -= n.m_n);}TE <uint M> CE MN<M>& MN<M>::OP*=(CO MN<M>& n)NE{ull m_n_copy = m_n;RE Ref(m_n = MO(ReducedMU(m_n_copy,n.m_n)));}TE <uint M> IN MN<M>& MN<M>::OP/=(MN<M> n){RE OP*=(MN<M>(n).Invert());}TE <uint M> TE <TY INT> CE MN<M>& MN<M>::OP<<=(INT n){RE AS(n >= 0);RE *TH *= MN<M>(two()).NonNegativePW(MO(n));}TE <uint M> TE <TY INT> CE MN<M>& MN<M>::OP>>=(INT n){AS(n >=0);WH(n-- > 0){((m_n & 1)== 0?m_n:m_n += M)>>= 1;}RE *TH;}TE <uint M> CE MN<M>& MN<M>::OP++()NE{RE Ref(Normalise(m_n += COantsForMN<M>::g_MN_base_mod));}TE <uint M> CE MN<M> MN<M>::OP++(int)NE{MN<M> n{*TH};OP++();RE n;}TE <uint M> CE MN<M>& MN<M>::OP--()NE{RE Ref((m_n < COantsForMN<M>::g_MN_base_mod?m_n += M:m_n)-= COantsForMN<M>::g_MN_base_mod);}TE <uint M> CE MN<M> MN<M>::OP--(int)NE{MN<M> n{*TH};OP--();RE n;}DF_OF_CM_FOR_MN(==);DF_OF_CM_FOR_MN(!=);DF_OF_AR_FOR_MN(+,NE,n,+);DF_OF_AR_FOR_MN(-,NE,n.SignInvert(),+);DF_OF_AR_FOR_MN(*,NE,n,*);DF_OF_AR_FOR_MN(/,,n.Invert(),*);TE <uint M> TE <TY INT> CE MN<M> MN<M>::OP^(INT EX)CO{RE MO(MN<M>(*TH).PW(MO(EX)));}TE <uint M> TE <TY INT> CE MN<M> MN<M>::OP<<(INT n)CO{RE MO(MN<M>(*TH)<<= MO(n));}TE <uint M> TE <TY INT> CE MN<M> MN<M>::OP>>(INT n)CO{RE MO(MN<M>(*TH)>>= MO(n));}TE <uint M> CE MN<M> MN<M>::OP-()CO NE{RE MO(MN<M>(*TH).SignInvert());}TE <uint M> CE MN<M>& MN<M>::SignInvert()NE{RE Ref(m_n > 0?m_n = M - m_n:m_n);}TE <uint M> CE MN<M>& MN<M>::Invert(){AS(m_n != 0);RE PositivePW(uint(COantsForMN<M>::g_M_minus_2));}TE <uint M> TE <TY INT> CE MN<M>& MN<M>::PositivePW(INT EX)NE{MN<M> PW{*TH};(--EX)%= COantsForMN<M>::g_M_minus_2;WH(EX != 0){(EX & 1)== 1?*TH *= PW:*TH;EX >>= 1;PW *= PW;}RE *TH;}TE <uint M> TE <TY INT> CE MN<M>& MN<M>::NonNegativePW(INT EX)NE{RE EX == 0?Ref(m_n = COantsForMN<M>::g_MN_base_mod):PositivePW(MO(EX));}TE <uint M> TE <TY INT> CE MN<M>& MN<M>::PW(INT EX){bool neg = EX < 0;AS(!(neg && m_n == 0));RE neg?PositivePW(MO(EX *= COantsForMN<M>::g_M_minus_2_neg)):NonNegativePW(MO(EX));}TE <uint M> CE VO MN<M>::swap(MN<M>& n)NE{std::swap(m_n,n.m_n);}TE <uint M> CE uint MN<M>::RP()CO NE{ull m_n_copy = m_n;RE MO(Reduction(m_n_copy));}TE <uint M> CE MN<M> MN<M>::DeRP(CO uint& n)NE{MN<M> n_copy{};n_copy.m_n = Form(n);RE n_copy;}TE <uint M> IN CO MN<M>& MN<M>::Inverse(CO uint& n){AS(n < COantsForMN<M>::g_memory_LE);ST uint memory0[COantsForMN<M>::g_memory_LE]={0,1};ST MN<M> memory1[COantsForMN<M>::g_memory_LE]={zero(),one()};ST uint LE_curr = 2;WH(LE_curr <= n){memory1[LE_curr].m_n = Form(memory0[LE_curr]= M - memory0[M % LE_curr]* ull(M / LE_curr)% M);LE_curr++;}RE memory1[n];}TE <uint M> IN CO MN<M>& MN<M>::Factorial(CO uint& n){AS(n < COantsForMN<M>::g_memory_LE);ST MN<M> memory[COantsForMN<M>::g_memory_LE]={one(),one()};ST uint LE_curr = 2;ST MN<M> val_curr{one()};ST MN<M> val_last{one()};WH(LE_curr <= n){memory[LE_curr++]= val_curr *= ++val_last;}RE memory[n];}TE <uint M> IN CO MN<M>& MN<M>::FactorialInverse(CO uint& n){ST MN<M> memory[COantsForMN<M>::g_memory_LE]={one(),one()};ST uint LE_curr = 2;ST MN<M> val_curr{one()};ST MN<M> val_last{one()};WH(LE_curr <= n){memory[LE_curr]= val_curr *= Inverse(LE_curr);LE_curr++;}RE memory[n];}TE <uint M> IN MN<M> MN<M>::Combination(CO uint& n,CO uint& i){RE i <= n?Factorial(n)* FactorialInverse(i)* FactorialInverse(n - i):zero();}TE <uint M> IN CO MN<M>& MN<M>::zero()NE{ST CE CO MN<M> z{};RE z;}TE <uint M> IN CO MN<M>& MN<M>::one()NE{ST CE CO MN<M> o{1};RE o;}TE <uint M> IN CO MN<M>& MN<M>::two()NE{ST CE CO MN<M> t{2};RE t;}TE <uint M> CE uint MN<M>::Form(CO uint& n)NE{ull n_copy = n;RE uint(MO(Reduction(n_copy *= COantsForMN<M>::g_MN_base_square_mod)));}TE <uint M> CE ull& MN<M>::Reduction(ull& n)NE{ull n_sub = n & COantsForMN<M>::g_MN_base_minus;RE((n +=((n_sub *= COantsForMN<M>::g_MN_M_neg_inverse)&= COantsForMN<M>::g_MN_base_minus)*= M)>>= COantsForMN<M>::g_MN_digit)< M?n:n -= M;}TE <uint M> CE ull& MN<M>::ReducedMU(ull& n,CO uint& m)NE{RE Reduction(n *= m);}TE <uint M> CE uint MN<M>::BaseSquareTruncation(uint& n)NE{CO uint n_u = n >> COantsForMN<M>::g_MN_digit_half;n &= COantsForMN<M>::g_MN_base_sqrt_minus;RE n_u;}TE <uint M> TE <TY T> CE MN<M>& MN<M>::Ref(T&& n)NE{RE *TH;}TE <uint M> CE uint& MN<M>::Normalise(uint& n)NE{RE n < M?n:n -= M;}TE <uint M> CE MN<M> Inverse(CO MN<M>& n){RE MO(MN<M>(n).Invert());}TE <uint M,TY INT> CE MN<M> PW(MN<M> n,INT EX){RE MO(n.PW(MO(EX)));}TE <uint M> CE VO swap(MN<M>& n0,MN<M>& n1)NE{n0.swap(n1);}TE <uint M> IN string to_string(CO MN<M>& n)NE{RE to_string(n.RP())+ to_string(M)+ "Z";}TE <uint M,CL Traits> IN basic_istream<char,Traits>& OP>>(basic_istream<char,Traits>& is,MN<M>& n){ll m;is >> m;n = m;RE is;}TE<uint M,CL Traits> IN basic_ostream<char,Traits>& OP<<(basic_ostream<char,Traits>& os,CO MN<M>& n){RE os << n.RP();}
// AAA 常設ライブラリは以上に挿入する。

#define INCLUDE_LIBRARY
#include __FILE__

#endif // INCLUDE_LIBRARY

#endif // INCLUDE_SUB

#endif // INCLUDE_MAIN

// （Derepresent,+=,-=,*=,SignInvert,+,*,^,++,--,Combination,zero,one）

// Mが奇数の場合にのみサポート
template <INT_TYPE_FOR_MONTGOMERY M>
class Montgomery
{

private:
  INT_TYPE_FOR_MONTGOMERY m_n;

public:
  inline constexpr Montgomery() noexcept;
  inline constexpr Montgomery( const Montgomery<M>& n ) noexcept;
  inline constexpr Montgomery( Montgomery<M>&& n ) noexcept;
  template <typename T> inline constexpr Montgomery( T n ) noexcept;

  inline constexpr Montgomery<M>& operator=( Montgomery<M> n ) noexcept;
  inline constexpr Montgomery<M>& operator+=( const Montgomery<M>& n ) noexcept;
  inline constexpr Montgomery<M>& operator-=( const Montgomery<M>& n ) noexcept;
  inline constexpr Montgomery<M>& operator*=( const Montgomery<M>& n ) noexcept;
  inline Montgomery<M>& operator/=( Montgomery<M> n );
  // n>=0である場合のみサポート。計算量O(log n)で2^n倍する。
  template <typename INT> inline constexpr Montgomery<M>& operator<<=( INT n );
  // n>=0かつMが奇数である場合のみサポート。計算量O(n)で2^{-n}倍する。
  template <typename INT> inline constexpr Montgomery<M>& operator>>=( INT n );

  inline constexpr Montgomery<M>& operator++() noexcept;
  inline constexpr Montgomery<M> operator++( int ) noexcept;
  inline constexpr Montgomery<M>& operator--() noexcept;
  inline constexpr Montgomery<M> operator--( int ) noexcept;

  DECLARATION_OF_COMPARISON_FOR_MONTGOMERY( == );
  DECLARATION_OF_COMPARISON_FOR_MONTGOMERY( != );
  
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( + , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( - , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( * , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( / , );
  // Mが素数であるかexponent>=0である場合にのみサポート。
  template <typename INT> inline constexpr Montgomery<M> operator^( INT exponent ) const;
  // n>=0である場合のみサポート。計算量O(log n)で2^n倍する。
  template <typename INT> inline constexpr Montgomery<M> operator<<( INT n ) const;
  // n>=0かつMが奇数である場合のみサポート。計算量O(n)で2^{-n}倍する。
  template <typename INT> inline constexpr Montgomery<M> operator>>( INT n ) const;

  inline constexpr Montgomery<M> operator-() const noexcept;
  inline constexpr Montgomery<M>& SignInvert() noexcept;
  // Mが素数である場合のみサポート。
  inline constexpr Montgomery<M>& Invert();
  // Mが素数であるかexponent>=0である場合にのみサポート。
  template <typename INT> inline constexpr Montgomery<M>& Power( INT exponent );
  // グローバルスコープでswapを定義するためのもの。
  inline constexpr void swap( Montgomery<M>& n ) noexcept;

  inline constexpr INT_TYPE_FOR_MONTGOMERY Represent() const noexcept;
  // 0 <= n < Mの場合のみサポート。定数倍高速化のためにassertなし。
  static inline constexpr Montgomery<M> Derepresent( const INT_TYPE_FOR_MONTGOMERY& n ) noexcept;

  // Mが素数かつn < g_memory_lengthである場合のみサポート。
  static inline const Montgomery<M>& Inverse( const INT_TYPE_FOR_MONTGOMERY& n );
  // n < g_memory_lengthである場合のみサポート。
  static inline const Montgomery<M>& Factorial( const INT_TYPE_FOR_MONTGOMERY& n );
  // Mが素数かつn < g_memory_lengthである場合のみサポート。
  static inline const Montgomery<M>& FactorialInverse( const INT_TYPE_FOR_MONTGOMERY& n );
  // Mが素数かつn < g_memory_lengthである場合のみサポート。
  static inline Montgomery<M> Combination( const INT_TYPE_FOR_MONTGOMERY& n , const INT_TYPE_FOR_MONTGOMERY& i );

  static inline const Montgomery<M>& zero() noexcept;
  static inline const Montgomery<M>& one() noexcept;
  static inline const Montgomery<M>& two() noexcept;

private:
  static inline constexpr INT_TYPE_FOR_MONTGOMERY Form( const INT_TYPE_FOR_MONTGOMERY& n ) noexcept;
  static inline constexpr ull& Reduction( ull& n ) noexcept;
  static inline constexpr ull& ReducedMultiplication( ull& n , const INT_TYPE_FOR_MONTGOMERY& m ) noexcept;
  static inline constexpr uint BaseSquareTruncation( INT_TYPE_FOR_MONTGOMERY& n ) noexcept;

  template <typename INT> inline constexpr Montgomery<M>& PositivePower( INT exponent ) noexcept;
  template <typename INT> inline constexpr Montgomery<M>& NonNegativePower( INT exponent ) noexcept;

  template <typename T> inline constexpr Montgomery<M>& Ref( T&& n ) noexcept;
  static inline constexpr INT_TYPE_FOR_MONTGOMERY& Normalise( INT_TYPE_FOR_MONTGOMERY& n ) noexcept;

};

// Mが素数でありnが0でない場合にのみサポート。
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M> Inverse( const Montgomery<M>& n );

// Mが素数であるかexponent>=0である場合にのみサポート。
template <INT_TYPE_FOR_MONTGOMERY M , typename INT> inline constexpr Montgomery<M> Power( const Montgomery<M>& n , INT exponent );

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr void swap( Montgomery<M>& n0 , Montgomery<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MONTGOMERY M> inline string to_string( const Montgomery<M>& n ) noexcept;

template <INT_TYPE_FOR_MONTGOMERY M , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , Montgomery<M>& n );
template <INT_TYPE_FOR_MONTGOMERY M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Montgomery<M>& n );
