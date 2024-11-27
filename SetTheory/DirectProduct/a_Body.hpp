// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/String/a_Body.hpp"
#include "../../../Utility/WrappedType/Int/a.hpp"

template <typename T0 , typename... T1> inline DirectProduct<T0,T1...>::DirectProduct() : m_t() , m_v() {}
template <typename T0 , typename... T1> inline DirectProduct<T0,T1...>::DirectProduct( const T0& t0 , const T1&... t1 ) : DirectProduct<T0,T1...>( t0 , DirectProduct<T1...>( t1... ) ) {}
template <typename T0 , typename... T1> inline DirectProduct<T0,T1...>::DirectProduct( const T0& t , const DirectProduct<T1...>& v ) : m_t( t ) , m_v( v ) {}


template<uint i> inline EmptySet DirectProduct<>::Get() const { return EmptySet(); }
template <typename T0 , typename... T1> template<uint i> inline auto DirectProduct<T0,T1...>::Get() const -> typename enable_if< equal_to<uint>()( 0 , i ) , ConstTypeOfProjection<i,T0,T1...> >::type { return m_t; }
template <typename T0 , typename... T1> template<uint i> inline auto DirectProduct<T0,T1...>::Get() const -> typename enable_if< less_equal<uint>()( 1 , i ) , ConstTypeOfProjection<i,T0,T1...> >::type{ return m_v.template Get<i-1>(); }


template<uint i> inline EmptySet DirectProduct<>::Ref() { return EmptySet(); }
template <typename T0 , typename... T1> template<uint i> inline auto DirectProduct<T0,T1...>::Ref() -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfProjection<i,T0,T1...> >::type { return m_t; }
template <typename T0 , typename... T1> template<uint i> inline auto DirectProduct<T0,T1...>::Ref() -> typename enable_if< less_equal<uint>()( 1 , i ) , TypeOfProjection<i,T0,T1...> >::type{ return m_v.template Ref<i-1>(); }


template<uint i> inline auto DirectProduct<>::GetFinalSegment() const -> typename enable_if< equal_to<uint>()( 0 , i ) , ConstTypeOfFinalSegment<i> >::type { return *this; }
template<uint i> inline auto DirectProduct<>::GetFinalSegment() const -> typename enable_if< less_equal<uint>()( 1 , i ) , ConstTypeOfFinalSegment<i> >::type { return EmptySet(); }
template <typename T0 , typename... T1> template<uint i> inline auto DirectProduct<T0,T1...>::GetFinalSegment() const -> typename enable_if< equal_to<uint>()( 0 , i ) , ConstTypeOfFinalSegment<i,T0,T1...> >::type { return *this; }
template <typename T0 , typename... T1> template<uint i> inline auto DirectProduct<T0,T1...>::GetFinalSegment() const -> typename enable_if< less_equal<uint>()( 1 , i ) , ConstTypeOfFinalSegment<i,T0,T1...> >::type { return m_v.template GetFinalSegment<i-1>(); }


template<uint i> inline auto DirectProduct<>::RefFinalSegment() -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfFinalSegment<i> >::type { return *this; }
template<uint i> inline auto DirectProduct<>::RefFinalSegment() -> typename enable_if< less_equal<uint>()( 1 , i ) , TypeOfFinalSegment<i> >::type { return EmptySet(); }
template <typename T0 , typename... T1> template<uint i> inline auto DirectProduct<T0,T1...>::RefFinalSegment() -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfFinalSegment<i,T0,T1...> >::type { return *this; }
template <typename T0 , typename... T1> template<uint i> inline auto DirectProduct<T0,T1...>::RefFinalSegment() -> typename enable_if< less_equal<uint>()( 1 , i ) , TypeOfFinalSegment<i,T0,T1...> >::type { return m_v.template RefFinalSegment<i-1>(); }


