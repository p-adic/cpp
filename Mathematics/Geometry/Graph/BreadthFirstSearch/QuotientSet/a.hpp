// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/QuotientSet/a.hpp

#pragma once
#include "a.hpp"

//verify:
// https://yukicoder.me/submissions/981290（Shift,Next）

// GRAPHは辺Edge:T->(T \times ...)^{< \omega}を持つMemorisationGraphでない
// 完全グラフに相当する型。

// 構築 O(1)/O(|V_G|)（未初期化/初期化）
// Next()の反復でinitから到達可能な頂点を全探索 O(initの連結成分における辺の本数)
// Next()の反復とShift()で全探索 O(|V_G|+|E_G|)
// initからの到達可能性判定と深さ計算 O(initの連結成分における辺の本数)
// 連結成分の色分けと数え上げ O(|V_G|+|E_G|) 
template <typename T , typename GRAPH>
class QuotientSetSearch
{

protected:
  GRAPH& m_G;
  // 未訪問点のm_prevに格納するための変数。m_nextが空の時のNext()の戻り値。
  T m_not_found;
  // 次の探索点たちを格納。（InitialiseとShiftでしか増えないのでvectorでよい）
  vector<T> m_next;

  // 以下GRAPHがGraphでない場合は添字にEnumerationが絡むことに注意。
  // 連結成分全体を探索済みか否かを格納。
  vector<bool> m_found;
  // 同値類の代表元を格納。
  // GRAPHがGraphでない場合は添字にEnumerationが絡むことに注意。
  vector<T> m_repr;

public:
  inline QuotientSetSearch( GRAPH& G , const T& not_found );
  template <typename Arg> inline QuotientSetSearch( GRAPH& G , const T& not_found , Arg&& init );

  // m_foundとm_prevを初期化する。
  inline void Initialise();
  // m_nextとm_foundを初期化した上でinitを最初の探索点に設定する。
  inline void Initialise( const T& init );
  inline void Initialise( vector<T> inits );
  // m_nextを初期化した上でm_foundを非初期化せずinitを次の探索点に設定する。
  inline void Shift( const T& init );
  inline void Shift( vector<T> inits );

  // Gのサイズを取得。
  inline const int& size() const noexcept;
  inline vector<bool>::reference found( const T& t );
  inline const T& repr( const T& t );

  inline T Next();

  // 連結成分の代表元による色分けと連結成分数を格納。
  pair<const vector<T>&,int> Get();

};
