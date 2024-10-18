// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Path/a.hpp

#pragma once

// EXECはvoid (&exec)( const T& )に相当する型。

// 頂点数をV、出次数の最大値をD_max、経路長の最大値をL_maxと置く。
// 合計O(V+D_max^L_max)で経路pを全探索しexec(p)を実行する。
// 例えばグリッドならO(4^{HW})で処理し、HW=13程度が限度。
template <typename GRAPH , typename T , typename EXEC> void PathExhausiveSearch( GRAPH& G , const T& start , const T& goal , const EXEC& exec );
