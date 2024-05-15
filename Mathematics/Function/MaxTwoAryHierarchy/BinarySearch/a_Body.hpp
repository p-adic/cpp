// c:/Users/user/Documents/Programming/Mathematics/Function/MaxTwoAryHierarchy/BinarySearch/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U , typename V , typename INT , typename FUNC> inline TwoAryHierarchyBinarySearchIntersection<U,V,INT,FUNC>::TwoAryHierarchyBinarySearchIntersection( FUNC& func , const INT& x_min , const INT& x_max ) : m_p_func( &func ) , m_p_x_min( &x_min ) , m_p_x_max( &x_max ) {}

template <typename U , typename V , typename INT , typename FUNC> INT TwoAryHierarchyBinarySearchIntersection<U,V,INT,FUNC>::Intersection( const U& u0 , const V& v0 , const U& u1 , const V& v1 )
{

  INT r = *m_p_x_max;

  if( ( *m_p_func )( u1 , v1 , r ) < ( *m_p_func )( u0 , v0 , r ) ){

    return r + 1;

  }

  INT l = *m_p_x_min - 1;

  while( l + 1 < r ){

    INT m = ( l + r ) >> 1;
    ( ( *m_p_func )( u1 , v1 , m ) < ( *m_p_func )( u0 , v0 , m ) ? l : r ) = m;

  }

  return r;

}

template <typename U , typename V , typename INT , typename FUNC> inline MaxTwoAryHierarchyBinarySearch<U,V,INT,FUNC>::MaxTwoAryHierarchyBinarySearch( FUNC func , const INT& x_min , const INT& x_max , const U& u , const V& v ) : VirtualMaxTwoAryHierarchy<U,V,INT,FUNC>( move( func ) , x_min , x_max , u , v ) , TwoAryHierarchyBinarySearchIntersection<U,V,INT,FUNC>( this->m_func , this->m_x_min , this->m_x_max ) {}
template <typename U , typename V , typename INT , typename FUNC> inline MinTwoAryHierarchyBinarySearch<U,V,INT,FUNC>::MinTwoAryHierarchyBinarySearch( FUNC func , const INT& x_min , const INT& x_max , const U& u , const V& v ) : VirtualMinTwoAryHierarchy<U,V,INT,FUNC>( move( func ) , x_min , x_max , u , v ) , TwoAryHierarchyBinarySearchIntersection<Reversed<U>,Reversed<V>,INT,ReversedTwoAryHierarchy<U,V,INT,FUNC>>( this->m_func , this->m_x_min , this->m_x_max ) {}
