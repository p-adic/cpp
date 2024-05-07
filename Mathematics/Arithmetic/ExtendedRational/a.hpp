// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/ExtendedRational/a.hpp

#pragma once

template <typename T>
class ExtendedRational
{

private:
  T m_n;
  T m_d;

public:
  inline constexpr ExtendedRational( const T& n = 0 , const T& d = 1 );
  inline constexpr ExtendedRational( const ExtendedRational<T>& r );
  inline constexpr ExtendedRational( ExtendedRational<T>&& r );

  inline constexpr ExtendedRational<T>& operator=( ExtendedRational<T> r ) noexcept;

  inline constexpr bool operator==( const ExtendedRational<T>& r ) const noexcept;
  inline constexpr bool operator!=( const ExtendedRational<T>& r ) const noexcept;
  inline constexpr bool operator<=( const ExtendedRational<T>& r ) const noexcept;
  inline constexpr bool operator>=( const ExtendedRational<T>& r ) const noexcept;
  inline constexpr bool operator<( const ExtendedRational<T>& r ) const noexcept;
  inline constexpr bool operator>( const ExtendedRational<T>& r ) const noexcept;

  inline constexpr const T& GetNumerator() const noexcept;
  inline constexpr const T& GetDenominator() const noexcept;

};

template <typename T> inline constexpr bool operator==( const T& n , const ExtendedRational<T>& r ) noexcept;
template <typename T> inline constexpr bool operator!=( const T& n , const ExtendedRational<T>& r ) noexcept;
template <typename T> inline constexpr bool operator<=( const T& n , const ExtendedRational<T>& r ) noexcept;
template <typename T> inline constexpr bool operator>=( const T& n , const ExtendedRational<T>& r ) noexcept;
template <typename T> inline constexpr bool operator<( const T& n , const ExtendedRational<T>& r ) noexcept;
template <typename T> inline constexpr bool operator>( const T& n , const ExtendedRational<T>& r ) noexcept;

template <typename T , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , const ExtendedRational<T>& r );
template <typename T , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const ExtendedRational<T>& r );
