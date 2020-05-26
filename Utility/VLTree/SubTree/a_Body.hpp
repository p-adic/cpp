// c:/Users/user/Documents/Programming/Utility/VLTree/SubTree/a_Body.hpp

#pragma once
#include "a.hpp"

// ERR_CALL経由のIndicateIllegalCallの呼び出しに必要
#include "../../../Error/IllegalCall/a.hpp"

#include "../Iterator/a_Body.hpp"
#include "../../WrappedType/a_Body.hpp"
#include "../../../Error/IllegalImput/a_Body.hpp"

template <typename T> inline VLSubTree<T>::VLSubTree() : m_e() , m_root( m_e ) , m_size( 0 ) {}
template <typename T> template <typename Arg1 , typename... Arg2> inline VLSubTree<T>::VLSubTree( const Arg1& t0 , const Arg2&... t1 ) : VLSubTree<T>() { push_RightMost( t0 , t1... ); }

template <typename T> template <typename Arg> inline VLSubTree<T>::VLSubTree( const WrappedType<Arg>& t ) : m_e( t.Get() ) , m_root( m_e ) , m_size( 0 ) {}

template <typename T> inline VLSubTree<T>::VLSubTree( const VLSubTree<T>& a ) : m_e( a.m_e.m_t ) , m_root( m_e ) , m_size( 0 ) { LeafToTree( a ); }

template <typename T>
VLSubTree<T>::VLSubTree( EntryOfVLTree<T>& e ) :
  m_e( e ) , m_root( e ) , m_size( 0 )
{

  EntryOfVLTree<T>* p = m_root.m_leftmost_node;

  if( p != &m_root ){

    m_size++;

    EntryOfVLTree<T>* const p_rightmost = m_root.m_rightmost_node;

    while( p != p_rightmost ){

      p = p->m_right_branch;
      m_size++;

    }
  
  }
  
}

template <typename T> inline VLSubTree<T>::VLSubTree( const IteratorOfVLTree<T>& itr ) : VLSubTree( *( itr.m_p ) ) {}

template <typename T>
VLSubTree<T>::VLSubTree( const int& dummy , const EntryOfVLTree<T>& e ) :
  m_e( e.m_t ) , m_root( m_e ) , m_size( 0 )
{

  const EntryOfVLTree<T>* p = e.m_leftmost_node;
  const EntryOfVLTree<T>* const p_rightmost = e.m_rightmost_node;
  bool b = ( p != &e );

  while( b ){

    push_RightMost( VLTree<T>( dummy , *p ) );
    b = ( p != p_rightmost );
    p = p->m_right_branch;

  }

}

template <typename T> inline VLSubTree<T>::VLSubTree( const int& dummy , const ConstIteratorOfVLTree<T>& itr ) : VLSubTree( dummy , *( itr.m_p ) ) {}

template <typename T>
VLSubTree<T>& VLSubTree<T>::operator=( const VLSubTree<T>& a )
{

  if( this != &a ){
    
    CutBranches();
    LeafToTree( a );
  
  }

  return *this;

}

template <typename T>
void VLSubTree<T>::LeafToTree( const VLSubTree<T>& a )
{

  m_root.m_t = a.m_root.m_t;
  EntryOfVLTree<T>* p = a.m_root.m_leftmost_node;
  const uint& N = a.m_size;
    
  for( uint n = 0 ; n < N ; n++ ){

    push_RightMost( VLTree<T>( 0 , *p ) );
    p = p->m_right_branch;

  }

  return;
  
}

template <typename T> inline const uint& VLSubTree<T>::size() const noexcept { return m_size; }
template <typename T> inline void VLSubTree<T>::CutBranches(){ while( m_size > 0 ) pop_RightMost(); }
template <typename T> inline bool VLSubTree<T>::IsLeaf() const noexcept { return m_size == 0; }

template <typename T> inline VLSubTree<T> VLSubTree<T>::LeftMostSubTree() { return VLSubTree( *( m_root.m_leftmost_node ) ); }
template <typename T> inline VLSubTree<T> VLSubTree<T>::RightMostSubTree() { return VLSubTree( *( m_root.m_rightmost_node ) ); }

template <typename T> inline VLTree<T> VLSubTree<T>::LeftMostSubTreeCopy() const { return VLTree<T>( 0 , *( m_root.m_leftmost_node ) ); }

template <typename T> inline VLTree<T> VLSubTree<T>::RightMostSubTreeCopy() const { return VLTree<T>( 0 , *( m_root.m_rightmost_node ) ); }

template <typename T> inline void VLSubTree<T>::push_RightMost() const noexcept {}

