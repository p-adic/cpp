// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/OnDo/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "SetTouJi/a_Body.hpp"

inline OnDo::OnDo( const Pitch& P1 , const Pitch& P2 ) noexcept : OnDo( ComputeSignedZeroIndexedDoSuu( P1 , P2 ) , ComputeSignedPitchDifference( P1 , P2 ) ) {}
inline OnDo::OnDo( const int& D , const int& d ) noexcept : OnDo( D , d , D >= 0 ? 1 : -1 ) {}
inline OnDo::OnDo( const int& D , const int& d , const int& sign ) noexcept : OnDo( (uint)( sign * D ) , sign * d ) {}
inline OnDo::OnDo( const ZeroIndexedDoSuu& D , const PitchDifference& d ) noexcept : m_settouji( SetTouJiOfOnDo::Compute( D , d ) ) , m_dosuu( D + 1 ) , m_dosuu_mod( m_dosuu ) {}

inline const SetTouJiOfOnDo& OnDo::GetSetTouJi() const noexcept { return m_settouji; }
inline const DoSuu& OnDo::GetDoSuu() const noexcept { return m_dosuu; }
inline const Mod<7>& OnDo::GetDoSuuMod() const noexcept { return m_dosuu_mod; }

inline string OnDo::Display() const noexcept { return m_settouji.Get() + to_string( m_dosuu ) + "Do";}

inline int OnDo::PitchToAbsoluteDoSuu( const Pitch& P ) noexcept { return ( ( ( P.GetOnMei() ).GetKanOn() ).GetNum() ).Represent() + P.GetOctave() * 7; }
inline int OnDo::ComputeSignedZeroIndexedDoSuu( const Pitch& P1 , const Pitch& P2 ) noexcept { return PitchToAbsoluteDoSuu( P2 ) - PitchToAbsoluteDoSuu( P1 ); }
inline int OnDo::ComputeSignedPitchDifference( const Pitch& P1 , const Pitch& P2 ) noexcept { return P2.GetNoteNumber() - P1.GetNoteNumber(); }

inline bool operator==( const OnDo& D1 , const OnDo& D2 ) noexcept { return ( D1.GetSetTouJi() == D2.GetSetTouJi() ) && ( D1.GetDoSuu() == D2.GetDoSuu() ); }
inline bool operator!=( const OnDo& D1 , const OnDo& D2 ) noexcept { return !( D1 == D2 ); }
