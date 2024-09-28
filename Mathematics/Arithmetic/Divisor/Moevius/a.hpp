// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Moevius/a.hpp

#pragma once
#include "../../Prime/Enumeration/SFINAE/a.hpp"

// O(√n)
template <typename INT> int MoeviusFunction( const INT& n ) noexcept;
// PEはPrimeEnumerationrなどで、peがsqrt( n )以下の素数を管理する時のみサポート。
// O(√n/(log n))
template <typename PE , typename INT> auto MoeviusFunction( const PE& pe , INT n ) noexcept -> enable_if_t<IsPE<PE>,int>;
// LDはLeastDivisorなどで、ldがn以下の正整数の最小の約数を管理する時のみサポート。
// O(d(n)) = O(log n / log log n)
template <typename LD , typename INT> auto MoeviusFunction( const LD& ld , INT n ) -> enable_if_t<!IsPE<LD>,int>;

// LDはLeastDivisorなどで、ldがn_max以下の正整数の最小の約数を管理する時のみサポート。
// O(n_max)
template <typename LD , typename INT> vector<INT> TotalMoeviusFunction( const LD& ld , const INT& n_max );

