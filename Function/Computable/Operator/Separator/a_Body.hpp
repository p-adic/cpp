// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Separator/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Syntax/a_Body.hpp"

SeparatorOfComputableFunction::SeparatorOfComputableFunction( const string& f , const uint& arity , const bool& variadic ) :
  SeparatorOfComputableFunction( 0 )
{

  VLTree<string>& t = Ref();

  t.push_RightMost( f + "( " );
  
  for( uint i = 1 ; i < arity ; i++ ){

    t.push_RightMost( " , " );

  }

  if( variadic ){

    t.push_RightMost( LdotsSymbol<void>().Get() );
    t.push_RightMost( " , " );

  }

  if( arity == 0 && ! variadic ){

    t.push_RightMost( ")" );

  } else {
    
    t.push_RightMost( " )" );

  }

}

template <typename... Args > inline SeparatorOfComputableFunction::SeparatorOfComputableFunction( const Dummy<Args...>& dummy , const Args&... args ) : SyntaxOfComputableFunction( SeparatorString() , args... ) {}
