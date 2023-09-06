// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/HopcroftKarp/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/911317

// (S,T,edge)が二部グラフである場合のみサポート。
// edgeのサイズをeと置く。最大二部マッチング問題を
// 時間計算量O((S+T+e)√(S+T))
// 空間計算量O(S+T+e)
// で解く。特に
// - eがO(ST)の時は時間計算量O(ST√(S+T))
// - eがO(S+T)の時は時間計算量O((S+T)√(S+T))
// で解く。
template <int S_max , int T_max>
class HopcroftKarp
{

private:
  // BFSのテンプレート引数にEdgeを渡すために、staticメンバのみを使う。
  static int g_S;
  static int g_T;
  static set<int> g_unchosen_source;
  static list<int> g_edge[S_max];
  static int g_prev[T_max];

public:
  HopcroftKarp() = delete;

  static list<pair<int,int> > Solve( const int& S , const int& T , const list<pair<int,int> >& edge );

  // BFSのテンプレート引数に渡す。
  // (1) w=0の時は、未選択なSの頂点リストを返す。
  // (2) 0<w<=Sの時は、s=w-1からの有向辺の終端全体のリストを返す。
  // (3) S<w<=S+Tの時は、t=w-S-1が未選択ならば空リストを返し、
  //     選択済みならば対応する有向辺の始端sのみからなるリストを返す。
  static list<int> Edge( const int& w );

};

