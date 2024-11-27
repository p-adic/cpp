// c:/Users/user/Documents/Programming/Utility/StdStream/a.hpp

#pragma once
#include "a_Macro.hpp"

#include <bits/stdc++.h>

template <class Traits> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is );
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is , Arg& arg , ARGS&... args );
template <class Traits> inline basic_istream<char,Traits>& VariadicSet( basic_istream<char,Traits>& is , const int& i );
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicSet( basic_istream<char,Traits>& is , const int& i , Arg& arg , ARGS&... args );

template <class Traits> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator );
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator , Arg& arg , ARGS&... args );

template <class Traits , typename Arg> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , Arg&& arg );
template <class Traits , typename Arg1 , typename Arg2 , typename... ARGS> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , Arg1&& arg1 , Arg2&& arg2 , ARGS&&... args );

template <class Traits , typename Arg> inline basic_ostream<char,Traits>& VariadicCoutNonSep( basic_ostream<char,Traits>& os , Arg&& arg );
template <class Traits , typename Arg1 , typename Arg2 , typename... ARGS> inline basic_ostream<char,Traits>& VariadicCoutNonSep( basic_ostream<char,Traits>& os , Arg1&& arg1 , Arg2&& arg2 , ARGS&&... args );

template <class Traits , typename ARRAY> inline basic_ostream<char,Traits>& CoutArray( basic_ostream<char,Traits>& os , const int& i_start , const int& i_ulim , ARRAY&& a );
