// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename TREE> inline DepthFirstSearchOnTree<TREE>::DepthFirstSearchOnTree( TREE& T , const int& root , const int& digit ) :
  DepthFirstSearch<TREE>( T , root ) , m_reversed( this->size() ) , m_children() , m_set_children() , m_depth() , m_set_depth() , m_height() , m_set_height() , m_weight() , m_set_weight() , m_digit( digit ) , m_doubling( m_digit ) , m_set_doubling()
{

  int n = this->size();
  
  while( --n >= 0 ){
    
    m_reversed[n] = this->Next();

  }

}

template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Root() const { return this->init(); }

template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Parent( const int& i ) { return this->prev( i ); }
template <typename TREE> inline const vector<int>& DepthFirstSearchOnTree<TREE>::Children( const int& i ) { if( ! m_set_children ){ SetChildren(); } return m_children[i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Depth( const int& i ) { if( ! m_set_depth ){ SetDepth(); } return m_depth[i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Height( const int& i ) { if( ! m_set_height ){ SetHeight(); } return m_height[i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Weight( const int& i ) { if( ! m_set_weight ){ SetWeight(); } return m_weight[i]; }

template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::NodeNumber( const int& i , const bool& reversed ) const { return m_reversed[reversed ? i : this->size() - 1 - i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::ChildrenNumber( const int& i ) { if( ! m_set_children ){ SetChildren(); } return m_children_num[i]; }

template <typename TREE>
int DepthFirstSearchOnTree<TREE>::Ancestor( int i , int n )
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

template <typename TREE>
int DepthFirstSearchOnTree<TREE>::LCA( int i , int j )
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

template <typename TREE>
int DepthFirstSearchOnTree<TREE>::LCA( int i , int j , int& i_prev , int& j_prev )
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

template <typename TREE>
void DepthFirstSearchOnTree<TREE>::SetChildren()
{

  assert( !m_set_children );
  m_set_children = true;
  const int& V = this->size();
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

template <typename TREE>
void DepthFirstSearchOnTree<TREE>::SetDepth()
{

  assert( !m_set_depth );
  m_set_depth = true;
  const int& V = this->size();
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

template <typename TREE>
void DepthFirstSearchOnTree<TREE>::SetHeight()
{

  assert( !m_set_height );
  m_set_height = true;
  const int& V = this->size();
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

template <typename TREE>
void DepthFirstSearchOnTree<TREE>::SetWeight()
{

  assert( !m_set_weight );
  m_set_weight = true;
  const int& V = this->size();
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

template <typename TREE>
void DepthFirstSearchOnTree<TREE>::SetDoubling()
{

  assert( !m_set_doubling );
  m_set_doubling = true;
  const int& V = this->size();
  
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

template <typename TREE> template <typename F>
ret_t<F> DepthFirstSearchOnTree<TREE>::RootingDP( F& f )
{

  using U = ret_t<F>;
  static_assert( is_invocable_r_v<U,F,list<U>,int> );

  if( ! m_set_children ){

    SetChildren();

  }
  
  const int& V = this->size();
  vector<list<U>> children_value( V );
  U temp;
  
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
  
template <typename TREE> template <typename MONOID , typename F , typename G>
void DepthFirstSearchOnTree<TREE>::RerootingDP( MONOID M , F& f , G& g , vector<inner_t<MONOID>>& d )
{

  using U = inner_t<MONOID>;
  static_assert( is_invocable_r_v<U,F,U,int> && is_invocable_r_v<U,G,U,bool,int,int> );
  
  if( ! m_set_children ){

    SetChildren();

  }
  
  const int& V = this->size();
  const U& e = M.Unit();
  d.resize( V );

  // children_value[i][m]‚Éi‚Ìm”Ô–Ú‚Ìqƒm[ƒhj‚Ü‚Å‚ÌŒvZ’l‚Ìf‚Å‚Ì‘œ‚ğŠi”[B
  vector<vector<U>> children_value( V );
  // left_sum[i][m]‚Échildren_value[i][0],...,children_value[i][m-1]‚Ì
  // g‚Å‚Ì‘œ‚ÌM‚ÉŠÖ‚·‚éÏ‚ğŠi”[B
  vector<vector<U>> left_sum( V );
  // right_sum[i][m]‚Échildren_value[i][m+1],...,children_value[i][size_i-1]‚Ì
  // g‚Å‚Ì‘œ‚ÌMŠÖ‚·‚éÏ‚ğŠi”[B
  vector<vector<U>> right_sum( V );
  
  for( int i = 0 ; i < V ; i++ ){

    children_value[i].resize( m_children[i].size() );

  }
  
  for( int n = 0 ; n < V ; n++ ){
    
    const int& i = NodeNumber( n , true );
    const vector<U>& children_value_i = children_value[i];
    const int size_i = children_value_i.size();

    U temp = e;
    vector<U>& left_sum_i = left_sum[i];
    left_sum_i.reserve( size_i + 1 );
    left_sum_i.push_back( temp );
    
    for( int m = 0 ; m < size_i ; m++ ){

      left_sum_i.push_back( temp = M.Product( temp , g( children_value_i[m] , true , i , m_children[i][m] ) ) );

    }
    
    const int& j = Parent( i );

    if( j != -1 ){
      
      children_value[j][m_children_num[i]] = f( temp , i );

    }

    temp = e;
    vector<U>& right_sum_i = right_sum[i];
    right_sum_i.resize( size_i );

    for( int m = 1 ; m <= size_i ; m++ ){

      right_sum_i[ size_i - m ] = temp;
      temp = M.Product( g( children_value_i[size_i - m] , true , i , m_children[i][size_i - m] ) , temp );

    }

  }

  // left_sum[i][m]‚Échildren_value[i][0],...,children_value[i][m-1]‚Ì
  // g‚Å‚Ì‘œ‚ÌM‚ÉŠÖ‚·‚éÏ‚ğŠi”[‚µ‚Ä‚¢‚½‚ªA‚³‚ç‚É‚±‚ê‚Éeƒm[ƒh‚ÌŠñ—^‚à’Ç‰Á‚·‚éB
  for( int n = 1 ; n < V ; n++ ){
    
    const int& i = NodeNumber( n );
    const int& j = Parent( i );
    const int& k = ChildrenNumber( i );
    vector<U>& left_sum_i = left_sum[i];
    vector<U>& right_sum_i = right_sum[i];
    const int size_i = right_sum_i.size();
    // children_value[j][0],...,children_value[j][k-1]‚Ìg‚Å‚Ì‘œ‚Æ
    // rest_jiŠù‚ÉŒvZÏ‚İj‚Æ
    // children_value[j][k+1],...,children_value[j][size_i-1]‚Ìg‚Å‚Ì‘œ‚Æ
    // ‚ÌM‚ÉŠÖ‚·‚éÏ‚Ìf‚Å‚Ì‘œ‚Ìg‚Å‚Ì‘œB
    const U rest_i = g( f( M.Product( left_sum[j][k] , right_sum[j][k] ) , j ) , false , i , j );
    
    for( int m = 0 ; m <= size_i ; m++ ){

      // left_sum_im‚Érest_i‚Æ
      // children_value[i][0],...,children_value[i][m-1]‚Ìg‚Å‚Ì‘œ
      // ‚ÌM‚ÉŠÖ‚·‚éÏ‚ğŠi”[B
      U& left_sum_im = left_sum_i[m];
      left_sum_im = M.Product( rest_i , left_sum_im );

    }

  }

  for( int i = 0 ; i < V ; i++ ){

    // left_sum[i].back()‚Íchildren_value_i[0],...,children_value_i[size_i-1]‚Ì
    // g‚Å‚Ì‘œ‚Æe‚ÌŠñ—^‚ÌM‚ÉŠÖ‚·‚éÏB
    d[i] = f( left_sum[i].back() , i );

  }

  return;

}
