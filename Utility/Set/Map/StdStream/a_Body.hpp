// c:/Users/user/Documents/Programming/Utility/Set/Map/StdStream/a_Body.hpp

#pragma once
#include "a.hpp"

// operator<<のオーバーロードを行うため、先にincludeする。
#include "../../Tuple/StdStream/Debug/a_Body.hpp"

template <class Traits , typename T , typename U> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const map<T,U>& f )
{

  #ifndef DEBUG
    static_assert( false );
  #endif
  
  os << "map VVV\n";

  for( auto& [key,val] : f ){

    os << key << " -> " << val << "\n";

  }
  
  return os << "map AAA";

}

template <class Traits , typename T , typename U> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const unordered_map<T,U>& f )
{

  #ifndef DEBUG
    static_assert( false );
  #endif

  os << "unordered_map VVV\n";

  for( auto& [key,val] : f ){

    os << key << " -> " << val << "\n";

  }
  
  return os << "unordered_map AAA";

}
