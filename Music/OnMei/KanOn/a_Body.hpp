// c:/Users/user/Documents/Programming/Music/OnMei/KanOn/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Mathematics/Arithmetic/Mod/a_Body.hpp"
#include "../../../Utility/String/a_Body.hpp"

inline KanOn::KanOn( const int& num ) noexcept : m_num( num ){}

inline const string& KanOn::Display() const noexcept { return IntToString( Represent( m_num ) ) ; }
inline const uint& KanOn::GetNum() const noexcept { return m_num; }

inline bool operator==( const KanOn& N1 , const KanOn& N2 ) noexcept { return N1.GetNum() == N2.GetNum(); }
inline bool operator!=( const KanOn& N1 , const KanOn& N2 ) noexcept { return !( N1 == N2 ); }


