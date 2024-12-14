// c:/Users/user/Documents/Programming/Mathematics/Function/ConvexHullTrick/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Utility/Reverse/a_Body.hpp"

template <typename U , typename V , typename X , typename FUNC> inline VirtualMaxCrossingHierarchy<U,V,X,FUNC>::VirtualMaxCrossingHierarchy( FUNC func , const X& x_min , const X& x_max , const U& dummy1 , const V& dummy2 ) : m_func( move( func ) ) , m_x_min( x_min ) , m_x_max( x_max ) , m_uvx() , m_xu() { assert( m_x_min <= m_x_max ); }
template <typename U , typename V , typename X , typename FUNC> inline VirtualMinCrossingHierarchy<U,V,X,FUNC>::VirtualMinCrossingHierarchy( FUNC func , const X& x_min , const X& x_max , const U& dummy1 , const V& dummy2 ) : VirtualMaxCrossingHierarchy<Reversed<U>,Reversed<V>,X,ReversedCrossingHierarchy<U,V,X,FUNC>>( move( func ) , x_min , x_max , dummy1 , dummy2 ) {}
template <typename U , typename V , typename X , typename FUNC> inline ReversedCrossingHierarchy<U,V,X,FUNC>::ReversedCrossingHierarchy( FUNC&& func ) : FUNC( move( func ) ) {}
  
template <typename U , typename V , typename X , typename FUNC> inline Reversed<ret_t<FUNC,const U&,const V&,const X&>> ReversedCrossingHierarchy<U,V,X,FUNC>::operator()( const Reversed<U>& u , const Reversed<V>& v , const X& x ) { return Reversed<ret_t<FUNC,const U&,const V&,const X&>>( FUNC::operator()( u.Get() , v.Get() , x ) ); }

template <typename U , typename V , typename X , typename FUNC>
void VirtualMaxCrossingHierarchy<U,V,X,FUNC>::SetMax( const U& u , const V& v )
{

  if( m_uvx.empty() ){

    assert( m_xu.empty() );
    m_uvx[u] = { v , m_x_min };
    m_xu[m_x_min] = u;

  }
  
  auto itr_right = m_uvx.lower_bound( u ) , begin = m_uvx.begin();
  auto end = m_uvx.end();

  if( itr_right != end ){

    const U& u0 = itr_right->first;
    auto& [v0,x0] = itr_right->second;

    if( u == u0 ){

      if( v <= v0 ){

	return;
	
      }

      m_xu.erase( x0 );

      if( itr_right == begin ){

	if( ++begin == end ){

	  m_uvx[u] = { v , m_x_min };
	  m_xu[m_x_min] = u;
	  return;

	}

      }
	
      itr_right = m_uvx.erase( itr_right );

    }

  }

  auto itr_left = itr_right;

  if( itr_left == begin ){

    const U& u0 = itr_left->first;
    auto& [v0,x0] = itr_left->second;

    if( m_x_min >= this->Intersection( u , v , u0 , v0 ) ){

      return;

    }

    itr_left = end;

  } else if( itr_left == end ){

    itr_left = m_uvx.lower_bound( m_uvx.rbegin()->first );
    const U& u0 = itr_left->first;
    auto& [v0,x0] = itr_left->second;

    if( this->Intersection( u0 , v0 , u , v ) >= m_x_max ){

      return;

    }

  } else {

    --itr_left;
    const U& u0 = itr_left->first;
    auto& [v0,x0] = itr_left->second;
    const U& u1 = itr_right->first;
    auto& [v1,x1] = itr_right->second;

    if( this->Intersection( u0 , v0 , u , v ) >= this->Intersection( u , v , u1 , v1 ) ){

      return;

    }

  }

  if( itr_right != end ){

    bool valid = true;

    while( valid ){

      auto itr_right_copy = itr_right++;
      const U& u0 = itr_right_copy->first;
      auto& [v0,x0] = itr_right_copy->second;
      m_xu.erase( x0 );
      x0 = this->Intersection( u , v , u0 , v0 );
      bool remove = true;

      if( itr_right == end ){

	valid = false;
	remove = m_x_max < x0;

      } else if( x0 < itr_right->second.second ){
	
	valid = false;
	remove = false;
	
      }

      if( remove ){
	
	m_uvx.erase( itr_right_copy );

      } else {

	m_xu[x0] = u0;

      }

    }

  }

  X x = m_x_min;

  if( itr_left != end ){

    while( true ){

      const U& u1 = itr_left->first;
      auto& [v1,x1] = itr_left->second;

      if( x1 < ( x = this->Intersection( u1 , v1 , u , v ) ) ){

	break;
	
      }

      m_xu.erase( x1 );

      if( itr_left == begin ){

	m_uvx.erase( itr_left );
	break;

      }
      
      m_uvx.erase( itr_left-- );

    }

  }

  m_uvx[u] = { v , x = min( max( m_x_min , x ) , m_x_max ) };
  m_xu[x] = u;
  return;

}

