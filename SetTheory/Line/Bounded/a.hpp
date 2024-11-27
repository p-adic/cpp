// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/a.hpp

#pragma once
#include "Iterator/a.hpp"

#ifdef DEBUG
  #include "../../DirectProduct/AffineSpace/BIT/Debug/a.hpp"
#else
  #include "../../DirectProduct/AffineSpace/BIT/a.hpp"
#endif

// verify:
// https://yukicoder.me/submissions/1008247 (insert, erase, ConnectedComponentOf)

// 構築O(ubound - lbound)
// 一点挿入O(log (ubound - lbound))
// 一点削除O(log (ubound - lbound))
// 一点帰属判定O(log (ubound - lbound))
// 区間要素数取得O(log (ubound - lbound))

// 先頭イテレータ取得O(log (ubound - lbound))
// 末尾イテレータ取得O(log (ubound - lbound))
// 上限/下限二分探索O(log (ubound - lbound))

// 最大値/最小値取得O(log (ubound - lbound))

// 一点連結成分取得O(log (ubound - lbound))
// 全連結成分取得O(連結成分数 log (ubound - lbound))

template <typename INT , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR>
class VirtualBoundedLineSubset
{

protected:
  INT m_lbound;
  INT m_ubound;
  DATA_STR<INT> m_ds;

public:
  using iterator = IteratorOfBoundedLineSubset<VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN,DATA_STR>,INT>;
  
  inline void insert( const INT& i );
  inline void erase( const INT& i ) noexcept;
  // itrをインクリメントして書き換え、それへの参照を返す。
  inline iterator& erase( iterator& itr );
  inline void clear();

  inline INT count( const INT& i ) noexcept;
  bool find( const INT& i ) noexcept;

  inline INT InitialSegmentCount( const INT& i_final );
  inline INT IntervalCount( const INT& i_start , const INT& i_final );
  inline bool empty() noexcept;

  inline iterator begin() noexcept;
  inline iterator end() noexcept;

  inline iterator MaximumLeq( const INT& i , const INT& k = 0 );
  inline iterator MaximumLt( const INT& i , const INT& k = 0 );
  inline iterator MinimumGeq( const INT& i , const INT& k = 0 );
  inline iterator MinimumGt( const INT& i , const INT& k = 0 );

  inline INT Maximum( const INT& k = 0 );
  inline INT Minimum( const INT& k = 0 );

  // iを含む連結成分の右端を返す。存在しない場合はi-1を返す。
  INT RightEndPointOf( const INT& i , int d = -1 , int comp_minus = -1 , const bool& in = false );
  // iを含む連結成分の左端を返す。存在しない場合はi+1を返す。
  INT LeftEndPointOf( const INT& i , int d = -1 , int comp_minus = -1 , const bool& in = false );

  // iを含む連結成分を返す。存在しない場合は[1+1,i-1]を返す。
  inline pair<INT,INT> ConnectedComponentOf( const INT& i , bool in = false );

  vector<pair<INT,INT>> GetConnectedComponent() noexcept;

  inline const INT& lbound() const noexcept;
  inline const INT& ubound() const noexcept;

protected:
  virtual bool InRange( const INT& i ) = 0;
  virtual RET_NOR Normalise( const INT& i ) = 0;
  virtual RET_DEN Denormalise( const decay_t<RET_NOR>& d ) = 0;

};

template <typename INT , template <typename...> typename DATA_STR>
class AbstractBoundedLineSubset :
  virtual public VirtualBoundedLineSubset<INT,INT,INT,DATA_STR>
{

public:
  inline AbstractBoundedLineSubset( const INT& lbound , const INT& ubound );

protected:
  inline bool InRange( const INT& i );
  inline INT Normalise( const INT& i );
  inline INT Denormalise( const INT& d );

};

#include "a_Alias.hpp"

