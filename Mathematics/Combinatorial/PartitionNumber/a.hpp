// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/PartitionNumber/a.hpp

#pragma once

// n以下の非負整数iを正整数の昇順和に分割する方法を第i成分に格納する。（O(n^2)）
vector<int> PartitionNumber( const int& n );
// n以下の非負整数iを非負整数l個の昇順和に分割する方法を第i成分に格納する。（O(ln^2)）
vector<int> NonNegativePartitionNumber( const int& n , const int& l );
