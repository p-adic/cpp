// MemberFunction/Operator/a_Macro.hpp

#pragma once
#include "../../a_Macro.hpp"

#define DEFINITION_OF_HAS_MEMBER_OPERATOR_( Oper , eq )			\
									\
  template <typename T>							\
  class CONNECT( callable_member_operator_ , Oper ) :			\
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename U>						\
    static auto Check( U&& u1 , const U& u2 ) -> typename enable_if< is_same< decltype( u1 eq u2 ) , U& >::value , true_type >::type; \
									\
    template <typename U>						\
    static auto Check( U&& u1 , const U& u2 ) -> typename enable_if< ! ( is_same< decltype( u1 eq u2 ) , U& >::value ) , false_type >::type; \
									\
  public:								\
    static const bool value = decltype( Check<T>( declval<T>() , declval<T>() ) )::value; \
    									\
  };									\
  									\

#define VALUE_MEMBER_OPERATOR_VALID( Oper )			\
  ( CONNECT( callable_member_operator_ , Oper )<T> ::value ) 

#define VALUE_MEMBER_OPERATOR_INVALID( Oper )	\
  ( ! VALUE_MEMBER_OPERATOR_VALID( Oper ) ) 

#define TYPE_ALIAS_FOR_MEMBER_OPERATOR_VALID( Oper )			\
									\
  template <typename T>							\
  using CONNECT( CONNECT( Valid_ , Oper ) , _Extended ) = enable_if< VALUE_MEMBER_OPERATOR_VALID( Oper ) , T& >; \
									\

#define TYPE_ALIAS_FOR_MEMBER_OPERATOR_INVALID( Oper )			\
									\
  template <typename T>							\
  using CONNECT( CONNECT( Invalid_ , Oper ) , _Extended ) = enable_if< VALUE_MEMBER_OPERATOR_INVALID( Oper ) , T& >; \
									\

#define TYPE_OF_MEMBER_OPERATOR_VALID( Oper )				\
  typename CONNECT( CONNECT( Valid_ , Oper ) , _Extended )<T> ::type 

#define TYPE_OF_MEMBER_OPERATOR_INVALID( Oper )				\
  typename CONNECT( CONNECT( Invalid_ , Oper ) , _Extended )<T> ::type 

#define DECLARATION_OF_MEMBER_OPERATOR_VALID( Oper )			\
 									\
  template <typename T> TYPE_OF_MEMBER_OPERATOR_VALID( Oper ) ( Oper )( T& t1 , const T& t2 ) 

#define DECLARATION_OF_MEMBER_OPERATOR_INVALID( Oper )			\
									\
  template <typename T> TYPE_OF_MEMBER_OPERATOR_INVALID( Oper ) ( Oper )( T& t1 , const T& t2 ) 

#define DEFINITION_OF_MEMBER_OPERATOR_VALID( Oper , eq )	\
								\
  DECLARATION_OF_MEMBER_OPERATOR_VALID( Oper )			\
  {								\
								\
    return t1 eq t2;						\
								\
  }								\
								\

#define DEFINITION_OF_MEMBER_OPERATOR_INVALID( Oper )	\
 							\
  DECLARATION_OF_MEMBER_OPERATOR_INVALID( Oper )	\
  {							\
							\
    ERR_IMPUT( typeid( T ) );				\
    return t1;						\
							\
  }							\
							\
  
#define TWO_WAYS_SFINAE_MEMBER_OPERATOR_ALIAS( Oper , eq )	\
								\
  DEFINITION_OF_HAS_MEMBER_OPERATOR_( Oper , eq );		\
  TYPE_ALIAS_FOR_MEMBER_OPERATOR_VALID( Oper );			\
  TYPE_ALIAS_FOR_MEMBER_OPERATOR_INVALID( Oper ) 

#define TWO_WAYS_SFINAE_MEMBER_OPERATOR( Oper )	\
						\
  DECLARATION_OF_MEMBER_OPERATOR_VALID( Oper );	\
  DECLARATION_OF_MEMBER_OPERATOR_INVALID( Oper ) 

#define TWO_WAYS_SFINAE_MEMBER_OPERATOR_BODY( Oper , eq )	\
								\
  DEFINITION_OF_MEMBER_OPERATOR_VALID( Oper , eq );		\
  DEFINITION_OF_MEMBER_OPERATOR_INVALID( Oper ) 
