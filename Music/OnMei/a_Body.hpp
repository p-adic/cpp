// c:/Users/user/Documents/Programming/Music/OnMei/a_Body.hpp

#pragma once
#include "a.hpp"

#include "KanOn/a_Body.hpp"
#include "HenkaKigou/a_Body.hpp"
#include "../../Mathematics/Arithmetic/Mod/a_Body.hpp"

inline OnMei::OnMei( const KanOn& N ) noexcept : OnMei( N , HenkaKigou( 0 ) ){}
inline OnMei::OnMei( const KanOn& N , const HenkaKigou& S ) noexcept : m_N( N ) , m_S( S ), m_num( KanOnToInt( N ) + S.GetNum() ) {}

inline string OnMei::Display() const noexcept { return m_N.Display() + m_S.Display(); }
inline const Mod<12>& OnMei::GetNum() const noexcept { return m_num; }
