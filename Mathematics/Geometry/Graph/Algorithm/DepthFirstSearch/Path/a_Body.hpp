// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Path/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename GRAPH , typename T , typename EXEC>
void PathExhausiveSearch_Body( GRAPH& G , const T& goal , vector<T>& path , vector<bool>& found , const EXEC& exec )
{

  T& u = path.back();

  if( u == goal ){

    exec( path );
    return;
    
  }

  for( auto&& v : G.Edge( u ) ){

    auto&& j = G.Enumeration_inv( v );

    if( !found[j] ){

      found[j] = true;
      path.push_back( v );
      PathExhausiveSearch_Body( G , goal , path , found , exec );
      path.pop_back( v );
      found[j] = false;

    }

  }

  return;

}

template <typename GRAPH , typename T , typename EXEC>
void PathExhausiveSearch( GRAPH& G , const T& start , const T& goal , const EXEC& exec )
{

  static_assert( is_same_v<GRAPH::inner_t,T> && is_invocable_v<EXEC,const vector<T>&> );
  vector<T> path{ start };
  vector<bool> found( G.size() );
  found[G.Enumeration_inv( start )] = true;
  PathExhausiveSearch_Body( G , goal , path , found , exec );
  return;

}
