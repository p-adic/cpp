// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename V , typename T , typename U , int size_max> inline DifferenceSequenceBody<V,T,U,size_max>::DifferenceSequenceBody( const int& size ) :
  m_size( size ) , m_a() , m_lazy_addition() , m_updated( false ) { assert( m_size <= size_max ); }
template <typename T , int size_max> inline DifferenceSequence<T,size_max>::DifferenceSequence( const int& size ) :
  DifferenceSequenceBody<int,T,T,size_max>( size )
{

  using base = DifferenceSequenceBody<int,T,T,size_max>;
  const T& unit = Unit();
  
  if( base::m_lazy_addition[0] != unit ){

    for( int i = 0 ; i < size ; i++ ){

      base::m_a[i] = base::m_lazy_addition[i] = unit;

    }

  }

}

template <typename T , int size_max> inline DifferenceSequence<T,size_max>::DifferenceSequence( const T ( &a )[size_max] , const int& size ) :
  DifferenceSequenceBody<int,T,T,size_max>( size )
{

  using base = DifferenceSequenceBody<int,T,T,size_max>;

  for( int i = 0 ; i < size ; i++ ){

    base::m_a[i] = a[i];

  }

  const T& unit = Unit();
  
  if( base::m_lazy_addition[0] != unit ){

    for( int i = 0 ; i < size ; i++ ){

      base::m_lazy_addition[i] = unit;

    }

  }
  
}

template <typename T , int size_max> inline DifferenceSequence<T,size_max>::DifferenceSequence( T ( &&a )[size_max] , const int& size ) :
  DifferenceSequenceBody<int,T,T,size_max>( size )
{

  using base = DifferenceSequenceBody<int,T,T,size_max>;
  swap( base::m_a , a );
  const T& unit = Unit();
  
  if( base::m_lazy_addition[0] != unit ){

    for( int i = 0 ; i < size ; i++ ){

      base::m_lazy_addition[i] = unit;

    }

  }

}

template <typename V , typename T , typename U , int size_max> inline void DifferenceSequenceBody<V,T,U,size_max>::Set( const V& v , const U& u ) { Update(); m_a[e_inv(v)] = u; }
template <typename V , typename T , typename U , int size_max> inline const U& DifferenceSequenceBody<V,T,U,size_max>::Get( const V& v ) { Update(); return m_a[e_inv(v)]; }
template <typename V , typename T , typename U , int size_max> inline U& DifferenceSequenceBody<V,T,U,size_max>::Ref( const V& v ) { return m_a[e_inv(v)]; }

template <typename V , typename T , typename U , int size_max> inline void DifferenceSequenceBody<V,T,U,size_max>::Add( const V& v , const U& u ) { Addition( m_a[e_inv(v)] , u ); }

template <typename V , typename T , typename U , int size_max>
void DifferenceSequenceBody<V,T,U,size_max>::SubTreeAdd( const V& v_start , const list<V>& v_final , const U& u )
{

  if( u == Unit() ){

    return;

  }

  m_updated = true;
  Addition( u , m_lazy_addition[e_inv(v_start)] );
  const U u_inv = Inverse( u );
  
  for( auto itr_v_final = v_final.begin() , end_v_final = v_final.end() ; itr_v_final != end_v_final ; itr_v_final++ ){

    auto edge = Edge( *itr_v_final );

    for( auto itr_edge = edge.begin() , end_edge = edge.end() ; itr_edge != end_edge ; itr_edge++ ){

      Addition( u_inv , m_lazy_addition[ e_inv( *itr_edge ) ] );

    }

  }

  return;
  
}

template <typename T , int size_max> inline void DifferenceSequence<T,size_max>::InitialSegmentAdd( const int& v_start , const T& u ) { SubTreeAdd( v_start , {} , u ); }
template <typename T , int size_max> inline void DifferenceSequence<T,size_max>::FinalSegmentAdd( const int& v_final , const T& u ) { IntervalAdd( 0 , v_final , u ); }
template <typename T , int size_max> inline void DifferenceSequence<T,size_max>::IntervalAdd( const int& v_start , const int& v_final , const T& u ) { SubTreeAdd( v_start , { v_final } , u ); }

template <typename T , int size_max> inline void DifferenceSequence<T,size_max>::IntervalSubtract( const int& v_start , const int& v_final , const T& u ) { SubTreeAdd( v_start , { v_final } , -u ); }


template <typename V , typename T , typename U , int size_max>
DifferenceSequenceBody<V,T,U,size_max>& DifferenceSequenceBody<V,T,U,size_max>::operator+=( const DifferenceSequenceBody<V,T,U,size_max>& a )
{

  for( int i = 0 ; i < m_size ; i++ ){

    Addition( a.m_a[i] , m_a[i] );
    Addition( a.m_lazy_addition[i] , m_lazy_addition[i] );
    
  }

  Update();
  return *this;
  
}

template <typename V , typename T , typename U , int size_max>
void DifferenceSequenceBody<V,T,U,size_max>::Update()
{

  if( ! m_updated ){

    return;

  }

  for( int i = 0 ; i < m_size ; i++ ){

    const int j = e_inv( Edge_inv( e( i ) ) );
    
    if( j != i ){

      assert( j < i );
      Addition( m_lazy_addition[j] , m_lazy_addition[i] );

    }

  }

  const T& unit = Unit();

  for( int i = 0 ; i < m_size ; i++ ){

    U& m_lazy_addition_i = m_lazy_addition[i];
    Action( m_lazy_addition_i , m_a[i] );
    m_lazy_addition_i = unit;

  }

  m_updated = false;
  return;
  
}


template <typename T , int size_max> inline list<int> DifferenceSequence<T,size_max>::Edge( const int& v ) const { using base = DifferenceSequenceBody<int,T,T,size_max>; const int w = v + 1; return w < base::m_size ? list<int>{ w } : list<int>{}; }

template <typename T , int size_max> inline int DifferenceSequence<T,size_max>::Edge_inv( const int& v ) const { const int w = v - 1; return w < 0 ? v : w; }

template <typename T , int size_max> inline int DifferenceSequence<T,size_max>::e( const int& i ) const { return i; }

template <typename T , int size_max> inline int DifferenceSequence<T,size_max>::e_inv( const int& v ) const { return v; }

template <typename T , int size_max> inline const T& DifferenceSequence<T,size_max>::Unit() const { static const T unit{}; return unit; }

template <typename T , int size_max> inline T& DifferenceSequence<T,size_max>::Addition( const T& t0 , T& t1 ) const { return t1 += t0; }

template <typename T , int size_max> inline T DifferenceSequence<T,size_max>::Inverse( const T& u ) const { return -u; }

template <typename T , int size_max> inline T& DifferenceSequence<T,size_max>::Action( const T& u , T& t ) const { return t += u; }
