// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/BIT/IntervalMaxBIT/Template/a_Body.hpp

#pragma once
#include "a.hpp"

template <TEMPLETE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT> inline const T& AbstractBIT<T,m_T,e_T,N>::g_e = e_T();

template <TEMPLETE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT> inline IdempotentMonoidBIT<T,m_T,e_T,N>::IdempotentMonoidBIT() : m_a() , m_fenwick_0() , m_fenwick_1()
{

  if( m_a[0] != g_e ){

    for( int i = 0 ; i < N ; i++ ){

      m_a[i] = g_e;

    }

    for( int j = 1 ; j <= N ; j++ ){

      m_fenwick_0[j] = m_fenwick_1[j] = g_e;

    }

  }

}

template <TEMPLETE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT> inline IdempotentMonoidBIT<T,m_T,e_T,N>::IdempotentMonoidBIT( const T ( &a )[N] ) : m_init( n ) , m_a() , m_fenwick_0() , m_fenwick_1() 
{

  for( int i = 0 ; i < N ; i++ ){

    m_a[i] = a[i];

  }

  for( int i = 0 ; i < N ; i++ ){

    int j = i + 1;
    T& fenwick_0i = m_fenwick_0[j];
    fenwick_0i = a[i];
    const int j_llim = j - ( j & -j );
    j--;

    while( j > j_llim ){

      fenwick_0i = m_T( fenwick_0i , m_fenwick_0[j] );
      j -= ( j & -j );

    }

  }

  for( int i = N - 1 ; i >= 0 ; i-- ){

    int j = i + 1;
    T& fenwick_1i = m_fenwick_1[j];
    fenwick_1i = a[i];
    const int j_ulim = min( j + ( j & -j ) , N + 1 );
    j++;

    while( j < j_ulim ){

      fenwick_1i = m_T( fenwick_1i , m_fenwick_1[j] );
      j += ( j & -j );

    }

  }

}

template <TEMPLETE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT> inline const T& IdempotentMonoidBIT<T,m_T,e_T,N>::operator[]( const int& i ) const { return m_a[i]; } 
template <TEMPLETE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT> inline const T& IdempotentMonoidBIT<T,m_T,e_T,N>::Get( const int& i ) const { return m_a[i]; } 

template <TEMPLETE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT>
T IdempotentMonoidBIT<T,m_T,e_T,N>::IntervalAdd( const int& i_start , const int& i_final ) 
{

  T answer = g_e;
  const int j_min = i_start < 0 ? 1 : i_start + 1;
  const int j_max = i_final < N ? i_final + 1 : N;
  int j = j_min;
  int j_next = j + ( j & - j );

  while( j_next <= j_max ){

    answer = m_T( answer , m_fenwick_1[j] );
    j = j_next;
    j_next += ( j & -j );

  }

  j_min <= j_max ? answer = m_T( answer , m_a[j-1] ); 
  j = j_max;
  j_next = j - ( j & - j );

  while( j_next >= j_min ){

    answer = m_T( answer , m_fenwick_0[j] );
    j = j_next;
    j_next -= ( j & -j );

  }

  return answer;

}

template <TEMPLETE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT>
void IdempotentMonoidBIT<T,m_T,e_T,N>::Set( const int& i , const T& n )
{

  T& ai = m_a[i];

  if( n INEQUALITY ai ){

    int j = i + 1;

    while( j <= N ){

      const int lsb = ( j & -j );
      m_fenwick_0[j] = m_T( m_T( IntervalAdd( j - lsb + 1 , i - 1 ) , n ) , IntervalAdd( i + 1 , j ) ); 
      j += lsb;

    }

    j = i + 1;

    while( j > 0 ){

      const int lsb = ( j & -j );
      m_fenwick_0[j] = m_T( m_T( IntervalAdd( j , i - 1 ) , n ) , IntervalAdd( i + 1 , j + lsb - 1 ) ); 
      j -= lsb;

    }

    ai = n;

  } else {

    SetAdd( i , n );
  }

  return;

}

template <TEMPLETE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT>
void IdempotentMonoidBIT<T,m_T,e_T,N>::SetAdd( const int& i , const T& n ) 
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


template <TEMPLETE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT>
void IdempotentMonoidBIT<T,m_T,e_T,N>::IntervalSetAdd( const int& i_start , const int& i_final , const T& n ) 
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
