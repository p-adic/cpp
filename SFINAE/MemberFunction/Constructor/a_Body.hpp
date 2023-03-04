// c:/Users/user/Documents/Programming/SFINAE/MemberFunction/Constructor/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"

template <typename T , typename... Args> inline TYPE_OF_CONSTRUCTOR_VALID Construct( const Args&... args ){ return T( args... ); }

template <typename T , typename... Args> inline TYPE_OF_CONSTRUCTOR_INVALID Construct( const Args&... args ){ ERR_INPUT( typeid( T ) , args... ); return T(); }
