// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/DifferenceSequence/TwoDimensional/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline TwoDimensionalDifferenceSequence<T>::TwoDimensionalDifferenceSequence( const vector<vector<T> >& a ) : m_size_X( a.size() ) , m_size_Y() , m_a( a ) , m_lazy_addition( m_size_X , vector<T>( m_size_X > 0 ? m_a.front().size() : 0 ) ) , m_updated( false ) { static_assert( ! is_same<T,int>::value ); }
template <typename T> inline TwoDimensionalDifferenceSequence<T>::TwoDimensionalDifferenceSequence( vector<vector<T> >&& a ) : m_size_X( a.size() ) , m_size_Y() , m_a( move( a ) ) , m_lazy_addition( m_size_X , vector<T>( m_size_X > 0 ? m_a.front().size() : 0 ) ) , m_updated( false ) { static_assert( ! is_same<T,int>::value ); }

template <typename T> inline TwoDimensionalDifferenceSequence<T>::TwoDimensionalDifferenceSequence( const int& size_X , const int& size_Y ) : m_size_X( size_X ) , m_size_Y( size_Y ) , m_a( m_size_X , vector<T>( m_size_Y ) ) , m_lazy_addition( m_size_X , vector<T>( m_size_Y ) ) , m_updated( false ) { static_assert( ! is_same<T,int>::value ); }

template <typename T> template <int size_X_max , int size_Y_max> inline TwoDimensionalDifferenceSequence<T>::TwoDimensionalDifferenceSequence( const T ( &a )[size_X_max][size_Y_max] , const int& size_X , const int& size_Y ) : m_size_X( size_X ) , m_size_Y( size_Y ) , m_a( m_size_X ) , m_lazy_addition( m_size_X ) , m_updated( false )
{

  static_assert( ! is_same<T,int>::value );
  assert( m_size_X <= size_X_max && m_size_Y <= size_Y_max );

  for( int x = 0 ; x < m_size_X ; x++ ){

    const T ( &a_x )[size_Y_max] = a[x];
    vector<T>& m_a_x = m_a[x];
    m_a_x.reserve( m_size_Y );

    for( int y = 0 ; y < m_size_Y ; y++ ){

      m_a_x.push_back( a_x[y] );

    }

  }

}

template <typename T> inline void TwoDimensionalDifferenceSequence<T>::Set( const int& i_x , const int& i_y , const T& t ) { Update(); m_a[i_x][i_y] = t; }
template <typename T> inline const T& TwoDimensionalDifferenceSequence<T>::Get( const int& i_x , const int& i_y ) { Update(); return m_a[i_x][i_y]; }
template <typename T> inline T& TwoDimensionalDifferenceSequence<T>::Ref( const int& i_x , const int& i_y ) { return m_a[i_x][i_y]; }

template <typename T> inline void TwoDimensionalDifferenceSequence<T>::Add( const int& i_x , const int& i_y , const T& t ) { m_a[i_x][i_y] += t; }
  
template <typename T> inline void TwoDimensionalDifferenceSequence<T>::RectangleAdd( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const T& t )
{

  m_updated = true;
  vector<T>& m_lazy_addition_i_start_x = m_lazy_addition[i_start_x];
  m_lazy_addition_i_start_x[i_start_y] += t;
  const int i_final_y_plus = i_final_y + 1;

  if( i_final_y_plus < m_size_Y ){

    m_lazy_addition_i_start_x[i_final_y_plus] -= t;

  }

  const int i_final_x_plus = i_final_x + 1;
  
  if( i_final_x_plus < m_size_X ){

    vector<T>& m_lazy_addition_i_final_x_plus = m_lazy_addition[i_final_x_plus];
    m_lazy_addition_i_final_x_plus[i_start_y] -= t;

    if( i_final_y_plus < m_size_Y ){

      m_lazy_addition_i_final_x_plus[i_final_y_plus] += t;

    }

  }

  return;
  
}

template <typename T> inline void TwoDimensionalDifferenceSequence<T>::RectangleSubtract( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const T& t ) { RectangleAdd( i_start_x , i_start_y , i_final_x , i_final_y , -t ); }

template <typename T> inline TwoDimensionalDifferenceSequence<T>& TwoDimensionalDifferenceSequence<T>::operator+=( const TwoDimensionalDifferenceSequence<T>& a )
{

  assert( m_size_X == a.m_size_X && m_size_Y == a.m_size_Y );

  for( int x = 0 ; x < m_size_X ; x++ ){

    vector<T>& m_a_x = m_a[x];
    vector<T>& m_lazy_addition_x = m_a[x];
    const vector<T>& a_x = a.m_a[x];
    const vector<T>& lazy_addition_x = a.m_lazy_addition[x];

    for( int y = 0 ; y < m_size_Y ; y++ ){

      m_a_x[y] += a_x[y];
      m_lazy_addition_x[y] += lazy_addition_x[y];

    }
  
  }

  Update();
  return *this;

}

template <typename T> void TwoDimensionalDifferenceSequence<T>::Update()
{

  if( ! m_updated ){

    return;

  }

  vector<T> diff( m_size_Y );
  T zero{};
  
  for( int x = 0 ; x < m_size_X ; x++ ){

    vector<T>& m_a_x = m_a[x];
    vector<T>& m_lazy_addition_x = m_lazy_addition[x];
    T temp = zero;

    for( int y = 0 ; y < m_size_Y ; y++ ){

      T& m_lazy_addition_xy = m_lazy_addition_x[y];
      m_a_x[y] += diff[y] += temp += m_lazy_addition_xy;
      m_lazy_addition_xy = zero;

    }
  
  }

  m_updated = false;
  return;

}
