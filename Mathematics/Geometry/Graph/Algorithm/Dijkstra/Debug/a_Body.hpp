// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../a_Body.hpp"
#include "../../../../../Algebra/Monoid/a_Body.hpp"

template <typename T , typename GRAPH , typename U , typename COMM_MONOID> inline AbstractDijkstra<T,GRAPH,U,COMM_MONOID>::AbstractDijkstra( GRAPH& G , COMM_MONOID M , const U& infty ) : PointedSet<U>( infty ) , m_G( G ) , m_M( move( M ) )
{

  static bool init = true;
  static U infty_prev{};

  if( init ){

    cerr << "Dijkstraをデバッグモードで実行します。" << endl;
    cerr << "マクロが展開されるだけなのでファイルサイズとエラー出力以外は変わりません。" << endl;
    cerr << "infty = " << infty << "と定義されています。" << endl;
    infty_prev = infty;
    init = false;

  } else if( infty_prev != infty ){
    
    cerr << "Dijkstraをデバッグモードで再実行しますが、" << endl;
    cerr << "infty = " << infty << "に定義が変更されました。" << endl;
    infty_prev = infty;

  }

}

template <typename T , typename GRAPH> inline Dijkstra<T,GRAPH>::Dijkstra( GRAPH& G , const ll& infty ) : AbstractDijkstra<T,GRAPH,ll,AdditiveMonoid<>>( G , AdditiveMonoid<>() , infty ) {}

template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
U AbstractDijkstra<T,GRAPH,U,COMM_MONOID>::GetDistance( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> fixed( size );
  auto&& i_final = m_G.Enumeration_inv( t_final );
  // VVV DIJKSTRA_BODY( , if( i == i_final ){ break; } , );
  const U& one = m_M.One();
  assert( one < infty );
  auto&& i_start = m_G.Enumeration_inv( t_start );
  assert( 0 <= i_start && i_start < size );
  // INITIALISE_PREV;

  if( many_edges ){

    if( path_length == -1 ){

      path_length = size - 1;

    }

    weight[i_start] = one;
    int i = i_start;

    for( int num = 0 ; num < path_length ; num++ ){

      const U& weight_i = weight[i];
      fixed[i] = true;
      auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );

      for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

	auto&& j = m_G.Enumeration_inv( itr->first );

	if( !fixed[j] ){

	  const U& edge_ij = get<1>( *itr );
	  U temp = m_M.Product( weight_i , edge_ij );
	  assert( temp < infty );
	  U& weight_j = weight[j];

	  if( temp < weight_j ){

	    // SET_PREV;
	    weight_j = move( temp );

	  }

	}

      }

      U temp = infty;

      for( int j = 0 ; j < size ; j++ ){

	if( !fixed[j] ){

	  U& weight_j = weight[j];

	  if( weight_j < temp ){

	    temp = weight_j;
	    i = j;

	  }

	}

      }

    }

  } else {

    assert( path_length == -1 );
    set<pair<U,int>> vertex{};
    vertex.insert( pair<U,int>( weight[i_start] = one , i_start ) );

    while( ! vertex.empty() ){

      auto begin = vertex.begin();
      auto [weight_i,i] = *begin;
      if( i == i_final ){ break; } // CHECK_FINAL;
      fixed[i] = true;
      vertex.erase( begin );
      auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );
      vector<pair<U,int>> changed_vertex{};

      for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

	auto&& j = m_G.Enumeration_inv( itr->first );

	if( !fixed[j] ){

	  const U& edge_ij = get<1>( *itr );
	  U temp = m_M.Product( weight_i , edge_ij );
	  assert( temp < infty );
	  U& weight_j = weight[j];

	  if( temp < weight_j ){

	    if( weight_j != infty ){

	      vertex.erase( pair<U,int>( weight_j , j ) );

	    }

	    // SET_PREV;
	    changed_vertex.push_back( pair<U,int>( weight_j = move( temp ) , j ) );

	  }

	}

      }

      for( auto& v : changed_vertex ){

	vertex.insert( v );

      }

    }

  }
  // AAA DIJKSTRA_BODY( , if( i == i_final ){ break; } , );
  U answer{ move( weight[i_final] ) };
  cerr << "Dijkstra::GetDistance( t_start = " << t_start << " , t_final = " << t_final << " , many_edges = " << many_edges << " , path_length = " << path_length << " )の実行結果：" << endl;
  cerr << "answer = " << answer << endl;
  return answer;

}

