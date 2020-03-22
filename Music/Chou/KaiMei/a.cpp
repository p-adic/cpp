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

const KaiMei& operator+( const KaiMei& n1 , const int& n2 ) noexcept
{

  const Mod<7> n{ n1.Represent() + n2 };

  const FunctionPointerType<const KaiMei&> f[7] =
    {

      &( KaiMei::I ) ,
      &( KaiMei::II ) ,
      &( KaiMei::III ) ,
      &( KaiMei::IV ) ,
      &( KaiMei::V ) ,
      &( KaiMei::VI ) ,
      &( KaiMei::VII )

    };

  return ( f[ n.Represent() ] )();

}
