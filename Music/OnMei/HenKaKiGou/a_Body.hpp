// c:/Users/user/Documents/Programming/Music/OnMei/HenKaKiGou/a_Body.hpp

#pragma once
#include "a.hpp"

inline HenKaKiGou::HenKaKiGou( const int& num ) noexcept : m_num( num ){}

inline string HenKaKiGou::Display() const noexcept { return IntToString( m_num ); }
inline const int& HenKaKiGou::GetNum() const noexcept { return m_num; }

inline bool operator==( const HenKaKiGou& S1 , const HenKaKiGou& S2 ) noexcept { return S1.GetNum() == S2.GetNum(); }
inline bool operator!=( const HenKaKiGou& S1 , const HenKaKiGou& S2 ) noexcept { return !( S1 == S2 ); }

inline HenKaKiGou operator+( const HenKaKiGou& S1 , const HenKaKiGou& S2 ) noexcept { return HenKaKiGou( S1.GetNum() + S2.GetNum() ); }
inline HenKaKiGou operator-( const HenKaKiGou& S1 , const HenKaKiGou& S2 ) noexcept { return HenKaKiGou( S1.GetNum() - S2.GetNum() ); }
