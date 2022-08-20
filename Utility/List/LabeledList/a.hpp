// LabeledList/a.hpp

#pragma once

#include "../../VLArray/a.hpp"
#include "../../../Mathematics/SetTheory/DirectProduct/a.hpp"

template <typename T , typename Key1 , typename... Key2>
class LabeledList
{

private:
  VLArray<DirectProduct<DirectProduct<Key1,Key2...>,T> > m_v;
  
public:
  inline LabeledList();
  // ofstreamのようにコピーコンストラクタを持たない型Tを使いたい時は代わりにSartPointer<T>を用い、このコンストラクタを適用してWrappedType<DirectProduct<DirectProduct<Key1,Key2...>,SmartPointer<T> > >を渡す。
  inline LabeledList( const WrappedType<DirectProduct<DirectProduct<Key1,Key2...>,T> >& );
  
  inline const VLArray<DirectProduct<DirectProduct<Key1,Key2...>,T> >& Get() const noexcept;
  T& operator()( const Key1& , const Key2&... );
  const T& operator()( const Key1& , const Key2&... ) const;
  inline void Insert( const Key1& , const Key2&... , const T& );
  void Delete( const Key1& , const Key2&... );
  bool Contain( const Key1& , const Key2&... ) const;

  // Containでないならばinsertをし、その後operator()をする。
  T& RefInsert( const Key1& , const Key2&... , const T& );

  
  // 以下bool operator<( const DirectProduct<Key1,Key2...>& , const DirectProduct<Key1,Key2...>& )が定義されている時のみ実体化可能
  void SortKey( const string& method = "normal" , const VLArray<int>& option = VLArray<int>() );

};

template <typename T , typename Key1 , typename... Key2> inline bool operator<( const DirectProduct<DirectProduct<Key1,Key2...>,T>& , const DirectProduct<DirectProduct<Key1,Key2...>,T>& );
