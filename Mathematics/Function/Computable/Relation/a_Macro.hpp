// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/a_Macro.hpp

#pragma once
#include "../../../../Utility/Macro.hpp"

#define DECLARATION_OF_RELATION_SYMBOL( REL )				\
									\
  template <typename Ret> const RelationSymbol<Ret,Ret>& CONNECT( REL , Symbol )() \
									\

#define DEFINITION_OF_RELATION_SYMBOL( REL , NAME )			\
									\
  DECLARATION_OF_RELATION_SYMBOL( REL )					\
  {									\
									\
    static const RelationSymbol<Ret,Ret> r( TO_STRING( NAME ) , SeparatorOfComputableFunction( 0 , to_string( "" ) , " " + CONNECT( REL , String )() + " " , to_string( "" ) ) , VariableSymbol<Ret>( "x" ) , VariableSymbol<Ret>( "y" ) ); \
    return r;								\
									\
  }									\
									\
  
#define DECLARATION_OF_RELATION_SYMBOL_APPLICATION( REL )		\
									\
  template <typename Ret> inline ConditionOfComputableFunction CONNECT( REL , SymbolApplication )( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ) \
									\

#define DEFINITION_OF_RELATION_SYMBOL_APPLICATION( REL )		\
									\
  DECLARATION_OF_RELATION_SYMBOL_APPLICATION( REL ){ return CONNECT( REL , Symbol )<Ret>()( e1 , e2 ); } \
  
