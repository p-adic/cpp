// c:/Users/user/Documents/Programming/Utility/Search/BreadthFirst/a_Macro.hpp

#pragma once

// ResetÇÕm_foundÇ∆m_prevÇ‡èâä˙âª
// ShiftÇÕm_foundÇ∆m_prevÇÕîÒèâä˙âª
#define DECLARATION_OF_FIRST_SEARCH( BREADTH )				\
  template <int V_max,list<int> E(const int&)>				\
  class BREADTH ## FirstSearch						\
  {									\
									\
  private:								\
    int m_V;								\
    int m_init;								\
    list<int> m_next;							\
    bool m_found[V_max];						\
    int m_prev[V_max];							\
									\
  public:								\
    inline BREADTH ## FirstSearch( const int& V );			\
    inline BREADTH ## FirstSearch( const int& V , const int& init );	\
									\
    inline void Reset( const int& init );				\
    inline void Shift( const int& init );				\
									\
    bool& found( const int& i );					\
    const int& prev( const int& i ) const;				\
									\
    int Next();								\
									\
  };									\

#define DEFINITION_OF_FIRST_SEARCH( BREADTH , PUSH )			\
  template <int V_max,list<int> E(const int&)> inline BREADTH ## FirstSearch<V_max,E>::BREADTH ## FirstSearch( const int& V ) : m_V( V ) , m_init() , m_next() , m_found() , m_prev() { for( int i = 0 ; i < m_V ; i++ ){ m_prev[i] = -1; } } \
  template <int V_max,list<int> E(const int&)> inline BREADTH ## FirstSearch<V_max,E>::BREADTH ## FirstSearch( const int& V , const int& init ) : BREADTH ## FirstSearch( V ) { m_init = init; m_next.push_back( m_init ); m_found[m_init] = true; } \
									\
  template <int V_max,list<int> E(const int&)> inline void BREADTH ## FirstSearch<V_max,E>::Reset( const int& init ) { m_init = init; assert( m_init < m_V ); m_next.clear(); m_next.push_back( m_init ); for( int i = 0 ; i < m_V ; i++ ){ m_found[i] = i == m_init; m_prev[i] = -1; } } \
  template <int V_max,list<int> E(const int&)> inline void BREADTH ## FirstSearch<V_max,E>::Shift( const int& init ) { m_init = init; assert( m_init < m_V ); m_next.clear(); if( ! m_found[m_init] ){ m_next.push_back( m_init ); m_found[m_init] = true; m_prev[i] = -1; } } \
									\
  template <int V_max,list<int> E(const int&)> inline bool& BREADTH ## FirstSearch<V_max,E>::found( const int& i ) { assert( i < m_V ); return m_found[i]; } \
  template <int V_max,list<int> E(const int&)> inline const int& BREADTH ## FirstSearch<V_max,E>::prev( const int& i ) { assert( i < m_V ); return m_prev[i]; } \
									\
  template <int V_max,list<int> E(const int&)>				\
  int BREADTH ## FirstSearch<V_max,E>::Next()				\
  {									\
									\
    if( m_next.empty() ){						\
									\
      return -1;							\
									\
    }									\
									\
    const int i_curr = m_next.front();					\
    m_next.pop_front();							\
    list<int> edge = E( i_curr );					\
									\
    for( auto itr = edge.begin() , end = edge.end() ; itr != end ; itr++ ){ \
									\
      const int& i = *itr;						\
      bool& found_i = Found( i );					\
									\
      if( ! found_i ){							\
									\
	m_next.PUSH( i );						\
	m_prev[i] = i_curr;						\
	found_i = true;							\
									\
      }									\
									\
    }									\
									\
    return i_curr;							\
									\
  }									\


