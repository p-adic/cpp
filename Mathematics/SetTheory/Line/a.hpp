// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1002400

// 構築O(1)
// 一点挿入O(log Q)
// 一点削除O(log Q)
// 一点帰属判定O(log Q)
// 一点連結成分取得O(log Q)

template <typename INT>
class LineSubset
{

private:
  // 区間[l,r]ごとにm_l[r] = lとして直線の部分集合を管理する。
  map<INT,INT> m_l;

public:
  void insert( const INT& i ) noexcept;
  void erase( const INT& i ) noexcept;

  inline int count( const INT& i ) const noexcept;
  bool find( const INT& i ) const noexcept;

  // iを含む連結成分を返す。存在しない場合は[1+1,i-1]を返す。
  pair<INT,INT> ConnectedComponentOf( const INT& i ) const noexcept;

  inline const map<INT,INT>& GetConnectedComponent() const noexcept;
  
};
