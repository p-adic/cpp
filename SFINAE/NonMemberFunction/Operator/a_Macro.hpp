// c:/Users/user/Documents/Programming/SFINAE/NonMemberFunction/Operator/a_Macro.hpp

#pragma once
#include "../../a_Macro.hpp"

#define DEFINITION_OF_CALLABLE_NON_MEMBER_OPERATOR_( Oper , eq )	\
									\
  template <typename T>							\
  class CONNECT( callable_non_member_operator_ , Oper ) :		\
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename U>						\
    static auto Check( const U& u1 , const U& u2 ) -> decltype( ( u1 eq u2 ) , true_type() ); \
									\
    template <typename U>						\
    static false_type Check( ... );					\
									\
  public:								\
    static const bool value = decltype( Check<T>( declval<T>() , declval<T>() ) )::value; \
    									\
  };									\
  									\

#define DEFINITION_OF_IMPLY_TYPE_OF_NON_MEMBER_OPERATOR_( Oper , eq )	\
									\
  template <typename T>							\
  class CONNECT( imply_TypeOf_non_member_operator_ , Oper ) :		\
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename U>						\
    static auto Check( const U& u1 , const U& u2 ) -> decltype( u1 eq u2 ); \
									\
    template <typename U>						\
    static false_type Check( ... );					\
									\
  public:								\
    using type = decltype( Check<T>( declval<T>() , declval<T>() ) );	\
									\
  };									\
									\

#define DEFINITION_OF_MATCH_TYPE_OF_NON_MEMBER_OPERATOR_( Oper , Ret )	\
									\
  template <typename T>							\
  class CONNECT( match_TypeOf_non_member_operator_ , Oper ) :		\
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename U>						\
    static auto Check() -> typename enable_if< is_same< TypeOfToValue<typename CONNECT( imply_TypeOf_non_member_operator_ , Oper )<U> ::type , Ret > , Ret >::value , true_type >::type; \
									\
    template <typename U>						\
    static auto Check() -> typename enable_if< ! ( is_same< TypeOfToValue<typename CONNECT( imply_TypeOf_non_member_operator_ , Oper )<U> ::type , Ret > , Ret >::value ) , false_type >::type; \
									\
  public:								\
    static const bool value = decltype( Check<T>() )::value && ! is_same< Ret , false_type >::value; \
    									\
  };									\
									\

#define VALUE_NON_MEMBER_OPERATOR_VALID( Oper )				\
  ( CONNECT( callable_non_member_operator_ , Oper )<T> ::value ) 

#define VALUE_NON_MEMBER_OPERATOR_INVALID( Oper )	\
  ( ! VALUE_NON_MEMBER_OPERATOR_VALID( Oper ) ) 

#define VALUE_NON_MEMBER_OPERATOR_TRUE( Oper )				\
  ( VALUE_NON_MEMBER_OPERATOR_VALID( Oper ) && CONNECT( match_TypeOf_non_member_operator_ , Oper )<T> ::value ) 

#define VALUE_NON_MEMBER_OPERATOR_FALSE( Oper )				\
  ( VALUE_NON_MEMBER_OPERATOR_VALID( Oper ) && ! VALUE_NON_MEMBER_OPERATOR_TRUE( Oper ) ) 

#define DECLTYPE_OF_NON_MEMBER_OPERATOR( Oper )				\
  typename CONNECT( imply_TypeOf_non_member_operator_ , Oper )<T> ::type 

#define TYPE_ALIAS_FOR_NON_MEMBER_OPERATOR_VALID( Oper )		\
									\
  template <typename T>							\
  using CONNECT( Valid_ , Oper ) = enable_if< VALUE_NON_MEMBER_OPERATOR_VALID( Oper ) , DECLTYPE_OF_NON_MEMBER_OPERATOR( Oper ) >; \
									\

#define TYPE_ALIAS_FOR_NON_MEMBER_OPERATOR_INVALID( Oper , Ret )	\
									\
  template <typename T>							\
  using CONNECT( Invalid_ , Oper ) = enable_if< VALUE_NON_MEMBER_OPERATOR_INVALID( Oper ) , Ret >; \
									\

#define TYPE_ALIAS_FOR_NON_MEMBER_OPERATOR_TRUE( Oper , Ret )		\
									\
  template <typename T>							\
  using CONNECT( True_ , Oper ) = enable_if< VALUE_NON_MEMBER_OPERATOR_TRUE( Oper ) , TypeOfToValueOrReference< DECLTYPE_OF_NON_MEMBER_OPERATOR( Oper ) , Ret > >; \
									\

#define TYPE_ALIAS_FOR_NON_MEMBER_OPERATOR_FALSE( Oper , Ret )		\
  									\
  template <typename T>							\
  using CONNECT( False_ , Oper ) = enable_if< VALUE_NON_MEMBER_OPERATOR_FALSE( Oper ) , Ret >; \
									\

