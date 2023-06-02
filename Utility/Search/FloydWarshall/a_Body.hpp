// c:/Users/user/Documents/Programming/Utility/Search/FloydWarshall/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
T FloydWarshall( const T ( &d )[size_max][size_max] , T ( &weight )[size_max][size_max] , const int& size , const T& infty )
{

  for( int i = 0 ; i < size ; i++ ){

    T ( &weight_i )[size_max] = weight[i];
    const T ( &d_i )[size_max] = d[i];
    
    for( int j = 0 ; j < size ; j++ ){

      weight_i[j] = d_i[j];

    }

  }

  for( int k = 0 ; k < size ; k++ ){

    T ( &weight_k )[size_max] = weight[k];

    for( int i = 0 ; i < size ; i++ ){

      T ( &weight_i )[size_max] = weight[i];
      const T& weight_ik = weight_i[k];
    
      if( weight_ik != infty ){
	
	for( int j = 0 ; j < size ; j++ ){

	  const T& weight_kj = weight_k[j];

	  if( weight_kj != infty ){

	    T& weight_ij = weight_i[j];
	    const T weight_curr = m_T( weight_ik , weight_kj );

	    if( weight_ij == infty ? true : weight_ij > weight_curr ){

	      weight_ij = weight_curr;

	    }

	  }

	}

      }

    }

  }

  return;

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
T FloydWarshall( const T ( &d )[size_max][size_max] , T ( &weight )[size_max][size_max] , const int& size , const T& infty , int ( &path )[size_max][size_max] )
{

  for( int i = 0 ; i < size ; i++ ){

    T ( &weight_i )[size_max] = weight[i];
    T ( &path_i )[size_max] = path[i];
    const T ( &d_i )[size_max] = d[i];
    
    for( int j = 0 ; j < size ; j++ ){

      weight_i[j] = d_i[j];
      path_i[j] = -1;

    }

  }

  for( int k = 0 ; k < size ; k++ ){

    T ( &weight_k )[size_max] = weight[k];

    for( int i = 0 ; i < size ; i++ ){

      T ( &weight_i )[size_max] = weight[i];
      T ( &path_i )[size_max] = path[i];
      const T& weight_ik = weight_i[k];
    
      if( weight_ik != infty ){
	
	for( int j = 0 ; j < size ; j++ ){

	  const T& weight_kj = weight_k[j];

	  if( weight_kj != infty ){

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
