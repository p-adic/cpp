// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a.hpp

#pragma once
#include <vector>

template <typename T> class TruncatedPolynomial;

template <typename T>
class Polynomial
{

  friend class TruncatedPolynomial<T>;

protected:
  vector<T> m_f;
  // m_f‚Ìsize
  uint m_size;
  bool m_no_redundant_zero;
  
public:
  inline Polynomial();
  inline Polynomial( const T& t );
  inline Polynomial( const Polynomial<T>& f );
  inline Polynomial( const uint& i , const T& t );
  inline Polynomial( vector<T>&& f );

  Polynomial<T>& operator=( const T& t );
  Polynomial<T>& operator=( const Polynomial<T>& f );

  // ŒW”
  inline const T& operator[]( const uint& i ) const;
  inline T& operator[]( const uint& i );

  // ‘ã“ü
  inline T operator()( const T& t ) const;

  inline Polynomial<T>& operator+=( const T& t );
  Polynomial<T>& operator+=( const Polynomial<T>& f );
  inline Polynomial<T>& operator-=( const T& t );
  Polynomial<T>& operator-=( const Polynomial<T>& f );
  Polynomial<T>& operator*=( const T& t );
  Polynomial<T>& operator*=( const Polynomial<T>& f );
  Polynomial<T>& operator/=( const T& t );
  Polynomial<T>& operator/=( const Polynomial<T>& f );
  Polynomial<T>& operator%=( const T& t );
  Polynomial<T>& operator%=( const Polynomial<T>& f );

  inline Polynomial<T> operator-() const;

  inline const vector<T>& GetCoefficient() const noexcept;
  inline const uint& size() const noexcept;
  
  void RemoveRedundantZero();

  inline string Display() const noexcept;
  
  static inline const Polynomial<T>& zero();
  static inline const T& const_zero();
  static inline const T& const_one();
  static inline const T& const_minus_one();

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
template <typename T , typename P> inline Polynomial<T> operator/( const Polynomial<T>& f0 , const P& f1 );
template <typename T , typename P> inline Polynomial<T> operator%( const Polynomial<T>& f0 , const P& f1 );

// ‘½€®‚Ì—ñ‚Ì‘Šæ‚ğ•ªŠ„“¡‚ÅŒvZ‚µA‚»‚ÌŒ‹‰Ê‚ğ‘æ1¬•ª‚ÉŠi”[‚µ‚ÄQÆ•Ô‚µ‚·‚éB
template <typename T> inline VLArray<Polynomial<T> >& Prod( list<Polynomial<T> >& f );

