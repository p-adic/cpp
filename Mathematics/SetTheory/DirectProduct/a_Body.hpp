// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/String/a_Body.hpp"
#include "../../../Utility/WrappedType/Int/a.hpp"

template <typename T0> inline DirectProduct<T0>::DirectProduct() :
  m_t() , m_c()
{}

template <typename T0> inline DirectProduct<T0>::DirectProduct( const T0& t0 ) :
  m_t( t0 ) , m_c()
{}

template <typename T0 , typename T1 , typename... T2> inline DirectProduct<T0,T1,T2...>::DirectProduct() :
  m_t() , m_v()
{}

template <typename T0 , typename T1 , typename... T2> inline DirectProduct<T0,T1,T2...>::DirectProduct( const T0& t0 , const T1& t1 , const T2&... t2 ) :
  DirectProduct<T0,T1,T2...>( t0 , DirectProduct<T1,T2...>( t1 , t2... ) )
{}

template <typename T0 , typename T1 , typename... T2> inline DirectProduct<T0,T1,T2...>::DirectProduct( const T0& t0 , const DirectProduct<T1,T2...>& v1 ) :
  m_t( t0 ) , m_v( v1 )
{}

template <typename T0>
const T0& DirectProduct<T0>::GetInitial() const
{

  return m_t;

}

template <typename T0 , typename T1 , typename... T2>
const T0& DirectProduct<T0,T1,T2...>::GetInitial() const
{

  return m_t;

}

template <typename T0>
const DirectProduct<>& DirectProduct<T0>::IgnoreInitial() const
{

  return m_c;

}

template <typename T0 , typename T1 , typename... T2>
const DirectProduct<T1,T2...>& DirectProduct<T0,T1,T2...>::IgnoreInitial() const
{

  return m_v;

}

inline bool operator==( const DirectProduct<>& , const DirectProduct<>& ){ return true; }

template <typename T0 , typename... T1>
bool operator==( const DirectProduct<T0,T1...>& v0 , const DirectProduct<T0,T1...>& v1 )
{

  return ( Projection<0,T0,T1...>( v0 ) == Projection<0,T0,T1...>( v1 ) ) * ( RestrictToRight<1,T0,T1...>( v0 ) == RestrictToRight<1,T0,T1...>( v1 ) );

}

inline bool Equal( const DirectProduct<>& ){ return true; }

template <typename T0 , typename... T1>
bool Equal( const DirectProduct<T0,T1...>& v0 , const T0& t0 , const T1&... t1 )
{

  return Projection<0,T0,T1...>( v0 ) == t0 && Equal( RestrictToRight<1,T0,T1...>( v0 ) , t1... );

}

template <typename T0 , typename... T1>
const T0& SeparateInitialLeft( const DirectProduct<T0,T1...>& v )
{

  return v.GetInitial();

}

template <typename T0 , typename... T1>
const DirectProduct<T1...>& SeparateInitialRight( const DirectProduct<T0,T1...>& v )
{

  return v.IgnoreInitial();

}

template <typename T0>
TypeOfIgnoreFinal<T0> SeparateFinalLeft( const DirectProduct<T0>& v0 )
{

  return SeparateInitialRight( v0 );

}

template <typename T0 , typename T1 , typename... T2>
TypeOfIgnoreFinal<T0,T1,T2...> SeparateFinalLeft( const DirectProduct<T0,T1,T2...>& v0 )
{

  TypeOfIgnoreFinal<T1,T2...> v_v1;
  
  return Connect( SeparateInitialLeft( v0 ) , SeparateFinalLeft( SeparateInitialRight( v0 ) ) );

}

template <typename T0>
TypeOfFinal<T0> SeparateFinalRight( const DirectProduct<T0>& v0 )
{

  return SeparateInitialLeft( v0 );

}

template <typename T0 , typename T1 , typename... T2>
TypeOfFinal<T0,T1,T2...> SeparateFinalRight( const DirectProduct<T0,T1,T2...>& v0 )
{
  
  return SeparateFinalRight( SeparateInitialRight( v0 ) );

}

template <typename... T0>
DirectProduct<T0...> Connect( const DirectProduct<>& c , const DirectProduct<T0...>& v0 )
{

  return v0;

}

template <typename T0 , typename... T1>
DirectProduct<T0,T1...> Connect( const DirectProduct<T0,T1...>& v0 , const DirectProduct<>& c )
{

  return v0;

}

template <typename T0 , typename T1 , typename... T2>
DirectProduct<T0,T1,T2...> Connect( const DirectProduct<T0>& v0 , const DirectProduct<T1,T2...>& v1 )
{
  
  return DirectProduct<T0,T1,T2...>( SeparateInitialLeft( v0 ) , v1 );

}

template <typename T0 , typename T1 , typename... T2 , typename T3 , typename... T4> DirectProduct<T0,T1,T2...,T3,T4...> Connect( const DirectProduct<T0,T1,T2...>& v0 , const DirectProduct<T3,T4...>& v1 )
{

  return DirectProduct<T0,T1,T2...,T3,T4...>( SeparateInitialLeft( v0 ) , Connect( SeparateInitialRight( v0 ) , v1 ) );

}

