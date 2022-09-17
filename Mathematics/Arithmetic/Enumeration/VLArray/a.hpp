// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/VLArray/a.hpp

#pragma once
#include "../a.hpp"

#include "../../../../Utility/VLArray/a.hpp"

// 濃度a_d[0],a_d[1],...の集合の排他的和集合の数え上げ
void BijSum1N( const VLArray<dim>& a_d , const INT_TYPE_FOR_DIM& n , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 );

// BijSum1Nの逆
INT_TYPE_FOR_DIM BijSumN1( const VLArray<dim>& a_d , const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 );

// 濃度a_d[0],a_d[1],...の集合の直積の数え上げ
VLArray<INT_TYPE_FOR_DIM> BijProd1N( const VLArray<dim>& a_d , const INT_TYPE_FOR_DIM& n );
void BijProd1N( const VLArray<dim>& a_d , const INT_TYPE_FOR_DIM& n , VLArray<INT_TYPE_FOR_DIM>& a_n );

// 可算無限濃度の集合N個の直積の数え上げ
inline VLArray<INT_TYPE_FOR_DIM> BijProd1N( const INT_TYPE_FOR_DIM& N , const INT_TYPE_FOR_DIM& n );
inline void BijProd1N( const INT_TYPE_FOR_DIM& N , const INT_TYPE_FOR_DIM& n , VLArray<INT_TYPE_FOR_DIM>& a_n );

// BijProd1Nの逆
INT_TYPE_FOR_DIM BijProdN1( const VLArray<dim>& a_d , const VLArray<INT_TYPE_FOR_DIM>& a_n );
inline INT_TYPE_FOR_DIM BijProdN1( const VLArray<INT_TYPE_FOR_DIM>& a_n );


// 可算無限濃度の集合可算無限個の直積の本質的有限部分の数え上げ
void BijProd1Infty( const INT_TYPE_FOR_DIM& n , VLArray<INT_TYPE_FOR_DIM>& a );
VLArray<INT_TYPE_FOR_DIM> BijProd1Infty( const INT_TYPE_FOR_DIM& );


// 階乗（INT = Mod<M>の時にMでの値が1であることに注意）
template <typename INT> inline INT Factorial( const INT& n , const INT& n_min = 1 , const string& mode = "normal" );

// modular階乗（INT1 = Mod<M>の時にMでの値が0であることに注意）
template <typename INT1 , typename INT2> inline INT1 ModularFactorial( const INT2& n , const INT2& n_min = 1 , const string& mode = "normal" );

// 再帰式（呼び出し順によっては再帰深度が大きい）
template <typename INT1 , typename INT2>
const INT1& ModularFactorialNormalMethod( const INT2& n );
template <typename INT1 , typename INT2>
const INT1& ModularFactorialNormalMethod( const INT2& n , const INT2& n_min );
template <typename INT1 , typename INT2>
const INT1& ModularFactorialNormalMethod_Body( const INT2& n , const INT2& n_min );

// ループ
template <typename INT1 , typename INT2>
INT1 ModularFactorialLoopMethod( const INT2& n , const INT2& n_min = 1 );

// modular階乗の逆数（INT1 = Mod<M>の時にMでの値がサポート外であることに注意）
template <typename INT1 , typename INT2> inline INT1 ModularFactorialInverse( const INT2& n , const INT2& n_min = 1 , const string& mode = "normal" );

// 再帰式（呼び出し順によっては再帰深度が大きい）
template <typename INT1 , typename INT2>
const INT1& ModularFactorialInverseNormalMethod( const INT2& n );
template <typename INT1 , typename INT2>
const INT1& ModularFactorialInverseNormalMethod( const INT2& n , const INT2& n_min );
template <typename INT1 , typename INT2>
const INT1& ModularFactorialInverseNormalMethod_Body( const INT2& n , const INT2& n_min );

// ループ
template <typename INT1 , typename INT2>
INT1 ModularFactorialInverseLoopMethod( const INT2& n , const INT2& n_min = 1 );

// 場合の数
template <typename INT>
INT Combination( const INT& n , const INT& m , const string& mode = "normal" );

// 再帰式（呼び出し順によっては再帰深度が大きい）
template <typename INT>
const INT& CombinationNormalMethod( const INT& n , const INT& m );

// ループ（割り算回数が大きい）
template <typename INT>
INT CombinationLoopMethod( const INT& n , const INT& m );

// 階乗の比（modular演算でない時はオーバーフローしやすい）
template <typename INT> inline INT CombinationFactorialNormalMethod( const INT& n , const INT& m );
template <typename INT> inline INT CombinationFactorialLoopMethod( const INT& n , const INT& m );
template <typename INT> inline INT CombinationModularFactorialInverseNormalMethod( const INT& n , const INT& m );
template <typename INT> inline INT CombinationModularFactorialInverseLoopMethod( const INT& n , const INT& m );

