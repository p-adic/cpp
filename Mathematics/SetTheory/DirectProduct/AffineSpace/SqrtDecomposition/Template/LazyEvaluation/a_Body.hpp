// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/LazyEvaluation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Sqrt/a_Body.hpp"

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> const T& LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::g_e_T = e_T();
template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> const U& LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::g_e_U = e_U();

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::LazySqrtDecomposition()
: m_a() , m_b() , m_lazy_substitution() , m_suspended() , m_lazy_action()
{

  if( m_a[0] != g_e_U ){

    for( int d = 0 ; d < N_d ; d++ ){

      m_b[d] = m_lazy_substitution[d] = g_e_U;
      m_suspended[d] = true;

    }

  }

  if( m_lazy_action[0] != g_e_T ){

    for( int d = 0 ; d < N_d ; d++ ){

      m_lazy_action[d] = g_e_T;

    }

  }

}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::LazySqrtDecomposition( const U ( &a )[N] )
: m_a() , m_b() , m_lazy_substitution() , m_suspended() , m_lazy_action()
{

  int i = 0;

  while( i < N ){
    
    m_a[i] = a[i];
    i++;
  }

  while( i < N_m ){

    m_a[i] = g_e_U;
    i++;

  }

  i = 0;
  
  for( int d = 0 ; d < N_d ; d++ ){

    U& m_bd = m_b[d] = g_e_U;

    for( int j = 0 ; j < N_sqrt ; j++ ){

      m_bd = m_U( m_bd , m_a[i] );
      i++;

    }

  }

  if( m_lazy_action[0] != g_e_T ){

    for( int d = 0 ; d < N_d ; d++ ){

      m_lazy_action[d] = g_e_T;

    }

  }

}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr U LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::Get( const int& i ) const { const int d = i / N_sqrt; return m_suspended[d] ? m_lazy_substitution[d] : o_U( m_lazy_action[d] , m_a[i] ); }

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr U LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::IntervalProd( const int& i_start , const int& i_final ) const
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , N );
  const int d_0 = ( i_min + N_sqrt - 1 ) / N_sqrt;
  const int d_1 = max( d_0 , i_ulim / N_sqrt );
  const int i_0 = min( d_0 * N_sqrt , i_ulim ) ;
  const int i_1 = max( i_0 , d_1 * N_sqrt );
  
  U answer = g_e_U;

  if( i_min < i_0 ){

    // この時d_0 > 0になる。
    const int d_0_minus = d_0 - 1;
    answer = m_suspended[d_0_minus] ? Power( m_lazy_substitution[d_0_minus] , i_0 - i_min ) : o_U( m_lazy_action[d_0_minus] , IntervalProd_Body( i_min , i_0 ) );
    
  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    answer = m_U( answer , m_b[d] );

  }

  if( i_1 < i_ulim ){

    // この時d_1 < N_dになる。
    answer = m_U( answer , m_suspended[d_1] ? Power( m_lazy_substitution[d_1] , i_ulim - i_1 ) : o_U( m_lazy_action[d_1] , IntervalProd_Body( i_1 , i_ulim ) ) );

  }

  return answer;

}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::Set( const int& i , const U& u )
{

  const int d = i / N_sqrt;
  const int i_min = d * N_sqrt;
  const int i_ulim = i_min + N_sqrt;
  U& m_ai = m_a[i];

  if( m_suspended[d] ){

    U& m_lazy_substitution_d = m_lazy_substitution[d];

    if( m_lazy_substitution_d != u ){

      SolveSuspendedSubstitution( d , m_lazy_substitution_d );
      m_ai = u;
      m_b[d] = m_U( m_U( Power( m_lazy_substitution_d , i - i_min ) , u ) , Power( m_lazy_substitution_d , i_ulim - ( i + 1 ) ) );

    }
      
  } else {

    SolveSuspendedAction( d );

    if( m_ai != u ){

      m_ai = u;
      SetProd( d );

    }

  }
  
  return;

}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::IntervalSet( const int& i_start , const int& i_final , const U& u )
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , N );
  const int d_0 = ( i_min + N_sqrt - 1 ) / N_sqrt;
  const int d_1 = max( d_0 , i_ulim / N_sqrt );
  const int d_0_N_sqrt = d_0 * N_sqrt;
  const int d_1_N_sqrt = d_1 * N_sqrt;
  const int i_0 = min( d_0_N_sqrt , i_ulim );
  const int i_1 = max( i_0 , d_1_N_sqrt );

  if( i_min < i_0 ){

    // この時d_0 > 0になる。
    const int d_0_minus = d_0 - 1;
    const int d_0_N_sqrt_minus = d_0_N_sqrt - N_sqrt;
    U& m_bd = m_b[d_0_minus];
    bool& m_suspended_d = m_suspended[d_0_minus];

    if( m_suspended_d ){

      U& m_lazy_substitution_d = m_lazy_substitution[d_0_minus];
      IntervalSet_Body( d_0_N_sqrt_minus , i_min , m_lazy_substitution_d );
      IntervalSet_Body( i_min , i_0 , u );
      IntervalSet_Body( i_0 , d_0_N_sqrt , m_lazy_substitution_d );
      m_suspended_d = false;
      m_bd = m_U( m_U( Power( m_lazy_substitution_d , i_min - d_0_N_sqrt_minus ) , Power( u , i_0 - i_min ) ) , Power( m_lazy_substitution_d , d_0_N_sqrt - i_0 ) );

    } else {

      SolveSuspendedAction( d_0_minus );
      IntervalSet_Body( i_min , i_0 , u );
      m_bd = m_U( m_U( IntervalProd_Body( d_0_N_sqrt_minus , i_min ) , Power( u , i_0 - i_min ) ) , IntervalProd_Body( i_0 , d_0_N_sqrt ) );
      
    }
    
  }

  const U power = Power( u , N_sqrt );
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    m_b[d] = power;
    m_lazy_substitution[d] = u;
    m_suspended[d] = true;
    m_lazy_action[d] = g_e_T;

  }

  if( i_1 < i_ulim ){
      
    // この時d_1 < N_dになる。
    const int d_1_N_sqrt_plus = d_1_N_sqrt + N_sqrt;
    U& m_bd = m_b[d_1];
    bool& m_suspended_d = m_suspended[d_1];

    if( m_suspended_d ){

      U& m_lazy_substitution_d = m_lazy_substitution[d_1];
      IntervalSet_Body( d_1_N_sqrt , i_1 , m_lazy_substitution_d );
      IntervalSet_Body( i_1 , i_ulim , u );
      IntervalSet_Body( i_ulim , d_1_N_sqrt_plus , m_lazy_substitution_d );
      m_suspended_d = false;
      m_bd = m_U( m_U( Power( m_lazy_substitution_d , i_1 - d_1_N_sqrt ) , Power( u , i_ulim - i_1 ) ) , Power( m_lazy_substitution_d , d_1_N_sqrt_plus - i_ulim ) );

    } else {

      SolveSuspendedAction( d_1 );
      IntervalSet_Body( i_1 , i_ulim , u );
      m_bd = m_U( m_U( IntervalProd_Body( d_1_N_sqrt , i_1 ) , Power( u , i_ulim - i_1 ) ) , IntervalProd_Body( i_ulim , d_1_N_sqrt_plus ) );
      
    }
    
  }
  
  return;

}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::IntervalAct( const int& i_start , const int& i_final , const T& t )
{

  if( t != g_e_T ){
  
    const int i_min = max( i_start , 0 );
    const int i_ulim = min( i_final + 1 , N );
    const int d_0 = ( i_min + N_sqrt - 1 ) / N_sqrt;
    const int d_1 = max( d_0 , i_ulim / N_sqrt );
    const int d_0_N_sqrt = d_0 * N_sqrt;
    const int d_1_N_sqrt = d_1 * N_sqrt;
    const int i_0 = min( d_0_N_sqrt , i_ulim );
    const int i_1 = max( i_0 , d_1_N_sqrt );

    if( i_min < i_0 ){

      // この時d_0 > 0になる。
      const int d_0_minus = d_0 - 1;
      const int d_0_N_sqrt_minus = d_0_N_sqrt - N_sqrt;
      bool& m_suspended_d = m_suspended[d_0_minus];

      if( m_suspended_d ){

	U& m_lazy_substitution_d = m_lazy_substitution[d_0_minus];
	U& m_bd = m_b[d_0_minus];
	const U u = o_U( t , m_lazy_substitution_d );
	IntervalSet_Body( d_0_N_sqrt_minus , i_min , m_lazy_substitution_d );
	IntervalSet_Body( i_min , i_0 , u );
	IntervalSet_Body( i_0 , d_0_N_sqrt , m_lazy_substitution_d );
	m_suspended = false;
	m_bd = m_U( m_U( Power( m_lazy_substitution_d , i_min - d_0_N_sqrt_minus ) , Power( u , i_0 - i_min ) ) , Power( m_lazy_substitution , d_0_N_sqrt - i_0 ) );

      } else {

	T& m_lazy_action_d = m_lazy_action[d_0_minus];

	if( m_lazy_action_d == g_e_T ){

	  IntervalAct_Body( i_min , i_0 , t );

	} else {
	  
	  IntervalAct_Body( d_0_N_sqrt_minus , i_min , m_lazy_action_d );
	  IntervalAct_Body( i_min , i_0 , m_T( t , m_lazy_action_d ) );
	  IntervalAct_Body( i_0 , d_0_N_sqrt , m_lazy_action_d );
	  m_lazy_action_d = g_e_T;

	}

	SetProd( d_0_minus );
      
      }

    }
  
    for( int d = d_0 ; d < d_1 ; d++ ){

      U& m_bd = m_b[d];
      m_bd = o_U( t , m_bd );

      if( m_suspended[d] ){

	U& m_lazy_substitution_d = m_lazy_substitution[d];
	m_lazy_substitution_d = o_U( t , m_lazy_substitution_d );

      } else {
      
	T& m_lazy_action_d = m_lazy_action[d];
	m_lazy_action_d = m_T( t , m_lazy_action_d );

      }

    }

    if( i_1 < i_ulim ){
      
      // この時d_1 < N_dになる。
      const int d_1_N_sqrt_plus = d_1_N_sqrt + N_sqrt;
      bool& m_suspended_d = m_suspended[d_1];

      if( m_suspended_d ){

	U& m_lazy_substitution_d = m_lazy_substitution[d_1];
	U& m_bd = m_b[d_1];
	const U u = o_U( t , m_lazy_substitution_d );
	IntervalSet_Body( d_1_N_sqrt , i_1 , m_lazy_substitution_d );
	IntervalSet_Body( i_1 , i_ulim , u );
	IntervalSet_Body( i_ulim , d_1_N_sqrt_plus , m_lazy_substitution_d );
	m_suspended = false;
	m_bd = m_U( m_U( Power( m_lazy_substitution_d , i_1 - d_1_N_sqrt ) , Power( u , i_ulim - i_1 ) ) , Power( m_lazy_substitution , d_1_N_sqrt_plus - i_ulim ) );

      } else {

	T& m_lazy_action_d = m_lazy_action[d_1];

	if( m_lazy_action_d == g_e_T ){

	  IntervalAct_Body( i_1 , i_ulim , t );
	  SetProd( d_1 );

	} else {
	  
	  IntervalAct_Body( d_1_N_sqrt , i_1 , m_lazy_action_d );
	  IntervalAct_Body( i_1 , i_ulim , m_T( t , m_lazy_action_d ) );
	  IntervalAct_Body( i_ulim , d_1_N_sqrt_plus , m_lazy_action_d );
	  m_lazy_action_d = g_e_T;
	  SetProd( d_1 );

	}
      
      }

    }

  }
  
  return;
  
}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr U LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::Power( const U& u , int exponent )
{

  U answer = g_e_U;

  if( u != g_e_U ){

    U power = u;

    while( exponent > 0 ){

      answer = ( exponent & 1 ) == 0 ? answer : m_U( answer , power );
      power = m_U( power , power );
      exponent >>= 1;

    }

  }

  return answer;

}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr U LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::IntervalProd_Body( const int& i_min , const int& i_ulim ) const
{

  U answer = g_e_U;
  
  for( int i = i_min ; i < i_ulim ; i++ ){

    answer = m_U( answer , m_a[i] );

  }

  return answer;
  
}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::SetProd( const int& d )
{

  U& m_bd = m_b[d] = g_e_U;
  const int i_min = d * N_sqrt;
  const int i_ulim = i_min + N_sqrt;

  for( int i = i_min ; i < i_ulim ; i++ ){

    m_bd = m_U( m_bd , m_a[i] );

  }

  return;

}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::SolveSuspendedSubstitution( const int& d , const U& u )
{

  const int i_min = d * N_sqrt;
  IntervalSet_Body( i_min , i_min + N_sqrt , u );
  m_suspended[d] = false;
  return;

}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::IntervalSet_Body( const int& i_min , const int& i_ulim , const U& u )
{

  for( int i = i_min ; i < i_ulim ; i++ ){

    m_a[i] = u;

  }

  return;
  
}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::SolveSuspendedAction( const int& d )
{

  T& m_lazy_action_d = m_lazy_action[d];

  if( m_lazy_action_d != g_e_T ){

    const int i_min = d * N_sqrt;
    const int i_ulim = i_min + N_sqrt;
    IntervalAct_Body( i_min , i_ulim , m_lazy_action_d );
    U& m_bd = m_b[d];
    m_bd = o_U( m_lazy_action_d , m_bd );
    m_lazy_action_d = g_e_T;
 
  }

  return;
  
}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::IntervalAct_Body( const int& i_min , const int& i_ulim , const T& t )
{

  for( int i = i_min ; i < i_ulim ; i++ ){

    U& m_ai = m_a[i];
    m_ai = o_U( t , m_ai );

  }

  return;
  
}
