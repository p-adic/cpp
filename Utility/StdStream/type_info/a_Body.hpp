// c:/Users/user/Documents/Programming/Utility/StdStream/type_info/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../String/a_Body.hpp"

template <class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const type_info& type ) noexcept { return os << to_string( type ); }
