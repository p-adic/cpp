// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/TwoDimensional/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U , typename ABELIAN_GROUP> inline AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::AbstractTwoDimensionalDifferenceSequence( ABELIAN_GROUP M , const int& size_X , const int& size_Y , int degree ) : AbstractTwoDimensionalDifferenceSequence( M , vector( size_X , vector<U>( size_Y , M.Zero() ) ) , move( degree ) ) {}
template <typename U , typename ABELIAN_GROUP> inline AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::AbstractTwoDimensionalDifferenceSequence( ABELIAN_GROUP M , const vector<vector<U>>& a , int degree ) : m_M( move( M ) ) , m_size_X( a.size() ) , m_size_Y( m_size_X > 0 ? a[0].size() : 0 ) , m_a( m_size_X + 1 , vector<U>( m_size_Y + 1 , m_M.Zero() ) ) , m_degree( move( degree ) )
{

  for( int x = 0 ; x < m_size_X ; x++ ){

    for( int y = 0 ; y < m_size_Y ; y++ ){

      m_a[x+1][y+1] = a[x][y];

    }

  }

  cerr << "TwoDimensionalDifferenceSequence‚ðƒfƒoƒbƒOƒ‚[ƒh‚ÅŽÀs‚µ‚Ü‚·B" << endl;
  cerr << degree << "ŠK‚ÌŠK·”—ñ‚Ì‰Šú’l‚Í" << endl;
  cerr << *this << endl;
  cerr << "‚Å‚·B" << endl;
  cerr << endl;
  
}

template <typename U> template <typename...Args> inline TwoDimensionalDifferenceSequence<U>::TwoDimensionalDifferenceSequence( Args&&... args ) : AbstractTwoDimensionalDifferenceSequence<U,AdditiveGroup<U>>( AdditiveGroup<U>() , forward<decay_t<Args>>( args )... ) {}

template <typename U , typename ABELIAN_GROUP> template <typename...Args> inline void AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::Initialise( Args&&... args )
{

  cerr << "TwoDimensionalDifferenceSequence‚ð‰Šú‰»‚µAÄ“x" << endl;
  AbstractTwoDimensionalDifferenceSequence temp{ m_M , forward<decay_t<Args>>( args )... };
  m_size_X = temp.m_size_X;
  m_size_Y = temp.m_size_Y;
  m_a = move( temp.m_a );
  m_degree = temp.m_degree;
  return;

}

template <typename U , typename ABELIAN_GROUP> inline const int& AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::size_X() const noexcept { return m_size_X; }
template <typename U , typename ABELIAN_GROUP> inline const int& AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::size_Y() const noexcept { return m_size_Y; }
template <typename U , typename ABELIAN_GROUP> inline const vector<vector<U>>& AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::Get() const noexcept { return m_a; }

template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::Set( const int& i_x , const int& i_y , const U& u , const int& degree )
{

  cerr << degree << "ŠK‚ÌŠK·”—ñ‚Ì(" << i_x << "," << i_y << ")‚Å‚Ì’l‚É" << endl;
  cerr << u << "‚ð‘ã“ü‚µ‚Ü‚·B" << endl;
  cerr << "‚»‚Ì‚½‚ß‚É";
  Add( i_x , i_y , m_M.Sum( m_M.Inverse( Get( i_x , i_y , degree ) ) , u ) , degree );
  return;

}

template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::Add( const int& i_x , const int& i_y , const U& u , const int& degree )
{

  cerr << degree << "ŠK‚ÌŠK·”—ñ‚Ì(" << i_x << "," << i_y << ")‚Å‚Ì’l‚É" << endl;
  cerr << u << "‚ð‰ÁŽZ‚µ‚Ü‚·B" << endl;

  if( u == m_M.Zero() ){

    cerr << "‰ÁŽZ’l‚ª" << u << "‚È‚Ì‚ÅXV‚ðs‚¢‚Ü‚¹‚ñ‚Å‚µ‚½B" << endl;
    cerr << endl;
    return;

  }

  Shift( degree );
  auto& m_a_i_x_i_y = m_a[i_x+1][i_y+1];
  m_a_i_x_i_y = m_M.Sum( move( m_a_i_x_i_y ) , u );
  cerr << "‰ÁŽZŒã‚Ì" << m_degree << "ŠK‚ÌŠK·”—ñ‚Í" << endl;
  cerr << *this << endl;
  cerr << "‚Å‚·B" << endl;
  cerr << endl;
  return;

}
  
