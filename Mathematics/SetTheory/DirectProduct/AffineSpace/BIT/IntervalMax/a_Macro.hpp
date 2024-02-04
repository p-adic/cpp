// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/a_Macro.hpp

#pragma once

#define DECLARATION_OF_INTERVAL_MAX_BIT( MAX )				\
  template <typename U>							\
  class Interval ## MAX ## BIT						\
  {									\
  private:								\
    int m_size;								\
    U m_unit;								\
    vector<U> m_a;							\
    vector<U> m_fenwick_0;						\
    vector<U> m_fenwick_1;						\
    int m_power;							\
									\
  public:								\
    inline Interval ## MAX ## BIT( const U& unit , vector<U> a = vector<U>() ); \
									\
    inline const U& operator[]( const int& i ) const;			\
    inline const U& Get( const int& i ) const;				\
    inline const U& LSBSegment ## MAX( const int& j , const bool& left = true ) const; \
    U Interval ## MAX( const int& i_start , const int& i_final ) const; \
									\
    void Set( const int& i , const U& u );				\
    inline void Set( const U& unit , vector<U>&& a );			\
    void Set ## MAX( const int& i , const U& u );			\
    inline void Set ## MAX( vector<U> a );				\
    void IntervalSet ## MAX( const int& i_start , const int& i_final , const U& n ); \
    inline void Initialise( const U& unit , const int& size );		\
									\
    int BinarySearch( const U& u ) const;				\
									\
  };									\

