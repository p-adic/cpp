// c:/Users/user/Documents/Programming/Utility/Tuple/a_Body.hpp

#pragma once
#include "a.hpp"

#if !defined( SAMPLE_CHECK ) && defined( DEBUG )
  #include "StdStream/Debug/a_Body.hpp"
#else
  #include "StdStream/a_Body.hpp"
#endif

#include "Hash/a_Body.hpp"

DEFINITION_OF_ARITHMETIC_FOR_TUPLE( + );
template <typename T , typename U , template <typename...> typename V> inline auto operator-( const V<T,U>& t ) -> decltype( get<0>( t ) , t ) { return { -get<0>( t ) , -get<1>( t ) }; }
template <typename T , typename U , typename V> inline tuple<T,U,V> operator-( const tuple<T,U,V>& t ) { return { -get<0>( t ) , -get<1>( t ) , -get<2>( t ) }; }
template <typename T , typename U , typename V , typename W> inline tuple<T,U,V,W> operator-( const tuple<T,U,V,W>& t ) { return { -get<0>( t ) , -get<1>( t ) , -get<2>( t ) , -get<3>( t ) }; }
DEFINITION_OF_ARITHMETIC_FOR_TUPLE( - );
DEFINITION_OF_ARITHMETIC_FOR_TUPLE( * );
DEFINITION_OF_ARITHMETIC_FOR_TUPLE( / );
DEFINITION_OF_ARITHMETIC_FOR_TUPLE( % );

DEFINITION_OF_INCREMENT_FOR_TUPLE( ++ );
DEFINITION_OF_INCREMENT_FOR_TUPLE( -- );