template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::RectangleAdd( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const U& u , const int& degree )
{

  cerr << degree << "ŠK‚ÌŠK·”—ñ‚Ì‹éŒ`[" << i_start_x << "," << i_final_x << "] times [" << i_start_y << "," << i_final_y << "]‚É" << endl;
  cerr << u << "‚ð‰ÁŽZ‚µ‚Ü‚·B" << endl;
  
  if( u == m_M.Zero() ){

    cerr << "‰ÁŽZ’l‚ª" << u << "‚È‚Ì‚ÅXV‚ðs‚¢‚Ü‚¹‚ñ‚Å‚µ‚½B" << endl;
    cerr << endl;
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

  cerr << "‰ÁŽZŒã‚Ì" << m_degree << "ŠK‚ÌŠK·”—ñ‚Í" << endl;
  cerr << *this << endl;
  cerr << "‚Å‚·B" << endl;
  cerr << endl;
  return;
  
}

template <typename U , typename ABELIAN_GROUP> inline const U& AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::Get( const int& i_x , const int& i_y , const int& degree )
{

  assert( 0 <= i_x && i_x < m_size_X && 0 <= i_y && i_y < m_size_Y );
  cerr << degree << "ŠK‚ÌŠK·”—ñ‚Ì(" << i_x << "," << i_y << ")‚Å‚Ì’l‚ðŽæ“¾‚µ‚Ü‚·B" << endl;
  Shift( degree );
  cerr << degree << "ŠK‚ÌŠK·”—ñ‚Ì(" << i_x << "," << i_y << ")‚Å‚Ì’l‚Í" << endl;
  cerr << m_a[i_x+1][i_y+1] << "‚Å‚·B" << endl;
  cerr << endl;
  return m_a[i_x+1][i_y+1];

}

template <typename U , typename ABELIAN_GROUP> inline const U& AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::InitialRectangleSum( const int& i_x , const int& i_y , const int& degree )
{
  assert( -1 <= i_x && i_x < m_size_X && -1 <= i_y && i_y < m_size_Y );
  cerr << degree << "ŠK‚ÌŠK·”—ñ‚Ì‹éŒ`[0," << i_x << "] times [0," << i_y << "]‚Ì‘˜a‚ðŽæ“¾‚µ‚Ü‚·B" << endl;
  Shift( degree - 1 );
  cerr << degree << "ŠK‚ÌŠK·”—ñ‚Ì(" << i_x << "," << i_y << ")‚Å‚Ì’l‚Í" << endl;
  cerr << m_a[i_x+1][i_y+1] << "‚Å‚·B" << endl;
  cerr << endl;
  return m_a[i_x+1][i_y+1];
}

template <typename U , typename ABELIAN_GROUP> inline U AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>::RectangleSum( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const int& degree )
{

  assert( 0 <= i_start_x && i_start_x - 1 <= i_final_x && i_final_x < m_size_X && 0 <= i_start_y && i_start_y - 1 <= i_final_y && i_final_y < m_size_Y );
  cerr << degree << "ŠK‚ÌŠK·”—ñ‚Ì‹éŒ`[" << i_start_x << "," << i_final_x << "] times [" << i_start_y << "," << i_final_y << "]‚Å‚Ì‘˜a‚ðŽæ“¾‚µ‚Ü‚·B" << endl;
  Shift( degree - 1 );
  U answer = m_M.Sum( m_M.Sum( m_a[i_start_x][i_start_y] , m_M.Inverse( m_M.Sum( m_a[i_final_x+1][i_start_y] , m_a[i_start_x][i_final_y+1] ) ) ) , m_a[i_final_x+1][i_final_y+1] );
  cerr << degree << "ŠK‚ÌŠK·”—ñ‚Ì‹éŒ`[" << i_start_x << "," << i_final_x << "] times [" << i_start_y << "," << i_final_y << "]‚Ì‘˜a‚Í" << endl;
  cerr << answer << "‚Å‚·B" << endl;
  cerr << endl;
  return answer;

}

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

  cerr << "ŠK·”—ñ‚ÌŠK”‚ð" << m_degree + 1 << "‚©‚ç" << m_degree << "‚É•ÏX‚µ‚Ü‚·B" << endl;
  cerr << m_degree << "ŠK‚ÌŠK·”—ñ‚ÌŒ»Ý’l‚Í" << endl;
  cerr << *this << endl;
  cerr << "‚Å‚ ‚èA" << endl;
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

  cerr << "ŠK·”—ñ‚ÌŠK”‚ð" << m_degree - 1 << "‚©‚ç" << m_degree << "‚É•ÏX‚µ‚Ü‚·B" << endl;
  cerr << m_degree << "ŠK‚ÌŠK·”—ñ‚ÌŒ»Ý’l‚Í" << endl;
  cerr << *this << endl;
  cerr << "‚Å‚ ‚èA" << endl;
  return;

}


template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>& tdds )
{

  const int& size_X = tdds.size_X();
  const int& size_Y = tdds.size_Y();
  auto& a = tdds.Get();

  for( int x = 0 ; x < size_X ; x++ ){

    if( x > 0 ){

      os << endl;

    }
      
    for( int y = 0 ; y < size_Y ; y++ ){

      ( y == 0 ? os : os << " " ) << a[x+1][y+1];

    }

  }

  return os;

}
