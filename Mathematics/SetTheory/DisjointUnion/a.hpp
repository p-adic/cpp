// DisjointUnion/a.hpp

#pragma once

#include "../DirectProduct/a.hpp"
#include "../../../Utility/WrappedInt/a.hpp"

template <typename... T0> class DisjointUnion;

template <>
class DisjointUnion<> :
  public EmptySet
{

public:
  template <typename T0> static DirectProduct<T0*> Initialise();
  template <typename T0, typename T1 , typename... T2> static DirectProduct<T0*,T1*,T2*...> Initialise();
  
};

template <typename T0 , typename... T1>
class DisjointUnion<T0,T1...>
{

private:
  DirectProduct<T0*,T1*...> m_p;
  uint m_i;
  template <uint i> static DirectProduct<T0*,T1*...> Normalise( TypeOfProjection<i,T0,T1...>& );

public:
  template <uint i> DisjointUnion( const WrappedUInt<i>& , TypeOfProjection<i,T0,T1...>& );
  
  template <uint i> const TypeOfProjection<i,T0*,T1*...>& GetEntry() const;
  const uint& GetNumber() const;

};

template <uint i , typename T0 , typename... T1> const TypeOfProjection<i,T0,T1...>& Access( const DisjointUnion<T0,T1...>& );

template <typename... T0>  const uint& to_int( const DisjointUnion<T0...>& );
template <uint i , typename... T0> DisjointUnion<T0...> to_DisjointUnion( TypeOfProjection<i,T0...>& );

template <typename... T0 , typename... T1> DisjointUnion<T0...,T1...> ExtendToLeft( const DisjointUnion<T1...>& );
template <typename... T0 , typename... T1> DisjointUnion<T0...,T1...> ExtendToRight( const DisjointUnion<T0...>& );
