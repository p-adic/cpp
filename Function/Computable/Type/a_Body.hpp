// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Syntax/Translation/a_Body.hpp"

inline TypeOfComputableFunction::TypeOfComputableFunction( const string& type_name , const string& construction , const string& description ) noexcept : m_type_name( type_name ) , m_construction( construction ) , m_description( description ) {}
  
inline const string& TypeOfComputableFunction::Display() const noexcept { return m_type_name; }
