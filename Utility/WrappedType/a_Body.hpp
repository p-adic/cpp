// c:/Users/user/Documents/Programming/Utility/WrappedType/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename Arg> template <typename... ARGS> inline WrappedType<Arg>::WrappedType( const ARGS&... args ) : m_t( args... ) {}

template <typename Arg> inline void WrappedType<Arg>::Set( const Arg& t ){ m_t = t; }
template <typename Arg> inline const Arg& WrappedType<Arg>::Get() const noexcept { return m_t; }
