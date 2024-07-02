// c:/Users/user/Documents/Programming/Utility/Tuple/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Random/a_Body.hpp"

template <class Traits , typename T , typename U , template <typename...> typename V> inline auto operator>>( basic_istream<char,Traits>& is , V<T,U>& arg ) -> decltype((get<0>(arg),is))& { return is >> get<0>( arg ) >> get<1>( arg ); }
template <class Traits , typename T , typename U , typename V> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , tuple<T,U,V>& arg ) { return is >> get<0>( arg ) >> get<1>( arg ) >> get<2>( arg ); }
template <class Traits , typename T , typename U , typename V , typename W> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , tuple<T,U,V,W>& arg ) { return is >> get<0>( arg ) >> get<1>( arg ) >> get<2>( arg ) >> get<3>( arg ); }

template <class Traits , typename T , typename U , template <typename...> typename V> inline auto operator<<( basic_ostream<char,Traits>& os , const V<T,U>& arg ) -> decltype((get<0>(arg),os))& { return os << get<0>( arg ) << " " << get<1>( arg ); }
template <class Traits , typename T , typename U , typename V> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const tuple<T,U,V>& arg ) { return os << get<0>( arg ) << " " << get<1>( arg ) << " " << get<2>( arg ); }
template <class Traits , typename T , typename U , typename V , typename W> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const tuple<T,U,V,W>& arg ) { return os << get<0>( arg ) << " " << get<1>( arg ) << " " << get<2>( arg ) << " " << get<3>( arg ); }

DEFINITION_OF_ARITHMETIC_FOR_TUPLE( + );
DEFINITION_OF_ARITHMETIC_FOR_TUPLE( - );
DEFINITION_OF_ARITHMETIC_FOR_TUPLE( * );
DEFINITION_OF_ARITHMETIC_FOR_TUPLE( / );
DEFINITION_OF_ARITHMETIC_FOR_TUPLE( % );

DEFINITION_OF_INCREMENT_FOR_TUPLE( ++ );
DEFINITION_OF_INCREMENT_FOR_TUPLE( -- );

#include "../Set/a_Body.hpp"
template <typename T> inline size_t hash<tuple<T>>::operator()( const tuple<T>& n ) const { static const hash<T> h; return h(get<0>( n ) ); }
DEFINITION_OF_HASH_FOR_TUPLE( pair );
DEFINITION_OF_HASH_FOR_TUPLE( tuple );
template <typename T , typename U , typename V> inline size_t hash<tuple<T,U,V>>::operator()( const tuple<T,U,V>& n ) const { static const size_t seed = ( GetRand( 1e3 , 1e8 ) << 1 ) | 1; static const hash<pair<T,U>> h01; static const hash<V> h2; return ( h01( { get<0>( n ) , get<1>( n ) } ) * seed ) ^ h2( get<2>( n ) ); }
template <typename T , typename U , typename V , typename W> inline size_t hash<tuple<T,U,V,W>>::operator()( const tuple<T,U,V,W>& n ) const { static const size_t seed = ( GetRand( 1e3 , 1e8 ) << 1 ) | 1; static const hash<pair<T,U>> h01; static const hash<pair<V,W>> h23; return ( h01( { get<0>( n ) , get<1>( n ) } ) * seed ) ^ h23( { get<2>( n ) , get<3>( n ) } ); }
