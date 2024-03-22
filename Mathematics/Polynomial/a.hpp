// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a.hpp

#pragma once
#include <vector>

#include "a_Macro.hpp"

template <typename T> class TruncatedPolynomial;

template <typename T> TruncatedPolynomial<T> Differential( const uint& n , const TruncatedPolynomial<T>& f );
template <typename T> TruncatedPolynomial<T> TruncatedDifferential( const TruncatedPolynomial<T>& f , const uint& N_output_start_plus_one );
template <typename T> TruncatedPolynomial<T> TruncatedIntegral( const TruncatedPolynomial<T>& f , const uint& N_output_start );

template <typename T>
class Polynomial
{

  friend class TruncatedPolynomial<T>;
  friend TruncatedPolynomial<T> Differential<T>( const uint& n , const TruncatedPolynomial<T>& f );
  friend TruncatedPolynomial<T> TruncatedDifferential<T>( const TruncatedPolynomial<T>& f , const uint& N_output_start_plus_one );
  friend TruncatedPolynomial<T> TruncatedIntegral<T>( const TruncatedPolynomial<T>& f , const uint& N_output_start );

protected:
  vector<T> m_f;
  // m_fのsize
  uint m_size;
  
public:
  inline Polynomial();
  inline Polynomial( const Polynomial<T>& f );
  inline Polynomial( Polynomial<T>&& f );
  inline Polynomial( TruncatedPolynomial<T> f );
  inline Polynomial( vector<T> f );
  inline Polynomial( T t );
  template <SFINAE_FOR_POLYNOMIAL( = nullptr )> inline Polynomial( Arg n );
  inline Polynomial( const uint& i , T t );
  template <SFINAE_FOR_POLYNOMIAL( = nullptr )> inline Polynomial( const uint& i , Arg n );

  template <SFINAE_FOR_POLYNOMIAL( = nullptr )> inline Polynomial<T>& operator=( Arg n );
  inline Polynomial<T>& operator=( Polynomial<T> f );
  inline Polynomial<T>& operator=( vector<T> f );

  // 係数を参照。capacity変更時に不正な参照となるのでこの返り値を参照型の引数に渡す時は注意。
  inline const T& operator[]( const uint& i ) const;
  inline T& operator[]( const uint& i );

  // 代入
  inline T operator()( const T& t ) const;

  Polynomial<T>& operator+=( const Polynomial<T>& f );
  Polynomial<T>& operator-=( const Polynomial<T>& f );
  Polynomial<T>& operator*=( const Polynomial<T>& f );
  // 部分特殊化用
  Polynomial<T>& operator*=( Polynomial<T>&& f );
  inline Polynomial<T>& operator/=( const Polynomial<T>& f );
  Polynomial<T>& operator/=( const T& t );
  Polynomial<T>& operator%=( const Polynomial<T>& f );
  Polynomial<T>& operator%=( const T& t );

  bool operator==( const Polynomial<T>& f ) const;
  bool operator==( const T& t ) const;
  template <typename P> inline bool operator!=( const P& f ) const;

  DECLARATION_OF_ARITHMETIC_FOR_POLYNOMIAL( + );
  inline Polynomial<T> operator-() const;
  DECLARATION_OF_ARITHMETIC_FOR_POLYNOMIAL( - );
  DECLARATION_OF_ARITHMETIC_FOR_POLYNOMIAL( * );
  inline Polynomial<T> operator/( const Polynomial<T>& f ) const;
  inline Polynomial<T> operator/( const T& t ) const;
  inline Polynomial<T> operator%( const Polynomial<T>& f ) const;
  inline Polynomial<T> operator%( const T& t ) const;

  inline const vector<T>& GetCoefficient() const noexcept;
  inline const uint& size() const noexcept;
  inline void resize( const uint& deg_plus ) noexcept;

  inline void swap( Polynomial<T>& f );
  inline void swap( vector<T>& f );
  
  void RemoveRedundantZero();

  inline string Display() const noexcept;

  static Polynomial<T> Quotient( const Polynomial<T>& f0 , const Polynomial<T>& f1 );
  static Polynomial<T> Transpose( const Polynomial<T>& f , const uint& f_transpose_size );

  static inline const Polynomial<T>& zero();
  static inline const Polynomial<T>& one();
  static inline const T& c_zero();
  static inline const T& c_one();
  static inline const T& c_minus_one();

private:
  inline Polynomial<T>& SignInvert();

};

template <typename T> Polynomial<T> Differential( const uint& n , const Polynomial<T>& f );

// PowerはCumulative/a_Body.hppで定義。
