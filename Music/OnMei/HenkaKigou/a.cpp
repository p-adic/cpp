// c:/Users/user/Documents/Programming/Music/OnMei/HenkaKigou/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

int HenkaKigou::StringToInt( const string& sym )
{

  for( num = -1 ; num <= 1 ; num++ ){

    if( sym == IntToString( num ) ){

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
