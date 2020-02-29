// c:/Users/user/Documents/Programming/Music/OnMei/HenkaKigou/a_Body.hpp

#pragma once
#include "a.hpp"

inline HenkaKigou::HenkaKigou( const int& num ) noexcept : m_num( num ){}

inline string HenkaKigou::Display() const noexcept { return IntToString( m_num ); }
inline const int& HenkaKigou::GetNum() const noexcept { return m_num; }

inline bool operator==( const HenkaKigou& S1 , const HenkaKigou& S2 ) noexcept { return S1.GetNum() == S2.GetNum(); }
inline bool operator!=( const HenkaKigou& S1 , const HenkaKigou& S2 ) noexcept { return !( S1 == S2 ); }

inline HenkaKigou operator+( const HenkaKigou& S1 , const HenkaKigou& S2 ) noexcept { return HenkaKigou( S1.GetNum() + S2.GetNum() ); }
inline HenkaKigou operator-( const HenkaKigou& S1 , const HenkaKigou& S2 ) noexcept { return HenkaKigou( S1.GetNum() - S2.GetNum() ); }
