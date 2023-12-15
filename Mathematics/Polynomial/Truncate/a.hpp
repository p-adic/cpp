// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Mod/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// 非常によくバグるので、更新したら必ずverifyすること！
// verify:
// https://judge.yosupo.jp/submission/175535 畳み込み
// https://judge.yosupo.jp/submission/176529 剰余
// https://judge.yosupo.jp/submission/176829 平行移動
// https://yukicoder.me/submissions/938613 メビウス変換
// https://yukicoder.me/submissions/937654 多点評価
// https://yukicoder.me/submissions/937650 ボスタン森

template <typename T> class TruncatedPolynomial;

template <typename T> TruncatedPolynomial<T> Differential( const uint& n , const TruncatedPolynomial<T>& f );
template <typename T> TruncatedPolynomial<T> TruncatedDifferential( const TruncatedPolynomial<T>& f , const uint& N_output_start_plus_one );
template <typename T> TruncatedPolynomial<T> TruncatedIntegral( const TruncatedPolynomial<T>& f , const uint& N_output_start );

template <typename T>
class TruncatedPolynomial :
  public Polynomial<T>
{

  friend TruncatedPolynomial<T> Differential<T>( const uint& n , const TruncatedPolynomial<T>& f );
  friend TruncatedPolynomial<T> TruncatedDifferential<T>( const TruncatedPolynomial<T>& f , const uint& N_output_start_plus_one );
  friend TruncatedPolynomial<T> TruncatedIntegral<T>( const TruncatedPolynomial<T>& f , const uint& N_output_start );
  
private:
  // mod X^{m_N}で計算する。
  // m_N == 0でも動くが、その場合はm_size == 1の時にm_size <= m_Nが成り立たなくなることに注意
  uint m_N;
  
public:
  inline TruncatedPolynomial( const uint& N = 0 );
  inline TruncatedPolynomial( const TruncatedPolynomial<T>& f );
  inline TruncatedPolynomial( TruncatedPolynomial<T>&& f );
  inline TruncatedPolynomial( const uint& N , const T& t );
  inline TruncatedPolynomial( const uint& N , const Polynomial<T>& f );
  inline TruncatedPolynomial( const uint& N , Polynomial<T>&& f );
  inline TruncatedPolynomial( const uint& N , const uint& i , const T& t );
  inline TruncatedPolynomial( const uint& N , const uint& i , T&& t );
  template <SFINAE_FOR_POLYNOMIAL( = nullptr )> inline TruncatedPolynomial( const uint& N , const uint& i , const Arg& t );
  inline TruncatedPolynomial( const uint& N , vector<T>&& f );

  // m_Nも代入されることに注意
  inline TruncatedPolynomial<T>& operator=( const TruncatedPolynomial<T>& f );
  inline TruncatedPolynomial<T>& operator=( TruncatedPolynomial<T>&& f );
  inline TruncatedPolynomial<T>& operator=( const T& t );
  inline TruncatedPolynomial<T>& operator=( T&& t );
  template <SFINAE_FOR_POLYNOMIAL( = nullptr )> inline TruncatedPolynomial<T>& operator=( const Arg& n );
  inline TruncatedPolynomial<T>& operator=( const Polynomial<T>& f );
  inline TruncatedPolynomial<T>& operator=( Polynomial<T>&& f );

  // m_Nは変化しないことに注意
  inline TruncatedPolynomial<T>& operator+=( const T& t );
  inline TruncatedPolynomial<T>& operator+=( const Polynomial<T>& f );
  // m_N == 0の時のみm_Nが変化する。（内積などの計算の仕様）
  inline TruncatedPolynomial<T>& operator+=( const TruncatedPolynomial<T>& f );
  
  // N_input_lim <= f.size()の場合のみサポート。
  // 自身を(N_input_start個の0,f[N_input_start],...,f[N_input_lim-1],0,...)を足した値 mod X^{ m_N }で置き換える。
  TruncatedPolynomial<T>& TruncatedPlus( const Polynomial<T>& f , const uint& N_input_start , const uint& N_input_limit );

  // m_Nは変化しないことに注意
  inline TruncatedPolynomial<T>& operator-=( const T& t );
  inline TruncatedPolynomial<T>& operator-=( const Polynomial<T>& f );
  // m_N == 0の時のみm_Nが変化する。
  inline TruncatedPolynomial<T>& operator-=( const TruncatedPolynomial<T>& f );

  // N_input_lim <= f.size()の場合のみサポート。
  // 自身を(N_input_start個の0,f[N_input_start],...,f[N_input_lim-1],0,...)を引いた値 mod X^{ m_N }で置き換える。
  TruncatedPolynomial<T>& TruncatedMinus( const Polynomial<T>& f , const uint& N_input_start , const uint& N_input_limit );

  inline TruncatedPolynomial<T>& operator*=( const T& t );

  // m_N > 0の場合のみサポート。
  TruncatedPolynomial<T>& operator*=( const Polynomial<T>& f );
  inline TruncatedPolynomial<T>& operator*=( Polynomial<T>&& f );

  // m_N > 0の場合のみサポート。
  // 自身をFFTによりf倍 mod X ^ { m_N }を計算した値で置き換える。
  TruncatedPolynomial<T>& FFT_Multiplication( const Polynomial<T>& f );

  // m_N > 0かつf != 0の場合のみサポート。
  // 自身をf倍した値をhとし、長さm_Nの配列
  // (f[0],...,f[N_output_start-1],h[N_output_start],...,h[N_output_lim - 1],0,...)
  // で自身を置き換える。
  TruncatedPolynomial<T>& TruncatedMultiplication( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim );
    
  // m_N > 0かつf != 0の場合のみサポート。
  // 自身のf倍をFFTにより計算した値をhとし、長さm_Nの配列
  // (f[0],...,f[N_output_start-1],h[N_output_start],...,h[N_output_lim - 1],0,...)
  // で自身を置き換える。
  TruncatedPolynomial<T>& FFT_TruncatedMultiplication( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim );
  TruncatedPolynomial<T>& FFT_TruncatedMultiplication( Polynomial<T>&& f , const uint& N_output_start , const uint& N_output_lim );

  // m_N > 0の場合のみサポート。
  // 自身をf倍した値をhとし、長さm_Nの配列
  // (N_output_start個の0,h[N_output_start],...,h[N_output_lim - 1],0,...)
  // を返す。
  TruncatedPolynomial<T> TruncatedMultiplication_const( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim ) const;

  // m_N > 0の場合のみサポート。
  // 自身のf倍をFFTにより計算した値をhとし、長さm_Nの配列
  // (N_output_start個の0,h[N_output_start],...,h[N_output_lim - 1],0,...)
  // を返す。
  TruncatedPolynomial<T> FFT_TruncatedMultiplication_const( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim ) const;
  TruncatedPolynomial<T> FFT_TruncatedMultiplication_const( Polynomial<T>&& f , const uint& N_output_start , const uint& N_output_lim ) const;

  inline TruncatedPolynomial<T>& operator/=( const T& t );
  // Polynomialとしての商でないことに注意。
  inline TruncatedPolynomial<T>& operator/=( const TruncatedPolynomial<T>& t );
  inline TruncatedPolynomial<T>& operator%=( const T& t );

  inline TruncatedPolynomial<T> operator-() const;

  inline void SetTruncation( const uint& N ) noexcept;
  inline const uint& GetTruncation() const noexcept;

  // N次未満を0に変更。
  inline TruncatedPolynomial<T>& TruncateInitial( const uint& N ) noexcept;
  // N次以上を0に変更。
  inline TruncatedPolynomial<T>& TruncateFinal( const uint& N ) noexcept;

};

