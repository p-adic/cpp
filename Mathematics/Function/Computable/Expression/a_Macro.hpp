// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/a_Macro.hpp

#pragma once

#define DECLARATION_OF_BASIC_FUNCTION( RET , OPERATOR )			\
									\
  inline ExpressionOfComputableFunction< RET > operator OPERATOR ( const ExpressionOfComputableFunction< RET >& e1 , const ExpressionOfComputableFunction< RET >& e2 ) \


#define DEFINITION_OF_BASIC_FUNCTION( RET , OPERATOR , SYMB )		\
									\
  DECLARATION_OF_BASIC_FUNCTION( RET , OPERATOR ){ return CONNECT( SYMB , SymbolApplication )( e1 , e2 ); } \
  