template <typename T> template <typename Arg1 , typename... Arg2>
void VLSubTree<T>::push_RightMost( const Arg1& t0 , const Arg2&... t1 )
{
  
  auto p = new EntryOfVLTree<T>( t0 );
  EntryOfVLTree<T>*& p_rightmost = m_root.m_rightmost_node;

  if( p_rightmost == &m_root ){

    m_root.m_leftmost_node = p;

  } else {

    p->m_left_branch = p_rightmost;
    p_rightmost->m_right_branch = p;  

  }

  p_rightmost = p;

  m_size++;
  push_RightMost( t1... );
  return;

}

template <typename T> template <typename... Args>
void VLSubTree<T>::push_RightMost( const VLTree<T>& t0 , const Args&... t1 )
{

  push_RightMost( t0.m_root.m_t );
  Concatenate( t0 );
  push_RightMost( t1... );
  return;

}

template <typename T> template <typename Arg>
void VLSubTree<T>::push_LeftMost( const Arg& t )
{

  auto p = new EntryOfVLTree<T>( t );
  EntryOfVLTree<T>*& p_leftmost = m_root.m_leftmost_node;

  if( p_leftmost == &m_root ){

    m_root.m_rightmost_node = p;

  } else {

    p->m_right_branch = p_leftmost;
    p_leftmost->m_left_branch = p;

  }
  
  p_leftmost = p;
  
  m_size++;
  return;

}

template <typename T>
void VLSubTree<T>::pop_RightMost()
{

  if( m_size == 0 ){

    ERR_CALL;
    
  }
  
  EntryOfVLTree<T>* p_rightmost = m_root.m_rightmost_node;

  VLSubTree<T> t{ *p_rightmost };
  t.CutBranches();

  if( m_size == 1 ){

    m_root.m_leftmost_node = &m_root;
    m_root.m_rightmost_node = &m_root;

  } else {
    
    EntryOfVLTree<T>* const& p_rightmost_prev = p_rightmost->m_left_branch;

    m_root.m_rightmost_node = p_rightmost_prev;
    p_rightmost_prev->m_right_branch = p_rightmost_prev;

  }
  
  delete p_rightmost;
  m_size--;
  return;
  
}

template <typename T>
void VLSubTree<T>::pop_LeftMost()
{

  if( m_size == 0 ){

    ERR_CALL;
    
  }

  EntryOfVLTree<T>* p_leftmost = m_root.m_leftmost_node;

  VLSubTree<T> t{ *p_leftmost };
  t.CutBranches();

  if( m_size == 1 ){

    m_root.m_leftmost_node = &m_root;
    m_root.m_rightmost_node = &m_root;

  } else {
    
    EntryOfVLTree<T>* const& p_leftmost_next = p_leftmost->m_right_branch;

    m_root.m_leftmost_node = p_leftmost_next;
    p_leftmost_next->m_left_branch = p_leftmost_next;

  }
  
  delete p_leftmost;
  m_size--;
  return;
  
}

template <typename T>
void VLSubTree<T>::pop_Root()
{

  if( m_size != 1 ){

    ERR_CALL;
    
  }

  EntryOfVLTree<T>* p_unique_node = m_root.m_leftmost_node;
  m_root = *( m_root.m_leftmost_node );
  delete p_unique_node;
  
  m_size = 0;
  EntryOfVLTree<T>* p = m_root.m_leftmost_node;

  if( p != &m_root ){

    m_size++;
    
    while( p != p->m_right_branch ){

      p = p->m_right_branch;
      m_size++;

    }

  }
  
  return;

}

template <typename T> inline typename VLSubTree<T>::iterator VLSubTree<T>::LeftMostNode() noexcept { return IteratorOfVLTree<T>( m_root.m_leftmost_node ); }
template <typename T> inline typename VLSubTree<T>::const_iterator VLSubTree<T>::LeftMostNode() const noexcept { return ConstIteratorOfVLTree<T>( m_root.m_leftmost_node ); }
template <typename T> inline typename VLSubTree<T>::iterator VLSubTree<T>::RightMostNode() noexcept { return IteratorOfVLTree<T>( m_root.m_rightmost_node ); }
template <typename T> inline typename VLSubTree<T>::const_iterator VLSubTree<T>::RightMostNode() const noexcept { return ConstIteratorOfVLTree<T>( m_root.m_rightmost_node ); }

template <typename T>
typename VLSubTree<T>::iterator VLSubTree<T>::LeftMostLeaf() noexcept
{

  EntryOfVLTree<T>* p = m_root.m_leftmost_node;

  while( p != p->m_leftmost_node ){

    p = p->m_leftmost_node;

  }

  return IteratorOfVLTree<T>( p );

}

