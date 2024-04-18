// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/Potentialised/MinimumCostFlow/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../../../Algebra/Monoid/Semirng/Ring/a_Body.hpp"

template <typename T , typename GRAPH , typename U , typename RING> inline AbstractMinimumCostFlow<T,GRAPH,U,RING>::AbstractMinimumCostFlow( GRAPH& G , RING R , const U& infty ) : PointedSet<U>( infty ) , m_G( G ) , m_R( move( R ) ) {}
template <typename T , typename GRAPH , typename U> inline MinimumCostFlow<T,GRAPH,U>::MinimumCostFlow( GRAPH& G , const U& one_U , const U& infty ) : AbstractMinimumCostFlow<T,GRAPH,U,Ring<U>>( G , Ring<U>( one_U ) , infty ) {}

template <typename T , typename GRAPH , typename U , typename RING>
pair<U,vector<vector<tuple<T,U>>>> AbstractMinimumCostFlow<T,GRAPH,U,RING>::GetFlow( const T& t_start , const T& t_final , U f , const bool& many_edges , int path_length )
{

  const U& zero = m_R.Zero();
  const U& infty = this->Infty();
  const int& size = m_G.size();
  // rest[i]に、m_G.Enumeration(i)を始点とする辺m_G.Enumeration(i)->m_G.Enumeration(j)
  // または辺m_G.Enumeration(j)->m_G.Enumeration(i)の反転ごとに
  // {j,重み,まだ流せる量,flow[反転?j:i]における位置}のデータを格納する。
  vector<vector<tuple<int,U,U,int>>> rest( size );
  // flow[i]に、m_G.Enumeration(i)を始点とする辺m_G.Enumeration(i)->m_G.Enumeration(j)
  // ごとに{m_G.Enumeration(j),既に流した量}のデータを格納する。
  vector<vector<tuple<T,U>>> flow( size );
  vector edge_num( size , vector<int>( size , -1 ) );
  vector edge_rev_num( size , vector<int>( size , -1 ) );

  for( int i = 0 ; i < size ; i++ ){

    auto&& vi = m_G.Enumeration( i );

    for( auto& [vj,wj,fj] : m_G.Edge( vi ) ){

      assert( vi != vj && !( wj < zero ) && wj < infty && !( fj < zero ) && fj < infty );

      if( zero < fj ){

	auto&& j = m_G.Enumeration_inv( vj );
	assert( edge_num[i][j] == -1 );
	edge_num[i][j] = rest[i].size(); 
	assert( edge_rev_num[j][i] == -1 );
	edge_rev_num[j][i] = rest[j].size();
	const int flow_i_size = flow[i].size();
	rest[i].push_back( { j , wj , fj , flow_i_size } );
	rest[j].push_back( { i , m_R.Inverse( wj ) , zero , flow_i_size } );
	flow[i].push_back( { vj , zero } );

	if( edge_num[j][i] != -1 ){

	  // ダイクストラの要件のためにコスト昇順になるようswapする。
	  swap( rest[j][edge_num[j][i]] , rest[j][edge_rev_num[j][i]] );
	  swap( edge_num[j][i] , edge_rev_num[j][i] );

	}

      }
      
    }

  }

  auto edge = [&]( const T& t ) -> const vector<tuple<int,U,U,int>>& { return rest[m_G.Enumeration_inv( t )]; };
  auto on = [&]( const tuple<T,U,U,int>& e ) { return zero < get<2>( e ); };
  auto G = m_G.GetGraph( move( edge ) );
  AbstractPotentialisedDijkstra pd{ G , m_R.AdditiveGroup() , t_start , infty , move( on ) };
  auto&& i_start = m_G.Enumeration_inv( t_start );
  auto&& i_final = m_G.Enumeration_inv( t_final );
  const vector<T> t_finals = { t_final };
  U w = zero;

  while( zero < f ){

    auto [weight,paths] = pd.GetPath( t_finals , many_edges , path_length );
    const U w_min = weight[i_final];
    pd.SetPotential( move( weight ) );
    auto& path = paths.front();
    auto itr_path = path.begin() , itr_path_prev = itr_path , end_path = path.end();
    int i = i_start;
    U f_min = f;
    // vector<tuple<int,int,int,int>> flow_num{};
    // パス内の辺ごとに
    // {残りの容量のアドレス,逆の辺の残りの容量のアドレス,
    //  対応するflowの成分のアドレス,反転しているか否か}
    // のデータを格納する。
    vector<tuple<U*,U*,U*,bool>> update{};
    update.reserve( path.size() - 1 );

    while( ++itr_path != end_path ){

      auto&& j = m_G.Enumeration_inv( *itr_path );
      bool reversed = false;

      if( edge_rev_num[i][j]!= -1 ){

	auto& [j_copy,w_rev_ij,f_rev_ij,flow_num_ji] = rest[i][edge_rev_num[i][j]];

	if( zero < f_rev_ij ){

	  f_min = min( f_min , f_rev_ij );
	  update.push_back( { &f_rev_ij , &( get<2>( rest[j][edge_num[j][i]] ) ) , &( get<1>( flow[j][flow_num_ji] ) ) , reversed = true } );
	  
	}

      }

      if( !reversed ){

	auto& [j_copy,w_ij,f_ij,flow_num_ij] = rest[i][edge_num[i][j]];
	f_min = min( f_min , f_ij );
	update.push_back( { &f_ij , &( get<2>( rest[j][edge_rev_num[j][i]] ) ) , &( get<1>( flow[i][flow_num_ij] ) ) , reversed } );

      }

      itr_path_prev = itr_path;
      i = j;

    }

    const U f_min_inv = m_R.Inverse( f_min );
    f = m_R.Sum( f , f_min_inv );
    w = m_R.Sum( w , m_R.Product( f_min , w_min ) );

    for( auto& [p_f,p_f_rev,p_flow,reversed] : update ){

      *p_f = m_R.Sum( move( *p_f ) , f_min_inv );
      *p_f_rev = m_R.Sum( move( *p_f_rev ) , f_min );
      *p_flow = m_R.Sum( move( *p_flow ) , reversed ? f_min_inv : f_min );

    }

  }

  return { move( w ) , move( flow ) };

}
