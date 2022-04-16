// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/a_Alias.hpp

#pragma once
#include "../EmptySet/a.hpp"

template <uint i , typename... T0> class TypeOfRestrictToRight_Body;

template <uint i>
class TypeOfRestrictToRight_Body<i> :
  public EmptySet
{

public:
  using type = EmptySet;

};

template <>
class TypeOfRestrictToRight_Body<0> :
  public EmptySet
{

public:
  using type = DirectProduct<>;

};

template <uint i , typename T0 , typename... T1>
class TypeOfRestrictToRight_Body<i,T0,T1...> :
  public TypeOfRestrictToRight_Body<i-1,T1...>
{};

template <typename T0 , typename... T1>
class TypeOfRestrictToRight_Body<0,T0,T1...> :
  public EmptySet
{

public:
  using type = DirectProduct<T0,T1...>;

};

template <uint i , typename... T0> class TypeOfRestrictToLeft_Body;

template <uint i>
class TypeOfRestrictToLeft_Body<i> :
  public EmptySet
{

public:
  using type = EmptySet;

};

template <>
class TypeOfRestrictToLeft_Body<0> :
  public EmptySet
{

public:
  using type = DirectProduct<>;

};

template <uint i , typename T0 , typename... T1>
class TypeOfRestrictToLeft_Body<i,T0,T1...> :
  public EmptySet
{

public:
  using type = typename conditional< less_equal<uint>()( i , sizeof...( T1 ) + 1 ) , decltype( Connect( declval<DirectProduct<T0> >() , declval<typename TypeOfRestrictToLeft_Body<i-1,T1...>::type>() , Em@tySet ) ) >::type;

};

template <typename T0 , typename... T1>
class TypeOfRestrictToLeft_Body<0,T0,T1...> :
  public EmptySet
{

public:
  using type = DirectProduct<>;

};

template <uint i , typename... T0> class TypeOfProjection_Body;

template <uint i>
class TypeOfProjection_Body<i> :
  public EmptySet
{

public:
  using type = EmptySet;

};

template <uint i , typename T0 , typename... T1>
class TypeOfProjection_Body<i,T0,T1...> :
  public TypeOfProjection_Body<i-1,T1...>
{};

template <typename T0 , typename... T1>
class TypeOfProjection_Body<0,T0,T1...> :
  public EmptySet
{

public:
  using type = T0;

};

template <uint i , typename... T0>
using TypeOfRestrictToRight = typename TypeOfRestrictToRight_Body<i,T0...>::type;

template <uint i , typename... T0>
using TypeOfRestrictToLeft = typename TypeOfRestrictToLeft_Body<i,T0...>::type;

template <typename T0 , typename... T1>
using TypeOfIgnoreFinal = TypeOfRestrictToLeft<sizeof...( T1 ),T0,T1...>;

template <uint i , typename... T0>
using TypeOfProjection = typename TypeOfProjection_Body<i,T0...>::type;

template <typename T0 , typename... T1>
using TypeOfFinal = TypeOfProjection<sizeof...(T1),T0,T1...>;
