// NonMemberFunction/a_Macro.hpp

#pragma once
#include "../a_Macro.hpp"

// const参照な仮引数のみを持つ関数に拡張するために、非const参照でない仮引数のみを許容する。
#define DEFINITION_OF_CALLABLE_NON_MEMBER_WITH_CONST_VARIABLES( _ul_ , Func ) \
									\
  template <typename... Args>						\
  class CONNECT( CONNECT( callable_non_member_with_const_variables , _ul_ ) , Func ) : \
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename... A>						\
    static auto Check( const A&... a ) -> decltype( Func ( a... ) , true_type() ); \
									\
    template <typename... A>						\
    static false_type Check( ... );					\
									\
  public:								\
    static const bool value = decltype( Check<Args...>( declval<Args>()... ) )::value; \
									\
  };									\
									\

#define DEFINITION_OF_IMPLY_TYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ul_ , Func ) \
									\
  template <typename... Args>						\
  class CONNECT( CONNECT( imply_TypeOf_non_member_with_const_variables , _ul_ ) , Func ) : \
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename... A>						\
    static auto Check( const A&... a ) -> decltype( Func ( a... ) ); \
									\
    template <typename... A>						\
    static false_type Check( ... );					\
    									\
  public:								\
    using type = decltype( Check<Args...>( declval<Args>()... ) );	\
    									\
  };									\
  									\

#define DEFINITION_OF_MATCH_TYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ul_ , Func , Ret ) \
									\
  template <typename... Args>						\
  class CONNECT( CONNECT( match_TypeOf_non_member_with_const_variables , _ul_ ) , Func ) : \
    public EmptySet							\
  {									\
									\
  private:								\
    template <typename... A >						\
    static auto Check() -> typename enable_if< is_same< TypeOfToValue< typename CONNECT( CONNECT( imply_TypeOf_non_member_with_const_variables , _ul_ ) , Func )<A...> ::type , Ret > , Ret >::value , true_type >::type; \
									\
    template <typename... A >						\
    static auto Check() -> typename enable_if< ! ( is_same< TypeOfToValue< typename CONNECT( CONNECT( imply_TypeOf_non_member_with_const_variables , _ul_ ) , Func )<A...> ::type , Ret > , Ret >::value ) , false_type >::type; \
    									\
  public:								\
    static const bool value = decltype( Check<Args...>() )::value && ! is_same< Ret , false_type >::value; \
    									\
  };									\
									\

#define VALUE_NON_MEMBER_WITH_CONST_VARIABLES_VALID( _ul_ , Func )	\
  ( CONNECT( CONNECT( callable_non_member_with_const_variables , _ul_ ) , Func )<Args...> ::value ) 

#define VALUE_NON_MEMBER_WITH_CONST_VARIABLES_INVALID( _ul_ , Func )	\
  ( ! VALUE_NON_MEMBER_WITH_CONST_VARIABLES_VALID( _ul_ , Func ) ) 

#define VALUE_NON_MEMBER_WITH_CONST_VARIABLES_TRUE( _ul_ , Func )	\
  ( VALUE_NON_MEMBER_WITH_CONST_VARIABLES_VALID( _ul_ , Func ) && CONNECT( CONNECT( match_TypeOf_non_member_with_const_variables , _ul_ ) , Func )<Args...> ::value ) 

#define VALUE_NON_MEMBER_WITH_CONST_VARIABLES_FALSE( _ul_ , Func )	\
  ( VALUE_NON_MEMBER_WITH_CONST_VARIABLES_VALID( _ul_ , Func ) && ! VALUE_NON_MEMBER_WITH_CONST_VARIABLES_TRUE( _ul_ , Func ) ) 

#define DECLTYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ul_ , Func )	\
  typename CONNECT( CONNECT( imply_TypeOf_non_member_with_const_variables , _ul_ ) , Func )<Args...> ::type 

#define TYPE_ALIAS_FOR_NON_MEMBER_WITH_CONST_VARIABLES_VALID( _ul_ , Func , _ext ) \
									\
  template <typename... Args>						\
  using CONNECT( CONNECT( Valid_ , Func ) , _ext ) = enable_if< VALUE_NON_MEMBER_WITH_CONST_VARIABLES_VALID( _ul_ , Func ) , DECLTYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ul_ , Func ) >; \
									\

#define TYPE_ALIAS_FOR_NON_MEMBER_WITH_CONST_VARIABLES_INVALID( _ul_ , Func , Ret , _ext ) \
  									\
  template <typename... Args>						\
  using CONNECT( CONNECT( Invalid_ , Func ) , _ext ) = enable_if< VALUE_NON_MEMBER_WITH_CONST_VARIABLES_INVALID( _ul_ , Func ) , Ret >; \
									\

#define TYPE_ALIAS_FOR_NON_MEMBER_WITH_CONST_VARIABLES_TRUE( _ul_ , Func , Ret , _ext ) \
									\
  template <typename... Args>						\
  using CONNECT( CONNECT( True_ , Func ) , _ext ) = enable_if< VALUE_NON_MEMBER_WITH_CONST_VARIABLES_TRUE( _ul_ , Func ) , TypeOfToValueOrReference< DECLTYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ul_ , Func ) , Ret > >; \
									\

#define TYPE_ALIAS_FOR_NON_MEMBER_WITH_CONST_VARIABLES_FALSE( _ul_ , Func , Ret , _ext ) \
  									\
  template <typename... Args>						\
  using CONNECT( CONNECT( False_ , Func ) , _ext ) = enable_if< VALUE_NON_MEMBER_WITH_CONST_VARIABLES_FALSE( _ul_ , Func ) , Ret >; \
									\

