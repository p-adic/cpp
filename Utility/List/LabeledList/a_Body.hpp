// c:/Users/user/Documents/Programming/Utility/List/LabeledList/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../VLArray/a_Body.hpp"
#include "../../../Error/IllegalImput/a_Body.hpp"
#include "../../../Mathematics/SetTheory/DirectProduct/a_Body.hpp"

template <typename T , typename Key1 , typename... Key2> inline LabeledList<T,Key1,Key2...>::LabeledList() :
  m_key() , m_t()
{}

// VLArray<T>::VLArray( const WrappedType<T>& )ÇégópÇ∑ÇÈÅB
template <typename T , typename Key1 , typename... Key2> inline LabeledList<T,Key1,Key2...>::LabeledList( const WrappedType<DirectProduct<Key1,Key2...> >& key , const WrappedType<T>& t ) :
  m_key( key ) , m_t( t )
{}

template <typename T , typename Key1 , typename... Key2>  const VLArray<DirectProduct<Key1,Key2...> >& inline LabeledList<T,Key1,Key2...>::GetKey() const noexcept { return m_key; }

template <typename T , typename Key1 , typename... Key2>
T& LabeledList<T,Key1,Key2...>::operator()( const Key1& key1 , const Key2&... key2 )
{

  const DirectProduct<Key1,Key2...> key_temp{ key1 , key2... };

  typename VLArray<DirectProduct<Key1,Key2...> >::const_iterator itr1 = m_key.begin() , end = m_key.end();
  typename VLArray<T>::iterator itr2 = m_t.begin();
  
  while( itr1 != end ){

    if( *itr1 == key_temp ){

      return *itr2;

    }

    itr1++;
    itr2++;
    
  }

  ERR_IMPUT( m_key , key1 , key2... );
  return m_t.front();

}

template <typename T , typename Key1 , typename... Key2>
const T& LabeledList<T,Key1,Key2...>::operator()( const Key1& key1 , const Key2&... key2 ) const
{

  const DirectProduct<Key1,Key2...> key_temp{ key1 , key2... };

  typename VLArray<DirectProduct<Key1,Key2...> >::const_iterator itr1 = m_key.begin() , end = m_key.end();
  typename VLArray<T>::const_iterator itr2 = m_t.begin();
  
  while( itr1 != end ){

    if( *itr1 == key_temp ){

      return *itr2;

    }

    itr1++;
    itr2++;
    
  }

  ERR_IMPUT( m_key , key1 , key2... );
  return m_t.front();

}

template <typename T , typename Key1 , typename... Key2>
void LabeledList<T,Key1,Key2...>::Insert( const Key1& key1 , const Key2&... key2 , const T& t )
{

  const DirectProduct<Key1,Key2...> key_temp{ key1 , key2... };
  m_key.push_back( key );
  m_t.push_back( t );
  return;

}

template <typename T , typename Key1 , typename... Key2>
void LabeledList<T,Key1,Key2...>::Delete( const Key1& key1 , const Key2&... key2 )
{

  const DirectProduct<Key1,Key2...> key_temp{ key1 , key2... };
  
  typename VLArray<DirectProduct<Key1,Key2...> >::const_iterator itr1 = m_key.begin() , end = m_key.end();
  typename VLArray<T>::iterator itr2 = m_t.begin();
  
  while( itr1 != end ){

    if( *itr1 == key_temp ){

      return;

    }

    itr1++;
    itr2++;
    
  }

  ERR_IMPUT( m_key , key1 , key2... );
  return;

}

template <typename T , typename Key1 , typename... Key2>
bool LabeledList<T,Key1,Key2...>::Contain( const Key1& key1 , const Key2&... key2 ) const
{

  const DirectProduct<Key1,Key2...> key_temp{ key1 , key2... };
  
  typename VLArray<DirectProduct<Key1,Key2...> >::const_iterator itr1 = m_key.begin() , end = m_key.end();
  typename VLArray<T>::const_iterator itr2 = m_t.begin();
  
  while( itr1 != end ){

    if( *itr1 == key_temp ){

      return true;
      
    }

    itr1++;
    itr2++;
   
  }

  return false;

}


template <typename T , typename Key1 , typename... Key2>
T& LabeledList<T,Key1,Key2...>::Ref( const Key1& key1 , const Key2&... key2 , const T& t )
{

  const DirectProduct<Key1,Key2...> key_temp{ key1 , key2... };
  
  typename VLArray<DirectProduct<Key1,Key2...> >::const_iterator itr1 = m_key.begin() , end = m_key.end();
  typename VLArray<T>::iterator itr2 = m_t.begin();
  
  while( itr1 != end ){

    if( *itr1 == key_temp ){

      return *itr2;
      
    }

    itr1++;
    itr2++;
   
  }

  Insert( const Key1& key1 , const Key2&... key2 , const T& t );
  itr2--;
  return *itr2;

}
