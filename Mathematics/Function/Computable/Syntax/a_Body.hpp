// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/a_Body.hpp

#pragma once

#include "a.hpp"
#include "../../../../Utility/VLTree/a_Body.hpp"

template <typename... ARGS> SyntaxOfComputableFunction::SyntaxOfComputableFunction( const string& role , const ARGS&... args ) : m_syntax( args... ) { m_syntax.SetRoot( role ); }
  
inline const VLTree<string>& SyntaxOfComputableFunction::Get() const noexcept { return m_syntax; }

inline VLTree<string>& SyntaxOfComputableFunction::Ref() noexcept { return m_syntax; }

inline const string& SyntaxOfComputableFunction::GetRootString() const noexcept { return m_syntax.GetRoot(); }

inline const string& SyntaxOfComputableFunction::GetNodeString( const int& n ) const { return *( ( m_syntax.Root() )[n] );}

inline string SyntaxOfComputableFunction::Display() const noexcept { return m_syntax.Display(); }

inline void SyntaxOfComputableFunction::InputExitLine( ofstream& ofs , const string& function_expression_name ) const noexcept { ofs << "\\(" << function_expression_name << "\\)‚Í–¢’è‹`‚Å‚ ‚éB" << endl; }


template <typename... Args>
auto ExpressionsToListSyntax( const Args&... args ) -> typename enable_if<conjunction<is_same<Args,VLTree<string> >...>::value,VLTree<string> >::type
{

  const VLTree<VLTree<string> > args_copy{ args... };
  VLTree<string> t{};
  const string& list = ListString();

  for( auto itr = args_copy.LeftMostNode() ; itr.IsValid() ; itr++ ){

    auto itr_sub = itr->LeftMostNode();

    if( *itr_sub == list ){

      itr_sub++;
      itr_sub++;
      itr_sub++;
      
      while( itr_sub.IsValid() ){

	auto itr_sub_copy = itr_sub;
	itr_sub_copy[2];

	if( ! itr_sub_copy.IsValid() ){

	  ERR_IMPUT( t , *itr_sub );
	  
	}

	t.push_RightMost( *itr_sub_copy );
	itr_sub++;

      }

    } else {

      itr_sub++;
      
      if( ! itr_sub.IsValid() ){

	ERR_IMPUT( t );
	  
      }

      t.push_RightMost( *itr_sub );

    }    

  }

  return t;
  
}

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( List , list );
