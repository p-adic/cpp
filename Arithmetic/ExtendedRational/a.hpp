// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/ExtendedRational/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../Utility/Set/a.hpp"

// verify:
// https://yukicoder.me/submissions/985340ÅiT=llÅj

// TÇÕ
// (1) äeéÌî‰ärââéZéqÇ∆éZèpââéZéq
// (2) intÇ©ÇÁTÇ÷ÇÃå^ïœä∑
// (3) GCD(const T&,const T&)
// Ç™íËã`Ç≥ÇÍÇƒÇ¢ÇÈå^ÅB
template <typename T>
class ExtendedRational
{

private:
  T m_n;
  T m_d;

public:
  inline constexpr ExtendedRational( const T& n = 0 , const T& d = 1 , const bool& reduced = false );
  inline constexpr ExtendedRational( const ExtendedRational<T>& r );
  inline constexpr ExtendedRational( ExtendedRational<T>&& r );

  inline constexpr ExtendedRational<T>& operator=( ExtendedRational<T> r ) noexcept;

  inline constexpr bool operator==( const ExtendedRational<T>& r ) const noexcept;
  inline constexpr bool operator!=( const ExtendedRational<T>& r ) const noexcept;
  inline constexpr bool operator<=( const ExtendedRational<T>& r ) const noexcept;
  inline constexpr bool operator>=( const ExtendedRational<T>& r ) const noexcept;
  inline constexpr bool operator<( const ExtendedRational<T>& r ) const noexcept;
  inline constexpr bool operator>( const ExtendedRational<T>& r ) const noexcept;

  DECLARATION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( + );
  DECLARATION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( - );
  inline constexpr ExtendedRational<T> operator-() const noexcept;
  DECLARATION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( * );
  inline constexpr ExtendedRational<T> Inverse() const noexcept;
  DECLARATION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( / );

  inline constexpr const T& GetNumerator() const noexcept;
  inline constexpr const T& GetDenominator() const noexcept;

};

template <typename T> inline constexpr bool operator==( const T& n , const ExtendedRational<T>& r ) noexcept;
template <typename T> inline constexpr bool operator!=( const T& n , const ExtendedRational<T>& r ) noexcept;
template <typename T> inline constexpr bool operator<=( const T& n , const ExtendedRational<T>& r ) noexcept;
template <typename T> inline constexpr bool operator>=( const T& n , const ExtendedRational<T>& r ) noexcept;
template <typename T> inline constexpr bool operator<( const T& n , const ExtendedRational<T>& r ) noexcept;
template <typename T> inline constexpr bool operator>( const T& n , const ExtendedRational<T>& r ) noexcept;

DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( + );
DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( - );
DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( * );
DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( / );

template <typename T , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , const ExtendedRational<T>& r );
template <typename T , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const ExtendedRational<T>& r );


template <typename T> DECLARATION_OF_HASH( ExtendedRational<T> );

