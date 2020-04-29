// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Relation/a_Macro.hpp

#pragma once
#include "../../../../../Utility/Macro.hpp"


// 2-ary
#define DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( RET , REL )		\
									\
  inline auto CONNECT( REL , Symbol )() -> typename enable_if<! is_same< RET , bool >::value , const RelationSymbol< RET , RET >& >::type \
									\

#define DEFINITION_OF_TWO_ARY_RELATION_SYMBOL( RET , REL )		\
									\
  DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( RET , REL )			\
  {									\
									\
    static const RelationSymbol< RET , RET > r				\
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
	VariableSymbol< RET >( "x" ) ,					\
	VariableSymbol< RET >( "y" )					\
									\
	};								\
									\
    return r;								\
									\
  }									\
									\


#define DECLARATION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( RET , REL )	\
									\
  inline ConditionOfComputableFunction CONNECT( REL , SymbolApplication )( const ExpressionOfComputableFunction< RET >& e1 , const ExpressionOfComputableFunction< RET >& e2 ) \
									\

#define DEFINITION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( RET , REL , SYMBOL )	\
									\
  DECLARATION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( RET , REL ){ return CONNECT( REL , SYMBOL )()( e1 , e2 ); } \
  
