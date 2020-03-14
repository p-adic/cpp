// c:/Users/user/Documents/Programming/Utility/VLTree/Iterator/Sequential/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../VLArray/a_Body.hpp"

// SequentialIteratorOfVLTree
template <typename T> inline SequentialIteratorOfVLTree<T>::SequentialIteratorOfVLTree( const IteratorOfVLTree<T>& itr ) : IteratorOfVLTree<T>( itr ) , m_itr(){}

template <typename T> inline SequentialIteratorOfVLTree<T>::SequentialIteratorOfVLTree( const SequentialIteratorOfVLTree<T>& itr ) : IteratorOfVLTree<T>( itr ) , m_itr( itr.m_itr ){}

template <typename T>
SequentialIteratorOfVLTree<T>& SequentialIteratorOfVLTree<T>::operator=( const IteratorOfVLTree<T>& itr )
{

  IteratorOfVLTree<T>::operator=( itr );
  m_itr.clear();
  return *this;

}

template <typename T>
SequentialIteratorOfVLTree<T>& SequentialIteratorOfVLTree<T>::operator=( const SequentialIteratorOfVLTree<T>& itr )
{

  IteratorOfVLTree<T>::operator=( itr );
  m_itr = itr.m_itr;
  return *this;

}

template <typename T>
void SequentialIteratorOfVLTree<T>::operator[]( const int& i )
{

  if( i == 0 ){

    if( m_itr.empty() ){

      ERR_IMPUT( i );
      
    }
    
    IteratorOfVLTree<T>::operator=( m_itr.back() );
    m_itr.pop_back();

  } else {

    if( IteratorOfVLTree<T>::IsLeaf() ){

      ERR_IMPUT( i );

    }
    
    m_itr.push_back( *this );
    IteratorOfVLTree<T>::operator[]( i );

  }

  return;

}

template <typename T> inline T& SequentialIteratorOfVLTree<T>::Access_Body( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const uint& i ) const { TRY_CATCH( return i == m_itr.size() ? IteratorOfVLTree<T>::Access_Body( FILE , LINE , FUNC , VARIABLE_NAMES ) : m_itr[i].Access_Body( FILE , LINE , FUNC , VARIABLE_NAMES ) , IllegalAccess& e , CALL_P( e , i , m_itr.size() ) ); return i == m_itr.size() ? IteratorOfVLTree<T>::Access_Body( FILE , LINE , FUNC , VARIABLE_NAMES ) : m_itr[i].Access_Body( FILE , LINE , FUNC , VARIABLE_NAMES ); }
template <typename T> inline T& SequentialIteratorOfVLTree<T>::Ref( const uint& i ) const { return i == m_itr.size() ? IteratorOfVLTree<T>::operator*() : *( m_itr[i] ); }
template <typename T> inline const T& SequentialIteratorOfVLTree<T>::Get( const uint& i ) const { return i == m_itr.size() ? IteratorOfVLTree<T>::operator*() : *( m_itr[i] ); }

template <typename T> inline void SequentialIteratorOfVLTree<T>::pop_front(){ m_itr.pop_front(); }

template <typename T>
void SequentialIteratorOfVLTree<T>::erase_back( VLSubTree<T>& t )
{

  SequentialIteratorOfVLTree<T> itr_copy = *this;
  
  if( IteratorOfVLTree<T>::IsRightMost() ){

    if( IteratorOfVLTree<T>::IsLeftMost() ){
      
      operator[]( 0 );

    } else {

      IteratorOfVLTree<T>::operator--( 0 );

    }
    
  } else {

    IteratorOfVLTree<T>::operator++( 0 );

  }
  
  erase_back_Body( t , itr_copy );
  return;

}

template <typename T>
void SequentialIteratorOfVLTree<T>::erase_back_Body( VLSubTree<T>& t , SequentialIteratorOfVLTree<T>& itr )
{

  const uint& L = itr.size();

  if( L == 1 ){

    ERR_CODE;

  }
  
  if( L == 2 ){

    t.erase( itr );

  } else {

    itr.pop_front();
    VLSubTree<T> t_sub = t[ ( itr.m_itr ).front() ];
    erase_back_Body( t_sub , itr );

  }
  
  return;

}

template <typename T>
bool SequentialIteratorOfVLTree<T>::CheckContained( const VLSubTree<T>& t ) const
{

  if( m_itr.empty() ){

    return true;

  }

  SequentialIteratorOfVLTree<T> itr_copy = *this;
  itr_copy.pop_front();
  return CheckContained_Body( t , itr_copy );

}

template <typename T>
bool SequentialIteratorOfVLTree<T>::CheckContained_Body( const VLSubTree<T>& t , const SequentialIteratorOfVLTree<T>& itr )
{

  if( ( itr.m_itr ).empty() ){

    return t.CheckContain( itr );

  }

  const IteratorOfVLTree<T>& itr_front = ( itr.m_itr ).front();

  if( t.CheckContain( itr_front ) ){

    const VLSubTree<T> t_sub{ itr_front };
    SequentialIteratorOfVLTree<T> itr_copy = itr;
    itr_copy.pop_front();
    
    return CheckContained_Body( t_sub , itr_copy );

  }

  return false;

}

