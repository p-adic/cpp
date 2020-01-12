// c:/Users/user/Documents/Programming/Music/OnMei/a_Body.hpp

#pragma once
#include "a.hpp"

#include "KanOn/a_Body.hpp"
#include "../../Mathematics/Arithmetic/Mod/a_Body.hpp"

inline OnMei::OnMei( const KanOn& N ) : OnMei( N , 0 ){}
inline OnMei::OnMei( const KanOn& N , const int& n ) : m_N( N ) , m_sharp( n ){}
inline OnMei::OnMei( const OnMei& N ) : OnMei( N.m_N , N.m_sharp ){}

inline const string& OnMei::Display() const noexcept { return m_N.Display(); }
