// c:/Users/user/Documents/Programming/Utility/Set/Map/StdStream/a.hpp

#pragma once

// デバッグ時にのみ用いるため、"../a.hpp"にはincludeしない。

template <class Traits , typename T , typename U> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const map<T,U>& f );
template <class Traits , typename T , typename U> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const unordered_map<T,U>& f );
