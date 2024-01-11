// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename E> inline DepthFirstSearchOnTree<E>::DepthFirstSearchOnTree( const int& V , E e , const int& root , const int& digit ) :
  DepthFirstSearch<E>( V , move( e ) , root ) , m_reversed( V ) , m_children() , m_set_children() , m_depth() , m_set_depth() , m_height() , m_set_height() , m_weight() , m_set_weight() , m_digit( digit ) , m_doubling( m_digit ) , m_set_doubling()
{

  int n = V;
  
  while( --n >= 0 ){
    
    m_reversed[n] = DepthFirstSearch<E>::Next();

  }

}

template <typename E> inline const int& DepthFirstSearchOnTree<E>::Root() const { return DepthFirstSearch<E>::init(); }

template <typename E> inline const int& DepthFirstSearchOnTree<E>::Parent( const int& i ) const { return DepthFirstSearch<E>::prev( i ); }
template <typename E> inline const vector<int>& DepthFirstSearchOnTree<E>::Children( const int& i ) { if( ! m_set_children ){ SetChildren(); } return m_children[i]; }
template <typename E> inline const int& DepthFirstSearchOnTree<E>::Depth( const int& i ) const { if( ! m_set_depth ){ SetDepth(); } return m_depth[i]; }
template <typename E> inline const int& DepthFirstSearchOnTree<E>::Height( const int& i ) { if( ! m_set_height ){ SetHeight(); } return m_height[i]; }
template <typename E> inline const int& DepthFirstSearchOnTree<E>::Weight( const int& i ) { if( ! m_set_weight ){ SetWeight(); } return m_weight[i]; }

template <typename E> inline const int& DepthFirstSearchOnTree<E>::NodeNumber( const int& i , const bool& reversed ) const { return m_reversed[reversed ? i : DepthFirstSearch<E>::size() - 1 - i]; }
template <typename E> inline const int& DepthFirstSearchOnTree<E>::ChildrenNumber( const int& i ) { if( ! m_set_children ){ SetChildren(); } return m_children_num[i]; }

