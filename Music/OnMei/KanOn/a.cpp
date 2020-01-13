// c:/Users/user/Documents/Programming/Music/OnMei/KanOn/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../../Error/FaultInCoding/a.hpp"
#include "../../../Mathematics/Function/a.hpp"

uint KanOn::StringToInt( const string& N )
{

  for( uint num = 0 ; num < 7 ; num++ ){

    if( N == IntToString( num ) ){

      return num;

    }

  }

  return -1;

}

const string& KanOn::IntToString( const uint& num )
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

DEFINITION_OF_GLOBAL_CONST_KAN_ON( Do );
DEFINITION_OF_GLOBAL_CONST_KAN_ON( Re );
DEFINITION_OF_GLOBAL_CONST_KAN_ON( Mi );
DEFINITION_OF_GLOBAL_CONST_KAN_ON( Fa );
DEFINITION_OF_GLOBAL_CONST_KAN_ON( So );
DEFINITION_OF_GLOBAL_CONST_KAN_ON( La );
DEFINITION_OF_GLOBAL_CONST_KAN_ON( Ti );

const KanOn& KanOnTable( const uint& num )
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

  if( num >= 7 ){

    ERR_CODE;

  }
  
  return ( *Table[num] )();
  
}