template<uint i> inline auto DirectProduct<>::CopyInitialSegment() const -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfInitialSegment<i> >::type { return *this; }
template<uint i> inline auto DirectProduct<>::CopyInitialSegment() const -> typename enable_if< less_equal<uint>()( 1 , i ) , TypeOfInitialSegment<i> >::type { return EmptySet(); }
template <typename T0 , typename... T1> template<uint i> inline auto DirectProduct<T0,T1...>::CopyInitialSegment() const -> typename enable_if< equal_to<uint>()( 0 , i ) , TypeOfInitialSegment<i,T0,T1...> >::type { return DirectProduct<>(); }
template <typename T0 , typename... T1> template<uint i> inline auto DirectProduct<T0,T1...>::CopyInitialSegment() const -> typename enable_if< less_equal<uint>()( 1 , i ) , TypeOfInitialSegment<i,T0,T1...> >::type { return TypeOfInitialSegment<i,T0,T1...>( m_t , m_v.template CopyInitialSegment<i-1>() ); }

inline bool operator==( const DirectProduct<>& , const DirectProduct<>& ) noexcept { return true; }

template <typename T0 , typename... T1> inline bool operator==( const DirectProduct<T0,T1...>& v0 , const DirectProduct<T0,T1...>& v1 ) { return ( v0.template Get<0>() == v1.template Get<0>() ) && v0.template GetFinalSegment<1>() == v1.template GetFinalSegment<1>(); }

inline bool Equal( const DirectProduct<>& ) noexcept { return true; }
template <typename T0 , typename... T1> bool Equal( const DirectProduct<T0,T1...>& v0 , const T0& t0 , const T1&... t1 ) {  return v0.template Get<0>() == t0 && Equal( v0.template GetFinalSegmnt<1>() , t1... ); }

template <typename... T0> inline DirectProduct<T0...> Connect( const DirectProduct<>& c , const DirectProduct<T0...>& v0 ) noexcept { return v0; }
template <typename T0 , typename... T1> inline DirectProduct<T0,T1...> Connect( const DirectProduct<T0,T1...>& v0 , const DirectProduct<>& c ) noexcept { return v0; }
template <typename T0 , typename T1 , typename... T2> inline DirectProduct<T0,T1,T2...> Connect( const DirectProduct<T0>& v0 , const DirectProduct<T1,T2...>& v1 ) { return DirectProduct<T0,T1,T2...>( v0.template Get<0>() , v1 ); }
template <typename T0 , typename T1 , typename... T2 , typename T3 , typename... T4> inline DirectProduct<T0,T1,T2...,T3,T4...> Connect( const DirectProduct<T0,T1,T2...>& v0 , const DirectProduct<T3,T4...>& v1 ) { return DirectProduct<T0,T1,T2...,T3,T4...>( v0.template Get<0>() , Connect( v0.template GetFinalSegment<1>() , v1 ) ); }
template <typename T0> inline EmptySet Connect( const DirectProduct<T0>& v0 , const EmptySet& v1 ) { return v1; }

template <uint i , typename... T0> inline auto Projection( const T0&... v ) -> ConstTypeOfProjection<i,T0...> { return *( DirectProduct<const T0*...>( &v... ).template Get<i>() ); }
template <uint i , typename... T0> inline auto Projection( T0&... v ) -> TypeOfProjection<i,T0...> { return *( Projection<i,T0*...>( DirectProduct<T0*...>( &v... ) ) ); }

inline string to_string_Body( const DirectProduct<>& ){ return " "; }
template <typename T0> static inline string to_string_Body( const DirectProduct<T0>& v ) { return " " + to_string_Normalised( v.template Get<0>() ) + " "; }
template <typename T0 , typename T1 , typename... T2> static inline string to_string_Body( const DirectProduct<T0,T1,T2...>& v ) { return to_string( v.template Get<0>() ) + "," + to_string_Body( v.template GetFinalSegment<1>() ); }
template <typename... T0> inline string to_string( const DirectProduct<T0...>& v ) { return "(" + to_string_Body( v ) + ")"; }
