// Normalised_Alias.hpp

#pragma once

// THREE_WAYS_SFINAE_NON_MEMBER_CONSTIFIED_ALIAS( to_string , string );
DEFINITION_OF_CALLABLE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _Constified_ , to_string );
DEFINITION_OF_IMPLY_TYPE_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( _Constified_ , to_string );

template <typename Arg1 , typename... Arg2>
class CONNECT( CONNECT( match_TypeOf_non_member_with_at_least_one_variable , _Constified_ ) , to_string ) :
  public EmptySet
{

private:
  template <typename A1 , typename... A2 >
  static auto Check() -> typename enable_if< is_same< TypeOfToValue< typename CONNECT( CONNECT( imply_TypeOf_non_member_with_at_least_one_variable , _Constified_ ) , to_string )<A1,A2...> ::type , string > , string >::value , true_type >::type;
    
  template <typename A1 , typename... A2 >
  static auto Check() -> typename enable_if< ! ( is_same< TypeOfToValue< typename CONNECT( CONNECT( imply_TypeOf_non_member_with_at_least_one_variable , _Constified_ ) , to_string )<A1,A2...> ::type , string > , string >::value ) , false_type >::type;

public:
  static const bool value = decltype( Check<Arg1,Arg2...>() )::value;

};

template <typename Arg1 , typename... Arg2>
class CONNECT( CONNECT( match_TypeOf_non_member_with_at_least_one_variable , _Constified_const_ ) , to_string ) :
  public EmptySet
{

private:
  template <typename A1 , typename... A2 >
  static auto Check() -> typename enable_if< is_same< TypeOfToValue< typename CONNECT( CONNECT( imply_TypeOf_non_member_with_at_least_one_variable , _Constified_const_ ) , to_string )<A1,A2...> ::type , string > , string >::value , true_type >::type;

  template <typename A1 , typename... A2 >
  static auto Check() -> typename enable_if< ! ( is_same< TypeOfToValue< typename CONNECT( CONNECT( imply_TypeOf_non_member_with_at_least_one_variable , _Constified_const_ ) , to_string )<A1,A2...> ::type , string > , string >::value ) , false_type >::type;

public:
  static const bool value = decltype( Check<Arg1,Arg2...>() )::value;

};

template <typename Arg1 , typename... Arg2>
using CONNECT( CONNECT( ConstTrue_ , to_string ) , _Constified ) = enable_if< VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_CONST_TRUE( _Constified_ , to_string ) , string >;

template <typename Arg1 , typename... Arg2>
using CONNECT( CONNECT( NonConstTrue_ , to_string ) , _Constified ) = enable_if< VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_NON_CONST_TRUE( _Constified_ , to_string ) , string >;

template <typename Arg1 , typename... Arg2>
using CONNECT( CONNECT( False_ , to_string ) , _Constified ) = enable_if< VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_FALSE( _Constified_ , to_string ) , string >;

template <typename Arg1 , typename... Arg2>
using CONNECT( CONNECT( Invalid_ , to_string ) , _Constified ) = enable_if< VALUE_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE_INVALID( _Constified_ , to_string ) , string >;
