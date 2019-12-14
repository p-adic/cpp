// Angle/a_body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../Arithmetic/Mod/a_Body.hpp"
#include <cmath>

template <typename... ARGS> inline Angle::Angle( const ARGS&... args ) noexcept : Mod<360>( args... ){}

inline float Angle::Represent() const noexcept { return ( Mod<360>::Represent() * pi ) / 180.0; };

inline float sin( const Angle& c ){ return sin( c.Represent() ); }
inline float cos( const Angle& c ){ return cos( c.Represent() ); }
