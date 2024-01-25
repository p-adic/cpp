// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/01/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/946047（経路復元なし）

// GRAPHは{0,1}彩色付き辺Edge:N->(N \times \{0,1\})^{< \omega}を持つグラフに相当する型。

// 構築 O(1)/O(|V_G|)（未初期化/初期化）
// Next()の反復でinitから到達可能な頂点を全探索 O(initの連結成分における辺の本数)
// Next()の反復とShift()で全探索 O(|V_G|+|E_G|)
// initからの到達可能性判定と距離計算 O(initの連結成分における辺の本数)
template <typename GRAPH>
class ZeroOneBreadthFirstSearch
{

protected:
  GRAPH& m_G;
  bool m_initialised;
  // 次の探索点たちを格納。
  list<int> m_next;
  // 0:未接続、1:前に接続、2:後ろに接続、3:探索済み
  vector<int> m_found;
  // 到達済みかつ到達済みの点から辺を辿って到達した場合、その点を格納。
  vector<int> m_prev;
  // 探索時点の始点からの重みを格納。
  vector<int> m_weight;
  
public:
  inline ZeroOneBreadthFirstSearch( GRAPH& G );
  inline ZeroOneBreadthFirstSearch( GRAPH& G , const int& init );

  // m_nextとm_foundとm_prevとm_weightを初期化する。
  inline void Initialise();
  // m_nextとm_foundとm_prevとm_weightを初期化した上でinitを最初の探索点に設定する。
  inline void Initialise( const int& init );
  // m_nextを初期化した上でm_foundとm_prevとm_weightを非初期化せずinitを次の探索点に設定する。
  inline void Shift( const int& init );

  inline const int& size() const;
  inline int& found( const int& i );
  inline const int& prev( const int& i );
  inline const int& weight( const int& i );

  int Next();

  // 最初の未到達点（初期化時点ではinit）から到達できる未到達点の重みをm_weightに格納し、
  // 到達できない未到達点や既到達点は重みの代わりに-1を格納。
  inline void SetWeight();
  // 初期化後にNext()の反復でinitからgoalまでの重みを計算する。
  inline const int& GetWeight( const int& init , const int& goal );

};
