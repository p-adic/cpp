// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/OnDo/a.cpp

#include "../../../Header.hpp"
#include "a_Body.hpp"

bool OnDo::CheckKyouWaOnTei() const noexcept
{

  if( CheckKyouWaOnTeiBottom() ){

    return true;

  }

  return ( m_dosuu_mod == 4 ) && ( m_settouji == SetTouJiOfOnDo::KanZen() );

}

bool OnDo::CheckKyouWaOnTeiBottom() const noexcept
{

  if( m_dosuu_mod == 1 || m_dosuu_mod == 5 ){

    return m_settouji == SetTouJiOfOnDo::KanZen();

  }

  if( m_dosuu_mod == 3 || m_dosuu_mod == 6 ){

    return ( m_settouji == SetTouJiOfOnDo::Chou() ) || ( m_settouji == SetTouJiOfOnDo::Tan() );

  }

  return false;

}
