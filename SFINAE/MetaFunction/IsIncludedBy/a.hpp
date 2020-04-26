// c:/Users/user/Documents/Programming/SFINAE/MetaFunction/IsIncludedBy/a.hpp

#pragma once
#include "../a.hpp"

template <typename... Types>
class WrappedTypes
{};

template <typename... Types1>
class IsIncludedBy_Body :
  public EmptySet
{

public:
  template <typename... Types2> static true_type CheckInclude( const Types1&... , const Types2&... );

  static false_type CheckInclude( ... );

};

DEFINITION_OF_CALLABLE_MEMBER( CheckInclude );

template <typename Wrap1, typename Wrap2>
class IsIncludedBy :
  public EmptySet
{

public:
  static constexpr const bool value = false;

};

template <typename... Types1, typename... Types2>
class IsIncludedBy<WrappedTypes<Types1...>,WrappedTypes<Types2...> > :
  public EmptySet
{

public:
  static constexpr const bool value = decltype( IsIncludedBy_Body<Types1...>::CheckInclude( declval<Types2>()... ) )::value;

};
