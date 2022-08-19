// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a.hpp

#pragma once
#include "../SetTheory/DirectProduct/AffineSpace/a.hpp"
#include <vector>

#include "a_Alias.hpp"

template <typename T , uint D> class Polynomial;

template <typename T>
class Polynomial<T,0>
{
  
private:
  T m_t;
  
public:
  using index = PolynomialIndex<0>;

  inline Polynomial();
  inline Polynomial( const T& c );
  inline Polynomial( const Polynomial<T,0>& t );
  inline Polynomial( const index& I );
  inline Polynomial( const index& I , const T& t );

  Polynomial<T,0>& operator=( const T& t );
  Polynomial<T,0>& operator=( const Polynomial<T,0>& t );
  
  template <uint E> inline const T& operator()( const PolynomialIndex<E>& I ) const;
  template <uint E> inline T& operator()( const PolynomialIndex<E>& I );
  inline const T& operator[]( const uint& i ) const;
  // i == 0の場合しかサポートしない
  inline T& operator[]( const uint& i );

  inline Polynomial<T,0>& operator+=( const T& t );
  inline Polynomial<T,0>& operator+=( const Polynomial<T,0>& t );
  inline Polynomial<T,0>& operator-=( const T& t );
  inline Polynomial<T,0>& operator-=( const Polynomial<T,0>& t );
  inline Polynomial<T,0>& operator*=( const T& t );
  inline Polynomial<T,0>& operator*=( const Polynomial<T,0>& t );
  inline Polynomial<T,0>& operator/=( const T& t );
  inline Polynomial<T,0>& operator/=( const Polynomial<T,0>& t );
  inline Polynomial<T,0>& operator%=( const T& t );
  inline Polynomial<T,0>& operator%=( const Polynomial<T,0>& t );
  
  inline const uint& size() const noexcept;
  
  inline void RemoveRedundantZero() const noexcept;
  inline void RecursivelyRemoveRedundantZero() const noexcept;

  inline string Display() const noexcept;

  static const Polynomial<T,0>& zero();
  static const T& const_zero();
  static const T& const_one();
  
};

template <typename T , uint D>
class Polynomial
{

private:
  vector<Polynomial<T,D-1> > m_f;
  uint m_size;
  bool m_no_redundant_zero;
    
public:
  using index = PolynomialIndex<D>;

  inline Polynomial();
  inline Polynomial( const T& t );
  // E <= Dの場合のみサポート
  template <uint E> inline Polynomial( const Polynomial<T,E>& f );
  inline Polynomial( const Polynomial<T,D>& f );
  inline Polynomial( const index& I , const T& t = Polynomial<T,0>::const_one() );

  Polynomial<T,D>& operator=( const T& t );
    // E <= Dの場合のみサポート
  template <uint E> Polynomial<T,D>& operator=( const Polynomial<T,E>& f );
  Polynomial<T,D>& operator=( const Polynomial<T,D>& f );

  template <uint E> const T& operator()( const PolynomialIndex<E>& I ) const;
  template <uint E> T& operator()( const PolynomialIndex<E>& I );
  inline const Polynomial<T,D-1>& operator[]( const uint& i ) const;
  inline Polynomial<T,D-1>& operator[]( const uint& i );

  // E <= Dの場合のみサポート
  inline Polynomial<T,D>& operator+=( const T& t );
  template <uint E> inline Polynomial<T,D>& operator+=( const Polynomial<T,E>& f );
  Polynomial<T,D>& operator+=( const Polynomial<T,D>& f );
  inline Polynomial<T,D>& operator-=( const T& t );
  template <uint E> inline Polynomial<T,D>& operator-=( const Polynomial<T,E>& f );
  Polynomial<T,D>& operator-=( const Polynomial<T,D>& f );
  Polynomial<T,D>& operator*=( const T& t );
  template <uint E> inline Polynomial<T,D>& operator*=( const Polynomial<T,E>& f );
  Polynomial<T,D>& operator*=( const Polynomial<T,D>& f );
  Polynomial<T,D>& operator/=( const T& t );
  Polynomial<T,D>& operator%=( const T& t );

  inline const uint& size() const noexcept;
    
  void RemoveRedundantZero();
  void RecursivelyRemoveRedundantZero();

  string Display() const noexcept;

  static inline const Polynomial<T,D>& zero();

};

template <typename T> inline bool operator==( const Polynomial<T,0>& f0 , const T& t1 );
template <typename T> inline bool operator==( const Polynomial<T,0>& f0 , const Polynomial<T,0>& f1 );
template <typename T , uint D>
bool operator==( const Polynomial<T,D>& f0 , const T& t1 );
// E <= Dの場合のみサポート
template <typename T , uint D , uint E>
bool operator==( const Polynomial<T,D>& f0 , const Polynomial<T,E>& f1 );
template <typename T , uint D>
bool operator==( const Polynomial<T,D>& f0 , const Polynomial<T,D>& f1 );
template <typename T , uint D , typename P> inline bool operator!=( const Polynomial<T,D>& f0 , const P& f1 );


template <typename T , uint D , typename P> inline Polynomial<T,D> operator+( const Polynomial<T,D>& f0 , const P& f1 );
template <typename T , uint D , typename P> inline Polynomial<T,D> operator-( const Polynomial<T,D>& f0 , const P& f1 );
template <typename T , uint D , typename P> inline Polynomial<T,D> operator*( const Polynomial<T,D>& f0 , const P& f1 );
template <typename T , uint D> inline Polynomial<T,D> operator/( const Polynomial<T,D>& f0 , const T& t1 );
template <typename T , uint D> inline Polynomial<T,D> operator%( const Polynomial<T,D>& f0 , const T& t1 );
