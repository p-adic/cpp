// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Algebra/Monoid/Group/a_Body.hpp"

template <typename U , typename ABELIAN_GROUP> inline AbstractBIT<U,ABELIAN_GROUP>::AbstractBIT( ABELIAN_GROUP M , const int& size ) : m_M( move( M ) ) , m_size( size ) , m_fenwick( m_size + 1 , m_M.Zero() ) , m_power( 1 ) { Construct(); }
template <typename U , typename ABELIAN_GROUP> inline AbstractBIT<U,ABELIAN_GROUP>::AbstractBIT( ABELIAN_GROUP M , const vector<U>& a ) : m_M( move( M ) ) , m_size( a.size() ) , m_fenwick( m_size + 1 , m_M.Zero() ) , m_power( 1 )
{

  Construct();

  for( int j = 1 ; j <= m_size ; j++ ){

    U& fenwick_j = m_fenwick[j];
    int i = j - 1;
    fenwick_j = a[i];
    int i_lim = j - ( j & -j );

    while( i > i_lim ){

      fenwick_j = m_M.Sum( fenwick_j , m_fenwick[i] );
      i -= ( i & -i );

    }

  }

}

template <typename U , typename ABELIAN_GROUP> inline void AbstractBIT<U,ABELIAN_GROUP>::Construct()
{

  static_assert( is_same_v<U,inner_t<ABELIAN_GROUP>> );
  
  while( m_power < m_size ){

    m_power <<= 1;

  }
  
}
  
template <typename U> template <typename...Args> inline BIT<U>::BIT( const Args&... args ) : AbstractBIT<U,AdditiveGroup<U>>( AdditiveGroup<U>() , args... ) { static_assert( !is_same_v<U,int> ); }

template <typename U , typename ABELIAN_GROUP> template <typename...Args> inline void AbstractBIT<U,ABELIAN_GROUP>::Initialise( const Args&... args ) { *this = AbstractBIT<U,ABELIAN_GROUP>( move( m_M ) , args... ); }
template <typename U , typename ABELIAN_GROUP> inline void AbstractBIT<U,ABELIAN_GROUP>::Set( const int& i , const U& u ) { Add( i , m_M.Sum( m_M.Inverse( IntervalSum( i , i ) ) , u ) ); }
template <typename U , typename ABELIAN_GROUP> inline AbstractBIT<U,ABELIAN_GROUP>& AbstractBIT<U,ABELIAN_GROUP>::operator+=( const vector<U>& a ) { AbstractBIT<U,ABELIAN_GROUP> a_copy{ m_M , a }; assert( m_size == a_copy.m_size ); for( int j = 1 ; j <= m_size ; j++ ){ m_fenwick[j] = m_M.Sum( m_fenwick[j] , a.m_fenwick[j] ); } return *this; }

template <typename U , typename ABELIAN_GROUP>
void AbstractBIT<U,ABELIAN_GROUP>::Add( const int& i , const U& u )
{
  
  int j = i + 1;

  while( j <= m_size ){

    U& m_fenwick_j = m_fenwick[j];
    m_fenwick_j = m_M.Sum( m_fenwick_j , u );
    j += ( j & -j );

  }

  return;
  
}

template <typename U , typename ABELIAN_GROUP> inline const int& AbstractBIT<U,ABELIAN_GROUP>::size() const noexcept { return m_size; }
template <typename U , typename ABELIAN_GROUP> inline U AbstractBIT<U,ABELIAN_GROUP>::operator[]( const int& i ) const { assert( i < m_size ); return IntervalSum( i , i ); }
template <typename U , typename ABELIAN_GROUP> inline U AbstractBIT<U,ABELIAN_GROUP>::Get( const int& i ) const { return operator[]( i ); }

template <typename U , typename ABELIAN_GROUP> inline const U& AbstractBIT<U,ABELIAN_GROUP>::LSBSegmentSum( const int& j ) const { assert( 0 < j && j <= m_size ); return m_fenwick[j]; }

template <typename U , typename ABELIAN_GROUP> 
U AbstractBIT<U,ABELIAN_GROUP>::InitialSegmentSum( const int& i_final )
{

  U sum = m_M.Zero();
  int j = min( i_final + 1 , m_size );

  while( j > 0 ){

    sum = m_M.Sum( sum , m_fenwick[j] );
    j -= j & -j;
    
  }

  return sum;
  
}

template <typename U , typename ABELIAN_GROUP> inline U AbstractBIT<U,ABELIAN_GROUP>::IntervalSum( const int& i_start , const int& i_final ) { return m_M.Sum( m_M.Inverse( InitialSegmentSum( i_start - 1 ) ) , InitialSegmentSum( i_final ) ); }


template <typename U , typename ABELIAN_GROUP> template <typename F , SFINAE_FOR_BIT_BS>
int AbstractBIT<U,ABELIAN_GROUP>::BinarySearch( const F& f )
{

  int j = 0;
  int power = m_power;
  U sum = m_M.Zero();
  U sum_next = sum;
  
  while( power > 0 ){

    int j_next = j | power;

    if( j_next <= m_size ){
      
      sum_next = m_M.Sum( sum_next , m_fenwick[j_next] );

      if( f( sum_next , j_next - 1 ) ){
	
	sum_next = sum;

      } else {

	sum = sum_next;
	j = j_next;
	
      }
      
    }
    
    power >>= 1;

  }

  // f( InitialSegmentSum( i ) , i )がfalseとなるiが存在するならばjはその最大値に
  // 1を足したものとなり、存在しないならばj=0となる。
  // いずれの場合もf( InitialSegmentSum( i ) , i )がtrueとなるiが存在するならば
  // jはそのような最小のiと等しい。
  return j;
  
}

template <typename U , typename ABELIAN_GROUP> template <typename F , SFINAE_FOR_BIT_BS> inline int AbstractBIT<U,ABELIAN_GROUP>::BinarySearch( const int& i_start , const F& f ) { const U u_inv = m_M.Inverse( InitialSegmentSum( i_start - 1 ) ); return max( i_start , BinarySearch( [&]( const U& sum , const int& i ){ return i_start <= i && f( m_M.Sum( u_inv , sum ) , i ); } ) ); }

template <typename U , typename ABELIAN_GROUP> inline int AbstractBIT<U,ABELIAN_GROUP>::BinarySearch( const U& u ) { return BinarySearch( [&]( const U& sum , const int& ){ return !( sum < u ); } ); }

template <typename U , typename ABELIAN_GROUP> inline int AbstractBIT<U,ABELIAN_GROUP>::BinarySearch( const int& i_start , const U& u ) { return max( i_start , BinarySearch( m_M.Sum( InitialSegmentSum( i_start - 1 ) , u ) ) ); }
