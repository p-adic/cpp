// c:/Users/user/Documents/Programming/Utility/WrappedType/Int/a.hpp

#pragma once
#include "../../../Mathematics/SetTheory/Singleton/a.hpp"

template <int i>
class WrappedInt :
  public SingletonType<WrappedInt<i> >
{
  
  friend class SingletonType<WrappedInt<i> >;

private:
  WrappedInt() = default;
  WrappedInt( const WrappedInt& ) = default;
  WrappedInt& operator=( const WrappedInt& ) = default;
  static const int m_i;

public:
  static int Get();

};

template <uint i>
class WrappedUInt :
  public SingletonType<WrappedUInt<i> >
{

  friend class SingletonType<WrappedUInt<i> >;

private:
  WrappedUInt() = default;
  WrappedUInt( const WrappedUInt& ) = default;
  WrappedUInt& operator=( const WrappedUInt& ) = default;
  static const uint m_i;

public:
  static uint Get();

};

template <int i> const WrappedInt<i>& Wrap();
template <uint i> const WrappedUInt<i>& WrapU();
