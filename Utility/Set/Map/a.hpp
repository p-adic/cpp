// c:/Users/user/Documents/Programming/Utility/Set/Map/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// デバッグ用（CERRマクロ内でのみ使用）
#ifdef DEBUG
  #include "StdStream/a.hpp"
#endif

#include "a_Alias.hpp"

// Map<T,U>は
// - unordered_map<T,U>()がwell-formedならばunordered_map<T,U>
// - そうでなくoperator<(declval<T>(),declval<T>())がwell-formedならばmap<T,U>
// - そうでないならばvoid

DECLARATION_OF_ARITHMETICS_FOR_MAP( map );
DECLARATION_OF_ARITHMETICS_FOR_MAP( unordered_map );
