// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/Moevius/a.hpp

#pragma once

// O(√n)
template <typename INT> int Moevius( const INT& n ) noexcept;
// sqrt( n )以下の最大の素数 < val_limit（peのテンプレート引数）の時のみサポート。
// O(√n/(log n))
template <typename PE , typename INT> int Moevius( const PE& pe , INT n ) noexcept;
// n < val_limit（ldのテンプレート引数） の時のみサポート。
// O(d(n)) = O(log n / log log n)
template <typename LD , typename INT> int Moevius( const LD& ld , INT n );
