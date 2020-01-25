// c:/Users/user/Documents/Programming/Music/Chou/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

OnMei Chou::OnMeiTable( const Mod<7>& num ) const noexcept
{

  const KanOn N = m_N.GetKanOn() + num;
  const int d = ( m_N.GetNum() +  m_scale.NumTable( num ) - OnMei( N ).GetNum() ).Represent();

  if( d < 6 ){

    return OnMei( N , d );
  
  }
  
  return OnMei( N , d - 12 );

}
