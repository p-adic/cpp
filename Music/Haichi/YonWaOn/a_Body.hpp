// c:/Users/user/Documents/Programming/Music/Haichi/YonWaOn/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../OnMei/a_Body.hpp"

inline YonWaOn::YonWaOn( const OnMei& N0 , const OnMei& N1 , const OnMei& N2 , const OnMei& N3 ) noexcept : m_N0( N0 ) , m_N1( N1 ) , m_N2( N2 ) , m_N3( N3 ) , m_is_valid( m_N0 != m_N1 && m_N1 != m_N2 && m_N2 != m_N3 && m_N3 != m_N0 && m_N0 != m_N2 && m_N1 != m_N3 ) {}

inline string YonWaOn::Display() const noexcept { return "(" + m_N0.Display() + "," + m_N1.Display() + "," + m_N2.Display() + "," + m_N3.Display() + ")"; }

inline const bool& YonWaOn::IsValid() const noexcept { return m_is_valid; }

inline bool operator!=( const YonWaOn& H1 , const YonWaOn& H2 ) noexcept { return !( H1 == H2 ); }
