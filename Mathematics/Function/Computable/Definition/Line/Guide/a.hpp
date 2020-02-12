// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Line/Guide/a.hpp

#pragma once
#include "../../../../../SetTheory/EmptySet/a.hpp"

template <typename... ARGS> class CheckNonVoidType;
template<typename Arg1, typename Arg2> class CheckNonVoidType_Body;

template <>
class CheckNonVoidType<> :
  public EmptySet
{

public:
  using type = void;

};

template <typename Arg1>
class CheckNonVoidType<Arg1> :
  public EmptySet
{

public:
  using type = Arg1;

};

template <typename Arg1, typename Arg2>
class CheckNonVoidType<Arg1,Arg2> :
  public EmptySet
{

public:
  using type = typename CheckNonVoidType_Body<Arg1,Arg2>::type;

};

template <typename Arg1, typename Arg2, typename Arg3, typename... ARGS>
class CheckNonVoidType<Arg1,Arg2,Arg3,ARGS...> :
  public EmptySet
{

public:
  using type = typename CheckNonVoidType_Body<Arg1,typename CheckNonVoidType<Arg2,Arg3,ARGS...>::type>::type;

};

template<typename Arg1, typename Arg2>
class CheckNonVoidType_Body :
  public EmptySet
{

public:
  using type = Arg1;

};

template<typename Arg2>
class CheckNonVoidType_Body<void,Arg2> :
  public EmptySet
{

public:
  using type = Arg2;

};

template<typename Arg1, typename Arg2>
class IsSameOrVoid :
  public EmptySet
{

public:
  static constexpr const bool value = ( is_same<Arg1,Arg2>::value || is_void<Arg2>::value );

};

#include "a_Alias.hpp"
