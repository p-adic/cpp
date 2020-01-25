// c:/Users/user/Documents/Programming/Music/Chou/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

HenkaKigou Chou::HenkaKigouTable_Body( const KaiMei& num , const KanOn& N ) const noexcept
{

  const int d = ( m_N.GetPitchClass() + m_scale.PitchClassTable( num ) - OnMei( N ).GetPitchClass() ).Represent();

  if( d < 6 ){

    return HenkaKigou( d );
  
  }
  
  return HenkaKigou( d - 12 );

}
