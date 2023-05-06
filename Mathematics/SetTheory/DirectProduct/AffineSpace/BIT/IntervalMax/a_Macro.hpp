// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/a_Macro.hpp

#pragma once

// 最大（最小）元による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// 区間max（min）取得O(log_2 N)

// 一点更新O((log_2 N)^2)
// max（min）による一点更新O(log_2 N)
// max（min）による区間更新O(i_final-i_start+log_2 N)

// t以上（以下）となる要素の添字の最小値の二分探索O(log_2 N)

// そのうちの区間min取得と一点更新は
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// の手法をもとに実装
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
    inline Interval ## MAX ## BIT( const T& n , const T ( &a )[N] );	\
    inline Interval ## MAX ## BIT( const T& n , T ( &&a )[N] );		\
									\
    inline const T& operator[]( const int& i ) const;			\
    inline const T& Get( const int& i ) const;				\
    T Interval ## MAX( const int& i_start , const int& i_final ) const;	\
									\
    void Set( const int& i , const T& n );				\
    void Set ## MAX( const int& i , const T& n );			\
    void IntervalSet ## MAX( const int& i_start , const int& i_final , const T& n ); \
									\
    int BinarySearch( const T& t ) const;				\
									\
  };									\

#define DEFINITION_OF_INTERVAL_MAX_BIT( MAX , INEQUALITY , OP )		\
  template <typename T , int N> inline Interval ## MAX ## BIT<T,N>::Interval ## MAX ## BIT( const T& n ) \
    : m_init( n ) , m_a() , m_fenwick_0() , m_fenwick_1()		\
  {									\
									\
    if( m_a[0] != m_init ){						\
									\
      for( int i = 0 ; i < N ; i++ ){					\
									\
	m_a[i] = m_init;						\
									\
      }									\
									\
      for( int j = 1 ; j <= N ; j++ ){					\
									\
	m_fenwick_0[j] = m_fenwick_1[j] = m_init;			\
      }									\
									\
    }									\
									\
  }									\
									\
  template <typename T , int N> inline Interval ## MAX ## BIT<T,N>::Interval ## MAX ## BIT( const T& n , const T ( &a )[N] ) : m_init( n ) , m_a() , m_fenwick_0() , m_fenwick_1() \
  {									\
									\
    for( int i = 0 ; i < N ; i++ ){					\
									\
      m_a[i] = a[i];							\
									\
    }									\
									\
    for( int i = 0 ; i < N ; i++ ){					\
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
    for( int i = N - 1 ; i >= 0 ; i-- ){				\
									\
      int j = i + 1;							\
      T& fenwick_1i = m_fenwick_1[j];					\
      fenwick_1i = m_a[i];						\
      const int j_ulim = min( j + ( j & -j ) , N + 1 );			\
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
  }									\
									\
  template <typename T , int N> inline Interval ## MAX ## BIT<T,N>::Interval ## MAX ## BIT( const T& n , T ( &&a )[N] ) : m_init( n ) , m_a() , m_fenwick_0() , m_fenwick_1() \
  {									\
									\
    swap( m_a , a );							\
									\
    for( int i = 0 ; i < N ; i++ ){					\
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
    for( int i = N - 1 ; i >= 0 ; i-- ){				\
									\
      int j = i + 1;							\
      T& fenwick_1i = m_fenwick_1[j];					\
      fenwick_1i = m_a[i];						\
      const int j_ulim = min( j + ( j & -j ) , N + 1 );			\
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
  }									\
									\
  template <typename T , int N> inline const T& Interval ## MAX ## BIT<T,N>::operator[]( const int& i ) const { return m_a[i]; } \
  template <typename T , int N> inline const T& Interval ## MAX ## BIT<T,N>::Get( const int& i ) const { return m_a[i]; } \
									\
  template <typename T , int N>						\
  T Interval ## MAX ## BIT<T,N>::Interval ## MAX( const int& i_start , const int& i_final ) const \
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
									\
  template <typename T , int N>						\
  void Interval ## MAX ## BIT<T,N>::Set( const int& i , const T& n )	\
  {									\
									\
    T& ai = m_a[i];							\
									\
    if( n INEQUALITY ai ){						\
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
  void Interval ## MAX ## BIT<T,N>::Set ## MAX( const int& i , const T& n ) \
  {									\
									\
    T& ai = m_a[i];							\
    ai INEQUALITY n ? ai = n : ai;					\
    int j = i + 1;							\
									\
    while( j <= N ){							\
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
  template <typename T , int N>						\
  void Interval ## MAX ## BIT<T,N>::IntervalSet ## MAX( const int& i_start , const int& i_final , const T& n ) \
  {									\
									\
    const int j_min = max( i_start + 1 , 1 );				\
    const int j_max = min( i_final + 1 , N );				\
    \
    for( int i = j_min - 1 ; i < j_max ; i++ ){				\
									\
      T& ai = m_a[i];							\
      ai INEQUALITY n ? ai = n : ai;					\
									\
    }									\
									\
    const int j_llim = j_min - ( j_min & -j_min );					\
    const int j_ulim = min( j_max + ( j_max & j_max ) , N + 1 );	\
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
  template <typename T , int N>						\
  void Interval ## MAX ## BIT<T,N> int BIT<T>::BinarySearch( const T& t ) const	\
  {									\
									\
    int j = 0;								\
    int power = PowerCalculation<N>.m_val;				\
    T temp{};								\
    T temp_next{};							\
									\
    while( power > 0 ){							\
									\
      int j_next = j | power;						\
									\
      if( j_next < m_N ){						\
									\
	const T& fenwick_j_next = m_fenwick[j_next];			\
	temp_next INEQUALITY fenwick_j_next ? temp_next = fenwick_j_next : temp; \
									\
	if( temp_next INEQUALITY t ){					\
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


