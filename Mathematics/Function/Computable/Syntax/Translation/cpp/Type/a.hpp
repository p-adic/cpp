// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Type/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "a_Alias.hpp"

inline string WrapInParenthesis( const string& arg );

template <typename Arg> inline auto ConcatenateWithSeparator( const string& s , const Arg& arg ) -> typename enable_if<is_same<Arg,string>::value,string>::type;

template <typename Arg1, typename Arg2, typename... Args> inline auto ConcatenateWithSeparator( const string& s , const Arg1& arg1 , const Arg2& arg2 , const Args&... args ) -> typename enable_if<is_same<Arg1,string>::value && is_same<Arg2,string>::value && conjunction<is_same<Args,string>...>::value,string>::type;

template <typename Arg, typename... Args> inline string ArgumentString( const Arg& arg , const Args&... args );
template <typename Arg, typename... Args> inline string TypeString();
template <typename Arg, typename... Args> inline string TypeAndArgumentString( const Arg& arg , const Args&... args );

