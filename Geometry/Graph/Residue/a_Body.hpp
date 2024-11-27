// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Residue/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T , typename E> inline ResidueGraph<T,E>::ResidueGraph( const int& size , const T& dummy , E edge ) : EdgeImplimentation<T,T,int,E>( size , move( edge ) ) { static_assert( is_invocable_v<E,T> ); }

template <typename T , typename E> inline T ResidueGraph<T,E>::Enumeration( const int& i ) { return T::Derepresent( i ); }
template <typename T , typename E> inline int ResidueGraph<T,E>::Enumeration_inv_Body( const T& t ){ return t.Represent(); }

template <typename T , typename E> template <typename F> inline ResidueGraph<T,F> ResidueGraph<T,E>::GetGraph( F edge ) const { return ResidueGraph<T,F>( this->size() , T::zero() , move( edge ) ); }
