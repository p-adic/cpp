// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Potentialised/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../../Algebra/Monoid/Group/a_Body.hpp"

#include "../../Debug/a_Body.hpp"

template <typename T , typename GRAPH , typename U , typename GROUP , typename On> inline AbstractPotentialisedDijkstra<T,GRAPH,U,GROUP,On>::AbstractPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on , vector<U> potential ) : PointedSet<U>( infty ) , m_G( G ) , m_M( move( M ) ) , m_t_start( t_start ) , m_on( move( on ) ) , m_potential( potential ) { static_assert( is_invocable_r_v<bool,On,decltype(declval<GRAPH>().Edge(declval<T>()).back())> ); if( m_potential.empty() ){ m_potential = vector<U>( m_G.size() , m_M.Zero() ); } else { assert( int( m_potential.size() ) == m_G.size() ); } }

template <typename T , typename GRAPH , typename On> template <typename...Args> inline PotentialisedDijkstra<T,GRAPH,On>::PotentialisedDijkstra( GRAPH& G , const T& t_start , On on , Args&&... args ) : AbstractPotentialisedDijkstra<T,GRAPH,ll,AdditiveGroup<>,On>( G , AdditiveGroup<>() , t_start , 1e18 , move( on ) , forward<decay_t<Args>>( args )... ) {}

template <typename T , typename GRAPH , typename U , typename GROUP , typename On> inline const vector<U>& AbstractPotentialisedDijkstra<T,GRAPH,U,GROUP,On>::Potential() const noexcept { return m_potential; }
template <typename T , typename GRAPH , typename U , typename GROUP , typename On> inline void AbstractPotentialisedDijkstra<T,GRAPH,U,GROUP,On>::SetPotential( vector<U> potential ) { assert( int( potential.size() ) == m_G.size() ); m_potential = move( potential ); }

template <typename T , typename GRAPH , typename U , typename GROUP , typename On> template <typename...Args> vector<U> AbstractPotentialisedDijkstra<T,GRAPH,U,GROUP,On>::GetDistance( Args&&... args )
{
  // VVV POTENTIALISED_DIJKSTRA_BODY( GetDistance( m_t_start , forward<Args>( args )... ) , value );
  const U& infty = this->Infty();
  const U& zero = m_M.Zero();
  auto edge = [&]( const T& t ){

    const U& potential_i = m_potential[m_G.Enumeration_inv( t )];
    assert( potential_i < infty );
    auto edge_i = m_G.Edge( t );
    vector<pair<T,U>> answer{};

    for( auto& e : edge_i ){

      if( m_on( e ) ){

	const auto& v_j = get<0>( e );
	U& w_j = get<1>( e );
	const U& potential_j = m_potential[m_G.Enumeration_inv( v_j )];
	assert( w_j < infty && potential_j < infty );
	const U potential_j_inv = m_M.Inverse( potential_j );
	w_j = m_M.Sum( m_M.Sum( w_j , potential_i ) , potential_j_inv );
	assert( !( w_j < zero ) && w_j < infty );
	answer.push_back( { v_j , move( w_j ) } );

      }

    }

    return answer;

  };

  auto G = m_G.GetGraph( move( edge ) );
  AbstractDijkstra d{ G , m_M , infty };
  auto value = d.GetDistance( m_t_start , forward<Args>( args )... ); // auto value = d.GET;
  const int& size = m_G.size();

  for( int i = 0 ; i < size ; i++ ){

    auto& weight_i = value[i]; // auto& weight_i = WEIGHT[i];

    if( weight_i != infty ){

      weight_i = m_M.Sum( weight_i , m_potential[i] );

    }

  }

  return value;
  // AAA POTENTIALISED_DIJKSTRA_BODY( GetDistance( m_t_start , forward<Args>( args )... ) , value );
}

template <typename T , typename GRAPH , typename U , typename GROUP , typename On> template <typename...Args> pair<vector<U>,vector<list<T>>> AbstractPotentialisedDijkstra<T,GRAPH,U,GROUP,On>::GetPath( Args&&... args )
{
  // VVV POTENTIALISED_DIJKSTRA_BODY( GetPath( m_t_start , forward<Args>( args )... ) , get<0>( value ) );
  const U& infty = this->Infty();
  const U& zero = m_M.Zero();
  auto edge = [&]( const T& t ){

    const U& potential_i = m_potential[m_G.Enumeration_inv( t )];
    assert( potential_i < infty );
    auto edge_i = m_G.Edge( t );
    vector<pair<T,U>> answer{};

    for( auto& e : edge_i ){

      if( m_on( e ) ){

	const auto& v_j = get<0>( e );
	U& w_j = get<1>( e );
	const U& potential_j = m_potential[m_G.Enumeration_inv( v_j )];
	assert( w_j < infty && potential_j < infty );
	const U potential_j_inv = m_M.Inverse( potential_j );
	w_j = m_M.Sum( m_M.Sum( w_j , potential_i ) , potential_j_inv );
	assert( !( w_j < zero ) && w_j < infty );
	answer.push_back( { v_j , move( w_j ) } );

      }

    }

    return answer;

  };

  auto G = m_G.GetGraph( move( edge ) );
  AbstractDijkstra d{ G , m_M , infty };
  auto value = d.GetPath( m_t_start , forward<Args>( args )... ); // auto value = d.GET;
  const int& size = m_G.size();

  for( int i = 0 ; i < size ; i++ ){

    auto& weight_i = get<0>( value )[i]; // auto& weight_i = WEIGHT[i];

    if( weight_i != infty ){

      weight_i = m_M.Sum( weight_i , m_potential[i] );

    }

  }

  return value;
  // AAA POTENTIALISED_DIJKSTRA_BODY( GetPath( m_t_start , forward<Args>( args )... ) , get<0>( value ) );
}
