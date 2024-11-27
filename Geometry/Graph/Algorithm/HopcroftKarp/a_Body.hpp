// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/HopcroftKarp/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../BreadthFirst/a_Body.hpp"

template <typename Edge> vector<pair<int,int>> HopcroftKarp::GetMaximumMatching( const int& S , const int& T , Edge edge )
{

  static_assert( is_invocable_r_v<vector<int>,Edge,const int&> );
  unordered_set<int> unchosen_source{};
  vector<int> prev( T , -1 );
  
  for( int s = 0 ; s < S ; s++ ){

    unchosen_source.insert( s );

  }

  // BFSのコンストラクタに渡す。
  // (1) w=0の時は、未選択なSの頂点vectorを返す。
  // (2) 0<w<=Sの時は、s=w-1からの有向辺の終端全体のvectorを返す。
  // (3) S<w<=S+Tの時は、t=w-S-1が未選択ならば空vectorを返し、
  //     選択済みならば対応する有向辺の始端sのみからなるvectorを返す。
  auto edge_shifted = [&]( const int& w ){

    vector<int> answer{};
  
    if( w == 0 ){

      for( auto& us : unchosen_source ){

	answer.push_back( 1 + us );

      }

    } else if( w <= S ){

      auto&& edge_w = edge( w - 1 );
      answer.reserve( edge_w.size() );

      for( auto& t : edge_w ){

	answer.push_back( 1 + S + t );

      }

    } else {

      const int t = w - 1 - S;
      assert( t < T );
      const int& s = prev[t];

      if( s != -1 ){
      
	assert( 0 <= s && s < S );
	answer.push_back( 1 + s );

      }

    }

    return answer;

  };

  Graph graph{ 1 + S + T , move( edge_shifted ) };
  BreadthFirstSearch bfs{ graph , -1 };
  vector<bool> chosen_source( S );
  vector<bool> chosen_target( T );
  vector<unordered_map<int,bool>> chosen_edge( S );
  vector<int> depth( 1 + S + T );
  int depth_min = -1;
  vector<int> root( S + T );
  vector<int> new_chosen_target{ 0 };
  int v , w;
  bool found;
  
  while( ! new_chosen_target.empty() ){

    new_chosen_target.clear();
    bfs.Initialise( 0 );
    v = bfs.Next();
    found = false;
    
    while( ( v = bfs.Next() ) != -1 ){

      w = bfs.prev( v );
      int& depth_v = depth[v] = depth[w] + 1;
      
      if( found && depth_v > depth_min ){

	break;
      
      }

      if( w == 0 ){

	const int s = v - 1;
	assert( 0 <= s && s < S );
	root[s] = s;

      } else {

	root[v - 1] = root[w - 1];

      }

      if( ( depth_v & 1 ) == 0 ){

	const int t = v - 1 - S;
	assert( 0 <= t && t < T );
	auto&& chosen_target_t = chosen_target[t];
      
	if( !chosen_target_t ){

	  const int& s = root[v - 1];
	  assert( 0 <= s && s < S );
	  auto&& chosen_source_s = chosen_source[s];

	  if( !chosen_source_s ){

	    chosen_source_s = true;
	    chosen_target_t = true;
	    new_chosen_target.push_back( v );

	    if( !found ){

	      found = true;
	      depth_min = depth_v;

	    }

	  }

	}

      }

    }

    for( auto& nct : new_chosen_target ){

      int* p[2] = { &w , &v };
      int*& p0 = p[0];
      int*& p1 = p[1];
      v = nct;

      while( ( w = bfs.prev( v ) ) != 0 ){

	const int s = *p0 - 1;
	const int t = *p1 - 1 - S;
	assert( 0 <= s && s < S && 0 <= t && t < T );
	
	if( chosen_edge[s][t] ^= true ){

	  prev[t] = s;

	}
	
	swap( w , v );
	swap( p0 , p1 );

      }

      const int s = v - 1;
      assert( 0 <= s && s < S && unchosen_source.count( s ) == 1 );
      unchosen_source.erase( s );

    }

  }

  vector<pair<int,int>> answer{};

  for( int t = 0 ; t < T ; t++ ){

    const int& s = prev[t];
    
    if( s != -1 ){

      assert( 0 <= s && s < S && 0 <= t && t < T );
      answer.push_back( { s , t } );

    }

  }
  
  return answer;

}
