// c:/Users/user/Documents/Programming/SFINAE/NonMemberFunction/List/a_Macro.hpp

#pragma once
#include "../Constified/a_Macro.hpp"

#define DECLTYPE_OF_NON_MEMBER_LISTED( Func )				\
  DECLTYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _Listed_ , Func ) 

#define VALUE_NON_MEMBER_LISTED_VALID( Func )				\
  ( VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_VALID( _Listed_ , Func ) && equal_to<uint>()( sizeof...( Arg2 ) , 0 ) ) 

#define VALUE_NON_MEMBER_LISTED_CONST_VALID( Func )			\
  ( VALUE_NON_MEMBER_LISTED_VALID( Func ) && ! is_reference< DECLTYPE_OF_NON_MEMBER_LISTED( Func ) >::value  && VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_CONST_VALID( _Listed_ , Func ) ) 

#define VALUE_NON_MEMBER_LISTED_NON_CONST_VALID( Func )			\
  ( VALUE_NON_MEMBER_LISTED_VALID( Func ) && ! is_reference< DECLTYPE_OF_NON_MEMBER_LISTED( Func ) >::value && ! VALUE_NON_MEMBER_LISTED_CONST_VALID( Func ) ) 

#define VALUE_NON_MEMBER_LISTED_REFERENCE_VALID( Func )			\
  ( VALUE_NON_MEMBER_LISTED_VALID( Func ) && is_reference< DECLTYPE_OF_NON_MEMBER_LISTED( Func ) >::value ) 

#define VALUE_NON_MEMBER_LISTED_INVALID( Func )	\
  ( ! VALUE_NON_MEMBER_LISTED_VALID( Func ) ) 

#define VALUE_NON_MEMBER_LISTED_TRUE( Func )				\
  ( VALUE_NON_MEMBER_LISTED_VALID( Func ) && VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_TRUE( _Listed_ , Func ) ) 

#define VALUE_NON_MEMBER_LISTED_CONST_TRUE( Func )			\
  ( VALUE_NON_MEMBER_LISTED_TRUE( Func ) && VALUE_NON_MEMBER_LISTED_CONST_VALID( Func ) ) 

#define VALUE_NON_MEMBER_LISTED_NON_CONST_TRUE( Func )			\
  ( VALUE_NON_MEMBER_LISTED_TRUE( Func ) && ! VALUE_NON_MEMBER_LISTED_CONST_TRUE( Func ) ) 

#define VALUE_NON_MEMBER_LISTED_FALSE( Func )				\
  ( VALUE_NON_MEMBER_LISTED_VALID( Func ) && ! VALUE_NON_MEMBER_LISTED_TRUE( Func ) ) 

#define TYPE_ALIAS_FOR_NON_MEMBER_LISTED_VALID( Func ) \
									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( ConstValid_ , Func ), _Listed ) = enable_if< VALUE_NON_MEMBER_LISTED_CONST_VALID( Func ) , list< DECLTYPE_OF_NON_MEMBER_LISTED( Func ) > >; \
									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( NonConstValid_ , Func ), _Listed ) = enable_if< VALUE_NON_MEMBER_LISTED_NON_CONST_VALID( Func ) , list< DECLTYPE_OF_NON_MEMBER_LISTED( Func ) > >; \
									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( ReferenceValid_ , Func ), _Listed ) = enable_if< VALUE_NON_MEMBER_LISTED_NON_CONST_VALID( Func ) , list<int> >; \

// RetÇÕîÒéQè∆å^ÇÃÇ›ãñóeÅB
#define TYPE_ALIAS_FOR_NON_MEMBER_LISTED_INVALID( Func , Ret )		\
									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( Invalid_ , Func ) , _Listed ) = enable_if< VALUE_NON_MEMBER_LISTED_INVALID( Func ) , list< Ret > >; \
									\

#define TYPE_ALIAS_FOR_NON_MEMBER_LISTED_TRUE( Func , Ret )		\
									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( ConstTrue_ , Func ) , _Listed ) = enable_if< VALUE_NON_MEMBER_LISTED_CONST_TRUE( Func ) , list<TypeOfToValue< DECLTYPE_OF_NON_MEMBER_LISTED( Func ) , Ret > > >; \
									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( NonConstTrue_ , Func ) , _Listed ) = enable_if< VALUE_NON_MEMBER_LISTED_NON_CONST_TRUE( Func ) , list<TypeOfToValue< DECLTYPE_OF_NON_MEMBER_LISTED( Func ) , Ret > > >; \
									\

