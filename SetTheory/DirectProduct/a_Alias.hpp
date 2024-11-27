// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/a_Alias.hpp

#pragma once
#include "../EmptySet/a.hpp"

template <uint i , typename... T0> class TypeOfFinalSegment_Body;

template <uint i>
class TypeOfFinalSegment_Body<i> :
  public EmptySet
{

public:
  using const_type = EmptySet;
  using type = EmptySet;

};

template <>
class TypeOfFinalSegment_Body<0> :
  public EmptySet
{

public:
  using const_type = const DirectProduct<>&;
  using type = DirectProduct<>&;

};

template <uint i , typename T0 , typename... T1>
class TypeOfFinalSegment_Body<i,T0,T1...> :
  public TypeOfFinalSegment_Body<i-1,T1...>
{};

template <typename T0 , typename... T1>
class TypeOfFinalSegment_Body<0,T0,T1...> :
  public EmptySet
{

public:
  using const_type = const DirectProduct<T0,T1...>&;
  using type = DirectProduct<T0,T1...>&;

};

template <uint i , typename... T0> class TypeOfInitialSegment_Body;

template <uint i>
class TypeOfInitialSegment_Body<i> :
  public EmptySet
{

public:
  using type = EmptySet;

};

template <>
class TypeOfInitialSegment_Body<0> :
  public EmptySet
{

public:
  using type = DirectProduct<>;

};

template <uint i , typename T0 , typename... T1>
class TypeOfInitialSegment_Body<i,T0,T1...> :
  public EmptySet
{

public:
  using type = typename conditional< less_equal<uint>()( i , sizeof...( T1 ) + 1 ) , decltype( Connect( declval<DirectProduct<T0> >() , declval<typename TypeOfInitialSegment_Body<i-1,T1...>::type>() ) ) , EmptySet >::type;

};

template <typename T0 , typename... T1>
class TypeOfInitialSegment_Body<0,T0,T1...> :
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
  using const_type = EmptySet;
  using type = EmptySet;

};

template <typename T0 , typename... T1>
class TypeOfProjection_Body<0,T0,T1...> :
  public EmptySet
{

public:
  using const_type = const T0&;
  using type = T0&;

};

template <uint i , typename T0 , typename... T1>
class TypeOfProjection_Body<i,T0,T1...> :
  public TypeOfProjection_Body<i-1,T1...>
{};

template <uint i , typename... T0>
using ConstTypeOfFinalSegment = typename TypeOfFinalSegment_Body<i,T0...>::const_type;

template <uint i , typename... T0>
using TypeOfFinalSegment = typename TypeOfFinalSegment_Body<i,T0...>::type;

template <uint i , typename... T0>
using TypeOfInitialSegment = typename TypeOfInitialSegment_Body<i,T0...>::type;

template <uint i , typename... T0>
using ConstTypeOfProjection = typename TypeOfProjection_Body<i,T0...>::const_type;
template <uint i , typename... T0>
using TypeOfProjection = typename TypeOfProjection_Body<i,T0...>::type;
