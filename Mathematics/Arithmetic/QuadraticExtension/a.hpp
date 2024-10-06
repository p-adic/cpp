// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/QuadraticExtension/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1015838 (INT = Mod<998244353>, D = 5)

#include "Constant/a.hpp"

template <typename INT , int NUM>
class QuadraticExtensions
{

private:
  INT m_a;
  INT m_b;
  
public:
  inline QuadraticExtensions() noexcept;
  inline QuadraticExtensions( const INT& a ) noexcept;
  inline QuadraticExtensions( const INT& a , const INT& b ) noexcept;
  inline QuadraticExtensions( const QuadraticExtensions<INT,NUM>& n ) noexcept;
  inline QuadraticExtensions( QuadraticExtensions<INT,NUM>&& n ) noexcept;

  inline QuadraticExtensions<INT,NUM>& operator=( QuadraticExtensions<INT,NUM> n ) noexcept;
  
  inline pair<const INT&,const INT&> Get() const noexcept;

  inline QuadraticExtensions<INT,NUM>& operator+=( const QuadraticExtensions<INT,NUM>& n ) noexcept;
  template <typename T> inline auto operator+=( const T& a ) noexcept -> enable_if_t<is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&>;
  template <typename T> inline auto operator+=( const T& n ) noexcept -> enable_if_t<!is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&>;

  inline QuadraticExtensions<INT,NUM>& operator-=( const QuadraticExtensions<INT,NUM>& n ) noexcept;
  template <typename T> inline auto operator-=( const T& a ) noexcept -> enable_if_t<is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&>;
  template <typename T> inline auto operator-=( const T& n ) noexcept -> enable_if_t<!is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&>;

  // 3数の乗法が入るのでオーバーフローに注意
  // 10^6より大きいmodで計算する時はINTにMod<M>などを代入するか乗法の定義を修正する
  inline QuadraticExtensions<INT,NUM>& operator*=( const QuadraticExtensions<INT,NUM>& n ) noexcept;
  template <typename T> inline auto operator*=( const T& a ) noexcept -> enable_if_t<is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&>;
  template <typename T> inline auto operator*=( const T& n ) noexcept -> enable_if_t<!is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&>;

  inline QuadraticExtensions<INT,NUM>& operator/=( QuadraticExtensions<INT,NUM> n ) noexcept;
  template <typename T> inline auto operator/=( const T& a ) noexcept -> enable_if_t<is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&>;
  template <typename T> inline auto operator/=( const T& n ) noexcept -> enable_if_t<!is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&>;

  template <typename T> inline auto operator%=( const T& a ) noexcept -> enable_if_t<is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&>;
  
  inline bool operator==( const QuadraticExtensions<INT,NUM>& n ) noexcept;
  template <typename T> inline bool operator==( const T& n ) noexcept;
  template <typename T> inline bool operator!=( const T& n ) noexcept;

  // exponent>=0である場合にのみサポート。exponent乗する。
  template <typename SINT> inline QuadraticExtensions<INT,NUM> operator^( SINT exponent ) const;

  inline QuadraticExtensions<INT,NUM> operator-() const noexcept;
  inline INT Norm() const noexcept;
  inline QuadraticExtensions<INT,NUM> Adjoint() const noexcept;
  // exponent>=0である場合にのみサポート。exponent乗する。
  template <typename SINT> inline QuadraticExtensions<INT,NUM>& Power( SINT exponent );
  // グローバルスコープでswapを定義するためのもの。
  inline void swap( QuadraticExtensions<INT,NUM>& n ) noexcept;
  
  static inline const QuadraticExtensions<INT,NUM>& zero() noexcept;
  static inline const QuadraticExtensions<INT,NUM>& one() noexcept;

  static inline const INT& GetD() noexcept;
  static inline void SetD( const INT& M ) noexcept;  

private:
  template <typename UINT> inline QuadraticExtensions<INT,NUM>& PositivePower( UINT exponent ) noexcept;
  template <typename UINT> inline QuadraticExtensions<INT,NUM>& NonNegativePower( UINT exponent ) noexcept;

  using Constants = ConstantsForQuadraticExtensions<INT,NUM>;
  
};

#include "a_Alias.hpp"

template <typename INT , int NUM , typename T> inline QuadraticExtensions<INT,NUM> operator+( QuadraticExtensions<INT,NUM> n , const T& a ) noexcept;
template <typename INT , int NUM , typename T> inline QuadraticExtensions<INT,NUM> operator-( QuadraticExtensions<INT,NUM> n , const T& a ) noexcept;
template <typename INT , int NUM , typename T> inline QuadraticExtensions<INT,NUM> operator*( QuadraticExtensions<INT,NUM> n , const T& a ) noexcept;
template <typename INT , int NUM , typename T> inline QuadraticExtensions<INT,NUM> operator/( QuadraticExtensions<INT,NUM> n , const T& a ) noexcept;
template <typename INT , int NUM , typename T> inline QuadraticExtensions<INT,NUM> operator%( QuadraticExtensions<INT,NUM> n , const T& a ) noexcept;

template <typename INT , int NUM , typename SINT> inline QuadraticExtensions<INT,NUM> Power( QuadraticExtensions<INT,NUM> n , SINT exponent );

