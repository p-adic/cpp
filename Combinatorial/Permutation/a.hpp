// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Permutation/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/1030881（InversionNumber）

// 7! ≒ 5×10^3"
// 8! ≒ 4×10^4"
// 9! ≒ 4×10^5"
// 10! ≒ 4×10^6"
// 11! ≒ 4×10^7"
// 12! ≒ 5×10^8"
// 18! ≒ 6×10^15
// 19! ≒ 1×10^17
// 20! ≒ 2×10^18

// 一巡の合計計算量O(N(N!))。
// 辞書順で後者が存在しない場合は辞書順で最小値に戻ることに注意。
template <typename INT , int size_max> inline bool NextPermutation( INT ( &P )[size_max] , const int& size );
template <typename INT> inline bool NextPermutation( vector<INT>& P );
// 辞書順で前者が存在しない場合は辞書順で最大値に戻ることに注意。
template <typename INT , int size_max> inline bool PreviousPermutation( INT ( &P )[size_max] , const int& size );
template <typename INT> inline bool PreviousPermutation( vector<INT>& P );

// 順列とは限らない配列Pの転倒数計算O(N log N)。
template <typename INT> ll InversionNumber( const vector<INT>& P );

// 順列Pの巡回置換表示O(N)。
template <typename INT> vector<vector<INT>> CyclicPermutationRepresentation( const vector<INT>& P , const bool& zero_indexed = true );

// 順列Pの極小互換表示O(N)。
template <typename INT> vector<pair<INT,INT>> MinimalTranspositionRepresentation( const vector<INT>& P , const bool& zero_indexed = true );

// 順列Pの極小基本互換表示O(N^2)。
template <typename INT> vector<pair<INT,INT>> MinimalAdjacentTranspositionRepresentation( vector<INT> P , const bool& zero_indexed = true );

// 順列Pの位数計算O(N)。
template <typename INT> ll PermutationOrder( const vector<INT>& P , const bool& zero_indexed = true );

// 順列Pの極小互換表示の濃度計算O(N)。
template <typename INT> INT LeastSwapCount( const vector<INT>& P , const bool& zero_indexed = true );

// 順列Pの極小基本互換表示の濃度計算O(N log N)。
template <typename INT> inline ll LeastSwapCount( const vector<INT>& P );

// 順列Pの符号計算O(N log N)。
template <typename INT> inline int Signature( const vector<INT>& P );

