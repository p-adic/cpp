// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Variadic/Guide/a.hpp

#pragma once
#include "../../../../../../SFINAE/MetaFunction/IsIncludedBy/a.hpp"

template <typename VArg, typename... Types1>
class IsValidVariadicArguments_Body :
  public EmptySet
{

public:
  template <typename... Types2> static auto CheckValid( const Types1&... , const Types2&... ) -> typename enable_if<conjunction<is_same<VArg,Types2>...>::value,true_type>::type;

  static false_type CheckValid( ... );

};

template <typename Wrap1, typename VArg, typename Wrap2>
class IsValidVariadicArguments :
  public EmptySet
{

public:
  static constexpr const bool value = false;

};

template <typename VArg, typename... Types1, typename... Types2>
class IsValidVariadicArguments<VArg,WrappedTypes<Types1...>,WrappedTypes<Types2...> > :
  public EmptySet
{

public:
  static constexpr const bool value = decltype( IsValidVariadicArguments_Body<VArg,Types1...>::CheckValid( declval<Types2>()... ) )::value;

};
