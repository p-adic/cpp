// c:/Users/user/Documents/Programming/Music/Choui/a_Body.hpp

#pragma once
#include "a.hpp"
#include "OnKai/a_Body.hpp"
#include "../OnMei/a_Body.hpp"


inline OnMei Chou::OnMeiTable_Body( const KaiMei& num , const KanOn& N ) const noexcept{ return OnMei( N , HenkaKigouTable_Body( num , N ) ); }

inline Chou::Chou( const OnMei& N , const OnKai& scale ) noexcept : m_N( N ) , m_scale( scale ) {}

inline KanOn Chou::KanOnTable( const KaiMei& num ) const noexcept{ return m_N.GetKanOn() + num; }
inline HenkaKigou Chou::HenkaKigouTable( const KaiMei& num ) const noexcept{ return HenkaKigouTable_Body( num , KanOnTable( num ) ); }
inline OnMei Chou::OnMeiTable( const KaiMei& num ) const noexcept{ return OnMeiTable_Body( num , KanOnTable( num )); }

inline const OnMei& Chou::GetOnMei() const noexcept{ return m_N; }
inline const OnKai& Chou::GetOnKai() const noexcept{ return m_scale; }

inline string Chou::Display() const noexcept{ return m_scale.Display() + ": " + m_N.Display(); }

inline bool operator==( const Chou& N1 , const Chou& N2 ) noexcept { return ( N1.GetOnMei() == N2.GetOnMei() ) && ( N1.GetOnKai() == N2.GetOnKai() ); }
inline bool operator!=( const Chou& N1 , const Chou& N2 ) noexcept { return !( N1 == N2 ); }
