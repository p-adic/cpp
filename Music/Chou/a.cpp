// c:/Users/user/Documents/Programming/Music/Chou/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

HenkaKigou Chou::HenkaKigouTable_Body( const KaiMei& num , const KanOn& N ) const noexcept
{

  const int d = ( OnMei::KanOnToPitchClass( m_N.GetKanOn() ) + m_scale.PitchClassTable( num ) - OnMei( N ).GetPitchClass() ).Represent();
  const HenkaKigou& S = m_N.GetHenkaKigou();

  if( d < 6 ){

    return HenkaKigou( d ) + S;
  
  }
  
  return HenkaKigou( d - 12 ) + S;

}
