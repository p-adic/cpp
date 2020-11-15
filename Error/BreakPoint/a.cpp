// c:/Users/user/Documents/Programming/Error/BreakPoint/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

void FlagCounter::Set( const uint& i0 , const uint& i1 ) noexcept
{

  m_i0 = i0;
  m_i1 = i1;
  return;

}

void FlagCounter::CheckActive() noexcept
{

  // FLAG‚ðˆê“x‚à’Ê‰ß‚·‚é‘O‚ÉCOUNT‚©‚çŒÄ‚Ño‚³‚ê‚½ê‡
  if( m_i1 == 0 ){

    return;

  }
  
  if( m_count > m_i0 ){

    m_b = ( ( m_count - m_i0 - 1 ) % m_i1 == 0 );

  } else{

    m_b = false;

  }

  return;
  
}

void CountCall( const char* const FILE , const int& LINE , const char* const FUNC , const uint& i0 ) noexcept
{

  if( CallFlagContainer( true , i0 , 1 ) ){
    
    BreakPoint( FILE , LINE , FUNC );

  }
  
  return;
  
}
