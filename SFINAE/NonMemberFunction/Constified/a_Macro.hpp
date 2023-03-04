// c:/Users/user/Documents/Programming/SFINAE/NonMemberFunction/Constified/a_Macro.hpp

#pragma once
#include "../a_Macro.hpp"
#include "../../MemberFunction/Constructor/a_Macro.hpp"

// (T0,T1) を const int& , int& , int , int&& の組み合わせとして以下を考える。
// int f( T0 n ){ return n; }; int g( T1 n ){ return f( n ); };
//
// 以下はコンパイル可能。
// ( const int& , const int& )
// ( const int& , int& )
// ( const int& , int )
// ( const int& , int&& )
// ( int& , int& )
// ( int& , int&& )
// ( int , const int& )
// ( int , int& )
// ( int , int )
// ( int , int&& )
// ( int&& , const int& )
// ( int&& , int& )
// ( int&& , int )
// ( int&& , int&& )
//
// 以下はコンパイルエラー。
// ( int& , const int& )
// ( int& , int )

// 第１仮引数のみ非const参照も許容する。
#define DEFINITION_OF_CALLABLE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _ul_ , Func ) \
									\
  template <typename Arg1 , typename... Arg2>				\
  class CONNECT( CONNECT( callable_non_member_with_at_least_one_variable , _ul_ ) , Func ) : \
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename A1 , typename... A2>				\
    static auto Check( A1&& a1 , const A2&... a2 ) -> decltype( Func ( a1 , a2... ) , true_type() ); \
									\
    template <typename A1 , typename... A2>				\
    static false_type Check( ... );					\
									\
  public:								\
    static const bool value = decltype( Check<Arg1,Arg2...>( declval<Arg1>() , declval<Arg2>()... ) )::value; \
									\
  };									\
									\
  DEFINITION_OF_CALLABLE_NON_MEMBER_WITH_CONST_VARIABLES( CONNECT( _with_at_least_one_variable , _ul_ ) , Func ); \
									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( CONNECT( callable_non_member_with_at_least_one_variable , _ul_ ) , const_ ) , Func ) = CONNECT( CONNECT( callable_non_member_with_const_variables , CONNECT( _with_at_least_one_variable , _ul_ ) ) , Func )<Arg1,Arg2...> \

#define DEFINITION_OF_IMPLY_TYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _ul_ , Func ) \
									\
  template <typename Arg1 , typename... Arg2>				\
  class CONNECT( CONNECT( imply_TypeOf_non_member_with_at_least_one_variable , _ul_ ) , Func ) : \
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename A1 , typename... A2>				\
    static auto Check( A1&& a1 , const A2&... a2 ) -> decltype( Func ( a1 , a2... ) ); \
									\
    template <typename A1 , typename... A2>				\
    static false_type Check( ... );					\
    									\
  public:								\
    using type = decltype( Check<Arg1,Arg2...>( declval<Arg1>() , declval<Arg2>()... ) ); \
    									\
  };									\
  									\
  DEFINITION_OF_IMPLY_TYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( CONNECT( _with_at_least_one_variable , _ul_ ) , Func ); \
									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( CONNECT( imply_TypeOf_non_member_with_at_least_one_variable , _ul_ ) , const_ ) , Func ) = CONNECT( CONNECT( imply_TypeOf_non_member_with_const_variables , CONNECT( _with_at_least_one_variable , _ul_ ) ) , Func )<Arg1,Arg2...> \

#define DEFINITION_OF_MATCH_TYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _ul_ , Func , Ret ) \
									\
  template <typename Arg1 , typename... Arg2>				\
  class CONNECT( CONNECT( match_TypeOf_non_member_with_at_least_one_variable , _ul_ ) , Func ) : \
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename A1 , typename... A2 >				\
    static auto Check() -> typename enable_if< is_same< TypeOfToValue< typename CONNECT( CONNECT( imply_TypeOf_non_member_with_at_least_one_variable , _ul_ ) , Func )<A1,A2...> ::type , Ret > , Ret >::value , true_type >::type; \
									\
    template <typename A1 , typename... A2 >				\
    static auto Check() -> typename enable_if< ! ( is_same< TypeOfToValue< typename CONNECT( CONNECT( imply_TypeOf_non_member_with_at_least_one_variable , _ul_ ) , Func )<A1,A2...> ::type , Ret > , Ret >::value ) , false_type >::type; \
    									\
  public:								\
    static const bool value = decltype( Check<Arg1,Arg2...>() )::value && ! is_same< Ret , false_type >::value; \
    									\
  };									\
									\
  DEFINITION_OF_MATCH_TYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( CONNECT( _with_at_least_one_variable , _ul_ ) , Func , Ret ); \
									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( CONNECT( match_TypeOf_non_member_with_at_least_one_variable , _ul_ ) , const_ ) , Func ) = CONNECT( CONNECT( match_TypeOf_non_member_with_const_variables , CONNECT( _with_at_least_one_variable , _ul_ ) ) , Func )<Arg1,Arg2...> \

