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
  // コピーコンストラクタを持たない型Tを使いたい時は代わりにSartPointer<T>を用い、このコンストラクタを適用してWrappedType<SmartPointer<T> >を渡す。
  inline LabeledList( const WrappedType<DirectProduct<Key1,Key2...> >& , const WrappedType<T>& );
  
  T& operator()( const Key1& , const Key2&... );
  const T& operator()( const Key1& , const Key2&... ) const;
  void Insert( const Key1& , const Key2&... , const T& );
  void Delete( const Key1& , const Key2&... );
  bool Contain( const Key1& , const Key2&... ) const;

};
