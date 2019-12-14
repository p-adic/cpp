// c:/Users/user/Documents/Programming/Utility/VLArray/Wrap/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename Arg> template <typename... ARGS> inline WrapForVLArray<Arg>::WrapForVLArray( const ARGS&... args ) : m_t( args... ) {}

template <typename Arg> inline const Arg& WrapForVLArray<Arg>::Get() const noexcept { return m_t; }
