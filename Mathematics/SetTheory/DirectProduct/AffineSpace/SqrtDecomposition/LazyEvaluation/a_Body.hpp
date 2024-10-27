// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/LazyEvaluation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Sqrt/a_Body.hpp"

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> template <typename...Args> inline LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::LazySqrtDecomposition( PT_MAGMA L , RN_BIMODULE M , const int& N , const Args&... args ) : SqrtDecompositionCoordinate( N , args... ) , m_L( move( L ) ) , m_M( move( M ) ) , m_a( N , m_M.One() ) , m_b( m_N_d , m_M.One() ) , m_lazy_substitution( m_b ) , m_suspended( m_N_d ) , m_lazy_action( m_N_d , m_L.Point() ) { Construct(); }
template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> template <typename...Args> inline LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::LazySqrtDecomposition( PT_MAGMA L , RN_BIMODULE M , vector<U> a , const Args&... args ) : SqrtDecompositionCoordinate( a.size() , args... ) , m_L( move( L ) ) , m_M( move( M ) ) , m_a( move( a ) ) , m_b( m_N_d , m_M.One() ) , m_lazy_substitution( m_b ) , m_suspended( m_N_d ) , m_lazy_action( m_N_d , m_L.Point() ) { Construct(); }

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> inline void LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::Construct()
{

  static_assert( is_same_v<R,inner_t<PT_MAGMA>> && is_same_v<U,inner_t<RN_BIMODULE>> );
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

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> template <typename...Args> inline void LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::Initialise( Args&&...args ) { LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE> temp{ m_L , m_M , forward<Args>( args )... }; SqrtDecompositionCoordinate::operator=( temp ); m_a = move( temp.m_a ); m_b = move( temp.m_b ); m_lazy_substitution = move( temp.m_lazy_substitution ); m_suspended = move( temp.m_suspended ); m_lazy_action = move( temp.m_lazy_action ); }

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> inline void LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::Set( const int& i , const U& u )
{

  const int d = i / m_N_sqrt;
  const int i_min = d * m_N_sqrt;
  const int i_ulim = i_min + m_N_sqrt;
  U& m_ai = m_a[i];

  if( m_suspended[d] ){

    U& m_lazy_substitution_d = m_lazy_substitution[d];

    if( m_lazy_substitution_d != u ){

      SolveSuspendedSubstitution( d , m_lazy_substitution_d );
      m_ai = u;
      m_b[d] = m_M.Product( m_M.Product( m_M.Power( m_lazy_substitution_d , i - i_min ) , u ) , m_M.Power( m_lazy_substitution_d , i_ulim - ( i + 1 ) ) );

    }
      
  } else {

    SolveSuspendedAction( d );

    if( m_ai != u ){

      m_ai = u;
      SetProduct( d );

    }

  }
  
  return;

}

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> inline void LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::IntervalSet( const int& i_start , const int& i_final , const U& u )
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
      m_bd = m_M.Product( m_M.Product( m_M.Power( m_lazy_substitution_d , i_min - d_0_N_sqrt_minus ) , m_M.Power( u , i_0 - i_min ) ) , m_M.Power( m_lazy_substitution_d , d_0_N_sqrt - i_0 ) );

    } else {

      SolveSuspendedAction( d_0_minus );
      IntervalSet_Body( i_min , i_0 , u );
      m_bd = m_M.Product( m_M.Product( IntervalProduct_Body( d_0_N_sqrt_minus , i_min ) , m_M.Power( u , i_0 - i_min ) ) , IntervalProduct_Body( i_0 , d_0_N_sqrt ) );
      
    }
    
  }

  const U power = m_M.Power( u , m_N_sqrt );
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    m_b[d] = power;
    m_lazy_substitution[d] = u;
    m_suspended[d] = true;
    m_lazy_action[d] = m_L.Point();

  }

  if( i_1 < i_ulim ){
      
    // この時d_1 < m_N_dになる。
    const int d_1_N_sqrt_plus = d_1_N_sqrt + m_N_sqrt;
    U& m_bd = m_b[d_1];
    vector<bool>::reference m_suspended_d = m_suspended[d_1];

    if( m_suspended_d ){

      const U& m_lazy_substitution_d = m_lazy_substitution[d_1];
      IntervalSet_Body( d_1_N_sqrt , i_1 , m_lazy_substitution_d );
      IntervalSet_Body( i_1 , i_ulim , u );
      IntervalSet_Body( i_ulim , d_1_N_sqrt_plus , m_lazy_substitution_d );
      m_suspended_d = false;
      m_bd = m_M.Product( m_M.Product( m_M.Power( m_lazy_substitution_d , i_1 - d_1_N_sqrt ) , m_M.Power( u , i_ulim - i_1 ) ) , m_M.Power( m_lazy_substitution_d , d_1_N_sqrt_plus - i_ulim ) );

    } else {

      SolveSuspendedAction( d_1 );
      IntervalSet_Body( i_1 , i_ulim , u );
      m_bd = m_M.Product( m_M.Product( IntervalProduct_Body( d_1_N_sqrt , i_1 ) , m_M.Power( u , i_ulim - i_1 ) ) , IntervalProduct_Body( i_ulim , d_1_N_sqrt_plus ) );
      
    }
    
  }
  
  return;

}

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> inline void LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::IntervalAct( const int& i_start , const int& i_final , const R& r )
{

  if( r != m_L.Point() ){
  
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
      vector<bool>::reference m_suspended_d = m_suspended[d_0_minus];

      if( m_suspended_d ){

	const U& m_lazy_substitution_d = m_lazy_substitution[d_0_minus];
	U& m_bd = m_b[d_0_minus];
	const U u = m_M.ScalarProduct( r , m_lazy_substitution_d );
	IntervalSet_Body( d_0_N_sqrt_minus , i_min , m_lazy_substitution_d );
	IntervalSet_Body( i_min , i_0 , u );
	IntervalSet_Body( i_0 , d_0_N_sqrt , m_lazy_substitution_d );
	m_suspended_d = false;
	m_bd = m_M.Product( m_M.Product( m_M.Power( m_lazy_substitution_d , i_min - d_0_N_sqrt_minus ) , m_M.Power( u , i_0 - i_min ) ) , m_M.Power( m_lazy_substitution_d , d_0_N_sqrt - i_0 ) );

      } else {

	R& m_lazy_action_d = m_lazy_action[d_0_minus];

	if( m_lazy_action_d == m_L.Point() ){

	  IntervalAct_Body( i_min , i_0 , r );

	} else {
	  
	  IntervalAct_Body( d_0_N_sqrt_minus , i_min , m_lazy_action_d );
	  IntervalAct_Body( i_min , i_0 , m_L.Product( r , m_lazy_action_d ) );
	  IntervalAct_Body( i_0 , d_0_N_sqrt , m_lazy_action_d );
	  m_lazy_action_d = m_L.Point();

	}

	SetProduct( d_0_minus );
      
      }

    }
  
    for( int d = d_0 ; d < d_1 ; d++ ){

      U& m_bd = m_b[d];
      m_bd = m_M.ScalarProduct( r , m_bd );

      if( m_suspended[d] ){

	U& m_lazy_substitution_d = m_lazy_substitution[d];
	m_lazy_substitution_d = m_M.ScalarProduct( r , m_lazy_substitution_d );

      } else {
      
	R& m_lazy_action_d = m_lazy_action[d];
	m_lazy_action_d = m_L.Product( r , m_lazy_action_d );

      }

    }

    if( i_1 < i_ulim ){
      
      // この時d_1 < m_N_dになる。
      const int d_1_N_sqrt_plus = d_1_N_sqrt + m_N_sqrt;
      vector<bool>::reference m_suspended_d = m_suspended[d_1];

      if( m_suspended_d ){

	const U& m_lazy_substitution_d = m_lazy_substitution[d_1];
	U& m_bd = m_b[d_1];
	const U u = m_M.ScalarProduct( r , m_lazy_substitution_d );
	IntervalSet_Body( d_1_N_sqrt , i_1 , m_lazy_substitution_d );
	IntervalSet_Body( i_1 , i_ulim , u );
	IntervalSet_Body( i_ulim , d_1_N_sqrt_plus , m_lazy_substitution_d );
	m_suspended_d = false;
	m_bd = m_M.Product( m_M.Product( m_M.Power( m_lazy_substitution_d , i_1 - d_1_N_sqrt ) , m_M.Power( u , i_ulim - i_1 ) ) , m_M.Power( m_lazy_substitution_d , d_1_N_sqrt_plus - i_ulim ) );

      } else {

	R& m_lazy_action_d = m_lazy_action[d_1];

	if( m_lazy_action_d == m_L.Point() ){

	  IntervalAct_Body( i_1 , i_ulim , r );
	  SetProduct( d_1 );

	} else {
	  
	  IntervalAct_Body( d_1_N_sqrt , i_1 , m_lazy_action_d );
	  IntervalAct_Body( i_1 , i_ulim , m_L.Product( r , m_lazy_action_d ) );
	  IntervalAct_Body( i_ulim , d_1_N_sqrt_plus , m_lazy_action_d );
	  m_lazy_action_d = m_L.Point();
	  SetProduct( d_1 );

	}
      
      }

    }

  }
  
  return;
  
}

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> inline U LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::IntervalProduct_Body( const int& i_min , const int& i_ulim )
{

  U answer = m_M.One();
  
  for( int i = i_min ; i < i_ulim ; i++ ){

    answer = m_M.Product( move( answer ) , m_a[i] );

  }

  return answer;
  
}

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> inline void LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::SetProduct( const int& d )
{

  U& m_bd = m_b[d] = m_M.One();
  const int i_min = d * m_N_sqrt;
  const int i_ulim = i_min + m_N_sqrt;

  for( int i = i_min ; i < i_ulim ; i++ ){

    m_bd = m_M.Product( move( m_bd ) , m_a[i] );

  }

  return;

}

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> inline void LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::SolveSuspendedSubstitution( const int& d , const U& u )
{

  const int i_min = d * m_N_sqrt;
  IntervalSet_Body( i_min , i_min + m_N_sqrt , u );
  m_suspended[d] = false;
  return;

}

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> inline void LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::IntervalSet_Body( const int& i_min , const int& i_ulim , const U& u )
{

  for( int i = i_min ; i < i_ulim ; i++ ){

    m_a[i] = u;

  }

  return;
  
}

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> inline void LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::SolveSuspendedAction( const int& d )
{

  R& m_lazy_action_d = m_lazy_action[d];

  if( m_lazy_action_d != m_L.Point() ){

    const int i_min = d * m_N_sqrt;
    const int i_ulim = i_min + m_N_sqrt;
    IntervalAct_Body( i_min , i_ulim , m_lazy_action_d );
    U& m_bd = m_b[d];
    m_bd = m_M.ScalarProduct( m_lazy_action_d , m_bd );
    m_lazy_action_d = m_L.Point();
 
  }

  return;
  
}

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> inline U LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::operator[]( const int& i ) { assert( 0 <= i && i < m_N ); const int d = i / m_N_sqrt; return m_suspended[d] ? m_lazy_substitution[d] : m_M.ScalarProduct( m_lazy_action[d] , m_a[i] ); }
template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> inline U LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::Get( const int& i ) { return operator[]( i ); }

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> inline U LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::IntervalProduct( const int& i_start , const int& i_final )
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , m_N );
  const int d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;
  const int d_1 = max( d_0 , i_ulim / m_N_sqrt );
  const int i_0 = min( d_0 * m_N_sqrt , i_ulim ) ;
  const int i_1 = max( i_0 , d_1 * m_N_sqrt );
  
  U answer = m_M.One();

  if( i_min < i_0 ){

    // この時d_0 > 0になる。
    const int d_0_minus = d_0 - 1;
    answer = m_suspended[d_0_minus] ? m_M.Power( m_lazy_substitution[d_0_minus] , i_0 - i_min ) : m_M.ScalarProduct( m_lazy_action[d_0_minus] , IntervalProduct_Body( i_min , i_0 ) );
    
  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    answer = m_M.Product( move( answer ) , m_b[d] );

  }

  if( i_1 < i_ulim ){

    // この時d_1 < m_N_dになる。
    answer = m_M.Product( move( answer ), m_suspended[d_1] ? m_M.Power( m_lazy_substitution[d_1] , i_ulim - i_1 ) : m_M.ScalarProduct( m_lazy_action[d_1] , IntervalProduct_Body( i_1 , i_ulim ) ) );

  }

  return answer;

}

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> inline void LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::IntervalAct_Body( const int& i_min , const int& i_ulim , const R& r )
{

  for( int i = i_min ; i < i_ulim ; i++ ){

    U& m_ai = m_a[i];
    m_ai = m_M.ScalarProduct( r , m_ai );

  }

  return;
  
}

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> template <typename F , SFINAE_FOR_SD_S> inline int LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::Search( const int& i_start , const F& f , const bool& reversed ) { return reversed ? SearchReverse_Body( i_start , f , m_M.One() ) : Search_Body( i_start , f , m_M.One() ); }
template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> inline int LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::Search( const int& i_start , const U& u , const bool& reversed ) { return Search( i_start , [&]( const U& product , const int& ){ return !( product < u ); } , reversed ); }

