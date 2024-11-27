// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/DiscreteLog/a.hpp

#pragma once

// Baby-step giant-stepアルゴリズムで離散対数を求める。（O(√B)）
template <typename INT1 , typename INT2 , typename INT3> int DiscreteLog( INT1 x , INT2 base , const INT3& B );
