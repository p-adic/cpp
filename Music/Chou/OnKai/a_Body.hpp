// c:/Users/user/Documents/Programming/Music/Chou/OnKai/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../KaiMei/a_Body.hpp"
#include "../../OnMei/a_Body.hpp"

inline OnKai::OnKai( const string& scale , const int& I , const int& II , const int& III , const int& IV , const int& V , const int& VI , const int& VII ) noexcept : m_scale( scale ) , m_I( I ) , m_II( II ) , m_III( III ) , m_IV( IV ) , m_V( V ) , m_VI( VI ) , m_VII( VII ){}

inline const string& OnKai::Display() const noexcept{ return m_scale; }

inline bool operator==( const OnKai& N1 , const OnKai& N2 ) noexcept { return N1.Display() == N2.Display(); }
inline bool operator!=( const OnKai& N1 , const OnKai& N2 ) noexcept { return !( N1 == N2 ); }
