// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/a_Body.hpp

#pragma once
#include "a.hpp"

inline TypeOfComputableFunction::TypeOfComputableFunction( const string& type_name , const string& definition ) noexcept : m_type_name( type_name ) , m_definition( definition ) {}
  
inline const string& TypeOfComputableFunction::Display() const noexcept { return m_type_name; }
