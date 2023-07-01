// c:/Users/user/Documents/Programming/Utility/Search/BreadthFirst/a_Macro.hpp

#pragma once

// ResetÇÕm_foundÇ∆m_prevÇèâä˙âª
// ShiftÇÕm_foundÇ∆m_prevÇîÒèâä˙âª
#define DECLARATION_OF_FIRST_SEARCH( BREADTH )				\
  template <int V_max>							\
  class BREADTH ## FirstSearch_Body					\
  {									\
									\
  protected:								\
    int m_V;								\
    int m_init;								\
    list<int> m_next;							\
    bool m_found[V_max];						\
    int m_prev[V_max];							\
									\
  public:								\
    inline BREADTH ## FirstSearch_Body( const int& V );			\
    inline BREADTH ## FirstSearch_Body( const int& V , const int& init ); \
									\
    inline void Reset( const int& init );				\
    inline void Shift( const int& init );				\
									\
    inline const int& size() const;					\
    inline const int& init() const;					\
    inline bool& found( const int& i );					\
    inline const int& prev( const int& i ) const;			\
									\
    int Next();								\
									\
  private:								\
    virtual list<int> e( const int& t ) = 0;				\
									\
  };									\
									\
  template <int V_max,list<int> E(const int&)>				\
  class BREADTH ## FirstSearch :					\
    public BREADTH ## FirstSearch_Body<V_max>				\
  {									\
									\
  public:								\
									\
    template<typename... Args> inline BREADTH ## FirstSearch( const Args&... args ); \
									\
  private:								\
    inline list<int> e( const int& t );					\
									\
  };									\
									\
  template <int V_max,list<int> E(const int&)> void BREADTH ## FirstConnectedComponent( const int& V , int ( &vertex )[V_max] , int& count ); \

#define DEFINITION_OF_FIRST_SEARCH( BREADTH , PUSH )			\
  template <int V_max> inline BREADTH ## FirstSearch_Body<V_max>::BREADTH ## FirstSearch_Body( const int& V ) : m_V( V ) , m_init() , m_next() , m_found() , m_prev() { assert( m_V <= V_max ); for( int i = 0 ; i < m_V ; i++ ){ m_prev[i] = -1; } } \
  template <int V_max> inline BREADTH ## FirstSearch_Body<V_max>::BREADTH ## FirstSearch_Body( const int& V , const int& init ) : BREADTH ## FirstSearch_Body( V ) { m_init = init; m_next.push_back( m_init ); m_found[m_init] = true; } \
  template <int V_max,list<int> E(const int&)> template <typename... Args> inline BREADTH ## FirstSearch<V_max,E>::BREADTH ## FirstSearch( const Args&... args ) : BREADTH ## FirstSearch_Body<V_max>( args... ) {} \
									\
  template <int V_max> inline void BREADTH ## FirstSearch_Body<V_max>::Reset( const int& init ) { m_init = init; assert( m_init < m_V ); m_next.clear(); m_next.push_back( m_init ); for( int i = 0 ; i < m_V ; i++ ){ m_found[i] = i == m_init; m_prev[i] = -1; } } \
  template <int V_max> inline void BREADTH ## FirstSearch_Body<V_max>::Shift( const int& init ) { m_init = init; assert( m_init < m_V ); m_next.clear(); if( ! m_found[m_init] ){ m_next.push_back( m_init ); m_found[m_init] = true; } } \
									\
  template <int V_max> inline const int& BREADTH ## FirstSearch_Body<V_max>::size() const { return m_V; } \
  template <int V_max> inline const int& BREADTH ## FirstSearch_Body<V_max>::init() const { return m_init; } \
  template <int V_max> inline bool& BREADTH ## FirstSearch_Body<V_max>::found( const int& i ) { assert( i < m_V ); return m_found[i]; } \
  template <int V_max> inline const int& BREADTH ## FirstSearch_Body<V_max>::prev( const int& i ) const { assert( i < m_V ); return m_prev[i]; } \
									\
  template <int V_max>							\
  int BREADTH ## FirstSearch_Body<V_max>::Next()			\
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
    list<int> edge = e( i_curr );					\
									\
    while( ! edge.empty() ){						\
									\
      const int& i = edge.front();					\
      bool& found_i = found( i );					\
									\
      if( ! found_i ){							\
									\
	m_next.PUSH( i );						\
	m_prev[i] = i_curr;						\
	found_i = true;							\
									\
      }									\
									\
      edge.pop_front();							\
									\
    }									\
									\
    return i_curr;							\
									\
  }									\
									\
  template <int V_max,list<int> E(const int&)> inline list <int> BREADTH ## FirstSearch<V_max,E>::e( const int& t ) { return E( t ); } \
									\
  template <int V_max,list<int> E(const int&)> void BREADTH ## FirstConnectedComponentSearch( const int& V , int ( &vertex )[V_max] , int& count ) \
  {									\
									\
    BREADTH ## FirstSearch<V_max,E> bfs{ V };				\
    count = 0;								\
									\
    for( int i = 0 ; i < V ; i++ ){					\
									\
      vertex[i] = -1;							\
									\
    }									\
									\
    for( int i = 0 ; i < V ; i++ ){					\
									\
      if( vertex[i] == -1 ){						\
									\
	bfs.Shift( i );							\
	int j = bfs.Next();						\
									\
	while( j != -1 ? vertex[j] == 0 : false ){			\
									\
	  vertex[j] = count;						\
	  j = bfs.Next();						\
									\
	}								\
									\
	count++;							\
									\
      }									\
									\
    }									\
									\
    return;								\
									\
  }									\


