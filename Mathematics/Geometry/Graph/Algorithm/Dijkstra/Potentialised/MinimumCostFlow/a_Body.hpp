// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Potentialised/MinimumCostFlow/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../Debug/a_Body.hpp"
#else
  #include "../a_Body.hpp"
#endif
#include "../../../../../../Algebra/Monoid/Semirng/Ring/a_Body.hpp"

template <typename T , typename GRAPH , typename U , typename RING> inline AbstractMinimumCostFlow<T,GRAPH,U,RING>::AbstractMinimumCostFlow( GRAPH& G , RING R , const U& infty ) : m_G( G ) , m_R( move( R ) ) , m_infty( infty ) , m_full() , m_flow() , m_edge_num() , m_edge_rev_num()
{

  const U& zero = m_R.Zero();
  const int& size = m_G.size();
  m_full.resize( size );
  m_flow.resize( size );
  m_edge_num.resize( size , vector<int>( size , -1 ) );
  m_edge_rev_num.resize( size , vector<int>( size , -1 ) );

  for( int i = 0 ; i < size ; i++ ){

    auto&& vi = m_G.Enumeration( i );

    for( auto& [vj,wj,fj] : m_G.Edge( vi ) ){

      assert( vi != vj && !( wj < zero ) && wj < m_infty && !( fj < zero ) && fj < m_infty );

      if( zero < fj ){

	auto&& j = m_G.Enumeration_inv( vj );
	assert( m_edge_num[i][j] == -1 );
	m_edge_num[i][j] = m_full[i].size(); 
	assert( m_edge_rev_num[j][i] == -1 );
	m_edge_rev_num[j][i] = m_full[j].size();
	const int flow_i_size = m_flow[i].size();
	m_full[i].push_back( { j , wj , fj , flow_i_size } );
	m_full[j].push_back( { i , m_R.Inverse( wj ) , zero , flow_i_size } );
	m_flow[i].push_back( { vj , zero } );

	if( m_edge_num[j][i] != -1 ){

	  // ダイクストラの要件のためにコスト昇順になるようswapする。
	  swap( m_full[j][m_edge_num[j][i]] , m_full[j][m_edge_rev_num[j][i]] );
	  swap( m_edge_num[j][i] , m_edge_rev_num[j][i] );

	}

      }
      
    }

  }

}

template <typename T , typename GRAPH , typename U> inline MinimumCostFlow<T,GRAPH,U>::MinimumCostFlow( GRAPH& G , const U& one_U , const U& infty ) : AbstractMinimumCostFlow<T,GRAPH,U,Ring<U>>( G , Ring<U>( one_U ) , infty ) {}

template <typename T , typename GRAPH , typename U , typename RING>
pair<U,vector<vector<tuple<T,U>>>> AbstractMinimumCostFlow<T,GRAPH,U,RING>::GetFlow( const T& t_start , const T& t_final , U f , const bool& many_edges , int path_length )
{

  const U& zero = m_R.Zero();
  auto rest = m_full;
  auto flow = m_flow;
  auto edge = [&]( const T& t ) -> const vector<tuple<int,U,U,int>>& { return rest[m_G.Enumeration_inv( t )]; };
  auto on = [&]( const tuple<T,U,U,int>& e ) { return zero < get<2>( e ); };
  auto G = m_G.GetGraph( move( edge ) );
  AbstractPotentialisedDijkstra pd{ G , m_R.AdditiveGroup() , t_start , m_infty , move( on ) };
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
    // パス内の辺ごとに
    // {残りの容量のアドレス,逆の辺の残りの容量のアドレス,
    //  対応するflowの成分のアドレス,反転しているか否か}
    // のデータを格納する。
    vector<tuple<U*,U*,U*,bool>> update{};
    update.reserve( path.size() - 1 );

    while( ++itr_path != end_path ){

      auto&& j = m_G.Enumeration_inv( *itr_path );
      bool reversed = false;

      if( m_edge_rev_num[i][j]!= -1 ){

	auto& [j_copy,w_rev_ij,f_rev_ij,flow_num_ji] = rest[i][m_edge_rev_num[i][j]];

	if( zero < f_rev_ij ){

	  f_min = min( f_min , f_rev_ij );
	  update.push_back( { &f_rev_ij , &( get<2>( rest[j][m_edge_num[j][i]] ) ) , &( get<1>( flow[j][flow_num_ji] ) ) , reversed = true } );
	  
	}

      }

      if( !reversed ){

	auto& [j_copy,w_ij,f_ij,flow_num_ij] = rest[i][m_edge_num[i][j]];
	f_min = min( f_min , f_ij );
	update.push_back( { &f_ij , &( get<2>( rest[j][m_edge_rev_num[j][i]] ) ) , &( get<1>( flow[i][flow_num_ij] ) ) , reversed } );

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
