// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Algebra/Monoid/a_Body.hpp"

template <typename GRAPH , typename COMM_MONOID , typename U> inline AbstractDijkstra<GRAPH,COMM_MONOID,U>::AbstractDijkstra( GRAPH& G , COMM_MONOID M , const U& infty ) : PointedSet<U>( infty ) , m_G( G ) , m_M( move( M ) ) { static_assert( ! is_same_v<U,int> ); }
template <typename GRAPH> inline Dijkstra<GRAPH>::Dijkstra( GRAPH& G ) : AbstractDijkstra<GRAPH,AdditiveMonoid<>,ll>( G , AdditiveMonoid<>() , 4611686018427387904 ) {}

template <typename GRAPH , typename COMM_MONOID , typename U>
U AbstractDijkstra<GRAPH,COMM_MONOID,U>::GetDistance( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges , int walk_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> found( size );
  auto&& i_final = m_G.Enumeration_inv( t_final );
  DIJKSTRA_BODY( , if( i == i_final ){ break; } , );
  U answer{ move( weight[i_final] ) };
  m_G.Reset();
  return answer;

}

template <typename GRAPH , typename COMM_MONOID , typename U>
vector<U> AbstractDijkstra<GRAPH,COMM_MONOID,U>::GetDistance( const inner_t<GRAPH>& t_start , const bool& many_edges , int walk_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> found( size );
  DIJKSTRA_BODY( , , );
  m_G.Reset();
  return weight;

}

template <typename GRAPH , typename COMM_MONOID , typename U>
void AbstractDijkstra<GRAPH,COMM_MONOID,U>::SetDistance( vector<U>& weight , vector<bool>& found , const inner_t<GRAPH>& t_start , const bool& many_edges , int walk_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  assert( int( weight.size() ) == size );
  assert( int( found.size() ) == size );
  DIJKSTRA_BODY( , , );
  m_G.Reset();
  return;

}

template <typename GRAPH , typename COMM_MONOID , typename U>
pair<U,list<inner_t<GRAPH>>> AbstractDijkstra<GRAPH,COMM_MONOID,U>::GetPath( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges , int walk_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> found( size );
  auto&& i_final = m_G.Enumeration_inv( t_final );
  DIJKSTRA_BODY( vector<int> prev( size ) , if( i == i_final ){ break; } , prev[j] = i );
  int i = i_final;
  list<inner_t<GRAPH>> path{};
  path.push_back( t_final );

  if( found[i] ){

    while( i != i_start ){

      i = prev[i];
      path.push_front( m_G.Enumeration( i ) );

    }

  }

  U answer{ move( weight[i_final] ) };
  m_G.Reset();
  return { move( answer ) , move( path ) };

}

template <typename GRAPH , typename COMM_MONOID , typename U> template <template <typename...> typename V> 
pair<vector<U>,vector<list<inner_t<GRAPH>>>> AbstractDijkstra<GRAPH,COMM_MONOID,U>::GetPath( const inner_t<GRAPH>& t_start , const V<inner_t<GRAPH>>& t_finals , const bool& many_edges , int walk_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> found( size );
  DIJKSTRA_BODY( vector<int> prev( size ) , , prev[j] = i );
  const int path_size = t_finals.size();
  vector<list<inner_t<GRAPH>>> path;
  path.reserve( path_size );

  for( auto itr = t_finals.begin() , end = t_finals.end() ; itr != end ; itr++ ){

    list<inner_t<GRAPH>> path_j{};
    const inner_t<GRAPH>& t_final = *itr;
    path_j.push_back( t_final );
    int i = m_G.Enumeration_inv( t_final );

    if( found[i] ){

      while( i != i_start ){

	i = prev[i];
	path_j.push_front( m_G.Enumeration( i ) );

      }

    }

    path.push_back( path_j );

  }

  m_G.Reset();
  return { move( weight ) , move( path ) };

}

template <typename GRAPH , typename COMM_MONOID , typename U>
pair<vector<U>,vector<list<inner_t<GRAPH>>>> AbstractDijkstra<GRAPH,COMM_MONOID,U>::GetPath( const inner_t<GRAPH>& t_start , const bool& many_edges , int walk_length )
{

  const int& size = m_G.size();
  vector<inner_t<GRAPH>> t_finals( size );

  for( int i = 0 ; i < size ; i++ ){

    t_finals[i] = i;

  }

  return GetPath( t_start , t_finals , many_edges , walk_length );

}
