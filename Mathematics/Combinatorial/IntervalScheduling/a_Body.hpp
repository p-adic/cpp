// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/IntervalScheduling/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline void IntervalScheduling<T>::insert( const T& l , const T& r ) { assert( l < r ); m_l.push_back( l ); m_r.push_back( r ); m_valid.push_back( true ); m_rli.insert( { r , l , m_count++ } ); m_size = m_rli.size(); if( m_l_max < l ){ m_l_max = l; } }
template <typename T> inline void IntervalScheduling<T>::erase( const tuple<T,T,int>& v ) { auto& [l,r,i] = v; assert( 0 <= i && i < m_count ? m_l[i] == l && m_r[i] == l : false ); m_valid[i] = false; m_rli.erase( v ); m_size = m_rli.size(); }

template <typename T> inline const int& IntervalScheduling<T>::count() const noexcept { return m_count; }
template <typename T> inline const T& IntervalScheduling<T>::GetL( const int& i ) const { assert( 0 <= i && i < m_count ); return m_l[i]; }
template <typename T> inline const T& IntervalScheduling<T>::GetR( const int& i ) const { assert( 0 <= i && i < m_count ); return m_r[i]; }
template <typename T> inline bool IntervalScheduling<T>::GetValid( const int& i ) const { assert( 0 <= i && i < m_count ); return m_valid[i]; }
template <typename T> inline const int& IntervalScheduling<T>::size() const noexcept { return m_size; }

template <typename T> inline const int& IntervalScheduling<T>::Init() const { assert( m_size > 0 ); return get<2>( *( m_rli.begin() ) ); }

template <typename T>
int IntervalScheduling<T>::Next( const int& i ) const
{

  assert( 0 <= i && i < m_count ? m_valid[i] : false );
  const T& r_i = m_r[i];
  auto itr = m_rli.upper_bound( { m_r[i] , m_l_max , m_count } ) , end = m_rli.end();

  while( itr != end ){

    if( r_i <= get<1>( *itr ) ){

      return get<2>( *itr );

    }

  }

  return -1;

}

template <typename T>
void IntervalScheduling<T>::SetNext( vector<int>& a ) const noexcept
{

  a.resize( m_size );
  auto itr_1 = m_rli.begin() , end = m_rli.end();
  auto itr_0 = itr_1++;

  while( itr_1 != end ){

    if( get<0>( *itr_0 ) <= get<1>( *itr_1 ) ){

      a[ get<2>( *itr_0 ) ] = get<2>( *itr_1 );
      itr_0++;

    } else {

      itr_1++;

    }

  }

  while( itr_0 != end ){

    a[ get<2>( *( itr_0++ ) ) ] = -1;

  }

  return;

}

template <typename T>
void IntervalScheduling<T>::SetMaximal( list<int>& a , const int& i ) const
{

  a.clear();

  if( m_size == 0 ){

    assert( i == -1 );
    return;

  }
  
  auto itr = i == -1 ? m_rli.begin() : ( assert( 0 <= i && i < m_count ? m_valid[i] : false ) , m_rli.lower_bound( { m_r[i] , m_l[i] , i } ) ) , end = m_rli.end();

  while( itr != end ){

    a.push_back( get<2>( *itr ) );
    auto itr_prev = itr++;
    const T& r_i = get<0>( *itr_prev );

    while( itr != end ){

      if( r_i <= get<1>( *itr ) ){

	break;	

      } else {

	itr++;

      }

    }

  }

  return;

}
