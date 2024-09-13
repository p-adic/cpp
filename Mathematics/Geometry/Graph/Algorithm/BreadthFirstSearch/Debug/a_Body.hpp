// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../a_Body.hpp"
#include "../../../../../../Utility/Set/Map/a_Body.hpp"

template <typename T , typename GRAPH> inline VirtualBreadthFirstSearch<T,GRAPH>::VirtualBreadthFirstSearch( GRAPH& G , const T& not_found ) : m_G( G ) , m_not_found( not_found ) , m_initialised( false ) , m_next() , m_found() , m_prev()
{

  static_assert( is_same_v<inner_t<GRAPH>,T> );
  const int& V = m_G.size();
  DEBUG_OUTPUT << "幅／深さ探索優先探索をデバッグモードで実行します。" << endl;
  DEBUG_OUTPUT << "各探索ステップの計算量がO(V)追加されることに注意してください。" << endl;
  DEBUG_OUTPUT << "グラフの頂点数Vは" << V << "です。" << endl;

  bool empty = true;

  for( int i = 0 ; i < V ; i++ ){

    auto&& t = m_G.Enumeration( i );

    for( auto&& u : m_G.Edge( t ) ){

      if( empty ){

	empty = false;
	DEBUG_OUTPUT << "有向辺が" << endl;

      }

      DEBUG_OUTPUT << t << " -> " << m_G.Vertex( u ) << endl;

    }

  }

  if( empty ){

    DEBUG_OUTPUT << "有向辺が1本もありません。" << endl;

  } else {

    DEBUG_OUTPUT << "と貼られています。" << endl;

  }
  
  DEBUG_OUTPUT << endl;

}

template <typename T , typename GRAPH> template <typename Arg> inline VirtualBreadthFirstSearch<T,GRAPH>::VirtualBreadthFirstSearch( GRAPH& G , const T& not_found , Arg&& init ) : VirtualBreadthFirstSearch<T,GRAPH>( G , not_found ) { Initialise( forward<Arg>( init ) ); }

template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Initialise()
{

  m_initialised = true;
  const int& V = size();
  DEBUG_OUTPUT << "行番号: " << __LINE__ << endl;
  DEBUG_OUTPUT << "幅／深さ探索優先探索を初期化します。" << endl;

  if( ! m_next.empty() ){

    DEBUG_OUTPUT << "訪問予定の頂点リストを削除しました。" << endl;
    DEBUG_OUTPUT << endl;
    m_next.clear();

  }
  
  m_found = vector<bool>( V );
  m_prev = vector<T>( V , m_not_found );

}

template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Initialise( const T& init )
{

  auto&& i = m_G.Enumeration_inv( init );
  const int& V = size();
  assert( 0 <= i && i < V );
  DEBUG_OUTPUT << "行番号: " << __LINE__ << endl;
  DEBUG_OUTPUT << "-> ";
  Initialise();
  m_next.push_back( init );
  m_found[i] = true;
  DEBUG_OUTPUT << "訪問予定の頂点リストに" << init << "を追加しました。" << endl;
  DEBUG_OUTPUT << "訪問予定の頂点リスト: " << m_next << endl;
  DEBUG_OUTPUT << "訪問予定に追加済みの頂点リスト:";

  for( int j = 0 ; j < V ; j++ ){

    m_found[j] ? ( DEBUG_OUTPUT << " " << m_G.Enumeration( j ) ) : DEBUG_OUTPUT;

  }
  
  DEBUG_OUTPUT << endl;
  DEBUG_OUTPUT << endl;

}

template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Initialise( list<T> inits )
{

  DEBUG_OUTPUT << "行番号: " << __LINE__ << endl;
  DEBUG_OUTPUT << "-> ";
  Initialise();
  m_next = move( inits );
  const int& V = size();

  for( auto& u : m_next ){

    auto&& i = m_G.Enumeration_inv( u );
    assert( 0 <= i && i < V );
    m_found[i] = true;

  }

  DEBUG_OUTPUT << "訪問予定の頂点リストに" << inits << "を追加しました。" << endl;
  DEBUG_OUTPUT << "訪問予定の頂点リスト: " << m_next << endl;
  DEBUG_OUTPUT << "訪問予定に追加済みの頂点リスト:";

  for( int j = 0 ; j < V ; j++ ){

    m_found[j] ? ( DEBUG_OUTPUT << " " << m_G.Enumeration( j ) ) : DEBUG_OUTPUT;

  }
  
  DEBUG_OUTPUT << endl;
  DEBUG_OUTPUT << endl;

}