template <typename T> inline uint SequentialIteratorOfVLTree<T>::size() const noexcept { return m_itr.size() + 1; }


// SequentialConstIteratorOfVLTree
template <typename T> inline SequentialConstIteratorOfVLTree<T>::SequentialConstIteratorOfVLTree( const ConstIteratorOfVLTree<T>& itr ) : ConstIteratorOfVLTree<T>( itr ) , m_itr(){}
template <typename T> inline SequentialConstIteratorOfVLTree<T>::SequentialConstIteratorOfVLTree( const SequentialConstIteratorOfVLTree<T>& itr ) : ConstIteratorOfVLTree<T>( itr ) , m_itr( itr.m_itr ){}

template <typename T>
SequentialConstIteratorOfVLTree<T>::SequentialConstIteratorOfVLTree( const SequentialIteratorOfVLTree<T>& itr ) : ConstIteratorOfVLTree<T>( itr ) , m_itr()
{

  for( auto itr_itr = ( itr.m_itr ).begin() , itr_itr_e = ( itr.m_itr ).end() ; itr_itr != itr_itr_e ; itr_itr++ ){

    m_itr.push_back( *itr_itr );
    
  }

}

template <typename T>
SequentialConstIteratorOfVLTree<T>& SequentialConstIteratorOfVLTree<T>::operator=( const ConstIteratorOfVLTree<T>& itr )
{

  ConstIteratorOfVLTree<T>::operator=( itr );
  m_itr.clear();
  return *this;

}

template <typename T>
SequentialConstIteratorOfVLTree<T>& SequentialConstIteratorOfVLTree<T>::operator=( const SequentialConstIteratorOfVLTree<T>& itr )
{

  ConstIteratorOfVLTree<T>::operator=( itr );
  m_itr = itr.m_itr;
  return *this;

}

template <typename T>
void SequentialConstIteratorOfVLTree<T>::operator[]( const int& i )
{

  if( i == 0 ){

    if( ! m_itr.empty() ){

      ConstIteratorOfVLTree<T>::operator=( m_itr.back() );
      m_itr.pop_back();

    }

  } else {

    m_itr.push_back( *this );
    ConstIteratorOfVLTree<T>::operator[]( i );

  }

  return;

}

template <typename T> inline const T& SequentialConstIteratorOfVLTree<T>::Access_Body( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const uint& i ) const  { TRY_CATCH( return i == m_itr.size() ? ConstIteratorOfVLTree<T>::Access_Body( FILE , LINE , FUNC , VARIABLE_NAMES ) : m_itr[i].Access_Body( FILE , LINE , FUNC , VARIABLE_NAMES ) , IllegalAccess& e , CALL_P( e , i , m_itr.size() ) ); return i == m_itr.size() ? ConstIteratorOfVLTree<T>::Access_Body( FILE , LINE , FUNC , VARIABLE_NAMES ) : m_itr[i].Access_Body( FILE , LINE , FUNC , VARIABLE_NAMES ); }
template <typename T> inline const T& SequentialConstIteratorOfVLTree<T>::Get( const uint& i ) const { return i == m_itr.size() ? ConstIteratorOfVLTree<T>::operator*() : *( m_itr[i] ); }

template <typename T> inline void SequentialConstIteratorOfVLTree<T>::pop_front(){ m_itr.pop_front(); }

template <typename T>
bool SequentialConstIteratorOfVLTree<T>::CheckContained( const VLSubTree<T>& t ) const
{

  if( m_itr.empty() ){

    return true;

  }

  SequentialConstIteratorOfVLTree<T> itr_copy = *this;
  itr_copy.pop_front();
  return CheckContained_Body( t , itr_copy );

}

template <typename T>
bool SequentialConstIteratorOfVLTree<T>::CheckContained_Body( const VLSubTree<T>& t , const SequentialConstIteratorOfVLTree<T>& itr )
{

  if( ( itr.m_itr ).empty() ){

    return t.CheckContain( itr );

  }

  const ConstIteratorOfVLTree<T>& itr_front = ( itr.m_itr ).front();

  if( t.CheckContain( itr_front ) ){

    const VLSubTree<T> t_sub{ IteratorOfVLTree<T>( const_cast<EntryOfVLTree<T>*>( itr_front.m_p ) ) };
    SequentialConstIteratorOfVLTree<T> itr_copy = itr;
    itr_copy.pop_front();
    
    return CheckContained_Body( t_sub , itr_copy );

  }

  return false;

}

template <typename T> inline uint SequentialConstIteratorOfVLTree<T>::size() const noexcept { return m_itr.size() + 1; }

template <typename T> inline T& Access( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const SequentialIteratorOfVLTree<T>& itr , const uint& i ){ return itr.Access_Body( FILE , LINE , FUNC , VARIABLE_NAMES , i ); }
template <typename T> inline const T& Access( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const SequentialConstIteratorOfVLTree<T>& itr , const uint& i ){ return itr.Access_Body( FILE , LINE , FUNC , VARIABLE_NAMES , i ); }
