// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../Constexpr/a.hpp"



// O(√n)
template <typename INT> INT CountDivisor( const INT& n ) noexcept;
// sqrt( n )以下の最大の素数 < val_limit の時のみサポート。
// O(√n/(log n))
template <typename INT , INT val_limit , int length_max> INT CountDivisor( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT n ) noexcept;

// O(√n)
template <typename INT> list<int> EnumerateDivisor( const INT& n ) noexcept;
// sqrt( n )以下の最大の素数 < val_limit の時のみサポート。
// O(√n/(log n))
template <typename INT , INT val_limit , int length_max> list<INT> EnumerateDivisor( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT n ) noexcept;

// O(size_max log size_max)
template <int size_max> void MemoriseEnumerateDivisor( list<int> ( &memory )[size_max] ) noexcept;

// O(√n)
template <typename INT> int MoeviusFunction( const INT& n ) noexcept;
// sqrt( n )以下の最大の素数 < val_limit の時のみサポート。
// O(√n/(log n))
template <typename INT , INT val_limit , int length_max> int MoeviusFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT n ) noexcept;
