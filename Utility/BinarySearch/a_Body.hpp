// c:/Users/user/Documents/Programming/Utility/BinarySearch/a_Body.hpp

#pragma once
#include "a.hpp"

// a_Macro.hppì‡ÇÃCERRÇ…ópÇ¢ÇÈÅB
#include "../StdStream/a_Body.hpp"

template <typename T> inline typename set<T>::iterator MaximumLeq( set<T>& S , const T& t ) { auto itr = S.upper_bound( t ); return itr == S.begin() ? S.end() : --itr; }

template <typename T> inline typename set<T>::iterator MaximumLt( set<T>& S , const T& t ) { auto itr = S.lower_bound( t ); return itr == S.begin() ? S.end() : --itr; }

template <typename T> inline typename set<T>::iterator MinimumGeq( set<T>& S , const T& t ) { return S.lower_bound( t ); }

template <typename T> inline typename set<T>::iterator MinimumGt( set<T>& S , const T& t ) { return S.upper_bound( t ); }