template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
vector<U> AbstractDijkstra<T,GRAPH,U,COMM_MONOID>::GetDistance( const inner_t<GRAPH>& t_start , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> fixed( size );
  // VVV DIJKSTRA_BODY( , , );
  const U& one = m_M.One();
  assert( one < infty );
  auto&& i_start = m_G.Enumeration_inv( t_start );
  assert( 0 <= i_start && i_start < size );
  // INITIALISE_PREV;

  if( many_edges ){

    if( path_length == -1 ){

      path_length = size - 1;

    }

    weight[i_start] = one;
    int i = i_start;

    for( int num = 0 ; num < path_length ; num++ ){

      const U& weight_i = weight[i];
      fixed[i] = true;
      auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );

      for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

	auto&& j = m_G.Enumeration_inv( itr->first );

	if( !fixed[j] ){

	  const U& edge_ij = get<1>( *itr );
	  U temp = m_M.Product( weight_i , edge_ij );
	  assert( temp < infty );
	  U& weight_j = weight[j];

	  if( temp < weight_j ){

	    // SET_PREV;
	    weight_j = move( temp );

	  }

	}

      }

      U temp = infty;

      for( int j = 0 ; j < size ; j++ ){

	if( !fixed[j] ){

	  U& weight_j = weight[j];

	  if( weight_j < temp ){

	    temp = weight_j;
	    i = j;

	  }

	}

      }

    }

  } else {

    assert( path_length == -1 );
    set<pair<U,int>> vertex{};
    vertex.insert( pair<U,int>( weight[i_start] = one , i_start ) );

    while( ! vertex.empty() ){

      auto begin = vertex.begin();
      auto [weight_i,i] = *begin;
      // CHECK_FINAL;
      fixed[i] = true;
      vertex.erase( begin );
      auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );
      vector<pair<U,int>> changed_vertex{};

      for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

	auto&& j = m_G.Enumeration_inv( itr->first );

	if( !fixed[j] ){

	  const U& edge_ij = get<1>( *itr );
	  U temp = m_M.Product( weight_i , edge_ij );
	  assert( temp < infty );
	  U& weight_j = weight[j];

	  if( temp < weight_j ){

	    if( weight_j != infty ){

	      vertex.erase( pair<U,int>( weight_j , j ) );

	    }

	    // SET_PREV;
	    changed_vertex.push_back( pair<U,int>( weight_j = move( temp ) , j ) );

	  }

	}

      }

      for( auto& v : changed_vertex ){

	vertex.insert( v );

      }

    }

  }
  // AAA DIJKSTRA_BODY( , , );
  cerr << "Dijkstra::GetDistance( t_start = " << t_start << " , many_edges = " << many_edges << " , path_length = " << path_length << " )の実行結果：" << endl;
  cerr << "weight = ( " << weight << " )" << endl;
  return weight;

}

template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
void AbstractDijkstra<T,GRAPH,U,COMM_MONOID>::SetDistance( vector<U>& weight , vector<bool>& fixed , const inner_t<GRAPH>& t_start , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  assert( int( weight.size() ) == size );
  assert( int( fixed.size() ) == size );
  // VVV DIJKSTRA_BODY( , , );
  const U& one = m_M.One();
  assert( one < infty );
  auto&& i_start = m_G.Enumeration_inv( t_start );
  assert( 0 <= i_start && i_start < size );
  // INITIALISE_PREV;

  if( many_edges ){

    if( path_length == -1 ){

      path_length = size - 1;

    }

    weight[i_start] = one;
    int i = i_start;

    for( int num = 0 ; num < path_length ; num++ ){

      const U& weight_i = weight[i];
      fixed[i] = true;
      auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );

      for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

	auto&& j = m_G.Enumeration_inv( itr->first );

	if( !fixed[j] ){

	  const U& edge_ij = get<1>( *itr );
	  U temp = m_M.Product( weight_i , edge_ij );
	  assert( temp < infty );
	  U& weight_j = weight[j];

	  if( temp < weight_j ){

	    // SET_PREV;
	    weight_j = move( temp );

	  }

	}

      }

      U temp = infty;

      for( int j = 0 ; j < size ; j++ ){

	if( !fixed[j] ){

	  U& weight_j = weight[j];

	  if( weight_j < temp ){

	    temp = weight_j;
	    i = j;

	  }

	}

      }

    }

  } else {

    assert( path_length == -1 );
    set<pair<U,int>> vertex{};
    vertex.insert( pair<U,int>( weight[i_start] = one , i_start ) );

    while( ! vertex.empty() ){

      auto begin = vertex.begin();
      auto [weight_i,i] = *begin;
      // CHECK_FINAL;
      fixed[i] = true;
      vertex.erase( begin );
      auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );
      vector<pair<U,int>> changed_vertex{};

      for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

	auto&& j = m_G.Enumeration_inv( itr->first );

	if( !fixed[j] ){

	  const U& edge_ij = get<1>( *itr );
	  U temp = m_M.Product( weight_i , edge_ij );
	  assert( temp < infty );
	  U& weight_j = weight[j];

	  if( temp < weight_j ){

	    if( weight_j != infty ){

	      vertex.erase( pair<U,int>( weight_j , j ) );

	    }

	    // SET_PREV;
	    changed_vertex.push_back( pair<U,int>( weight_j = move( temp ) , j ) );

	  }

	}

      }

      for( auto& v : changed_vertex ){

	vertex.insert( v );

      }

    }

  }
  // AAA DIJKSTRA_BODY( , , );
  return;

}

