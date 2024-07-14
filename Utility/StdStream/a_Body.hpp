// c:/Users/user/Documents/Programming/Utility/StdStream/a_Body.hpp

#pragma once
#include "a.hpp"

// operator<<のオーバーロードを行うため、先にincludeする。
#include "../Tuple/a_Body.hpp"
#include "../Vector/a_Body.hpp"

template <class Traits> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is ) { return is; }
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is , Arg& arg , ARGS&... args ) { return VariadicCin( is >> arg , args... ); }
template <class Traits> inline basic_istream<char,Traits>& VariadicSet( basic_istream<char,Traits>& is , const int& i ) { return is; }
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicSet( basic_istream<char,Traits>& is , const int& i , Arg& arg , ARGS&... args ) { return VariadicSet( is >> arg[i] , i , args... ); }

template <class Traits> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator ) { return is; }
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator , Arg& arg , ARGS&... args ) { return VariadicGetline( getline( is , arg , separator ) , separator , args... ); }

template <class Traits , typename Arg> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , const Arg& arg ) { return os << arg; }
template <class Traits , typename Arg1 , typename Arg2 , typename... ARGS> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , const Arg1& arg1 , const Arg2& arg2 , const ARGS&... args ) { return VariadicCout( os << arg1 << " " , arg2 , args... ); }
