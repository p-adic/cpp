// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/Potentialised/MinimumCostFlow/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../../../Algebra/Monoid/Semirng/Ring/a_Body.hpp"

template <typename GRAPH , typename RING , typename U> inline AbstractMinimumCostFlow<GRAPH,RING,U>::AbstractMinimumCostFlow( GRAPH& G , RING R , const U& infty ) : PointedSet<U>( infty ) , m_G( G ) , m_R( move( R ) ) {}
template <typename GRAPH , typename U> inline MinimumCostFlow<GRAPH,U>::MinimumCostFlow( GRAPH& G , const U& one_U , const U& infty ) : AbstractMinimumCostFlow<GRAPH,Ring<U>,U>( G , Ring<U>( one_U ) , infty ) {}

template <typename GRAPH , typename RING , typename U>
pair<U,vector<vector<tuple<inner_t<GRAPH>,U>>>> AbstractMinimumCostFlow<GRAPH,RING,U>::GetFlow( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , U f , const bool& many_edges , int path_length )
{

  using T = inner_t<GRAPH>;
  const U& zero = m_R.Zero();
  const U& infty = this->Infty();
  const int& size = m_G.size();
  vector<vector<tuple<int,U,U,bool,int>>> rest( size );
  vector<vector<tuple<T,U>>> flow( size );
  int edge_num = 0;

  for( int i = 0 ; i < size ; i++ ){

    auto&& ui = m_G.Enumeration( i );
    auto&& edge_i = m_G.Edge( ui );

    for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

      const auto& [vj,wj,fj] = *itr;
      assert( ui != vj && !( wj < zero ) && wj < infty && !( fj < zero ) && fj < infty );
      auto&& j = m_G.Enumeration_inv( vj );
      rest[i].push_back( { j , wj , fj , false , edge_num } );
      rest[j].push_back( { i , m_R.Inverse( wj ) , zero , true , edge_num } );
      flow[i].push_back( { vj , 0 } );
      edge_num++;
      
    }

  }

  for( int i = 0 ; i < size ; i++ ){

    auto& rest_i = rest[i];
    sort( rest_i.begin() , rest_i.end() );

  }

  vector<tuple<int,int,int,int>> edge_pair( edge_num , { -1 , -1 , -1 , -1 } );
  
  for( int i = 0 ; i < size ; i++ ){

    const auto& rest_i = rest[i];
    const int size_i = rest_i.size();

    for( int j = 0 ; j < size_i ; j++ ){

      const auto& rest_ij = rest_i[j];
      auto& [i_0,j_0,i_1,j_1] = edge_pair[get<4>( rest_ij )];

      if( i_0 == -1 ){

	i_0 = i;
	j_0 = j;

      } else {

	i_1 = i;
	j_1 = j;

      }      

    }

  }

  auto edge = [&]( const T& t ) -> const vector<tuple<int,U,U,bool,int>>& { return rest[m_G.Enumeration_inv( t )]; };
  auto on = [&]( const tuple<T,U,U,bool,int>& e ) { return zero < get<2>( e ); };
  auto G = m_G.GetGraph( move( edge ) );
  AbstractPotentialisedDijkstra pd{ G , m_R.AdditiveGroup() , t_start , infty , move( on ) , false };
  assert( pd.Valid() );
  auto&& i_start = m_G.Enumeration_inv( t_start );
  const vector<T> t_finals = { t_final };
  U w = zero;

  while( zero < f ){

    auto [valid,weight,paths] = pd.GetPath( t_finals , many_edges , path_length );
    pd.SetPotential( true , move( weight ) );
    auto& path = paths.front();
    auto itr_path = path.begin() , itr_path_prev = itr_path , end_path = path.end();
    assert( itr_path != end_path );
    int i = i_start;
    list<tuple<int,int,int,int>> flow_num{};
    U f_min = f;

    while( ++itr_path != end_path ){

      T t = *itr_path;
      flow_num.push_back( { i , m_G.Enumeration_inv( t ) , -1 , -1 } );
      auto& [i_curr,i_next,j_1,j_2] = flow_num.back();
      const auto& rest_i = rest[i_curr];
      int size_i = rest_i.size();

      for( int j = 0 ; j < size_i ; j++ ){

	const auto& [vj,wj,fj,rj,numj] = rest_i[j];

	if( zero < fj && vj == t ){

	  j_1 = j;
	  fj < f_min ? f_min = fj : f_min;

	  if( rj ){

	    i_curr = i_next;
	    t = *itr_path_prev;

	  }

	  break;

	}

      }

      assert( j_1 != -1 );
      auto& flow_i = flow[i_curr];
      size_i = flow_i.size();

      for( int j = 0 ; j < size_i ; j++ ){

	const auto& [vj,fj] = flow_i[j];

	if( vj == t ){

	  j_2 = j;
	  break;

	}

      }

      assert( j_2 != -1 );
      i_curr = i;
      i = i_next;
      itr_path_prev = itr_path;

    }

    const U f_min_minus = m_R.Inverse( f_min );
    U w_diff = zero;

    for( auto itr = flow_num.begin() , end = flow_num.end() ; itr != end ; itr++ ){

      const auto& [i_curr,i_next,j_1,j_2] = *itr;
      auto& [vj,wj,fj,rj,numj] = rest[i_curr][j_1];
      const auto& edge_pair_i = edge_pair[numj];
      const int& j_3 = get<0>( edge_pair_i ) == i_curr ? get<3>( edge_pair_i ) : get<1>( edge_pair_i );
      auto& fj_inv = get<2>( rest[i_next][j_3] );
      auto& f_curr = get<1>( flow[rj ? i_next : i_curr][j_2] );
      w_diff = m_R.Sum( w_diff , wj );
      fj = m_R.Sum( fj , f_min_minus );
      fj_inv = m_R.Sum( fj_inv , f_min );
      f_curr = m_R.Sum( f_curr , f_min );

    }

    f = m_R.Sum( f , f_min_minus );
    w = m_R.Sum( w , m_R.Product( f_min , w_diff ) );

  }

  return { move( w ) , move( flow ) };

}
