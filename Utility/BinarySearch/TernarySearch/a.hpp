// c:/Users/user/Documents/Programming/Utility/BinarySearch/TernarySearch/a.hpp

#pragma once

// verify;
// https://yukicoder.me/submissions/1027301iminimise = truej

template <typename FUNC> auto TernarySearch( ll l , ll r , FUNC f , const bool& minimise = true ) -> pair<ll,decltype( f( r ) )>;

