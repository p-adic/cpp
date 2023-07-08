// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/HopcroftKarp/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/Search/BreadthFirst/a_Body.hpp"

template <int S_max , int T_max> int HopcroftKarp<S_max,T_max>::g_S = 0;
template <int S_max , int T_max> int HopcroftKarp<S_max,T_max>::g_T = 0;
template <int S_max , int T_max> set<int> HopcroftKarp<S_max,T_max>::g_unchosen_source{};
template <int S_max , int T_max> list<int> HopcroftKarp<S_max,T_max>::g_edge[S_max] = {};
template <int S_max , int T_max> int HopcroftKarp<S_max,T_max>::g_prev[T_max] = {};

template <int S_max , int T_max>
list<pair<int,int> > HopcroftKarp<S_max,T_max>::Solve( const int& S , const int& T ,  const list<pair<int,int> >& edge )
{

  g_S = S;
  g_T = T;
  assert( g_S <= S_max && g_T <= T_max );
  
  for( int s = 0 ; s < g_S ; s++ ){

    g_unchosen_source.insert( s );

  }

  for( int s = 0 ; s < g_S ; s++ ){

    g_edge[s].clear();

  }

  for( auto itr = edge.begin() , end = edge.end() ; itr != end ; itr++ ){

    const int& s = itr->first;
    const int& t = itr->second;
    assert( 0 <= s && s < g_S && 0 <= s && t < g_T );
    g_edge[s].push_back( 1 + g_S + t );

  }

  for( int t = 0 ; t < g_T ; t++ ){

    g_prev[t] = -1;

  }

  BreadthFirstSearch<1 + S_max + T_max , Edge> bfs{ 1 + g_S + g_T };
  bool chosen_source[S_max] = {};
  bool chosen_target[T_max] = {};
  bool chosen_edge[S_max][T_max] = {};
  int depth[1 + S_max + T_max] = {};
  int depth_min = -1;
  int root[S_max + T_max] = {};
  list<int> new_chosen_target{ 0 };
  int v , w;
  bool found;
  
  while( ! new_chosen_target.empty() ){

    new_chosen_target.clear();
    bfs.Reset( 0 );
    v = bfs.Next();
    found = false;
    
    while( ( v = bfs.Next() ) != -1 ){

      w = bfs.prev( v );
      int& depth_v = depth[v] = depth[w] + 1;
      
      if( found ? depth_v > depth_min : false ){

	break;
      
      }

      if( w == 0 ){

	const int s = v - 1;
	assert( 0 <= s && s < g_S );
	root[s] = s;

      } else {

	root[v - 1] = root[w - 1];

      }

      if( depth_v % 2 == 0 ){

	const int t = v - 1 - g_S;
	assert( 0 <= t && t < g_T );
	bool& chosen_target_t = chosen_target[t];
      
	if( !chosen_target_t ){

	  const int& s = root[v - 1];
	  assert( 0 <= s && s < g_S );
	  bool& chosen_source_s = chosen_source[s];

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

    for( auto itr = new_chosen_target.begin() , end = new_chosen_target.end() ; itr != end ; itr++ ){

      int* p[2] = { &w , &v };
      int*& p0 = p[0];
      int*& p1 = p[1];
      v = *itr;

      while( ( w = bfs.prev( v ) ) != 0 ){

	const int s = *p0 - 1;
	const int t = *p1 - 1 - g_S;
	assert( 0 <= s && s < g_S && 0 <= t && t < g_T );
	
	if( chosen_edge[s][t] ^= true ){

	  g_prev[t] = s;

	}
	
	swap( w , v );
	swap( p0 , p1 );

      }

      const int s = v - 1;
      assert( 0 <= s && s < g_S && g_unchosen_source.count( s ) == 1 );
      g_unchosen_source.erase( s );

    }

  }

  list<pair<int,int> > answer{};

  for( int t = 0 ; t < g_T ; t++ ){

    const int& s = g_prev[t];
    
    if( s != -1 ){

      assert( 0 <= s && s < g_S && 0 <= t && t < g_T );
      answer.push_back( { s , t } );

    }

  }
  
  return answer;

}

template <int S_max , int T_max>
list<int> HopcroftKarp<S_max,T_max>::Edge( const int& w )
{

  list<int> answer{};
  
  if( w == 0 ){

    for( auto itr = g_unchosen_source.begin() , end = g_unchosen_source.end() ; itr != end ; itr++ ){

      answer.push_back( 1 + *itr );

    }

  } else if( w <= g_S ){

    answer = g_edge[ w - 1 ];

  } else {

    const int t = w - 1 - g_S;
    assert( t < g_T );
    const int& s = g_prev[t];

    if( s != -1 ){
      
      assert( 0 <= s && s < g_S );
      answer.push_back( 1 + s );

    }

  }

  return answer;

}
