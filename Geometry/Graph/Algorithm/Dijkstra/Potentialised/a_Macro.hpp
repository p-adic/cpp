// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Potentialised/a_Macro.hpp

#pragma once

#define POTENTIALISED_DIJKSTRA_BODY( GET , WEIGHT )			\
  const U& infty = this->Infty();					\
  const U& zero = m_M.Zero();						\
  auto edge = [&]( const T& t ){					\
									\
    const U& potential_i = m_potential[m_G.Enumeration_inv( t )];	\
    assert( potential_i < infty );					\
    auto edge_i = m_G.Edge( t );					\
    vector<pair<T,U>> answer{};						\
									\
    for( auto& e : edge_i ){						\
									\
      if( m_on( e ) ){							\
									\
	const auto& v_j = get<0>( e );					\
	U& w_j = get<1>( e );						\
	const U& potential_j = m_potential[m_G.Enumeration_inv( v_j )]; \
	assert( w_j < infty && potential_j < infty );			\
	const U potential_j_inv = m_M.Inverse( potential_j );		\
	w_j = m_M.Sum( m_M.Sum( w_j , potential_i ) , potential_j_inv ); \
	assert( !( w_j < zero ) && w_j < infty );			\
	answer.push_back( { v_j , move( w_j ) } );			\
									\
      }									\
									\
    }									\
									\
    return answer;							\
									\
  };									\
									\
  auto G = m_G.GetGraph( move( edge ) );				\
  AbstractDijkstra d{ G , m_M , infty };				\
  auto value = d.GET;							\
  const int& size = m_G.size();						\
									\
  for( int i = 0 ; i < size ; i++ ){					\
      									\
    auto& weight_i = WEIGHT[i];						\
									\
    if( weight_i != infty ){						\
									\
      weight_i = m_M.Sum( weight_i , m_potential[i] );			\
									\
    }									\
									\
  }									\
									\
  return value;								\


