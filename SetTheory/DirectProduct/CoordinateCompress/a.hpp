// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/996898（ll、R）
// https://yukicoder.me/submissions/994770（ll、L）
// https://yukicoder.me/submissions/972421（tuple<int,int,int>、R）

// Set回数をQ、Setされた項の種類数をNと置く。

// 右辺値登録O(log N)
// 右辺値圧縮結果取得O(N)
// 右辺値圧縮結果使用O(1)（expected）
// 合計O(Q log N)（expected）

// 左辺値登録O(1)
// 左辺値圧縮O(Q log Q)
// 合計O(Q log Q)

// 上界の評価は右辺値圧縮の方が小さいが、NがQに近い時は左辺値圧縮の方が軽い。
template <typename INT = ll>
class CoordinateCompress
{

private:
  set<INT> m_r;
  vector<INT*> m_l;

public:
  inline CoordinateCompress();

  inline void SetR( INT t );
  template <typename U , template <typename...> typename V > inline void SetR( V<U> a );
  pair<vector<INT>,unordered_map<INT,int>> GetR();
  // 右辺値の圧縮データを返す。
  inline void clearR();

  inline void SetL( INT& t );
  template <typename U , template <typename...> typename V > inline void SetL( V<U>& a );
  // 左辺値を圧縮してソート済みの配列を返す。
  vector<INT> GetL();
  inline void clearL();

};
