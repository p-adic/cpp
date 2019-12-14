// MemberFunction/a_Macro.hpp

#pragma once
#include "../a_Macro.hpp"

#define DEFINITION_OF_CALLABLE_MEMBER( F )				\
									\
  template <typename T , typename... Args>				\
  class CONNECT( callable_member_ , F ) :				\
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename U , typename... A>				\
    static auto Check( U&& u , const A&... a ) -> decltype( ( u. F )( a... ) , true_type() ); \
									\
    template <typename U , typename... A>				\
    static false_type Check( ... );					\
									\
  public:								\
    static const bool value = decltype( Check<T,Args...>( declval<T>() , declval<Args>()... ) )::value; \
									\
  };									\
									\
  template <typename T , typename... Args>				\
  class CONNECT( callable_member_const_ , F ) :				\
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename U , typename... A>				\
    static auto Check( const U& u , const A&... a ) -> decltype( ( u. F )( a... ) , true_type() ); \
									\
    template <typename U , typename... A>				\
    static false_type Check( ... );					\
									\
  public:								\
    static const bool value = decltype( Check<T,Args...>( declval<T>() , declval<Args>()... ) )::value; \
									\
  };									\
									\

#define DEFINITION_OF_IMPLY_TYPE_OF_MEMBER( F )				\
									\
  template <typename T , typename... Args>				\
  class CONNECT( imply_TypeOf_member_ , F ) :				\
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename U , typename... A>				\
    static auto Check( U&& u , const A&... a ) -> decltype( ( u. F )( a... ) ); \
									\
    template <typename U , typename... A>				\
    static false_type Check( ... );					\
									\
  public:								\
    using type = decltype( Check<T,Args...>( declval<T>() , declval<Args>()... ) ); \
									\
  };									\
									\
  template <typename T , typename... Args>				\
  class CONNECT( imply_TypeOf_member_const_ , F ) :			\
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename U , typename... A>				\
    static auto Check( const U& u , const A&... a ) -> decltype( ( u. F )( a... ) ); \
									\
    template <typename U , typename... A>				\
    static false_type Check( ... );					\
									\
  public:								\
    using type = decltype( Check<T,Args...>( declval<T>() , declval<Args>()... ) ); \
									\
  };									\
									\

#define DEFINITION_OF_MATCH_TYPE_OF_MEMBER( F , Ret )			\
									\
  template <typename T , typename... Args>				\
  class CONNECT( match_TypeOf_member_ , F ) :				\
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename U , typename... A >				\
    static auto Check() -> typename enable_if< is_same< TypeOfToValue< typename CONNECT( imply_TypeOf_member_ , F )<U,A...> ::type , Ret > , Ret >::value , true_type >::type; \
									\
    template <typename U , typename... A >				\
    static auto Check() -> typename enable_if< ! ( is_same< TypeOfToValue< typename CONNECT( imply_TypeOf_member_ , F )<U,A...> ::type , Ret > , Ret >::value ) , false_type >::type; \
    									\
  public:								\
    static const bool value = decltype( Check<T,Args...>() )::value;	\
    									\
  };									\
									\
  template <typename T , typename... Args>				\
  class CONNECT( match_TypeOf_member_const_ , F ) :			\
    public EmptySet							\
  {									\
    									\
  private:								\
    template <typename U , typename... A >				\
    static auto Check() -> typename enable_if< is_same< TypeOfToValue< typename CONNECT( imply_TypeOf_member_const_ , F )<U,A...> ::type , Ret > , Ret >::value , true_type >::type; \
									\
    template <typename U , typename... A >				\
    static auto Check() -> typename enable_if< ! ( is_same< TypeOfToValue< typename CONNECT( imply_TypeOf_member_const_ , F )<U,A...> ::type , Ret > , Ret >::value ) , false_type >::type; \
    									\
  public:								\
    static const bool value = decltype( Check<T,Args...>() )::value && ! is_same< Ret , false_type >::value;	\
    									\
  };									\
									\

#define VALUE_MEMBER_VALID( F )					\
  ( CONNECT( callable_member_ , F )<T,Args...> ::value ) 

#define VALUE_MEMBER_CONST_VALID( F )					\
  ( VALUE_MEMBER_VALID( F ) && CONNECT( callable_member_const_ , F )<T,Args...> ::value ) 

#define VALUE_MEMBER_NON_CONST_VALID( F )				\
  ( VALUE_MEMBER_VALID( F ) && ! VALUE_MEMBER_CONST_VALID( F ) ) 

#define VALUE_MEMBER_INVALID( F )		\
  ( ! VALUE_MEMBER_VALID( F ) ) 

#define VALUE_MEMBER_TRUE( F )					\
  ( VALUE_MEMBER_VALID( F ) && CONNECT( match_TypeOf_member_ , F )<T,Args...> ::value ) 

