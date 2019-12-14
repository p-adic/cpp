// SFINAE/a_Alias.hpp

#pragma once

template <typename T , typename Ret>
using FromValueToValue = enable_if< is_same<T,Ret>::value , Ret >;

template <typename T , typename Ret>
using FromPointerToValue = enable_if< is_PointerOf<T,Ret>::value , Ret >;

template <typename T , typename Ret>
using FromReferenceToValue = enable_if< is_ReferenceOf<T,Ret>::value , Ret >;

template <typename T , typename Ret>
using InvalidToValue = enable_if< ! is_same<T,Ret>::value && ! is_PointerOf<T,Ret>::value && ! is_ReferenceOf<T,Ret>::value , false_type >;

template <typename T , typename Ret>
using FromValueToValueOrReference = enable_if< is_same<T,Ret>::value , Ret >;

template <typename T , typename Ret>
using FromPointerToValueOrReference = enable_if< is_PointerOf<T,Ret>::value , const Ret& >;

template <typename T , typename Ret>
using FromReferenceToValueOrReference = enable_if< is_ReferenceOf<T,Ret>::value , const Ret& >;

template <typename T , typename Ret>
using InvalidToValueOrReference = enable_if< ! is_same<T,Ret>::value && ! is_PointerOf<T,Ret>::value && ! is_ReferenceOf<T,Ret>::value , false_type >;

template <typename T , typename Ret>
class TypeOfToValue_Body :
  public EmptySet
{

private:
  template <typename U , typename R>
  static auto Check() -> typename FromValueToValue<U,R>::type;

  template <typename U , typename R>
  static auto Check() -> typename FromPointerToValue<U,R>::type;

  template <typename U , typename R>
  static auto Check() -> typename FromReferenceToValue<U,R>::type;

  template <typename U , typename R>
  static auto Check() -> typename InvalidToValue<U,R>::type;

public:
  using type = decltype( Check<T,Ret>() );

};

template <typename T , typename Ret>
class TypeOfToValueOrReference_Body :
  public EmptySet
{

private:
  template <typename U , typename R>
  static auto Check() -> typename FromValueToValueOrReference<U,R>::type;

  template <typename U , typename R>
  static auto Check() -> typename FromPointerToValueOrReference<U,R>::type;

  template <typename U , typename R>
  static auto Check() -> typename FromReferenceToValueOrReference<U,R>::type;

  template <typename U , typename R>
  static auto Check() -> typename InvalidToValueOrReference<U,R>::type;

public:
  using type = decltype( Check<T,Ret>() );

};

template <typename T , typename Ret>
using TypeOfToValue = typename TypeOfToValue_Body<T,Ret>::type;

template <typename T , typename Ret>
using TypeOfToValueOrReference = typename TypeOfToValueOrReference_Body<T,Ret>::type;
