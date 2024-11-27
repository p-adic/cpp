// Angle/a_body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../Arithmetic/Mod/ConstexprModulo/a_Body.hpp"
#include <cmath>

template <typename... ARGS> inline Angle::Angle( const ARGS&... args ) noexcept : Mod<360>( args... ){}
inline Angle::Angle( const Angle& n ) noexcept : Mod<360>( n ){}
inline Angle::Angle( Angle&& n ) noexcept : Mod<360>( move( n ) ){}

inline Angle& Angle::operator=( const int& n ) noexcept { Mod<360>::operator=( n ); return *this; }
inline Angle& Angle::operator=( const Angle& n ) noexcept { Mod<360>::operator=( n ); return *this; }
inline Angle& Angle::operator=( Angle&& n ) noexcept { Mod<360>::operator=( move( n ) ); return *this; }

inline Angle& Angle::operator/=( const int& n ) { m_n /= n; return *this; }
inline Angle& Angle::operator/=( const Angle& n ) { m_n /= n.m_n; return *this; }

inline float Angle::Represent() const noexcept { return ( Mod<360>::Represent() * pi ) / 180.0; };

inline Angle operator/( const Angle& n0 , const int& n1 ) { return move( Angle( n0 ) /= n1 ); }
inline Angle operator/( const Angle& n0 , const Angle& n1 ) { return move( Angle( n0 ) /= n1 ); }

inline float sin( const Angle& c ){ return sin( c.Represent() ); }
inline float cos( const Angle& c ){ return cos( c.Represent() ); }