template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> template <typename F> int LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::Search_Body( const int& i_start , const F& f , U product_temp )
{

  const int i_min = max( i_start , 0 );
  // d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;とすると再帰が無限ループする。
  const int d_0 = i_min / m_N_sqrt + 1;
  const int i_0 = min( d_0 * m_N_sqrt , m_N );

  if( i_min < i_0 ){

    // この時d_0 > 0になる。
    const int d_0_minus = d_0 - 1;

    if( m_suspended[d_0_minus] ){
      
      SolveSuspendedSubstitution( d_0_minus , m_lazy_substitution[d_0_minus] );

    } else {

      SolveSuspendedAction( d_0_minus );

    }
    
  }
  
  for( int i = i_min ; i < i_0 ; i++ ){

    product_temp = m_M.Product( move( product_temp ) , m_a[i] );

    if( f( product_temp , i ) ){

      return i;

    }

  }
  
  for( int d = d_0 ; d < m_N_d ; d++ ){

    U product_next = m_M.Product( product_temp , m_b[d] );

    if( f( product_next , min( ( d + 1 ) * m_N_sqrt , m_N ) - 1 ) ){

      return Search_Body( d * m_N_sqrt , f , move( product_temp ) );

    }

    product_temp = move( product_next );
    
  }

  return -1;

}


template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE> template <typename F> int LazySqrtDecomposition<R,PT_MAGMA,U,RN_BIMODULE>::SearchReverse_Body( const int& i_final , const F& f , U product_temp )
{

  const int i_max = min( i_final , m_N - 1 );
  const int d_1 = i_max / m_N_sqrt;
  const int i_1 = max( d_1 * m_N_sqrt , 0 );

  if( m_suspended[d_1] ){

    SolveSuspendedSubstitution( d_1 , m_lazy_substitution[d_1] );

  } else {

    SolveSuspendedAction( d_1 );

  }
  
  for( int i = i_max ; i >= i_1 ; i-- ){

    product_temp = m_M.Product( m_a[i] , product_temp );

    if( f( product_temp , i ) ){

      return i;

    }

  }
  
  for( int d = d_1 - 1 ; d >= 0 ; d-- ){

    U product_next = m_M.Product( m_b[d] , product_temp );

    if( f( product_next , d * m_N_sqrt ) ){

      return Search_Body( ( d + 1 ) * m_N_sqrt - 1 , f , move( product_temp ) );

    }

    product_temp = move( product_next );
    
  }

  return -1;

}

#include "../../../../../Algebra/Monoid/Group/Module/BiModule/a_Body.hpp"
