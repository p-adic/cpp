// c:/Users/user/Documents/Programming/SFINAE/a.hpp

#pragma once
#include "a_Macro.hpp"

#include <type_traits>
#include "../Utility/Header.hpp"

#include "MetaFunction/IsPointerOf/a.hpp"
#include "MetaFunction/IsReferenceOf/a.hpp"

#include "a_Alias.hpp"

template <typename T , typename Ret> auto to_Value( const T & ) -> typename FromValueToValue<T,Ret>::type;
template <typename T , typename Ret> auto to_Value( const T & ) -> typename FromPointerToValue<T,Ret>::type;
template <typename T , typename Ret> auto to_Value( const T & ) -> typename FromReferenceToValue<T,Ret>::type;
template <typename T , typename Ret> auto to_Value( const T & ) -> typename InvalidToValue<T,Ret>::type;

template <typename T , typename Ret> auto to_ValueOrReference( const T & ) -> typename FromValueToValueOrReference<T,Ret>::type;
template <typename T , typename Ret> auto to_ValueOrReference( const T & ) -> typename FromPointerToValueOrReference<T,Ret>::type;
template <typename T , typename Ret> auto to_ValueOrReference( const T & ) -> typename FromReferenceToValueOrReference<T,Ret>::type;
template <typename T , typename Ret> auto to_ValueOrReference( const T & ) -> typename InvalidToValueOrReference<T,Ret>::type;
