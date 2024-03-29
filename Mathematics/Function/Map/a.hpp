// c:/Users/user/Documents/Programming/Mathematics/Function/Map/a.hpp

#pragma once

class is_ordered
{

private:
  is_ordered() = delete;
  template <typename T> static constexpr auto Check( const T& t ) -> decltype( t < t , true_type() );
  static constexpr false_type Check( ... );

public:
  template <typename T> static constexpr const bool value = is_same_v< decltype( Check( declval<T>() ) ) , true_type >;

};


template <typename INT , template <typename...> typename T>
struct hash<T<INT>> :
  public hash<INT>
{

  inline size_t operator()( const T<INT>& n ) const;

};

#include "a_Alias.hpp"
// Map<T,U>は
// - unordered_map<T,U>()がwell-formedならばunordered_map<T,U>
// - そうでなくoperator<(declval<T>(),declval<T>())がwell-formedならばmap<T,U>
// - そうでないならばvoid
