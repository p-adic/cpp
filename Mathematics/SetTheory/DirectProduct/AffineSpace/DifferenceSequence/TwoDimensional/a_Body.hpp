// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/DifferenceSequence/TwoDimensional/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U , typename ABELIAN_GROUP> inline AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::AbstractTwoDimensionalDifferenceSequence( ABELIAN_GROUP M , const int& size_X , const int& size_Y , int degree ) : m_M( move( M ) ) , m_size_X( size_X ) , m_size_Y( size_Y ) , m_a( m_size_X + 1 , vector<U>( m_size_Y + 1 , m_M.Zero() ) ) , m_degree( move( degree ) ) {}
template <typename U , typename ABELIAN_GROUP> inline AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::AbstractTwoDimensionalDifferenceSequence( ABELIAN_GROUP M , const vector<vector<U>>& a , int degree ) : m_M( move( M ) ) , m_size_X( a.size() ) , m_size_Y( m_size_X > 0 ? a[0].size() : 0 ) , m_a( m_size_X + 1 , vector<U>( m_size_Y + 1 , m_M.Zero() ) ) , m_degree( move( degree ) )
{

  for( int x = 0 ; x < m_size_X ; x++ ){

    for( int y = 0 ; y < m_size_Y ; y++ ){

      m_a[x+1][y+1] = a[x][y];

    }

  }
  
}

template <typename U> template <typename...Args> inline TwoDimensionalDifferenceSequence<U>::TwoDimensionalDifferenceSequence( Args&&... args ) : AbstractTwoDimensionalDifferenceSequence<U,AdditiveGroup<U>>( AdditiveGroup<U>() , forward<decay_t<Args>>( args )... ) {}

template <typename U , typename ABELIAN_GROUP> template <typename...Args> inline void AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::Initialise( Args&&... args ) { AbstractTwoDimensionalDifferenceSequence temp{ m_M , forward<decay_t<Args>>( args )... }; m_size_X = temp.m_size_X; m_size_Y = temp.m_size_Y; m_a = move( temp.m_a ); m_degree = temp.m_degree; }

template <typename U , typename ABELIAN_GROUP> inline const int& AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::size_X() const noexcept { return m_size_X; }
template <typename U , typename ABELIAN_GROUP> inline const int& AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::size_Y() const noexcept { return m_size_Y; }

template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::Set( const int& i_x , const int& i_y , const U& u , const int& degree ) { Add( i_x , i_y , m_M.Sum( m_M.Inverse( Get( i_x , i_y , degree ) ) , u ) , degree ); }

template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::Add( const int& i_x , const int& i_y , const U& u , const int& degree ) { if( u == m_M.Zero() ){ return; } Shift( degree ); auto& m_a_i_x_i_y = m_a[i_x+1][i_y+1]; m_a_i_x_i_y = m_M.Sum( move( m_a_i_x_i_y ) , u ); }
  
template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::RectangleAdd( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const U& u , const int& degree )
{

  if( u == m_M.Zero() ){

    return;

  }

  Shift( degree + 1 );
  auto& m_a_i_start_x = m_a[i_start_x+1];
  auto& m_a_i_start_x_i_start_y = m_a_i_start_x[i_start_y+1];
  m_a_i_start_x_i_start_y = m_M.Sum( move( m_a_i_start_x_i_start_y ) , u );
  const int i_final_y_plus = i_final_y + 1;
  const U u_inv = m_M.Inverse( u );

  if( i_final_y_plus < m_size_Y ){

    auto& m_a_i_start_x_i_final_y_plus = m_a_i_start_x[i_final_y_plus+1];
    m_a_i_start_x_i_final_y_plus = m_M.Sum( move( m_a_i_start_x_i_final_y_plus ) , u_inv );

  }

  const int i_final_x_plus = i_final_x + 1;
  
  if( i_final_x_plus < m_size_X ){

    auto& m_a_i_final_x_plus = m_a[i_final_x_plus+1];
    auto& m_a_i_final_x_plus_i_start_y = m_a_i_final_x_plus[i_start_y+1];
    m_a_i_final_x_plus_i_start_y = m_M.Sum( move( m_a_i_final_x_plus_i_start_y ) , u_inv );

    if( i_final_y_plus < m_size_Y ){

      auto& m_a_i_final_x_plus_i_final_y_plus = m_a_i_final_x_plus[i_final_y_plus+1];
      m_a_i_final_x_plus_i_final_y_plus = m_M.Sum( move( m_a_i_final_x_plus_i_final_y_plus ) , u );

    }

  }

  return;
  
}

template <typename U , typename ABELIAN_GROUP> inline const U& AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::Get( const int& i_x , const int& i_y , const int& degree ) { assert( 0 <= i_x && i_x < m_size_X && 0 <= i_y && i_y < m_size_Y ); Shift( degree ); return m_a[i_x+1][i_y+1]; }

template <typename U , typename ABELIAN_GROUP> inline const U& AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::InitialRectangleSum( const int& i_x , const int& i_y , const int& degree ) { assert( -1 <= i_x && i_x < m_size_X && -1 <= i_y && i_y < m_size_Y ); Shift( degree - 1 ); return m_a[i_x+1][i_y+1]; }

template <typename U , typename ABELIAN_GROUP> inline U AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::RectangleSum( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const int& degree ) { assert( 0 <= i_start_x && i_start_x - 1 <= i_final_x && i_final_x < m_size_X && 0 <= i_start_y && i_start_y - 1 <= i_final_y && i_final_y < m_size_Y ); Shift( degree - 1 ); return m_M.Sum( m_M.Sum( m_a[i_start_x][i_start_y] , m_M.Inverse( m_M.Sum( m_a[i_final_x+1][i_start_y] , m_a[i_start_x][i_final_y+1] ) ) ) , m_a[i_final_x+1][i_final_y+1] ); }

template <typename U , typename ABELIAN_GROUP> void AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::Shift( const int& degree ) { while( m_degree < degree ){ Differentiate(); } while( m_degree > degree ){ Integrate(); } }

template <typename U , typename ABELIAN_GROUP> void AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::Integrate()
{

  m_degree--;
  
  for( int x = 0 ; x < m_size_X ; x++ ){

    auto& m_a_x_minus = m_a[x];
    auto& m_a_x = m_a[x+1];

    for( int y = 0 ; y < m_size_Y ; y++ ){

      U& m_a_xy = m_a_x[y+1];
      m_a_xy = m_M.Sum( m_M.Sum( m_M.Sum( move( m_a_xy ) , m_a_x_minus[y+1] ) , m_a_x[y] ) , m_M.Inverse( m_a_x_minus[y] ) );

    }
  
  }

  return;

}

template <typename U , typename ABELIAN_GROUP> void AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::Differentiate()
{

  m_degree++;
  
  for( int x = m_size_X - 1 ; x >= 0 ; x-- ){

    auto& m_a_x_minus = m_a[x];
    auto& m_a_x = m_a[x+1];

    for( int y = m_size_Y - 1 ; y >=0 ; y-- ){

    U& m_a_xy = m_a_x[y+1];
    m_a_xy = m_M.Sum( m_M.Sum( m_M.Sum( move( m_a_xy ) , m_M.Inverse( m_a_x_minus[y+1] ) ) , m_M.Inverse( m_a_x[y] ) ) , m_a_x_minus[y] );

    }
  
  }

  return;

}
