// c:/Users/user/Documents/Programming/Music/OnMei/HenkaKigou/a_Body.hpp

#pragma once
#include "a.hpp"

inline HenkaKigou::HenkaKigou( const string& sym ) : m_sym( sym ) , m_num( StringToInt( sym ) ){}
inline HenkaKigou::HenkaKigou( const int& num ) : m_sym( IntToString( num ) ) , m_num( num ){}
inline HenkaKigou::HenkaKigou( const HenkaKigou& S ) : m_sym( S.m_sym ) , m_num( S.m_num ){}

inline const string& HenkaKigou::Display() const noexcept { return m_sym; }
inline const int& HenkaKigou::GetNum() const noexcept { return m_num; }
