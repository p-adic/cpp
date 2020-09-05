// LabeledList/a.hpp

#pragma once

#include "../../VLArray/a.hpp"
#include "../../../Mathematics/SetTheory/DirectProduct/a.hpp"

template <typename T , typename Key1 , typename... Key2>
class LabeledList
{

private:
  VLArray<DirectProduct<Key1,Key2...> > m_key;
  VLArray<T> m_t;

public:
  inline LabeledList();
  template <typename Arg1 , typename Arg2> inline LabeledList( const WrappedType<Arg1>& , const WrappedType<Arg2>& );
  
  T& operator()( const Key1& , const Key2&... );
  void Insert( const Key1& , const Key2&... , const T& );
  void Delete( const Key1& , const Key2&... );
  bool Contain( const Key1& , const Key2&... ) const;

};
