// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/Potentialised/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Algebra/Monoid/Group/a_Body.hpp"

#include "../../BellmanFord/a_Body.hpp"

template <typename T , typename GRAPH , typename GROUP , typename U , typename On> inline AbstractPotentialisedDijkstra<T,GRAPH,GROUP,U,On>::AbstractPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on , const bool& negative ) : AbstractPotentialisedDijkstra( G , move( M ) , t_start , infty , move( on ) , true , vector<U>()  )
{

  if( negative ){
    
    auto edge = [&]( const int& t ){

      auto&& edge_i = m_G.Edge( t );
      list<pair<T,U>> answer{};

      for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

	const auto& e = *itr;
	answer.push_back( { get<0>( e ) , get<1>( e ) } );
	
      }

      return answer;

    };

    auto G_full = m_G.GetGraph( move( edge ) );
    AbstractBellmanFord bf{ G_full , m_M , infty };
    auto [valid,potential] = bf.GetDistance( m_t_start );
    m_valid = valid;
    m_potential = move( potential );

  } else {

    m_potential = vector<U>( m_G.size() , m_M.Zero() );

  }

}

template <typename T , typename GRAPH , typename GROUP , typename U , typename On> inline AbstractPotentialisedDijkstra<T,GRAPH,GROUP,U,On>::AbstractPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on , const bool& valid , vector<U> potential ) : PointedSet<U>( infty ) , m_G( G ) , m_M( move( M ) ) , m_t_start( t_start ) , m_on( move( on ) ) , m_valid( valid ) , m_potential( potential ) { static_assert( is_invocable_r_v<bool,On,decltype(declval<GRAPH>().Edge(declval<T>()).back())> ); }

template <typename T , typename GRAPH , typename On> template <typename...Args> inline PotentialisedDijkstra<T,GRAPH,On>::PotentialisedDijkstra( GRAPH& G , const T& t_start , On on , Args&&... args ) : AbstractPotentialisedDijkstra<T,GRAPH,AdditiveGroup<>,ll,On>( G , AdditiveGroup<>() , t_start , 4611686018427387904 , move( on ) , forward<decay_t<Args>>( args )... ) {}

template <typename T , typename GRAPH , typename GROUP , typename U , typename On> inline const bool& AbstractPotentialisedDijkstra<T,GRAPH,GROUP,U,On>::Valid() const noexcept { return m_valid; }
template <typename T , typename GRAPH , typename GROUP , typename U , typename On> inline const vector<U>& AbstractPotentialisedDijkstra<T,GRAPH,GROUP,U,On>::Potential() const noexcept { return m_potential; }
template <typename T , typename GRAPH , typename GROUP , typename U , typename On> inline void AbstractPotentialisedDijkstra<T,GRAPH,GROUP,U,On>::SetPotential( const bool& valid , vector<U> potential ) { assert( int( potential.size() ) == m_G.size() ); m_valid = valid; m_potential = move( potential ); }

template <typename T , typename GRAPH , typename GROUP , typename U , typename On> tuple<bool,vector<U>> AbstractPotentialisedDijkstra<T,GRAPH,GROUP,U,On>::GetDistance( const bool& many_edges ) { POTENTIALISED_DIJKSTRA_BODY( GetDistance( m_t_start , many_edges ) , value , move( value ) ); }
template <typename T , typename GRAPH , typename GROUP , typename U , typename On> template <typename...Args> tuple<bool,vector<U>,vector<list<T>>> AbstractPotentialisedDijkstra<T,GRAPH,GROUP,U,On>::GetPath( const Args&... args ) { POTENTIALISED_DIJKSTRA_BODY( GetPath( m_t_start , args... ) , get<0>( value ) , move( get<0>( value ) ) , move( get<1>( value ) ) ); }
