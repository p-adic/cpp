// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/ExtendedRational/a_Macro.hpp

#pragma once

#define DECLARATION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( OPR )		\
  inline constexpr ExtendedRational<T>& operator OPR ## =( const ExtendedRational<T>& r ) noexcept; \
  inline constexpr ExtendedRational<T> operator OPR( const ExtendedRational<T>& r ) const noexcept \

#define DEFINITION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( OPR )	\
  template <typename T> inline constexpr ExtendedRational<T>& ExtendedRational<T>::operator OPR ## =( const ExtendedRational<T>& r ) noexcept { return *this = *this + r; }

#define DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( OPR )	\
  template <typename T , typename ARG> inline constexpr ExtendedRational<T> operator OPR( const ARG& t , const ExtendedRational<T>& r ) noexcept


