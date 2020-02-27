// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/a_Body.hpp

#pragma once

#include "a.hpp"
#include "../../../../Utility/VLTree/a_Body.hpp"

template <typename... ARGS> SyntaxOfComputableFunction::SyntaxOfComputableFunction( const string& role , const ARGS&... args ) : m_syntax( args... ) { m_syntax.SetRoot( role ); }
  
inline const VLTree<string>& SyntaxOfComputableFunction::Get() const noexcept { return m_syntax; }

inline VLTree<string>& SyntaxOfComputableFunction::Ref() noexcept { return m_syntax; }

inline const string& SyntaxOfComputableFunction::GetRootString() const noexcept { return m_syntax.GetRoot(); }

inline const string& SyntaxOfComputableFunction::GetNodeString( const int& n ) const { return *( m_syntax.Root()[n] );}

inline void SyntaxOfComputableFunction::InputFinishLine( ofstream& ofs ) const noexcept { ofs << "I—¹‚·‚éB" << endl; }


DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( List , list );
