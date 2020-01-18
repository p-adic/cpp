// c:/Users/user/Documents/Programming/Music/OnMei/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

int OnMei::KanOnToInt( const KanOn& N ) noexcept
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

  return Table[ ( N.GetNum() ).Represent() ];

}