template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Shift( const T& init )
{

  if( m_initialised ){

    const int& V = size();
    auto&& i = m_G.Enumeration_inv( init );
    assert( 0 <= i && i < V );
    m_next.clear();
    DEBUG_OUTPUT << "行番号: " << __LINE__ << endl;

    if( m_found[i] ){

      DEBUG_OUTPUT << "訪問予定の頂点リストを削除しました。" << endl;
      DEBUG_OUTPUT << "訪問予定の頂点リスト: " << m_next << endl;

    } else {
      
      m_next.push_back( init );
      m_found[i] = true;
      DEBUG_OUTPUT << "訪問予定の頂点リストを削除し" << init << "を追加しました。" << endl;
      DEBUG_OUTPUT << "訪問予定の頂点リスト: " << m_next << endl;
      DEBUG_OUTPUT << "訪問予定に追加済みの頂点リスト:";

      for( int j = 0 ; j < V ; j++ ){

	m_found[j] ? ( DEBUG_OUTPUT << " " << m_G.Enumeration( j ) ) : DEBUG_OUTPUT;

      }
  
      DEBUG_OUTPUT << endl;

    }

    DEBUG_OUTPUT << endl;

  } else {

    DEBUG_OUTPUT << "行番号: " << __LINE__ << endl;
    DEBUG_OUTPUT << "-> ";
    Initialise( init );

  }

}

template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Shift( list<T> inits )
{

  if( m_initialised ){

    m_next.clear();
    const int& V = size();
    DEBUG_OUTPUT << "行番号: " << __LINE__ << endl;

    for( auto& u : m_next ){

      auto&& i = m_G.Enumeration_inv( u );
      assert( 0 <= i && i < V );

      if( ! m_found[i] ){

	m_next.push_back( u );
	m_found[i] = true;

      }

    }

    if( m_next.empty() ){

      DEBUG_OUTPUT << "行番号: " << __LINE__ << endl;
      DEBUG_OUTPUT << "訪問予定の頂点リストを削除しました。" << endl;
      DEBUG_OUTPUT << "訪問予定の頂点リスト:" << m_next << endl;

    } else {
      
      DEBUG_OUTPUT << "行番号: " << __LINE__ << endl;
      DEBUG_OUTPUT << "訪問予定の頂点リストを削除し";

      for( auto begin = m_next.begin() , itr = begin , end = m_next.end() ; itr != end ; itr++ ){

	( itr == begin ? DEBUG_OUTPUT : DEBUG_OUTPUT << ", " ) << *itr;

      }

      DEBUG_OUTPUT << "を追加しました。" << endl;
      DEBUG_OUTPUT << "訪問予定に追加済みの頂点リスト:";

      for( int j = 0 ; j < V ; j++ ){

	m_found[j] ? ( DEBUG_OUTPUT << " " << m_G.Enumeration( j ) ) : DEBUG_OUTPUT;

      }
  
      DEBUG_OUTPUT << endl;

    }

    DEBUG_OUTPUT << endl;

  } else {

    DEBUG_OUTPUT << "行番号: " << __LINE__ << endl;
    Initialise( move( inits ) );

  }

}

template <typename T , typename GRAPH> inline const int& VirtualBreadthFirstSearch<T,GRAPH>::size() const noexcept { return m_G.size(); }
template <typename T , typename GRAPH> inline vector<bool>::reference VirtualBreadthFirstSearch<T,GRAPH>::found( const T& t ) { auto&& i = m_G.Enumeration_inv( t ); assert( 0 <= i && i < size() ); if( !m_initialised ){ Initialise(); } return m_found[i]; }
template <typename T , typename GRAPH> inline const T& VirtualBreadthFirstSearch<T,GRAPH>::prev( const T& t ) { auto&& i = m_G.Enumeration_inv( t ); assert( 0 <= i && i < size() ); if( !m_initialised ){ Initialise(); } return m_prev[i]; }

template <typename T , typename GRAPH> inline T VirtualBreadthFirstSearch<T,GRAPH>::Next()
{

  if( m_next.empty() ){

    return m_not_found;

  }

  const T t_curr = m_next.front();
  m_next.pop_front();
  vector<T> new_next{};

  for( auto& t : m_G.Edge( t_curr ) ){

    auto&& i = m_G.Enumeration_inv( t );
    auto&& found_i = m_found[i];

    if( ! found_i ){

      Push( m_next , t );
      m_prev[i] = t_curr;
      found_i = true;
      new_next.push_back( t );

    }

  }

  if( new_next.empty() ){

    DEBUG_OUTPUT << "行番号: " << __LINE__ << endl;
    DEBUG_OUTPUT << "訪問予定の頂点リストから" << t_curr << "を取り出しました。" << endl;
    DEBUG_OUTPUT << "訪問予定の頂点リスト: " << m_next << endl;

  } else {
    
    DEBUG_OUTPUT << "行番号: " << __LINE__ << endl;
    DEBUG_OUTPUT << "訪問予定の頂点リストから" << t_curr << "を取り出し";

    for( auto begin = new_next.begin() , itr = begin , end = new_next.end() ; itr != end ; itr++ ){

      ( itr == begin ? DEBUG_OUTPUT : DEBUG_OUTPUT << ", " ) << *itr;

    }

    DEBUG_OUTPUT << "を追加しました。" << endl;
    DEBUG_OUTPUT << "訪問予定の頂点リスト: " << m_next << endl;
    DEBUG_OUTPUT << "訪問予定に追加済みの頂点リスト:";
    const int& V = size();
  
    for( int j = 0 ; j < V ; j++ ){

      m_found[j] ? ( DEBUG_OUTPUT << " " << m_G.Enumeration( j ) ) : DEBUG_OUTPUT;

    }
  
    DEBUG_OUTPUT << endl;

  }
  
  DEBUG_OUTPUT << endl;
  return t_curr;

}

