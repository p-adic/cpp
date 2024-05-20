// c:/Users/user/Documents/Programming/Mathematics/Graph/Algorithm/HeldKarp/a.hpp

#pragma once

// 各辺の重みがpath_Eである巡回世ールスマン問題において
// 頂点k_startから頂点k_goalまでをsに2進法で対応する頂点集合のみを経由する場合に
// （要仕様確認）
template <int NM , int P> const ll& HeldKarp( const int& k_start , const int& k_goal , const int& s , const int (&k_valid)[P] , const int& P_valid , const ll (&path_E)[NM][NM] , const int (&near)[P][P][2] , const ll (&E_min)[P][P] , int (&k_mid)[P] );
