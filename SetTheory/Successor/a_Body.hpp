// Successor/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../DisjointUnion/a_Body.hpp"
#include "../Singleton/a_Body.hpp"
#include "../../../SFINAE/NonMemberFunction/Operator/a_Body.hpp"

template <typename T>
SuccessorOf<T>::SuccessorOf() :
  m_t( WrapU<0>() , Object<SingletonOf<T> >() )
{}

template <typename T>
SuccessorOf<T>::SuccessorOf( const T& t ) :
  m_t( WrapU<1>() , t )
{}

template <typename T> template <uint i>
const TypeOfProjection<i,SingletonOf<T>,T>& SuccessorOf<T>::GetEntry() const
{

  return Access<i,const SingletonOf<T>,const T>( m_t );

}

template <typename T>
const uint& SuccessorOf<T>::GetNumber() const
{

  return to_int( m_t );

}

template <typename T>
SuccessorOf<T>& SuccessorOf<T>::operator=( const SingletonOf<T>& t )
{

  m_t = DisjointUnion<SingletonOf<T>,T>( WrapU<0>() , t );
  return *this;

}

template <typename T>
SuccessorOf<T>& SuccessorOf<T>::operator=( const T& t )
{

  m_t = DisjointUnion<const SingletonOf<T>,const T>( WrapU<1>() , t );
  return *this;

}

template <uint i , typename T>
const TypeOfProjection<i,SingletonOf<T>,T>& Access( const SuccessorOf<T>& t )
{

  return t.template GetEntry<i>();

}

template <typename T> const uint& to_int( const SuccessorOf<T>& t )
{

  return t.GetNumber();

}

template <typename T> bool operator==( const SuccessorOf<T>& t1 , const SingletonOf<T>& t2 )
{

  return to_int( t1 ) == 0;

}

template <typename T> bool operator==( const SuccessorOf<T>& t1 , const T& t2 )
{

  if( to_int( t1 ) == 1 ){

    return Equal( Access<1,T>( t1 ) , t2 );

  }

  return false;

}

template <typename T> bool operator==( const SuccessorOf<T>& t1 , const SuccessorOf<T>& t2 )
{

  if( to_int( t1 ) == 0 ){

    return to_int( t2 ) == 0;

  }

  return t1 == Access<1,T>( t2 );
    
}
