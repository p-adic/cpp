// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../Expression/Condition/a_Body.hpp"

inline TypeOfComputableFunction::TypeOfComputableFunction( const ConditionOfComputableFunction& cond ) : m_cond( cond ) {}

inline const string& TypeOfComputableFunction::Name() noexcept { static const string name = "V"; return name; }

inline void TypeOfComputableFunction::SetCondition( const ConditionOfComputableFunction& cond ) noexcept { m_cond = m_cond && cond; }
inline const ConditionOfComputableFunction& TypeOfComputableFunction::GetCondition() const noexcept { return m_cond; }