#define VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_VALID( _ul_ , Func ) \
  ( CONNECT( CONNECT( callable_non_member_with_at_least_one_variable , _ul_ ) , Func )<Arg1,Arg2...> ::value && ( CONNECT( CONNECT( CONNECT( callable_non_member_with_at_least_one_variable , _ul_ ) , const_ ) , Func )<Arg1,Arg2...> ::value || callable_Constructor<Arg1,Arg1>::value ) ) 

#define VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_CONST_VALID( _ul_ , Func ) \
  ( VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_VALID( _ul_ , Func ) && CONNECT( CONNECT( CONNECT( callable_non_member_with_at_least_one_variable , _ul_ ) , const_ ) , Func )<Arg1,Arg2...> ::value ) 

#define VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_NON_CONST_VALID( _ul_ , Func ) \
  ( VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_VALID( _ul_ , Func ) && ! VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_CONST_VALID( _ul_ , Func ) ) 

#define VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_INVALID( _ul_ , Func ) \
  ( ! VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_VALID( _ul_ , Func ) ) 

#define VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_TRUE( _ul_ , Func )	\
  ( VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_VALID( _ul_ , Func ) && CONNECT( CONNECT( match_TypeOf_non_member_with_at_least_one_variable , _ul_ ) , Func )<Arg1,Arg2...> ::value ) 

#define VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_CONST_TRUE( _ul_ , Func ) \
  ( VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_TRUE( _ul_ , Func ) && VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_CONST_VALID( _ul_ , Func ) && CONNECT( CONNECT( CONNECT( match_TypeOf_non_member_with_at_least_one_variable , _ul_ ) , const_ ) , Func )<Arg1,Arg2...> ::value ) 

#define VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_NON_CONST_TRUE( _ul_ , Func ) \
  ( VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_TRUE( _ul_ , Func ) && ! VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_CONST_TRUE( _ul_ , Func ) ) 

#define VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_FALSE( _ul_ , Func ) \
  ( VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_VALID( _ul_ , Func ) && ! VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_TRUE( _ul_ , Func ) ) 

#define DECLTYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _ul_ , Func ) \
  typename CONNECT( CONNECT( imply_TypeOf_non_member_with_at_least_one_variable , _ul_ ) , Func )<Arg1,Arg2...> ::type 

#define TYPE_ALIAS_FOR_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_VALID( Func , _con ) \
									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( ConstValid_ , Func ), _con ) = enable_if< VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_CONST_VALID( Func ) , DECLTYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( Func ) >; \
									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( NonConstValid_ , Func ) , _con ) = enable_if< VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_NON_CONST_VALID( Func ) , DECLTYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( Func ) >; \
									\

#define TYPE_ALIAS_FOR_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_INVALID( Func , Ret , _con ) \
  									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( Invalid_ , Func ) , _con ) = enable_if< VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_INVALID( Func ) , Ret >; \
									\

#define TYPE_ALIAS_FOR_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_TRUE( Func , Ret , _con ) \
									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( ConstTrue_ , Func ) , _con ) = enable_if< VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_CONST_TRUE( Func ) , TypeOfToValueOrReference< DECLTYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( Func ) , Ret > >; \
									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( NonConstTrue_ , Func ) , _con ) = enable_if< VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_NON_CONST_TRUE( Func ) , TypeOfToValueOrReference< DECLTYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( Func ) , Ret > >; \
									\

#define TYPE_ALIAS_FOR_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_FALSE( Func , Ret , _con ) \
  									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( False_ , Func ) , _con ) = enable_if< VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_FALSE( Func ) , Ret >; \
									\

#define TYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( val_ , Func , _con ) \
  typename CONNECT( CONNECT( val_ , Func ) , _con )<Arg1,Arg2...> ::type 

#define DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( val_ , Func , _con ) \
									\
  template <typename Arg1 , typename... Arg2> TYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( val_ , Func , _con ) ( CONNECT( Func , _con ) )( const Arg1& arg1 , const Arg2&... arg2 ) 

#define DEFINITION_OF_NON_MEMBER_CONSTIFIED_VALID( Func )		\
									\
  DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( ConstValid_ , Func , _Constified ) \
  {									\
									\
    return ( Func )( arg1 , arg2... );					\
									\
  }									\
									\
  DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( NonConstValid_ , Func , _Constified ) \
  {									\
									\
    Arg1 copy_arg1 = arg1;						\
    return ( Func )( copy_arg1 , arg2... );				\
									\
  }									\
									\

