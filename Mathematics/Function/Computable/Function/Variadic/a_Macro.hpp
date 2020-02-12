// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Variadic/a_Macro.hpp

#pragma once

#define PLUS( ... ) PlusSymbolApplication( __VA_ARGS__ ) 
#define TIMES( ... ) TimesSymbolApplication( __VA_ARGS__ ) 

#define LAND( ... ) LandSymbolApplication( __VA_ARGS__ ) 
#define LOR( ... ) LorSymbolApplication( __VA_ARGS__ ) 
#define EQUIV( ... ) EquivSymbolApplication( __VA_ARGS__ ) 


#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_BODY( RET , FUNC )	\
									\
  const VariadicFunctionSymbol< RET , RET >& CONNECT( FUNC , Symbol )() \
									\
    
#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE_BODY( RET , FUNC ) \
									\
  inline ExpressionOfComputableFunction< RET > CONNECT( FUNC , SymbolApplication )( const ExpressionOfComputableFunction< RET >& e ) \
									\

#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO_BODY( RET , FUNC ) \
									\
  ExpressionOfComputableFunction< RET > CONNECT( FUNC , SymbolApplication )( const ExpressionOfComputableFunction< RET >& e1 , const ExpressionOfComputableFunction< RET >& e2 ) \
									\

#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE_BODY( RET , FUNC ) \
									\
  inline auto CONNECT( FUNC , SymbolApplication )( const ExpressionOfComputableFunction< RET >& e1 , const ExpressionOfComputableFunction< RET >& e2 , const ExpressionOfComputableFunction< RET >& e3 , const Args&... args ) \
									\

#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_BODY( RET , FUNC )	\
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_BODY( RET , FUNC )		\
  {									\
									\
    static const VariadicFunctionSymbol< RET , RET > f( TO_STRING( FUNC ) , VariableSymbol< RET >( "x" ) ); \
    return f;								\
									\
  }									\
									\
  
#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE_BODY( RET , FUNC ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE_BODY( RET , FUNC ){ return e; } \
									\
  

#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO_BODY( RET , FUNC , SYMBOL , TRIV ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO_BODY( RET , FUNC ) \
  {									\
									\
    const string& name1 = e1.Name();					\
									\
    if( name1 == TO_STRING( TRIV ) ){					\
									\
      return e2;							\
									\
    }									\
									\
    const string& name2 = e2.Name();					\
									\
    if( name2 == TO_STRING( TRIV ) ){					\
									\
      return e1;							\
									\
    }									\
									\
    if( name1 == TO_STRING( FUNC ) ){					\
									\
      auto e1_copy = e1;						\
      VLTree<string>& t1 = e1_copy.Ref();				\
      const VLTree<string>& t2 = e2.Get();				\
									\
      if( name2 == TO_STRING( FUNC ) ){					\
									\
	auto itr = t2.LeftMostNode();					\
	itr++;								\
	itr++;								\
	itr++;								\
									\
	while( itr.IsValid() ){						\
									\
	  t1.push_RightMost( *itr );					\
	  itr++;							\
									\
	}								\
									\
      } else {								\
									\
	t1.push_RightMost( t2 );					\
									\
      }									\
									\
      return e1_copy;							\
									\
    }									\
									\
    if( name2 == TO_STRING( FUNC ) ){					\
									\
      auto e2_copy = e2;						\
      const VLTree<string>& t1 = e1.Get();				\
      VLTree<string>& t2 = e2_copy.Ref();				\
      auto itr = t2.LeftMostNode();					\
      itr++;								\
      itr++;								\
      t2.Concatenate( itr , t1 );					\
									\
      return e2_copy;							\
									\
    }									\
									\
    return CONNECT( FUNC , SYMBOL )()( e1 , e2 );			\
									\
  }									\
									\
  

#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE_BODY( RET , FUNC , TRIV ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE_BODY( RET , FUNC ){ return CONNECT( FUNC , SymbolApplication )( e1 , CONNECT( FUNC , SYMBOL_APPLICATION )( e2 , e3 , args... ) ); } \
									\
  

#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( FUNC )			\
									\
  template <typename Ret> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_BODY( Ret , FUNC ) \
									\
    
#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( FUNC )	\
									\
  template <typename Ret> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE_BODY( Ret , FUNC ) \
    

#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( FUNC )	\
									\
  template <typename Ret> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO_BODY( Ret , FUNC ) \
    

#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( FUNC ) \
									\
  template <typename Ret, typename... Args> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE_BODY( Ret , FUNC ) \
    

#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ALL( FUNC ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( FUNC );	\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( FUNC );	\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( FUNC )	\


#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( FUNC )			\
									\
  template <typename Ret> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_BODY( Ret , FUNC ) \
									\
    
#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( FUNC )	\
									\
  template <typename Ret> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE_BODY( Ret , FUNC ) \
    

#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( FUNC , TRIV ) \
									\
  template <typename Ret> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO_BODY( Ret , FUNC , Symbol<Ret> , TRIV ) \


#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( FUNC , TRIV ) \
									\
  template <typename Ret, typename... Args> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE_BODY( Ret , FUNC , TRIV ) \


#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE_MORE( FUNC , TRIV ) \
									\
  DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( FUNC );	\
  DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( FUNC , TRIV ) \


#define DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE( FUNC )	\
								\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_BODY( bool , FUNC )	\
								\
    
#define DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( FUNC ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE_BODY( bool , FUNC ) \
    

#define DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_TWO( FUNC ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO_BODY( bool , FUNC ) \
    

#define DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( FUNC ) \
									\
  template <typename... Args> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE_BODY( bool , FUNC ) \
    

#define DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ALL( FUNC ) \
									\
  DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( FUNC );	\
  DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_TWO( FUNC );	\
  DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( FUNC )	\


#define DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE( FUNC )	\
								\
  DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_BODY( bool , FUNC )	\
								\
    
#define DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( FUNC ) \
									\
  DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE_BODY( bool , FUNC ) \
    

#define DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_TWO( FUNC , TRIV ) \
									\
  DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO_BODY( bool , FUNC , Symbol , TRIV ) \
    

#define DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( FUNC , TRIV ) \
									\
  template <typename... Args> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE_BODY( bool , FUNC , TRIV ) \
    

#define DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE_MORE( FUNC , TRIV ) \
									\
  DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( FUNC );	\
  DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( FUNC , TRIV ) \

