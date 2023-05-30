// c:/Users/user/Documents/Programming/Utility/Search/Dijkstra/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Header.hpp"
#include "a_Body.hpp"

template <typename T> inline PairForDijkstra<T>::PairForDijkstra( const T& t , const int& i ) : m_t( t ) , m_i( i ) {}
template <typename T> inline void PairForDijkstra<T>::Set( const T& t ) { m_t = t; }
template <typename T> inline const T& PairForDijkstra<T>::Get() const noexcept { return m_t; }
template <typename T> inline const int& PairForDijkstra<T>::index() const noexcept { return m_i; }
template <typename T> inline bool PairForDijkstra<T>::operator<( const PairForDijkstra& t ) const { return m_t < t.m_t ? true : t.m_t < m_t ? false : m_i < t.m_i; }

template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
T Dijkstra( const T ( &d )[size_max][size_max] , const int& i_start , const int& i_final , const int& size , const T& weight_max , list<int>& path )
{

  set<PairForDijkstra<T> > vertex{};

  for( int i = 0 ; i < size ; i++ ){

    vertex.insert( PairForDijkstra<T>( i == i_start ? e_T() : weight_max , i ) );
      
  }

  T weight[size_max] = {};
  int prev[size_max] = {};

  while( ! vertex.empty() ){

    auto itr = vertex.begin() , end = vertex.end();
    PairForDijkstra<T> v = *itr;
    const T& t = v.Get();
    const int& i = v.index();
    const T ( &di )[size_max] = d[i];
    weight[i] = t;

    if( i == i_final ){

      break;

    }

    itr = vertex.erase( itr );
    list<PairForDijkstra<T> > changed_vertex{};

    while( itr != end ){

      const T& weight_curr = itr->Get();
      const T weight_temp = m_T( t , di[itr->index()] );

      if( weight_curr > weight_temp ){

	const int i_curr = itr->index();
	prev[i_curr] = i;
	itr = vertex.erase( itr );
	changed_vertex.push_back( PairForDijkstra<T>( weight_temp , i_curr ) );

      } else {

	itr++;

      }

    }

    for( auto itr_changed = changed_vertex.begin() , end_changed = changed_vertex.end() ; itr_changed != end_changed ; itr_changed++ ){

      vertex.insert( *itr_changed );

    }
    
  }

  int i = i_final;

  while( i != i_start ){

    path.push_front( i );
    i = prev[i];

  }

  path.push_front( i_start );
  return weight[ i_final ];
  
}
