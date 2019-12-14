// String_Alias.hpp

#pragma once

// THREE_WAYS_SFINAE_MEMBER_ALIAS( Display , string );
DEFINITION_OF_CALLABLE_MEMBER( Display );
DEFINITION_OF_IMPLY_TYPE_OF_MEMBER( Display );

template <typename T , typename... Args>
class CONNECT( match_TypeOf_member_ , Display ) :
  public EmptySet
{

private:
  template <typename U , typename... A >
  static auto Check() -> typename enable_if< is_same< typename CONNECT( imply_TypeOf_member_ , Display )<U,A...> ::type , string >::value || is_ReferenceOf< typename CONNECT( imply_TypeOf_member_ , Display )<U,A...> ::type , string >::value , true_type >::type;

  template <typename U , typename... A >	
  static auto Check() -> typename enable_if< ! ( is_same< typename CONNECT( imply_TypeOf_member_ , Display )<U,A...> ::type , string >::value || is_ReferenceOf< typename CONNECT( imply_TypeOf_member_ , Display )<U,A...> ::type , string >::value ) , false_type >::type;

public:
  static const bool value = decltype( Check<T,Args...>() )::value;

};

template <typename T , typename... Args>
class CONNECT( match_TypeOf_member_const_ , Display ) :
  public EmptySet
{

private:
  template <typename U , typename... A >
  static auto Check() -> typename enable_if< is_same< typename CONNECT( imply_TypeOf_member_const_ , Display )<U,A...> ::type , string >::value || is_ReferenceOf< typename CONNECT( imply_TypeOf_member_const_ , Display )<U,A...> ::type , string >::value , true_type >::type;

  template <typename U , typename... A >
  static auto Check() -> typename enable_if< ! ( is_same< typename CONNECT( imply_TypeOf_member_const_ , Display )<U,A...> ::type , string >::value || is_ReferenceOf< typename CONNECT( imply_TypeOf_member_const_ , Display )<U,A...> ::type , string >::value ) , false_type >::type;

public:
  static const bool value = decltype( Check<T,Args...>() )::value;

};

template <typename T , typename... Args>
using CONNECT( ConstTrue_ , to_string ) = enable_if< VALUE_MEMBER_CONST_TRUE( Display ) , TypeOfToValueOrReference< DECLTYPE_OF_MEMBER( _const_ , Display ) , string > >;

template <typename T , typename... Args>
using CONNECT( NonConstTrue_ , to_string ) = enable_if< VALUE_MEMBER_NON_CONST_TRUE( Display ) , TypeOfToValueOrReference< DECLTYPE_OF_MEMBER( _ , Display ) , string > >;

template <typename T , typename... Args>
using CONNECT( False_ , to_string ) = enable_if< VALUE_MEMBER_FALSE( Display ) , string >;

template <typename T , typename... Args>
using CONNECT( Invalid_ , to_string ) = enable_if< VALUE_MEMBER_INVALID( Display ) , string >;
