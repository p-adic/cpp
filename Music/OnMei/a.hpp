// c:/Users/user/Documents/Programming/Music/OnMei/a.hpp

#pragma once
#include "KanOn/a.hpp"
#include "HenkaKigou/a.hpp"
#include "../../Mathematics/Arithmetic/Mod/a.hpp"

class OnMei
{

private:
  KanOn m_N;
  HenkaKigou m_S;
  Mod<12> m_num;

public:
  inline OnMei( const KanOn& N ) noexcept;
  inline OnMei( const KanOn& N , const HenkaKigou& S ) noexcept;
  
  inline string Display() const noexcept;
  inline const KanOn& GetKanOn() const noexcept;
  inline const HenkaKigou& GetHenkaKigou() const noexcept;
  inline const Mod<12>& GetNum() const noexcept;
  
  static int KanOnToInt( const KanOn& N ) noexcept;

};

inline bool operator==( const OnMei& N1 , const OnMei& N2 ) noexcept;
inline bool operator!=( const OnMei& N1 , const OnMei& N2 ) noexcept;
