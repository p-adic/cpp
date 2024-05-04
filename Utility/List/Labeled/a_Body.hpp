// c:/Users/user/Documents/Programming/Utility/List/Labeled/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../VLArray/a_Body.hpp"
#include "../../../Mathematics/SetTheory/DirectProduct/a_Body.hpp"

#include "../../VLArray/Sort/a_Body.hpp"
#include "../../../Error/IllegalInput/a_Body.hpp"

template <typename T , typename Key1 , typename... Key2> inline LabeledList<T,Key1,Key2...>::LabeledList() : m_v() {}
template <typename T , typename Key1 , typename... Key2> inline LabeledList<T,Key1,Key2...>::LabeledList( const WrappedType<DirectProduct<DirectProduct<Key1,Key2...>,T> >& v ) :
  m_v( v )
{}

template <typename T , typename Key1 , typename... Key2> inline const VLArray<DirectProduct<DirectProduct<Key1,Key2...>,T> >& LabeledList<T,Key1,Key2...>::Get() const noexcept { return m_v; }

template <typename T , typename Key1 , typename... Key2>
T& LabeledList<T,Key1,Key2...>::operator()( const Key1& key1 , const Key2&... key2 )
{

  const DirectProduct<Key1,Key2...> key_temp{ key1 , key2... };

  for( auto itr = m_v.begin() , end = m_v.end() ; itr != end ; itr++ ){

    if( itr->template Get<0>() == key_temp ){

      return itr->template Ref<1>();

    }

  }

  ERR_INPUT( key1 , key2... );
  return m_v.back().template Ref<1>();

}

template <typename T , typename Key1 , typename... Key2>
const T& LabeledList<T,Key1,Key2...>::operator()( const Key1& key1 , const Key2&... key2 ) const
{

  const DirectProduct<Key1,Key2...> key_temp{ key1 , key2... };

  for( auto itr = m_v.begin() , end = m_v.end() ; itr != end ; itr++ ){

    if( itr->template Get<0>() == key_temp ){

      return itr->template Get<1>();

    }

  }
  
  ERR_INPUT( key1 , key2... );
  return m_v.back().template Get<1>();

}

template <typename T , typename Key1 , typename... Key2> inline void LabeledList<T,Key1,Key2...>::Insert( const Key1& key1 , const Key2&... key2 , const T& t ) { m_v.push_back( DirectProduct<DirectProduct<Key1,Key2...>,T>( DirectProduct<Key1,Key2...>( key1 , key2... ) , t ) ); }

template <typename T , typename Key1 , typename... Key2>
void LabeledList<T,Key1,Key2...>::Delete( const Key1& key1 , const Key2&... key2 )
{

  const DirectProduct<Key1,Key2...> key_temp{ key1 , key2... };
  
  for( auto itr = m_v.begin() , end = m_v.end() ; itr != end ; itr++ ){

    if( itr->template Get<0>() == key_temp ){

      m_v.erase( itr );

    }

  }

  ERR_INPUT( key1 , key2... );
  return;

}

template <typename T , typename Key1 , typename... Key2>
bool LabeledList<T,Key1,Key2...>::Contain( const Key1& key1 , const Key2&... key2 ) const
{

  const DirectProduct<Key1,Key2...> key_temp{ key1 , key2... };
  
  for( auto itr = m_v.begin() , end = m_v.end() ; itr != end ; itr++ ){

    if( itr->template Get<0>() == key_temp ){

      return true;

    }

  }

  return false;

}

template <typename T , typename Key1 , typename... Key2>
T& LabeledList<T,Key1,Key2...>::RefInsert( const Key1& key1 , const Key2&... key2 , const T& t )
{

  const DirectProduct<Key1,Key2...> key_temp{ key1 , key2... };
  
  for( auto itr = m_v.begin() , end = m_v.end() ; itr != end ; itr++ ){

    if( itr->template Get<0>() == key_temp ){

      return itr->template Ref<1>();

    }

  }

  Insert( key1 , key2... , t );
  return m_v.back().template Ref<1>();

}

template <typename T , typename Key1 , typename... Key2> inline void LabeledList<T,Key1,Key2...>::SortKey( const string& method , const VLArray<int>& option ) { Sort( m_v , method , option ); }

template <typename T , typename Key1 , typename... Key2> inline bool operator<( const DirectProduct<DirectProduct<Key1,Key2...>,T>& v0 , const DirectProduct<DirectProduct<Key1,Key2...>,T>& v1 ) { return v0.template Get<0>() < v1.template Get<0>(); }

