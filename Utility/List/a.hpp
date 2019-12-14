// List.hpp

#pragma once

template <typename T> list<T> to_list() noexcept;
template <typename T> list<T> to_list( const T& ) noexcept;
template <typename T> list<T> to_list( const T& , const T& ) noexcept;
template <typename T> list<T> to_list( const T& , const T& , const T& ) noexcept;

template <typename T> list<T> copy( const uint& , const T& ) noexcept;

template <typename T> uint Length( const list<T>& ) noexcept;
template <typename T> bool Length( const list<T>& , const uint& ) noexcept;
template <typename T> bool Longer( const list<T>& , const uint& ) noexcept;
template <typename T> bool Longer( const list<T>& , const uint& , uint& ) noexcept;
template <typename T> bool LongerOrEqual( const list<T>& , const uint& ) noexcept;

template <typename T> void Separate( const list<T>& , T& , list<T>& );
template <typename T> void Separate( const int& , const list<T>& , list<T>& , list<T>& );

template <typename T> list<T> Connect( const list<T>& , const list<T>& );

template <typename T> list<T> Front( const int& , const list<T>& );
template <typename T> list<T> Back( const int& , const list<T>& );

template <typename T> const T& Access( const uint& , const list<T>& );

template <typename T> bool CheckContain( const list<T>& , const T& );
template <typename T> bool CheckReduced( const list<T>& );
template <typename T> list<T> Reduce( const list<T>& );
