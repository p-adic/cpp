// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Enumeration/a.hpp

#pragma once
#include "../../Prime/Enumeration/SFINAE/a.hpp"

// verify:
// https://yukicoder.me/submissions/970639（EnumerateDivisor）
// https://yukicoder.me/submissions/1027344（TotalEnumerateDivisor）

// O(√n)
template <typename INT> vector<INT> EnumerateDivisor( INT n ) noexcept;
// PEはPrimeEnumerationなどで、peがsqrt( n )以下の素数を管理する時のみサポート。
// O(√n/log n)
template <typename PE , typename INT> auto EnumerateDivisor( const PE& pe , INT n ) -> enable_if_t<IsPE<PE>,vector<INT>>;
// LDはLeastDivisorなどで、ldがn以下の素数を管理する時のみサポート。
// O(d(n)) = O(log n/log log n)
template <typename LD , typename INT> auto EnumerateDivisor( const LD& ld , INT n ) -> enable_if_t<!IsPE<LD>,vector<INT>>;

// O(size log size)（空間計算量もO(size log size)であることに注意）
template <typename INT> vector<vector<INT>> TotalEnumerateDivisor( const INT& size ) noexcept;
// O(size log size)（空間計算量はO(size)）
// answer[i]に「initに対しiの約数dを昇順にわたらせてf(-,d)を適用したもの」を格納。
template <typename INT , typename FUNC , typename U> vector<U> TotalEnumerateDivisor( const INT& size , FUNC f , const U& init ) noexcept;