#define TYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ul_ , Func , _ext )	\
  typename CONNECT( CONNECT( _ul_ , Func ) , _ext )<Args...> ::type 

#define DECLARATION_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ul_ , Func , _ext ) \
									\
  template <typename... Args> TYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ul_ , Func , _ext ) ( CONNECT( Func , _ext ) )( const Args&... args ) 

#define DEFINITION_OF_NON_MEMBER_WITH_CONST_VARIABLES_VALID( Func )	\
									\
  DECLARATION_OF_NON_MEMBER_WITH_CONST_VARIABLES( Valid_ , Func , _Extended ) \
  {									\
									\
    return ( Func )( args... );						\
									\
  }									\
									\

#define DEFINITION_OF_NON_MEMBER_WITH_CONST_VARIABLES_INVALID( Func , Ret ) \
									\
  DECLARATION_OF_NON_MEMBER_WITH_CONST_VARIABLES( Invalid_ , Func , _Extended )	\
  {									\
									\
    ERR_IMPUT( typeid( Ret ) , typeid( Args )... );			\
    return Ret ();							\
									\
  }									\
									\

#define DEFINITION_OF_NON_MEMBER_WITH_CONST_VARIABLES_TRUE( Func , Ret ) \
									\
  DECLARATION_OF_NON_MEMBER_WITH_CONST_VARIABLES( True_ , Func , _Extended ) \
  {									\
									\
    return to_ValueOrReference< DECLTYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ , Func ) , Ret >( ( Func )( args... ) ); \
									\
  }									\
									\

#define DEFINITION_OF_NON_MEMBER_WITH_CONST_VARIABLES_FALSE( Func , Ret ) \
									\
  DECLARATION_OF_NON_MEMBER_WITH_CONST_VARIABLES( False_ , Func , _Extended ) \
  {									\
									\
    ERR_IMPUT( typeid( Ret ) , typeid( Args )... );			\
    return Ret ();							\
									\
  }									\
									\

#define TWO_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES_UNIVERSAL_ALIAS( _ul_ , Func , _ext ) \
									\
  DEFINITION_OF_CALLABLE_NON_MEMBER_WITH_CONST_VARIABLES( _ul_ , Func ); \
  DEFINITION_OF_IMPLY_TYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ul_ , Func ); \
  TYPE_ALIAS_FOR_NON_MEMBER_WITH_CONST_VARIABLES_VALID( _ul_ , Func , _ext ); \
  TYPE_ALIAS_FOR_NON_MEMBER_WITH_CONST_VARIABLES_INVALID( _ul_ , Func , int , _ext ) 

#define TWO_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES_UNIVERSAL( Func , _ext ) \
									\
  DECLARATION_OF_NON_MEMBER_WITH_CONST_VARIABLES( Valid_ , Func , _ext ); \
  DECLARATION_OF_NON_MEMBER_WITH_CONST_VARIABLES( Invalid_ , Func , _ext ) 

#define TWO_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES_ALIAS( Func )	\
									\
  TWO_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES_UNIVERSAL_ALIAS( _ , Func , _Extended ) 

#define TWO_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES( Func )		\
									\
  TWO_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES_UNIVERSAL( Func , _Extended ) 

#define TWO_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES_BODY( Func )	\
									\
  DEFINITION_OF_NON_MEMBER_WITH_CONST_VARIABLES_VALID( Func );		\
  DEFINITION_OF_NON_MEMBER_WITH_CONST_VARIABLES_INVALID( Func , int ) 

#define THREE_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES_UNIVERSAL_ALIAS( _ul_ , Func , Ret , _ext ) \
  									\
  DEFINITION_OF_CALLABLE_NON_MEMBER_WITH_CONST_VARIABLES( _ul_ , Func ); \
  DEFINITION_OF_IMPLY_TYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ul_ , Func ); \
  DEFINITION_OF_MATCH_TYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ul_ , Func , Ret ); \
  TYPE_ALIAS_FOR_NON_MEMBER_WITH_CONST_VARIABLES_TRUE( _ul_ , Func , Ret , _ext ); \
  TYPE_ALIAS_FOR_NON_MEMBER_WITH_CONST_VARIABLES_FALSE( _ul_ , Func , Ret , _ext ); \
  TYPE_ALIAS_FOR_NON_MEMBER_WITH_CONST_VARIABLES_INVALID( _ul_ , Func , Ret , _ext ) 
  
#define THREE_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES_UNIVERSAL( Func , _ext ) \
									\
  DECLARATION_OF_NON_MEMBER_WITH_CONST_VARIABLES( True_ , Func , _ext ); \
  DECLARATION_OF_NON_MEMBER_WITH_CONST_VARIABLES( False_ , Func , _ext ); \
  DECLARATION_OF_NON_MEMBER_WITH_CONST_VARIABLES( Invalid_ , Func , _ext ) 

#define THREE_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES_ALIAS( Func , Ret ) \
									\
  THREE_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES_UNIVERSAL_ALIAS( _ , Func , Ret , _Extended ) 
  
#define THREE_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES( Func )	\
									\
  THREE_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES_UNIVERSAL( Func , _Extended ) 

#define THREE_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES_BODY( Func , Ret ) \
									\
  DEFINITION_OF_NON_MEMBER_WITH_CONST_VARIABLES_TRUE( Func , Ret );	\
  DEFINITION_OF_NON_MEMBER_WITH_CONST_VARIABLES_FALSE( Func , Ret );	\
  DEFINITION_OF_NON_MEMBER_WITH_CONST_VARIABLES_INVALID( Func , Ret ) 
