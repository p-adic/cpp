// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/IntervalSet/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Sqrt/a_Body.hpp"

template <typename U , typename NON_COMM_N_MODULE> template <typename...Args> inline IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE>::IntervalSetSqrtDecomposition( NON_COMM_N_MODULE M , const int& N , const Args&... args ) : SqrtDecompositionCoordinate( N , args... ) , m_M( move( M ) ) , m_a( m_N_m , m_M.One() ) , m_b( m_N_d , m_M.One() ) , m_lazy_substitution( m_N_d , m_M.One() ) , m_suspended( m_N_d ) { static_assert( ! is_same_v<U,int> && is_same_v<U,inner_t<NON_COMM_N_MODULE>> ); }
template <typename U , typename NON_COMM_N_MODULE> template <typename...Args> inline IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE>::IntervalSetSqrtDecomposition( NON_COMM_N_MODULE M , vector<U> a , const Args&... args ) : SqrtDecompositionCoordinate( a.size() , args... ) , m_M( move( M ) ) , m_a( move( a ) ) , m_b( m_N_d , m_M.One() ) , m_lazy_substitution( m_N_d , m_M.One() ) , m_suspended( m_N_d )
{

  static_assert( ! is_same_v<U,int> && is_same_v<U,inner_t<NON_COMM_N_MODULE>> );
  m_a.resize( m_N_m , m_M.One() );
  int i_min = 0;
  int i_ulim = m_N_sqrt;

  for( int d = 0 ; d < m_N_d ; d++ ){

    U& m_bd = m_b[d];
  
    for( int i = i_min ; i < i_ulim ; i++ ){

      m_bd = m_M.Product( move( m_bd ) , m_a[i] );

    }
    
    i_min = i_ulim;
    i_ulim += m_N_sqrt;

  }

}

template <typename U , typename NON_COMM_N_MODULE> template <typename...Args> inline void IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE>::Initialise( Args&&... args ) { IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE> temp{ m_M , forward<Args>( args )... }; SqrtDecompositionCoordinate::operator=( temp ); m_a = move( temp.m_a ); m_b = move( temp.m_b ); m_lazy_substitution = vector( m_N_d , m_M.One() ); m_suspended = vector( m_N_d , false ); }

template <typename U , typename NON_COMM_N_MODULE> inline void IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE>::Set( const int& i , const U& u ) { IntervalSet( i , i , u ); }

template <typename U , typename NON_COMM_N_MODULE> inline void IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE>::IntervalSet( const int& i_start , const int& i_final , const U& u )
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , m_N );
  const int d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;
  const int d_1 = max( d_0 , i_ulim / m_N_sqrt );
  const int d_0_N_sqrt = d_0 * m_N_sqrt;
  const int d_1_N_sqrt = d_1 * m_N_sqrt;
  const int i_0 = min( d_0_N_sqrt , i_ulim );
  const int i_1 = max( i_0 , d_1_N_sqrt );

  if( i_min < i_0 ){
    
    // この時d_0 > 0になる。
    const int d_0_minus = d_0 - 1;
    const int d_0_N_sqrt_minus = d_0_N_sqrt - m_N_sqrt;
    U& m_bd = m_b[d_0_minus];
    vector<bool>::reference m_suspended_d = m_suspended[d_0_minus];

    if( m_suspended_d ){

      U& m_lazy_substitution_d = m_lazy_substitution[d_0_minus];
      IntervalSet_Body( d_0_N_sqrt_minus , i_min , m_lazy_substitution_d );
      IntervalSet_Body( i_min , i_0 , u );
      IntervalSet_Body( i_0 , d_0_N_sqrt , m_lazy_substitution_d );
      m_suspended_d = false;
      // 非可換N加群性を使った。
      m_bd = m_M.Product( m_M.Power( m_lazy_substitution_d , m_N_sqrt - ( i_0 - i_min ) ) , m_M.Power( u , i_0 - i_min ) );

    } else {

      IntervalSet_Body( i_min , i_0 , u );
      m_bd = m_M.Product( m_M.Product( IntervalProduct_Body( d_0_N_sqrt_minus , i_min ) , m_M.Power( u , i_0 - i_min ) ) , IntervalProduct_Body( i_0 , d_0_N_sqrt ) );
      
    }

  }
  
  const U power = m_M.Power( u , m_N_sqrt );
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    m_b[d] = power;
    m_lazy_substitution[d] = u;
    m_suspended[d] = true;

  }

  if( i_1 < i_ulim ){
      
    // この時d_1 < m_N_dになる。
    const int d_1_N_sqrt_plus = d_1_N_sqrt + m_N_sqrt;
    U& m_bd = m_b[d_1];
    vector<bool>::reference m_suspended_d = m_suspended[d_1];

    if( m_suspended_d ){

      U& m_lazy_substitution_d = m_lazy_substitution[d_1];
      IntervalSet_Body( d_1_N_sqrt , i_1 , m_lazy_substitution_d );
      IntervalSet_Body( i_1 , i_ulim , u );
      IntervalSet_Body( i_ulim , d_1_N_sqrt_plus , m_lazy_substitution_d );
      m_suspended_d = false;
      m_bd = m_M.Product( m_M.Product( m_M.Power( m_lazy_substitution_d , i_1 - d_1_N_sqrt ) , m_M.Power( u , i_ulim - i_1 ) ) , m_M.Power( m_lazy_substitution_d , d_1_N_sqrt_plus - i_ulim ) );

    } else {

      IntervalSet_Body( i_1 , i_ulim , u );
      m_bd = m_M.Product( m_M.Product( IntervalProduct_Body( d_1_N_sqrt , i_1 ) , m_M.Power( u , i_ulim - i_1 ) ) , IntervalProduct_Body( i_ulim , d_1_N_sqrt_plus ) );
      
    }
    
  }
  
  return;
  
}

