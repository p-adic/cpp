// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/DifferenceSequence/TwoDimensional/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U , typename GROUP> inline AbstractTwoDimensionalDifferenceSequence<U,GROUP>::AbstractTwoDimensionalDifferenceSequence( GROUP M , const int& size_X , const int& size_Y ) : m_M( move( M ) ) , m_size_X( size_X ) , m_size_Y( size_Y ) , m_a( m_size_X , vector<U>( m_size_Y , m_M.Zero() ) ) , m_lazy_addition( m_a ) , m_updated( false ) { static_assert( ! is_same_v<U,int> ); }
template <typename U , typename GROUP> inline AbstractTwoDimensionalDifferenceSequence<U,GROUP>::AbstractTwoDimensionalDifferenceSequence( GROUP M , vector<vector<U>> a ) : m_M( move( M ) ) , m_size_X( a.size() ) , m_size_Y( m_size_X > 0 ? a.front().size() : 0 ) , m_a( move( a ) ) , m_lazy_addition( m_size_X , vector<U>( m_size_Y , m_M.Zero() ) ) , m_updated( false ) { static_assert( ! is_same_v<U,int> ); }
template <typename U> template <typename...Args> inline TwoDimensionalDifferenceSequence<U>::TwoDimensionalDifferenceSequence( Args&&... args ) : AbstractTwoDimensionalDifferenceSequence<U,AdditiveGroup<U>>( AdditiveGroup<U>() , forward<decay_t<Args>>( args )... ) {}

template <typename U , typename GROUP> template <typename...Args> inline void AbstractTwoDimensionalDifferenceSequence<U,GROUP>::Initialise( Args&&... args ) { *this = AbstractTwoDimensionalDifferenceSequence<U,GROUP>( move( m_M ) , forward<decay_t<Args>>( args )... ); }
template <typename U , typename GROUP> inline void AbstractTwoDimensionalDifferenceSequence<U,GROUP>::Set( const int& i_x , const int& i_y , const U& u ) { Update(); m_a[i_x][i_y] = u; }
template <typename U , typename GROUP> inline const U& AbstractTwoDimensionalDifferenceSequence<U,GROUP>::Get( const int& i_x , const int& i_y ) { Update(); return m_a[i_x][i_y]; }
template <typename U , typename GROUP> inline U& AbstractTwoDimensionalDifferenceSequence<U,GROUP>::Ref( const int& i_x , const int& i_y ) { return m_a[i_x][i_y]; }

template <typename U , typename GROUP> inline void AbstractTwoDimensionalDifferenceSequence<U,GROUP>::Add( const int& i_x , const int& i_y , const U& u ) { m_a[i_x][i_y] = m_M.Sum( move( m_a[i_x][i_y] ) , u ); }
  
template <typename U , typename GROUP> inline void AbstractTwoDimensionalDifferenceSequence<U,GROUP>::RectangleAdd( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const U& u )
{

  m_updated = true;
  vector<U>& m_lazy_addition_i_start_x = m_lazy_addition[i_start_x];
  m_lazy_addition_i_start_x[i_start_y] = m_M.Sum( move( m_lazy_addition_i_start_x[i_start_y] ) , u );
  const int i_final_y_plus = i_final_y + 1;
  const U u_inv = m_M.Inverse( u );

  if( i_final_y_plus < m_size_Y ){

    m_lazy_addition_i_start_x[i_final_y_plus] = m_M.Sum( move( m_lazy_addition_i_start_x[i_final_y_plus] ) , u_inv );

  }

  const int i_final_x_plus = i_final_x + 1;
  
  if( i_final_x_plus < m_size_X ){

    vector<U>& m_lazy_addition_i_final_x_plus = m_lazy_addition[i_final_x_plus];
    m_lazy_addition_i_final_x_plus[i_start_y] = m_M.Sum( move( m_lazy_addition_i_final_x_plus[i_start_y] ) , u_inv );

    if( i_final_y_plus < m_size_Y ){

      m_lazy_addition_i_final_x_plus[i_final_y_plus] = m_M.Sum( move( m_lazy_addition_i_final_x_plus[i_final_y_plus] ) , u );

    }

  }

  return;
  
}

template <typename U , typename GROUP> inline AbstractTwoDimensionalDifferenceSequence<U,GROUP>& AbstractTwoDimensionalDifferenceSequence<U,GROUP>::operator+=( const vector<U>& a )
{

  assert( m_size_X == int( a.size() ) && m_size_X > 0 ? m_size_Y == int( a[0].size() ) : true );

  for( int x = 0 ; x < m_size_X ; x++ ){

    vector<U>& m_a_x = m_a[x];
    const vector<U>& a_x = a.m_a[x];

    for( int y = 0 ; y < m_size_Y ; y++ ){

      m_a_x[y] = m_M.Sum( move( m_a_x[y] ) , a_x[y] );

    }
  
  }

  return *this;

}

template <typename U , typename GROUP> void AbstractTwoDimensionalDifferenceSequence<U,GROUP>::Update()
{

  if( ! m_updated ){

    return;

  }

  const U& zero = m_M.Zero();
  vector<U> diff( m_size_Y , zero );
  
  for( int x = 0 ; x < m_size_X ; x++ ){

    vector<U>& m_a_x = m_a[x];
    vector<U>& m_lazy_addition_x = m_lazy_addition[x];
    U temp = zero;

    for( int y = 0 ; y < m_size_Y ; y++ ){

      U& m_lazy_addition_xy = m_lazy_addition_x[y];
      temp = m_M.Sum( move( temp ) , m_lazy_addition_xy );
      diff[y] = m_M.Sum( move( diff[y] ) , temp );
      m_a_x[y] = m_M.Sum( move( m_a_x[y] ) , diff[y] );
      m_lazy_addition_xy = zero;

    }
  
  }

  m_updated = false;
  return;

}
