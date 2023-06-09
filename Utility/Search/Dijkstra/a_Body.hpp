// c:/Users/user/Documents/Programming/Utility/Search/Dijkstra/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , typename U , list<pair<T,U> > E(const T&) , int size_max> inline DijkstraBody<T,U,E,size_max>::DijkstraBody( const int& size , const U& infty , const U& found ) : m_size( size ) , m_infty( infty ) , m_found( found ) , m_length() , m_memory() , m_memory_inv() {}
template <list<pair<int,ll> > E(const int&) , int size_max> inline Dijkstra<E,size_max>::Dijkstra( const int& size ) : DijkstraBody<int,ll,E,size_max>( size , 2147483647 , -1 ) {}
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&) , int size_max> inline MemorisationDijkstra<T,U,m_U,e_U,E,size_max>::MemorisationDijkstra( const int& size , const U& infty , const U& found ) : DijkstraBody<T,U,E,size_max>( size , infty , found ) {}
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline EnumerationDijkstra<T,U,m_U,e_U,E,size_max,enum_T,enum_T_inv>::EnumerationDijkstra( const int& size , const U& infty , const U& found ) : DijkstraBody<T,U,E,size_max>( size , infty , found ) {}

template <typename T , typename U , list<pair<T,U> > E(const T&) , int size_max>
U DijkstraBody<T,U,E,size_max>::Solve( const T& t_start , const T& t_final )
{

  DIJKSTRA_BODY( , );
  Reset();
  return weight[i_final];

}

template <typename T , typename U , list<pair<T,U> > E(const T&) , int size_max>
U DijkstraBody<T,U,E,size_max>::Solve( const T& t_start , const T& t_final , list<T>& path )
{

  DIJKSTRA_BODY( T prev[size_max] = {} , prev[j] = i );
  int i = i_final;

  while( i != i_start ){

    path.push_front( e( i ) );
    i = prev[i];

  }

  path.push_front( t_start );
  Reset();
  return weight[i_final];

}

template <list<pair<int,ll> > E(const int&) , int size_max> inline ll Dijkstra<E,size_max>::Unit() const { static const ll unit = 0; return unit; }
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&) , int size_max> inline U MemorisationDijkstra<T,U,m_U,e_U,E,size_max>::Unit() const { return e_U(); }
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline U EnumerationDijkstra<T,U,m_U,e_U,E,size_max,enum_T,enum_T_inv>::Unit() const { return e_U(); }

template <list<pair<int,ll> > E(const int&) , int size_max> inline const ll& Dijkstra<E,size_max>::Addition( const ll& u0 , const ll& u1 ) const { return u0 + u1; }
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&) , int size_max> inline const U& MemorisationDijkstra<T,U,m_U,e_U,E,size_max>::Addition( const U& u0 , const U& u1 ) const { return m_U( u0 , u1 ); }
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline const U& EnumerationDijkstra<T,U,m_U,e_U,E,size_max,enum_T,enum_T_inv>::Addition( const U& u0 , const U& u1 ) const { return m_U( u0 , u1 ); }

template <typename T , typename U , list<pair<T,U> > E(const T&) , int size_max>
T DijkstraBody<T,U,E,size_max>::e( const int& i )
{
  
  assert( i < m_length );
  return m_memory_inv[i];

}

template <list<pair<int,ll> > E(const int&) , int size_max> inline int Dijkstra<E,size_max>::e( const int& i ) { return i; }
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline T EnumerationDijkstra<T,U,m_U,e_U,E,size_max,enum_T,enum_T_inv>::e( const int& i ) { return enum_T( i ); }

template <typename T , typename U , list<pair<T,U> > E(const T&) , int size_max>
int DijkstraBody<T,U,E,size_max>::e_inv( const T& t )
{

  if( m_memory.count( t ) == 0 ){

    assert( m_length < m_size );
    m_memory_inv.push_back( t );
    return m_memory[t] = m_length++;

  }
  
  return m_memory[t];

}

template <list<pair<int,ll> > E(const int&) , int size_max> inline int Dijkstra<E,size_max>::e_inv( const int& t ) { return t; }
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline int EnumerationDijkstra<T,U,m_U,e_U,E,size_max,enum_T,enum_T_inv>::e_inv( const T& t ) { return enum_T_inv( t ); }

template <typename T , typename U , list<pair<T,U> > E(const T&) , int size_max>
void DijkstraBody<T,U,E,size_max>::Reset()
{

  m_length = 0;
  m_memory.clear();
  m_memory_inv.clear();
  return;

}

template <list<pair<int,ll> > E(const int&) , int size_max> inline void Dijkstra<E,size_max>::Reset() {}
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline void EnumerationDijkstra<T,U,m_U,e_U,E,size_max,enum_T,enum_T_inv>::Reset() {}
