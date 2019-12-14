// IsList/a.hpp

#pragma once
#include "../a.hpp"

template <typename T>
class is_List :
  public EmptySet
{

private:
  template <typename U>
  static auto Check( U&& u ) -> typename remove_reference< decltype( u.front() ) >::type;

  template <typename U>
  static false_type Check( ... );

public:
  static const bool value = is_same< T , list< decltype( Check<T>( declval<T>() ) ) > >::value;
  using type = decltype( Check<T>( declval<T>() ) );

};
