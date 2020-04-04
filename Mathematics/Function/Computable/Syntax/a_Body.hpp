// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/a_Body.hpp

#pragma once

#include "a.hpp"
#include "../../../../Utility/VLTree/a_Body.hpp"

template <typename... ARGS> SyntaxOfComputableFunction::SyntaxOfComputableFunction( const string& role , const ARGS&... args ) : m_syntax( args... ) { m_syntax.SetRoot( role ); }
  
inline const VLTree<string>& SyntaxOfComputableFunction::Get() const noexcept { return m_syntax; }

inline VLTree<string>& SyntaxOfComputableFunction::Ref() noexcept { return m_syntax; }

inline const string& SyntaxOfComputableFunction::GetRootString() const noexcept { return m_syntax.GetRoot(); }

inline const string& SyntaxOfComputableFunction::GetNodeString( const int& n ) const { return *( m_syntax.Root()[n] );}

inline string SyntaxOfComputableFunction::Display() const noexcept { return m_syntax.Display(); }

inline void SyntaxOfComputableFunction::InputExitLine( ofstream& ofs , const string& function_expression_name ) const noexcept { ofs << "\\(" << function_expression_name << "\\)‚Í–¢’è‹`‚Å‚ ‚éB" << endl; }

template <typename... Args>
auto FunctionExpressionToString( const SyntaxOfComputableFunction& f , const Args&... args ) -> typename enable_if<conjunction<is_same<Args,string>...>::value,string>::type
{

  VLTree<string> t{ args... };
  VLTree<string>::const_iterator itr = t.LeftMostNode();

  TRY_CATCH
    (

     return FunctionExpressionToString( f , itr ) ,
     const ErrorType& e ,
     CALL_P( e , f , args... )

     );
  
  return "dummy";

}


DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( List , list );