#define DEFINITION_OF_NON_MEMBER_CONSTIFIED_INVALID( Func , Ret )	\
									\
  DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( Invalid_ , Func , _Constified )	\
  {									\
									\
    ERR_INPUT( arg1 , arg2... );					\
    return Ret ();							\
									\
  }									\
									\

#define DEFINITION_OF_NON_MEMBER_CONSTIFIED_TRUE( Func , Ret )		\
									\
  DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( ConstTrue_ , Func , _Constified ) \
  {									\
									\
    return to_ValueOrReference< DECLTYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( Func ) , Ret >( ( Func )( arg1 , arg2... ) ); \
									\
  }									\
									\
  DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( NonConstTrue_ , Func , _Constified ) \
  {									\
									\
    Arg1 copy_arg1 = arg1;						\
    return to_ValueOrReference< DECLTYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( Func ) , Ret >( ( Func )( copy_arg1 , arg2... ) ); \
									\
  }									\
									\
  
#define DEFINITION_OF_NON_MEMBER_CONSTIFIED_FALSE( Func , Ret )		\
									\
  DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( False_ , Func , _Constified ) \
  {									\
									\
    ERR_INPUT( arg1 , arg2... );					\
    return Ret ();							\
									\
  }									\
									\

#define TWO_WAYS_SFINAE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_UNIVERSAL_ALIAS( _ul_ , Func , _con ) \
									\
  DEFINITION_OF_CALLABLE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _ul_ , Func ); \
  DEFINITION_OF_IMPLY_TYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _ul_ , Func ); \
  TYPE_ALIAS_FOR_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_VALID( _ul_ , Func , _con ); \
  TYPE_ALIAS_FOR_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_INVALID( _ul_ , Func , int , _con ) 

#define TWO_WAYS_SFINAE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_UNIVERSAL( Func , _con ) \
									\
  DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( ConstValid_ , Func , _con ); \
  DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( NonConstValid_ , Func , _con ); \
  DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( Invalid_ , Func , _con ) 

#define TWO_WAYS_SFINAE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_ALIAS( Func ) \
									\
  TWO_WAYS_SFINAE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_UNIVERSAL( Func , _Constified ) 

#define TWO_WAYS_SFINAE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( Func )	\
									\
  TWO_WAYS_SFINAE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_UNIVERSAL( Func , _Constified ) 

#define TWO_WAYS_SFINAE_NON_MEMBER_CONSTIFIED_BODY( Func )	\
								\
  DEFINITION_OF_NON_MEMBER_CONSTIFIED_VALID( Func );		\
  DEFINITION_OF_NON_MEMBER_CONSTIFIED_INVALID( Func , int ) 

#define THREE_WAYS_SFINAE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_UNIVERSAL_ALIAS( _ul_ , Func , Ret , _con ) \
									\
  DEFINITION_OF_CALLABLE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _ul_ , Func ); \
  DEFINITION_OF_IMPLY_TYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _ul_ , Func ); \
  DEFINITION_OF_MATCH_TYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _ul_ , Func , Ret ); \
  TYPE_ALIAS_FOR_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_TRUE( _ul_ , Func , Ret , _con ); \
  TYPE_ALIAS_FOR_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_FALSE( _ul_ , Func , Ret , _con ); \
  TYPE_ALIAS_FOR_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_INVALID( _ul_ , Func , Ret , _con ) 
  
#define THREE_WAYS_SFINAE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_UNIVERSAL( Func , _con ) \
									\
  DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( ConstTrue_ , Func , _con ); \
  DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( NonConstTrue_ , Func , _con ); \
  DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( False_ , Func , _con ); \
  DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( Invalid_ , Func , _con ) 

#define THREE_WAYS_SFINAE_NON_MEMBER_CONSTIFIED_ALIAS( Func , Ret )	\
									\
  THREE_WAYS_SFINAE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_UNIVERSAL_ALIAS( _ , Func , Ret , _Constified ) 

#define THREE_WAYS_SFINAE_NON_MEMBER_CONSTIFIED( Func )			\
									\
  THREE_WAYS_SFINAE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_UNIVERSAL( Func , _Constfied ) \

#define THREE_WAYS_SFINAE_NON_MEMBER_CONSTIFIED_BODY( Func , Ret )	\
									\
  DEFINITION_OF_NON_MEMBER_CONSTIFIED_TRUE( Func , Ret );		\
  DEFINITION_OF_NON_MEMBER_CONSTIFIED_FALSE( Func , Ret );		\
  DEFINITION_OF_NON_MEMBER_CONSTIFIED_INVALID( Func , Ret ) 
