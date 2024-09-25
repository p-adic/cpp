// c:/Users/user/Documents/Programming/Utility/String/Palindrome/a.hpp

#pragma once

// reversed=falseの時はS[0,r]（0<=r<N）が回文か否かをanswer[r]に、
// reversed=trueの時はS[l,N-1]（0<=l<N）が回文か否かをanswer[l]に
// O(N)で格納。（確率的判定）
vector<bool> Palindrome( const string& S , const bool& reversed = false );

// S[l,r]（0<=l<=r+1<=N）が回文か否かをO(N^2)でanswer[r][l]に格納。
// answer[l][r]にするとメモリの無駄遣いとなるので逆であることに注意。
vector<vector<bool>> TotalPalindrome( const string& S );
