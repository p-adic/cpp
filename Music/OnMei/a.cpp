// c:/Users/user/Documents/Programming/Music/OnMei/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

OnMei& OnMei::operator++() noexcept
{

  ++m_S;
  return *this;

}

OnMei& OnMei::operator--() noexcept
{

  --m_S;
  return *this;

}

PitchClass OnMei::KanOnToPitchClass( const KanOn& N ) noexcept
{

  const int Table[7] =
    {

      0 ,
      2 ,
      4 ,
      5 ,
      7 ,
      9 ,
      11
      
    };

  return PitchClass( Table[ ( N.GetNum() ).Represent() ] );

}

