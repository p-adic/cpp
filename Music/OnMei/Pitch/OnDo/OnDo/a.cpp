// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/OnDo/a.cpp

#include "../../../Header.hpp"
#include "a_Body.hpp"

bool OnDo::CheckKyouWaOnTei() const noexcept
{

  if( CheckKyouWaOnteiNonBottom() ){

    return true;

  }

  return ( m_dosuu_mod == 4 ) && ( m_settouji == KanZen() );

}

bool OnDo::CheckKyouWaOnTeiNonBottom() const noexcept
{

  if( m_dosuu_mod == 1 || m_dosuu_mod == 5 ){

    return m_settouji == KanZen();

  }

  if( m_dosuu_mod == 3 || m_dosuu_mod == 6 ){

    return ( m_settouji == Chou() ) || ( m_settouji == Tan() );

  }

  return false;

}

int OnDo::ComputeSignedDoSuu( const Pitch& P1 , const Pitch& P2 ) noexcept
{

  const int N1 = ( ( ( P1.GetOnMei() ).GetKanOn() ).GetNum() ).Represent() + P1.GetOctave() * 7;
  const int N2 = ( ( ( P2.GetOnMei() ).GetKanOn() ).GetNum() ).Represent() + P2.GetOctave() * 7;

  return N2 - N1;

}

uint OnDo::ComputeZeroIndexedDoSuu( const int& signed_dosuu , const bool& valid ) noexcept
{

  if( valid ){

    return (uint)signed_dosuu;

  }

  return (uint)(- signed_dosuu );
  
}

uint OnDo::ComputePitchDifference( const Pitch& P1 , const Pitch& P2 , const bool& valid ) noexcept
{

  if( !valid ){

    return ComputePitchDifference( P2 , P1 , true );

  }

  return P2.GetNoteNumber() - P1.GetNoteNumber();
 
}
