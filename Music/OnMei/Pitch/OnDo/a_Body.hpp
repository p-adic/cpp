// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/OnDo/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

inline string OnDo::Display() const noexcept { return m_settouji + to_string( m_dosuu ) + "Do";}

inline OnDo::OnDo( const Pitch& P1 , const Pitch& P2 ) noexcept : OnDo( P1 , P2 , ComputeSignedDosuu( P1 , P2 ) ) {}
inline OnDo::OnDo( const Pitch& P1 , const Pitch& P2 , const int& signed_dosuu ) noexcept : OnDo( P1 , P2 , signed_dosuu , signed_dosuu >= 0 ) {}
inline OnDo::OnDo( const Pitch& P1 , const Pitch& P2 , const int& signed_dosuu , const bool& valid ) noexcept : OnDo( ComputeZeroIndexedDosuu( signed_dosuu , valid ) , ComputePitchDifference( P1 , P2 , valid ) ) {}
inline OnDo::OnDo( const uint& zero_indexed_dosuu , const int& pitch_difference ) noexcept : m_settouji( ComputeSettouji( zero_indexed_dosuu , pitch_difference ) ) , m_dosuu( zero_indexed_dosuu + 1 ) , m_dosuu_mod( m_dosuu % 7 ) {}
