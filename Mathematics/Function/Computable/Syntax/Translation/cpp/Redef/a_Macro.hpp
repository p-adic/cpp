// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Redef/a_Macro.hpp

#pragma once


// expression
#define SUGAR( CONST , x )						\
									\
  __SYMBOL_OF_OFS__() << "#define " << TO_STRING( CONST ) << " " << x.GetTermString() << " " << endl; \
									\
  const CppClassForString& CONST = x					\
									\

// variable
#define LDOTS( V ) LdotsSymbol<BaseTypeOf< V >::type>() 


// function
#define PLUS( ... ) PlusStringApplication( __VA_ARGS__ ) 
#define TIMES( ... ) TimesStringApplication( __VA_ARGS__ ) 
#define MINUS( x , y ) MinusStringApplication( x , y ) 
#define SLASH( x , y ) SlashStringApplication( x , y ) 
#define MOD( x , y ) ModStringApplication( x , y ) 
#define POWER( x , y ) PowerStringApplication( x , y ) 

#define NEG( x ) NegStringApplication( x ) 
#define LAND( ... ) LandStringApplication( __VA_ARGS__ ) 
#define LOR( ... ) LorStringApplication( __VA_ARGS__ ) 
#define TO( x , y ) ToStringApplication( x , y ) 
#define OT( x , y ) TO( y , x ) 
#define EQUIV( ... ) EquivStringApplication( __VA_ARGS__ ) 

#define STRINGISE( n ) StringiseStringApplication( n ) 
#define LENGTH( a ) LengthStringApplication( a ) 
#define ENTRY( a , n ) EntryAccessStringApplication( a , n ) 
#define INISEG( a , n ) InitialSegmentStringApplication( a , n ) 
#define FINSEG( a , n ) FinalSegmentStringApplication( a , n ) 

#define PROJ( i , a ) ProjectionStringApplication< i >( a ) 

#define WRAP( x ) WrapStringApplication( x ) 
#define NWRAP( a ) NestedWrapStringApplication( a ) 
#define NESTIFY( a ) NestifyStringApplication( a ) 

#define TUPLE( x , ... ) TupleStringApplication( x , __VA_ARGS__ ) 

#define ENNEST( x ) ToTrivialNestedArrayStringApplication( x ) 
#define DENEST( a ) RemoveNestedArrayStringApplication( a ) 
#define DENESTABLE( a ) RemovableNestedArrayStringApplication( a ) 


// relation
#define EQ( x , y ) EqStringApplication( x , y ) 
#define NEQ( x , y ) NeqStringApplication( x , y ) 
#define LEQ( x , y ) LeqStringApplication( x , y ) 
#define GEQ( x , y ) GeqStringApplication( x , y ) 
#define LNEQ( x , y ) LneqStringApplication( x , y ) 
#define GNEQ( x , y ) GneqStringApplication( x , y ) 

#define NONNEG( n ) NonNegativeStringApplication( n ) 


// meta function
#define ARRAYISE( FUNC , VAR ) ArrayiseStringApplication( FUNC ) 
#define CURRY( FUNC , ... ) CurryingStringApplication( FUNC , __VA_ARGS__ ) 
// #define EXISTS( VAR , REL ) ExistenceString( VAR , FUNC ) Not Yet
//#define UEXISTS( VAR , REL ) UniqueExistenceString( VAR , FUNC ) Not Yet


// // decraration
#define USE( TYPE_NAME , VARIABLE )					\
									\
  const CppClassForString VARIABLE{ TypeString<BaseTypeOf< TYPE_NAME >::type>() , TO_STRING( VARIABLE ) }; \
  const VariableSymbol< TYPE_NAME > CONNECT( CONNECT( __SYMBOL_OF_ , VARIABLE ) , __ )( TO_STRING( VARIABLE ) ); \
									\
  __SYMBOL_OF_OFS__() << "// " << TO_STRING( VARIABLE ) << "への代入を行うPUT文をQpでの定義文内に含む演算子、すなわち\"" <<  TO_STRING( VARIABLE ) << " = \"という代入演算子の適用をc++への翻訳後の定義文に含む演算子は、c++への翻訳後の定義文の冒頭に次の１行を手動でコピー＆ペーストしそのコメントアウトを解除し改行する：" << endl; \
  __SYMBOL_OF_OFS__() << "// " << TypeString<BaseTypeOf< TYPE_NAME >::type>() << " " << TO_STRING( VARIABLE ) << ";" << endl << endl; \

  
