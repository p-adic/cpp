// c:/Users/user/Documents/Programming/Music/OnMei/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

#include "../../Error/FaultInCoding/a.hpp"
#include "../../Mathematics/Function/a.hpp"

Mod<12> OnMei::GetNumber() const
{

  FunctionPointerType<const KanOn&> KanOnTable[7] =
    {

      &Do ,
      &Re ,
      &Mi ,
      &Fa ,
      &So ,
      &La ,
      &Ti

    };

  for( uint i = 0 ; i < 7 ; i++ ){

    if( m_N == ( *KanOnTable[i] )() ){

      auto n = Mod<12>( i );
      n += m_sharp;
      return n;

    }

  }

  ERR_CODE;
  return Mod<12>( -1 );

}
