// LabeledList/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../VLArray/a_Body.hpp"
#include "../../../Error/IllegalImput/a_Body.hpp"
#include "../../../Mathematics/SetTheory/DirectProduct/a_Body.hpp"

template <typename T , typename Key1 , typename... Key2> inline LabeledList<T,Key1,Key2...>::LabeledList() :
  m_key() , m_t()
{}

template <typename T , typename Key1 , typename... Key2> template <typename Arg1 , typename Arg2> inline LabeledList<T,Key1,Key2...>::LabeledList( const WrapForVLArray<Arg1>& key , const WrapForVLArray<Arg2>& t) :
  m_key( key ) , m_t( t )
{}

template <typename T , typename Key1 , typename... Key2>
T& LabeledList<T,Key1,Key2...>::operator()( const Key1& key1 , const Key2&... key2 )
{

  typename VLArray<DirectProduct<Key1,Key2...> >::const_iterator itr1 = m_key.begin() , end = m_key.end();
  typename VLArray<T>::iterator itr2 = m_t.begin();
  
  while( itr1 != end ){

    if( Equal( *itr1 , key1 , key2... ) ){

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

  if( Contain( key1 , key2... ) ){

    ERR_IMPUT( m_key , key1 , key2... );

  }

  m_key.push_back( DirectProduct<Key1,Key2...>( key1 , key2... ) );
  m_t.push_back( t );
  return;

}

template <typename T , typename Key1 , typename... Key2>
void LabeledList<T,Key1,Key2...>::Delete( const Key1& key1 , const Key2&... key2 )
{

  typename VLArray<DirectProduct<Key1,Key2...> >::const_iterator itr1 = m_key.begin() , end = m_key.end();
  typename VLArray<T>::iterator itr2 = m_t.begin();
  
  for( size_t i = 0 ; itr1 != end ; i++ ){

    if( Equal( *itr1 , key1 , key2... ) ){

      m_key.erase( itr1 );
      m_t.erase( itr2 );

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

  for( typename VLArray<DirectProduct<Key1,Key2...> >::const_iterator itr = m_key.begin() , end = m_key.end() ; itr != end ; itr++ ){

    if( Equal( *itr , key1 , key2... ) ){

      return true;
      
    }
   
  }

  return false;

}
