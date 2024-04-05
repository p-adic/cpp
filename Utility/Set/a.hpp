// c:/Users/user/Documents/Programming/Utility/Set/a.hpp

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

template <typename T , template <typename...> typename MOD>
struct hash<MOD<T>>
{

  inline size_t operator()( const MOD<T>& n ) const;

};


template <typename T1 , typename T2 , template <typename...> typename PAIR>
struct hash<PAIR<T1,T2>>
{

  inline size_t operator()( const PAIR<T1,T2>& n ) const;

};

template <typename T1 , typename T2 , typename T3>
struct hash<tuple<T1,T2,T3>>
{

  inline size_t operator()( const tuple<T1,T2,T3>& n ) const;

};

#include "a_Alias.hpp"
// Set<T>は
// - unordered_set<T>()がwell-formedならばunordered_set<T>
// - そうでなくoperator<(declval<T>(),declval<T>())がwell-formedならばset<T>
// - そうでないならばvoid

// Map<T,U>は
// - unordered_map<T,U>()がwell-formedならばunordered_map<T,U>
// - そうでなくoperator<(declval<T>(),declval<T>())がwell-formedならばmap<T,U>
// - そうでないならばvoid