#define TYPE_ALIAS_FOR_NON_MEMBER_LISTED_FALSE( Func , Ret )		\
									\
  template <typename Arg1 , typename... Arg2>				\
  using CONNECT( CONNECT( False_ , Func ) , _Listed ) = enable_if< VALUE_NON_MEMBER_LISTED_FALSE( Func ) , list< Ret > >; \
									\

#define TYPE_OF_NON_MEMBER_LISTED( val_ , Func )			\
  TYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( val_ , Func , _Listed ) 

#define DECLARATION_OF_NON_MEMBER_LISTED_CONST_VALID( Func )		\
									\
  template <typename Arg1 , typename... Arg2> TYPE_OF_NON_MEMBER_LISTED( ConstValid_ , Func ) ( CONNECT( Func , _Listed ) )( const list<Arg1>& arg1 , const list<Arg2>&... arg2 ) \

#define DECLARATION_OF_NON_MEMBER_LISTED_NON_CONST_VALID( Func )	\
									\
  template <typename Arg1 , typename... Arg2> TYPE_OF_NON_MEMBER_LISTED( NonConstValid_ , Func ) ( CONNECT( Func , _Listed ) )( list<Arg1>& arg1 , const list<Arg2>&... arg2 ) \

#define DECLARATION_OF_NON_MEMBER_LISTED_REFERENCE_VALID( Func )	\
									\
  template <typename Arg1 , typename... Arg2> TYPE_OF_NON_MEMBER_LISTED( ReferenceValid_ , Func ) ( CONNECT( Func , _Listed ) )( const list<Arg1>& arg1 , const list<Arg2>&... arg2 ) \

#define DECLARATION_OF_NON_MEMBER_LISTED_INVALID( Func )		\
									\
  template <typename Arg1 , typename... Arg2> TYPE_OF_NON_MEMBER_LISTED( Invalid_ , Func ) ( CONNECT( Func , _Listed ) )( const list<Arg1>& arg1 , const list<Arg2>&... arg2 ) \

#define DECLARATION_OF_NON_MEMBER_LISTED_CONST_TRUE( Func )		\
									\
  template <typename Arg1 , typename... Arg2> TYPE_OF_NON_MEMBER_LISTED( ConstTrue_ , Func ) ( CONNECT( Func , _Listed ) )( const list<Arg1>& arg1 , const list<Arg2>&... arg2 ) \

#define DECLARATION_OF_NON_MEMBER_LISTED_NON_CONST_TRUE( Func )		\
									\
  template <typename Arg1 , typename... Arg2> TYPE_OF_NON_MEMBER_LISTED( NonConstTrue_ , Func ) ( CONNECT( Func , _Listed ) )( list<Arg1>& arg1 , const list<Arg2>&... arg2 ) \

#define DECLARATION_OF_NON_MEMBER_LISTED_FALSE( Func )			\
									\
  template <typename Arg1 , typename... Arg2> TYPE_OF_NON_MEMBER_LISTED( False_ , Func ) ( CONNECT( Func , _Listed ) )( const list<Arg1>& arg1 , const list<Arg2>&... arg2 ) \

#define DEFINITION_OF_NON_MEMBER_LISTED_VALID( Func )			\
									\
  DECLARATION_OF_NON_MEMBER_LISTED_CONST_VALID( Func )			\
  {									\
									\
    TYPE_OF_NON_MEMBER_LISTED( ConstValid_ , Func ) ret;		\
									\
    for( typename list<Arg1>::const_iterator itr = arg1.begin() , end = arg1.end() ; itr != end ; itr++ ){ \
									\
      ret.push_back( to_Value< DECLTYPE_OF_NON_MEMBER_LISTED( Func ) , Ret >( ( Func )( *itr ) ) ); \
									\
    }									\
									\
    return ret;								\
									\
  }									\
									\
  DECLARATION_OF_NON_MEMBER_LISTED_NON_CONST_VALID( Func )		\
  {									\
									\
    TYPE_OF_NON_MEMBER_LISTED( NonConstValid_ , Func ) ret;		\
									\
    for( typename list<Arg1>::iterator itr = arg1.begin() , end = arg1.end() ; itr != end ; itr++ ){ \
									\
      ret.push_back( to_Value< DECLTYPE_OF_NON_MEMBER_LISTED( Func ) , Ret >( ( Func )( *itr ) ) ); \
									\
    }									\
									\
    return ret;								\
									\
  }									\
									\
  DECLARATION_OF_NON_MEMBER_LISTED_REFERENCE_VALID( Func )		\
  {									\
									\
    ERR_INPUT( arg1 , arg2... );					\
    return list<int>();							\
									\
  }									\
									\

#define DEFINITION_OF_NON_MEMBER_LISTED_INVALID( Func , Ret )	\
								\
  DECLARATION_OF_NON_MEMBER_LISTED_INVALID( Func )		\
  {								\
								\
    ERR_INPUT( arg1 , arg2... );				\
    return list< Ret >();					\
								\
  }								\
								\
  
