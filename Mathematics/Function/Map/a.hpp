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

#include "a_Alias.hpp"
// Map<T,U>‚Í
// - unordered_map<T,U>()‚ªwell-formed‚È‚ç‚Îunordered_map<T,U>
// - ‚»‚¤‚Å‚È‚­operator<(declval<T>(),declval<T>())‚ªwell-formed‚È‚ç‚Îmap<T,U>
// - ‚»‚¤‚Å‚È‚¢‚È‚ç‚Îvoid
