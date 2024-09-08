// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Debug/a.hpp

#pragma once
#include "../Iterator/a.hpp"

// デバッグ用にデバッグ出力とsetそのものを追加したもの。
// 各計算量にO(m_size)が加わることに注意。

template <typename INT>
class LineSubset
{

private:
  // 区間[l,r]ごとにm_l[r] = lとして直線の部分集合を管理する。
  map<INT,INT> m_l;
  int m_size;

  set<INT> m_set;

public:
  inline LineSubset();
  
  using iterator = IteratorOfLineSubset<INT>;
  
  void insert( const INT& i ) noexcept;
  void erase( const INT& i ) noexcept;
  // itrをインクリメントして書き換え、それへの参照を返す。
  inline iterator& erase( iterator& itr );

  inline int count( const INT& i ) const noexcept;
  bool find( const INT& i ) const noexcept;

  inline const int& size() const noexcept;
  inline bool empty() const noexcept;

  inline iterator begin() const noexcept;
  inline iterator end() const noexcept;

  inline iterator MaximumLeq( const INT& i ) const noexcept;
  inline iterator MaximumLt( const INT& i ) const noexcept;
  inline iterator MinimumGeq( const INT& i ) const noexcept;
  inline iterator MinimumGt( const INT& i ) const noexcept;

  inline INT Maximum() const;
  inline INT Minimum() const;

  // iを含む連結成分を返す。存在しない場合は[1+1,i-1]を返す。
  pair<INT,INT> ConnectedComponentOf( const INT& i ) const noexcept;

  inline const map<INT,INT>& GetConnectedComponent() const noexcept;

  inline void Display() const noexcept;
  
};
