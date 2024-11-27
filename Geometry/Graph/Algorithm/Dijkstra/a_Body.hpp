// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"
#include "../../../../Algebra/Monoid/a_Body.hpp"

template <typename T , typename GRAPH , typename U , typename COMM_MONOID> inline AbstractDijkstra<T,GRAPH,U,COMM_MONOID>::AbstractDijkstra( GRAPH& G , COMM_MONOID M , const U& infty ) : PointedSet<U>( infty ) , m_G( G ) , m_M( move( M ) ) { static_assert( is_same_v<T,inner_t<GRAPH>> ); }
template <typename T , typename GRAPH> inline Dijkstra<T,GRAPH>::Dijkstra( GRAPH& G , const ll& infty ) : AbstractDijkstra<T,GRAPH,ll,AdditiveMonoid<>>( G , AdditiveMonoid<>() , infty ) {}

template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
U AbstractDijkstra<T,GRAPH,U,COMM_MONOID>::GetDistance( const T& t_start , const T& t_final , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> fixed( size );
  auto&& i_final = m_G.Enumeration_inv( t_final );
  DIJKSTRA_BODY( , if( i == i_final ){ break; } , );
  U answer{ move( weight[i_final] ) };
  return answer;

}

template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
vector<U> AbstractDijkstra<T,GRAPH,U,COMM_MONOID>::GetDistance( const T& t_start , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> fixed( size );
  DIJKSTRA_BODY( , , );
  return weight;

}

template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
void AbstractDijkstra<T,GRAPH,U,COMM_MONOID>::SetDistance( vector<U>& weight , vector<bool>& fixed , const T& t_start , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  assert( int( weight.size() ) == size );
  assert( int( fixed.size() ) == size );
  DIJKSTRA_BODY( , , );
  return;

}

template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
pair<U,list<T>> AbstractDijkstra<T,GRAPH,U,COMM_MONOID>::GetPath( const T& t_start , const T& t_final , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> fixed( size );
  auto&& i_final = m_G.Enumeration_inv( t_final );
  DIJKSTRA_BODY( vector<int> prev( size ) , if( i == i_final ){ break; } , prev[j] = i );
  int i = i_final;
  list<T> path{};
  path.push_back( t_final );

  if( weight[i] != infty ){

    while( i != i_start ){

      i = prev[i];
      path.push_front( m_G.Enumeration( i ) );

    }

  }

  U answer{ move( weight[i_final] ) };
  return { move( answer ) , move( path ) };

}

template <typename T , typename GRAPH , typename U , typename COMM_MONOID> template <template <typename...> typename V> 
pair<vector<U>,vector<list<T>>> AbstractDijkstra<T,GRAPH,U,COMM_MONOID>::GetPath( const T& t_start , const V<T>& t_finals , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> fixed( size );
  DIJKSTRA_BODY( vector<int> prev( size ) , , prev[j] = i );
  const int path_size = t_finals.size();
  vector<list<T>> path;
  path.reserve( path_size );

  for( auto itr = t_finals.begin() , end = t_finals.end() ; itr != end ; itr++ ){

    list<T> path_j{};
    const T& t_final = *itr;
    path_j.push_back( t_final );
    int i = m_G.Enumeration_inv( t_final );

    if( weight[i] != infty ){

      while( i != i_start ){

	i = prev[i];
	path_j.push_front( m_G.Enumeration( i ) );

      }

    }

    path.push_back( path_j );

  }

  return { move( weight ) , move( path ) };

}

template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
pair<vector<U>,vector<list<T>>> AbstractDijkstra<T,GRAPH,U,COMM_MONOID>::GetPath( const T& t_start , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  vector<T> t_finals( size );

  for( int i = 0 ; i < size ; i++ ){

    t_finals[i] = i;

  }

  return GetPath( t_start , t_finals , many_edges , path_length );

}
