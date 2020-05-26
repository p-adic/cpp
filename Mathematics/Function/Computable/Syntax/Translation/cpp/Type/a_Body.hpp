// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Type/a_Body.hpp

#pragma once
#include "a.hpp"

inline string WrapInParenthesis( const string& arg ) { return LparenString() + arg + RparenString(); }

template <typename Arg> inline auto ConcatenateWithSeparator( const string& s , const Arg& arg ) -> typename enable_if<is_same<Arg,string>::value,string>::type { return arg; }

template <typename Arg1, typename Arg2, typename... Args> inline auto ConcatenateWithSeparator( const string& s , const Arg1& arg1 , const Arg2& arg2 , const Args&... args ) -> typename enable_if<is_same<Arg1,string>::value && is_same<Arg2,string>::value && conjunction<is_same<Args,string>...>::value,string>::type { return arg1 + " " + s + " " + ConcatenateWithSeparator( s , arg2 , args... ); }


template <typename Arg, typename... Args> inline string ArgumentString( const Arg& arg , const Args&... args ) { return ConcatenateWithSeparator( CommaString() , CppClassForArgumentString<Arg>::GetString( arg ) , CppClassForArgumentString<Args>::GetString( args )... ); }

template <typename Arg, typename... Args> inline string TypeString() { return ConcatenateWithSeparator( CommaString() , CppClassForTypeString<Arg>::GetString() , CppClassForTypeString<Args>::GetString()... ); }

template <typename Arg, typename... Args> inline string TypeAndArgumentString( const Arg& arg , const Args&... args ) { return ConcatenateWithSeparator( CommaString() , CppClassForTypeAndArgumentString<Arg>::GetString( arg ) , CppClassForTypeAndArgumentString<Args>::GetString( args )... ); }