#define DEFINITION_OF_INTERVAL_MAX_BIT( MAX , INEQUALITY , OPR )	\
  template <typename U> inline Interval ## MAX ## BIT<U>::Interval ## MAX ## BIT( const U& unit , vector<U> a ) : m_size( a.size() ) , m_unit( unit ) , m_a( move( a ) ) , m_fenwick_0( m_size + 1 ) , m_fenwick_1( m_size + 1 ) , m_power( 1 ) \
  {									\
									\
    for( int i = 0 ; i < m_size ; i++ ){				\
									\
      int j = i + 1;							\
      U& fenwick_0i = m_fenwick_0[j];					\
      fenwick_0i = m_a[i];						\
      const int j_llim = j - ( j & -j );				\
      j--;								\
									\
      while( j > j_llim ){						\
									\
	const U& uj = m_fenwick_0[j];					\
	fenwick_0i INEQUALITY uj ? fenwick_0i = uj : fenwick_0i;	\
	j -= ( j & -j );						\
									\
      }									\
									\
    }									\
									\
    for( int i = m_size - 1 ; i >= 0 ; i-- ){				\
									\
      int j = i + 1;							\
      U& fenwick_1i = m_fenwick_1[j];					\
      fenwick_1i = m_a[i];						\
      const int j_ulim = min( j + ( j & -j ) , m_size + 1 );		\
      j++;								\
									\
      while( j < j_ulim ){						\
									\
	const U& uj = m_fenwick_1[j];					\
	fenwick_1i INEQUALITY uj ? fenwick_1i = uj : fenwick_1i;	\
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
  template <typename U>							\
  void Interval ## MAX ## BIT<U>::Set( const int& i , const U& u )	\
  {									\
									\
    U& ai = m_a[i];							\
									\
    if( u INEQUALITY ai ){						\
									\
      int j = i + 1;							\
									\
      while( j <= m_size ){						\
									\
	const int lsb = ( j & -j );					\
	m_fenwick_0[j] = OPR( OPR( Interval ## MAX( j - lsb , i - 1 ) , u ) , Interval ## MAX( i + 1 , j - 1 ) ); \
	j += lsb;							\
									\
      }									\
									\
      j = i + 1;							\
									\
      while( j > 0 ){							\
									\
	const int lsb = ( j & -j );					\
	m_fenwick_1[j] = OPR( OPR( Interval ## MAX( j - 1  , i - 1 ) , u ) , Interval ## MAX( i + 1 , j + lsb - 2 ) ); \
	j -= lsb;							\
									\
      }									\
									\
      ai = u;								\
									\
    } else {								\
									\
      Set ## MAX( i , u );						\
									\
    }									\
									\
    return;								\
									\
  }									\
									\
  template <typename U> inline void Interval ## MAX ## BIT<U>::Set( const U& unit , vector<U>&& a ) { *this = Interval ## MAX ## BIT<U>( unit , move( a ) ); } \
									\
  template <typename U>							\
  void Interval ## MAX ## BIT<U>::Set ## MAX( const int& i , const U& u ) \
  {									\
									\
    assert( i < m_size );						\
    U& ai = m_a[i];							\
    ai INEQUALITY u ? ai = u : ai;					\
    int j = i + 1;							\
									\
    while( j <= m_size ){						\
									\
      U& uj = m_fenwick_0[j];						\
      uj INEQUALITY u ? uj = u : uj;					\
      j += ( j & -j );							\
									\
    }									\
									\
    j = i + 1;								\
									\
    while( j > 0 ){							\
									\
      U& uj = m_fenwick_1[j];						\
      uj INEQUALITY u ? uj = u : uj;					\
      j -= ( j & -j );							\
									\
    }									\
									\
    return;								\
									\
  }									\
									\
  template <typename U> inline void Interval ## MAX ## BIT<U>::Set ## MAX( vector<U> a ) { Interval ## MAX ## BIT<U> a_copy{ m_unit , move( a ) }; assert( m_size == a_copy.m_size ); for( int j = 1 ; j <= m_size ; j++ ){ U& t0j = m_fenwick_0[j]; U& a0j = a_copy.m_fenwick_0[j]; t0j INEQUALITY a0j ? t0j = a0j : t0j; U& t1j = m_fenwick_1[j]; U& a1j = a_copy.m_fenwick_1[j]; t1j INEQUALITY a1j ? t1j = a1j : t1j; } } \
									\
  template <typename U>							\
  void Interval ## MAX ## BIT<U>::IntervalSet ## MAX( const int& i_start , const int& i_final , const U& u ) \
  {									\
									\
    const int j_min = max( i_start + 1 , 1 );				\
    const int j_max = min( i_final + 1 , m_size );			\
									\
    for( int i = j_min - 1 ; i < j_max ; i++ ){				\
									\
      U& ai = m_a[i];							\
      ai INEQUALITY u ? ai = u : ai;					\
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
	  U& uj = m_fenwick_0[j];					\
	  uj INEQUALITY u ? uj = u : uj;				\
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
	  U& uj = m_fenwick_0[j];					\
	  uj INEQUALITY u ? uj = u : uj;				\
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
  template <typename U> inline void Interval ## MAX ## BIT<U>::Initialise( const U& unit , const int& size ) { m_size = size; m_unit = unit; m_a = vector<U>( m_size , m_unit ); m_fenwick_0 = m_fenwick_1 = vector<U>( m_size + 1 , m_unit ); } \
									\
  template <typename U> inline const U& Interval ## MAX ## BIT<U>::operator[]( const int& i ) const { assert( 0 <= i & i < m_size ); return m_a[i]; } \
  template <typename U> inline const U& Interval ## MAX ## BIT<U>::Get( const int& i ) const { return operator[]( i ); } \
  template <typename U> inline const U& Interval ## MAX ## BIT<U>::LSBSegment ## MAX( const int& j , const bool& left ) const { assert( 0 < j && j <= m_size ); return ( left ? m_fenwick_0 : m_fenwick_1 )[j]; } \
									\
  template <typename U>							\
  U Interval ## MAX ## BIT<U>::Interval ## MAX( const int& i_start , const int& i_final ) const \
  {									\
									\
    U answer = m_unit;							\
    const int j_min = max( i_start + 1 , 1 );				\
    const int j_max = min( i_final + 1 , m_size );			\
    int j = j_min;							\
    int j_next = j + ( j & - j );					\
									\
    while( j_next <= j_max ){						\
									\
      const U& uj = m_fenwick_1[j];					\
      answer INEQUALITY uj ? answer = uj : answer;			\
      j = j_next;							\
      j_next += ( j & -j );						\
									\
    }									\
									\
    const U& a_centre = m_a[j-1];					\
    ( j_min <= j_max && answer INEQUALITY a_centre ) ? answer = a_centre : answer; \
    j = j_max;								\
    j_next = j - ( j & - j );						\
									\
    while( j_next >= j_min ){						\
									\
      const U& uj = m_fenwick_0[j];					\
      answer INEQUALITY uj ? answer = uj : answer;			\
      j = j_next;							\
      j_next -= ( j & -j );						\
									\
    }									\
									\
    return answer;							\
									\
  }									\
									\
  template <typename U>							\
  int Interval ## MAX ## BIT<U>::BinarySearch( const U& u ) const	\
  {									\
									\
    int j = 0;								\
    int power = m_power;						\
    U temp{};								\
    U temp_next{};							\
									\
    while( power > 0 ){							\
									\
      int j_next = j | power;						\
									\
      if( j_next < m_size ){						\
									\
	const U& fenwick_j_next = m_fenwick_0[j_next];			\
	temp_next INEQUALITY fenwick_j_next ? temp_next = fenwick_j_next : temp; \
									\
	if( temp_next INEQUALITY u ){					\
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


