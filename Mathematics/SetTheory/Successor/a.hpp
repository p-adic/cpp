// Successor/a.hpp

#pragma once

#include "../DisjointUnion/a.hpp"
#include "../Singleton/a.hpp"

template <typename T>
class SuccessorOf
{

private:
  DisjointUnion<const SingletonOf<T>,const T> m_t;

public:
  SuccessorOf();
  SuccessorOf( const T& );
  template <uint i> const TypeOfProjection<i,SingletonOf<T>,T>& GetEntry() const;
  const uint& GetNumber() const;
  SuccessorOf<T>& operator=( const SingletonOf<T>& );
  SuccessorOf<T>& operator=( const T& );

};

template <uint i , typename T> const TypeOfProjection<i,SingletonOf<T>,T>& Access( const SuccessorOf<T>& );

template <typename T> const uint& to_int( const SuccessorOf<T>& );

template <typename T> bool operator==( const SuccessorOf<T>& , const SingletonOf<T>& );
template <typename T> bool operator==( const SuccessorOf<T>& , const T& );
template <typename T> bool operator==( const SuccessorOf<T>& , const SuccessorOf<T>& );
