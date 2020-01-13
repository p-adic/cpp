// c:/Users/user/Documents/Programming/Music/OnMei/HenkaKigou/a_Body.hpp

#pragma once
#include "a.hpp"

inline HenkaKigou::HenkaKigou( const string& S ) : m_S( S ) , m_num( StringToInt( S ) ){}
inline HenkaKigou::HenkaKigou( const int& num ) : m_S( IntToString( num ) ) , m_num( num ){}

inline const string& HenkaKigou::Display() const noexcept { return m_S; }
inline const int& HenkaKigou::GetNum() const noexcept { return m_num; }

inline bool operator==( const HenkaKigou& S1 , const HenkaKigou& S2 ){ return S1.Display() == S2.Display(); }
inline bool operator!=( const HenkaKigou& S1 , const HenkaKigou& S2 ){ return !( S1 == S2 ); }

inline const HenkaKigou& HenkaKigouTable( const string& S ){ return HenkaKigouTable( HenkaKigou::StringToInt( S ) ); }
