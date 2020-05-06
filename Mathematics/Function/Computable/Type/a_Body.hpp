// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Syntax/Translation/a_Body.hpp"

inline TypeOfComputableFunction::TypeOfComputableFunction( const string& type_name , const string& definition ) noexcept : m_type_name( type_name ) , m_definition( definition ) {}
  
inline const string& TypeOfComputableFunction::Display() const noexcept { return m_type_name; }

inline void TypeOfComputableFunction::InputDefinition( ofstream& ofs , const string& language , const string& style ) const noexcept { try{ InputDefinitionOfRecursiveSet( ofs , m_type_name , m_definition , language , style ); } catch( const ErrorType& e ){ IGNORED_ERR( e ); }; }
