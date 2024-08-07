// c:/Users/user/Documents/Programming/Mathematics/Game/a.hpp

#pragma once

// Edgeはゲームの状態遷移を表す写像edge:T->T^{<\infty}に相当する型。
template <typename Edge , typename T> const bool& IsWinningState( Edge& edge , const T& t , const bool& reset = false );

// AEdgeはゲームの状態遷移の和への分解を表す写像aedge:T->(T^{<\infty})^{<\infty}に相当する型。
// 各a in aedge(t)はそのゲーム和がtの遷移先に対応する配列。
template <typename AEdge , typename T> const int& GrundyNumber( AEdge& aedge , const T& t , const bool& reset = false );
