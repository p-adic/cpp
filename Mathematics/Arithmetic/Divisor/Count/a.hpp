// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Count/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/970583（CountDivisor）

// O(√n)
template <typename INT> INT CountDivisor( INT n ) noexcept;
// PEはPrimeEnumeration/LeastDivisorなどで、
// peがsqrt( n )以下の素数/n以下の正整数の約数を管理する時のみサポート。
// O(√n/log n)/O(log n)
template <typename PE , typename INT> INT CountDivisor( const PE& pe , INT n ) noexcept;
