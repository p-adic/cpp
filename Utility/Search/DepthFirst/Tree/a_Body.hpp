// c:/Users/user/Documents/Programming/Utility/Search/DepthFirst/Tree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <int V_max,list<int> E(const int&),int digit> inline DepthFirstSearchOnTree<V_max,E,digit>::DepthFirstSearchOnTree( const int& V , const int& root ) : DepthFirstSearch<V_max,E>( V , root ) , m_reversed() , m_children() , m_set_children() , m_depth() , m_set_depth() , m_height() , m_set_height() , m_weight() , m_set_weight() , m_doubling() , m_set_doubling() { int i = size(); while( --i >= 0 ){ reversed[i] = Next(); } }

template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::root() const { return init(); }

template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::parent( const int& i ) { return prev( i ); }
template <int V_max,list<int> E(const int&),int digit> inline const list<int>& DepthFirstSearchOnTree<V_max,E,digit>::children( const int& i ) { if( ! m_set_children ){ SetChildren(); } return m_children[i]; }
template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::depth( const int& i ) { if( ! m_set_depth ){ SetDepth(); } return m_depth[i]; }
template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::height( const int& i ) { if( ! m_set_height ){ SetHeight(); } return height[i]; }
template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::weight( const int& i ) { if( ! m_set_weight ){ SetWeight(); } return weight[i]; }

template <int V_max,list<int> E(const int&),int digit>
int DepthFirstSearchOnTree<V_max,E,digit>::Ancestor( int i , int n )
{

  if( ! m_set_doubling ){

    SetDoubling();

  }
    
  int d = 0;
  
  while( n != 0 ){

    assert( d < digit );
    ( ( n & 1 ) == 1 ) ? i = m_doubling[d++][i] : i;
    n >>= 1;

  }

  return i;

}

template <int V_max,list<int> E(const int&),int digit>
int DepthFirstSearchOnTree<V_max,E,digit>::LCA( int i , int j )
{

  int diff = depth( i ) - depth( j );

  if( diff < 0 ){

    swap( i , j );
    diff *= -1;

  }
    
  int i_copy = i;
  int j_copy = j;
  i_copy = Ancestor( i_copy , diff );

  if( i_copy == j_copy ){

    return i_copy;
      
  }
    
  int d = digit;

  while( --d != 0 ){

    const int ( &doubling_d )[V_max] = m_doubling[d];
    const int& doubleing_d_i = m_doubling_d[i_copy];
    const int& doubleing_d_j = m_doubling_d[j_copy];

    if( doubling_d_i != doubling_d_j ){

      i_copy = doubling_d_i;
      j_copy = doubling_d_j;

    }

  }

  return parent( i_copy );

}

template <int V_max,list<int> E(const int&),int digit>
void DepthFirstSearchOnTree<V_max,E,digit>::SetChildren()
{

  assert( !m_set_children );
  m_set_children = true;
  const int& V = size();
  
  for( int i = 0 ; i < V ; i++ ){

    const int& parent_i = parent( i );

    if( parent_i != -1 ){

      m_children[parent_i].push_back( i );

    }

  }

  return;
  
}

template <int V_max,list<int> E(const int&),int digit>
void DepthFirstSearchOnTree<V_max,E,digit>::SetDepth()
{

  assert( !m_set_depth );
  m_set_depth = true;
  const int& V = size();
  
  for( int n = 0 ; n < V ; n++ ){

    const int i = Next();
    const int& j = parent( i );

    if( j != -1 ){

      m_depth[i] = m_depth[j] + 1;

    }

  }

  return;

}

template <int V_max,list<int> E(const int&),int digit>
void DepthFirstSearchOnTree<V_max,E,digit>::SetHeight()
{

  assert( !m_set_height );
  m_set_height = true;
  const int& V = size();
  
  for( int i = 0 ; i < V ; i++ ){

    const int& parent_i = parent( m_reversed[i] );

    if( parent_i != -1 ){

      int& height_parent_i = m_height[parent_i];
      const int& height_i = m_height[i];
      height_parent_i > height_i ? height_parent_i : height_parent_i = height_i + 1;

    }

  }

  return;

}

template <int V_max,list<int> E(const int&),int digit>
void DepthFirstSearchOnTree<V_max,E,digit>::SetWeight( const DepthFirstSearch<V_max,E>& dfs  , const int ( &reversed_vertex )[V_max] , ( &count )[V_max] )
{

  assert( !m_set_weight );
  m_set_weight = true;
  const int& V = size();
  
  for( int i = 0 ; i < V ; i++ ){

    const int& parent_i = parent( m_reversed[i] );

    if( parent_i != -1 ){

      m_weight[parent_i] += m_weight[i] + 1;

    }

  }

  return;

}

template <int V_max,list<int> E(const int&),int digit>
void DepthFirstSearchOnTree<V_max,E,digit>::SetDoubling( const DepthFirstSearch<V_max,E>& dfs , ( &doubling )[digit][V_max] )
{

  assert( !m_set_doubling );
  m_set_doubling = true;
  const int& V = size();
  
  {
    
    int ( &doubling_0 )[V_max] = m_doubling[0];
    const int& r = root();

    for( int i = 0 ; i < V ; i++ ){

      doubling_0[i] = i == r ? r : parent( i );

    }

  }
  
  for( int d = 1 ; d < digit ; d++ ){

    int ( &doubling_d )[V_max] = m_doubling[d];
    int ( &doubling_d_minus )[V_max] = m_doubling[d-1];

    for( int i = 0 ; i < V ; i++ ){

      doubling_d[i] = doubling_d_minus[doubling_d_minus[i]];

    }

  }

  return;

}

