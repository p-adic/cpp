// c:/Users/user/Documents/Programming/Mathematics/Function/Recursion/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/Tuple/a_Body.hpp"

template <typename REC> inline MemorisationRecursion<REC>::MemorisationRecursion( REC rec ) : REC( move( rec ) ) {}

template <typename REC> template <typename...Args> inline const ret_t<REC,MemorisationRecursion<REC>&,Args&&...>& MemorisationRecursion<REC>::operator()( Args&&... args ){ static unordered_map<tuple<decay_t<Args>...>,ret_t<REC,MemorisationRecursion<REC>&,Args&&...>> memory{}; const tuple<decay_t<Args>...> v{ args... }; return memory.count( v ) == 0 ? memory[v] = REC::operator()( *this , forward<decay_t<Args>>( args )... ) : memory[v]; }
