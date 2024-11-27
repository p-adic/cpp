// c:/Users/user/Documents/Programming/Mathematics/Game/Nim/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/972137ÅiBoundedNimÅj

template <typename INT , template <typename...> typename V> inline INT Nim( const V<INT>& a );
template <typename INT1 , template <typename...> typename V , typename INT2> inline INT1 BoundedNim( const V<INT1>& a , INT2 bound );
