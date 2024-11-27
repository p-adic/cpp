// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/UnionFindForest/Kruscal/a.hpp

#pragma once
#include "../../../a.hpp"

// verify:
// https://yukicoder.me/submissions/957499

// GRAPHは有向グラフG=(V_G,E_G)に相当する型。
// ただし辺Eは写像T -> ( T \times U \times int \times ... )^{< \omega}に相当し、
// その値の第3成分は辺番号を表す。

// 入力の範囲内で要件
// (1) Uはbool operator<(const U&,const U&)に関して全順序である。
// (2) EはE_Gの番号付けである。
// を満たす場合にのみサポート。

// O(|E_G|(α(|V_G| + log_2 |E_G|)))でGの無向化の、answerに対応する辺集合を含む全域森のうち
// 重み（の<に関して全順序モノイドをなす可換モノイド構造に関する総和）が最小な全域森の
// {辺番号の配列,連結成分の個数}を返す。
// そのような全域森が存在しない（answerが閉路を含む）場合は{answer,-1}を返す。
template <typename GRAPH> inline pair<vector<int>,int> Kruscal( GRAPH& G , const vector<pair<int,int>>& E , vector<int> answer = {} );

// OnはE_Gの{0,1}彩色on:int（辺番号）-> {0,1}に相当する型。

// 入力の範囲内で要件
// (1) E_sortedはE_GをUの順序に関してソートしたものである。
// を満たす場合にのみサポート。

// O(|E_G| α(|V_G|))でonで1に色付けされるGの辺のみからなる部分グラフの無向化の、
// answerに対応する辺集合を含む全域森のうち重み（の<に関して全順序モノイドをなす
// 可換モノイド構造に関する総和）が最小な全域森の{辺番号の配列,連結成分の個数}を返す。
// そのような全域森が存在しない（answerが閉路を含むか0に色付けされる辺を含む）場合は
// {answer,-1}を返す。
template <typename On> pair<vector<int>,int> Kruscal( const int& V , const vector<pair<int,int>>& E , const list<tuple<int,int,int>>& E_sorted , const On& on , vector<int> answer = {} );
