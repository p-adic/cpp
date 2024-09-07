// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Debug/a.hpp

#pragma once
#include "../Iterator/a.hpp"
#include "../../../DirectProduct/AffineSpace/BIT/Debug/a.hpp"

// デバッグ用にデバッグ出力とsetを追加したもの。
// 各処理の計算量がO(size)増えることに注意。

template <typename INT , template <typename...> typename DATA_STR>
class AbstractBoundedLineSubset :
  public Debug
{

protected:
  INT m_lbound;
  INT m_ubound;
  DATA_STR<INT> m_ds;

  set<INT> m_S;

public:
  inline AbstractBoundedLineSubset( const INT& lbound , const INT& ubound , const bool& output_mode = true );
  
  using iterator = IteratorOfBoundedLineSubset<INT,DATA_STR>;
  
  inline void insert( const INT& i );
  inline void erase( const INT& i );
  // itrをインクリメントして書き換え、それへの参照を返す。
  inline iterator& erase( iterator& itr );

  inline int count( const INT& i ) noexcept;
  bool find( const INT& i ) noexcept;

  inline int InitialSegmentCount( const INT& i_final ) noexcept;
  inline int IntervalCount( const INT& i_start , const INT& i_final ) noexcept;
  inline bool empty() noexcept;

  inline iterator begin() noexcept;
  inline iterator end() noexcept;

  inline iterator MaximumLeq( const INT& i , const int& k = 0 ) noexcept;
  inline iterator MaximumLt( const INT& i , const int& k = 0 ) noexcept;
  inline iterator MinimumGeq( const INT& i , const int& k = 0 ) noexcept;
  inline iterator MinimumGt( const INT& i , const int& k = 0 ) noexcept;

  inline INT Maximum( const int& k = 0 );
  inline INT Minimum( const int& k = 0 );

  // iを含む連結成分の右端を返す。存在しない場合はi-1を返す。
  INT RightEndPointOf( const INT& i , const bool& in = false ) noexcept;
  // iを含む連結成分の左端を返す。存在しない場合はi+1を返す。
  INT LeftEndPointOf( const INT& i , const bool& in = false ) noexcept;

  // iを含む連結成分を返す。存在しない場合は[1+1,i-1]を返す。
  inline pair<INT,INT> ConnectedComponentOf( const INT& i , bool in = false ) noexcept;

  vector<pair<INT,INT>> GetConnectedComponent() noexcept;

  inline const INT& lbound() const noexcept;
  inline const INT& ubound() const noexcept;

  void Display() noexcept;

};

#include "../a_Alias.hpp"
