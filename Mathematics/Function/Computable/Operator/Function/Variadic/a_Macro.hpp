// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Function/Variadic/a_Macro.hpp

#pragma once

#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( RET , FUNC )		\
									\
  const VariadicFunctionSymbol< RET , RET , RET >& CONNECT( FUNC , Symbol )() \
									\
    
#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( RET , FUNC ) \
									\
  ExpressionOfComputableFunction< RET > CONNECT( FUNC , SymbolApplication )( const ExpressionOfComputableFunction< RET >& e ) \
									\

#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( RET , FUNC ) \
									\
  auto CONNECT( FUNC , SymbolApplication )( const ExpressionOfComputableFunction< RET >& e1 , const ExpressionOfComputableFunction< RET >& e2 , const ExpressionOfComputableFunction<Args>&... args ) -> typename enable_if<conjunction<is_same<Args, RET >...>::value,ExpressionOfComputableFunction< RET > >::type \
									\

#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( RET , FUNC , OPERATOR )	\
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( RET , FUNC )			\
  {									\
    static const VariadicFunctionSymbol< typename BaseTypeOf< RET >::type , typename BaseTypeOf< RET >::type , typename BaseTypeOf< RET >::type > f \
      (									\
									\
       CONNECT( OPERATOR , String )() ,					\
       SeparatorOfComputableFunction					\
       (								\
									\
	0 ,								\
	EmptyString() ,							\
	LdotsString() ,							\
	SpaceString() + CONNECT( OPERATOR , String )() + SpaceString() , \
	EmptyString()							\
									\
										) , \
       GetTypeName< RET >() ,						\
       VariableSymbol<typename BaseTypeOf< RET >::type>( "x" , GetTypeName< RET >() ) \
									\
									); \
									\
    return f;								\
									\
  }									\


#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( RET , FUNC ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( RET , FUNC ){ return e; } \
									\
  
#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( RET , FUNC , SYMBOL ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( RET , FUNC ){ return CONNECT( FUNC , SYMBOL )()( e1 , e2 , args... ); } \
									\
  
