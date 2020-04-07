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
#define POWER( x , y ) PowerSymbolApplication( x , y ) 

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
  VariableSymbol< TYPE > CONNECT( CONNECT( __SYMBOL_OF_ , VARIABLE ) , __ ) = VariableSymbol< TYPE >( TO_STRING( VARIABLE ) ); \
  const VariableSymbol< TYPE >& VARIABLE = CONNECT( CONNECT( __SYMBOL_OF_ , VARIABLE ) , __ ); \
  CHECK_VALID( TYPE )							\
									\
  
#define IMP( RET , FUNC , ... )						\
									\
  auto CONNECT( CONNECT( __SYMBOL_OF_ , FUNC ) , __ ) = FUNCTION_SYMBOL_CONSTRUCTOR( RET , FUNC , __VA_ARGS__ ); \
  const decltype( CONNECT( CONNECT( __SYMBOL_OF_ , FUNC ) , __ ) )& FUNC = CONNECT( CONNECT( __SYMBOL_OF_ , FUNC ) , __ ) \


// symbol setting
#define STR( SYMB ) TO_STRING( SYMB ) 

#define SET( OBJ , SYMB ) CONNECT( CONNECT( __SYMBOL_OF_ , OBJ ) , __ ).SetSymbol( STR( SYMB ) ) 

#define PLAIN( SYMB ) Plainise( STR( SYMB ) ) 

#define ROMANISE( OBJ ) CONNECT( CONNECT( __SYMBOL_OF_ , OBJ ) , __ ).RomaniseSymbol() 


// separator setting
#define SYMB( FUNC ) FUNC.GetNodeString( 2 ) 
#define SPACE SpaceString() 
#define VSPACE to_string( "\\ " ) 
#define SUB SubString()
#define SUP SupString() 
#define LPAREN LparenString() 
#define RPAREN RparenString() 
#define LBRACE LbraceString() 
#define RBRACE RbraceString() 
#define LBRACK LbrackString() 
#define RBRACK RbrackString() 
#define LANGLE to_string( "\\langle" ) 
#define RANGLE to_string( "\\rangle" ) 
#define VERT to_string( "\mid" ) 
#define VVERT to_string( "\|" ) 
#define FRAC to_string( "\\frac" ) 
#define LBIG to_string( "\\left" ) 
#define MBIG to_string( "\\middle" ) 
#define RBIG to_string( "\\right" ) 
#define PERIOD to_string( "." ) 
#define COMMA CommaString() 
#define COLON to_string( "\\colon" ) 
#define SCOLON to_string( ";" ) 
#define ATMARK to_string( "@" ) 
#define LMAT( C ) to_string( "\\begin{array}{" ) + TO_STRING( C ) + to_string( "}" ) 
#define RMAT to_string( "\\end{array}" ) 
#define ET to_string( "&" ) 
#define YY to_string( "\\\\" ) 
#define HLINE to_string( "\\hline" ) 
#define LVEC LMAT( c ) 
#define RVEC RMAT 


#define SEP( FUNC , ... )			\
						\
  CONNECT( CONNECT( __SYMBOL_OF_ , FUNC ) , __ ).SetSeparator( __VA_ARGS__ );		\


// definition
#define DEF( FUNC )							\
									\
  const decltype( DefinitionOfComputableFunction( FUNC ) ) CONNECT( __DEFINITION_OF__ , FUNC )

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
#define DISPLAY( FUNC , FILE ) CONNECT( __DEFINITION_OF__ , FUNC ).Display( FUNC , TO_STRING( FILE ) );
