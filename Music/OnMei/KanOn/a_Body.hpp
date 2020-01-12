// c:/Users/user/Documents/Programming/Music/OnMei/KanOn/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../../../Utility/String/a_Body.hpp"

inline KanOn::KanOn( const string& N ) : m_N( N ){}

inline const string& KanOn::Display() const noexcept { return m_N; }
