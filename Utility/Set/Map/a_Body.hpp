// c:/Users/user/Documents/Programming/Utility/Set/Map/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

// デバッグ用（CERRマクロ内でのみ使用）
#ifdef DEBUG
  #include "StdStream/a_Body.hpp"
#endif

DEFINITION_OF_ARITHMETICS_FOR_MAP( map );
DEFINITION_OF_ARITHMETICS_FOR_MAP( unordered_map );