#define TYPE_OF_NON_MEMBER_OPERATOR( ul , Oper )	\
  typename CONNECT( ul , Oper )<T> ::type 

#define DECLARATION_OF_NON_MEMBER_OPERATOR( ul , Oper )			\
									\
  template <typename T> TYPE_OF_NON_MEMBER_OPERATOR( ul , Oper ) ( Oper )( const T& t1 , const T& t2 ) 

#define DEFINITION_OF_NON_MEMBER_OPERATOR_VALID( Oper , eq )	\
  								\
  DECLARATION_OF_NON_MEMBER_OPERATOR( Valid_ , Oper )		\
  {								\
  								\
    return t1 eq t2;						\
    								\
  }								\
  								\

#define DEFINITION_OF_NON_MEMBER_OPERATOR_INVALID( Oper , Ret )	\
 								\
  DECLARATION_OF_NON_MEMBER_OPERATOR( Invalid_ , Oper )		\
  {								\
  								\
    ERR_IMPUT( typeid( T ).name() );				\
    return Ret ();						\
    								\
  }								\
  								\

#define DEFINITION_OF_NON_MEMBER_OPERATOR_TRUE( Oper , eq )	\
  								\
  DECLARATION_OF_NON_MEMBER_OPERATOR( True_ , Oper )		\
  {								\
  								\
    return t1 eq t2;						\
    								\
  }								\
  								\

#define DEFINITION_OF_NON_MEMBER_OPERATOR_FALSE( Oper , Ret )	\
								\
  DECLARATION_OF_NON_MEMBER_OPERATOR( False_ , Oper )		\
  {								\
								\
    ERR_IMPUT( typeid( T ) );					\
    return Ret ();						\
								\
  }								\
								\

#define TWO_WAYS_SFINAE_NON_MEMBER_OPERATOR_ALIAS( Oper , eq )		\
									\
  DEFINITION_OF_CALLABLE_NON_MEMBER_OPERATOR_( Oper , eq );		\
  DEFINITION_OF_IMPLY_TYPE_OF_NON_MEMBER_OPERATOR_( Oper , eq );	\
  TYPE_ALIAS_FOR_NON_MEMBER_OPERATOR_VALID( Oper );			\
  TYPE_ALIAS_FOR_NON_MEMBER_OPERATOR_INVALID( Oper , bool ) 

#define TWO_WAYS_SFINAE_NON_MEMBER_OPERATOR( Oper )	\
							\
  DECLARATION_OF_NON_MEMBER_OPERATOR( Valid_ , Oper );	\
  DECLARATION_OF_NON_MEMBER_OPERATOR( Invalid_ , Oper ) 

#define TWO_WAYS_SFINAE_NON_MEMBER_OPERATOR_BODY( Oper , eq )	\
								\
  DEFINITION_OF_NON_MEMBER_OPERATOR_VALID( Oper , eq );		\
  DEFINITION_OF_NON_MEMBER_OPERATOR_INVALID( Oper , bool ) 

#define THREE_WAYS_SFINAE_NON_MEMBER_OPERATOR_ALIAS( Oper , eq , Ret )	\
									\
  DEFINITION_OF_CALLABLE_NON_MEMBER_OPERATOR_( Oper , eq );		\
  DEFINITION_OF_IMPLY_TYPE_OF_NON_MEMBER_OPERATOR_( Oper , eq );	\
  DEFINITION_OF_MATCH_TYPE_OF_NON_MEMBER_OPERATOR_( Oper , Ret );	\
  TYPE_ALIAS_FOR_NON_MEMBER_OPERATOR_TRUE( Oper , Ret );		\
  TYPE_ALIAS_FOR_NON_MEMBER_OPERATOR_FALSE( Oper , Ret );		\
  TYPE_ALIAS_FOR_NON_MEMBER_OPERATOR_INVALID( Oper , Ret ) 

#define THREE_WAYS_SFINAE_NON_MEMBER_OPERATOR( Oper )	\
							\
  DECLARATION_OF_NON_MEMBER_OPERATOR( True_ , Oper );	\
  DECLARATION_OF_NON_MEMBER_OPERATOR( False_ , Oper );	\
  DECLARATION_OF_NON_MEMBER_OPERATOR( Invalid_ , Oper ) 

#define THREE_WAYS_SFINAE_NON_MEMBER_OPERATOR_BODY( Oper , eq , Ret )	\
									\
  DEFINITION_OF_NON_MEMBER_OPERATOR_TRUE( Oper , eq );			\
  DEFINITION_OF_NON_MEMBER_OPERATOR_FALSE( Oper , Ret );		\
  DEFINITION_OF_NON_MEMBER_OPERATOR_INVALID( Oper , Ret ) 
