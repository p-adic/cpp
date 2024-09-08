// c:/Users/user/Documents/Programming/Error/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

inline Debug::Debug( const bool& output_mode ) : m_output_mode( output_mode ) {}

inline const bool& Debug::OutputMode() const noexcept { return m_output_mode; }
inline void Debug::ChangeOutputMode( const bool& output_mode ) noexcept { m_output_mode = output_mode; }
