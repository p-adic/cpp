// LazyEvaluation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../SmartPointer/a_Body.hpp"
#include "../List/a_Body.hpp"

template <typename T> inline LazyEvaluation<T>::LazyEvaluation() : m_p( SmartPointer<T>() ){}

template <typename T> inline LazyEvaluation<T>::LazyEvaluation( const T& t ) : m_p( SmartPointer<T>( t ) ){}

template <typename T>
const LazyEvaluation<T>& LazyEvaluation<T>::operator=( const T& t ) const
{

  *m_p = t;
  return *this;

}

template <typename T> inline void LazyEvaluation<T>::Forget() const { m_p.Forget(); }

template <typename T> inline const T& LazyEvaluation<T>::Get() const { return Access( m_p ); }

template <typename T> inline bool LazyEvaluation<T>::IsInitial() const { return m_p.IsAccessible(); }

template <typename T> inline void Initialise( const LazyEvaluation<T>& t ){ t.Forget(); }

template <typename T> void Memorise( const LazyEvaluation<T>& t1 , const T& t2 )
{

  if( ! CheckInitial( t1 ) ){

    ERR_INPUT( t1 , t2 );

  }

  t1 = t2;
  return;

}

template <typename T , typename... Args> inline void Memorise( const LazyEvaluation<T>& t , const FunctionType<T,Args...>& func , const Args&... args ){ Memorise( t , func( args... ) ); }

template <typename T> inline const T& Load( const LazyEvaluation<T>& t ){ return t.Get(); }

template <typename T , typename... Args> const T& Load( LazyEvaluation<T>& t , const FunctionType<T,Args...>& func , const Args&... args )
{


  if( CheckInitial( t ) ){

    Memorise( t , func , args... );

  }

  return Load( t );

}

template <typename T> inline bool CheckInitial( const LazyEvaluation<T>& t ){ return t.IsInitial(); }
