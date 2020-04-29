// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/a_Alias.hpp

#pragma once

class PrettyOperator_Body :
  public EmptySet
{

public:
  template <typename Ret, typename... Args> auto GetType( const WrappedTypes<Ret,Args...>()& ) -> typename enable_if<! is_same<typename BaseTypeOf<Ret>::type,bool>::value,PrettyFunction<Ret,Args...> >::type;

  template <typename Ret, typename... Args> auto GetType( const WrappedTypes<Ret,Args...>()& ) -> typename enable_if<is_same<typename BaseTypeOf<Ret>::type,bool>::value,PrettyRelation<Args...> >::type;

};

template <typename Ret, typename... Args>
using PrettyOperator = decltype( PrettyOperator_Body::GetType( WrappedTypes<Ret,Args...>() ) );

class PrettyVariadicOperator_Body :
  public EmptySet
{

public:
  template <typename Ret, typename VArg, typename... Args> auto GetType( const WrappedTypes<Ret,VArg,Args...>()& ) -> typename enable_if<! is_same<typename BaseTypeOf<Ret>::type,bool>::value,PrettyVariadicFunction<Ret,VArg,Args...> >::type;

  template <typename Ret, typename VArg, typename... Args> auto GetType( const WrappedTypes<Ret,VArg,Args...>()& ) -> typename enable_if<is_same<typename BaseTypeOf<Ret>::type,bool>::value,PrettyVariadicRelation<VArg,Args...> >::type;

};

template <typename Ret, typename VArg, typename... Args>
using PrettyVariadicOperator = decltype( PrettyVariadicOperator_Body::GetType( WrappedTypes<Ret,VArg,Args...>() ) );
