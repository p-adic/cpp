// c:/Users/user/Documents/Programming/Music/SanWaOn/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../OnMei/a_Body.hpp"

inline SanWaOn::SanWaOn( const OnMei& N0 , const OnMei& N1 , const OnMei& N2 ) noexcept : m_N0( N0 ) , m_N1( N1 ) , m_N2( N2 ) {}

inline string SanWaOn::Display() const noexcept { return "(" + m_N0.Display() "," m_N1.Display() "," m_N2.Display() + ")"; }

inline bool operator!=( const SanWaOn& H1 , const SanWaOn& H2 ) noexcept { return !( H1 == H2 ); }
