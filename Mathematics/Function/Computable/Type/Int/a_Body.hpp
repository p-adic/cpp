// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Int/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../a_Body.hpp"

inline IntTypeOfComputableFunction::IntTypeOfComputableFunction( const int& n ) noexcept : TypeOfComputableFunction() , m_n( n );

const int& IntTypeOfComputableFunction::GetValue() const noexcept { return m_n; }
