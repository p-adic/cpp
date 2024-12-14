// c:/Users/user/Documents/Programming/Mathematics/Function/ConvexHullTrick/BinarySearch/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U , typename V , typename INT , typename FUNC> inline CrossingHierarchyBinarySearchIntersection<U,V,INT,FUNC>::CrossingHierarchyBinarySearchIntersection( FUNC& func , const INT& x_min , const INT& x_max ) : m_p_func( &func ) , m_p_x_min( &x_min ) , m_p_x_max( &x_max ) {}

template <typename U , typename V , typename INT , typename FUNC> INT CrossingHierarchyBinarySearchIntersection<U,V,INT,FUNC>::Intersection( const U& u0 , const V& v0 , const U& u1 , const V& v1 )
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

template <typename U , typename V , typename INT , typename FUNC> inline MaxCrossingHierarchyBinarySearch<U,V,INT,FUNC>::MaxCrossingHierarchyBinarySearch( FUNC func , const INT& x_min , const INT& x_max , const U& dummy1 , const V& dummy2 ) : VirtualMaxCrossingHierarchy<U,V,INT,FUNC>( move( func ) , x_min , x_max , dummy1 , dummy2 ) , CrossingHierarchyBinarySearchIntersection<U,V,INT,FUNC>( this->m_func , this->m_x_min , this->m_x_max ) {}
template <typename U , typename V , typename INT , typename FUNC> inline MinCrossingHierarchyBinarySearch<U,V,INT,FUNC>::MinCrossingHierarchyBinarySearch( FUNC func , const INT& x_min , const INT& x_max , const U& dummy1 , const V& dummy2 ) : VirtualMinCrossingHierarchy<U,V,INT,FUNC>( move( func ) , x_min , x_max , dummy1 , dummy2 ) , CrossingHierarchyBinarySearchIntersection<Reversed<U>,Reversed<V>,INT,ReversedCrossingHierarchy<U,V,INT,FUNC>>( this->m_func , this->m_x_min , this->m_x_max ) {}
