// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/a_Macro.hpp

#pragma once
#include "../../../../Utility/Macro.hpp"

// 1-ary
#define DECLARATION_OF_ONE_ARY_RELATION_SYMBOL( RET , REL )		\
									\
  inline auto CONNECT( REL , Symbol )() -> typename enable_if<! is_same< RET , bool >::value , const RelationSymbol<typename BaseTypeOf< RET >::type>& >::type \
									\

#define DECLARATION_OF_ONE_ARY_RELATION_SYMBOL_APPLICATION( RET , REL )	\
									\
  inline ConditionOfComputableFunction CONNECT( REL , SymbolApplication )( const ExpressionOfComputableFunction< RET >& e ) \
									\

#define DEFINITION_OF_ONE_ARY_RELATION_SYMBOL_APPLICATION( RET , REL , SYMBOL )	\
									\
  DECLARATION_OF_ONE_ARY_RELATION_SYMBOL_APPLICATION( RET , REL ){ return CONNECT( REL , SYMBOL )()( e ); } \
  

// 2-ary
#define DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( RET , REL )		\
									\
  inline auto CONNECT( REL , Symbol )() -> typename enable_if<! is_same< RET , bool >::value , const RelationSymbol<typename BaseTypeOf< RET >::type,typename BaseTypeOf< RET >::type>& >::type \
									\

#define DEFINITION_OF_TWO_ARY_RELATION_SYMBOL( RET , REL )		\
									\
  DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( RET , REL )			\
  {									\
									\
    static const RelationSymbol<typename BaseTypeOf< RET >::type,typename BaseTypeOf< RET >::type> r \
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
	VariableSymbol<typename BaseTypeOf< RET >::type>( "x" , GetTypeName< RET >() ) , \
	VariableSymbol<typename BaseTypeOf< RET >::type>( "y" , GetTypeName< RET >() ) \
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
  
