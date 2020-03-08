// c:/Users/user/Documents/Programming/SFINAE/MetaFunction/IsPointerOf/a.hpp

#pragma once
#include "../a.hpp"

// 標準搭載の is_pointer<T> と違い、どの型のポインターか指定する。
// 標準搭載の remove_pointer<T> を用いても同様に定義できる。
template <typename T , typename Ret>
class is_PointerOf :
  public EmptySet
{

private:
  template <typename U , typename R>
  static auto Check() -> typename enable_if< is_same<U,R*>::value || is_same<U,const R*>::value , true_type >::type;

  template <typename U , typename R>
  static auto Check() -> typename enable_if< ! ( is_same<U,R*>::value || is_same<U,const R*>::value ) , false_type >::type;

public:
  static const bool value = decltype( Check<T,Ret>() )::value;

};
