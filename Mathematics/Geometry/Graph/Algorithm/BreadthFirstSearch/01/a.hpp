// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/01/a.hpp

#pragma once
#include "../../../a.hpp"

// verify:
// https://yukicoder.me/submissions/953236 (GetWeight)
// https://yukicoder.me/submissions/1009094 (GetWeight)

// GRAPHは{0,1}彩色付き辺Edge:T->(T \times \{0,1\})^{< \omega}を持つグラフに相当する型。

// 構築 O(1)/O(|V_G|)（未初期化/初期化）
// Next()の反復でinitから到達可能な頂点を全探索 O(initの連結成分における辺の本数)
// Next()の反復とShift()で全探索 O(|V_G|+|E_G|)
// initからの到達可能性判定と距離計算 O(initの連結成分における辺の本数)
template <typename T , typename GRAPH>
class ZeroOneBreadthFirstSearch
{

protected:
  GRAPH& m_G;
  // 未訪問点のm_prevに格納するための変数。m_nextが空の時のNext()の戻り値。
  T m_not_found;
  bool m_initialised;
  // 次の探索点たちを格納。
  list<T> m_next;

  // 以下GRAPHがGraphでない場合は添字にEnumerationが絡むことに注意。
  // 0:未接続、1:前に接続、2:後ろに接続、3:探索済み
  vector<int> m_found;
  // 到達済みかつ到達済みの点から辺を辿って到達した場合、その点を格納。
  vector<T> m_prev;
  // 探索時点の始点からの重みを格納。
  vector<int> m_weight;
  
public:
  inline ZeroOneBreadthFirstSearch( GRAPH& G , const T& not_found );
  template <typename Arg> inline ZeroOneBreadthFirstSearch( GRAPH& G , const T& not_found , Arg&& init );

  // m_nextとm_foundとm_prevとm_weightを初期化する。
  inline void Initialise();
  // m_nextとm_foundとm_prevとm_weightを初期化した上でinitを最初の探索点に設定する。
  inline void Initialise( const T& init );
  inline void Initialise( list<T> inits );
  // m_nextを初期化した上でm_foundとm_prevとm_weightを非初期化せずinitを次の探索点に設定する。
  inline void Shift( const T& init );
  inline void Shift( list<T> inits );

  inline const int& size() const;
  inline int& found( const T& t );
  inline const T& prev( const T& t );
  // 現時点での重みを返す。
  inline const int& weight( const T& t );

  T Next();

  // 始点から到達できる点の重みをm_weightに格納し、到達できない未到達点は重みの代わりに-1を格納する。
  inline void SetWeight();
  // t_goalが始点から到達できるならばその重みを、到達できないならば-1をm_weightに格納して
  // そこへの参照を返す。
  // Dijkstraと違って参照を行うため、返り値を配列にしない。
  inline const int& GetWeight( const T& t_goal );

};
