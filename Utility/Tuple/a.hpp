// c:/Users/user/Documents/Programming/Utility/Tuple/a.hpp

#pragma once
#include "a_Macro.hpp"

#if !defined( SAMPLE_CHECK ) && defined( DEBUG )
  #include "StdStream/Debug/a.hpp"
#else
  #include "StdStream/a.hpp"
#endif

DECLARATION_OF_ARITHMETIC_FOR_TUPLE( + );
template <typename T , typename U , template <typename...> typename V> inline auto operator-( const V<T,U>& t ) -> decltype( get<0>( t ) , t );
template <typename T , typename U , typename V> inline tuple<T,U,V> operator-( const tuple<T,U,V>& t );
template <typename T , typename U , typename V , typename W> inline tuple<T,U,V,W> operator-( const tuple<T,U,V,W>& t );
DECLARATION_OF_ARITHMETIC_FOR_TUPLE( - );
DECLARATION_OF_ARITHMETIC_FOR_TUPLE( * );
DECLARATION_OF_ARITHMETIC_FOR_TUPLE( / );
DECLARATION_OF_ARITHMETIC_FOR_TUPLE( % );

DECLARATION_OF_INCREMENT_FOR_TUPLE( ++ );
DECLARATION_OF_INCREMENT_FOR_TUPLE( -- );
