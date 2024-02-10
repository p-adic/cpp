// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BellmanFord/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../../../Algebra/Monoid/a.hpp"

// verify:
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/GRL_1_B/judge/8795916/C++17（経路復元なし）

// GRAPHはグラフG=(V_G,E_G:T->(T \times U)^{< \omega})に相当する型。

// 入力の範囲内で要件
// (0) Mは全順序可換モノイド構造である。
// (1) inftyがE_Gの値の各成分の第2成分|V_G|個以下の和で表せるいかなる数よりも大きい。
// が成り立つ場合にのみサポート。

// 単一始点全終点最短経路探索／経路復元なしO(|V_G| |E_G|)
// 単一始点全終点最短経路探索／経路復元ありO(|V_G| |E_G|)
template <typename GRAPH , typename MONOID , typename U>
class AbstractBellmanFord :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  // コンストラクタに引数が必要なMultiplicativeMonoidなどはstaticメンバ関数による
  // 参照返しがしにくく、コンストラクタの返り値である右辺値を受け取ることを許容したいので
  // 左辺値参照にはしない。
  MONOID m_M;

public:
  inline AbstractBellmanFord( GRAPH& G , MONOID M , const U& infty );

  // 負の閉路が存在すればfalse、存在しなければtrueを第1成分に返す。
  tuple<bool,vector<U>> GetDistance( const inner_t<GRAPH>& t_start , const bool& dummy = true );
  template <template <typename...> typename V> tuple<bool,vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start , const V<inner_t<GRAPH>>& t_finals , const bool& dummy = true );
  tuple<bool,vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start , const bool& dummy = true );
  
};

template <typename GRAPH>
class BellmanFord :
  public AbstractBellmanFord<GRAPH,AdditiveMonoid<>,ll>
{

public:
  inline BellmanFord( GRAPH& G );
  
};
