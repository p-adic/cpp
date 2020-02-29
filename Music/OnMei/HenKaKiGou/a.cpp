// c:/Users/user/Documents/Programming/Music/OnMei/HenKaKiGou/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../../Error/FaultInCoding/a.hpp"
#include "../../../Mathematics/Function/a.hpp"
#include "../../../Utility/String/a_Body.hpp"

HenKaKiGou& HenKaKiGou::operator++() noexcept
{

  m_num += 1;
  return *this;

}

HenKaKiGou& HenKaKiGou::operator--() noexcept
{

  m_num -= 1;
  return *this;

}
string HenKaKiGou::IntToString( const int& num ) noexcept
{

  static const string Table[3] =
    {

      "ÅÛ" ,
      "" ,
      "ÅÚ"

    };

  if( -1 <= num  && num <= 1 ){

    return Table[num+1];

  }

  int d;

  if( num > 0 ){

    d = 1;

  } else {

    d = -1;

  }

  return IntToString( num - d ) + Table[d+1];

}
