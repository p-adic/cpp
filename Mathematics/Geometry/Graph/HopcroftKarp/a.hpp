// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/HopcroftKarp/a.hpp

#pragma once

// (S,T,edge)が二部グラフである場合のみサポート。
// edgeのサイズをeと置く。最大二部マッチング問題を
// O(ST+(e+log_2 S)√(S+T))で解く。
// 特に
// - eがO(ST)の時はO(ST√(S+T))、
// - eがO(S+T)の時はO(ST)
// で解く。
template <int S_max , int T_max>
class HopcroftKarp
{

private:
  static int g_S;
  static int g_T;
  static set<int> g_unchosen_source;
  static list<int> g_edge[S_max];
  static int g_prev[T_max];

public:
  HopcroftKarp() = delete;

  static list<pair<int,int> > Solve( const int& S , const int& T , const list<pair<int,int> >& edge );
  static list<int> Edge( const int& w );

};
