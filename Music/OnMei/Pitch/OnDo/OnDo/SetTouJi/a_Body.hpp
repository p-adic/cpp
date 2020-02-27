// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/OnDo/SetTouJi/a_Body.hpp

#pragma once
#include "a.hpp"

inline SetTouJiOfOnDo::SetTouJiOfOnDo( const string& s ) noexcept : m_s( s ){}

inline const string& SetTouJiOfOnDo::Get() const noexcept { return m_s; }

inline operator==( const SetTouJiOfOnDo& s1 , const SetTouJiOfOnDo& s2 ) noexcept { return s1.Get() == s2.Get(); }
inline operator!=( const SetTouJiOfOnDo& s1 , const SetTouJiOfOnDo& s2 ) noexcept { return !( s1 == s2 ); }
