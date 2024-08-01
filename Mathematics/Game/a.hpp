// c:/Users/user/Documents/Programming/Mathematics/Game/a.hpp

#pragma once

// Edge‚ÍƒQ[ƒ€‚Ìó‘Ô‘JˆÚ‚ğ•\‚·Ê‘œedge:T->T^{<\infty}‚É‘Š“–‚·‚éŒ^B
template <typename Edge , typename T> const bool& IsWinningState( Edge& edge , const T& t , const bool& reset = false );

// AEdge‚ÍƒQ[ƒ€‚Ìó‘Ô‘JˆÚ‚Ì˜a‚Ö‚Ì•ª‰ğ‚ğ•\‚·Ê‘œaedge:T->(T^{<\infty})^{<\infty}‚É‘Š“–‚·‚éŒ^B
// Šea in aedge(t)‚Í‚»‚ÌƒQ[ƒ€˜a‚ªt‚Ì‘JˆÚæ‚É‘Î‰‚·‚é”z—ñB
template <typename AEdge , typename T> const int& GrundyNumber( AEdge& aedge , const T& t , const bool& reset = false );
