// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Double/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../Debug/a_Body.hpp"
#else
  #include "../a_Body.hpp"
#endif

#include "../../../Acyclic/a_Body.hpp"

template <typename T1 , typename ACYCLIC_GRAPH , typename T2 , typename U , typename GRAPH , typename VERTEX> inline DoubleDijkstra<T1,ACYCLIC_GRAPH,T2,U,GRAPH,VERTEX>::DoubleDijkstra( ACYCLIC_GRAPH G1 , GRAPH G2 , VERTEX vertex ) : DoubleDijkstra( move( G1 ) , move( G2 ) , move( vertex ) , TopologicalSort( G1 ) ) {}
template <typename T1 , typename ACYCLIC_GRAPH , typename T2 , typename U , typename GRAPH , typename VERTEX> inline DoubleDijkstra<T1,ACYCLIC_GRAPH,T2,U,GRAPH,VERTEX>::DoubleDijkstra( ACYCLIC_GRAPH G1 , GRAPH G2 , VERTEX vertex  , vector<T1> top_sort ) :
  m_G1( move( G1 ) ) , m_G2( move( G2 ) ) , m_vertex( move( vertex ) ) , m_top_sort( move( top_sort ) )
{ static_assert( is_same_v<T1,inner_t<ACYCLIC_GRAPH>> && is_same_v<pair<T1,T2>,inner_t<GRAPH>> && is_same_v<U,decldecay_t( declval<GRAPH>().Edge( declval<inner_t<GRAPH>>() ).front().second )> && is_invocable_v<VERTEX,const T1&> ); }

template <typename T1 , typename ACYCLIC_GRAPH , typename T2 , typename U , typename GRAPH , typename VERTEX> inline const vector<T1>& DoubleDijkstra<T1,ACYCLIC_GRAPH,T2,U,GRAPH,VERTEX>::GetTopologicalSort() const noexcept { return m_top_sort; }

template <typename T1 , typename ACYCLIC_GRAPH , typename T2 , typename U , typename GRAPH , typename VERTEX> template <typename COMM_MONOID> vector<U> DoubleDijkstra<T1,ACYCLIC_GRAPH,T2,U,GRAPH,VERTEX>::GetDistance( const vector<pair<T1,T2>>& t_starts , COMM_MONOID M , const U& infty , const bool& many_edges )
{

  vector<U> weight( m_G2.size() , infty );

  if( t_starts.empty() ){

    return weight;

  }

  for( auto& t : t_starts ){

    auto&& i = m_G2.Enumeration_inv( t );
    weight[i] = M.One();

  }

  vector<bool> found( m_G2.size() );
  const int& G1_size = m_G1.size();
  auto& t_start = t_starts[0];

  for( int num = 0 ; num < G1_size ; num++ ){

    const T1& t1 = m_top_sort[num];
    auto&& V_t1 = m_vertex( t1 );
    using path_type = pair<pair<T1,T2>,U>;
    vector<path_type> inits{};

    for( auto& t2 : V_t1 ){

      pair<T1,T2> t{ t1 , t2 };
      auto&& j = m_G2.Enumeration_inv( t );

      if( weight[j] != infty ){

	inits.push_back( { move( t ) , weight[j] } );
	found[j] = false;
	weight[j] = infty;

      }

    }

    auto edge = [&]( const pair<T1,T2>& t ){ return t.first == t1 ? m_G2.Edge( t ) : t == t_start ? inits : vector<path_type>(); };
    auto graph = m_G2.GetGraph( move( edge ) );
    AbstractDijkstra dijk{ graph , M , infty };
    dijk.SetDistance( weight , found , t_start , many_edges , -1 );

  }

  return weight;

}

#include "../../../Linear/a_Body.hpp"