#define IMP( RET , FUNC , ... )						\
									\
  __SYMBOL_OF_OFS__() << "#define " << TO_STRING( CONNECT( CONNECT( __DECLARATION_OF_ , FUNC ) , __ ) ) << " " << TypeString<BaseTypeOf< RET >::type>() << " " << TO_STRING( FUNC ) << "( " << TypeAndArgumentString( __VA_ARGS__ ) << " ) " << endl << endl; \
  __SYMBOL_OF_OFS__() << TO_STRING( CONNECT( CONNECT( __DECLARATION_OF_ , FUNC ) , __ ) ) << ";" << endl << endl; \
									\
  const CppClassForFunctionString FUNC { TO_STRING( FUNC ) }		\

// symbol setting
#define STR EmptyString()

#define SYMBOL EmptyString()

#define SET( OBJ , ... ) 

#define PLAIN( SYMB ) EmptyString()

#define ROMANISE( OBJ ) 


// separator setting
#define SYMBOLISE( FUNC ) EmptyString()
#define EMPTY EmptyString()
#define ESCAPE EmptyString()
#define SPACE EmptyString()
#define SUB EmptyString()
#define SUP EmptyString()
#define LPAREN EmptyString()
#define RPAREN EmptyString()
#define LBRACE EmptyString()
#define RBRACE EmptyString()
#define LBRACK EmptyString()
#define RBRACK EmptyString()
#define LANGLE EmptyString()
#define RANGLE EmptyString()
#define VERT EmptyString()
#define VVERT EmptyString()
#define FRAC EmptyString()
#define LBIG EmptyString()
#define MBIG EmptyString()
#define RBIG EmptyString()
#define PERIOD EmptyString()
#define COMMA EmptyString()
#define COLON EmptyString()
#define SCOLON EmptyString()
#define ATMARK EmptyString()
#define LMAT( C ) EmptyString()
#define RMAT EmptyString()
#define ET EmptyString()
#define YY EmptyString()
#define HLINE EmptyString()
#define LVEC EmptyString()
#define RVEC EmptyString()

#define SEPARATOR EmptyString()

  
// computability setting
#define PARTIAL EmptyString()
#define TOTAL EmptyString() 
#define PRIMITIVE EmptyString()

#define TOTALITY EmptyString()


// definition
#define DEF( FUNC )							\
									\
  __SYMBOL_OF_OFS__() << TO_STRING( CONNECT( CONNECT( __DECLARATION_OF_ , FUNC ) , __ ) ) << endl; \
  CppClassForOfstream::type CONNECT( CONNECT( __DEFINITION_OF_ , FUNC ) , __ ) \
									\


#define IF( ... ) IfStringApplication( __VA_ARGS__ ) 

#define PUT( ... ) PutStringApplication( __VA_ARGS__ ) 
// #define UNIQUE( VAR , BOUND , COND ) UniqueStringApplication( VAR , BOUND , COND ) Not Yet
// #define MIN( VAR , COND ) MinStringApplication( VAR , COND ) Not Yet
// #define MAX( VAR , BOUND , COND ) MaxStringApplication( VAR , BOUND , COND ) Not Yet

#define PRINT( ... ) PrintStringApplication( __VA_ARGS__ ) 
  
#define EXIT ExitStringApplication() 

#define RETURN( X ) ReturnStringApplication( X )	
  

// display
#define DISPLAY( OBJECT , LANGUAGE ) 

// write
#define JAPANESE EmptyString() 
#define ENGLISH EmptyString() 
#define CHINESE EmptyString() 
#define FRENCH EmptyString() 
#define GERMAN EmptyString() 

#define FANDOM EmptyString() 

#define APP ios::app 
#define TRUNC ios::trunc 

#define WRITE( FUNC , LANGUAGE , STYLE , FILE , OPEN_MODE ) 
