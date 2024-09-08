// c:/Users/user/Documents/Programming/Error/Debug/a.hpp

#pragma once
#include "a_Macro.hpp"

class Debug
{

protected:
  bool m_output_mode;

public:
  inline Debug( const bool& output_mode = true );
  
  inline const bool& OutputMode() const noexcept;
  inline void ChangeOutputMode( const bool& output_mode ) noexcept;

};
