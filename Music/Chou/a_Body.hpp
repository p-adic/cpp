// c:/Users/user/Documents/Programming/Music/Choui/a_Body.hpp

#pragma once
#include "a.hpp"
#include "OnKai/a_Body.hpp"
#include "../OnMei/a_Body.hpp"

inline Chou::Chou( const OnMei& N , const OnKai& scale ) noexcept : m_N( N ) , m_scale( scale ) {}

inline const OnMei& Chou::GetOnMei() const noexcept{ return m_N; }
inline const OnKai& Chou::GetOnKai() const noexcept{ return m_scale; }

inline string Chou::Display() const noexcept{ return m_N.Display() + m_scale.Display(); }

inline bool operator==( const Chou& N1 , const Chou& N2 ) noexcept { return ( N1.GetOnMei() == N2.GetOnMei() ) && ( N1.GetOnKai() == N2.GetOnKai() ); }
inline bool operator!=( const Chou& N1 , const Chou& N2 ) noexcept { return !( N1 == N2 ); }
