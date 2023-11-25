// c:/Users/user/Documents/Programming/Utility/Set/Mex/GrundyNumber/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

template <typename T , template <typename...> typename V , V<T> E(const T&)>
const bool& HasNonZeroGrundyNumber( const T& t , const bool& reset = false );

template <typename T , template <typename...> typename V , V<T> E(const T&)>
const int& GrundyNumber( const T& t , const bool& reset = false );
