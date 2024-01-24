// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/FloydWarshall/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Algebra/Monoid/Semirng/a_Body.hpp"

template <typename U , typename IDEMPOTENT_SEMIRNG>
void FloydWarshall( IDEMPOTENT_SEMIRNG R , const vector<vector<U>>& d , vector<vector<U>>& weight )
{

  const int size = d.size();
  assert( size > 0 ? size == int( d[0].size() ) : true );
  weight = d;
  const U& infty = R.Infty();

  for( int k = 0 ; k < size ; k++ ){

    auto& weight_k = weight[k];

    for( int i = 0 ; i < size ; i++ ){

      auto& weight_i = weight[i];
      const U& weight_ik = weight_i[k];
    
      if( i != k && weight_ik != infty ){
	
	for( int j = 0 ; j < size ; j++ ){

	  const U& weight_kj = weight_k[j];

	  if( i != j && k != j && weight_kj != infty ){

	    U& weight_ij = weight_i[j];
	    weight_ij = R.Meet( weight_ij , R.Product( weight_ik , weight_kj ) );

	  }

	}

      }

    }

  }

  return;

}

template <typename U , typename TROPICAL_SEMIRNG>
void FloydWarshall( TROPICAL_SEMIRNG R , const vector<vector<U>>& d , vector<vector<U>>& weight , vector<vector<int>>& path )
{

  const int size = d.size();
  assert( size > 0 ? size == int( d[0].size() ) : true );
  weight = d;
  path = vector<vector<int>>( size , vector<int>( size , -1 ) );
  const U& infty = R.Infty();

  for( int k = 0 ; k < size ; k++ ){

    auto& weight_k = weight[k];

    for( int i = 0 ; i < size ; i++ ){

      auto& weight_i = weight[i];
      auto& path_i = path[i];
      const U& weight_ik = weight_i[k];
    
      if( i != k && weight_ik != infty ){
	
	for( int j = 0 ; j < size ; j++ ){

	  const U& weight_kj = weight_k[j];

	  if( i != j && k != j && weight_kj != infty ){

	    U& weight_ij = weight_i[j];
	    U weight_curr = R.Product( weight_ik , weight_kj );

	    if( weight_ij > weight_curr ){

	      weight_ij = move( weight_curr );
	      path_i[j] = k;

	    }

	  }

	}

      }

    }

  }

  return;

}
