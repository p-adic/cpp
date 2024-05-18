// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Hybrid/a.hpp

#pragma once
#include "../a.hpp"

// https://yukicoder.me/submissions/961777（零初期化、一点加算、区間和）
// https://yukicoder.me/submissions/961778（零初期化、配列初期化、始切片和）

// 一点取得と一点代入の高速化のためだけに通常の配列とハイブリッドしたBIT。
// メモリサイズは２倍になるので他の処理は遅くなる。

// 入力の範囲内で要件
// (1) MがUの可換群構造である。
// を満たす場合にのみサポート。
// ただしM.Inverse()を使うのはSetとIntervalSumのみなので、
// AddとInitialSegmentSumしか使わない場合は
// M.Inverse()を好きに設定してMをUの可換モノイド構造として良い。

// 配列による初期化O(size)

// 一点取得O(1)
// U.Sum()によるLSB切片和取得O(1)（a[j-(j&-j)]+...+a[j-1]）
// U.Sum()による始切片和取得O(log_2 size)
// U.Sum()による区間和取得O(log_2 size)

// 一点代入O(log_2 size)（通常のBITより定数倍速い）
// U.Sum()による一点加算O(log_2 size)

// 以下は入力の範囲内で要件
// (2) operator<(const U&,const U&)に関してMがUの全順序可換群構造である。
// (3) 各成分がM.One()より小さくない。
// を満たす場合にのみサポート。
// U.Sum()による始切片和がu以上となる要素の添字の最小値の二分探索O(log_2 size)
// 左端点を固定した時にU.Sum()による区間和がu以上となる要素の添字の最小値の二分探索O(log_2 size)
template <typename U , typename ABELIAN_GROUP>
class AbstractHybridBIT :
  public AbstractBIT<U,ABELIAN_GROUP>
{
private:
  vector<U> m_a;

public:
  inline AbstractHybridBIT( ABELIAN_GROUP M , const int& size = 0 );
  inline AbstractHybridBIT( ABELIAN_GROUP M , vector<U> a );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void Add( const int& i , const U& u );

  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  
};
template <typename ABELIAN_GROUP , typename...Args> AbstractHybridBIT( ABELIAN_GROUP M , Args&&... args ) -> AbstractHybridBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U>
class HybridBIT :
  public AbstractHybridBIT<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline HybridBIT( Args&&... args );

};
template <typename U> HybridBIT( const vector<U>& a ) -> HybridBIT<U>;
