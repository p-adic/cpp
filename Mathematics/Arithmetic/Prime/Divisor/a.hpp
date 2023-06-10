// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/a.hpp

#pragma once
#include "../a.hpp"
#include "../Constexpr/a.hpp"

template <typename INT> list<int> EnumerateDivisor( const INT& n ) noexcept;
// n < val_limitの2乗 の時のみサポート。
template <typename INT , INT val_limit , int length_max> list<int> EnumerateDivisor( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT n ) noexcept;

template <typename INT> int MoeviusFunction( const INT& n ) noexcept;
// n < val_limitの2乗 の時のみサポート。
template <typename INT , INT val_limit , int length_max> int MoeviusFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT n ) noexcept;
