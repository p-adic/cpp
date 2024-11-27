// c:/Users/user/Documents/Programming/Mathematics/Game/a.hpp

#pragma once

// 着手が存在しない場合に負けとなるゲームの勝敗を計算する。
// Edgeはゲームの状態遷移を表す写像edge:T->T^{<\infty}に相当する型。
template <typename Edge , typename T> const bool& IsWinningState( Edge& edge , const T& t , const bool& reset = false );

// 着手が存在しない場合に負けとなるゲームのグランディ数を計算する。
// AEdgeはゲームの状態遷移の和への分解を表す写像aedge:T->(T^{<\infty})^{<\infty}に相当する型。
// 各a in aedge(t)はそのゲーム和がtの遷移先に対応する配列。
template <typename AEdge , typename T> const int& GrundyNumber( AEdge& aedge , const T& t , const bool& reset = false );

// 着手が存在しない局面の{0,1}値不変量が最初に与えられる定数Cと一致する場合に
// 勝ちとなるゲームで必勝となるC全体の集合を2進法で計算する。
template <typename Edge , typename T , typename INVARIANT> const int& WinningConstantsOf( Edge& edge , const T& t , const INVARIANT& invariant , const bool& reset = false );
