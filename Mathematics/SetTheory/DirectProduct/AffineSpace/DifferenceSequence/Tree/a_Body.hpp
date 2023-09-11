// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/Tree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename V , list<V> E(const V&) , V E_inv(const V&) , V enum_V(const int&) , int enum_V_inv(const V&) , typename T , T& m_T(const T&,T&) , const T& e_T() , typename U , U inv_U(const U&) , T& o_U(const U&,T&) , int size_max> inline DifferenceSequenceOnTree<V,E,E_inv,enum_V,enum_V_inv,T,m_T,e_T,U,inv_U,o_U,size_max>::DifferenceSequenceOnTree( const int& size ) :
  DifferenceSequenceBody<V,T,U,size_max>( size )
{

  using base = DifferenceSequenceBody<V,T,U,size_max>;
  const T& unit = Unit();
  
  if( base::m_lazy_addition[0] != unit ){

    for( int i = 0 ; i < size ; i++ ){

      base::m_a[i] = base::m_lazy_addition[i] = unit;

    }

  }

}

template <typename V , list<V> E(const V&) , V E_inv(const V&) , V enum_V(const int&) , int enum_V_inv(const V&) , typename T , T& m_T(const T&,T&) , const T& e_T() , typename U , U inv_U(const U&) , T& o_U(const U&,T&) , int size_max> inline list<V> DifferenceSequenceOnTree<V,E,E_inv,enum_V,enum_V_inv,T,m_T,e_T,U,inv_U,o_U,size_max>::Edge( const V& v ) const { return E( v ); }

template <typename V , list<V> E(const V&) , V E_inv(const V&) , V enum_V(const int&) , int enum_V_inv(const V&) , typename T , T& m_T(const T&,T&) , const T& e_T() , typename U , U inv_U(const U&) , T& o_U(const U&,T&) , int size_max> inline V DifferenceSequenceOnTree<V,E,E_inv,enum_V,enum_V_inv,T,m_T,e_T,U,inv_U,o_U,size_max>::Edge_inv( const V& v ) const { return E_inv( v ); }

template <typename V , list<V> E(const V&) , V E_inv(const V&) , V enum_V(const int&) , int enum_V_inv(const V&) , typename T , T& m_T(const T&,T&) , const T& e_T() , typename U , U inv_U(const U&) , T& o_U(const U&,T&) , int size_max> inline V DifferenceSequenceOnTree<V,E,E_inv,enum_V,enum_V_inv,T,m_T,e_T,U,inv_U,o_U,size_max>::e( const int& i ) const { return enum_V( i ); }

template <typename V , list<V> E(const V&) , V E_inv(const V&) , V enum_V(const int&) , int enum_V_inv(const V&) , typename T , T& m_T(const T&,T&) , const T& e_T() , typename U , U inv_U(const U&) , T& o_U(const U&,T&) , int size_max> inline int DifferenceSequenceOnTree<V,E,E_inv,enum_V,enum_V_inv,T,m_T,e_T,U,inv_U,o_U,size_max>::e_inv( const V& v ) const { return enum_V_inv( v ); }

template <typename V , list<V> E(const V&) , V E_inv(const V&) , V enum_V(const int&) , int enum_V_inv(const V&) , typename T , T& m_T(const T&,T&) , const T& e_T() , typename U , U inv_U(const U&) , T& o_U(const U&,T&) , int size_max> inline const T& DifferenceSequenceOnTree<V,E,E_inv,enum_V,enum_V_inv,T,m_T,e_T,U,inv_U,o_U,size_max>::Unit() const { return e_T(); }

template <typename V , list<V> E(const V&) , V E_inv(const V&) , V enum_V(const int&) , int enum_V_inv(const V&) , typename T , T& m_T(const T&,T&) , const T& e_T() , typename U , U inv_U(const U&) , T& o_U(const U&,T&) , int size_max> inline T& DifferenceSequenceOnTree<V,E,E_inv,enum_V,enum_V_inv,T,m_T,e_T,U,inv_U,o_U,size_max>::Addition( const T& t0 , T& t1 ) const { return m_T( t0 , t1 ); }

template <typename V , list<V> E(const V&) , V E_inv(const V&) , V enum_V(const int&) , int enum_V_inv(const V&) , typename T , T& m_T(const T&,T&) , const T& e_T() , typename U , U inv_U(const U&) , T& o_U(const U&,T&) , int size_max> inline U DifferenceSequenceOnTree<V,E,E_inv,enum_V,enum_V_inv,T,m_T,e_T,U,inv_U,o_U,size_max>::Inverse( const U& u ) const { return inv_U( u ); }

template <typename V , list<V> E(const V&) , V E_inv(const V&) , V enum_V(const int&) , int enum_V_inv(const V&) , typename T , T& m_T(const T&,T&) , const T& e_T() , typename U , U inv_U(const U&) , T& o_U(const U&,T&) , int size_max> inline T& DifferenceSequenceOnTree<V,E,E_inv,enum_V,enum_V_inv,T,m_T,e_T,U,inv_U,o_U,size_max>::Action( const U& u , T& t ) const { return o_U( u , t ); }
