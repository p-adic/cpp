// c:/Users/user/Documents/Programming/Music/Chou/KaiMei/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

string KaiMei::SymbolTable( const int& n ) noexcept
{
  
  if( n < 7 ){

    const string s[7] =
      {

	"I" ,
	"II" ,
	"III" ,
	"IV" ,
	"V" ,
	"VI" ,
	"VII"

      };

    return s[n];

  }

  return SymbolTable( n % 7 );

}
