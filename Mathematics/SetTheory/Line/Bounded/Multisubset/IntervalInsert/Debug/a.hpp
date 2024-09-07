// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/IntervalInsert/Debug/a.hpp

#pragma once
#include "../../../Iterator/a.hpp"

#include "../../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a.hpp"

// デバッグ用にデバッグ出力とmultisetを追加したもの。
// 各処理の計算量がO(size)増えることに注意。

template <typename INT , template <typename...> typename DATA_STR>
class AbstractIntervalInsertBoundedLineMultiSubset
{

protected:
  INT m_lbound;
  INT m_ubound;
  DATA_STR<INT> m_ds;

  multiset<INT> m_S;
  multiset<INT> m_S_comp;

public:
  inline AbstractIntervalInsertBoundedLineMultiSubset( const INT& lbound , const INT& ubound );
  
  using iterator = IteratorOfBoundedLineSubset<INT,DATA_STR>;
  
  inline void insert( const INT& i , const int& c = 1 );
  inline void IntervalInsert( const INT& i_start , const INT& i_final , const int& c = 1 );
  inline void erase( const INT& i , const int& c = 1 );
  // itrをインクリメントして書き換え、それへの参照を返す。
  inline iterator& erase( iterator& itr );
  inline void EraseAll( const INT& i );
  inline void IntervalErase( const INT& i_start , const INT& i_final , const int& c = 1 );

  inline int count( const INT& i ) noexcept;
  bool find( const INT& i ) noexcept;

  inline int InitialSegmentCount( const INT& i_final ) noexcept;
  inline int IntervalCount( const INT& i_start , const INT& i_final ) noexcept;

  // VVV重複度が非負の場合のみサポート（noexceptが外れていることに注意）
  inline bool empty();

  inline iterator begin();
  inline iterator end() const;

  inline iterator MaximumLeq( const INT& i , const int& k = 0 );
  inline iterator MaximumLt( const INT& i , const int& k = 0 );
  inline iterator MinimumGeq( const INT& i , const int& k = 0 );
  inline iterator MinimumGt( const INT& i , const int& k = 0 );

  inline INT Maximum( const int& k = 0 );
  inline INT Minimum( const int& k = 0 );
  // AAA重複度が非負の場合のみサポート

  inline const INT& lbound() const noexcept;
  inline const INT& ubound() const noexcept;

  void Display() noexcept;

};

#include "../a_Alias.hpp"

