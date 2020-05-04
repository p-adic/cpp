// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/a_Macro.hpp

#pragma once

// constant
#define INFTY InftySymbol() 


// variable
#define LDOTS( V ) LdotsSymbol< V >()  


// function
#define OPERATOR_SYMBOL_CONSTRUCTOR( RET , NAME , ... )			\
									\
  TRY_CATCH								\
  (									\
									\
   OperatorSymbol_Guide<BaseTypeOf< RET >::type>::Get( TO_STRING( NAME ) , GetTypeName< RET >() , __VA_ARGS__ ) , \
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

#define LENGTH( a ) LengthSymbolApplication( a ) 
#define ENTRY( a , n ) EntryAccessSymbolApplication( a , n ) 
#define INISEG( a , n ) InitialSgmentSymbolApplication( a , n ) 
#define FINSEG( a , n ) FinalSgmentSymbolApplication( a , n ) 

#define PROJ( i , a ) ProjectionSymbolApplication< i >( a ) 

#define TUPLE( ... ) TupleSymbolApplication( __VA_ARGS__ ) 


// relation
#define EQ( x , y ) EqSymbolApplication( x , y ) 
#define NEQ( x , y ) NeqSymbolApplication( x , y ) 
#define LEQ( x , y ) LeqSymbolApplication( x , y ) 
#define GEQ( x , y ) GeqSymbolApplication( x , y ) 
#define LNEQ( x , y ) LneqSymbolApplication( x , y ) 
#define GNEQ( x , y ) GneqSymbolApplication( x , y ) 

#define NONNEG NonNegativeSymbol() 


// meta function
#define ARRAYISE( FUNC ) ArrayiseSymbol( FUNC ) 
#define CURRY( FUNC , ... ) CurryingSymbol( FUNC , __VA_ARGS__ ) 
#define EXISTS( VAR , REL ) ExistenceSymbol( VAR , FUNC ) 
#define UEXISTS( VAR , REL ) UniqueExistenceSymbol( VAR , FUNC ) 


// decraration
#define CHECK_VALID( TYPE_NAME )		\
						\
  if( ! IsValidType< TYPE_NAME >::value ){	\
						\
    MISMATCH( TYPE_NAME );			\
						\
  }						\



#define USE( TYPE_NAME , VARIABLE )					\
									\
  static VariableSymbol<BaseTypeOf< TYPE_NAME >::type> CONNECT( CONNECT( __SYMBOL_OF_ , VARIABLE ) , __ ) = VariableSymbol<BaseTypeOf< TYPE_NAME >::type>( TO_STRING( VARIABLE ) , GetTypeName< TYPE_NAME >() ); \
									\
  static const VariableSymbol<BaseTypeOf< TYPE_NAME >::type>& VARIABLE = CONNECT( CONNECT( __SYMBOL_OF_ , VARIABLE ) , __ ); \
									\
  CHECK_VALID( TYPE_NAME )						\
									\


#define IMP( RET , FUNC , ... )						\
									\
  static auto CONNECT( CONNECT( __SYMBOL_OF_ , FUNC ) , __ ) = OPERATOR_SYMBOL_CONSTRUCTOR( RET , FUNC , __VA_ARGS__ ); \
  static const decltype( CONNECT( CONNECT( __SYMBOL_OF_, FUNC ) , __ ) )& FUNC = CONNECT( CONNECT( __SYMBOL_OF_ , FUNC ) , __ ) \


// symbol setting
#define STR( SYMB ) TO_STRING( SYMB ) 

#define SYMBOL EmptyString() 

#define SET( OBJ , ... ) CONNECT( CONNECT( __SYMBOL_OF_, OBJ ) , __ ).Set( __VA_ARGS__ ) 

#define PLAIN( SYMB ) Plainise( STR( SYMB ) ) 

#define ROMANISE( OBJ ) CONNECT( CONNECT( __SYMBOL_OF_, OBJ ) , __ ).RomaniseSymbol() 


// separator setting
#define SYMBOLISE( FUNC ) FUNC.GetNodeString( 2 ) 
#define SPACE SpaceString() 
#define VSPACE VspaceString() 
#define SUB SubString()
#define SUP SupString() 
#define LPAREN LparenString() 
#define RPAREN RparenString() 
#define LBRACE LbraceString() 
#define RBRACE RbraceString() 
#define LBRACK LbrackString() 
#define RBRACK RbrackString() 
#define LANGLE LangleString() 
#define RANGLE RangleString() 
#define VERT VertString() 
#define VVERT VvertString() 
#define FRAC FracString() 
#define LBIG LbigString() 
#define MBIG MbigString() 
#define RBIG RbigString() 
#define PERIOD PeriodString() 
#define COMMA CommaString() 
#define COLON ColonString() 
#define SCOLON ScolonString() 
#define ATMARK AtmarkString() 
#define LMAT( C ) to_string( "\\begin{array}{" ) + TO_STRING( C ) + to_string( "}" ) 
#define RMAT to_string( "\\end{array}" ) 
#define ET to_string( "&" ) 
#define YY to_string( "\\\\" ) 
#define HLINE to_string( "\\hline" ) 
#define LVEC LMAT( c ) 
#define RVEC RMAT 

#define SEPARATOR SeparatorOfComputableFunction( 0 ) , 0 

  
// computability setting
#define PARTIAL PartialString() 
#define TOTAL TotalString() 
#define PRIMITIVE PrimitiveString() 

#define TOTALITY Recursiveness() 


// definition
#define DEF( FUNC )							\
									\
  const DefinitionOfOperator<remove_const<remove_reference<decltype( FUNC )>::type>::type> CONNECT( CONNECT( __DEFINITION_OF__ , FUNC ) , __ ) 

#define IF( ... )				\
						\
  IfLine( __VA_ARGS__ )				\
  
#define UNIQUE_BODY( CHAR , VAR , BOUND , COND ) CHAR , WrappedType<remove_const<remove_reference<decltype( VAR )>::type>::type>( VAR ) , WrappedType<remove_const<remove_reference<decltype( BOUND )>::type>::type>( BOUND ) , WrappedType<ConditionOfComputableFunction>( COND ) 

#define UNIQUE( VAR , BOUND , COND ) UNIQUE_BODY( UExistString() , VAR , BOUND , COND ) 
#define MIN( VAR , COND ) UNIQUE_BODY( MinString() , VAR , BOUND , COND ) 
#define MAX( VAR , BOUND , COND ) UNIQUE_BODY( MaxString() , VAR , BOUND , COND ) 


#define EXIT					\
						\
  LineOfDefinitionOfComputableFunction<void>()	\


#define RETURN( X )				\
						\
  ReturnLine( X )				\
  

// display
#define DISPLAY( OBJECT )						\
  									\
  cout << TO_STRING( OBJECT ) << " ‚Ì–Ø\‘¢‚ðo—Í‚µ‚Ü‚·F" << endl;	\
  cout << CONNECT( CONNECT( __SYMBOL_OF_, OBJECT ) , __ ).Display() << endl; \
  cout << endl;								\


// write
#define JAPANESE JapaneseString() 
#define ENGLISH EnglishString() 
#define FANDOM FandomString() 
#define APP ios::app 
#define TRUNC ios::trunc 

#define __DEFINITION_OF__int__ BaseType<int>() 
#define __DEFINITION_OF__string__ BaseType<string>() 
#define __DEFINITION_OF__bool__ BaseType<bool>() 

#define __SYMBOL_OF_int__ __DEFINITION_OF__int__ 
#define __SYMBOL_OF_string__ __DEFINITION_OF__string__ 
#define __SYMBOL_OF_bool__ __DEFINITION_OF__bool__ 

#define WRITE( FUNC , LANGUAGE , STYLE , FILE , OPEN_MODE ) CONNECT( CONNECT( __DEFINITION_OF__ , FUNC ) , __ ).WriteOn( CONNECT( CONNECT( __SYMBOL_OF_, FUNC ) , __ ) , LANGUAGE , STYLE , TO_STRING( FILE ) , OPEN_MODE );
