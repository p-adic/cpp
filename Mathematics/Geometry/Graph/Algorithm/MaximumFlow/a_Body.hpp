// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/MaximumFlow/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"

template <typename T , typename GRAPH , typename U , typename ABEL_GROUP> inline AbstractMaximumFlow<T,GRAPH,U,ABEL_GROUP>::AbstractMaximumFlow( GRAPH& G , ABEL_GROUP M ) : m_G( G ) , m_M( move( M ) ) {}
template <typename T , typename GRAPH , typename U> inline MaximumFlow<T,GRAPH,U>::MaximumFlow( GRAPH& G , const U& dummy ) : AbstractMaximumFlow<T,GRAPH,U,AdditiveGroup<U>>( G , AdditiveGroup<U>() ) {}

template <typename T , typename GRAPH , typename U , typename ABEL_GROUP>
pair<U,vector<vector<tuple<T,U>>>> AbstractMaximumFlow<T,GRAPH,U,ABEL_GROUP>::GetFlow( const T& t_start , const T& t_final )
{

  const U& zero = m_M.Zero();
  const int& size = m_G.size();
  // rest[i]に、viを始点とする辺または辺の反転vi->vjごとに
  // {j,まだ流せる量,反転のrest[i]における位置,flow[i]における位置}
  // のデータを格納する。
  vector<vector<tuple<int,U,int,int>>> rest( size );
  // flow[i]に、viを始点とする辺vi->vjごとに{vj,既に流した量}のデータを格納する。
  vector<vector<tuple<T,U>>> flow( size );

  for( int i = 0 ; i < size ; i++ ){

    auto&& vi = m_G.Enumeration( i );

    for( auto& [vj,fj] : m_G.Edge( vi ) ){

      assert( vi != vj && !( fj < zero ) );

      if( zero < fj ){
	
	auto&& j = m_G.Enumeration_inv( vj );
	rest[i].push_back( { j , fj , rest[j].size() , flow[i].size() } );
	rest[j].push_back( { i , zero , rest[i].size() - 1 , -1 } );
	flow[i].push_back( { vj , zero } );

      }
      
    }

  }

  vector<int> edge_num_max( size );

  for( int i = 0 ; i < size ; i++ ){

    edge_num_max[i] = rest[i].size() - 1;

  }
  
  auto&& i_start = m_G.Enumeration_inv( t_start );
  auto&& i_final = m_G.Enumeration_inv( t_final );
  U flow_sum = zero;
  bool updated = true;

  for( int length = 1 ; length < size && updated ; length++ ){

    updated = false;
    list<int> bfs = { i_start };
    vector<int> distance = vector( size , -1 );
    distance[i_start] = 0;

    // dual stepの最短経路長をBFSで求める。
    while( !bfs.empty() ){

      const int i = bfs.back();
      bfs.pop_back();

      for( auto& e : rest[i] ){

	auto& j = get<0>( e );
	
	if( distance[j] == -1 && zero < get<1>( e ) ){

	  distance[j] = distance[i] + 1;
	  bfs.push_front( j );

	}

      }

    }

    if( distance[i_final] == -1 ){

      break;

    }

    vector<int> path{ i_start };
    auto edge_num = edge_num_max;

    // primal stepのグラフ更新と容量更新をDFSで処理する。
    while( true ){

      const int i = path.back();

      while( edge_num[i] >= 0 ){

	auto& rest_i_curr = rest[i][edge_num[i]];
	auto& j = get<0>( rest_i_curr );

	if( distance[i] + 1 == distance[j] && zero < get<1>( rest_i_curr ) ){

	  path.push_back( j );
	  break;

	} else {

	  edge_num[i]--;

	}

      }

      if( edge_num[i] >= 0 ){

	continue;

      }

      path.pop_back();

      if( i == i_start ){

	break;

      } else if( i != i_final ){

	edge_num[path.back()]--;

      } else {

	updated = true;
	auto itr = path.begin() , end = path.end();
	U f_min = get<1>( rest[*itr][edge_num[*itr]] );

	while( ++itr != end ){

	  f_min = min( f_min , get<1>( rest[*itr][edge_num[*itr]] ) );

	}

	flow_sum = m_M.Sum( move( flow_sum ) , f_min );
	const U f_min_inv = m_M.Inverse( f_min );

	for( auto& s : path ){

	  auto& [t,f_rest,rev_num,flow_num_s] = rest[s][edge_num[s]];
	  auto& [s_copy,f_rest_rev,edge_num_s_copy,flow_num_t] = rest[t][rev_num];

	  if( flow_num_s >= 0 ){

	    U& f_curr = get<1>( flow[s][flow_num_s] );
	    f_curr = m_M.Sum( move( f_curr ) , f_min );

	  } else {

	    U& f_curr = get<1>( flow[t][flow_num_t] );
	    assert( !( ( f_curr = m_M.Sum( move( f_curr ) , f_min_inv ) ) < zero ) );

	  }

	  f_rest = m_M.Sum( move( f_rest ) , f_min_inv );
	  f_rest_rev = m_M.Sum( move( f_rest_rev ) , f_min );

	}

	path = { i_start };

      }

    }

  }

  return { move( flow_sum ) , move( flow ) };

}
