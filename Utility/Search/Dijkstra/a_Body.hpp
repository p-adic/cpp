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
T Dijkstra( const T ( &d )[size_max][size_max] , const int& i_start , const int& i_final , const int& size , const T& weight_max )
{

  DIJKSTRA_BODY( , );
  return weight[ i_final ];
  
}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
T Dijkstra( const T ( &d )[size_max][size_max] , const int& i_start , const int& i_final , const int& size , const T& weight_max , list<int>& path )
{

  DIJKSTRA_BODY( int prev[size_max] = {} , prev[i_curr] = i );

  int i = i_final;

  while( i != i_start ){

    path.push_front( i );
    i = prev[i];

  }

  path.push_front( i_start );
  return weight[ i_final ];
  
}
