// c:/Users/user/Documents/Programming/Utility/Set/a.hpp

#pragma once
#include "a_Macro.hpp"

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
// Set<T>‚Í
// - unordered_set<T>()‚ªwell-formed‚È‚ç‚Îunordered_set<T>
// - ‚»‚¤‚Å‚È‚­operator<(declval<T>(),declval<T>())‚ªwell-formed‚È‚ç‚Îset<T>
// - ‚»‚¤‚Å‚È‚¢‚È‚ç‚Îvoid

// Map<T,U>‚Í
// - unordered_map<T,U>()‚ªwell-formed‚È‚ç‚Îunordered_map<T,U>
// - ‚»‚¤‚Å‚È‚­operator<(declval<T>(),declval<T>())‚ªwell-formed‚È‚ç‚Îmap<T,U>
// - ‚»‚¤‚Å‚È‚¢‚È‚ç‚Îvoid
