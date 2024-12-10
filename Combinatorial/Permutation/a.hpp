// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Permutation/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/942586i“]“|”j

// 7! à 5~10^3"
// 8! à 4~10^4"
// 9! à 4~10^5"
// 10! à 4~10^6"
// 11! à 4~10^7"
// 12! à 5~10^8"
// 18! à 6~10^15
// 19! à 1~10^17
// 20! à 2~10^18

// ˆê„‚Ì‡ŒvŒvZ—ÊO(N(N!))B
// «‘‡‚ÅŒãÒ‚ª‘¶İ‚µ‚È‚¢ê‡‚Í«‘‡‚ÅÅ¬’l‚É–ß‚é‚±‚Æ‚É’ˆÓB
template <typename INT , int size_max> inline bool NextPermutation( INT ( &P )[size_max] , const int& size );
template <typename INT> inline bool NextPermutation( vector<INT>& P );
// «‘‡‚Å‘OÒ‚ª‘¶İ‚µ‚È‚¢ê‡‚Í«‘‡‚ÅÅ‘å’l‚É–ß‚é‚±‚Æ‚É’ˆÓB
template <typename INT , int size_max> inline bool PreviousPermutation( INT ( &P )[size_max] , const int& size );
template <typename INT> inline bool PreviousPermutation( vector<INT>& P );

// ‡—ñP‚Ì“]“|”ŒvZO(N log N)B
template <typename INT> ll InversionNumber( const vector<INT>& P );
template <typename INT> ll InversionNumber( const vector<INT>& P , const vector<INT>& P_inv , const int& size );

// ‡—ñP‚Ì„‰ñ’uŠ·•\¦O(N)B
template <typename INT> vector<vector<INT>> CyclicPermutationRepresentation( const vector<INT>& P , const bool& zero_indexed = true );

// ‡—ñP‚Ì‹É¬ŒİŠ·•\¦O(N)B
template <typename INT> vector<pair<INT,INT>> MinimalTranspositionRepresentation( const vector<INT>& P , const bool& zero_indexed = true );
