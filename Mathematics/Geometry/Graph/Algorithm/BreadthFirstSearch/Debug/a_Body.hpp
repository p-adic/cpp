// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../a_Body.hpp"
#include "../../../../../../Utility/Set/Map/a_Body.hpp"

template <typename T , typename GRAPH> inline VirtualBreadthFirstSearch<T,GRAPH>::VirtualBreadthFirstSearch( GRAPH& G , const T& not_found ) : m_G( G ) , m_not_found( not_found ) , m_initialised( false ) , m_next() , m_found() , m_prev()
{

  static_assert( is_same_v<inner_t<GRAPH>,T> );
  const int& V = m_G.size();
  cerr << "•^[‚³’Tõ—Dæ’Tõ‚ðƒfƒoƒbƒOƒ‚[ƒh‚ÅŽÀs‚µ‚Ü‚·B" << endl;
  cerr << "Še’TõƒXƒeƒbƒv‚ÌŒvŽZ—Ê‚ªO(V)’Ç‰Á‚³‚ê‚é‚±‚Æ‚É’ˆÓ‚µ‚Ä‚­‚¾‚³‚¢B" << endl;
  cerr << "ƒOƒ‰ƒt‚Ì’¸“_”V‚Í" << V << "‚Å‚·B" << endl;

  bool empty = true;

  for( int i = 0 ; i < V ; i++ ){

    auto&& t = m_G.Enumeration( i );

    for( auto&& u : m_G.Edge( t ) ){

      if( empty ){

	empty = false;
	cerr << "—LŒü•Ó‚ª" << endl;

      }

      cerr << t << " -> " << m_G.Vertex( u ) << endl;

    }

  }

  if( empty ){

    cerr << "—LŒü•Ó‚ª1–{‚à‚ ‚è‚Ü‚¹‚ñB" << endl;

  } else {

    cerr << "‚Æ“\‚ç‚ê‚Ä‚¢‚Ü‚·B" << endl;

  }
  
  cerr << endl;

}

template <typename T , typename GRAPH> template <typename Arg> inline VirtualBreadthFirstSearch<T,GRAPH>::VirtualBreadthFirstSearch( GRAPH& G , const T& not_found , Arg&& init ) : VirtualBreadthFirstSearch<T,GRAPH>( G , not_found ) { Initialise( forward<Arg>( init ) ); }

