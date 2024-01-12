// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/a_Macro.hpp

#pragma once

#define DECLARATION_OF_INTERVAL_MAX_BIT( MAX )				\
  template <typename T>							\
  class Interval ## MAX ## BIT						\
  {									\
  private:								\
    int m_size;								\
    T m_init;								\
    vector<T> m_a;							\
    vector<T> m_fenwick_0;						\
    vector<T> m_fenwick_1;						\
    int m_power;							\
									\
  public:								\
    inline Interval ## MAX ## BIT( const int& m_size = 0 , const T& n = T() ); \
    inline Interval ## MAX ## BIT( const T& n , vector<T> a );		\
    inline Interval ## MAX ## BIT<T>& operator=( Interval ## MAX ## BIT<T>&& a ); \
									\
    inline const T& operator[]( const int& i ) const;			\
    inline const T& Get( const int& i ) const;				\
    inline const T& LSBSegment ## MAX( const int& j , const bool& left = true ) const; \
    T Interval ## MAX( const int& i_start , const int& i_final ) const; \
									\
    void Set( const int& i , const T& n );				\
    inline void Set( const T& n , vector<T>&& a );			\
    void Set ## MAX( const int& i , const T& n );			\
    inline void Set ## MAX( vector<T> a );					\
    void IntervalSet ## MAX( const int& i_start , const int& i_final , const T& n ); \
    void Initialise( const T& n );					\
									\
    int BinarySearch( const T& n ) const;				\
									\
  };									\

