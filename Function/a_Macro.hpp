// c:/Users/user/Documents/Programming/Mathematics/Function/a_Macro.hpp

#pragma once
#include "../../Utility/String/a_Macro.hpp"

#define DECLARATION_OF_ITERATED_COMPOSITION_FOR_NON_MEMBER_FUNCTION( FUNCTION ) \
  template <typename Arg , typename U> inline Arg Iteration( const CONNECT( FUNCTION , PointerType )<Arg,Arg>& f , const U& num , const Arg& arg ) 

#define DECLARATION_OF_ITERATED_COMPOSITION_FOR_MEMBER_FUNCTION( MEMBER_FUNCTION ) \
  template <typename T , typename Arg , typename U> inline Arg Iteration( const T& class_object , const CONNECT( MEMBER_FUNCTION , PointerType )<Arg,T,Arg>& f , const U& num , const Arg& arg ) 


#define DEFINITION_OF_ITERATED_COMPOSITION_FOR_NON_MEMBER_FUNCTION( FUNCTION ) \
  DECLARATION_OF_ITERATED_COMPOSITION_FOR_NON_MEMBER_FUNCTION( FUNCTION ) \
  { return num == 0 ? arg : ( *f )( Iteration( f , num - 1 , arg ) ); } \


#define DEFINITION_OF_ITERATED_COMPOSITION_FOR_MEMBER_FUNCTION( FUNCTION ) \
  DECLARATION_OF_ITERATED_COMPOSITION_FOR_MEMBER_FUNCTION( FUNCTION ) \
  { return num == 0 ? arg : ( class_object.*f )( Iteration( f , num - 1 , arg ) ); } \

