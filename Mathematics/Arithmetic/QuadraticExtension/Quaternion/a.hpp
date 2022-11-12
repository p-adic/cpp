// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/QuadraticExtension/Quaternion/a.hpp

#pragma once

template <typename INT>
class Quaternion
{

private:
  // 1
  INT m_a;
  // i
  INT m_b;
  // j
  INT m_c;
  // k
  INT m_d;
  
public:
  inline Quaternion() noexcept;
  template <typename T> inline Quaternion( const T& a ) noexcept;
  inline Quaternion( const INT& a , const INT& b , const INT& c , const INT& d ) noexcept;
  inline Quaternion( const Quaternion<INT>& n ) noexcept;

  inline const INT& GetA() const noexcept;
  inline const INT& GetB() const noexcept;
  inline const INT& GetC() const noexcept;
  inline const INT& GetD() const noexcept;

  inline Quaternion<INT>& operator+=( const Quaternion<INT>& n ) noexcept;
  template <typename T> inline Quaternion<INT>& operator+=( const T& a ) noexcept;
  inline Quaternion<INT>& operator-=( const Quaternion<INT>& n ) noexcept;
  template <typename T> inline Quaternion<INT>& operator-=( const T& a ) noexcept;

  inline Quaternion<INT>& operator*=( const Quaternion<INT>& n ) noexcept;
  template <typename T> inline Quaternion<INT>& operator*=( const T& a ) noexcept;
  template <typename T> inline Quaternion<INT>& operator/=( const T& a ) noexcept;
  template <typename T> inline Quaternion<INT>& operator%=( const T& a ) noexcept;

  static inline bool Equal( const Quaternion<INT>& n0 , const Quaternion<INT>& n1 ) noexcept;
  
};

template <typename INT> inline bool operator==( const Quaternion<INT>& n0 , const Quaternion<INT>& n1 ) noexcept;
template <typename INT> inline bool operator!=( const Quaternion<INT>& n0 , const Quaternion<INT>& n1 ) noexcept;

template <typename INT , typename T> inline Quaternion<INT> operator+( const Quaternion<INT>& n , const T& a ) noexcept;
template <typename INT , typename T> inline Quaternion<INT> operator-( const Quaternion<INT>& n , const T& a ) noexcept;
template <typename INT , typename T> inline Quaternion<INT> operator*( const Quaternion<INT>& n , const T& a ) noexcept;
template <typename INT , typename T> inline Quaternion<INT> operator/( const Quaternion<INT>& n , const T& a ) noexcept;
template <typename INT , typename T> inline Quaternion<INT> operator%( const Quaternion<INT>& n , const T& a ) noexcept;
