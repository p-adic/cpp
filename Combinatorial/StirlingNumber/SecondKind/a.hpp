// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/StirlingNumber/SecondKind/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/914264

template <typename T , int length>
class SecondStirlingNumberCalculator
{

private:
  // N元集合の非交叉非空部分集合i個による被覆の個数をm_val[N][i]に格納する。
  T m_val[length][length];

public:
  // （コンパイル時に）計算量O(length^2)で構築する。
  constexpr inline SecondStirlingNumberCalculator();

  constexpr inline const T ( &operator[]( const int& i ) const )[length];

  // 以下N<lengthの場合のみサポート。（i<lengthでなくてもよい）

  // N元集合の非交叉非空部分集合i個による被覆の個数を返す。（O(1)）
  constexpr inline T CountDisjointCover( const int& N , const int& i ) const;
  // N元集合の非交叉非空部分集合i個の個数を返す。（O(1)）
  constexpr inline T CountDisjointSubset( const int& N , const int& i ) const;

  // 以下Tが正整数Mに対するMod<M>と表せる場合のみサポート。

  // N元集合の長さiの非交叉非空部分集合列による被覆の個数を返す。（O(log min{N,i})）
  inline T CountDisjointCoverSequence( const int& N , const int& i ) const;
  // N元集合の長さiの非交叉非空部分集合列の個数を返す。（O(log min{N,i})）
  inline T CountDisjointSubsetSequence( const int& N , const int& i ) const;

  // 以下Mがlength以上の素数である場合のみサポート。

  // N元集合の要素数nの部分集合の非交叉非空部分集合i個による被覆の個数を返す。（O(log N)）
  inline T CountDisjointCover( const int& N , const int& n , const int& i ) const;
  // N元集合の要素数nの部分集合の長さiの非交叉非空部分集合列による被覆の個数を返す。（O(log N)）
  inline T CountDisjointCoverSequence( const int& N , const int& n , const int& i ) const;
  
};