// Only for TypeOfRestrictToLeft
template <typename T0> EmptySet Connect( const DirectProduct<T0>& v0 , const EmptySet& v1 )
{

  ERR_IMPUT( v0 , v1 );
  return v1;

}

template <uint i , typename... T0>
auto RestrictToRight( const DirectProduct<T0...>& v ) -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfRestrictToRight<i,T0...> >::type
{

  return v;

}

template <uint i , typename... T0>
auto RestrictToRight( const DirectProduct<T0...>& v ) -> typename enable_if< less<uint>()( sizeof...( T0 ) , i ) , TypeOfRestrictToRight<i,T0...> >::type
{

  ERR_IMPUT( i , sizeof...( T0 ) , v );
  return EmptySet();

}

template <uint i , typename T0 ,  typename... T1>
auto RestrictToRight( const DirectProduct<T0,T1...>& v ) -> typename enable_if< less<uint>()( 0 , i ) && less_equal<uint>()( i , sizeof...( T1 ) + 1 ) , TypeOfRestrictToRight<i,T0,T1...> >::type
{

  return RestrictToRight<i-1,T1...>( SeparateInitialRight( v ) );

}

template <uint i , typename... T0>
auto RestrictToLeft( const DirectProduct<T0...>& v ) -> typename enable_if< equal_to<uint>()( i , sizeof...( T0 ) ) , TypeOfRestrictToLeft<i,T0...> >::type
{

  return v;

}

template <uint i , typename... T0>
auto RestrictToLeft( const DirectProduct<T0...>& v ) -> typename enable_if< less<uint>()( sizeof...( T0 ) , i ) , TypeOfRestrictToLeft<i,T0...> >::type
{

    ERR_IMPUT( i , sizeof...( T0 ) , v );
    return EmptySet();

}

template <uint i , typename T0 , typename... T1>
auto RestrictToLeft( const DirectProduct<T0,T1...>& v ) -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfRestrictToLeft<i,T0,T1...> >::type
{

  return SeparateInitialRight( DirectProduct<T0>( SeparateInitialLeft( v ) ) );

}

template <uint i , typename T0 , typename T1 , typename... T2>
auto RestrictToLeft( const DirectProduct<T0,T1,T2...>& v ) -> typename enable_if< equal_to<uint>()( i , 1 ) , TypeOfRestrictToLeft<i,T0,T1,T2...> >::type
{

  return DirectProduct<T0>( SeparateInitialLeft( v ) );

}

template <uint i , typename T0 , typename T1 , typename T2 , typename... T3>
auto RestrictToLeft( const DirectProduct<T0,T1,T2,T3...>& v ) -> typename enable_if< less<uint>()( 1 ,  i ) , TypeOfRestrictToLeft<i,T0,T1,T2,T3...> >::type
{

  return Connect( RestrictToLeft<1,T0,T1,T2,T3...>( v ) , RestrictToLeft<i-1,T1,T2,T3...>( SeparateInitialRight( v ) ) );


}

template <uint i , typename T0 , typename... T1>
auto Projection( const DirectProduct<T0,T1...>& v ) -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfProjection<i,T0,T1...> >::type
{

  return SeparateInitialLeft( v );

}

template <uint i , typename T0 , typename T1 , typename... T2>
auto Projection( const DirectProduct<T0,T1,T2...>& v ) -> typename enable_if< less_equal<uint>()( 1 , i ) && less_equal<uint>()( i , sizeof...( T2 ) + 1 ) , TypeOfProjection<i,T0,T1,T2...> >::type
{

  return Projection<i-1,T1,T2...>( SeparateInitialRight( v ) );

}

template <uint i , typename... T0>
auto Projection( const DirectProduct<T0...>& v ) -> typename enable_if< less_equal<uint>()( sizeof...( T0 ) , i ) , TypeOfProjection<i,T0...> >::type
{

  ERR_IMPUT( i , sizeof...( T0 ) , v );
  return EmptySet();

}

template <uint i , typename... T0>
auto Projection( const T0&... v ) -> typename TypeOfProjection<i,T0...>::type
{

  return ACCESS( Projection<i,const T0*...>( DirectProduct<const T0*...>( &v... ) ) );

}


inline string to_string_Body( const DirectProduct<>& ){ return " "; }

template <typename T0>
static string to_string_Body( const DirectProduct<T0>& v )
{
    
  return " " + to_string_Normalised( Projection<0,T0>( v ) ) + " ";

}

template <typename T0 , typename T1 , typename... T2>
static string to_string_Body( const DirectProduct<T0,T1,T2...>& v )
{

  return to_string_Body( RestrictToLeft<1,T0,T1,T2...>( v ) ) + "," + to_string_Body( RestrictToRight<1,T0,T1,T2...>( v ) );

}

template <typename... T0>
string to_string( const DirectProduct<T0...>& v )
{
    
  return "(" + to_string_Body( v ) + ")";

}