#define DEFINITION_OF_NON_MEMBER_LISTED_TRUE( Func , Ret )		\
									\
  DECLARATION_OF_NON_MEMBER_LISTED_CONST_TRUE( Func )			\
  {									\
									\
    list< Ret > ret;							\
									\
    for( typename list<Arg1>::const_iterator itr = arg1.begin() , end = arg1.end() ; itr != end ; itr++ ){ \
									\
      ret.push_back( to_ValueOrReference< DECLTYPE_OF_NON_MEMBER_LISTED( Func ) , Ret >( ( Func )( *itr ) ) ); \
									\
    }									\
									\
    return ret;								\
									\
  }									\
									\
  DECLARATION_OF_NON_MEMBER_LISTED_NON_CONST_TRUE( Func )		\
  {									\
									\
    list< Ret > ret;							\
									\
    for( typename list<Arg1>::iterator itr = arg1.begin() , end = arg1.end() ; itr != end ; itr++ ){ \
									\
      ret.push_back( to_ValueOrReference< DECLTYPE_OF_NON_MEMBER_LISTED( Func ) , Ret >( ( Func )( *itr ) ) ); \
									\
    }									\
									\
    return ret;								\
									\
  }									\
									\

#define DEFINITION_OF_NON_MEMBER_LISTED_FALSE( Func , Ret )	\
								\
  DECLARATION_OF_NON_MEMBER_LISTED_FALSE( Func )		\
  {								\
								\
    ERR_INPUT( arg1 , arg2... );				\
    return list< Ret >();					\
								\
  }								\
								\

#define TWO_WAYS_SFINAE_NON_MEMBER_LISTED_ALIAS( Func )			\
									\
  DEFINITION_OF_CALLABLE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _Listed_ , Func ); \
  DEFINITION_OF_IMPLY_TYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _Listed_ , Func );	\
  TYPE_ALIAS_FOR_NON_MEMBER_LISTED_VALID( Func );			\
  TYPE_ALIAS_FOR_NON_MEMBER_LISTED_INVALID( Func , int ); 
  
#define TWO_WAYS_SFINAE_NON_MEMBER_LISTED( Func )		\
								\
  DECLARATION_OF_NON_MEMBER_LISTED_CONST_VALID( Func );		\
  DECLARATION_OF_NON_MEMBER_LISTED_NON_CONST_VALID( Func );	\
  DECLARATION_OF_NON_MEMBER_LISTED_REFERENCE_VALID( Func );	\
  DECLARATION_OF_NON_MEMBER_LISTED_INVALID( Func ); 

#define TWO_WAYS_SFINAE_NON_MEMBER_LISTED_BODY( Func , Ret )	\
  								\
  DEFINITION_OF_NON_MEMBER_LISTED_VALID( Func , Ret );		\
  DEFINITION_OF_NON_MEMBER_LISTED_INVALID( Func , Ret ); 

#define THREE_WAYS_SFINAE_NON_MEMBER_LISTED_ALIAS( Func , Ret )		\
									\
  DEFINITION_OF_CALLABLE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _Listed_ , Func ); \
  DEFINITION_OF_IMPLY_TYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _Listed_ , Func );	\
  DEFINITION_OF_MATCH_TYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _Listed_ , Func , Ret ); \
  TYPE_ALIAS_FOR_NON_MEMBER_LISTED_TRUE( Func , Ret );			\
  TYPE_ALIAS_FOR_NON_MEMBER_LISTED_FALSE( Func , Ret );			\
  TYPE_ALIAS_FOR_NON_MEMBER_LISTED_INVALID( Func , Ret ); 
  
#define THREE_WAYS_SFINAE_NON_MEMBER_LISTED( Func )		\
								\
  DECLARATION_OF_NON_MEMBER_LISTED_CONST_TRUE( Func );		\
  DECLARATION_OF_NON_MEMBER_LISTED_NON_CONST_TRUE( Func );	\
  DECLARATION_OF_NON_MEMBER_LISTED_FALSE( Func );		\
  DECLARATION_OF_NON_MEMBER_LISTED_INVALID( Func ); 

#define THREE_WAYS_SFINAE_NON_MEMBER_LISTED_BODY( Func , Ret )	\
  								\
  DEFINITION_OF_NON_MEMBER_LISTED_TRUE( Func , Ret );		\
  DEFINITION_OF_NON_MEMBER_LISTED_FALSE( Func , Ret );		\
  DEFINITION_OF_NON_MEMBER_LISTED_INVALID( Func , Ret ); 
