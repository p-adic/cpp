// c:/Users/user/Documents/Programming/Music/OnMei/KanOn/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../../Error/FaultInCoding/a.hpp"
#include "../../../Mathematics/Function/a.hpp"


KanOn& KanOn::operator++( int ) noexcept
{

  m_num += 1;
  return *this;

}

KanOn& KanOn::operator--( int ) noexcept
{

  m_num -= 1;
  return *this;

}

const string& KanOn::IntToString( const int& num ) noexcept
{

  static const string Table[8] =
    {

      "Do" ,
      "Re" ,
      "Mi" ,
      "Fa" ,
      "So" ,
      "La" ,
      "Ti" ,
      "Error"

    };

  if( num >= 7 ){

    return Table[7];

  }

  return Table[num];

}

DEFINITION_OF_GLOBAL_CONST_KAN_ON( Do , 0 );
DEFINITION_OF_GLOBAL_CONST_KAN_ON( Re , 1 );
DEFINITION_OF_GLOBAL_CONST_KAN_ON( Mi , 2 );
DEFINITION_OF_GLOBAL_CONST_KAN_ON( Fa , 3 );
DEFINITION_OF_GLOBAL_CONST_KAN_ON( So , 4 );
DEFINITION_OF_GLOBAL_CONST_KAN_ON( La , 5 );
DEFINITION_OF_GLOBAL_CONST_KAN_ON( Ti , 6 );

const KanOn& KanOnTable( const int& num ) noexcept
{

  const FunctionPointerType<const KanOn&> Table[7] =
    {

      &Do ,
      &Re ,
      &Mi ,
      &Fa ,
      &So ,
      &La ,
      &Ti

    };
  
  return ( *Table[num] )();
  
}
