// c:/Users/user/Documents/Programming/Utility/Set/Map/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

#include "a_Alias.hpp"

// Map<T,U>‚Í
// - unordered_map<T,U>()‚ªwell-formed‚È‚ç‚Îunordered_map<T,U>
// - ‚»‚¤‚Å‚È‚­operator<(declval<T>(),declval<T>())‚ªwell-formed‚È‚ç‚Îmap<T,U>
// - ‚»‚¤‚Å‚È‚¢‚È‚ç‚Îvoid

DECLARATION_OF_ARITHMETICS_FOR_MAP( map );
DECLARATION_OF_ARITHMETICS_FOR_MAP( unordered_map );
