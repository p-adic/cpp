// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/945886（多点BFSによる全探索）
// https://yukicoder.me/submissions/945907（多点BFSによる連結成分取得）
// https://yukicoder.me/submissions/951954（GetDistance）

// GRAPHは辺Edge:N->N^{< \omega}を持つグラフに相当する型。

// 構築 O(1)/O(|V_G|)（未初期化/初期化）
// Next()の反復でinitから到達可能な頂点を全探索 O(initの連結成分における辺の本数)
// Next()の反復とShift()で全探索 O(|V_G|+|E_G|)
// initからの到達可能性判定と深さ計算 O(initの連結成分における辺の本数)
// 連結成分の色分けと数え上げ O(|V_G|+|E_G|) 
template <typename GRAPH>
class VirtualBreadthFirstSearch :
  public PointedSet<int>
{

protected:
  GRAPH& m_G;
  bool m_initialised;
  // 次の探索点たちを格納。
  list<int> m_next;
  // 到達済みか否かを格納。
  vector<bool> m_found;
  // 到達済みかつ到達済みの点から辺を辿って到達した場合、その点を格納。
  vector<int> m_prev;

public:
  inline VirtualBreadthFirstSearch( GRAPH& G );
  inline VirtualBreadthFirstSearch( GRAPH& G , const int& init );

  // m_nextとm_foundとm_prevを初期化する。
  inline void Initialise();
  // m_nextとm_foundとm_prevを初期化した上でinitを最初の探索点に設定する。
  inline void Initialise( const int& init );
  // m_nextを初期化した上でm_foundとm_prevを非初期化せずinitを次の探索点に設定する。
  inline void Shift( const int& init );

  inline const int& size() const noexcept;
  inline vector<bool>::reference found( const int& i );
  inline const int& prev( const int& i );

  inline int Next();

  // 最初の未到達点（初期化時点ではinit）から到達できる未到達点の深さを格納し、
  // 到達できない未到達点や既到達点は深さの代わりに-1を格納。
  vector<int> GetDistance();
  // 無向グラフである場合にのみサポート。
  // 未到達点の全体のなす部分グラフにおける連結成分の色分けと連結成分数を格納。
  void SetConnectedComponent( vector<int>& cc_num , int& count );

private:
  virtual void Push( list<int>& next , const int& i ) = 0;

};

template <typename GRAPH>
class BreadthFirstSearch :
  public VirtualBreadthFirstSearch<GRAPH>
{

public:
  template <typename...Args> inline BreadthFirstSearch( GRAPH& G , const Args&... args );

private:
  inline void Push( list<int>& next , const int& i );

};

