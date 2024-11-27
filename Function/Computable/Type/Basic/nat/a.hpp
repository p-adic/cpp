// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Basic/nat/a.hpp

#pragma once
#include "../../SubType/a.hpp"
#include "../../../Operator/Basic/int/a.hpp"

// SPECの仕様上NatString()を使えない。
SPEC_BODY( nat , \\mathbb{N} , VariableSymbol<int>( "n" ) , NonNegativeSymbol() );