template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
pair<U,list<inner_t<GRAPH>>> AbstractDijkstra<T,GRAPH,U,COMM_MONOID>::GetPath( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> fixed( size );
  auto&& i_final = m_G.Enumeration_inv( t_final );
  // VVV DIJKSTRA_BODY( vector<int> prev( size ) , if( i == i_final ){ break; } , prev[j] = i );
  const U& one = m_M.One();
  assert( one < infty );
  auto&& i_start = m_G.Enumeration_inv( t_start );
  assert( 0 <= i_start && i_start < size );
  vector<int> prev( size ); // INITIALISE_PREV;

  if( many_edges ){

    if( path_length == -1 ){

      path_length = size - 1;

    }

    weight[i_start] = one;
    int i = i_start;

    for( int num = 0 ; num < path_length ; num++ ){

      const U& weight_i = weight[i];
      fixed[i] = true;
      auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );

      for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

	auto&& j = m_G.Enumeration_inv( itr->first );

	if( !fixed[j] ){

	  const U& edge_ij = get<1>( *itr );
	  U temp = m_M.Product( weight_i , edge_ij );
	  assert( temp < infty );
	  U& weight_j = weight[j];

	  if( temp < weight_j ){

	    prev[j] = i; // SET_PREV;
	    weight_j = move( temp );

	  }

	}

      }

      U temp = infty;

      for( int j = 0 ; j < size ; j++ ){

	if( !fixed[j] ){

	  U& weight_j = weight[j];

	  if( weight_j < temp ){

	    temp = weight_j;
	    i = j;

	  }

	}

      }

    }

  } else {

    assert( path_length == -1 );
    set<pair<U,int>> vertex{};
    vertex.insert( pair<U,int>( weight[i_start] = one , i_start ) );

    while( ! vertex.empty() ){

      auto begin = vertex.begin();
      auto [weight_i,i] = *begin;
      if( i == i_final ){ break; } // CHECK_FINAL;
      fixed[i] = true;
      vertex.erase( begin );
      auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );
      vector<pair<U,int>> changed_vertex{};

      for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

	auto&& j = m_G.Enumeration_inv( itr->first );

	if( !fixed[j] ){

	  const U& edge_ij = get<1>( *itr );
	  U temp = m_M.Product( weight_i , edge_ij );
	  assert( temp < infty );
	  U& weight_j = weight[j];

	  if( temp < weight_j ){

	    if( weight_j != infty ){

	      vertex.erase( pair<U,int>( weight_j , j ) );

	    }

	    prev[j] = i; // SET_PREV;
	    changed_vertex.push_back( pair<U,int>( weight_j = move( temp ) , j ) );

	  }

	}

      }

      for( auto& v : changed_vertex ){

	vertex.insert( v );

      }

    }

  }
  // AAA DIJKSTRA_BODY( vector<int> prev( size ) , if( i == i_final ){ break; } , prev[j] = i );
  int i = i_final;
  list<inner_t<GRAPH>> path{};
  path.push_back( t_final );

  if( weight[i] != infty ){

    while( i != i_start ){

      i = prev[i];
      path.push_front( m_G.Enumeration( i ) );

    }

  }

  U answer{ move( weight[i_final] ) };
  cerr << "Dijkstra::GetPath( t_start = " << t_start << " , t_final = " << t_final << " , many_edges = " << many_edges << " , path_length = " << path_length << " )の実行結果：" << endl;
  cerr << "answer = " << answer << endl;
  cerr << "path = ( " << path << " )" << endl;
  return { move( answer ) , move( path ) };

}