template <typename T>
typename VLSubTree<T>::const_iterator VLSubTree<T>::LeftMostLeaf() const noexcept
{

  const EntryOfVLTree<T>* p = m_root.m_leftmost_node;

  while( p != p->m_leftmost_node ){

    p = p->m_leftmost_node;

  }

  return ConstIteratorOfVLTree<T>( p );

}

template <typename T>
typename VLSubTree<T>::iterator VLSubTree<T>::RightMostLeaf() noexcept
{

  EntryOfVLTree<T>* p = m_root.m_rightmost_node;

  while( p != p->m_rightmost_node ){

    p = p->m_rightmost_node;

  }

  return IteratorOfVLTree<T>( p );

}

template <typename T>
typename VLSubTree<T>::const_iterator VLSubTree<T>::RightMostLeaf() const noexcept
{

  const EntryOfVLTree<T>* p = m_root.m_rightmost_node;

  while( p != p->m_rightmost_node ){

    p = p->m_rightmost_node;

  }

  return ConstIteratorOfVLTree<T>( p );

}

template <typename T> inline typename VLSubTree<T>::iterator VLSubTree<T>::Root() noexcept { return IteratorOfVLTree<T>( &m_root ); }
template <typename T> inline typename VLSubTree<T>::const_iterator VLSubTree<T>::Root() const noexcept { return ConstIteratorOfVLTree<T>( &m_root ); }

template <typename T> template <typename... Args> inline typename VLSubTree<T>::iterator VLSubTree<T>::GetIterator( const Args&... args ) { return Root().Shift( args... ); }
template <typename T> template <typename... Args> inline typename VLSubTree<T>::const_iterator VLSubTree<T>::GetIterator( const Args&... args ) const { return Root().Shift( args... ); }


template <typename T> template <typename Arg>
void VLSubTree<T>::insert( const typename VLSubTree<T>::iterator& itr , const Arg& t )
{

  if( ! CheckContain( itr ) ){

    ERR_IMPUT( itr , t );
    
  }
  
  EntryOfVLTree<T>* const& p0 = itr.m_p;
  EntryOfVLTree<T>* const& p1 = p0->m_right_branch;
  auto p = new EntryOfVLTree<T>( t , p0 , p1 );
  
  p1->m_left_branch = p;
  p0->m_right_branch = p;
  
  m_size++;
  return;

}

template <typename T>
typename VLSubTree<T>::iterator VLSubTree<T>::erase( typename VLSubTree<T>::iterator& itr )
{
  
  if( ! CheckContain( itr ) ){

    ERR_IMPUT( itr );
    
  }

  EntryOfVLTree<T>* const p = itr.m_p;
  EntryOfVLTree<T>* const p0 = p->m_left_branch;
  EntryOfVLTree<T>* const p1 = p->m_right_branch;

  if( ! itr.IsLeaf() ){

    VLSubTree<T> t_sub{ *p };
    t_sub.CutBranches();
    
  }
  
  if( p0 != p ){

    if( p != p1 ){

      itr++;
      p0->m_right_branch = p1;
      p1->m_left_branch = p0;
      
    } else {

      itr--;
      p0->m_right_branch = p0;
      m_root.m_rightmost_node = p0;

    }

  } else {

    if( p != p1 ){

      itr++;
      p1->m_left_branch = p1;
      m_root.m_leftmost_node = p1;

    } else {

      itr = Root();
      m_root.m_leftmost_node = &m_root;
      m_root.m_rightmost_node = &m_root;

    }

  }
  
  delete p;
  m_size--;
  return itr;

}

template <typename T> inline const T& VLSubTree<T>::GetRoot() const noexcept { return m_root.m_t; }

template <typename T> inline void VLSubTree<T>::SetRoot( const T& t ){ m_root.m_t = t; }

template <typename T> template <typename... Args> inline const T& VLSubTree<T>::GetNode( const Args&... args ) const { return ACCESS( GetIterator( args... ) ); }


template <typename T>
VLSubTree<T> VLSubTree<T>::operator[]( const uint& i )
{

  if( i >= m_size ){

    ERR_IMPUT( i );

  }

  if( i <= m_size / 2 ){

    EntryOfVLTree<T>* p = m_root.m_leftmost_node;

    for( uint n = 0 ; n < i ; n++ ){

      p = p->m_right_branch;

    }

    return VLSubTree<T>( *p );

  }

  EntryOfVLTree<T>* p = m_root.m_rightmost_node;

  for( uint n = m_size - 1 ; n > i ; n-- ){

    p = p->m_left_branch;

  }

  return VLSubTree<T>( *p );

}

template <typename T>
VLSubTree<T> VLSubTree<T>::operator[]( typename VLSubTree<T>::iterator& itr )
{

  if( ! CheckContain( itr )){

    ERR_IMPUT( itr );

  }

  return VLSubTree<T>( *( itr.m_p ) );

}

