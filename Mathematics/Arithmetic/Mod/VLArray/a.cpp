// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/VLArray/a.cpp

#include "../../../Header.hpp"
#include "a_Body.hpp"

#include "../../../../Utility/VLArray/a_Body.hpp"

void LazyEvaluationOfModularInverse( const INT_TYPE_FOR_MOD& M , const INT_TYPE_FOR_MOD& n , INT_TYPE_FOR_MOD& m )
{

  static VLArray<INT_TYPE_FOR_MOD> memory_M{};
  static VLArray<VLArray<INT_TYPE_FOR_MOD> > memory_inverse{};

  auto itr_M = memory_M.begin() , end_M = memory_M.end();
  auto itr_inverse = memory_inverse.begin();

  VLArray<INT_TYPE_FOR_MOD>* p_inverse = nullptr;
  
  while( itr_M != end_M && p_inverse == nullptr ){

    if( *itr_M == M ){

      p_inverse = &( *itr_inverse );

    }

    itr_M++;
    itr_inverse++;

  }
  
  if( p_inverse == nullptr ){

    memory_M.push_front( M );
    memory_inverse.push_front( VLArray<INT_TYPE_FOR_MOD>() );
    p_inverse = &( memory_inverse.front() );
    p_inverse->push_back( M );

  }

  const INT_TYPE_FOR_MOD size = p_inverse->size();
  
  if( n < size ){

    if( n + n < size ){

      auto itr_m = p_inverse->begin();
      
      for( INT_TYPE_FOR_MOD i = 0 ; i < n ; i++ ){

	itr_m++;

      }

      m = *itr_m;

    } else {

      auto itr_m = p_inverse->end();
      
      for( INT_TYPE_FOR_MOD i = size ; i > n ; i-- ){

	itr_m--;

      }

      m = *itr_m;

    }

    return;

  }

  if( n != size ){

    INT_TYPE_FOR_MOD n_decr_inv;
    LazyEvaluationOfModularInverse( M , n - 1 , n_decr_inv );

  }

  const INT_TYPE_FOR_MOD M_abs = M >= 0 ? M : -M;
  const INT_TYPE_FOR_MOD n_sub = M_abs % n;
  INT_TYPE_FOR_MOD n_sub_inv;
  LazyEvaluationOfModularInverse( M , n_sub , n_sub_inv );

  if( n_sub_inv != M ){

    m = M_abs - ( ( n_sub_inv * ( M_abs / n ) ) % M_abs );
    VLArray<INT_TYPE_FOR_MOD> inv_pair{};
    p_inverse->push_back( m );
    return;

  }
  
  for( INT_TYPE_FOR_MOD i = 1 ; i < M_abs ; i++ ){
    
    if( ( n * i ) % M_abs == 1 ){

      m = i;
      p_inverse->push_back( m );
      return;
      
    }

  }

  m = M;
  p_inverse->push_back( M );
  return;

}
