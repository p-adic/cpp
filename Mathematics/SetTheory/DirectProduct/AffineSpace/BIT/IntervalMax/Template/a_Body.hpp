// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/Template/a_Body.hpp

#pragma once
#include "a.hpp"

template <TEMPLATE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT> inline const T& AbstractBIT<T,m_T,e_T,N>::g_e = e_T();

template <TEMPLATE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT> inline IdempotentMonoidBIT<T,m_T,e_T,N>::IdempotentMonoidBIT() : m_a() , m_fenwick_0() , m_fenwick_1() { if( m_a[0] != g_e ){ for( int i = 0 ; i < N ; i++ ){ m_a[i] = g_e; } for( int j = 1 ; j <= N ; j++ ){ m_fenwick_0[j] = m_fenwick_1[j] = g_e; } } }

template <TEMPLATE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT> inline IdempotentMonoidBIT<T,m_T,e_T,N>::IdempotentMonoidBIT( const T ( &a )[N] ) : m_init( n ) , m_a() , m_fenwick_0() , m_fenwick_1() 
{

  for( int i = 0 ; i < N ; i++ ){

    m_a[i] = a[i];

  }

  for( int i = 0 ; i < N ; i++ ){

    int j = i + 1;
    T& fenwick_0i = m_fenwick_0[j];
    fenwick_0i = m_a[i];
    const int j_llim = j - ( j & -j );
    j--;

    while( j > j_llim ){

      fenwick_0i = m_T( m_fenwick_0[j] , fenwick_0i );
      j -= ( j & -j );

    }

  }

  for( int i = N - 1 ; i >= 0 ; i-- ){

    int j = i + 1;
    T& fenwick_1i = m_fenwick_1[j];
    fenwick_1i = m_a[i];
    const int j_ulim = min( j + ( j & -j ) , N + 1 );
    j++;

    while( j < j_ulim ){

      fenwick_1i = m_T( fenwick_1i , m_fenwick_1[j] );
      j += ( j & -j );

    }

  }

}

template <TEMPLATE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT> inline IdempotentMonoidBIT<T,m_T,e_T,N>::IdempotentMonoidBIT( T ( &&a )[N] ) : m_init( n ) , m_a( move( a ) ) , m_fenwick_0() , m_fenwick_1() 
{

  for( int i = 0 ; i < N ; i++ ){

    int j = i + 1;
    T& fenwick_0i = m_fenwick_0[j];
    fenwick_0i = m_a[i];
    const int j_llim = j - ( j & -j );
    j--;

    while( j > j_llim ){

      fenwick_0i = m_T( m_fenwick_0[j] , fenwick_0i );
      j -= ( j & -j );

    }

  }

  for( int i = N - 1 ; i >= 0 ; i-- ){

    int j = i + 1;
    T& fenwick_1i = m_fenwick_1[j];
    fenwick_1i = m_a[i];
    const int j_ulim = min( j + ( j & -j ) , N + 1 );
    j++;

    while( j < j_ulim ){

      fenwick_1i = m_T( fenwick_1i , m_fenwick_1[j] );
      j += ( j & -j );

    }

  }

}

template <TEMPLATE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT> inline const T& IdempotentMonoidBIT<T,m_T,e_T,N>::operator[]( const int& i ) const { return m_a[i]; } 
template <TEMPLATE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT> inline const T& IdempotentMonoidBIT<T,m_T,e_T,N>::Get( const int& i ) const { return m_a[i]; } 

template <TEMPLATE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT>
T IdempotentMonoidBIT<T,m_T,e_T,N>::IntervalSum( const int& i_start , const int& i_final ) 
{

  const int j_min = i_start < 0 ? 1 : i_start + 1;
  const int j_max = i_final < N ? i_final + 1 : N;

  if( j_min > j_max ){

    return g_e;
  }
    
  T answer1 = g_e;
  int j = j_min;
  int j_next = j + ( j & -j );

  while( j_next <= j_max ){

    answer1 = m_T( answer1 , m_fenwick_1[j] );
    j = j_next;
    j_next += ( j & -j );

  }

  answer1 = m_T( answer1 , m_a[j-1] ); 
  T answer0 = g_e;
  j = j_max;
  j_next = j - ( j & -j );

  while( j_next >= j_min ){

    answer0 = m_T( m_fenwick_0[j] , answer0 );
    j = j_next;
    j_next -= ( j & -j );

  }

  return m_T( answer1 , answer0 );

}

template <TEMPLATE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT>
void IdempotentMonoidBIT<T,m_T,e_T,N>::Set( const int& i , const T& n )
{

  T& ai = m_a[i];

  if( n == m_T( ai , n ) ){

    Add( i , n );

  } else {
  
    int j = i + 1;

    while( j <= N ){

      const int lsb = ( j & -j );
      m_fenwick_0[j] = m_T( m_T( IntervalSum( j - lsb + 1 , i - 1 ) , n ) , IntervalSum( i + 1 , j ) ); 
      j += lsb;

    }

    j = i + 1;

    while( j > 0 ){

      const int lsb = ( j & -j );
      m_fenwick_0[j] = m_T( m_T( IntervalSum( j , i - 1 ) , n ) , IntervalSum( i + 1 , j + lsb - 1 ) ); 
      j -= lsb;

    }

    ai = n;

  }

  return;

}

template <TEMPLATE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT>
void IdempotentMonoidBIT<T,m_T,e_T,N>::Add( const int& i , const T& n ) 
{

  T& ai = m_a[i];
  ai = m_T( ai , n );
  int j = i + 1;

  while( j <= N ){

    T& tj = m_fenwick_0[j];
    tj = m_T( tj , n );
    j += ( j & -j );

  }

  j = i + 1;

  while( j > 0 ){

    T& tj = m_fenwick_1[j];
    tj = m_T( tj , n );
    j -= ( j & -j );

  }

  return;

}


template <TEMPLATE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT>
void IdempotentMonoidBIT<T,m_T,e_T,N>::IntervalAdd( const int& i_start , const int& i_final , const T& n ) 
{

  const int j_min = max( i_start + 1 , 1 );
  const int j_max = min( i_final + 1 , N );

  for( int i = j_min - 1 ; i < j_max ; i++ ){

    T& ai = m_a[i];
    ai = m_T( ai , n );

  }

  const int j_llim = j_min - ( j_min & -j_min );
  const int j_ulim = min( j_max + ( j_max & j_max ) , N + 1 );

  if( j_min <= j_max ){

    int j = j_min;

    while( j < j_ulim ){

      if( j - ( j & -j ) < j_max ){

	T& tj = m_fenwick_0[j];
	tj = m_T( tj , n );
  
      }

      j++;

    }

    j = j_max;

    while( j  > j_llim ){

      if( j + ( j & -j ) > j_min ){

	T& tj = m_fenwick_0[j];
	tj = m_T( tj , n );

      }

      j--;

    }

  }

  return;
}
