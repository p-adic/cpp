// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Debug/a.hpp

#pragma once
#include "../Iterator/a.hpp"
#include "../../../DirectProduct/AffineSpace/BIT/Debug/a.hpp"

// デバッグ用にデバッグ出力とsetを追加したもの。
// 各処理の計算量がO(size)増えることに注意。

template <typename INT , typename RET_NOR , typename RET_DEN>
class VirtualBoundedLineSubset :
  public Debug
{

protected:
  INT m_lbound;
  INT m_ubound;
  BIT<INT> m_ds;

  string m_name;
  set<INT> m_S;

public:
  inline VirtualBoundedLineSubset();
  
  using iterator = IteratorOfBoundedLineSubset<VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>,INT>;
  
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

  void Display() noexcept;

private:
  virtual bool InRange( const INT& i ) = 0;
  virtual RET_NOR Normalise( const INT& i ) = 0;
  virtual RET_DEN Denormalise( const decay_t<RET_NOR>& d ) = 0;

};

template <typename INT>
class BoundedLineSubset :
  virtual public VirtualBoundedLineSubset<INT,INT,INT>
{

public:
  inline BoundedLineSubset( const INT& lbound , const INT& ubound , const bool& output_mode = true );

private:
  inline bool InRange( const INT& i );
  inline INT Normalise( const INT& i );
  inline INT Denormalise( const INT& d );

};
