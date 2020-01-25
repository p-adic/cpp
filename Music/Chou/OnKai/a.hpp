// c:/Users/user/Documents/Programming/Music/Chou/OnKai/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../OnMei/a.hpp"
#include "../../../Mathematics/Arithmetic/Mod/a.hpp"

class OnKai
{

private:
  string m_scale;
  Mod<12> m_I;
  Mod<12> m_II;
  Mod<12> m_III;
  Mod<12> m_IV;
  Mod<12> m_V;
  Mod<12> m_VI;
  Mod<12> m_VII;

public:
  inline OnKai( const string& scale , const int& I , const int& II , const int& III , const int& IV , const int& V , const int& VI , const int& VII ) noexcept;
  
  inline const string& Display() const noexcept;
  const Mod<12>& NumTable( const Mod<7>& N ) const noexcept;

};

inline bool operator==( const OnKai& N1 , const OnKai& N2 ) noexcept;
inline bool operator!=( const OnKai& N1 , const OnKai& N2 ) noexcept;

const OnKai& Majour() noexcept;
const OnKai& HarmonicMinour() noexcept;
