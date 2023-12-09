// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/BernulliNumber/a.hpp

#pragma once

// verify:https://judge.yosupo.jp/submission/176740

template <typename T , int length>
class BernulliNumberCalculator
{

private:
  // Bernulli”B_0=1, B_1=1/2, B_2=1/6, ..., B_{length-1}‚ğŠi”[‚·‚éB
  T m_val[length];

public:
  // ŒvZ—ÊO(length log length)‚Å\’z‚·‚éB
  inline BernulliNumberCalculator();
  inline const T& operator[]( const int& i ) const;

};
