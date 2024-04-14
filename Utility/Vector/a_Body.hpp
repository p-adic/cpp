// c:/Users/user/Documents/Programming/Utility/Vector/a_Body.hpp

#pragma once
#include "a.hpp"

inline void VariadicResize( const int& size ) {}
template <typename Arg , typename... ARGS> inline void VariadicResize( const int& size , Arg& arg , ARGS&... args ) { arg.resize( size ); VariadicResize( size , args... ); }

