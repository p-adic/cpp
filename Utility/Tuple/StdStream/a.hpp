// c:/Users/user/Documents/Programming/Utility/Tuple/StdStream/a.hpp

#pragma once

template <class Traits , typename T> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , tuple<T>& arg );
template <class Traits , typename T , typename U , template <typename...> typename V> inline auto operator>>( basic_istream<char,Traits>& is , V<T,U>& arg ) -> decltype((get<0>(arg),is))&;
template <class Traits , typename T , typename U , typename V> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , tuple<T,U,V>& arg );
template <class Traits , typename T , typename U , typename V , typename W> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , tuple<T,U,V,W>& arg );

template <class Traits , typename T> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const tuple<T>& arg );
template <class Traits , typename T , typename U , template <typename...> typename V> inline auto operator<<( basic_ostream<char,Traits>& os , const V<T,U>& arg ) -> decltype((get<0>(arg),os))&;
template <class Traits , typename T , typename U , typename V> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const tuple<T,U,V>& arg );
template <class Traits , typename T , typename U , typename V , typename W> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const tuple<T,U,V,W>& arg );
