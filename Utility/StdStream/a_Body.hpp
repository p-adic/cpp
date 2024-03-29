// c:/Users/user/Documents/Programming/Utility/StdStream/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../String/a_Body.hpp"

template <class Traits> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is ) { return is; }
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is , Arg& arg , ARGS&... args ) { return VariadicCin( is >> arg , args... ); }

template <class Traits> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator ) { return is; }
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator , Arg& arg , ARGS&... args ) { return VariadicGetline( getline( is , arg , separator ) , separator , args... ); }

DEFINITION_OF_COUT_FOR_VECTOR( vector );
DEFINITION_OF_COUT_FOR_VECTOR( list );
DEFINITION_OF_COUT_FOR_VECTOR( set );
DEFINITION_OF_COUT_FOR_VECTOR( unordered_set );
template <class Traits , typename Arg1 , typename Arg2> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const pair<Arg1,Arg2>& arg ) { return os << arg.first << " " << arg.second; }

template <class Traits , typename Arg> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , const Arg& arg ) { return os << arg; }
template <class Traits , typename Arg1 , typename Arg2 , typename... ARGS> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , const Arg1& arg1 , const Arg2& arg2 , const ARGS&... args ) { return VariadicCout( os << arg1 << " " , arg2 , args... ); }

template <class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& is , const type_info& type ) noexcept { return is << to_string( type ); }
