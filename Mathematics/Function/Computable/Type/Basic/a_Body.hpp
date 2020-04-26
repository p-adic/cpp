// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Int/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

inline const int& infty() noexcept { static const int N = 2147483647; return N; }

DEFINITION_OF_BASIC_TYPE( int , IntString() );
DEFINITION_OF_BASIC_TYPE( string , StringString() );
DEFINITION_OF_BASIC_TYPE( bool , BoolString() );
