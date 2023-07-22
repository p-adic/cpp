// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <int V_max,list<int> E(const int&),int digit> inline DepthFirstSearchOnTree<V_max,E,digit>::DepthFirstSearchOnTree( const int& V , const int& root ) :
  DepthFirstSearch<V_max,E>( V , root ) , m_reversed() , m_children() , m_set_children() , m_depth() , m_height() , m_set_height() , m_weight() , m_set_weight() , m_doubling() , m_set_doubling()
{

  int n = DepthFirstSearch<V_max,E>::size();
  
  while( --n >= 0 ){
    
    const int& i = m_reversed[n] = DepthFirstSearch<V_max,E>::Next();
    const int& j = Parent( i );

    if( j != -1 ){

      m_depth[i] = m_depth[j] + 1;

    }

  }

}

template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::Root() const { return DepthFirstSearch<V_max,E>::init(); }

template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::Parent( const int& i ) const { return DepthFirstSearch<V_max,E>::prev( i ); }
template <int V_max,list<int> E(const int&),int digit> inline const list<int>& DepthFirstSearchOnTree<V_max,E,digit>::Children( const int& i ) { if( ! m_set_children ){ SetChildren(); } return m_children[i]; }
template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::Depth( const int& i ) const { return m_depth[i]; }
template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::Height( const int& i ) { if( ! m_set_height ){ SetHeight(); } return m_height[i]; }
template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::Weight( const int& i ) { if( ! m_set_weight ){ SetWeight(); } return m_weight[i]; }

template <int V_max,list<int> E(const int&),int digit>
int DepthFirstSearchOnTree<V_max,E,digit>::Ancestor( int i , int n )
{

  if( ! m_set_doubling ){

    SetDoubling();

  }

  assert( ( n >> digit ) == 0 );
    
  int d = 0;
  
  while( n != 0 ){

    if( ( n & 1 ) == 1 ){

      assert( ( i = m_doubling[d][i] ) != -1 );

    }
    
    d++;
    n >>= 1;

  }

  return i;

}

template <int V_max,list<int> E(const int&),int digit>
int DepthFirstSearchOnTree<V_max,E,digit>::LCA( int i , int j )
{

  int diff = Depth( i ) - Depth( j );

  if( diff < 0 ){

    swap( i , j );
    diff *= -1;

  }
    
  i = Ancestor( i , diff );

  if( i == j ){

    return i;
      
  }
    
  int d = digit;

  while( --d >= 0 ){

    const int ( &doubling_d )[V_max] = m_doubling[d];
    const int& doubling_d_i = doubling_d[i];
    const int& doubling_d_j = doubling_d[j];

    if( doubling_d_i != doubling_d_j ){

      i = doubling_d_i;
      j = doubling_d_j;
      assert( i != -1 );
      assert( j != -1 );

    }

  }

  return Parent( i );

}

template <int V_max,list<int> E(const int&),int digit>
int DepthFirstSearchOnTree<V_max,E,digit>::LCA( int i , int j , int& i_prev , int& j_prev )
{

  if( i == j ){

    i_prev = j_prev = -1;
    return i;

  }
  
  int diff = Depth( i ) - Depth( j );

  if( diff < 0 ){

    return LCA( j , i , j_prev , i_prev );

  }
  
  if( diff > 0 ){

    i_prev = Ancestor( i , diff - 1 );
    i = Parent( i_prev );
    assert( i != -1 );
    
    if( i == j ){

      j_prev = -1;
      return i;
      
    }
    
  } else if( ! m_set_doubling ){

    SetDoubling();

  }
    
  int d = digit;

  while( --d >= 0 ){

    const int ( &doubling_d )[V_max] = m_doubling[d];
    const int& doubling_d_i = doubling_d[i];
    const int& doubling_d_j = doubling_d[j];

    if( doubling_d_i != doubling_d_j ){

      i = doubling_d_i;
      j = doubling_d_j;
      assert( i != -1 );
      assert( j != -1 );

    }

  }

  i_prev = i;
  j_prev = j;
  return Parent( i_prev );

}

template <int V_max,list<int> E(const int&),int digit>
void DepthFirstSearchOnTree<V_max,E,digit>::SetChildren()
{

  assert( !m_set_children );
  m_set_children = true;
  const int& V = DepthFirstSearch<V_max,E>::size();
  
  for( int i = 0 ; i < V ; i++ ){

    const int& parent_i = Parent( i );

    if( parent_i != -1 ){

      m_children[parent_i].push_back( i );

    }

  }

  return;
  
}

template <int V_max,list<int> E(const int&),int digit>
void DepthFirstSearchOnTree<V_max,E,digit>::SetHeight()
{

  assert( !m_set_height );
  m_set_height = true;
  const int& V = DepthFirstSearch<V_max,E>::size();
  
  for( int i = 0 ; i < V ; i++ ){

    const int& reversed_i = m_reversed[i];
    const int& parent_i = Parent( reversed_i );

    if( parent_i != -1 ){

      int& height_parent_i = m_height[parent_i];
      const int& height_i = m_height[reversed_i];
      height_parent_i > height_i ? height_parent_i : height_parent_i = height_i + 1;

    }

  }

  return;

}

template <int V_max,list<int> E(const int&),int digit>
void DepthFirstSearchOnTree<V_max,E,digit>::SetWeight()
{

  assert( !m_set_weight );
  m_set_weight = true;
  const int& V = DepthFirstSearch<V_max,E>::size();
  
  for( int i = 0 ; i < V ; i++ ){

    const int& reversed_i = m_reversed[i];
    const int& parent_i = Parent( reversed_i );

    if( parent_i != -1 ){

      m_weight[parent_i] += m_weight[reversed_i] + 1;

    }

  }

  return;

}

template <int V_max,list<int> E(const int&),int digit>
void DepthFirstSearchOnTree<V_max,E,digit>::SetDoubling()
{

  assert( !m_set_doubling );
  m_set_doubling = true;
  const int& V = DepthFirstSearch<V_max,E>::size();
  
  {
    
    int ( &doubling_0 )[V_max] = m_doubling[0];
    const int& r = Root();

    for( int i = 0 ; i < V ; i++ ){

      doubling_0[i] = Parent( i );

    }

  }
  
  for( int d = 1 ; d < digit ; d++ ){

    int ( &doubling_d )[V_max] = m_doubling[d];
    int ( &doubling_d_minus )[V_max] = m_doubling[d-1];

    for( int i = 0 ; i < V ; i++ ){

      const int& doubling_d_minus_i = doubling_d_minus[i];
      doubling_d[i] = doubling_d_minus_i == -1 ? -1 : doubling_d_minus[doubling_d_minus_i];

    }

  }

  return;

}

