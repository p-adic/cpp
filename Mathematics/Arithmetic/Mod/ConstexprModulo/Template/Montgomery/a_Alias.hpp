// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Template/Montgomery/a_Alias.hpp

#pragma once

template <INT_TYPE_FOR_MOD M>
using Montgomery = Mod<M,enable_if_t< ( M & 1 ) == 1 , OperatorsForMontgomery<M> > >;
