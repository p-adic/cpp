// c:/Users/user/Documents/Programming/Utility/StdStream/a.hpp

#pragma once
#include "a_Macro.hpp"

#include <bits/stdc++.h>
#include "../String/a.hpp"

template <class Traits> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is );
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is , Arg& arg , ARGS&... args );

template <class Traits> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator );
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator , Arg& arg , ARGS&... args );

DECLARATION_OF_COUT_FOR_VECTOR( vector );
DECLARATION_OF_COUT_FOR_VECTOR( list );
DECLARATION_OF_COUT_FOR_VECTOR( set );
DECLARATION_OF_COUT_FOR_VECTOR( unordered_set );
template <class Traits , typename Arg1 , typename Arg2> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const pair<Arg1,Arg2>& arg );

template <class Traits , typename Arg> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , const Arg& arg );
template <class Traits , typename Arg1 , typename Arg2 , typename... ARGS> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , const Arg1& arg1 , const Arg2& arg2 , const ARGS&... args );

template <class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& is , const type_info& type ) noexcept;
