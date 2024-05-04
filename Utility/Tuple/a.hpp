// c:/Users/user/Documents/Programming/Utility/Tuple/a.hpp

#pragma once
#include "a_Macro.hpp"

template <class Traits , typename T , typename U , template <typename...> typename V> inline auto operator>>( basic_istream<char,Traits>& is , V<T,U>& arg ) -> decltype((get<0>(arg),is))&;
template <class Traits , typename T , typename U , typename V> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , tuple<T,U,V>& arg );
template <class Traits , typename T , typename U , typename V , typename W> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , tuple<T,U,V,W>& arg );

template <class Traits , typename T , typename U , template <typename...> typename V> inline auto operator<<( basic_ostream<char,Traits>& os , const V<T,U>& arg ) -> decltype((get<0>(arg),os))&;
template <class Traits , typename T , typename U , typename V> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const tuple<T,U,V>& arg );
template <class Traits , typename T , typename U , typename V , typename W> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const tuple<T,U,V,W>& arg );

DECLARATION_OF_OPERATOR_FOR_TUPLE( + );
DECLARATION_OF_OPERATOR_FOR_TUPLE( - );
DECLARATION_OF_OPERATOR_FOR_TUPLE( * );
DECLARATION_OF_OPERATOR_FOR_TUPLE( / );
DECLARATION_OF_OPERATOR_FOR_TUPLE( % );

DECLARATION_OF_INCREMENT_FOR_TUPLE( ++ );
DECLARATION_OF_INCREMENT_FOR_TUPLE( -- );

#include "../Set/a.hpp"
template <typename T , typename U> DECLARATION_OF_HASH( pair<T,U> );
template <typename T , typename U> DECLARATION_OF_HASH( tuple<T,U> );
template <typename T , typename U , typename V> DECLARATION_OF_HASH( tuple<T,U,V> );
template <typename T , typename U , typename V , typename W> DECLARATION_OF_HASH( tuple<T,U,V,W> );