template <typename U , typename NON_COMM_N_MODULE> inline void IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE>::IntervalSet_Body( const int& i_min , const int& i_ulim , const U& u )
{

  for( int i = i_min ; i < i_ulim ; i++ ){

    m_a[i] = u;

  }

  return;
  
}

template <typename U , typename NON_COMM_N_MODULE> inline U IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE>::operator[]( const int& i ) { assert( 0 <= i && i < m_N ); const int d = i / m_N_sqrt; return m_suspended[d] ? m_lazy_substitution[d] : m_a[i]; }
template <typename U , typename NON_COMM_N_MODULE> inline U IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE>::Get( const int& i ) { return operator[]( i ); }

template <typename U , typename NON_COMM_N_MODULE> inline U IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE>::IntervalProduct( const int& i_start , const int& i_final )
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , m_N );
  const int d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;
  const int d_1 = max( d_0 , i_ulim / m_N_sqrt );
  const int i_0 = min( d_0 * m_N_sqrt , i_ulim );
  const int i_1 = max( i_0 , d_1 * m_N_sqrt );
  
  U answer = m_M.One();

  if( i_min < i_0 ){

    // この時d_0 > 0になる。
    // 非可換N加群性を使った。
    const int d_0_minus = d_0 - 1;
    answer = m_suspended[d_0_minus] ? m_M.Power( m_lazy_substitution[d_0_minus] , i_0 - i_min ) : IntervalProduct_Body( i_min , i_0 );
    
  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    answer = m_M.Product( move( answer ) , m_b[d] );

  }

  if( i_1 < i_ulim ){

    // この時d_1 < m_N_dになる。
    // 非可換N加群性を使った。
    answer = m_M.Product( move( answer ) , m_suspended[d_1] ? m_M.Power( m_lazy_substitution[d_1] , i_ulim - i_1 ) : IntervalProduct_Body( i_1 , i_ulim ) );

  }

  return answer;
  
}

template <typename U , typename NON_COMM_N_MODULE> inline U IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE>::IntervalProduct_Body( const int& i_min , const int& i_ulim )
{

  U answer = m_M.One();
  
  for( int i = i_min ; i < i_ulim ; i++ ){

    answer = m_M.Product( move( answer ) , m_a[i] );

  }

  return answer;
    
}

