// c:/Users/user/Documents/Programming/Mathematics/Game/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../SetTheory/Mex/a_Body.hpp"
#include "../../Utility/Set/Map/a_Body.hpp"

template <typename Edge , typename T>
const bool& HasNonZeroGrundyNumber( Edge& edge , const T& t , const bool& reset )
{

  static_assert( is_invocable_v<Edge,const T&> );
  static Map<T,bool> g{};

  if( reset ){

    g.clear();

  }

  if( g.count( t ) == 1 ){

    return g[t];

  }

  bool b = false;

  for( auto&& u : edge( t ) ){

    b |= !HasNonZeroGrundyNumber( edge , u );

  }

  return ( g[t] = b );

}

template <typename AEdge , typename T>
const int& GrundyNumber( AEdge& aedge , const T& t , const bool& reset )
{

  static_assert( is_invocable_v<AEdge,const T&> );
  static Map<T,int> g{};

  if( reset ){

    g.clear();

  }

  if( g.count( t ) == 1 ){

    return g[t];

  }

  auto&& next = aedge( t );
  MexSet mex{ int( next.size() ) };

  for( auto&& a : next ){

    int temp = 0;

    for( auto&& u : a ){

      temp ^= GrundyNumber( aedge , u );

    }

    mex.insert( temp );
    
  }

  return g[t] = mex.Get();

}
