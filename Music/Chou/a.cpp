// c:/Users/user/Documents/Programming/Music/Chou/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

HenKaKiGou Chou::HenKaKiGouTable_Body( const KaiMei& num , const KanOn& N ) const noexcept
{

  const int d = ( OnMei::KanOnToPitchClass( m_N.GetKanOn() ) + m_scale.PitchClassTable( num ) - OnMei( N ).GetPitchClass() ).Represent();
  const HenKaKiGou& S = m_N.GetHenKaKiGou();

  if( d < 6 ){

    return HenKaKiGou( d ) + S;
  
  }
  
  return HenKaKiGou( d - 12 ) + S;

}
