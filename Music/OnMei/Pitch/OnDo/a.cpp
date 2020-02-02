// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/OnDo/a.cpp

#include "../../../Header.hpp"
#include "a_Body.hpp"

bool OnDo::CheckKyouWaOntei() const noexcept
{

  if( CheckKyouWaOnteiNonBottom() ){

    return true;

  }

  return ( m_dosuu_mod == 4 ) && ( m_settouji == Kanzen() );

}

bool OnDo::CheckKyouWaOnteiNonBottom() const noexcept
{

  if( m_dosuu_mod == 1 || m_dosuu_mod == 5 ){

    return m_settouji == Kanzen();

  }

  if( m_dosuu_mod == 3 || m_dosuu_mod == 6 ){

    return ( m_settouji == Chou() ) || ( m_settouji == Tan() );

  }

  return false;

}

int OnDo::ComputeSignedDosuu( const Pitch& P1 , const Pitch& P2 ) noexcept
{

  const int N1 = ( ( ( P1.GetOnMei() ).GetKanOn() ).GetNum() ).Represent() + P1.GetOctave() * 7;
  const int N2 = ( ( ( P2.GetOnMei() ).GetKanOn() ).GetNum() ).Represent() + P2.GetOctave() * 7;

  return N2 - N1;

}

uint OnDo::ComputeZeroIndexedDosuu( const int& signed_dosuu , const bool& valid ) noexcept
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

  return P2.GetNum() - P1.GetNum();
 
}

const string& OnDo::ComputeSettouji( const uint& zero_indexed_dosuu , const int& pitch_difference ) noexcept
{

  const int Table[7] =
    {

      0 ,
      3 ,
      7 ,
      10 ,
      14 ,
      17 ,
      21

    };

  const int d = pitch_difference * 2 - ( Table[zero_indexed_dosuu%7] + ( zero_indexed_dosuu / 7 ) * 24 );

  if( d == 0 ){

    return Kanzen();

  }

  if( d == 1 ){

    return Chou();

  }

  if( d == -1 ){

    return Tan();

  }

  if( d == 2 || d == 3 ){

    return Zou();

  }

  if( d == -2 || d == -3 ){

    return Gen();

  }

  if( d > 0 ){

    return JuuZou();

  }

  return JuuGen();

}

DEFINITION_OF_SETTOUJI_OF_ONDO( Kanzen );
DEFINITION_OF_SETTOUJI_OF_ONDO( Chou );
DEFINITION_OF_SETTOUJI_OF_ONDO( Tan );
DEFINITION_OF_SETTOUJI_OF_ONDO( Zou );
DEFINITION_OF_SETTOUJI_OF_ONDO( Gen );
DEFINITION_OF_SETTOUJI_OF_ONDO( JuuZou );
DEFINITION_OF_SETTOUJI_OF_ONDO( JuuGen );
