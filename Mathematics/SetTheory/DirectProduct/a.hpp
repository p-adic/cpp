// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/a.hpp

#pragma once
#include <functional>

template <typename... T0> class DirectProduct;

#include "a_Alias.hpp"

template <>
class DirectProduct<>
{

public:
  virtual ~DirectProduct() = default;

};

template <typename T0>
class DirectProduct<T0>
{

private:
  T0 m_t;
  DirectProduct<> m_c;
  
public:
  inline DirectProduct();
  inline DirectProduct( const T0& );
  virtual ~DirectProduct() = default;
  const T0& GetInitial() const;
  const DirectProduct<>& IgnoreInitial() const;

};

template <typename T0 , typename T1 , typename... T2>
class DirectProduct<T0,T1,T2...>
{

private:
  T0 m_t;
  DirectProduct<T1,T2...> m_v;
  
public:
  inline DirectProduct();
  inline DirectProduct( const T0& , const T1& , const T2& ... );
  inline DirectProduct( const T0& , const DirectProduct<T1,T2...>& );
  virtual ~DirectProduct() = default;
  const T0& GetInitial() const;
  const DirectProduct<T1,T2...>& IgnoreInitial() const;

};

bool operator==( const DirectProduct<>& , const DirectProduct<>& );
template <typename T0 , typename... T1> bool operator==( const DirectProduct<T0,T1...>& , const DirectProduct<T0,T1...>& );

bool Equal( const DirectProduct<>& );
template <typename T0 , typename... T1> bool Equal( const DirectProduct<T0,T1...>& , const T0& , const T1&... );

template <typename T0 , typename... T1> const T0& SeparateInitialLeft( const DirectProduct<T0,T1...>& );
template <typename T0 , typename... T1> const DirectProduct<T1...>& SeparateInitialRight( const DirectProduct<T0,T1...>& );
template <typename T0> TypeOfIgnoreFinal<T0> SeparateFinalLeft( const DirectProduct<T0>& );
template <typename T0 , typename T1 , typename... T2> TypeOfIgnoreFinal<T0,T1,T2...> SeparateFinalLeft( const DirectProduct<T0,T1,T2...>& );
template <typename T0> TypeOfFinal<T0> SeparateFinalRight( const DirectProduct<T0>& );
template <typename T0 , typename T1 , typename... T2> TypeOfFinal<T0,T1,T2...> SeparateFinalRight( const DirectProduct<T0,T1,T2...>& );

// DirectProduct<T0,...,Tn> Connect( const DirectProduct<T0,...,Ti>& , const DirectProduct<T{i+1},...,Tn>& )
template <typename... T0> DirectProduct<T0...> Connect( const DirectProduct<>& , const DirectProduct<T0...>& );
template <typename T0 , typename... T1> DirectProduct<T0,T1...> Connect( const DirectProduct<T0,T1...>& , const DirectProduct<>& );
template <typename T0 , typename T1 , typename... T2> DirectProduct<T0,T1,T2...> Connect( const DirectProduct<T0>& , const DirectProduct<T1,T2...>& );
template <typename T0 , typename T1 , typename... T2 , typename T3 , typename... T4> DirectProduct<T0,T1,T2...,T3,T4...> Connect( const DirectProduct<T0,T1,T2...>& , const DirectProduct<T3,T4...>& );

// DirectProduct<Ti,...,Tn> RestrictToRight<i,T0,...Tn>( const DirectProduct<T0,...,Tn>& )
template <uint i , typename... T0> auto RestrictToRight( const DirectProduct<T0...>& v ) -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfRestrictToRight<i,T0...> >::type;
template <uint i , typename... T0> auto RestrictToRight( const DirectProduct<T0...>& v ) -> typename enable_if< less<uint>()( sizeof...( T0 ) , i ) , TypeOfRestrictToRight<i,T0...> >::type;
template <uint i , typename T0 ,  typename... T1> auto RestrictToRight( const DirectProduct<T0,T1...>& v ) -> typename enable_if< less<uint>()( 0 , i ) && less_equal<uint>()( i , sizeof...( T1 ) + 1 ) , TypeOfRestrictToRight<i,T0,T1...> >::type;

// DirectProduct<T0,...,T{i-1}> RestrictToLeft<i,T0,...Tn>( const DirectProduct<T0,...,Tn>& )
template <uint i , typename... T0> auto RestrictToLeft( const DirectProduct<T0...>& v ) -> typename enable_if< equal_to<uint>()( i , sizeof...( T0 ) ) , TypeOfRestrictToLeft<i,T0...> >::type;
template <uint i , typename... T0> auto RestrictToLeft( const DirectProduct<T0...>& v ) -> typename enable_if< less<uint>()( sizeof...( T0 ) , i ) , TypeOfRestrictToLeft<i,T0...> >::type;
template <uint i , typename T0 , typename... T1> auto RestrictToLeft( const DirectProduct<T0,T1...>& v ) -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfRestrictToLeft<i,T0,T1...> >::type;
template <uint i , typename T0 , typename T1 , typename... T2> auto RestrictToLeft( const DirectProduct<T0,T1,T2...>& v ) -> typename enable_if< equal_to<uint>()( i , 1 ) , TypeOfRestrictToLeft<i,T0,T1,T2...> >::type;
template <uint i , typename T0 , typename T1 , typename T2 , typename... T3> auto RestrictToLeft( const DirectProduct<T0,T1,T2,T3...>& v ) -> typename enable_if< less<uint>()( 1 ,  i ) , TypeOfRestrictToLeft<i,T0,T1,T2,T3...> >::type;

// Ti Projection( const DirectProduct<T0,...,Tn>& )
template <uint i , typename T0 , typename... T1> auto Projection( const DirectProduct<T0,T1...>& v ) -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfProjection<i,T0,T1...> >::type;
template <uint i , typename T0 , typename T1 , typename... T2> auto Projection( const DirectProduct<T0,T1,T2...>& v ) -> typename enable_if< less_equal<uint>()( 1 , i ) && less_equal<uint>()( i , sizeof...( T2 ) + 1 ) , TypeOfProjection<i,T0,T1,T2...> >::type;
template <uint i , typename... T0> auto Projection( const DirectProduct<T0...>& v ) -> typename enable_if< less_equal<uint>()( sizeof...( T0 ) , i ) , TypeOfProjection<i,T0...> >::type;

// Ti Projection( const T0& , ... , const Tn& )
template <uint i , typename... T0> auto Projection( const T0&... v ) -> typename TypeOfProjection<i,T0...>::type;

template <typename... T0> string to_string( const DirectProduct<T0...>& );