#define VALUE_MEMBER_CONST_TRUE( F )				\
  ( VALUE_MEMBER_TRUE( F ) && VALUE_MEMBER_CONST_VALID( F ) && CONNECT( match_TypeOf_member_const_ , F )<T,Args...> ::value ) 

#define VALUE_MEMBER_NON_CONST_TRUE( F )				\
  ( VALUE_MEMBER_TRUE( F ) && ! VALUE_MEMBER_CONST_TRUE( F ) ) 

#define VALUE_MEMBER_FALSE( F )				\
  ( VALUE_MEMBER_VALID( F ) && ! VALUE_MEMBER_TRUE( F ) ) 

#define DECLTYPE_OF_MEMBER( ul , F )					\
  typename CONNECT( CONNECT( imply_TypeOf_member , ul ) , F )<T,Args...> ::type 

#define TYPE_ALIAS_FOR_MEMBER_VALID( Func , F )				\
									\
  template <typename T , typename... Args>				\
  using CONNECT( ConstValid_ , Func ) = enable_if< VALUE_MEMBER_CONST_VALID( F ) ,  >; \
									\
  template <typename T , typename... Args>				\
  using CONNECT( NonConstValid_ , Func ) = enable_if< VALUE_MEMBER_NON_CONST_VALID( F ) , DECLTYPE_OF_MEMBER( _ , F ) >; \
									\

#define TYPE_ALIAS_FOR_MEMBER_INVALID( Func , F , Ret )			\
									\
  template <typename T , typename... Args>				\
  using CONNECT( Invalid_ , Func ) = enable_if< VALUE_MEMBER_INVALID( F ) , Ret >; \
									\

#define TYPE_ALIAS_FOR_MEMBER_TRUE( Func , F , Ret )			\
									\
  template <typename T , typename... Args>				\
  using CONNECT( ConstTrue_ , Func ) = enable_if< VALUE_MEMBER_CONST_TRUE( F ) , TypeOfToValueOrReference< DECLTYPE_OF_MEMBER( _const_ , F ) , Ret > >; \
									\
  template <typename T , typename... Args>				\
  using CONNECT( NonConstTrue_ , Func ) = enable_if< VALUE_MEMBER_NON_CONST_TRUE( F ) , TypeOfToValueOrReference< DECLTYPE_OF_MEMBER( _ , F ) , Ret > >; \
									\

#define TYPE_ALIAS_FOR_MEMBER_FALSE( Func , F , Ret )			\
									\
  template <typename T , typename... Args>				\
  using CONNECT( False_ , Func ) = enable_if< VALUE_MEMBER_FALSE( F ) , Ret >; \
									\

#define TYPE_OF_MEMBER( ul , Func )			\
  typename CONNECT( ul , Func )<T,Args...> ::type 

// const左辺値参照と非const左辺値参照と右辺値参照で分かれるためマクロ化不可。
#define DECLARATION_OF_MEMBER_CONST_VALID( Func )			\
									\
  template <typename T , typename... Args> TYPE_OF_MEMBER( ConstValid_ , Func ) ( Func )( const T& t , const Args&... args ) 

#define DECLARATION_OF_MEMBER_NON_CONST_VALID_LVALUE( Func )		\
									\
  template <typename T , typename... Args> TYPE_OF_MEMBER( NonConstValid_ , Func ) ( Func )( T& t , const Args&... args ) 

#define DECLARATION_OF_MEMBER_NON_CONST_VALID_RVALUE( Func )		\
									\
  template <typename T , typename... Args> TYPE_OF_MEMBER( NonConstValid_ , Func ) ( Func )( T&& t , const Args&... args ) 

#define DECLARATION_OF_MEMBER_INVALID( Func )				\
									\
  template <typename T , typename... Args> TYPE_OF_MEMBER( Invalid_ , Func ) ( Func )( const T& t , const Args&... args ) 

#define DECLARATION_OF_MEMBER_CONST_TRUE( Func )			\
									\
  template <typename T , typename... Args> TYPE_OF_MEMBER( ConstTrue_ , Func ) ( Func )( const T& t , const Args&... args ) 

#define DECLARATION_OF_MEMBER_NON_CONST_TRUE_LVALUE( Func )		\
									\
  template <typename T , typename... Args> TYPE_OF_MEMBER( NonConstTrue_ , Func ) ( Func )( T& t , const Args&... args ) 

#define DECLARATION_OF_MEMBER_NON_CONST_TRUE_RVALUE( Func )		\
									\
  template <typename T , typename... Args> TYPE_OF_MEMBER( NonConstTrue_ , Func ) ( Func )( T&& t , const Args&... args ) 

#define DECLARATION_OF_MEMBER_FALSE( Func )				\
									\
  template <typename T , typename... Args> TYPE_OF_MEMBER( False_ , Func ) ( Func )( const T& t , const Args&... args ) 

