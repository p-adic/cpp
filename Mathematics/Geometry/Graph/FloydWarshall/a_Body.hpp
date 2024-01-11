// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/FloydWarshall/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , typename M_T , typename A_T>
void FloydWarshall( M_T m_T , A_T a_T , const vector<vector<T>>& d , vector<vector<T>>& weight , const T& infty )
{

  const int size = d.size();
  assert( size > 0 ? size == int( d[0].size() ) : true );
  weight = d;

  for( int k = 0 ; k < size ; k++ ){

    auto& weight_k = weight[k];

    for( int i = 0 ; i < size ; i++ ){

      auto& weight_i = weight[i];
      const T& weight_ik = weight_i[k];
    
      if( i != k && weight_ik != infty ){
	
	for( int j = 0 ; j < size ; j++ ){

	  const T& weight_kj = weight_k[j];

	  if( i != j && k != j && weight_kj != infty ){

	    T& weight_ij = weight_i[j];
	    const T weight_curr = m_T( weight_ik , weight_kj );
	    weight_ij = weight_ij == infty ? weight_curr : a_T( weight_ij , weight_curr );

	  }

	}

      }

    }

  }

  return;

}

template <typename T , typename M_T>
void FloydWarshall( M_T m_T , const vector<vector<T>>& d , vector<vector<T>>& weight , const T& infty , vector<vector<int>>& path )
{

  const int size = d.size();
  assert( size > 0 ? size == int( d[0].size() ) : true );
  weight = d;
  path = vector<vector<int>>( size , vector<int>( size , -1 ) );

  for( int k = 0 ; k < size ; k++ ){

    auto& weight_k = weight[k];

    for( int i = 0 ; i < size ; i++ ){

      auto& weight_i = weight[i];
      auto& path_i = path[i];
      const T& weight_ik = weight_i[k];
    
      if( i != k && weight_ik != infty ){
	
	for( int j = 0 ; j < size ; j++ ){

	  const T& weight_kj = weight_k[j];

	  if( i != j && k != j && weight_kj != infty ){

	    T& weight_ij = weight_i[j];
	    const T weight_curr = m_T( weight_ik , weight_kj );

	    if( weight_ij == infty ? true : weight_ij > weight_curr ){

	      weight_ij = weight_curr;
	      path_i[j] = k;

	    }

	  }

	}

      }

    }

  }

  return;

}


