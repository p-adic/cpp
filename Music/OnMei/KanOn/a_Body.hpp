// c:/Users/user/Documents/Programming/Music/OnMei/KanOn/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../../../Utility/String/a_Body.hpp"

inline KanOn::KanOn( const string& N ) : m_N( N ){}

inline const string& KanOn::Display() const noexcept { return m_N; }

inline bool operator==( const KanOn& N1 , const KanOn& N2 ){ return N1.Display() == N2.Display(); }
inline bool operator!=( const KanOn& N1 , const KanOn& N2 ){ return !( N1 == N2 ); }
