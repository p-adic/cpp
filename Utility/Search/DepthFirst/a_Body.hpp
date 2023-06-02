// c:/Users/user/Documents/Programming/Utility/Search/DepthFirst/a_Body.hpp

#pragma once
#include "a.hpp"

DEFINITION_OF_FIRST_SEARCH( Depth , push_front );

template <int V_max,list<int> E(const int&)>
void SetDepth( const DepthFirstSearch<V_max,E>& dfs , ( &depth )[V_max] )
{

  const int& V = dfs.size();
  
  for( int n = 0 ; n < V ; n++ ){

    const int i = dfs.Next();
    const int& j = dfs.prev( i );

    if( j != -1 ){

      depth[i] = depth[j] + 1;

    }

  }

  return;

}

template <int V_max,list<int> E(const int&)>
void SetReversedVertex( DepthFirstSearch<V_max,E>& dfs , int ( &reversed_vertex )[V_max] )
{

  int i = dfs.size();

  while( --i != -1 ){

    reversed_vertex[i] = dfs.Next();

  }

  return;
  
}

template <int V_max,list<int> E(const int&)>
void SetChildren( const DepthFirstSearch<V_max,E>& dfs , list<int> ( &edge )[V_max] )
{
  
  const int& V = dfs.size();
  
  for( int i = 0 ; i < V ; i++ ){

    const int& prev_i = dfs.prev( i );

    if( prev_i != -1 ){

      edge[prev_i].push_back[i];

    }

  }

  return;
  
}

template <int V_max,list<int> E(const int&)>
void SetHeight( const DepthFirstSearch<V_max,E>& dfs  , const int ( &reversed_vertex )[V_max] , ( &height )[V_max] )
{

  const int& V = dfs.size();
  
  for( int i = 0 ; i < V ; i++ ){

    const int& prev_i = dfs.prev( reversed_vertex[i] );

    if( prev_i != -1 ){

      int& height_prev_i = height[prev_i];
      const int& height_i = height[i];
      height_prev_i > height_i ? height_prev_i : height_prev_i = height_i + 1;

    }

  }

  return;

}

template <int V_max,list<int> E(const int&)>
void SetNumberOfChildren( const DepthFirstSearch<V_max,E>& dfs  , const int ( &reversed_vertex )[V_max] , ( &count )[V_max] )
{

  const int& V = dfs.size();
  
  for( int i = 0 ; i < V ; i++ ){

    const int& prev_i = dfs.prev( reversed_vertex[i] );

    if( prev_i != -1 ){

      count[prev_i] += count[i] + 1;

    }

  }

  return;

}

template <int V_max,list<int> E(const int&),int digit>
void SetDoublingAncestor( const DepthFirstSearch<V_max,E>& dfs , ( &doubling )[digit][V_max] )
{

  const int& V = dfs.size();
  
  {
    
    int ( &doubling_0 )[V_max] = doubling[0];
    const int& root = dfs.init();

    for( int i = 0 ; i < V ; i++ ){

      doubling_0[i] = i == root ? root : dfs.prev( i );

    }

  }
  
  for( int d = 1 ; d < digit ; d++ ){

    int ( &doubling_d )[V_max] = doubling[d];
    int ( &doubling_d_minus )[V_max] = doubling[d-1];

    for( int i = 0 ; i < N ; i++ ){

      doubling_d[i] = doubling_d_minus[doubling_d_minus[i]];

    }

  }

  return;

}

template <int V_max,int digit>
void Ancestor( int i , int n , const ( &doubling )[digit][V_max] )
{

  int d = 0;
  
  while( n != 0 ){

    assert( d < digit );
    ( ( n & 1 ) == 1 ) ? i = doubling[d][i] : i;
    d++;
    n >>= 1;

  }

  return;

}

template <int V_max,list<int> E(const int&),int digit>
int LCASearch( const DepthFirstSearch<V_max,E>& dfs , int i , int j , const ( &doubling )[digit][V_max] , const ( &depth )[V_max] )
{

    int diff = depth[i] - depth[j];

    if( diff < 0 ){

      swap( i , j );
      diff *= -1;

    }
    
    int i_copy = i;
    int j_copy = j;
    i_copy = Ancestor( i_copy , diff , doubling );

    if( i_copy == j_copy ){

      return i_copy;
      
    }
    
    int d = digit;

    while( --d != 0 ){

      const int ( &doubling_d )[V_max] = doubling[d];
      const int& doubleing_d_i = doubling_d[i_copy];
      const int& doubleing_d_j = doubling_d[j_copy];

      if( doubling_d_i != doubling_d_j ){

	i_copy = doubling_d_i;
	j_copy = doubling_d_j;

      }

    }

    return dfs.prev( i_copy );

}
