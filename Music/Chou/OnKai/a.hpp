// c:/Users/user/Documents/Programming/Music/Chou/OnKai/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../KaiMei/a.hpp"
#include "../../OnMei/a.hpp"

class OnKai
{

private:
  string m_scale;
  PitchClass m_I;
  PitchClass m_II;
  PitchClass m_III;
  PitchClass m_IV;
  PitchClass m_V;
  PitchClass m_VI;
  PitchClass m_VII;

public:
  inline OnKai( const string& scale , const int& I , const int& II , const int& III , const int& IV , const int& V , const int& VI , const int& VII ) noexcept;
  
  inline const string& Display() const noexcept;
  
  const PitchClass& PitchClassTable( const KaiMei& num ) const noexcept;

};

inline bool operator==( const OnKai& N1 , const OnKai& N2 ) noexcept;
inline bool operator!=( const OnKai& N1 , const OnKai& N2 ) noexcept;

const OnKai& ChouOnKai() noexcept;
const OnKai& WaSeiTekiTanOnKai() noexcept;
const OnKai& ShiZenTanOnKai() noexcept;
