// c:/Users/user/Documents/Programming/SFINAE/MemberFunction/Constructor/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../a.hpp"

#include "a_Alias.hpp"

template <typename T , typename... Args> inline TYPE_OF_CONSTRUCTOR_VALID Construct( const Args&... args );
template <typename T , typename... Args> inline TYPE_OF_CONSTRUCTOR_INVALID Construct( const Args&... args );
