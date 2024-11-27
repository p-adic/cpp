// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/YoungDiagram/a.hpp

#pragma once

// O(|type|)でフック長公式により型typeのヤング図形の個数を数え上げる。
template <typename INT1 , typename INT2 , template <typename...> typename V> void SetCountingYoundDiagram( INT1& answer , const V<INT2>& type );
