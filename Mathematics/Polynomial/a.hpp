// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a.hpp

#pragma once
#include <vector>

#include "a_Macro.hpp"

template <typename T> class TruncatedPolynomial;

template <typename T>
class Polynomial
{

  friend class TruncatedPolynomial<T>;

protected:
  vector<T> m_f;
  // m_fのsize
  uint m_size;
  
public:
  inline Polynomial();
  inline Polynomial( const T& t );
  inline Polynomial( const Polynomial<T>& f );
  inline Polynomial( Polynomial<T>&& f );
  inline Polynomial( const uint& i , const T& t );
  inline Polynomial( vector<T>&& f );

  Polynomial<T>& operator=( const T& t );
  Polynomial<T>& operator=( const Polynomial<T>& f );
  Polynomial<T>& operator=( Polynomial<T>&& f );

  // 係数
  inline const T& operator[]( const uint& i ) const;
  inline T& operator[]( const uint& i );

  // 代入
  inline T operator()( const T& t ) const;

  inline Polynomial<T>& operator+=( const T& t );
  Polynomial<T>& operator+=( const Polynomial<T>& f );
  inline Polynomial<T>& operator-=( const T& t );
  Polynomial<T>& operator-=( const Polynomial<T>& f );
  Polynomial<T>& operator*=( const T& t );
  Polynomial<T>& operator*=( const Polynomial<T>& f );
  Polynomial<T>& operator/=( const T& t );
  inline Polynomial<T>& operator/=( const Polynomial<T>& f );
  Polynomial<T>& operator%=( const T& t );
  Polynomial<T>& operator%=( const Polynomial<T>& f );

  inline Polynomial<T> operator-() const;

  // XをX+tにshift
  // Tにおいてm_size未満の正整数が可逆である時のみサポート
  Polynomial<T>& operator<<=( const T& t );

  inline const vector<T>& GetCoefficient() const noexcept;
  inline const uint& size() const noexcept;

  inline void swap( Polynomial<T>& f );
  inline void swap( vector<T>& f );
  
  void RemoveRedundantZero();

  inline string Display() const noexcept;

  static Polynomial<T> Quotient( const Polynomial<T>& f0 , const Polynomial<T>& f1 );
  static Polynomial<T> TransposeQuotient( const Polynomial<T>& f0 , const uint& f0_transpose_size , const Polynomial<T>& f1_transpose_inverse , const uint& f1_size );
  static Polynomial<T> Transpose( const Polynomial<T>& f , const uint& f_transpose_size );

  static inline const Polynomial<T>& zero();
  static inline const T& const_zero();
  static inline const T& const_one();
  static inline const T& const_minus_one();
  static inline const T& factorial( const uint& i );
  static inline const T& factorial_inverse( const uint& i );

};

template <typename T>
bool operator==( const Polynomial<T>& f0 , const T& t1 );
template <typename T>
bool operator==( const Polynomial<T>& f0 , const Polynomial<T>& f1 );
template <typename T , typename P> inline bool operator!=( const Polynomial<T>& f0 , const P& f1 );

template <typename T , typename P> inline Polynomial<T> operator+( const Polynomial<T>& f0 , const P& f1 );
template <typename T , typename P> inline Polynomial<T> operator-( const Polynomial<T>& f );
template <typename T , typename P> inline Polynomial<T> operator-( const Polynomial<T>& f0 , const P& f1 );
template <typename T , typename P> inline Polynomial<T> operator*( const Polynomial<T>& f0 , const P& f1 );
template <typename T> inline Polynomial<T> operator/( const Polynomial<T>& f0 , const T& t1 );
template <typename T> inline Polynomial<T> operator/( const Polynomial<T>& f0 , const Polynomial<T>& f1 );
template <typename T , typename P> inline Polynomial<T> operator%( const Polynomial<T>& f0 , const P& f1 );
template <typename T> inline Polynomial<T> operator<<( const Polynomial<T>& f , const T& t );

// 多項式などの列の総乗を分割統治で計算し、その結果を第1成分に格納して参照返しする。
// V<T>はeraseを持つ必要がある。
template <typename T , template <typename> typename V>
T& Prod( V<T>& f )
