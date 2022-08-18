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

  template<uint i> inline EmptySet Get() const;
  template<uint i> inline EmptySet Ref();

  // const DirectProduct<Ti...>& GetFinalSegment()
  template<uint i> inline auto GetFinalSegment() const -> typename enable_if< equal_to<uint>()( 0 , i ) , ConstTypeOfFinalSegment<i> >::type;
  template<uint i> inline auto GetFinalSegment() const -> typename enable_if< less_equal<uint>()( 1 , i ) , ConstTypeOfFinalSegment<i> >::type;
  // DirectProduct<Ti...>& RefFinalSegment()
  template<uint i> inline auto RefFinalSegment() -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfFinalSegment<i> >::type;
  template<uint i> inline auto RefFinalSegment() -> typename enable_if< less_equal<uint>()( 1 , i ) , TypeOfFinalSegment<i> >::type;

  
  // DirectProduct<T0,...,T_{i-1}> CopyInitialSegment()
  template<uint i> inline auto CopyInitialSegment() const -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfInitialSegment<i> >::type;
  template<uint i> inline auto CopyInitialSegment() const -> typename enable_if< less_equal<uint>()( 1 , i ) , TypeOfInitialSegment<i> >::type;
  
};

template <typename T0 , typename... T1>
class DirectProduct<T0,T1...>
{

private:
  T0 m_t;
  DirectProduct<T1...> m_v;
  
public:
  inline DirectProduct();
  inline DirectProduct( const T0& , const T1& ... );
  inline DirectProduct( const T0& , const DirectProduct<T1...>& );
  virtual ~DirectProduct() = default;

  // const Ti& Get()
  template<uint i> inline auto Get() const -> typename enable_if< equal_to<uint>()( 0 , i ) , ConstTypeOfProjection<i,T0,T1...> >::type;
  template<uint i> inline auto Get() const -> typename enable_if< less_equal<uint>()( 1 , i ) , ConstTypeOfProjection<i,T0,T1...> >::type;
  // Ti& Ref()
  template<uint i> inline auto Ref() -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfProjection<i,T0,T1...> >::type;
  template<uint i> inline auto Ref() -> typename enable_if< less_equal<uint>()( 1 , i ) , TypeOfProjection<i,T0,T1...> >::type;

  // const DirectProduct<Ti...>& GetFinalSegment()
  template<uint i> inline auto GetFinalSegment() const -> typename enable_if< equal_to<uint>()( 0 , i ) , ConstTypeOfFinalSegment<i,T0,T1...> >::type;
  template<uint i> inline auto GetFinalSegment() const -> typename enable_if< less_equal<uint>()( 1 , i ) , ConstTypeOfFinalSegment<i,T0,T1...> >::type;
  // DirectProduct<Ti...>& RefFinalSegment()
  template<uint i> inline auto RefFinalSegment() -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfFinalSegment<i,T0,T1...> >::type;
  template<uint i> inline auto RefFinalSegment() -> typename enable_if< less_equal<uint>()( 1 , i ) , TypeOfFinalSegment<i,T0,T1...> >::type;

  // DirectProduct<T0,...,T_{i-1}> CopyInitialSegment()
  template<uint i> inline auto CopyInitialSegment() const -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfInitialSegment<i,T0,T1...> >::type;
  template<uint i> inline auto CopyInitialSegment() const -> typename enable_if< less_equal<uint>()( 1 , i ) , TypeOfInitialSegment<i,T0,T1...> >::type;

};

inline bool operator==( const DirectProduct<>& , const DirectProduct<>& ) noexcept;
template <typename T0 , typename... T1> inline bool operator==( const DirectProduct<T0,T1...>& , const DirectProduct<T0,T1...>& );

// ìôçÜÇëΩïœêîÇ…ï™ÇØÇΩÇ‡ÇÃ
inline bool Equal( const DirectProduct<>& ) noexcept;
template <typename T0 , typename... T1> bool Equal( const DirectProduct<T0,T1...>& , const T0& , const T1&... );

// DirectProduct<T0,...,Tn> Connect( const DirectProduct<T0,...,Ti>& , const DirectProduct<T{i+1},...,Tn>& )
template <typename... T0> inline DirectProduct<T0...> Connect( const DirectProduct<>& , const DirectProduct<T0...>& ) noexcept;
template <typename T0 , typename... T1> inline DirectProduct<T0,T1...> Connect( const DirectProduct<T0,T1...>& , const DirectProduct<>& ) noexcept;
template <typename T0 , typename T1 , typename... T2> inline DirectProduct<T0,T1,T2...> Connect( const DirectProduct<T0>& , const DirectProduct<T1,T2...>& );
template <typename T0 , typename T1 , typename... T2 , typename T3 , typename... T4> inline DirectProduct<T0,T1,T2...,T3,T4...> Connect( const DirectProduct<T0,T1,T2...>& , const DirectProduct<T3,T4...>& );

// const Ti& Projection( const T0& , ... , const Tn& )
template <uint i , typename... T0> auto Projection( const T0&... v ) -> ConstTypeOfProjection<i,T0...>;
// Ti& Projection( T0& , ... , Tn& )
template <uint i , typename... T0> auto Projection( T0&... v ) -> TypeOfProjection<i,T0...>;

template <typename... T0> inline string to_string( const DirectProduct<T0...>& );