template <typename U , typename NON_COMM_N_MODULE> template <typename F , SFINAE_FOR_SD_S> inline int IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE>::Search( const int& i_start , const F& f , const bool& reversed ) { return reversed ? SearchReverse_Body( i_start , f , m_M.One() ) : Search_Body( i_start , f , m_M.One() ); }
template <typename U , typename NON_COMM_N_MODULE> inline int IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE>::Search( const int& i_start , const U& u , const bool& reversed ) { return Search( i_start , [&]( const U& product , const int& ){ return !( product < u ); } , reversed ); }

template <typename U , typename NON_COMM_N_MODULE> template <typename F> int IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE>::Search_Body( const int& i_start , const F& f , U product_temp )
{

  const int i_min = max( i_start , 0 );
  const int d_0 = i_min / m_N_sqrt + 1;
  const int i_0 = min( d_0 * m_N_sqrt , m_N );

  if( i_min < i_0 ){

    // この時d_0 > 0になる。
    const int d_0_minus = d_0 - 1;

    if( m_suspended[d_0_minus] ){

      const U& m_lazy_substitution_d = m_lazy_substitution[d_0_minus];
      U product_next = m_M.Product( product_temp , m_lazy_substitution_d );
      
      if( f( product_next , i_min ) ){

	return i_min;

      }

      int l = i_min , r = i_0;

      while( l + 1 < r ){

	int m = ( l + r ) >> 1;
	// 非可換N加群性を使った。
	product_next = m_M.Product( product_temp , m_M.Power( m_lazy_substitution_d , m - i_min + 1 ) );

	( f( product_next , m ) ? r : l ) = m;

      }

      if( r < i_0 ){ 

	return r;

      }

      product_temp = move( product_next );

    } else {

      for( int i = i_min ; i < i_0 ; i++ ){

	product_temp = m_M.Product( move( product_temp ) , m_a[i] );

	if( f( product_temp , i ) ){

	  return i;

	}

      }

    }

  }

  int N_sqrt_d = m_N_sqrt * d_0;
  
  for( int d = d_0 ; d < m_N_d ; d++ , N_sqrt_d += m_N_sqrt ){

    const int j_rest = d + 1 < m_N_d ? m_N_sqrt : m_N - N_sqrt_d;
    U product_next = m_M.Product( product_temp , m_suspended[d] ? m_M.Power( m_lazy_substitution[d] , j_rest ) : m_b[d] );

    if( f( product_next , N_sqrt_d + j_rest - 1 ) ){

      return Search_Body( N_sqrt_d , f , move( product_temp ) );

    }

    product_temp = move( product_next );
    
  }

  return -1;

}

template <typename U , typename NON_COMM_N_MODULE> template <typename F> int IntervalSetSqrtDecomposition<U,NON_COMM_N_MODULE>::SearchReverse_Body( const int& i_final , const F& f , U product_temp )
{

  const int i_max = min( i_final , m_N - 1 );
  const int d_1 = i_max / m_N_sqrt;
  const int i_1 = max( d_1 * m_N_sqrt , 0 );

  if( m_suspended[d_1] ){

    const U& m_lazy_substitution_d = m_lazy_substitution[d_1];
    U product_next = m_M.Product( product_temp , m_lazy_substitution_d );
      
    if( f( product_next , i_max ) ){

      return i_max;

    }

    int l = i_1 , r = i_max;

    while( l + 1 < r ){

      int m = ( l + r ) >> 1;
      // 非可換N加群性を使った。
      product_next = m_M.Product( m_M.Power( m_lazy_substitution_d , i_max - m + 1 ) , product_temp );

      ( f( product_next , m ) ? l : r ) = m;

    }

    if( i_1 < l ){

      return l;

    }

    product_temp = move( product_next );

  } else {

    for( int i = i_max ; i >= i_1 ; i-- ){

      product_temp = m_M.Product( m_a[i] , product_temp );

      if( f( product_temp , i ) ){

        return i;

      }

    }

  }
  
  for( int d = d_1 - 1 ; d >= 0 ; d-- ){

    U product_next = m_M.Product( m_suspended[d] ? m_M.Power( m_lazy_substitution[d] , m_N_sqrt ) : m_b[d] , product_temp );

    if( f( product_next , d * m_N_sqrt ) ){

      return Search_Body( ( d + 1 ) * m_N_sqrt - 1 , f , move( product_temp ) );

    }

    product_temp = move( product_next );
    
  }

  return -1;

}
