// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/a_Body.hpp

#pragma once

#include "a.hpp"
#include "../../../../Utility/VLTree/a_Body.hpp"

template <typename... ARGS> SyntaxOfComputableFunction::SyntaxOfComputableFunction( const string& role , const ARGS&... args ) : m_syntax( args... ) { m_syntax.SetRoot( role ); }
  
inline SyntaxOfComputableFunction::SyntaxOfComputableFunction( const SyntaxOfComputableFunction& t ) : m_syntax( t.m_syntax ) {}

inline SyntaxOfComputableFunction& SyntaxOfComputableFunction::operator=( const SyntaxOfComputableFunction& t ) { m_syntax = t.m_syntax; return *this; }


inline const VLTree<string>& SyntaxOfComputableFunction::Get() const noexcept { return m_syntax; }

inline VLTree<string>& SyntaxOfComputableFunction::Ref() noexcept { return m_syntax; }


template <typename... Args> inline const string& SyntaxOfComputableFunction::GetNodeString( const Args&... args ) const { return m_syntax.GetNode( args... );}

template <typename... Args> inline VLTree<string> SyntaxOfComputableFunction::GetSubTree( const Args&... args ) const { return VLTree<string>( 0 , m_syntax.GetIterator( args... ) ); }


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


// separator
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Separator , separator );

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Empty ){ static const string s = ""; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Escape ){ static const string s = "\\"; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Space ){ static const string s = " "; return s; }
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Sub , _ );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Sup , ^ );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lparen ){ static const string s = "("; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Rparen ){ static const string s = ")"; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lbrace ){ static const string s = "{"; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Rbrace ){ static const string s = "}"; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lbrack ){ static const string s = "["; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Rbrack ){ static const string s = "]"; return s; }
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Langle , \\langle );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Rangle , \\rangle );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Vert , \\mid );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Vvert , \\| );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Frac , \\frac );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lbig , \\left );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Mbig , \\middle );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Rbig , \\right );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Period ){ static const string s = "."; return s; }
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Comma ){ static const string s = ","; return s; }
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Colon , \\colon );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Scolon ){ static const string s = ";"; return s; }
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Atmark , @ );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Ast , \\ast );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Ldots , \\ldots );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Cdots , \\cdots );

// type
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Type , type );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Basic , basic );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( SubType , subtype );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( DirectProduct , DirectProduct );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Array , array );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Tree , tree );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Int , \\mathbb{Z} );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( String , \\textrm{String} );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Bool ){ static const string s = "\\{0,1\\}"; return s; }

// valid string
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Expression , expression );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Variable , variable );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Constant , constant );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Function , function );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Relation , relation );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Nest , nest );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( List , list );

// function
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

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Projection , \\textrm{Pr} );

// relation
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Eq , = );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Neq , \\neq );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Leq , \\leq );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Geq , \\geq );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lneq , < );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Gneq , > );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( In , \\in );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( NonNegative , \\geq 0 );

// line
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Line , line );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( If , if );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Put , put );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Print , print );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Exit , exit );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Return , return );

// write
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Japanese , Japanese );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( English , English );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( english , english );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Fandom , Fandom );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Jekyll , Jekyll );

