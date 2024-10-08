// c:/Users/user/Documents/Programming/Utility/Tuple/a_Macro.hpp

#pragma once
#ifndef decldecay_t
  #define decldecay_t( VAR ) decay_t<decltype( VAR )>
#endif

#define DECLARATION_OF_ARITHMETIC_FOR_TUPLE( OPR )			\
  template <typename T , typename U , template <typename...> typename V> inline auto operator OPR ## =( V<T,U>& t0 , const V<T,U>& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )&; \
  template <typename T , typename U , typename V> inline tuple<T,U,V>& operator OPR ## =( tuple<T,U,V>& t0 , const tuple<T,U,V>& t1 ); \
  template <typename T , typename U , typename V , typename W> inline tuple<T,U,V,W>& operator OPR ## =( tuple<T,U,V,W>& t0 , const tuple<T,U,V,W>& t1 ); \
  template <typename ARG , typename T , typename U , template <typename...> typename V> inline auto operator OPR ## =( V<T,U>& t0 , const ARG& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )&; \
  template <typename ARG , typename T , typename U , typename V> inline tuple<T,U,V>& operator OPR ## =( tuple<T,U,V>& t0 , const ARG& t1 ); \
  template <typename ARG , typename T , typename U , typename V , typename W> inline tuple<T,U,V,W>& operator OPR ## =( tuple<T,U,V,W>& t0 , const ARG& t1 ); \
  template <template <typename...> typename V , typename...ARGS , typename ARG> inline auto operator OPR( const V<ARGS...>& t0 , const ARG& t1 ) -> decldecay_t( ( get<0>( t0 ) , t0 ) ) \

#define DEFINITION_OF_ARITHMETIC_FOR_TUPLE( OPR )			\
  template <typename T , typename U , template <typename...> typename V> inline auto operator OPR ## =( V<T,U>& t0 , const V<T,U>& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )& { get<0>( t0 ) OPR ## = get<0>( t1 ); get<1>( t0 ) OPR ## = get<1>( t1 ); return t0; } \
  template <typename T , typename U , typename V> inline tuple<T,U,V>& operator OPR ## =( tuple<T,U,V>& t0 , const tuple<T,U,V>& t1 ) { get<0>( t0 ) OPR ## = get<0>( t1 ); get<1>( t0 ) OPR ## = get<1>( t1 ); get<2>( t0 ) OPR ## = get<2>( t1 ); return t0; } \
  template <typename T , typename U , typename V , typename W> inline tuple<T,U,V,W>& operator OPR ## =( tuple<T,U,V,W>& t0 , const tuple<T,U,V,W>& t1 ) { get<0>( t0 ) OPR ## = get<0>( t1 ); get<1>( t0 ) OPR ## = get<1>( t1 ); get<2>( t0 ) OPR ## = get<2>( t1 ); get<3>( t0 ) OPR ## = get<3>( t1 ); return t0; } \
  template <typename ARG , typename T , typename U , template <typename...> typename V> inline auto operator OPR ## =( V<T,U>& t0 , const ARG& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )& { get<0>( t0 ) OPR ## = t1; get<1>( t0 ) OPR ## = t1; return t0; } \
  template <typename ARG , typename T , typename U , typename V> inline tuple<T,U,V>& operator OPR ## =( tuple<T,U,V>& t0 , const ARG& t1 ) { get<0>( t0 ) OPR ## = t1; get<1>( t0 ) OPR ## = t1; get<2>( t0 ) OPR ## = t1; return t0; } \
  template <typename ARG , typename T , typename U , typename V , typename W> inline tuple<T,U,V,W>& operator OPR ## =( tuple<T,U,V,W>& t0 , const ARG& t1 ) { get<0>( t0 ) OPR ## = t1; get<1>( t0 ) OPR ## = t1; get<2>( t0 ) OPR ## = t1; get<3>( t0 ) OPR ## = t1; return t0; } \
  template <template <typename...> typename V , typename...ARGS , typename ARG> inline auto operator OPR( const V<ARGS...>& t0 , const ARG& t1 ) -> decldecay_t( ( get<0>( t0 ) , t0 ) ) { auto t = t0; return move( t OPR ## = t1 ); } \

#define DECLARATION_OF_INCREMENT_FOR_TUPLE( INCR )			\
  template <typename T , typename U , template <typename...> typename V> inline auto operator INCR( V<T,U>& t ) -> decltype( ( get<0>( t ) , t ) )&; \
  template <typename T , typename U , typename V> inline tuple<T,U,V>& operator INCR ( tuple<T,U,V>& t ); \
  template <typename T , typename U , typename V , typename W> inline tuple<T,U,V,W>& operator INCR ( tuple<T,U,V,W>& t ); \

#define DEFINITION_OF_INCREMENT_FOR_TUPLE( INCR )			\
  template <typename T , typename U , template <typename...> typename V> inline auto operator INCR( V<T,U>& t ) -> decltype( ( get<0>( t ) , t ) )& { INCR get<0>( t ); INCR get<1>( t ); return t; } \
  template <typename T , typename U , typename V> inline tuple<T,U,V>& operator INCR ( tuple<T,U,V>& t ) { INCR get<0>( t ); INCR get<1>( t ); INCR get<2>( t ); return t; } \
  template <typename T , typename U , typename V , typename W> inline tuple<T,U,V,W>& operator INCR ( tuple<T,U,V,W>& t ) { INCR get<0>( t ); INCR get<1>( t ); INCR get<2>( t ); INCR get<3>( t ); return t; }	\

