// c:/Users/user/Documents/Programming/SFINAE/NonMemberFunction/ToValue/a_Macro.hpp

#pragma once
#include "../a_Macro.hpp"

#define TYPE_ALIAS_FOR_NON_MEMBER_TO_VALUE_TRUE( Func , Ret )		\
									\
  template <typename... Args>						\
  using CONNECT( CONNECT( True_ , Func ) , _ToValue ) = enable_if< VALUE_NON_MEMBER_WITH_CONST_VARIABLES_TRUE( _ToValue_ , Func ) , TypeOfToValue< DECLTYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ToValue_ , Func ) , Ret > >; \
									\

#define DEFINITION_OF_NON_MEMBER_TO_VALUE_TRUE( Func , Ret )		\
									\
  DECLARATION_OF_NON_MEMBER_WITH_CONST_VARIABLES( True_ , Func , _ToValue ) \
  {									\
									\
    return to_Value< DECLTYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ToValue_ , Func ) , Ret >( ( Func )( args... ) ); \
									\
  }									\
									\
  
#define DEFINITION_OF_NON_MEMBER_TO_VALUE_FALSE( Func , Ret )		\
									\
  DECLARATION_OF_NON_MEMBER_WITH_CONST_VARIABLES( False_ , Func  , _ToValue ) \
  {									\
									\
    ERR_INPUT( typeid( Ret ) , typeid( Args )... );			\
    return Ret ();							\
									\
  }									\
									\

#define DEFINITION_OF_NON_MEMBER_TO_VALUE_INVALID( Func , Ret )		\
									\
  DECLARATION_OF_NON_MEMBER_WITH_CONST_VARIABLES( Invalid_ , Func , _ToValue ) \
  {									\
									\
    ERR_INPUT( typeid( Ret ) , typeid( Args )... );			\
    return Ret ();							\
									\
  }									\
									\

#define THREE_WAYS_SFINAE_NON_MEMBER_TO_VALUE_ALIAS( Func , Ret )	\
  									\
  DEFINITION_OF_CALLABLE_NON_MEMBER_WITH_CONST_VARIABLES( _ToValue_ , Func ); \
  DEFINITION_OF_IMPLY_TYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ToValue_ , Func ); \
  DEFINITION_OF_MATCH_TYPE_OF_NON_MEMBER_WITH_CONST_VARIABLES( _ToValue_ , Func , Ret ); \
  TYPE_ALIAS_FOR_NON_MEMBER_TO_VALUE_TRUE( Func , Ret )			\
  TYPE_ALIAS_FOR_NON_MEMBER_WITH_CONST_VARIABLES_FALSE( _ToValue_ , Func , Ret , _ToValue ) \
  TYPE_ALIAS_FOR_NON_MEMBER_WITH_CONST_VARIABLES_INVALID( _ToValue_ , Func , Ret , _ToValue ) 
  
#define THREE_WAYS_SFINAE_NON_MEMBER_TO_VALUE( Func )			\
									\
  THREE_WAYS_SFINAE_NON_MEMBER_WITH_CONST_VARIABLES_UNIVERSAL( Func , _ToValue ) 

#define THREE_WAYS_SFINAE_NON_MEMBER_TO_VALUE_BODY( Func , Ret )	\
									\
  DEFINITION_OF_NON_MEMBER_TO_VALUE_TRUE( Func , Ret );			\
  DEFINITION_OF_NON_MEMBER_TO_VALUE_FALSE( Func , Ret );		\
  DEFINITION_OF_NON_MEMBER_TO_VALUE_INVALID( Func , Ret ) 
