// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/CumulativeProd/TwoDimensional/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)>
TwoDimensionalCumulativeSum<T,m_T,e_T,i_T>::TwoDimensionalCumulativeSum( const vector<vector<T> >& a ) :
  m_size_X( a.size() ) , m_size_Y() , m_a( m_size_X + 1 )
{

  static_assert( ! is_same<T,int>::value );
  const T& zero = e_T();

  if( ! a.empty() ){

    m_size_Y = a[0].size();

  }

  m_a[0] = vector<T>( m_size_Y + 1 , zero );
  
  for( int x = 0 ; x < m_size_X ; x++ ){

    const vector<T>& a_x = a[x];
    const vector<T>& m_a_x_minus = m_a[x];
    vector<T>& m_a_x = m_a[x+1];
    m_a_x = vector<T>( m_size_Y + 1 , zero );
    T temp = zero;
      
    for( int y = 0 ; y < m_size_Y ; y++ ){

      m_a_x[y+1] = m_T( m_a_x_minus[y+1] , temp = m_T( temp , a_x[y] ) );

    }

  }

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)> template <int size_X_max , int size_Y_max>
TwoDimensionalCumulativeSum<T,m_T,e_T,i_T>::TwoDimensionalCumulativeSum( const T ( &a )[size_X_max][size_Y_max] , const int& size_X , const int& size_Y ) : m_size_X( size_X ) , m_size_Y( size_Y ) , m_a( m_size_X + 1 , vector<T>( m_size_Y + 1 , e_T() ) )
{

  assert( m_size_X <= size_X_max && m_size_Y <= size_Y_max );
  const T& zero = e_T();
  
  for( int x = 0 ; x < m_size_X ; x++ ){

    const T ( &a_x )[size_Y_max] = a[x];
    const vector<T>& m_a_x_minus = m_a[x];
    vector<T>& m_a_x = m_a[x+1];
    T temp = zero;
      
    for( int y = 0 ; y < m_size_Y ; y++ ){

      m_a_x[y+1] = m_T( m_a_x_minus[y+1] , temp = m_T( temp , a_x[y] ) );

    }

  }

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)> inline const T& TwoDimensionalCumulativeSum<T,m_T,e_T,i_T>::InitialRectangleSum( const int& i_x , const int& i_y ) const { assert( - 1 <= i_x && i_x < m_size_X && - 1 <= i_y && i_y < m_size_Y ); return m_a[i_x+1][i_y+1]; }

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)> inline T TwoDimensionalCumulativeSum<T,m_T,e_T,i_T>::RectangleSum( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y ) const
{ assert( 0 <= i_start_x && i_start_x - 1 <= i_final_x && i_final_x < m_size_X && 0 <= i_start_y && i_start_y - 1 <= i_final_y && i_final_y < m_size_Y ); return m_T( m_T( m_a[i_start_x][i_start_y] , i_T( m_T( m_a[i_final_x+1][i_start_y] , m_a[i_start_x][i_final_y+1] ) ) ) , m_a[i_final_x+1][i_final_y+1] ); }
