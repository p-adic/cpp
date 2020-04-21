// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/a_Macro.hpp

#pragma once
#include "../../../../Utility/Macro.hpp"

#define DECLARATION_OF_RELATION_SYMBOL( REL )				\
									\
  template <typename Ret> auto CONNECT( REL , Symbol )() -> typename enable_if<! is_same<Ret,bool>::value , const RelationSymbol<Ret,Ret>& >::type \
									\

#define DEFINITION_OF_RELATION_SYMBOL( REL )				\
									\
  DECLARATION_OF_RELATION_SYMBOL( REL )					\
  {									\
									\
    static const RelationSymbol<typename BaseTypeOf<Ret>::type,typename BaseTypeOf<Ret>::type> r \
    {									\
									\
      CONNECT( REL , String )() ,					\
	SeparatorOfComputableFunction					\
	(								\
									\
	 0 ,								\
	 EmptyString() ,						\
	 SpaceString() + CONNECT( REL , String )() + SpaceString() ,	\
	 EmptyString()							\
									\
									) , \
	GetTypeName<bool>() ,						\
	VariableSymbol<typename BaseTypeOf<Ret>::type>( "x" , GetTypeName<Ret>() ) , \
	VariableSymbol<typename BaseTypeOf<Ret>::type>( "y" , GetTypeName<Ret>() ) , \
	};								\
									\
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
  
