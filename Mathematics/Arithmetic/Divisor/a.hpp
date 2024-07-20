// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/a.hpp

#pragma once
#include "Constexpr/a.hpp"
#include "../Prime/Constexpr/a.hpp"

// verify:
// https://yukicoder.me/submissions/970583（CountDivisor）
// https://yukicoder.me/submissions/970639（EnumerateDivisor）

// O(√n)
template <typename INT> INT CountDivisor( INT n ) noexcept;
// sqrt( n )以下の最大の素数 < val_limit の時のみサポート。
// O(√n/(log n))
template <typename INT , typename PE> INT CountDivisor( const PE& pe , INT n ) noexcept;

// O(√n)
template <typename INT> vector<INT> EnumerateDivisor( INT n ) noexcept;
// sqrt( n )以下の最大の素数 < val_limit（peのテンプレート引数） の時のみサポート。
// O(√n/(log n))
template <typename INT1 , INT1 val_limit , int length_max , typename INT2> vector<INT2> EnumerateDivisor( const PrimeEnumeration<INT1,val_limit,length_max>& pe , INT2 n );
// n < val_limit（ldのテンプレート引数） の時のみサポート。
// O(d(n)) = O(log n / log log n)
template <typename INT1 , INT1 val_limit , typename INT2> vector<INT2> EnumerateDivisor( const LeastDivisor<INT1,val_limit>& ld , INT2 n );

// O(size log size)
template <typename INT> vector<vector<INT>> TotalEnumerateDivisor( const INT& size ) noexcept;
