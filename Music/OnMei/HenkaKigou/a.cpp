// c:/Users/user/Documents/Programming/Music/OnMei/HenkaKigou/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../../Utility/String/a_Body.hpp"

int HenkaKigou::StringToInt( const string& S )
{

  for( int num = -1 ; num <= 1 ; num++ ){

    if( S == IntToString( num ) ){

      return num;

    }

  }

  return 2;

}

const string& HenkaKigou::IntToString( const int& num )
{

  static const string Table[4] =
    {

      "ó" ,
      "" ,
      "ò" ,
      "Error"

    };

  if( num < -1 || num > 1 ){

    return Table[3];

  }

  return Table[num + 1];

}

const HenkaKigou& Flat()
{

  static const HenkaKigou& S( to_string( "ó" ) );
  return S;

}

const HenkaKigou& Natural()
{

  static const HenkaKigou& S( to_string( "" ) );
  return S;

}

const HenkaKigou& Sharp()
{

  static const HenkaKigou& S( to_string( "ò" ) );
  return S;

}

const HenkaKigou& HenkaKigouTable( const int& num )
{

  if( num < -1 || 1 < num ){

    ERR_CODE;

  }

  const FunctionPointerType<const HenkaKigou&> Table[3] =
    {

      &Flat ,
      &Natural ,
      &Sharp

    };

  return ( *Table[num+1] )();

}
