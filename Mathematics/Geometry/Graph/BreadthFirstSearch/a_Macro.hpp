// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/a_Macro.hpp

#pragma once

// Resetはm_foundとm_prevを初期化
// Shiftはm_foundとm_prevを非初期化
// Breadth/DepthFirstConnectedComponentSearchは無向グラフの連結成分を色分け＆数え上げ

// Next()の反復でm_initから到達可能な頂点を全探索。
// 計算量O((m_initの連結成分)+(m_initの連結成分におけるEのサイズの合計))
#define DECLARATION_OF_FIRST_SEARCH( BREADTH )				\
  class BREADTH ## FirstSearch_Body					\
  {									\
									\
  protected:								\
    int m_V;								\
    int m_init;								\
    list<int> m_next;							\
    vector<bool> m_found;						\
    vector<int> m_prev;							\
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
    inline vector<bool>::reference found( const int& i );		\
    inline const int& prev( const int& i ) const;			\
									\
    inline int Next();								\
									\
  private:								\
    virtual list<int> e( const int& t ) = 0;				\
									\
  };									\
									\
  template <list<int> E(const int&)>				\
  class BREADTH ## FirstSearch :					\
    public BREADTH ## FirstSearch_Body				\
  {									\
									\
  public:								\
    template<typename... Args> inline BREADTH ## FirstSearch( const Args&... args ); \
									\
  private:								\
    inline list<int> e( const int& t );					\
									\
  };									\
									\
  template <list<int> E(const int&)> void BREADTH ## FirstConnectedComponentSearch( const int& V , vector<int>& cc_num , int& count ); \

#define DEFINITION_OF_FIRST_SEARCH( BREADTH , PUSH )			\
  inline BREADTH ## FirstSearch_Body::BREADTH ## FirstSearch_Body( const int& V ) : m_V( V ) , m_init() , m_next() , m_found( m_V ) , m_prev( m_V , -1 ) {} \
  inline BREADTH ## FirstSearch_Body::BREADTH ## FirstSearch_Body( const int& V , const int& init ) : BREADTH ## FirstSearch_Body( V ) { assert( init < m_V ); m_init = init; m_next.push_back( m_init ); m_found[m_init] = true; } \
  template <list<int> E(const int&)> template <typename... Args> inline BREADTH ## FirstSearch<E>::BREADTH ## FirstSearch( const Args&... args ) : BREADTH ## FirstSearch_Body( args... ) {} \
									\
  inline void BREADTH ## FirstSearch_Body::Reset( const int& init ) { m_init = init; assert( m_init < m_V ); m_next.clear(); m_next.push_back( m_init ); for( int i = 0 ; i < m_V ; i++ ){ m_found[i] = i == m_init; m_prev[i] = -1; } } \
  inline void BREADTH ## FirstSearch_Body::Shift( const int& init ) { m_init = init; assert( m_init < m_V ); m_next.clear(); if( ! m_found[m_init] ){ m_next.push_back( m_init ); m_found[m_init] = true; } } \
									\
  inline const int& BREADTH ## FirstSearch_Body::size() const { return m_V; } \
  inline const int& BREADTH ## FirstSearch_Body::init() const { return m_init; } \
  inline vector<bool>::reference& BREADTH ## FirstSearch_Body::found( const int& i ) { assert( i < m_V ); return m_found[i]; } \
  inline const int& BREADTH ## FirstSearch_Body::prev( const int& i ) const { assert( i < m_V ); return m_prev[i]; } \
									\
  inline int BREADTH ## FirstSearch_Body::Next()			\
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
      auto&& found_i = m_found[i];					\
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
  template <list<int> E(const int&)> inline list<int> BREADTH ## FirstSearch<E>::e( const int& t ) { return E( t ); } \
									\
  template <list<int> E(const int&)> void BREADTH ## FirstConnectedComponentSearch( const int& V , vector<int>& cc_num , int& count ) \
  {									\
									\
    BREADTH ## FirstSearch<E> bfs{ V };				\
    count = 0;								\
    cc_num = vector<int>( V , -1 );					\
									\
    for( int i = 0 ; i < V ; i++ ){					\
									\
      if( cc_num[i] == -1 ){						\
									\
	bfs.Shift( i );							\
	int j = bfs.Next();						\
									\
	while( j != -1 ? cc_num[j] == -1 : false ){			\
									\
	  cc_num[j] = count;						\
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


