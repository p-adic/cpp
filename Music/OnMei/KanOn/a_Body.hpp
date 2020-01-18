// c:/Users/user/Documents/Programming/Music/OnMei/KanOn/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Mathematics/Arithmetic/Mod/a_Body.hpp"
#include "../../../Utility/String/a_Body.hpp"

inline KanOn::KanOn( const int& num ) noexcept : m_num( num ){}

inline const string& KanOn::Display() const noexcept { return IntToString( m_num ) ; }
inline const Mod<7>& KanOn::GetNum() const noexcept { return m_num; }

inline const string& KanOn::IntToString( const Mod<7>& num ) noexcept { return IntToString( num.Represent() ); }

inline bool operator==( const KanOn& N1 , const KanOn& N2 ) noexcept { return N1.GetNum() == N2.GetNum(); }
inline bool operator!=( const KanOn& N1 , const KanOn& N2 ) noexcept { return !( N1 == N2 ); }

inline const KanOn& operator+( const KanOn& N1 , const Mod<7>& N2 ) noexcept { return KanOnTable( N1.GetNum() + N2 ); }
inline Mod<7> operator-( const KanOn& N1 , const KanOn& N2 ) noexcept { return N1.GetNum() - N2.GetNum(); }

inline const KanOn& KanOnTable( const Mod<7>& num ) noexcept { return KanOnTable( num.Represent() ); }