#define DEFINITION_OF_MEMBER_VALID( Func , F )		\
 							\
  DECLARATION_OF_MEMBER_CONST_VALID( Func )		\
  {							\
							\
    return ( t. F )( args... );				\
							\
  }							\
							\
  DECLARATION_OF_MEMBER_NON_CONST_VALID_LVALUE( Func )	\
  {							\
							\
    return ( t. F )( args... );				\
							\
  }							\
							\
  DECLARATION_OF_MEMBER_NON_CONST_VALID_RVALUE( Func )	\
  {							\
							\
    return ( t. F )( args... );				\
							\
  }							\
							\

#define DEFINITION_OF_MEMBER_INVALID( Func , Ret )			\
									\
  DECLARATION_OF_MEMBER_INVALID( Func )					\
  {									\
									\
    ERR_IMPUT( typeid( T ) , typeid( Ret ) , typeid( Args )...  );	\
    return Ret ();							\
									\
  }									\
									\
  
#define DEFINITION_OF_MEMBER_TRUE( Func , F , Ret )	\
 							\
  DECLARATION_OF_MEMBER_CONST_TRUE( Func )		\
  {							\
							\
    return to_ValueOrReference<DECLTYPE_OF_MEMBER( _const_ , F ) , Ret >( ( t. F )( args... ) ); \
							\
  }							\
							\
  DECLARATION_OF_MEMBER_NON_CONST_TRUE_LVALUE( Func )	\
  {							\
							\
    return to_ValueOrReference<DECLTYPE_OF_MEMBER( _ , F ) , Ret >( ( t. F )( args... ) ); \
							\
  }							\
							\
  DECLARATION_OF_MEMBER_NON_CONST_TRUE_RVALUE( Func )	\
  {							\
							\
    return to_ValueOrReference<DECLTYPE_OF_MEMBER( _ , F ) , Ret >( ( t. F )( args... ) ); \
							\
  }							\
							\

#define DEFINITION_OF_MEMBER_FALSE( Func , Ret )	\
							\
  DECLARATION_OF_MEMBER_FALSE( Func )			\
  {							\
							\
    ERR_IMPUT( typeid( T ) , typeid( Ret ) , typeid( Args )... ); \
    return Ret ();					\
							\
  }							\
							\

#define TWO_WAYS_SFINAE_MEMBER_ALIAS( Func , F )	\
 							\
  DEFINITION_OF_CALLABLE_MEMBER( F );			\
  DEFINITION_OF_IMPLY_TYPE_OF_MEMBER( F );		\
  TYPE_ALIAS_FOR_MEMBER_VALID( Func , F );		\
  TYPE_ALIAS_FOR_MEMBER_INVALID( Func , F , int ) 

#define TWO_WAYS_SFINAE_MEMBER( Func )			\
							\
  DECLARATION_OF_MEMBER_CONST_VALID( Func );		\
  DECLARATION_OF_MEMBER_NON_CONST_VALID_LVALUE( Func );	\
  DECLARATION_OF_MEMBER_NON_CONST_VALID_RVALUE( Func );	\
  DECLARATION_OF_MEMBER_INVALID( Func ) 

#define TWO_WAYS_SFINAE_MEMBER_BODY( Func , F )		\
 							\
  DEFINITION_OF_MEMBER_VALID( Func , F );		\
  DEFINITION_OF_MEMBER_INVALID( Func , F , int ) 

#define THREE_WAYS_SFINAE_MEMBER_ALIAS( Func , F , Ret )	\
								\
  DEFINITION_OF_CALLABLE_MEMBER( F );				\
  DEFINITION_OF_IMPLY_TYPE_OF_MEMBER( F );			\
  DEFINITION_OF_MATCH_TYPE_OF_MEMBER( F , Ret );			\
  TYPE_ALIAS_FOR_MEMBER_TRUE( Func , F , Ret );			\
  TYPE_ALIAS_FOR_MEMBER_FALSE( Func , F , Ret );		\
  TYPE_ALIAS_FOR_MEMBER_INVALID( Func , F , Ret ) 
  
#define THREE_WAYS_SFINAE_MEMBER( Func )		\
							\
  DECLARATION_OF_MEMBER_CONST_TRUE( Func );		\
  DECLARATION_OF_MEMBER_NON_CONST_TRUE_LVALUE( Func );	\
  DECLARATION_OF_MEMBER_NON_CONST_TRUE_RVALUE( Func );	\
  DECLARATION_OF_MEMBER_FALSE( Func );			\
  DECLARATION_OF_MEMBER_INVALID( Func ) 

#define THREE_WAYS_SFINAE_MEMBER_BODY( Func , F , Ret )	\
 							\
  DEFINITION_OF_MEMBER_TRUE( Func , F , Ret );		\
  DEFINITION_OF_MEMBER_FALSE( Func , Ret );		\
  DEFINITION_OF_MEMBER_INVALID( Func , Ret ) 
