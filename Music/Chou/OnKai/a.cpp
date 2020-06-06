// c:/Users/user/Documents/Programming/Music/Chou/OnKai/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../../Error/FaultInCoding/a.hpp"

const PitchClass& OnKai::PitchClassTable( const KaiMei& num ) const noexcept
{

  const PitchClass* p_Table[7] =
    {

      &m_I ,
      &m_II ,
      &m_III ,
      &m_IV ,
      &m_V ,
      &m_VI ,
      &m_VII

    };
  
  return *p_Table[ num.Represent() ];
  
}

DEFINITION_OF_GLOBAL_CONST_ON_KAI( ChouOnKai , 0 , 2 , 4 , 5 , 7 , 9 , 11 );
DEFINITION_OF_GLOBAL_CONST_ON_KAI( WaSeiTekiTanOnKai , 0 , 2 , 3 , 5 , 7 , 8 , 11 );
DEFINITION_OF_GLOBAL_CONST_ON_KAI( ShiZenTanOnKai , 0 , 2 , 3 , 5 , 7 , 8 , 10 );
