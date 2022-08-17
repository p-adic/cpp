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

  // デフォルトコンストラクタを持たないがコピーコンストラクタを持つ型Tを使いたい時は、このコンストラクタを適用する。
  // 更にコピーコンストラクタも持たない型Tを使いたい時はTの代わりにSmartPointer<T>を用い、このコンストラクタを適用する。
  inline LabeledList( const WrappedType<DirectProduct<Key1,Key2...> >& , const WrappedType<T>& );

  const VLArray<DirectProduct<Key1,Key2...> >& inline Key() const noexcept;
  T& operator()( const Key1& , const Key2&... );
  const T& operator()( const Key1& , const Key2&... ) const;
  void Insert( const Key1& , const Key2&... , const T& );
  void Delete( const Key1& , const Key2&... );
  bool Contain( const Key1& , const Key2&... ) const;

};
