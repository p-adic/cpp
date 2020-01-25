// c:/Users/user/Documents/Programming/Music/Chou/OnKai/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../../Error/FaultInCoding/a.hpp"

const Mod<12>& OnKai::NumTable( const Mod<7>& N ) const noexcept
{

  const Mod<12>* p_Table[7] =
    {

      &m_I ,
      &m_II ,
      &m_III ,
      &m_IV ,
      &m_V ,
      &m_VI ,
      &m_VII       

    };
  
  return *p_Table[ N.Represent() ];
  
}

DEFINITION_OF_GLOBAL_CONST_ON_KAI( Majour , 0 , 2 , 4 , 5 , 7 , 9 , 11 );
DEFINITION_OF_GLOBAL_CONST_ON_KAI( HarmonicMinour , 0 , 2 , 3 , 5 , 7 , 8 , 11 );