template <typename T , typename GRAPH> template <typename U>
auto VirtualBreadthFirstSearch<T,GRAPH>::GetDistance() -> enable_if_t<is_same_v<GRAPH,MemorisationGraph<U,decldecay_t(declval<GRAPH>().edge())>>,Map<T,int>>
{

  Map<T,int> answer{};

  for( auto itr = m_next.begin() , end = m_next.end() ; itr != end ; itr++ ){

    answer[*itr] = 0;

  }
  
  T t;
  
  while( ( t = Next() ) != m_not_found ){

    if( answer.count( t ) == 0 ){
      
      answer[t] = answer[m_prev[m_G.Enumeration_inv( t )]] + 1;

    }

  }

  return answer;
  
}

template <typename T , typename GRAPH> template <typename U>
auto VirtualBreadthFirstSearch<T,GRAPH>::GetDistance() -> enable_if_t<!is_same_v<GRAPH,MemorisationGraph<U,decldecay_t(declval<GRAPH>().edge())>>,vector<int>>
{

  vector answer( size() , -1 );

  for( auto itr = m_next.begin() , end = m_next.end() ; itr != end ; itr++ ){

    answer[m_G.Enumeration_inv( *itr )] = 0;

  }
  
  T t;
  
  while( ( t = Next() ) != m_not_found ){

    auto&& i = m_G.Enumeration_inv( t );
    int& answer_i = answer[i];
    answer_i == -1 ? answer_i = answer[m_G.Enumeration_inv( m_prev[i] )] + 1 : answer_i;

  }

  return answer;
  
}

template <typename T , typename GRAPH>
pair<vector<int>,int> VirtualBreadthFirstSearch<T,GRAPH>::GetConnectedComponent()
{

  static_assert( !is_same_v<GRAPH,MemorisationGraph<T,decldecay_t( m_G.edge() )>> );
  const int& V = size();
  vector cc_num( V , -1 );
  int count = 0;

  for( int i = 0 ; i < V ; i++ ){

    if( cc_num[i] == -1 ){

      Shift( m_G.Enumeration( i ) );
      T t = Next();

      if( t != m_not_found ){

	while( t != m_not_found ){

	  cc_num[m_G.Enumeration_inv( t )] = count;
	  t = Next();

	}

	count++;

      }

    }

  }

  return { move( cc_num ) , move( count ) };

}


template <typename T , typename GRAPH>
vector<T> VirtualBreadthFirstSearch<T,GRAPH>::GetNodeEnumeration()
{

  vector<T> answer{};
  T t = Next();

  while( t != m_not_found ){

    answer.push_back( t );
    t = Next();
    
  }

  return answer;

}

template <typename T , typename GRAPH>
vector<T> VirtualBreadthFirstSearch<T,GRAPH>::GetReversedNodeEnumeration()
{

  vector<T> answer{};
  vector<T> next{};
  T t;
  bool searched;

  while( !( searched = ( t = Next() ) == m_not_found ) || !next.empty() ){

    while( !next.empty() && ( searched || next.back() != m_prev[m_G.Enumeration_inv( t )] ) ){

      answer.push_back( next.back() );
      next.pop_back();

    }

    if( !searched ){
      
      next.push_back( t );

    }
    
  }

  return answer;

}

template <typename T , typename GRAPH> template <typename PATH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Push( list<T>& next , const PATH& p ) { Push( next , get<0>( p ) ); }

template <typename T , typename GRAPH> template <typename...Args> inline BreadthFirstSearch<T,GRAPH>::BreadthFirstSearch( GRAPH& G , const T& not_found , Args&&... args ) : VirtualBreadthFirstSearch<T,GRAPH>( G , not_found , forward<Args>( args )... ) {}
template <typename T , typename GRAPH> inline void BreadthFirstSearch<T,GRAPH>::Push( list<T>& next , const T& t ) { next.push_back( t ); }
