// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMaxBIT/a_Macro.hpp

#pragma once

#define DECRALATION_OF_INTERVAL_MAX_BIT( MAX )				\
  template <typename T , int N>						\
  class Interval ## MAX ## BIT						\
  {									\
  private:								\
    T m_init;								\
    T m_fenwick_0[N + 1];						\
    T m_fenwick_1[N + 1];						\
									\
  public:								\
    inline Interval ## MAX ## BIT( const T& n );			\
									\
    void Set ## MAX( const int& i , const T& n );			\
									\
    T Interval ## MAX( const int& i_start , const int& i_final );	\
									\
  };									\

#define DEFINITION_OF_INTERVAL_MAX_BIT( MAX , LESS_THAN )		\
  template <typename T , int N> inline Interval ## MAX ## BIT<T,N>::Interval ## MAX ## BIT( const T& n ) : m_init( n ) , m_fenwick_0() , m_fenwick_1() { for( int i = 0 ; i <= N ; i++ ){ m_fenwick_0[i] = m_fenwick_1[i] = m_init; } } \
									\
  template <typename T , int N>						\
  void Interval ## MAX ## BIT<T,N>::Set ## MAX( const int& i , const T& n ) \
  {									\
									\
    int j = i + 1;							\
									\
    while( j <= N ){							\
									\
      T& ti = m_fenwick_0[j];						\
									\
      if( ti LESS_THAN n ){						\
									\
	ti = n;								\
									\
      }									\
									\
      j += ( j & -j );							\
									\
    }									\
									\
    j = i + 1;								\
									\
    while( j >= 0 ){							\
									\
      T& ti = m_fenwick_1[j];						\
									\
      if( ti LESS_THAN n ){						\
									\
	ti = n;								\
									\
      }									\
									\
      j -= ( j & -j );							\
									\
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
    int j = i_start + 1;						\
    const int& j_max = i_final < N ? i_final : N;			\
									\
    while( j <= j_max ){						\
									\
      const T& ti = m_fenwick_0[j];					\
									\
      if( answer LESS_THAN ti ){					\
									\
	answer = ti;							\
									\
      }									\
									\
      j += ( j & - j );							\
									\
    }									\
									\
    j = i_final + 1;							\
									\
    while( j > i_start ){						\
									\
      const T& ti = m_fenwick_1[j];					\
									\
      if( answer LESS_THAN ti ){					\
									\
	answer = ti;							\
									\
      }									\
									\
      j -= ( j & - j );							\
									\
    }									\
									\
    return answer;							\
									\
  }									\