template <typename T , typename GRAPH , typename U , typename COMM_MONOID> template <template <typename...> typename V> 
pair<vector<U>,vector<list<inner_t<GRAPH>>>> AbstractDijkstra<T,GRAPH,U,COMM_MONOID>::GetPath( const inner_t<GRAPH>& t_start , const V<inner_t<GRAPH>>& t_finals , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> fixed( size );
  // VVV DIJKSTRA_BODY( vector<int> prev( size ) , , prev[j] = i );
  const U& one = m_M.One();
  assert( one < infty );
  auto&& i_start = m_G.Enumeration_inv( t_start );
  assert( 0 <= i_start && i_start < size );
  vector<int> prev( size ); // INITIALISE_PREV;

  if( many_edges ){

    if( path_length == -1 ){

      path_length = size - 1;

    }

    weight[i_start] = one;
    int i = i_start;

    for( int num = 0 ; num < path_length ; num++ ){

      const U& weight_i = weight[i];
      fixed[i] = true;
      auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );

      for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

	auto&& j = m_G.Enumeration_inv( itr->first );

	if( !fixed[j] ){

	  const U& edge_ij = get<1>( *itr );
	  U temp = m_M.Product( weight_i , edge_ij );
	  assert( temp < infty );
	  U& weight_j = weight[j];

	  if( temp < weight_j ){

	    prev[j] = i; // SET_PREV;
	    weight_j = move( temp );

	  }

	}

      }

      U temp = infty;

      for( int j = 0 ; j < size ; j++ ){

	if( !fixed[j] ){

	  U& weight_j = weight[j];

	  if( weight_j < temp ){

	    temp = weight_j;
	    i = j;

	  }

	}

      }

    }

  } else {

    assert( path_length == -1 );
    set<pair<U,int>> vertex{};
    vertex.insert( pair<U,int>( weight[i_start] = one , i_start ) );

    while( ! vertex.empty() ){

      auto begin = vertex.begin();
      auto [weight_i,i] = *begin;
      // CHECK_FINAL;
      fixed[i] = true;
      vertex.erase( begin );
      auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );
      vector<pair<U,int>> changed_vertex{};

      for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

	auto&& j = m_G.Enumeration_inv( itr->first );

	if( !fixed[j] ){

	  const U& edge_ij = get<1>( *itr );
	  U temp = m_M.Product( weight_i , edge_ij );
	  assert( temp < infty );
	  U& weight_j = weight[j];

	  if( temp < weight_j ){

	    if( weight_j != infty ){

	      vertex.erase( pair<U,int>( weight_j , j ) );

	    }

	    prev[j] = i; // SET_PREV;
	    changed_vertex.push_back( pair<U,int>( weight_j = move( temp ) , j ) );

	  }

	}

      }

      for( auto& v : changed_vertex ){

	vertex.insert( v );

      }

    }

  }
  // AAA DIJKSTRA_BODY( vector<int> prev( size ) , , prev[j] = i );
  const int path_size = t_finals.size();
  vector<list<inner_t<GRAPH>>> path;
  path.reserve( path_size );

  for( auto itr = t_finals.begin() , end = t_finals.end() ; itr != end ; itr++ ){

    list<inner_t<GRAPH>> path_j{};
    const inner_t<GRAPH>& t_final = *itr;
    path_j.push_back( t_final );
    int i = m_G.Enumeration_inv( t_final );

    if( weight[i] != infty ){

      while( i != i_start ){

	i = prev[i];
	path_j.push_front( m_G.Enumeration( i ) );

      }

    }

    path.push_back( path_j );

  }

  cerr << "Dijkstra::GetPath( t_start = " << t_start << " , t_finals = ( " << t_finals << " ) , many_edges = " << many_edges << " , path_length = " << path_length << " )の実行結果：" << endl;
  cerr << "weight = ( " << weight << " )" << endl;
  cerr << "path = ( " << path << " )" << endl;
  return { move( weight ) , move( path ) };

}

template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
pair<vector<U>,vector<list<inner_t<GRAPH>>>> AbstractDijkstra<T,GRAPH,U,COMM_MONOID>::GetPath( const inner_t<GRAPH>& t_start , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  vector<inner_t<GRAPH>> t_finals( size );

  for( int i = 0 ; i < size ; i++ ){

    t_finals[i] = i;

  }

  return GetPath( t_start , t_finals , many_edges , path_length );

}
