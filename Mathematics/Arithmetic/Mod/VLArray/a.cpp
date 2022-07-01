// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/VLArray/a.cpp

#include "../../../Header.hpp"
#include "a_Body.hpp"

#include "../../../../Utility/VLArray/a_Body.hpp"

void LazyEvaluationOfModularInverse( const INT_TYPE_FOR_MOD& M , const INT_TYPE_FOR_MOD& n , INT_TYPE_FOR_MOD& m )
{

  static INT_TYPE_FOR_MOD M_prev = 0;
  static VLArray<VLArray<VLArray<INT_TYPE_FOR_MOD> > > a{};
  static VLArray<VLArray<INT_TYPE_FOR_MOD> >* p_prev = nullptr;

  if( M_prev != M ){

    p_prev = nullptr;
    
    for( auto itr = a.begin() , end = a.end() ; itr != end && p_prev != nullptr ; itr++ ){

      if( itr->front().back() == M ){

	p_prev = &( *itr );

      }

    }

    if( p_prev == nullptr ){

      a.push_back( VLArray<VLArray<INT_TYPE_FOR_MOD> >() );
      p_prev = &( a.back() );
      VLArray<INT_TYPE_FOR_MOD> inv_pair{};
      inv_pair.push_back( 0 );
      inv_pair.push_back( M );
      p_prev->push_back( inv_pair );
      inv_pair.clear();
      inv_pair.push_back( 1 );
      inv_pair.push_back( 1 );

    }

  }
  
  for( auto itr = p_prev->begin() , end = p_prev->end() ; itr != end ; itr++ ){

    if( itr->front() == n ){

      m = itr->back();
      return;

    }

    if( itr->back() == n ){

      m = itr->front();
      return;

    }
    
  }

  const INT_TYPE_FOR_MOD M_abs = M >= 0 ? M : -M;
  const INT_TYPE_FOR_MOD n_sub = M_abs % n;
  INT_TYPE_FOR_MOD n_sub_inv;
  LazyEvaluationOfModularInverse( M , n_sub , n_sub_inv );

  if( n_sub_inv != M ){

    m = M_abs - ( ( n_sub_inv * ( M_abs / n ) ) % M_abs );
    VLArray<INT_TYPE_FOR_MOD> inv_pair{};
    inv_pair.push_back( n );
    inv_pair.push_back( m );
    p_prev->push_back( inv_pair );
    return;

  }
  
  for( INT_TYPE_FOR_MOD i = 1 ; i < M_abs ; i++ ){
    
    if( ( n * i ) % M_abs == 1 ){

      m = i;
      VLArray<INT_TYPE_FOR_MOD> inv_pair{};
      inv_pair.push_back( n );
      inv_pair.push_back( m );
      p_prev->push_back( inv_pair );
      return;
      
    }

  }

  m = M;
  VLArray<INT_TYPE_FOR_MOD> inv_pair{};
  inv_pair.push_back( n );
  inv_pair.push_back( m );
  p_prev->push_back( inv_pair );
  return;

}
