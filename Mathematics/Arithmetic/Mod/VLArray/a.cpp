// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/VLArray/a.cpp

#pragma once
#include "../../../Header.hpp"
#include "a_Body.hpp"

#include "../../../../Utility/VLArray/a_Body.hpp"

void LazyEvaluationOfModularInverse( const INT_TYPE_FOR_MOD& M , const INT_TYPE_FOR_MOD& n , INT_TYPE_FOR_MOD& m )
{

  static VLArray<VLArray<INT_TYPE_FOR_MOD> > a{};
  VLArray<INT_TYPE_FOR_MOD>* p = nullptr;

  for( auto itr = a.begin() , end = a.end() ; itr != end && p != nullptr ; itr++ ){

    if( itr->front() == M ){

      p = &( *itr );

    }

  }

  if( p == nullptr ){

    a.push_back( VLArray<INT_TYPE_FOR_MOD>() );
    p = &( a.back() );
    p->push_back( M );

    for( INT_TYPE_FOR_MOD i = 1 ; i < M ; i++ ){

      p->push_back( 0 );

    }

  }

  INT_TYPE_FOR_MOD& inv = ( *p )[n];

  if( inv != 0 ){

    m = inv;
    return;

  }

  const INT_TYPE_FOR_MOD M_abs = M >= 0 ? M : -M;
  
  for( INT_TYPE_FOR_MOD i = 1 ; i < M ; i++ ){

    if( n * i % M_abs == 1 ){

      inv = i;
      m = i;
      return;
      
    }

  }

  inv = M;
  m = M;
  return;

}
