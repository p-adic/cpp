// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMaxBIT/a_Macro.hpp

#pragma once

#define DECRALATION_OF_INTERVAL_MAX_BIT( MAX )				\
  template <typename T , int N>						\
  class Interval ## MAX ## BIT						\
  {									\
  private:								\
    T m_init;								\
    T m_a[N];								\
    T m_fenwick_0[N + 1];						\
    T m_fenwick_1[N + 1];						\
									\
  public:								\
    inline Interval ## MAX ## BIT( const T& n );			\
									\
    inline const T& operator[]( const int& i ) const;				\
    inline const T& Get( const int& i ) const;				\
    void Set ## MAX( const int& i , const T& n );			\
    void Set( const int& i , const T& n );				\
									\
    T Interval ## MAX( const int& i_start , const int& i_final );	\
									\
  };									\

#define DEFINITION_OF_INTERVAL_MAX_BIT( MAX , INEQUALITY , OP )		\
  template <typename T , int N> inline Interval ## MAX ## BIT<T,N>::Interval ## MAX ## BIT( const T& n ) : m_init( n ) , m_a() , m_fenwick_0() , m_fenwick_1() { for( int i = 0 ; i <= N ; i++ ){ m_fenwick_0[i] = m_fenwick_1[i] = m_init; } } \
									\
  template <typename T , int N> inline const T& Interval ## MAX ## BIT<T,N>::operator[]( const int& i ) const { return m_a[i]; } \
  template <typename T , int N> inline const T& Interval ## MAX ## BIT<T,N>::Get( const int& i ) const { return m_a[i]; } \
  template <typename T , int N>						\
  void Interval ## MAX ## BIT<T,N>::Set ## MAX( const int& i , const T& n ) \
  {									\
									\
    T& ai = m_a[i];							\
    ai INEQUALITY n ? ai = n : ai;						\
    int j = i + 1;							\
									\
    while( j <= N ){							\
									\
      T& ti = m_fenwick_0[j];						\
      ti INEQUALITY n ? ti = n : ti;					\
      j += ( j & -j );							\
									\
    }									\
									\
    j = i + 1;								\
									\
    while( j > 0 ){							\
									\
      T& ti = m_fenwick_1[j];						\
      ti INEQUALITY n ? ti = n : ti;					\
      j -= ( j & -j );							\
									\
    }									\
									\
    return;								\
									\
  }									\
									\
  template <typename T , int N>						\
  void Interval ## MAX ## BIT<T,N>::Set( const int& i , const T& n )	\
  {									\
									\
    T& ai = m_a[i];							\
									\
    if( n INEQUALITY ai ){							\
									\
      int j = i + 1;							\
									\
      while( j <= N ){							\
									\
	const int lsb = ( j & -j );					\
	m_fenwick_0[j] = OP( OP( Interval ## MAX( j - lsb + 1 , i - 1 ) , n ) , Interval ## MAX( i + 1 , j ) ); \
	j += lsb;							\
									\
      }									\
									\
      j = i + 1;							\
									\
      while( j > 0 ){							\
									\
	const int lsb = ( j & -j );					\
	m_fenwick_0[j] = OP( OP( Interval ## MAX( j , i - 1 ) , n ) , Interval ## MAX( i + 1 , j + lsb - 1 ) ); \
	j -= lsb;							\
									\
      }									\
									\
      ai = n;								\
									\
    } else {								\
									\
      Set ## MAX( i , n );						\
    }									\
									\
    return;								\
									\
  }									\
									\
  template <typename T , int N>						\
  T Interval ## MAX ## BIT<T,N>::Interval ## MAX( const int& i_start , const int& i_final ) \
  {									\
									\
    T answer = m_init;							\
    const int j_min = i_start < 0 ? 1 : i_start + 1;			\
    const int j_max = i_final < N ? i_final + 1 : N;			\
    int j = j_min;							\
    int j_next = j + ( j & - j );					\
									\
    while( j_next <= j_max ){						\
									\
      const T& tj = m_fenwick_1[j];					\
      answer INEQUALITY tj ? answer = tj : answer;			\
      j = j_next;							\
      j_next += ( j & -j );						\
      									\
    }									\
									\
    const T& a_centre = m_a[j-1];					\
    ( j_min <= j_max && answer < a_centre ) ? answer = a_centre : answer; \
    j = j_max;								\
    j_next = j - ( j & - j );						\
									\
    while( j_next >= j_min ){						\
									\
      const T& tj = m_fenwick_0[j];					\
      answer INEQUALITY tj ? answer = tj : answer;			\
      j = j_next;							\
      j_next -= ( j & -j );						\
									\
    }									\
									\
    return answer;							\
									\
  }									\


