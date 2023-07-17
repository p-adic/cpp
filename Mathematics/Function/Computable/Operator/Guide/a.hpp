// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Guide/a.hpp

#pragma once
#include "../../../../SetTheory/EmptySet/a.hpp"
#include "../../../../../SFINAE/MetaFunction/IsIncludedBy/a.hpp"

// #include "../Function/a.hpp"
// #include "../Relation/a.hpp"
// #include "../../Expression/Variable/a.hpp"

// マクロIMPORTとDATAに用いる。

template <typename Ret> class VariableSymbol;
template <typename Ret> class VariadicVariableSymbol;
template <typename Ret, typename... Args> class FunctionSymbol;
template <typename... Args> class RelationSymbol;

template <typename Ret>
class OperatorSymbol_Guide :
  public EmptySet
{

public:
  // function
  template <typename... Args> static inline auto Get( const string& name , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) -> typename enable_if<! is_same<Ret,bool>::value && ! disjunction<is_base_of<VariableSymbol<void>,Args>...>::value,FunctionSymbol<Ret,Args...> >::type;

  // variadic function
  template <typename VArg, typename... Args> static inline auto Get( const string& name , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args , const VariadicVariableSymbol<VArg> ldots ) -> typename enable_if<! is_same<Ret,bool>::value && disjunction<is_base_of<VariableSymbol<void>,Args>...>::value ,VariadicFunctionSymbol<Ret,VArg,Args...> >::type;

};

template <>
class OperatorSymbol_Guide<bool> :
  public EmptySet
{

public:
  // relation
  template <typename... Args> static inline auto Get( const string& name , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) -> typename enable_if<! disjunction<is_base_of<VariableSymbol<void>,Args>...>::value ,RelationSymbol<Args...> >::type;

  // variadic relation
  template <typename VArg, typename... Args> static inline auto Get( const string& name , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args , const VariadicVariableSymbol<VArg> ldots ) -> typename enable_if<disjunction<is_base_of<VariableSymbol<void>,Args>...>::value ,VariadicRelationSymbol<VArg,Args...> >::type;

};


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
