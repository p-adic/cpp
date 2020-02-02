// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../a_Body.hpp"

#include <cmath>

inline Pitch::Pitch( const OnMei& N , const Octave& octave ) noexcept : m_N( N ) , m_octave( octave ) {}

inline Octave Pitch::GetNum() const noexcept { return ( m_N.GetPitchClass() ).Represent() + ( m_octave * 12 ); }
inline const OnMei& Pitch::GetOnMei() const noexcept { return m_N; }
inline const Octave& Pitch::GetOctave() const noexcept { return m_octave; }
inline double Pitch::GetShuuhasuu() const noexcept { return g_La4_shuuhasuu * pow( 2.0 , ( GetNum() - g_La4_octave ) / 12.0 ); }
inline PitchClass Pitch::GetPitchClass() const noexcept { return m_N.GetPitchClass(); }

inline string Pitch::Display() const noexcept { return m_N.Display() + to_string( m_octave ); }

inline bool operator==( const Pitch& N1 , const Pitch& N2 ) noexcept { return ( N1.GetOnMei() == N2.GetOnMei() ) && ( N1.GetOctave() == N2.GetOctave() ); }
inline bool operator!=( const Pitch& N1 , const Pitch& N2 ) noexcept { return!( N1 == N2 ); }
