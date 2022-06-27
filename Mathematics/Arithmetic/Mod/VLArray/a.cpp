// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/VLArray/a.cpp

#pragma once
#include "../../../Header.hpp"
#include "a_Body.hpp"

#include "../../../../Utility/VLArray/a_Body.hpp"

void LazyEvaluationOfModularInverse( const INT_TYPE_FOR_MOD& M , const INT_TYPE_FOR_MOD& n , INT_TYPE_FOR_MOD& m )
{

  static VLArray<VLArray<VLArray<INT_TYPE_FOR_MOD> > > a{};
  VLArray<VLArray<INT_TYPE_FOR_MOD> >* p = nullptr;

  for( auto itr = a.begin() , end = a.end() ; itr != end && p != nullptr ; itr++ ){

    if( itr->front().back() == M ){

      p = &( *itr );

    }

  }

  if( p == nullptr ){

    a.push_back( VLArray<VLArray<INT_TYPE_FOR_MOD> >() );
    p = &( a.back() );
    VLArray<INT_TYPE_FOR_MOD> inv_pair{};
    inv_pair.push_back( 0 );
    inv_pair.push_back( M );
    p->push_back( inv_pair );

  }

  for( auto itr = p->begin() , end = p->end() ; itr != end ; itr++ ){

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
  
  for( INT_TYPE_FOR_MOD i = 1 ; i < M ; i++ ){

    if( n * i % M_abs == 1 ){

      VLArray<INT_TYPE_FOR_MOD> inv_pair{};
      inv_pair.push_back( n );
      inv_pair.push_back( i );
      p->push_back( inv_pair );
      m = i;
      return;
      
    }

  }

  VLArray<INT_TYPE_FOR_MOD> inv_pair{};
  inv_pair.push_back( n );
  inv_pair.push_back( M );
  p->push_back( inv_pair );
  m = M;
  return;

}
