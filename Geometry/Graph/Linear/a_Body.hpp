// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Linear/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

inline LinearEdge::LinearEdge( const int& size , const int& direction ) : m_size( size ) , m_direction( direction ) {}
inline vector<int> LinearEdge::operator()( const int& t ) { vector<int> answer{}; if( ( m_direction >> 1 ) == 1 && t > 0 ){ answer.push_back( t - 1 ); } if( ( m_direction & 1 ) == 1 && t + 1 < m_size ){ answer.push_back( t + 1 ); } return answer; }

inline LinearGraph::LinearGraph( const int& size , const int& direction ) : Graph<LinearEdge>( size , LinearEdge( size , direction ) ) {}
