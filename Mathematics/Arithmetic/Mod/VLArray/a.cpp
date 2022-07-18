// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/VLArray/a.cpp

#include "../../../Header.hpp"
#include "a_Body.hpp"

#include "../../../../Utility/VLArray/a_Body.hpp"
#include <vector>

void LazyEvaluationOfModularInverse( const INT_TYPE_FOR_MOD& M , const INT_TYPE_FOR_MOD& n , INT_TYPE_FOR_MOD& m )
{

  static VLArray<INT_TYPE_FOR_MOD> memory_M{};

  // vector‚Å‚È‚­VLArray‚¾‚Æˆø”‚ª¬‚³‚¢‡‚ÉŒÄ‚Ño‚µ‚½‚ÌŒvZ—Ê‚ªO(1)‚©‚çO(n)‚É’µ‚Ëã‚ª‚Á‚Ä‚µ‚Ü‚¤B
  static VLArray<vector<INT_TYPE_FOR_MOD> > memory_inverse{};

  auto itr_M = memory_M.begin() , end_M = memory_M.end();
  auto itr_inverse = memory_inverse.begin();

  vector<INT_TYPE_FOR_MOD>* p_inverse = nullptr;
  
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

  for( INT_TYPE_FOR_MOD i = size ; i <= n ; i++ ){

    p_inverse->push_back( 0 );

  }
  
  INT_TYPE_FOR_MOD& n_inv = ( *p_inverse )[n];

  if( n_inv != 0 ){

    m = n_inv;
    return;

  }

  const INT_TYPE_FOR_MOD M_abs = M >= 0 ? M : -M;
  const INT_TYPE_FOR_MOD n_sub = M_abs % n;
  INT_TYPE_FOR_MOD n_sub_inv;
  LazyEvaluationOfModularInverse( M , n_sub , n_sub_inv );

  if( n_sub_inv != M ){

    n_inv = M_abs - ( ( n_sub_inv * ( M_abs / n ) ) % M_abs );
    m = n_inv;
    return;

  }
  
  for( INT_TYPE_FOR_MOD i = 1 ; i < M_abs ; i++ ){
    
    if( ( n * i ) % M_abs == 1 ){

      n_inv = i
      m = n_inv;
      return;
      
    }

  }

  n_inv = M;
  m = n_inv;
  return;

}
