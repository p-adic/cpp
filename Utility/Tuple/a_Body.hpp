// c:/Users/user/Documents/Programming/Utility/Tuple/a_Body.hpp

#pragma once
#include "a.hpp"

template <class Traits , typename T , typename U , template <typename...> typename V> inline auto operator>>( basic_istream<char,Traits>& is , V<T,U>& arg ) -> decltype((get<0>(arg),is))& { return is >> get<0>( arg ) >> get<1>( arg ); }
template <class Traits , typename T , typename U , typename V> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , tuple<T,U,V>& arg ) { return is >> get<0>( arg ) >> get<1>( arg ) >> get<2>( arg ); }
template <class Traits , typename T , typename U , typename V , typename W> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , tuple<T,U,V,W>& arg ) { return is >> get<0>( arg ) >> get<1>( arg ) >> get<2>( arg ) >> get<3>( arg ); }

template <class Traits , typename T , typename U , template <typename...> typename V> inline auto operator<<( basic_ostream<char,Traits>& os , const V<T,U>& arg ) -> decltype((get<0>(arg),os))& { return os << get<0>( arg ) << " " << get<1>( arg ); }
template <class Traits , typename T , typename U , typename V> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const tuple<T,U,V>& arg ) { return os << get<0>( arg ) << " " << get<1>( arg ) << " " << get<2>( arg ); }
template <class Traits , typename T , typename U , typename V , typename W> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const tuple<T,U,V,W>& arg ) { return os << get<0>( arg ) << " " << get<1>( arg ) << " " << get<2>( arg ) << " " << get<3>( arg ); }

DEFINITION_OF_OPERATOR_FOR_TUPLE( + );
DEFINITION_OF_OPERATOR_FOR_TUPLE( - );
DEFINITION_OF_OPERATOR_FOR_TUPLE( * );
DEFINITION_OF_OPERATOR_FOR_TUPLE( / );
DEFINITION_OF_OPERATOR_FOR_TUPLE( % );

DEFINITION_OF_INCREMENT_FOR_TUPLE( ++ );
DEFINITION_OF_INCREMENT_FOR_TUPLE( -- );
