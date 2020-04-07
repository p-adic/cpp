// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Variadic/a_Macro.hpp

#pragma once

#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( RET , FUNC )	\
									\
  inline const VariadicFunctionSymbol< RET , RET , RET >& CONNECT( FUNC , Symbol )() \
									\
    
#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( RET , FUNC ) \
									\
  inline ExpressionOfComputableFunction< RET > CONNECT( FUNC , SymbolApplication )( const ExpressionOfComputableFunction< RET >& e ) \
									\

#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( RET , FUNC ) \
									\
  ExpressionOfComputableFunction< RET > CONNECT( FUNC , SymbolApplication )( const ExpressionOfComputableFunction< RET >& e1 , const ExpressionOfComputableFunction< RET >& e2 ) \
									\

#define DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( RET , FUNC ) \
									\
  inline auto CONNECT( FUNC , SymbolApplication )( const ExpressionOfComputableFunction< RET >& e1 , const ExpressionOfComputableFunction< RET >& e2 , const ExpressionOfComputableFunction< RET >& e3 , const Args&... args ) \
									\

#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( RET , FUNC , OPERATOR )	\
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( RET , FUNC ){ static const VariadicFunctionSymbol< RET , RET , RET > f( CONNECT( OPERATOR , String )() , SeparatorOfComputableFunction( 0 , EmptyString() , LdotsString() , SpaceString() + CONNECT( OPERATOR , String )() + SpaceString() , EmptyString() ) , VariableSymbol< RET >( "x" ) ); return f; } \


#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( RET , FUNC ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( RET , FUNC ){ return e; } \
									\
  

#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( RET , FUNC , SYMBOL , IDENTITY , ZERO ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( RET , FUNC ) \
  {									\
									\
    const string identity = TO_STRING( IDENTITY );			\
    const string zero = TO_STRING( ZERO );				\
									\
    const string& name1 = e1.GetNodeString( 2 );			\
									\
    if( name1 == identity ){						\
									\
      return e2;							\
									\
    }									\
									\
    if( name1 == zero ){						\
									\
      return e1;							\
									\
    }									\
									\
    const string& name2 = e2.GetNodeString( 2 );			\
									\
    if( name2 == identity ){						\
									\
      return e1;							\
									\
    }									\
									\
    if( name2 == zero ){						\
									\
      return e2;							\
									\
    }									\
									\
									\
    const string func = TO_STRING( FUNC );				\
    									\
    if( e1.GetNodeString( 5 ) == func ){				\
									\
      auto e1_copy = e1;						\
      VLTree<string>& t1 = e1_copy.Ref();				\
      VLSubTree<string> t1_sub = t1.RightMostSubTree();			\
      const VLTree<string>& t2 = e2.Get();				\
									\
      if( e2.GetNodeString( 5 ) == func ){				\
									\
	auto itr = t2.LeftMostNode();					\
	itr++;								\
	itr++;								\
	itr++;								\
	t1_sub.push_RightMost( t2.GetBranchCopy( itr ) );		\
	itr++;								\
	itr[2];								\
									\
	while( itr.IsValid() ){						\
									\
	  t1_sub.push_RightMost( t2.GetBranchCopy( itr ) );		\
									\
	}								\
									\
      } else {								\
									\
	t1_sub.push_RightMost( t2 );					\
									\
      }									\
									\
      return e1_copy;							\
									\
    }									\
									\
    if( name2 == func ){						\
									\
      auto e2_copy = e2;						\
      const VLTree<string>& t1 = e1.Get();				\
      VLTree<string>& t2 = e2_copy.Ref();				\
      VLSubTree<string> t2_sub = t2.RightMostSubTree();			\
      auto itr = t2_sub.LeftMostNode();					\
      itr++;								\
      itr++;								\
      t2_sub.insert( itr , EmptyString() );				\
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
  

#define DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( RET , FUNC ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( RET , FUNC ){ return CONNECT( FUNC , SymbolApplication )( e1 , CONNECT( FUNC , SYMBOL_APPLICATION )( e2 , e3 , args... ) ); } \
									\
  

#define DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE( FUNC )	\
								\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( bool , FUNC )	\
								\
    
#define DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( FUNC ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( bool , FUNC ) \
    

#define DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_TWO( FUNC ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( bool , FUNC ) \
    

#define DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( FUNC ) \
									\
  template <typename... Args> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( bool , FUNC ) \
    

#define DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ALL( FUNC ) \
									\
  DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( FUNC );	\
  DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_TWO( FUNC );	\
  DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( FUNC )	\


#define DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE( FUNC )	\
								\
  DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( bool , FUNC , FUNC )	\
								\
    
#define DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( FUNC ) \
									\
  DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( bool , FUNC ) \
    

#define DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_TWO( FUNC , IDENTITY , ZERO ) \
									\
  DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( bool , FUNC , Symbol , IDENTITY , ZERO ) \
    

#define DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( FUNC ) \
									\
  template <typename... Args> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( bool , FUNC ) \
    

