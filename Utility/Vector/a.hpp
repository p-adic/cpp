// c:/Users/user/Documents/Programming/Utility/Vector/a.hpp

#pragma once

#include <vector>

inline void VariadicResize( const int& size );
template <typename Arg , typename... ARGS> inline void VariadicResize( const int& size , Arg& arg , ARGS&... args );