template <typename T> inline constexpr const uint FFT_Multiplication_border_0 = 17;
template <typename T> inline constexpr const uint FFT_Multiplication_border_1;
template <typename T> inline constexpr const uint FFT_Multiplication_border_1_2;
template <typename T> inline constexpr const uint FFT_Multiplication_border_1_2_exponent;
template <typename T> inline constexpr const uint FFT_Multiplication_border_1_2_inv;

template <typename T , typename P> inline TruncatedPolynomial<T> operator+( const TruncatedPolynomial<T>& f0 , const P& f1 );
template <typename T , typename P> inline TruncatedPolynomial<T> operator-( const TruncatedPolynomial<T>& f );
template <typename T , typename P> inline TruncatedPolynomial<T> operator-( const TruncatedPolynomial<T>& f0 , const P& f1 );
template <typename T , typename P> inline TruncatedPolynomial<T> operator*( const TruncatedPolynomial<T>& f0 , const P& f1 );
template <typename T , typename P> inline TruncatedPolynomial<T> operator/( const TruncatedPolynomial<T>& f0 , const P& f1 );
template <typename T> inline TruncatedPolynomial<T> operator%( const TruncatedPolynomial<T>& f0 , const T& t1 );

// m_Nが1下がることに注意。
template <typename T> inline TruncatedPolynomial<T> Differential( const TruncatedPolynomial<T>& f );
// m_Nがn下がることに注意。
template <typename T> inline TruncatedPolynomial<T> Differential( const uint& n , const TruncatedPolynomial<T>& f );
// m_Nが1下がることに注意。
// N_output_start_plus_one > 0の場合のみサポート。
template <typename T> TruncatedPolynomial<T> TruncatedDifferential( const TruncatedPolynomial<T>& f , const uint& N_output_start_plus_one );

// m_Nが1上がることに注意。
// Tが標数0またはf.m_N + 1以上の体の場合のみサポート。
template <typename T> inline TruncatedPolynomial<T> Integral( const TruncatedPolynomial<T>& f );
// m_Nが1上がることに注意。
// N_output_start > 0の場合のみサポート。
template <typename T>
TruncatedPolynomial<T> TruncatedIntegral( const TruncatedPolynomial<T>& f , const uint& N_output_start );

// f[0]が可逆な場合のみサポート。
template <typename T>
TruncatedPolynomial<T> Inverse( const TruncatedPolynomial<T>& f );

// Tが標数0またはf.m_N以上の体でかつf[0] == 0の場合のみサポート。
template <typename T>
TruncatedPolynomial<T> Exp( const TruncatedPolynomial<T>& f );

// Tが標数0またはf.m_N以上の体でかつf[0] == 1の場合のみサポート。
template <typename T> inline TruncatedPolynomial<T> Log( const TruncatedPolynomial<T>& f );
