// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/GCD/a.hpp

#pragma once

inline int GCD();
template <typename INT1 , typename...INT2> INT1 GCD( INT1 b_0 , INT2... args );
template <typename INT , template <typename...> typename V> INT GCD( V<INT> a );

template <typename INT1 , typename INT2> inline INT1 LCM( const INT1& b_0 , const INT2& b_1 );

inline int LCM();
template <typename INT1 , typename...INT2> INT1 LCM( INT1 b_0 , INT2... args );
template <typename INT , template <typename...> typename V> INT LCM( V<INT> a );
