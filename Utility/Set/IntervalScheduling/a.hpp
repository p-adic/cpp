// c:/Users/user/Documents/Programming/Utility/Set/IntervalScheduling/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/931520

// 区間追加O(log m_size)
// 区間削除O(log m_size)
// 先頭区間取得O(1)
// 後続区間取得O(log m_size)
// 全後続区間取得O(m_size)
// 最多排他的区間列取得O(m_size)
template <typename T>
class IntervalScheduling
{
  
private:
  int m_count;
  vector<T> m_l;
  vector<T> m_r;
  vector<bool> m_valid;
  set<tuple<T,T,int>> m_rli;
  int m_size;
  T m_l_max;

public:
  inline void insert( const T& l , const T& r );
  inline void erase( const tuple<T,T,int>& v );

  inline const int& count() const noexcept;
  inline const T& GetL( const int& i ) const;
  inline const T& GetR( const int& i ) const;
  // const参照でないことに注意
  inline bool GetValid( const int& i ) const;
  inline const int& size() const noexcept;

  inline const int& Init() const;
  int Next( const int& i ) const;
  void SetNext( vector<int>& a ) const noexcept;
  void SetMaximal( list<int>& a , const int& i = -1 ) const;
  
};
