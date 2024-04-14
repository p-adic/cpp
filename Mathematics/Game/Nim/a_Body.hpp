// c:/Users/user/Documents/Programming/Mathematics/Game/Nim/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , template <typename...> typename V> inline INT Nim( const V<INT>& a ) { INT answer{}; for( auto& n : a ){ answer ^= n; } return answer; }
template <typename INT1 , template <typename...> typename V , typename INT2> inline INT1 BoundedNim( const V<INT1>& a , INT2 bound ) { INT1 answer{}; bound++; for( auto& n : a ){ answer ^= ( n % bound ); } return answer; }
