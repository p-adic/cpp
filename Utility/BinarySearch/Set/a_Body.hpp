// c:/Users/user/Documents/Programming/Utility/BinarySearch/Set/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline typename set<T>::const_iterator MaximumLeq( const set<T>& S , const T& t ) { auto itr = S.upper_bound( t ); return itr == S.begin() ? S.end() : --itr; }
template <typename T , typename U> inline typename map<T,U>::iterator MaximumLeq( map<T,U>& f , const T& t ) { auto itr = f.upper_bound( t ); return itr == f.begin() ? f.end() : --itr; }

template <typename T> inline typename set<T>::const_iterator MaximumLt( const set<T>& S , const T& t ) { auto itr = S.lower_bound( t ); return itr == S.begin() ? S.end() : --itr; }
template <typename T , typename U> inline typename map<T,U>::iterator MaximumLt( map<T,U>& f , const T& t ) { auto itr = f.lower_bound( t ); return itr == f.begin() ? f.end() : --itr; }

template <typename T> inline typename set<T>::const_iterator MinimumGeq( const set<T>& S , const T& t ) { return S.lower_bound( t ); }
template <typename T , typename U> inline typename map<T,U>::iterator MinimumGeq( map<T,U>& f , const T& t ) { return f.lower_bound( t ); }

template <typename T> inline typename set<T>::const_iterator MinimumGt( const set<T>& S , const T& t ) { return S.upper_bound( t ); }
template <typename T , typename U> inline typename map<T,U>::iterator MinimumGt( map<T,U>& f , const T& t ) { return f.upper_bound( t ); }
