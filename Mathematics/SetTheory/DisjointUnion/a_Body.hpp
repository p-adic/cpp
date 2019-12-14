// DisjointUnion/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../DirectProduct/a_Body.hpp"
#include "../../../Utility/WrappedInt/a_Body.hpp"

template <typename T0 , typename... T1> template <uint i>
DirectProduct<T0*,T1*...> DisjointUnion<T0,T1...>::Normalise( TypeOfProjection<i,T0,T1...>& t )
{

  auto p = DisjointUnion<>::Initialise<T0,T1...>();
  
  if( i < sizeof...( T1 ) + 1 ){

    return Connect( Connect( RestrictToLeft<i,T0*,T1*...>( p ) , DirectProduct<TypeOfProjection<i,T0,T1...>*>( &t ) ) , RestrictToRight<i+1,T0*,T1*...>( p ) );
    
  }

  ERR_IMPUT( sizeof...( T1 ) , i , t );
  return p;

}

template <typename T0 , typename... T1> template <uint i>
DisjointUnion<T0,T1...>::DisjointUnion( const WrappedUInt<i>& , TypeOfProjection<i,T0,T1...>& t ) :
  m_p( Normalise<i>( t ) ) , m_i( i )
{}

template <typename T0>
DirectProduct<T0*> DisjointUnion<>::Initialise()
{

  return DirectProduct<T0*>( nullptr );

}

template <typename T0, typename T1 , typename... T2>
DirectProduct<T0*,T1*,T2*...> DisjointUnion<>::Initialise()
{

  return Connect( Initialise<T0>() , Initialise<T1,T2...>() );

}

template <typename T0 , typename... T1> template <uint i>
const TypeOfProjection<i,T0*,T1*...>& DisjointUnion<T0,T1...>::GetEntry() const
{

  if( m_i != i ){

    ERR_IMPUT( i , m_i );

  }

  return Projection<i,T0*,T1*...>( m_p );

}

template <typename T0 , typename... T1>
const uint& DisjointUnion<T0,T1...>::GetNumber() const
{

  return m_i;

}

template <uint i , typename T0 , typename... T1>
const TypeOfProjection<i,T0,T1...>& Access( const DisjointUnion<T0,T1...>& t )
{

  auto p = t.template GetEntry<i>();
  return ACCESS( p );

}

template <typename... T0>
const uint& to_int( const DisjointUnion<T0...>& t )
{

  return t.GetNumber();

}

template <uint i , typename... T0>
DisjointUnion<T0...> to_DisjointUnion( TypeOfProjection<i,T0...>& t )
{

  return DisjointUnion<T0...>( WrappedUInt<i>() , t );

}

template <typename... T0 , typename... T1> DisjointUnion<T0...,T1...> ExtendToLeft( const DisjointUnion<T1...>& t )
{

  const uint i = to_int( t );
  return to_DisjointUnion<sizeof...(T0)+i,T0...,T1...>( t.template GetEntry<i>() );

}

template <typename... T0 , typename... T1> DisjointUnion<T0...,T1...> ExtendToRight( const DisjointUnion<T0...>& t )
{

  const uint i = to_int( t );
  return to_DisjointUnion<i,T0...,T1...>( t.template GetEntry<i>() );

}
