// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/a.hpp

#pragma once
#include "../../a.hpp"
#include "../../../../Utility/Set/Map/a.hpp"

// verify:
// https://yukicoder.me/submissions/978898（一始点Shiftの反復による多点BFSでの全探索）
// https://yukicoder.me/submissions/978899（GetConnectedComponent）
// https://yukicoder.me/submissions/978904（一始点のGetDistance、EnumerationGraph）
// https://yukicoder.me/submissions/978910（一始点のGetDistance、MemorisationGraph）

// GRAPHは辺Edge:T->(T \times ...)^{< \omega}を持つグラフに相当する型。

// 入力の範囲内で要件
// (1) Gは有向グラフである。
// (2) not_foundはGの頂点でない。
// を満たす場合にのみサポート。

// 構築 O(1)/O(|V_G|)（未初期化/初期化）
// Next()の反復でinitから到達可能な頂点を全探索 O(initの連結成分における辺の本数)
// Next()の反復とShift()で全探索 O(|V_G|+|E_G|)
// initからの到達可能性判定と深さ計算 O(initの連結成分における辺の本数)
// 連結成分の色分けと数え上げ O(|V_G|+|E_G|) 
template <typename T , typename GRAPH>
class VirtualBreadthFirstSearch
{

protected:
  GRAPH& m_G;
  // 未訪問点のm_prevに格納するための変数。m_nextが空の時のNext()の戻り値。
  T m_not_found;
  bool m_initialised;
  // 次の探索点たちを格納。
  list<T> m_next;

  // 以下GRAPHがGraphでない場合は添字にEnumerationが絡むことに注意。
  // m_nextに格納されたことがあるか否か。
  vector<bool> m_found;
  // 到達済みかつ到達済みの点から辺を辿ってNext()で到達した場合、その点を格納。
  // GRAPHがGraphでない場合は添字にEnumerationが絡むことに注意。
  vector<T> m_prev;

public:
  inline VirtualBreadthFirstSearch( GRAPH& G , const T& not_found );
  template <typename Arg> inline VirtualBreadthFirstSearch( GRAPH& G , const T& not_found , Arg&& init );

  // m_nextとm_foundとm_prevを初期化する。
  inline void Initialise();
  // m_nextとm_foundとm_prevを初期化した上でinitを最初の探索点に設定する。
  inline void Initialise( const T& init );
  inline void Initialise( list<T> inits );
  // m_nextを初期化した上でm_foundとm_prevを非初期化せずinitを次の探索点に設定する。
  inline void Shift( const T& init );
  inline void Shift( list<T> inits );

  // Gのサイズを取得。
  inline const int& size() const noexcept;
  inline vector<bool>::reference found( const T& t );
  inline const T& prev( const T& t );

  inline T Next();

  // m_nextに格納されている未到達点（初期化時点ではinit/inits）から到達できる未到達点の深さを
  // 格納した配列を返す。ただし到達できない未到達点や既到達点は深さの代わりに-1を格納する。
  template <typename U = T> auto GetDistance() -> enable_if_t<is_same_v<GRAPH,MemorisationGraph<U,decldecay_t(declval<GRAPH>().edge())>>,Map<T,int>>;
  template <typename U = T> auto GetDistance() -> enable_if_t<!is_same_v<GRAPH,MemorisationGraph<U,decldecay_t(declval<GRAPH>().edge())>>,vector<int>>;
  
  // GRAPHがMemorisationGraphでない無向グラフ（の有向化）である場合にのみサポート。
  // {未到達点の全体のなす部分グラフにおける連結成分の色分け,その逆像,色の種類数}を格納。
  tuple<vector<int>,vector<vector<T>>,int> GetConnectedComponent();

  // m_nextに格納されている未到達点から到達できる未到達点を探索順に格納する。
  vector<T> GetNodeEnumeration();
  
  // m_nextに格納されている未到達点から到達できる未到達点を帰りがけ順に格納する。
  // 行きがけ順の逆順ではないことに注意。
  vector<T> GetReversedNodeEnumeration();

private:
  virtual void Push( list<T>& next , const T& t ) = 0;
  template <typename PATH> inline void Push( list<T>& next , const PATH& p );

};

template <typename T , typename GRAPH>
class BreadthFirstSearch :
  public VirtualBreadthFirstSearch<T,GRAPH>
{

public:
  template <typename...Args> inline BreadthFirstSearch( GRAPH& G , const T& not_found , Args&&... args );

private:
  inline void Push( list<T>& next , const T& t );

};