template <typename U , typename V , typename X , typename FUNC>
void VirtualMinCrossingHierarchy<U,V,X,FUNC>::SetMin( const U& u , const V& v ) { this->SetMax( u , v ); }

template <typename U , typename V , typename X , typename FUNC>
tuple<ret_t<FUNC,const U&,const V&,const X&>,U,V> VirtualMaxCrossingHierarchy<U,V,X,FUNC>::Get( const X& x )
{

  assert( !m_uvx.empty() && !m_xu.empty() && m_x_min <= x && x <= m_x_max );
  auto itr_next = m_xu.upper_bound( x );
  auto& [x0,u0] = *( --itr_next );
  auto itr = m_uvx.lower_bound( u0 );
  const U& u1 = itr->first;
  auto& [v1,x1] = itr->second;
  return { m_func( u1 , v1 , x ) , u1 , v1 };
  
}

template <typename U , typename V , typename X , typename FUNC> inline tuple<ret_t<FUNC,const U&,const V&,const X&>,U,V> VirtualMinCrossingHierarchy<U,V,X,FUNC>::Get( const X& x ) { auto [y,u,v] = VirtualMaxCrossingHierarchy<Reversed<U>,Reversed<V>,X,ReversedCrossingHierarchy<U,V,X,FUNC>>::Get( x ); return { y.move() , u.move() , v.move() }; }

template <typename U , typename V , typename X , typename INTERSECTION>
inline AbstractCrossingHierarchyIntersection<U,V,X,INTERSECTION>::AbstractCrossingHierarchyIntersection( INTERSECTION intersection ) : m_intersection( move( intersection ) ) { }

template <typename U , typename V , typename X , typename INTERSECTION>
inline X AbstractCrossingHierarchyIntersection<U,V,X,INTERSECTION>::Intersection( const U& u0 , const V& v0 , const U& u1 , const V& v1 ) { assert( u0 < u1 ); return m_intersection( u0 , v0 , u1 , v1 ); }

template <typename U , typename V , typename X , typename FUNC , typename INTERSECTION> inline AbstractMaxCrossingHierarchy<U,V,X,FUNC,INTERSECTION>::AbstractMaxCrossingHierarchy( FUNC func , const X& x_min , const X& x_max , const U& dummy1 , const V& dummy2 , INTERSECTION intersection ) : VirtualMaxCrossingHierarchy<U,V,X,FUNC>( move( func ) , x_min , x_max , dummy1 , dummy2 ) , AbstractCrossingHierarchyIntersection<U,V,X,INTERSECTION>( move( intersection ) ) {}
template <typename U , typename V , typename X , typename FUNC , typename INTERSECTION> inline AbstractMinCrossingHierarchy<U,V,X,FUNC,INTERSECTION>::AbstractMinCrossingHierarchy( FUNC func , const X& x_min , const X& x_max , const U& dummy1 , const V& dummy2 , INTERSECTION intersection ) : VirtualMinCrossingHierarchy<U,V,X,FUNC>( move( func ) , x_min , x_max , dummy1 , dummy2 ) , AbstractCrossingHierarchyIntersection<U,V,X,INTERSECTION>( move( intersection ) ) {}

