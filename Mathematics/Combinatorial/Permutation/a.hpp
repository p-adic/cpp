// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Permutation/a.hpp

#pragma once

// 一巡の合計計算量O(N!)。
// 辞書順で後者が存在しない場合は辞書順で最小値に戻ることに注意。
template <typename INT , int size_max> inline bool NextPermutation( INT ( &P )[size_max] , const int& size );
template <typename INT> inline bool NextPermutation( vector<INT>& P );
// 辞書順で前者が存在しない場合は辞書順で最大値に戻ることに注意。
template <typename INT , int size_max> inline bool PreviousPermutation( INT ( &P )[size_max] , const int& size );
template <typename INT> inline bool PreviousPermutation( vector<INT>& P );

// Pは0,...,size-1の順列
template <int size_max> long long InversionNumber( const int ( &P )[size_max] const int& size );