template <typename E>
int DepthFirstSearchOnTree<E>::Ancestor( int i , int n )
{

  if( ! m_set_doubling ){

    SetDoubling();

  }

  assert( ( n >> m_digit ) == 0 );
    
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

template <typename E>
int DepthFirstSearchOnTree<E>::LCA( int i , int j )
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
    
  int d = m_digit;

  while( --d >= 0 ){

    const vector<int>& doubling_d = m_doubling[d];
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

template <typename E>
int DepthFirstSearchOnTree<E>::LCA( int i , int j , int& i_prev , int& j_prev )
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
    
  int d = m_digit;

  while( --d >= 0 ){

    const vector<int>& doubling_d = m_doubling[d];
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

template <typename E>
void DepthFirstSearchOnTree<E>::SetChildren()
{

  assert( !m_set_children );
  m_set_children = true;
  const int& V = DepthFirstSearch<E>::size();
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

template <typename E>
void DepthFirstSearchOnTree<E>::SetDepth()
{

  assert( !m_set_depth );
  m_set_depth = true;
  const int& V = DepthFirstSearch<E>::size();
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

template <typename E>
void DepthFirstSearchOnTree<E>::SetHeight()
{

  assert( !m_set_height );
  m_set_height = true;
  const int& V = DepthFirstSearch<E>::size();
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

template <typename E>
void DepthFirstSearchOnTree<E>::SetWeight()
{

  assert( !m_set_weight );
  m_set_weight = true;
  const int& V = DepthFirstSearch<E>::size();
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

template <typename E>
void DepthFirstSearchOnTree<E>::SetDoubling()
{

  assert( !m_set_doubling );
  m_set_doubling = true;
  const int& V = DepthFirstSearch<E>::size();
  
  {
    
    vector<int>& doubling_0 = m_doubling[0];
    doubling_0.reserve( V );
    const int& r = Root();

    for( int i = 0 ; i < V ; i++ ){

      doubling_0.push_back( Parent( i ) );

    }

  }
  
  for( int d = 1 ; d < m_digit ; d++ ){

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

template <typename E> template <typename T , T f(const list<T>&,const int&)>
T DepthFirstSearchOnTree<E>::RootingDP()
{

  if( ! m_set_children ){

    SetChildren();

  }
  
  const int& V = DepthFirstSearch<E>::size();
  vector<list<T>> children_value( V );
  T temp;
  
  for( int n = 0 ; n < V ; n++ ){
    
    const int& i = NodeNumber( n , true );
    const int& j = Parent( i );
    temp = f( children_value[i] , i );

    if( j != -1 ){

      children_value[j].push_back( temp );

    }

  }

  return temp;

}
  
template <typename E> template <typename T , T m_T(const T&,const T&) ,const T& e_T() , T f(const T&,const int&), T g(const T&,const bool&,const int&,const int&)>
void DepthFirstSearchOnTree<E>::RerootingDP( vector<T>& d )
{

  if( ! m_set_children ){

    SetChildren();

  }
  
  const int& V = DepthFirstSearch<E>::size();
  const T& e = e_T();
  d.resize( V );

  // children_value[i][m]‚Éi‚Ìm”Ô–Ú‚Ìqƒm[ƒhj‚Ü‚Å‚ÌŒvZ’l‚Ìf‚Å‚Ì‘œ‚ğŠi”[B
  vector<vector<T>> children_value( V );
  // left_sum[i][m]‚Échildren_value[i][0],...,children_value[i][m-1]‚Ì
  // g‚Å‚Ì‘œ‚Ìm_T‚ÉŠÖ‚·‚éÏ‚ğŠi”[B
  vector<vector<T>> left_sum( V );
  // right_sum[i][m]‚Échildren_value[i][m+1],...,children_value[i][size_i-1]‚Ì
  // g‚Å‚Ì‘œ‚Ìm_T‚ÉŠÖ‚·‚éÏ‚ğŠi”[B
  vector<vector<T>> right_sum( V );
  
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

      left_sum_i.push_back( temp = m_T( temp , g( children_value_i[m] , true , i , m_children[i][m] ) ) );

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
      temp = m_T( g( children_value_i[size_i - m] , true , i , m_children[i][size_i - m] ) , temp );

    }

  }

  // left_sum[i][m]‚Échildren_value[i][0],...,children_value[i][m-1]‚Ì
  // g‚Å‚Ì‘œ‚Ìm_T‚ÉŠÖ‚·‚éÏ‚ğŠi”[‚µ‚Ä‚¢‚½‚ªA‚³‚ç‚É‚±‚ê‚Éeƒm[ƒh‚ÌŠñ—^‚à’Ç‰Á‚·‚éB
  for( int n = 1 ; n < V ; n++ ){
    
    const int& i = NodeNumber( n );
    const int& j = Parent( i );
    const int& k = ChildrenNumber( i );
    vector<T>& left_sum_i = left_sum[i];
    vector<T>& right_sum_i = right_sum[i];
    const int size_i = right_sum_i.size();
    // children_value[j][0],...,children_value[j][k-1]‚Ìg‚Å‚Ì‘œ‚Æ
    // rest_jiŠù‚ÉŒvZÏ‚İj‚Æ
    // children_value[j][k+1],...,children_value[j][size_i-1]‚Ìg‚Å‚Ì‘œ‚Æ
    // ‚Ìm_T‚ÉŠÖ‚·‚éÏ‚Ìf‚Å‚Ì‘œ‚Ìg‚Å‚Ì‘œB
    const T rest_i = g( f( m_T( left_sum[j][k] , right_sum[j][k] ) , j ) , false , i , j );
    
    for( int m = 0 ; m <= size_i ; m++ ){

      // left_sum_im‚Érest_i‚Æ
      // children_value[i][0],...,children_value[i][m-1]‚Ìg‚Å‚Ì‘œ
      // ‚Ìm_T‚ÉŠÖ‚·‚éÏ‚ğŠi”[B
      T& left_sum_im = left_sum_i[m];
      left_sum_im = m_T( rest_i , left_sum_im );

    }

  }

  for( int i = 0 ; i < V ; i++ ){

    // left_sum[i].back()‚Íchildren_value_i[0],...,children_value_i[size_i-1]‚Ì
    // g‚Å‚Ì‘œ‚Æe‚ÌŠñ—^‚Ìm_T‚ÉŠÖ‚·‚éÏB
    d[i] = f( left_sum[i].back() , i );

  }

  return;

}
