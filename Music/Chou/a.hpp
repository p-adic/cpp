// c:/Users/user/Documents/Programming/Music/Chou/a.hpp

#pragma once
#include "OnKai/a.hpp"
#include "../OnMei/a.hpp"

class Chou
{

private:
  OnMei m_N;
  OnKai m_scale;

public:
  inline Chou( const OnMei& N , const OnKai& scale = Majour() ) noexcept;

  inline const OnMei& GetOnMei() const noexcept;
  inline const OnKai& GetOnKai() const noexcept;

  inline string Display() const noexcept;

  OnMei OnMeiTable( const Mod<7>& num ) const noexcept;

};

inline bool operator==( const Chou& N1 , const Chou& N2 ) noexcept;
inline bool operator!=( const Chou& N1 , const Chou& N2 ) noexcept;
