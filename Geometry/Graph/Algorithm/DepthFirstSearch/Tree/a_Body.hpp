// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

// ƒtƒ@ƒCƒ‹—e—ÊíŒ¸‚Ì‚½‚ß‹É—Ívector‚Ì¬•ª‚ğQÆ‚·‚é‚¾‚¯‚Ì•Ï”‚ğ—p‚¢‚È‚¢B
// ÀsŠÔ‚É—DˆÊ·‚Í‚È‚µB

template <typename TREE> inline DepthFirstSearchOnTree<TREE>::DepthFirstSearchOnTree( TREE& T , const int& root , const int& digit ) : DepthFirstSearch<int,TREE>( T , -1 , root ) , m_node_num() , m_children() , m_set_children() , m_depth() , m_set_depth() , m_height_max() , m_height_min() , m_set_height() , m_heaviness() , m_set_heaviness() , m_digit( digit ) , m_doubling( m_digit ) , m_set_doubling() { static_assert( is_same_v<TREE,Graph<decldecay_t( declval<TREE>().edge() )>> ); assert( int( ( m_node_num = this->GetNodeEnumeration() ).size() ) == this->size() ); }

template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Root() const { return this->Point(); }

template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Parent( const int& i ) { return this->prev( i ); }
template <typename TREE> inline const vector<int>& DepthFirstSearchOnTree<TREE>::Children( const int& i ) { if( ! m_set_children ){ SetChildren(); } return m_children[i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Depth( const int& i ) { if( !m_set_depth ){ SetDepth(); } return m_depth[i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Height( const int& i , const bool& maximum ) { if( !m_set_height ){ SetHeight(); } return ( maximum ? m_height_max : m_height_min )[i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Heaviness( const int& i ) { if( !m_set_heaviness ){ SetHeaviness(); } return m_heaviness[i]; }

template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::NodeNumber( const int& i , const bool& reversed ) const { const int& V = this->size(); assert( i < V ); return m_node_num[reversed ? V - 1 - i : i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::ChildrenNumber( const int& i ) { if( ! m_set_children ){ SetChildren(); } return m_children_num[i]; }

template <typename TREE>
int DepthFirstSearchOnTree<TREE>::Ancestor( int i , int n )
{

  if( !m_set_doubling ){

    SetDoubling();

  }

  assert( ( n >> m_digit ) == 0 );
    
  int d = 0;
  
  while( n != 0 ){

    assert( ( n & 1 ) == 1 ? ( i = m_doubling[d][i] ) != -1 : true );
    d++;
    n >>= 1;

  }

  return i;

}

template <typename TREE> inline int DepthFirstSearchOnTree<TREE>::LCA( int i , int j ) { int i_prev; int j_prev; return LCA( i , j , i_prev , j_prev ); }

template <typename TREE>
int DepthFirstSearchOnTree<TREE>::LCA( int i , int j , int& i_prev , int& j_prev )
{

  i_prev = j_prev = -1;
  const int diff = Depth( i ) - Depth( j );
  assert( diff > 0 ? ( i = Parent( i_prev = Ancestor( i , diff - 1 ) ) ) != -1 : diff < 0 ? ( j = Parent( j_prev = Ancestor( j , - diff - 1 ) ) ) != -1 : true );

  if( i != j ){
  
    if( !m_set_doubling ){

      SetDoubling();

    }
  
    int d = m_digit;

    while( --d >= 0 ){

      assert( m_doubling[d][i] != m_doubling[d][j] ? ( i = m_doubling[d][i] ) != -1 && ( j = m_doubling[d][j] ) != -1 : true );

    }

    assert( ( i = Parent( i_prev = i ) ) == ( j = Parent( j_prev = j ) ) );

  }
  
  return i;

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
      
      m_children_num[i] = m_children[j].size();
      m_children[j].push_back( i );

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
  
  for( int n = 1 ; n < V ; n++ ){

    const int& i = m_node_num[n];
    const int& j = Parent( i );
    assert( j != -1 );
    m_depth[i] += m_depth[j] + 1;

  }

  return;

}

template <typename TREE>
void DepthFirstSearchOnTree<TREE>::SetHeight()
{

  assert( !m_set_height );
  m_set_height = true;
  const int& V = this->size();
  m_height_max.resize( V );
  m_height_min.resize( V );
  
  for( int n = V - 1 ; n > 0 ; n-- ){

    const int& i = m_node_num[n];
    const int& j = Parent( i );
    assert( j != -1 );
    m_height_max[j] = max( m_height_max[j] , m_height_max[i] + 1 );
    m_height_min[j] = m_height_min[j] == 0 ? m_height_min[i] + 1 : min( m_height_min[j] , m_height_min[i] + 1 );

  }

  return;

}

template <typename TREE>
void DepthFirstSearchOnTree<TREE>::SetHeaviness()
{

  assert( !m_set_heaviness );
  m_set_heaviness = true;
  const int& V = this->size();
  m_heaviness.resize( V );
  
  for( int n = V - 1 ; n > 0 ; n-- ){

    const int& i = m_node_num[n];
    const int& j = Parent( i );
    assert( j != -1 );
    m_heaviness[j] += m_heaviness[i] + 1;

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
    
    m_doubling[0].reserve( V );

    for( int i = 0 ; i < V ; i++ ){

      m_doubling[0].push_back( Parent( i ) );

    }

  }
  
  for( int d = 1 ; d < m_digit ; d++ ){

    m_doubling[d].reserve( V );

    for( int i = 0 ; i < V ; i++ ){

      m_doubling[d].push_back( m_doubling[d-1][i] == -1 ? -1 : m_doubling[d-1][m_doubling[d-1][i]] );

    }

  }

  return;

}

template <typename TREE> template <typename F>
ret_t<F> DepthFirstSearchOnTree<TREE>::RootingDP( F& f )
{

  using U = ret_t<F>;
  static_assert( is_invocable_r_v<U,F,vector<U>,int> );

  if( ! m_set_children ){

    SetChildren();

  }
  
  const int& V = this->size();
  vector<vector<U>> children_value( V );
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
  
template <typename TREE> template <typename U , typename COMM_MONOID , typename F , typename G>
void DepthFirstSearchOnTree<TREE>::RerootingDP( COMM_MONOID M , F& f , G& g , vector<U>& d )
{

  static_assert( is_same_v<U,inner_t<COMM_MONOID>> && is_invocable_r_v<U,F,U,int> && is_invocable_r_v<U,G,U,bool,int,int> );
  
  if( ! m_set_children ){

    SetChildren();

  }
  
  const int& V = this->size();
  const U& e = M.Unit();
  d.resize( V );

  // children_value[i][m]‚Éi‚Ìm”Ô–Ú‚Ìqƒm[ƒhj‚Ü‚Å‚ÌŒvZ’l‚Ìf‚Å‚Ì‘œ‚ğŠi”[B
  vector<vector<U>> children_value( V );
  // l_sum[i][m]‚Échildren_value[i][0],...,children_value[i][m-1]‚Ì
  // g‚Å‚Ì‘œ‚ÌM‚ÉŠÖ‚·‚éÏ‚ğŠi”[B
  vector<vector<U>> l_sum( V );
  // r_sum[i][m]‚Échildren_value[i][m+1],...,children_value[i][size_i-1]‚Ì
  // g‚Å‚Ì‘œ‚ÌMŠÖ‚·‚éÏ‚ğŠi”[B
  vector<vector<U>> r_sum( V );
  
  for( int i = 0 ; i < V ; i++ ){

    children_value[i].resize( m_children[i].size() );

  }
  
  for( int n = 0 ; n < V ; n++ ){
    
    const int& i = NodeNumber( n , true );
    const vector<U>& children_value_i = children_value[i];
    const int size_i = children_value_i.size();

    U temp = e;
    l_sum[i].reserve( size_i + 1 );
    l_sum[i].push_back( temp );
    
    for( int m = 0 ; m < size_i ; m++ ){

      l_sum[i].push_back( temp = M.Product( temp , g( children_value_i[m] , true , i , m_children[i][m] ) ) );

    }
    
    const int& j = Parent( i );

    if( j != -1 ){
      
      children_value[j][m_children_num[i]] = f( temp , i );

    }

    temp = e;
    r_sum[i].resize( size_i );

    for( int m = 1 ; m <= size_i ; m++ ){

      r_sum[i][size_i - m] = temp;
      temp = M.Product( g( children_value_i[size_i - m] , true , i , m_children[i][size_i - m] ) , temp );

    }

  }

  // l_sum[i][m]‚Échildren_value[i][0],...,children_value[i][m-1]‚Ì
  // g‚Å‚Ì‘œ‚ÌM‚ÉŠÖ‚·‚éÏ‚ğŠi”[‚µ‚Ä‚¢‚½‚ªA‚³‚ç‚É‚±‚ê‚Éeƒm[ƒh‚ÌŠñ—^‚à’Ç‰Á‚·‚éB
  for( int n = 1 ; n < V ; n++ ){
    
    const int& i = NodeNumber( n );
    const int& j = Parent( i );
    const int& k = ChildrenNumber( i );
    const int size_i = r_sum[i].size();
    // children_value[j][0],...,children_value[j][k-1]‚Ìg‚Å‚Ì‘œ‚Æ
    // rest_jiŠù‚ÉŒvZÏ‚İj‚Æ
    // children_value[j][k+1],...,children_value[j][size_i-1]‚Ìg‚Å‚Ì‘œ‚Æ
    // ‚ÌM‚ÉŠÖ‚·‚éÏ‚Ìf‚Å‚Ì‘œ‚Ìg‚Å‚Ì‘œB
    const U rest_i = g( f( M.Product( l_sum[j][k] , r_sum[j][k] ) , j ) , false , i , j );
    
    for( int m = 0 ; m <= size_i ; m++ ){

      // l_sum[i][m]‚Érest_i‚Æchildren_value[i][0],...,children_value[i][m-1]‚Ì
      // g‚Å‚Ì‘œ‚ÌM‚ÉŠÖ‚·‚éÏ‚ğŠi”[B
      l_sum[i][m] = M.Product( rest_i , l_sum[i][m] );

    }

  }

  for( int i = 0 ; i < V ; i++ ){

    // l_sum[i].back()‚Íchildren_value_i[0],...,children_value_i[size_i-1]‚Ì
    // g‚Å‚Ì‘œ‚Æe‚ÌŠñ—^‚ÌM‚ÉŠÖ‚·‚éÏB
    d[i] = f( l_sum[i].back() , i );

  }

  return;

}
