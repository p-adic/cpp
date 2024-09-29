// c:/Users/user/Documents/Programming/Utility/BinarySearch/Set/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1002390（setのMaximumLeq, setのMinimumGeq）
// https://yukicoder.me/submissions/1002389（mapのMaximumLeq）

// t以下の値が存在すればその最大値のiterator、存在しなければend()を返す。
template <typename T> inline typename set<T>::const_iterator MaximumLeq( const set<T>& S , const T& t );
// t以下のkeyが存在すればその最大値に対応するiterator、存在しなければend()を返す。
template <typename T , typename U> inline typename map<T,U>::iterator MaximumLeq( map<T,U>& f , const T& t );

// t未満の値が存在すればその最大値のiterator、存在しなければend()を返す。
template <typename T> inline typename set<T>::const_iterator MaximumLt( const set<T>& S , const T& t );
// t未満のkeyが存在すればその最大値に対応するiterator、存在しなければend()を返す。
template <typename T , typename U> inline typename map<T,U>::iterator MaximumLt( map<T,U>& f , const T& t );

// t以上の値が存在すればその最小値のiterator、存在しなければend()を返す。
template <typename T> inline typename set<T>::const_iterator MinimumGeq( const set<T>& S , const T& t );
// t以上のkeyが存在すればその最小値に対応するiterator、存在しなければend()を返す。
template <typename T , typename U> inline typename map<T,U>::iterator MaximumGeq( map<T,U>& f , const T& t );

// tより大きい値が存在すればその最小値のiterator、存在しなければend()を返す。
template <typename T> inline typename set<T>::const_iterator MinimumGt( const set<T>& S , const T& t );
// tより大きいkeyが存在すればその最小値に対応するiterator、存在しなければend()を返す。
template <typename T , typename U> inline typename map<T,U>::iterator MaximumGt( map<T,U>& f , const T& t );

