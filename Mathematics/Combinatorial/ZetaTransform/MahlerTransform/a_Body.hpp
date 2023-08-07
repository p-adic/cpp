// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/MahlerTransform/a_Body.hpp

#pragma once
#include "a.hpp"

template <int N_max> inline MahlerTransform<N_max>::MahlerTransform( const int& p ) : m_p( p ) , m_fact() , m_fact_inv() , m_inv()
{
  
  static_assert( 0 < N_max );
  assert( N_max <= m_p );
  m_fact[0] = m_fact_inv[0] = m_fact[1] = m_fact_inv[1] = m_inv[1] = 1;
  ll fact_temp = 1;
  ll fact_inv_temp = 1;
  
  for( int i = 2 ; i < N_max ; i++ ){

    m_fact[i] = ( fact_temp *= i ) %= m_p;
    m_fact_inv[i] = ( fact_inv_temp *= m_inv[i] = m_p - m_inv[m_p % i] * ( m_p / i ) % m_p ) %= m_p;
    
  }

}

template <int N_max> void MahlerTransform<N_max>::Convert( const ll ( &f )[N_max] , ll ( &a )[N_max] , const int& i_start , const int& i_final )
{

  assert( 0 <= i_start && i_start <= i_final && i_final < N_max );
  
  for( int i = i_start ; i <= i_final ; i++ ){

    a[i] = f[i];

  }
  
  for( int j = i_start + 1; j <= i_final ; j++ ){

    for( int i = i_final ; i >= j ; i-- ){

      ll& a_i = a[i] -= a[i - 1];
      a_i < 0 ? a_i += m_p : a_i;

    }

  }

  return;

}

template <int N_max> void MahlerTransform<N_max>::InverseConvert( const ll ( &a )[N_max] , ll ( &f )[N_max] , const int& i_start , const int& i_final )
{

  assert( 0 <= i_start && i_start <= i_final && i_final < N_max );
  
  for( int i = i_start ; i <= i_final ; i++ ){

    ll& f_i = f[i] = 0;

    for( int j = i_start ; j <= i ; j++ ){

      ( f_i += m_fact[i - i_start] * m_fact_inv[j - i_start] % m_p * m_fact_inv[i - j] % m_p * a[j] % m_p ) < m_p ? f_i : f_i -= m_p;

    }

  }
  
  return;

}

template <int N_max> inline ll MahlerTransform<N_max>::Combination( const int& n , const int& i ) const { assert( 0 <= n && n < N_max && 0 <= i ); return n < i ? 0 : m_fact[n] * m_fact_inv[i] % m_p * m_fact_inv[n-i] % m_p; }
template <int N_max> inline const ll& MahlerTransform<N_max>::Factorial( const int& n ) const { assert( 0 <= n && n < N_max ); return m_fact[n]; }
template <int N_max> inline const ll& MahlerTransform<N_max>::FactorialInverse( const int& n ) const { assert( 0 <= n && n < N_max ); return m_fact_inv[n]; }
template <int N_max> inline const ll& MahlerTransform<N_max>::Inverse( const int& n ) const { assert( 0 < n && n < N_max ); return m_inv[n]; }
