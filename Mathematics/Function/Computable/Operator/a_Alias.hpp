// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/a_Alias.hpp

#pragma once

template <typename Ret, typename... Args>
class OperatorSymbol_Body :
  public EmptySet
{

public:

  using type = FunctionSymbol<Ret,Args...>;

};

template <typename... Args>
class OperatorSymbol_Body<bool,Args...> :
  public EmptySet
{

public:

  using type = RelationSymbol<Args...>;

};

template <typename Ret, typename... Args>
using OperatorSymbol = typename OperatorSymbol_Body<Ret,Args...>::type;


class VariadicOperatorSymbol_Body :
  public EmptySet
{

public:
  template <typename Ret, typename VArg, typename... Args> auto GetType( const WrappedTypes<Ret,VArg,Args...>()& ) -> typename enable_if<! is_same<Ret,bool>::value,VariadicFunctionSymbol<Ret,VArg,Args...> >::type;

  template <typename Ret, typename VArg, typename... Args> auto GetType( const WrappedTypes<Ret,VArg,Args...>()& ) -> typename enable_if<is_same<Ret,bool>::value,VariadicRelationSymbol<VArg,Args...> >::type;

};

template <typename Ret, typename VArg, typename... Args>
using VariadicOperatorSymbol = decltype( VariadicOperatorSymbol_Body::GetType( WrappedTypes<Ret,VArg,Args...>() ) );


class PrettyOperator_Body :
  public EmptySet
{

public:
  template <typename Ret, typename... Args> auto GetType( const WrappedTypes<Ret,Args...>& ) -> typename enable_if<! is_same<typename BaseTypeOf<Ret>::type,bool>::value,PrettyFunction<Ret,Args...> >::type;

  template <typename Ret, typename... Args> auto GetType( const WrappedTypes<Ret,Args...>& ) -> typename enable_if<is_same<typename BaseTypeOf<Ret>::type,bool>::value,PrettyRelation<Args...> >::type;

};

template <typename Ret, typename... Args>
using PrettyOperator = decltype( PrettyOperator_Body::GetType( WrappedTypes<Ret,Args...>() ) );


class PrettyVariadicOperator_Body :
  public EmptySet
{

public:
  template <typename Ret, typename VArg, typename... Args> auto GetType( const WrappedTypes<Ret,VArg,Args...>& ) -> typename enable_if<! is_same<typename BaseTypeOf<Ret>::type,bool>::value,PrettyVariadicFunction<Ret,VArg,Args...> >::type;

  template <typename Ret, typename VArg, typename... Args> auto GetType( const WrappedTypes<Ret,VArg,Args...>& ) -> typename enable_if<is_same<typename BaseTypeOf<Ret>::type,bool>::value,PrettyVariadicRelation<VArg,Args...> >::type;

};

template <typename Ret, typename VArg, typename... Args>
using PrettyVariadicOperator = decltype( PrettyVariadicOperator_Body::GetType( WrappedTypes<Ret,VArg,Args...>() ) );
