// c:/Users/user/Documents/Programming/Utility/Order/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline Reversed<T>::Reversed( const Reversed<T>& t ) : m_t( t.m_t ) {}
template <typename T> inline Reversed<T>::Reversed( Reversed<T>& t ) : m_t( t.m_t ) {}
template <typename T> inline Reversed<T>::Reversed( Reversed<T>&& t ) : m_t( t.move() ) {}
template <typename T> template <typename...Args> inline Reversed<T>::Reversed( Args&&... args ) : m_t( forward<Args>( args )... ) {}

template <typename T> inline Reversed<T>& Reversed<T>::operator=( Reversed<T> t ) { m_t = t.move(); return *this; }

template <typename T> inline T& Reversed<T>::Ref() noexcept { return m_t; }
template <typename T> inline const T& Reversed<T>::Get() const noexcept { return m_t; }
template <typename T> inline T&& Reversed<T>::move() noexcept { return std::move( m_t ); }

DEFINITION_OF_REVERSED_RELATION( == );
DEFINITION_OF_REVERSED_RELATION( != );
DEFINITION_OF_REVERSED_RELATION( < );
DEFINITION_OF_REVERSED_RELATION( > );
DEFINITION_OF_REVERSED_RELATION( <= );
DEFINITION_OF_REVERSED_RELATION( >= );

DEFINITION_OF_REVERSED_ARITHMETIC( + , Reversed<T> , t.m_t );
template <typename T> inline Reversed<T> Reversed<T>::operator-() const { return Reversed<T>( -m_t ); }
DEFINITION_OF_REVERSED_ARITHMETIC( - , Reversed<T> , t.m_t );
DEFINITION_OF_REVERSED_ARITHMETIC( * , Reversed<T> , t.m_t );
DEFINITION_OF_REVERSED_ARITHMETIC( / , Reversed<T> , t.m_t );
DEFINITION_OF_REVERSED_ARITHMETIC( % , Reversed<T> , t.m_t );
DEFINITION_OF_REVERSED_ARITHMETIC( << , int , t );
DEFINITION_OF_REVERSED_ARITHMETIC( >> , int , t );
  