template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Initialise()
{

  m_initialised = true;
  const int& V = size();
  cerr << "s”Ô†: " << __LINE__ << endl;
  cerr << "•^[‚³’Tõ—Dæ’Tõ‚ð‰Šú‰»‚µ‚Ü‚·B" << endl;

  if( ! m_next.empty() ){

    cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg‚ðíœ‚µ‚Ü‚µ‚½B" << endl;
    cerr << endl;
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
  cerr << "s”Ô†: " << __LINE__ << endl;
  cerr << "-> ";
  Initialise();
  m_next.push_back( init );
  m_found[i] = true;
  cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg‚É" << init << "‚ð’Ç‰Á‚µ‚Ü‚µ‚½B" << endl;
  cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg: " << m_next << endl;
  cerr << "–K–â—\’è‚É’Ç‰ÁÏ‚Ý‚Ì’¸“_ƒŠƒXƒg:";

  for( int j = 0 ; j < V ; j++ ){

    m_found[j] ? ( cerr << " " << m_G.Enumeration( j ) ) : cerr;

  }
  
  cerr << endl;
  cerr << endl;

}

template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Initialise( list<T> inits )
{

  cerr << "s”Ô†: " << __LINE__ << endl;
  cerr << "-> ";
  Initialise();
  m_next = move( inits );
  const int& V = size();

  for( auto& u : m_next ){

    auto&& i = m_G.Enumeration_inv( u );
    assert( 0 <= i && i < V );
    m_found[i] = true;

  }

  cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg‚É" << inits << "‚ð’Ç‰Á‚µ‚Ü‚µ‚½B" << endl;
  cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg: " << m_next << endl;
  cerr << "–K–â—\’è‚É’Ç‰ÁÏ‚Ý‚Ì’¸“_ƒŠƒXƒg:";

  for( int j = 0 ; j < V ; j++ ){

    m_found[j] ? ( cerr << " " << m_G.Enumeration( j ) ) : cerr;

  }
  
  cerr << endl;
  cerr << endl;

}

template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Shift( const T& init )
{

  if( m_initialised ){

    const int& V = size();
    auto&& i = m_G.Enumeration_inv( init );
    assert( 0 <= i && i < V );
    m_next.clear();
    cerr << "s”Ô†: " << __LINE__ << endl;

    if( m_found[i] ){

      cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg‚ðíœ‚µ‚Ü‚µ‚½B" << endl;
      cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg: " << m_next << endl;

    } else {
      
      m_next.push_back( init );
      m_found[i] = true;
      cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg‚ðíœ‚µ" << init << "‚ð’Ç‰Á‚µ‚Ü‚µ‚½B" << endl;
      cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg: " << m_next << endl;
      cerr << "–K–â—\’è‚É’Ç‰ÁÏ‚Ý‚Ì’¸“_ƒŠƒXƒg:";

      for( int j = 0 ; j < V ; j++ ){

	m_found[j] ? ( cerr << " " << m_G.Enumeration( j ) ) : cerr;

      }
  
      cerr << endl;

    }

    cerr << endl;

  } else {

    cerr << "s”Ô†: " << __LINE__ << endl;
    cerr << "-> ";
    Initialise( init );

  }

}

template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Shift( list<T> inits )
{

  if( m_initialised ){

    m_next.clear();
    const int& V = size();
    cerr << "s”Ô†: " << __LINE__ << endl;

    for( auto& u : m_next ){

      auto&& i = m_G.Enumeration_inv( u );
      assert( 0 <= i && i < V );

      if( ! m_found[i] ){

	m_next.push_back( u );
	m_found[i] = true;

      }

    }

    if( m_next.empty() ){

      cerr << "s”Ô†: " << __LINE__ << endl;
      cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg‚ðíœ‚µ‚Ü‚µ‚½B" << endl;
      cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg:" << m_next << endl;

    } else {
      
      cerr << "s”Ô†: " << __LINE__ << endl;
      cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg‚ðíœ‚µ";

      for( auto begin = m_next.begin() , itr = begin , end = m_next.end() ; itr != end ; itr++ ){

	( itr == begin ? cerr : cerr << ", " ) << *itr;

      }

      cerr << "‚ð’Ç‰Á‚µ‚Ü‚µ‚½B" << endl;
      cerr << "–K–â—\’è‚É’Ç‰ÁÏ‚Ý‚Ì’¸“_ƒŠƒXƒg:";

      for( int j = 0 ; j < V ; j++ ){

	m_found[j] ? ( cerr << " " << m_G.Enumeration( j ) ) : cerr;

      }
  
      cerr << endl;

    }

    cerr << endl;

  } else {

    cerr << "s”Ô†: " << __LINE__ << endl;
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

    cerr << "s”Ô†: " << __LINE__ << endl;
    cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg‚©‚ç" << t_curr << "‚ðŽæ‚èo‚µ‚Ü‚µ‚½B" << endl;
    cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg: " << m_next << endl;

  } else {
    
    cerr << "s”Ô†: " << __LINE__ << endl;
    cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg‚©‚ç" << t_curr << "‚ðŽæ‚èo‚µ";

    for( auto begin = new_next.begin() , itr = begin , end = new_next.end() ; itr != end ; itr++ ){

      ( itr == begin ? cerr : cerr << ", " ) << *itr;

    }

    cerr << "‚ð’Ç‰Á‚µ‚Ü‚µ‚½B" << endl;
    cerr << "–K–â—\’è‚Ì’¸“_ƒŠƒXƒg: " << m_next << endl;
    cerr << "–K–â—\’è‚É’Ç‰ÁÏ‚Ý‚Ì’¸“_ƒŠƒXƒg:";
    const int& V = size();
  
    for( int j = 0 ; j < V ; j++ ){

      m_found[j] ? ( cerr << " " << m_G.Enumeration( j ) ) : cerr;

    }
  
    cerr << endl;

  }
  
  cerr << endl;
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