#define DEFINITION_OF_INTERVAL_MAX_BIT( MAX , INEQUALITY , OPR )	\
  template <typename T> inline Interval ## MAX ## BIT<T>::Interval ## MAX ## BIT( const int& size , const T& n ) : m_size( size ) , m_init( n ) , m_a( m_size , m_init ) , m_fenwick_0( m_size + 1 , m_init ) , m_fenwick_1( m_size + 1 , m_init ) , m_power( 1 ) { while( m_power < m_size ){ m_power <<= 1; } } \
									\
  template <typename T> inline Interval ## MAX ## BIT<T>::Interval ## MAX ## BIT( const T& n , vector<T> a ) : m_size( a.size() ) , m_init( n ) , m_a( move( a ) ) , m_fenwick_0( m_size + 1 ) , m_fenwick_1( m_size + 1 ) , m_power( 1 ) \
  {									\
									\
    for( int i = 0 ; i < m_size ; i++ ){				\
									\
      int j = i + 1;							\
      T& fenwick_0i = m_fenwick_0[j];					\
      fenwick_0i = m_a[i];						\
      const int j_llim = j - ( j & -j );				\
      j--;								\
									\
      while( j > j_llim ){						\
									\
	const T& tj = m_fenwick_0[j];					\
	fenwick_0i INEQUALITY tj ? fenwick_0i = tj : fenwick_0i;	\
	j -= ( j & -j );						\
									\
      }									\
									\
    }									\
									\
    for( int i = m_size - 1 ; i >= 0 ; i-- ){				\
									\
      int j = i + 1;							\
      T& fenwick_1i = m_fenwick_1[j];					\
      fenwick_1i = m_a[i];						\
      const int j_ulim = min( j + ( j & -j ) , m_size + 1 );		\
      j++;								\
									\
      while( j < j_ulim ){						\
									\
	const T& tj = m_fenwick_1[j];					\
	fenwick_1i INEQUALITY tj ? fenwick_1i = tj : fenwick_1i;	\
	j += ( j & -j );						\
									\
      }									\
									\
    }									\
									\
    while( m_power < m_size ){						\
									\
      m_power <<= 1;							\
									\
    }									\
									\
  }									\
									\
  template <typename T> inline Interval ## MAX ## BIT<T>& Interval ## MAX ## BIT<T>::operator=( Interval ## MAX ## BIT<T>&& a ) { m_size = a.m_size; m_init = move( a.m_init ); m_a = move( a.m_a ); m_fenwick_0 = move( m_fenwick_0 ); m_fenwick_1 = move( m_fenwick_1 ); m_PW = a.m_PW; return *this; } \
									\
  template <typename T> inline const T& Interval ## MAX ## BIT<T>::operator[]( const int& i ) const { return m_a[i]; } \
  template <typename T> inline const T& Interval ## MAX ## BIT<T>::Get( const int& i ) const { return m_a[i]; } \
  template <typename T> inline const T& Interval ## MAX ## BIT<T>::LSBSegment ## MAX( const int& j , const bool& left ) const { assert( 0 < j && j <= m_size ); return ( left ? m_fenwick_0 : m_fenwick_1 )[j]; } \
									\
  template <typename T>							\
  T Interval ## MAX ## BIT<T>::Interval ## MAX( const int& i_start , const int& i_final ) const \
  {									\
									\
    T answer = m_init;							\
    const int j_min = max( i_start + 1 , 1 );				\
    const int j_max = min( i_final + 1 , m_size );			\
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
    ( j_min <= j_max && answer INEQUALITY a_centre ) ? answer = a_centre : answer; \
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
									\
  template <typename T>							\
  void Interval ## MAX ## BIT<T>::Set( const int& i , const T& n )	\
  {									\
									\
    T& ai = m_a[i];							\
									\
    if( n INEQUALITY ai ){						\
									\
      int j = i + 1;							\
									\
      while( j <= m_size ){						\
									\
	const int lsb = ( j & -j );					\
	m_fenwick_0[j] = OPR( OPR( Interval ## MAX( j - lsb , i - 1 ) , n ) , Interval ## MAX( i + 1 , j - 1 ) ); \
	j += lsb;							\
									\
      }									\
									\
      j = i + 1;							\
									\
      while( j > 0 ){							\
									\
	const int lsb = ( j & -j );					\
	m_fenwick_1[j] = OPR( OPR( Interval ## MAX( j - 1  , i - 1 ) , n ) , Interval ## MAX( i + 1 , j + lsb - 2 ) ); \
	j -= lsb;							\
									\
      }									\
									\
      ai = n;								\
									\
    } else {								\
									\
      Set ## MAX( i , n );						\
									\
    }									\
									\
    return;								\
									\
  }									\
									\
  template <typename T> inline void Interval ## MAX ## BIT<T>::Set( const T& n , vector<T>&& a ) { *this = Interval ## MAX ## BIT<T>( n , move( a ) ); } \
									\
  template <typename T>							\
  void Interval ## MAX ## BIT<T>::Set ## MAX( const int& i , const T& n ) \
  {									\
									\
    assert( i < m_size );						\
    T& ai = m_a[i];							\
    ai INEQUALITY n ? ai = n : ai;					\
    int j = i + 1;							\
									\
    while( j <= m_size ){						\
									\
      T& tj = m_fenwick_0[j];						\
      tj INEQUALITY n ? tj = n : tj;					\
      j += ( j & -j );							\
									\
    }									\
									\
    j = i + 1;								\
									\
    while( j > 0 ){							\
									\
      T& tj = m_fenwick_1[j];						\
      tj INEQUALITY n ? tj = n : tj;					\
      j -= ( j & -j );							\
									\
    }									\
									\
    return;								\
									\
  }									\
									\
  template <typename T> inline void Interval ## MAX ## BIT<T>::Set ## MAX( vector<T>&& a ) { Interval ## MAX ## BIT<T> a_copy{ m_init , move( a ) }; assert( m_size == a_copy.m_size ); for( int j = 1 ; j <= m_size ; j++ ){ T& t0j = m_fenwick_0[j]; T& a0j = a_copy.m_fenwick_0[j]; t0j INEQUALITY a0j ? t0j = a0j : t0j; T& t1j = m_fenwick_1[j]; T& a1j = a_copy.m_fenwick_1[j]; t1j INEQUALITY a1j ? t1j = a1j : t1j; } } \
									\
  template <typename T> inline void Interval ## MAX ## BIT<T>::Set ## MAX( const int& i , const T& n ){} \
  template <typename T>							\
  void Interval ## MAX ## BIT<T>::IntervalSet ## MAX( const int& i_start , const int& i_final , const T& n ) \
  {									\
									\
    const int j_min = max( i_start + 1 , 1 );				\
    const int j_max = min( i_final + 1 , m_size );			\
									\
    for( int i = j_min - 1 ; i < j_max ; i++ ){				\
									\
      T& ai = m_a[i];							\
      ai INEQUALITY n ? ai = n : ai;					\
									\
    }									\
									\
    const int j_llim = j_min - ( j_min & -j_min );			\
    const int j_ulim = min( j_max + ( j_max & j_max ) , m_size + 1 );	\
									\
    if( j_min <= j_max ){						\
									\
      int j = j_min;							\
									\
      while( j < j_ulim ){						\
									\
	if( j - ( j & -j ) < j_max ){					\
									\
	  T& tj = m_fenwick_0[j];					\
	  tj INEQUALITY n ? tj = n : tj;				\
	  								\
	}								\
									\
	j++;								\
									\
      }									\
									\
      j = j_max;							\
									\
      while( j  > j_llim ){						\
									\
	if( j + ( j & -j ) > j_min ){					\
									\
	  T& tj = m_fenwick_0[j];					\
	  tj INEQUALITY n ? tj = n : tj;				\
									\
	}								\
									\
	j--;								\
									\
      }									\
									\
    }									\
									\
    return;								\
  }									\
									\
  template <typename T>							\
  void Interval ## MAX ## BIT<T>::Initialise( const T& n )		\
  {									\
									\
    m_init = n;								\
									\
    for( int i = 0 ; i < m_size ; i++ ){				\
									\
      m_a[i] = m_fenwick_0[i+1] = m_fenwick_1[i+1] = m_init;		\
    }									\
									\
    return;								\
									\
  }									\
  									\
  template <typename T>							\
  int Interval ## MAX ## BIT<T>::BinarySearch( const T& n ) const	\
  {									\
									\
    int j = 0;								\
    int power = m_power;						\
    T temp{};								\
    T temp_next{};							\
									\
    while( power > 0 ){							\
									\
      int j_next = j | power;						\
									\
      if( j_next < m_size ){						\
									\
	const T& fenwick_j_next = m_fenwick_0[j_next];			\
	temp_next INEQUALITY fenwick_j_next ? temp_next = fenwick_j_next : temp; \
									\
	if( temp_next INEQUALITY n ){					\
									\
	  temp = temp_next;						\
	  j = j_next;							\
									\
	} else {							\
									\
	  temp_next = temp;						\
									\
	}								\
									\
      }									\
									\
      power >>= 1;							\
									\
    }									\
									\
    return j;								\
									\
  }									\


