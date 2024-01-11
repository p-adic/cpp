// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Function/Map/a_Body.hpp"

template <typename T , typename U , typename E> inline Dijkstra_Body<T,U,E>::Dijkstra_Body( const int& size , const U& infty , const U& found , E edge ) : m_size( size ) , m_infty( infty ) , m_found( found ) , m_edge( move( edge ) ) { static_assert( ! is_same_v<U,int> && is_invocable_r_v<list<pair<T,U>>,E,T> ); }
template <typename E> inline Dijkstra<E>::Dijkstra( const int& size , E edge ) : Dijkstra_Body<int,ll,E>( size , 9223372036854775807 , -1 , move( edge ) ) {}
template <typename T , typename U , typename M_U , typename E_U , typename E> inline MonoidForDijkstra<T,U,M_U,E_U,E>::MonoidForDijkstra( const int& size , M_U m_U , E_U e_U , const U& infty , const U& found , E edge ) : Dijkstra_Body<T,U,E>( size , infty , found , move( edge ) ) , m_m_U( move( m_U ) ) , m_e_U( move( e_U ) ) {}
template <typename T , typename U , typename M_U , typename E_U , typename E> template <typename U2> inline MemorisationDijkstra<T,U,M_U,E_U,E>::MemorisationDijkstra( const int& size , M_U m_U , E_U e_U , const U& infty , const U2& found , E edge ) : MonoidForDijkstra<T,U,M_U,E_U,E>( size , move( m_U ) , move( e_U ) , infty , found , move( edge ) ) , m_length() , m_memory() , m_memory_inv() { static_assert( is_constructible_v<U,U2> ); }
template <typename T , typename Enum_T , typename Enum_T_inv , typename U , typename M_U , typename E_U , typename E> template <typename U2> inline EnumerationDijkstra<T,Enum_T,Enum_T_inv,U,M_U,E_U,E>::EnumerationDijkstra( const int& size , Enum_T enum_T , Enum_T_inv enum_T_inv , M_U m_U , E_U e_U , const U& infty , const U2& found , E edge ) : MonoidForDijkstra<T,U,M_U,E_U,E>( size , move( m_U ) , move( e_U ) , infty , found , move( edge ) ) , m_enum_T( move( enum_T ) ) , m_enum_T_inv( move( enum_T_inv ) ) { static_assert( is_constructible_v<U,U2> ); }

template <typename T , typename U , typename E>
U Dijkstra_Body<T,U,E>::Solve( const T& t_start , const T& t_final )
{

  const int i_final = e_inv( t_final );
  DIJKSTRA_BODY( , vector<U> weight( m_size , m_infty ) , weight[i] = m_found , weight_j != m_found , , );
  Reset();
  return weight[i_final];

}

template <typename T , typename U , typename E>
U Dijkstra_Body<T,U,E>::Solve( const T& t_start , const T& t_final , list<T>& path )
{

  const int i_final = e_inv( t_final );					\
  DIJKSTRA_BODY( , vector<U> weight( m_size , m_infty ) , weight[i] = m_found , weight_j != m_found , vector<int> prev( m_size ) , prev[j] = i );
  int i = i_final;

  while( i != i_start ){

    path.push_front( e( i ) );
    i = prev[i];

  }

  path.push_front( t_start );
  Reset();
  return weight[i_final];

}

template <typename T , typename U , typename E>
void Dijkstra_Body<T,U,E>::Solve( const T& t_start , vector<U>& weight )
{

  constexpr const int i_final = -1;
  DIJKSTRA_BODY( vector<bool> found( m_size ) , weight = vector<U>( m_size , m_infty ) , found[i] = true , !found[j] , , );
  Reset();
  return;

}

template <typename T , typename U , typename E>
void Dijkstra_Body<T,U,E>::Solve( const T& t_start , vector<U>& weight , vector<list<T>>& path )
{

  constexpr const int i_final = -1;
  DIJKSTRA_BODY( vector<bool> found( m_size ) , weight = vector<U>( m_size , m_infty ) , found[i] = true , !found[j] , vector<int> prev( m_size ) , prev[j] = i );

  for( int j = 0 ; j < m_size ; j++ ){

    list<T>& path_j = path[j];
    int i = j;

    while( i != i_start ){

      path_j.push_front( e( i ) );
      i = prev[i];

    }

    path_j.push_front( t_start );

  }

  Reset();
  return;

}

template <typename T , typename U , typename E> const U& Dijkstra_Body<T,U,E>::Infty() const { return m_infty; }

template <typename E> inline const ll& Dijkstra<E>::Unit() const { static const ll unit = 0; return unit; }
template <typename T , typename U , typename M_U , typename E_U , typename E> inline const U& MonoidForDijkstra<T,U,M_U,E_U,E>::Unit() const { return m_e_U(); }

template <typename E> inline ll Dijkstra<E>::Addition( const ll& u0 , const ll& u1 ) const { return u0 + u1; }
template <typename T , typename U , typename M_U , typename E_U , typename E> inline U MonoidForDijkstra<T,U,M_U,E_U,E>::Addition( const U& u0 , const U& u1 ) const { return m_m_U( u0 , u1 ); }

template <typename E> inline int Dijkstra<E>::e( const int& i ) { return i; }
template <typename T , typename U , typename M_U , typename E_U , typename E> inline T MemorisationDijkstra<T,U,M_U,E_U,E>::e( const int& i ) { assert( i < m_length ); return m_memory_inv[i]; }
template <typename T , typename Enum_T , typename Enum_T_inv , typename U , typename M_U , typename E_U , typename E> inline T EnumerationDijkstra<T,Enum_T,Enum_T_inv,U,M_U,E_U,E>::e( const int& i ) { return m_enum_T( i ); }

template <typename E> inline int Dijkstra<E>::e_inv( const int& t ) { return t; }

template <typename T , typename U , typename M_U , typename E_U , typename E> inline int MemorisationDijkstra<T,U,M_U,E_U,E>::e_inv( const T& t )
{

  using base = Dijkstra_Body<T,U,E>;
  
  if( m_memory.count( t ) == 0 ){

    assert( m_length < base::m_size );
    m_memory_inv.push_back( t );
    return m_memory[t] = m_length++;

  }
  
  return m_memory[t];

}

template <typename T , typename Enum_T , typename Enum_T_inv , typename U , typename M_U , typename E_U , typename E> inline int EnumerationDijkstra<T,Enum_T,Enum_T_inv,U,M_U,E_U,E>::e_inv( const T& t ) { return m_enum_T_inv( t ); }

template <typename T , typename U , typename E> inline void Dijkstra_Body<T,U,E>::Reset() {}
template <typename T , typename U , typename M_U , typename E_U , typename E> inline void MemorisationDijkstra<T,U,M_U,E_U,E>::Reset() { m_length = 0; m_memory.clear(); m_memory_inv.clear(); }
