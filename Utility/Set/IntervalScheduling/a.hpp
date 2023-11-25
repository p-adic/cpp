// c:/Users/user/Documents/Programming/Utility/Set/IntervalScheduling/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/931520

// ‹æŠÔ’Ç‰ÁO(log m_size)
// ‹æŠÔíœO(log m_size)
// æ“ª‹æŠÔæ“¾O(1)
// Œã‘±‹æŠÔæ“¾O(log m_size)
// ‘SŒã‘±‹æŠÔæ“¾O(m_size)
// Å‘½”r‘¼“I‹æŠÔ—ñæ“¾O(m_size)
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
  // constQÆ‚Å‚È‚¢‚±‚Æ‚É’ˆÓ
  inline bool GetValid( const int& i ) const;
  inline const int& size() const noexcept;

  inline const int& Init() const;
  int Next( const int& i ) const;
  void SetNext( vector<int>& a ) const noexcept;
  void SetMaximal( list<int>& a , const int& i = -1 ) const;
  
};
