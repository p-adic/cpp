// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <int V_max,list<int> E(const int&),int digit> inline DepthFirstSearchOnTree<V_max,E,digit>::DepthFirstSearchOnTree( const int& V , const int& root ) :
  DepthFirstSearch<V_max,E>( V , root ) , m_reversed() , m_children() , m_set_children() , m_depth() , m_set_depth , m_height() , m_set_height() , m_weight() , m_set_weight() , m_doubling() , m_set_doubling()
{

  int n = DepthFirstSearch<V_max,E>::size();
  
  while( --n >= 0 ){
    
    m_reversed[n] = DepthFirstSearch<V_max,E>::Next();

  }

}

template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::Root() const { return DepthFirstSearch<V_max,E>::init(); }

template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::Parent( const int& i ) const { return DepthFirstSearch<V_max,E>::prev( i ); }
template <int V_max,list<int> E(const int&),int digit> inline const vector<int>& DepthFirstSearchOnTree<V_max,E,digit>::Children( const int& i ) { if( ! m_set_children ){ SetChildren(); } return m_children[i]; }
template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::Depth( const int& i ) const { if( ! m_set_depth ){ SetDepth(); } return m_depth[i]; }
template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::Height( const int& i ) { if( ! m_set_height ){ SetHeight(); } return m_height[i]; }
template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::Weight( const int& i ) { if( ! m_set_weight ){ SetWeight(); } return m_weight[i]; }

template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::NodeNumber( const int& i , const bool& reversed ) const { return m_reversed[reversed ? i : DepthFirstSearch<V_max,E>::size() - 1 - i]; }
template <int V_max,list<int> E(const int&),int digit> inline const int& DepthFirstSearchOnTree<V_max,E,digit>::ChildrenNumber( const int& i ) { if( ! m_set_children ){ SetChildren(); } return m_children_num[i]; }

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
  m_children.resize( V );
  m_children_num.resize( V );
  
  for( int i = 0 ; i < V ; i++ ){

    const int& j = Parent( i );

    if( j == -1 ){

      m_children_num[i] = -1;

    } else {
      
      vector<int>& m_children_j = m_children[j];
      m_children_num[i] = m_children_j.size();
      m_children_j.push_back( i );

    }

  }

  return;
  
}

template <int V_max,list<int> E(const int&),int digit>
void DepthFirstSearchOnTree<V_max,E,digit>::SetDepth()
{

  assert( !m_set_depth );
  m_set_depth = true;
  const int& V = DepthFirstSearch<V_max,E>::size();
  m_depth.resize( V );
  
  for( int i = 0 ; i < V ; i++ ){

    const int& reversed_i = m_reversed[i];
    const int& parent_i = Parent( reversed_i );

    if( parent_i != -1 ){

      m_depth[i] += m_depth[parent_i] + 1;

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
  m_height.resize( V );
  
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
  m_weight.resize( V );
  
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
    
    vector<int>& doubling_0 = m_doubling[0];
    doubling_0.reserve( V );
    const int& r = Root();

    for( int i = 0 ; i < V ; i++ ){

      doubling_0.push_back( Parent( i ) );

    }

  }
  
  for( int d = 1 ; d < digit ; d++ ){

    vector<int>& doubling_d = m_doubling[d];
    vector<int>& doubling_d_minus = m_doubling[d-1];
    doubling_d.reserve( V );

    for( int i = 0 ; i < V ; i++ ){

      const int& doubling_d_minus_i = doubling_d_minus[i];
      doubling_d.push_back( doubling_d_minus_i == -1 ? -1 : doubling_d_minus[doubling_d_minus_i] );

    }

  }

  return;

}

template <int V_max,list<int> E(const int&),int digit> template <typename T , T f(const list<T>&,const int&)>
T DepthFirstSearchOnTree<V_max,E,digit>::RootingDP()
{

  if( ! m_set_children ){

    SetChildren();

  }
  
  const int& V = DepthFirstSearch<V_max,E>::size();
  list<T> children_value[V_max] = {};
  
  for( int n = 0 ; n < V ; n++ ){
    
    const int& i = NodeNumber( n , true );
    const int& j = Parent( i );

    if( j != -1 ){

      children_value[j].push_back( f( children_value[i] , i ) );

    }

  }

  return temp;

}
  
template <int V_max,list<int> E(const int&),int digit> template <typename T , T m_T(const T&,const T&) ,const T& e_T() , T f(const T&,const int&)>
void DepthFirstSearchOnTree<V_max,E,digit>::RerootingDP( T ( &d )[V_max] )
{

  if( ! m_set_children ){

    SetChildren();

  }
  
  const int& V = DepthFirstSearch<V_max,E>::size();
  const T& e = e_T();
  vector<T> children_value[V_max] = {};
  vector<T> left_sum[V_max] = {};
  vector<T> right_sum[V_max] = {};
  
  for( int i = 0 ; i < V ; i++ ){
    
    children_value[i].resize( m_children[i].size() );

  }
  
  for( int n = 0 ; n < V ; n++ ){
    
    const int& i = NodeNumber( n , true );
    const vector<T>& children_value_i = children_value[i];
    const int size_i = children_value_i.size();

    T temp = e;
    vector<T>& left_sum_i = left_sum[i];
    left_sum_i.reserve( size_i + 1 );
    left_sum_i.push_back( temp );
    
    for( int m = 0 ; m < size_i ; m++ ){

      left_sum_i.push_back( temp = m_T( temp , children_value_i[m] ) );

    }
    
    const int& j = Parent( i );

    if( j != -1 ){
      
      children_value[j][m_children_num[i]] = f( temp , i );

    }

    temp = e;
    vector<T>& right_sum_i = right_sum[i];
    right_sum_i.resize( size_i );

    for( int m = 1 ; m <= size_i ; m++ ){

      right_sum_i[ size_i - m ] = temp;
      temp = m_T( children_value_i[size_i - m] , temp );

    }

  }

  for( int n = 1 ; n < V ; n++ ){
    
    const int& i = NodeNumber( n );
    const int& j = Parent( i );
    const int& k = ChildrenNumber( i );
    vector<T>& left_sum_i = left_sum[i];
    vector<T>& right_sum_i = right_sum[i];
    const int size_i = right_sum_i.size();
    const T rest_i = f( m_T( left_sum[j][k] , right_sum[j][k] ) , j );
    
    for( int m = 0 ; m <= size_i ; m++ ){

      T& left_sum_im = left_sum_i[m];
      left_sum_im = m_T( rest_i , left_sum_im );

    }

  }

  for( int i = 0 ; i < V ; i++ ){

    d[i] = f( left_sum[i].back() , i );

  }

  return;

}
  