template <typename T>
VLTree<T> VLSubTree<T>::operator[]( const typename VLSubTree<T>::const_iterator& itr ) const
{

  if( ! CheckContain( itr )){

    ERR_IMPUT( itr );

  }

  return VLTree<T>( 0 , itr.m_p );

}

template <typename T>
VLTree<T> VLSubTree<T>::GetBranchCopy( const uint& i ) const
{

  if( i >= m_size ){

    ERR_IMPUT( i );

  }

  if( i <= m_size / 2 ){

    const EntryOfVLTree<T>* p = m_root.m_leftmost_node;

    for( uint n = 0 ; n < i ; n++ ){

      p = p->m_right_branch;

    }

    return VLTree<T>( 0 , *p );

  }

  const EntryOfVLTree<T>* p = m_root.m_rightmost_node;

  for( uint n = m_size - 1 ; n > i ; n-- ){

    p = p->m_left_branch;

  }

  return VLTree<T>( 0 , *p );

}

template <typename T>
VLTree<T> VLSubTree<T>::GetBranchCopy( const typename VLSubTree<T>::iterator& itr ) const
{

  if( ! CheckContain( itr ) ){

    ERR_IMPUT( itr );

  }

  return VLTree<T>( 0 , *( itr.m_p ) );

}

template <typename T>
VLTree<T> VLSubTree<T>::GetBranchCopy( const typename VLSubTree<T>::const_iterator& itr ) const
{

  if( ! CheckContain( itr ) ){

    ERR_IMPUT( itr );

  }

  return VLTree<T>( 0 , *( itr.m_p ) );

}

template <typename T> 
void VLSubTree<T>::Concatenate( const VLTree<T>& t )
{

  EntryOfVLTree<T>* const p_rightmost = m_root.m_rightmost_node;

  if( p_rightmost->m_rightmost_node != p_rightmost ){

    ERR_IMPUT( *this , t );

  }

  if( &m_root == p_rightmost ){
    
    LeafToTree( t );

  } else {

    VLSubTree<T>( *p_rightmost ).LeafToTree( t );

  }
  
  return;

}

template <typename T> 
void VLSubTree<T>::Concatenate( const typename VLSubTree<T>::iterator& itr , const VLTree<T>& t )
{

  if( ! itr.IsLeaf() ){

    ERR_IMPUT( itr , t );

  }
  
  EntryOfVLTree<T>* const p = itr.m_p;

  if( &m_root == p ){

    LeafToTree( t );

  } else {

    VLSubTree<T>( *p ).LeafToTree( t );

  }
  
  return;

}

template <typename T>
bool VLSubTree<T>::CheckContain( const iterator& itr ) const noexcept
{

  auto p0 = itr.m_p;
  auto p1 = m_root.m_leftmost_node;
  
  for( uint i = 0 ; i < m_size ; i++ ){

    if( p0 == p1 ){

      return true;

    }

    p1 = p1->m_right_branch;
    
  }

  return false;

}

template <typename T>
bool VLSubTree<T>::CheckContain( const const_iterator& itr ) const noexcept
{

  auto p0 = itr.m_p;
  auto p1 = m_root.m_leftmost_node;
  
  for( uint i = 0 ; i < m_size ; i++ ){

    if( p0 == p1 ){

      return true;

    }

    p1 = p1->m_right_branch;
    
  }

  return false;

}

template <typename T>
string VLSubTree<T>::Display() const
{
  
  string s = to_string( m_root.m_t );
  s += "(";
  
  const EntryOfVLTree<T>* p = m_root.m_leftmost_node;
  
  for( uint i = 0 ; i < m_size ; i++ ){

    if( i > 0 ){

      s += ",";

    }
    
    s += VLTree<T>( 0 , *p ).Display();
    
    p = p->m_right_branch;

  }

  s += ")";

  return s;

}


template <typename T>
bool operator==( const VLTree<T>& t1 , const VLTree<T>& t2 )
{

  if( t1.GetRoot() != t2.GetRoot() ){

    return false;

  }
  
  if( t1.IsLeaf() ){

    return t2.IsLeaf();

  }

  if( t2.IsLeaf() ){

    return false;

  }

  auto itr1 = t1.LeftMostNode();
  auto itr2 = t2.LeftMostNode();

  while( itr1.IsValid() && itr2.IsValid() ){

    if( t1.GetBranchCopy( *itr1 ) != t2.GetBranchCopy( *itr2 ) ){

      return false;

    }

    itr1++;
    itr2++;

  }

  return !( itr1.IsValid() || itr2.IsValid() );


}

template <typename T> inline bool operator!=( const VLTree<T>& t1 , const VLTree<T>& t2 ) { return !( t1 == t2 ); }
