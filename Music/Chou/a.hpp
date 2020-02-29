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
  inline Chou( const OnMei& N , const OnKai& scale = ChouOnKai() ) noexcept;

  inline const OnMei& GetOnMei() const noexcept;
  inline const OnKai& GetOnKai() const noexcept;

  inline string Display() const noexcept;

  inline KanOn KanOnTable( const KaiMei& num ) const noexcept;
  inline HenKaKiGou HenKaKiGouTable( const KaiMei& num ) const noexcept;
  inline OnMei OnMeiTable( const KaiMei& num ) const noexcept;

private:
  HenKaKiGou HenKaKiGouTable_Body( const KaiMei& num , const KanOn& N ) const noexcept;
  inline OnMei OnMeiTable_Body( const KaiMei& num , const KanOn& N ) const noexcept;

};

inline bool operator==( const Chou& N1 , const Chou& N2 ) noexcept;
inline bool operator!=( const Chou& N1 , const Chou& N2 ) noexcept;
