// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/OnDo/SetTouJi/a.cpp

#include "../../../../Header.hpp"
#include "a_Body.hpp"

const SetTouJiOfOnDo& SetTouJiOfOnDo::Compute( const ZeroIndexedDoSuu& D , const PitchDifference& d ) noexcept
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

  const int n = d * 2 - ( Table[D%7] + ( D / 7 ) * 24 );

  if( n == 0 ){

    return KanZen();

  }

  if( n == 1 ){

    return Chou();

  }

  if( n == -1 ){

    return Tan();

  }

  if( n == 2 || n == 3 ){

    return Zou();

  }

  if( n == -2 || n == -3 ){

    return Gen();

  }

  if( n > 0 ){

    return JuuZou();

  }

  return JuuGen();

}

DEFINITION_OF_SETTOUJI_OF_ONDO( KanZen );
DEFINITION_OF_SETTOUJI_OF_ONDO( Chou );
DEFINITION_OF_SETTOUJI_OF_ONDO( Tan );
DEFINITION_OF_SETTOUJI_OF_ONDO( Zou );
DEFINITION_OF_SETTOUJI_OF_ONDO( Gen );
DEFINITION_OF_SETTOUJI_OF_ONDO( JuuZou );
DEFINITION_OF_SETTOUJI_OF_ONDO( JuuGen );
