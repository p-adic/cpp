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

template <typename... Args>
auto ExpressionsToListSyntax( const Args&... args ) -> typename enable_if<conjunction<is_same<Args,VLTree<string> >...>::value,VLTree<string> >::type
{

  const VLTree<VLTree<string> > args_copy{ args... };
  VLTree<string> t{};
  const string& list = ListString();

  for( auto itr = args_copy.LeftMostNode() ; itr.IsValid() ; itr++ ){

    ConstIteratorOfVLTree<string> itr_sub = itr->LeftMostNode();

    if( *itr_sub == list ){

      itr_sub++;
      itr_sub++;
      itr_sub++;
      
      while( itr_sub.IsValid() ){

	ConstIteratorOfVLTree<string> itr_sub_copy = itr_sub;
	itr_sub_copy[2];

	t.push_RightMost( VLTree<string>( itr_sub_copy , 0 ) );
	itr_sub++;

      }

    } else {

      itr_sub++;
      
      if( ! itr_sub.IsValid() ){

	ERR_IMPUT( t );
	  
      }

      t.push_RightMost( VLTree<string>( itr_sub , 0 ) );

    }    

  }

  return t;
  
}

inline void PutKagi( string& s ) noexcept { s = "Åu" + s + "Åv"; }
inline void PutParenthesis( string& s ) noexcept { s = "( " + s + " )"; }

inline string Plainise( const string& s ) noexcept { return "\\textrm{" + s + "}"; }

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Empty ){ static const string s = ""; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Space ){ static const string s = " "; return s; }
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Sub , _ );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Sup , ^ );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lparen ){ static const string s = "("; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Rparen ){ static const string s = ")"; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lbrace ){ static const string s = "{"; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Rbrace ){ static const string s = "}"; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lbrack ){ static const string s = "["; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Rbrack ){ static const string s = "]"; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Comma ){ static const string s = ","; return s; }
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Ldots , \\ldots );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Separator , separator );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Nest , nest );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( List , list );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Expression , expression );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Variable , variable );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Constant , constant );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Function , function );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Relation , relation );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Minus , - );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Slash , \\slash );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Mod , % );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Power , ^ );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Neg , \\neg );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( To , \\rightarrow );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Equiv , \\equiv );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Plus , + );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Frown , \\frown );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Times , \\times );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Land , \\land );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lor , \\lor );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Eq , = );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Neq , \\neq );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Leq , \\leq );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Geq , \\geq );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lneq , < );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Gneq , > );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Line , line );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( If , if );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Put , put );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Print , print );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Exit , exit );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Return , return );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Japanese , Japanese );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( English , English );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( english , english );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Fandom , Fandom );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Jekyll , Jekyll );

