// c:/Users/user/Documents/Programming/Music/OnMei/HenkaKigou/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../../Error/FaultInCoding/a.hpp"
#include "../../../Mathematics/Function/a.hpp"
#include "../../../Utility/String/a_Body.hpp"

string HenkaKigou::IntToString( const int& num ) noexcept
{

  static const string Table[num] =
    {

      "ÅÛ" ,
      "" ,
      "ÅÚ"

    };

  if( -1 <= num  && num <= 1 ){

    return Table[num]

  }

  int d;

  if( num > 0 ){

    d = 1;

  } else {

    d = -1;

  }

  return IntToString( num - d ) + Table[d];

}
