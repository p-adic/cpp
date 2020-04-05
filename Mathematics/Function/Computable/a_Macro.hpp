// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/a_Macro.hpp

#pragma once

// constant
#define INFTY InftySymbol() 


// variable
#define LDOTS LdotsSymbol() 


// function
#define FUNCTION_SYMBOL_CONSTRUCTOR( RET , NAME , ... )			\
									\
  TRY_CATCH								\
  (									\
									\
   FunctionSymbol_Guide< RET >::Get( TO_STRING( NAME ) , __VA_ARGS__ ) , \
   const ErrorType& e ,							\
   CALL( e )								\
									\
									) \


#define PLUS( ... ) PlusSymbolApplication( __VA_ARGS__ ) 
#define TIMES( ... ) TimesSymbolApplication( __VA_ARGS__ ) 
#define MINUS( x , y ) MinusSymbolApplication( x , y ) 
#define SLASH( x , y ) SlashSymbolApplication( x , y ) 
#define MOD( x , y ) ModSymbolApplication( x , y ) 

#define NEG( x ) NegSymbolApplication( x ) 
#define LAND( ... ) LandSymbolApplication( __VA_ARGS__ ) 
#define LOR( ... ) LorSymbolApplication( __VA_ARGS__ ) 
#define TO( x , y ) ToSymbolApplication( x , y ) 
#define OT( x , y ) TO( y , x ) 
#define EQUIV( ... ) EquivSymbolApplication( __VA_ARGS__ ) 


// relation
#define EQ( x , y ) EqSymbolApplication( x , y ) 
#define NEQ( x , y ) NeqSymbolApplication( x , y ) 
#define LEQ( x , y ) LeqSymbolApplication( x , y ) 
#define GEQ( x , y ) GeqSymbolApplication( x , y ) 
#define LNEQ( x , y ) LneqSymbolApplication( x , y ) 
#define GNEQ( x , y ) GneqSymbolApplication( x , y ) 


// decraration
#define CHECK_VALID( TYPE )			\
						\
  if( ! IsValidType< TYPE >::value ){		\
						\
    MISMATCH( TYPE );				\
						\
  }						\



#define USE( TYPE , VARIABLE )						\
									\
  const VariableSymbol< TYPE > VARIABLE = VariableSymbol< TYPE >( TO_STRING( VARIABLE ) ); \
  CHECK_VALID( TYPE );							\
									\
  
#define IMP( RET , FUNC , ... )						\
									\
  const auto FUNC = FUNCTION_SYMBOL_CONSTRUCTOR( RET , FUNC , __VA_ARGS__ ) \
 
    
#define DEF( RET , FUNC , ... )						\
									\
  auto FUNC = FUNCTION_SYMBOL_CONSTRUCTOR( RET , FUNC , __VA_ARGS__ );	\
  auto& __THIS__ = FUNC							\
    

#define SYMB __THIS__.GetNodeString( 2 ) 

#define SUB to_string( "_" ) 

#define SUP to_string( "^" ) 

#define LPAREN to_string( "(" ) 

#define RPAREN to_string( ")" ) 

#define LBRACE to_string( "\\{" ) 

#define RBRACE to_string( "\\}" ) 

#define LBRACK to_string( "\\lbrack" ) 

#define RBRACK to_string( "\\rbrack" ) 

#define SPACE SpaceString() 

#define LBIG to_string( "\\left" ) 

#define MBIG to_string( "\\middle" ) 

#define RBIG to_string( "\\right" ) 

#define PERIOD to_string( "." ) 

#define COMMA to_string( "," ) 

#define COLON to_string( "\\colon" ) 

#define SEMICOLON to_string( ";" ) 

#define ATMARK to_string( "@" ) 

#define SEP( ... )				\
						\
  __THIS__.SetSeparator( __VA_ARGS__ );		\


// definition
#define BODY( ... )						\
								\
  const auto __DEFINITION__ = DefinitionOfComputableFunction( 0 , __THIS__ , __VA_ARGS__ ) \
  

#define IF( ... )				\
						\
  IfLine( __VA_ARGS__ )				\
  

#define EXIT					\
						\
  LineOfDefinitionOfComputableFunction<void>()	\


#define RETURN( X )				\
						\
  ReturnLine( X )				\
  

// display
#define DISPLAY __DEFINITION__.Display();
