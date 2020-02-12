// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../Expression/Condition/a_Body.hpp"

inline TypeOfComputableFunction::TypeOfComputableFunction() : TypeOfComputableFunction( true ) {}
inline TypeOfComputableFunction::TypeOfComputableFunction( const ConditionOfComputableFunction& cond ) : m_cond( cond );


inline void SetCondition( const ConditionOfComputableFunction& cond ) noexcept { m_cond = m_cond && cond; }
inline const ConditionOfComputableFunction& TypeOfComputableFunction::GetCondition() const noexcept { return m_cond; }
