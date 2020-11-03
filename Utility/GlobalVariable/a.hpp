// c:/Users/user/Documents/Programming/Utility/GlobalVariable/a.hpp

#pragma once
#include "a_Macro.hpp"

template <typename T , typename... Args> const T* const to_GlobalConstant( const string& name , const Args&... args );

template <typename T , typename... Args> T* const to_GlobalVariable( const string& name , const Args&... args );

template <typename T , typename... Args> T* to_GlobalPointer( const string& name , const Args&... args );
