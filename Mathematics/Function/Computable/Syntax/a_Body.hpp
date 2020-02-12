// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/a_Body.hpp

#pragma once

#include "a.hpp"
#include "../../../../Utility/VLTree/a_Body.hpp"

template <typename... ARGS> SyntaxOfComputableFunction::SyntaxOfComputableFunction( const ARGS&... args ) : m_syntax( args... ) {}
  
inline const VLTree<string>& SyntaxOfComputableFunction::Get() const noexcept { return m_syntax; }

inline VLTree<string>& SyntaxOfComputableFunction::Ref() noexcept { return m_syntax; }
