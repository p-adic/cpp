// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Array/a_Body.hpp

#pragma once
#include "../a.hpp"

#include "../a_Body.hpp"

inline LinearEdge::LinearEdge( const int& size , const bool& directed ) : m_size( size ) , m_directed( directed ) {}
inline vector<int> LinearEdge::operator()( const int& t ) { vector<int> answer{}; if( !m_directed && t > 0 ){ answer.push_back( t - 1 ); } if( t + 1 < m_size ){ answer.push_back( t + 1 ); } return answer; }

inline LinearGraph::LinearGraph( const int& size , const bool& directed ) : Graph<LinearEdge>( size , LinearEdge( size , directed ) ) {}
