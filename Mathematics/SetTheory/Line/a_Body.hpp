// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
void LineSubset<INT>::insert( const INT& i ) noexcept
{

  auto itr0 = m_l.lower_bound( i - 1 ) , end = m_l.end();

  if( itr0 == end ){

    m_l[i] = i;
    return;

  }

  auto& [r0,l0] = *itr0;

  if( l0 <= i && i <= r0 ){

    return;

  }

  if( i + 1 == l0 ){

    l0--;
    return;

  }

  if( i + 1 < l0 ){

    m_l[i] = i;
    return;

  }
  
  auto itr1 = m_l.lower_bound( i + 1 );

  if( itr1 == end ){

    m_l[i] = l0;

  } else {
    
    auto& [r1,l1] = *itr1;

    if( i + 1 < l1 ){

      m_l[i] = l0;

    } else {
    
      l1 = l0;

    }

  }
  
  m_l.erase( itr0 );
  return;

}

template <typename INT>
void LineSubset<INT>::erase( const INT& i ) noexcept
{

  auto itr = m_l.lower_bound( i );

  if( itr == m_l.end() ){

    return;

  }

  auto& [r,l] = *itr;

  if( i < l ){

    return;

  }

  if( l < i ){

    m_l[i-1] = l;

  }

  if( i == r ){

    m_l.erase( itr );

  } else {

    l = i + 1;

  }
  
  return;

}

template <typename INT> inline int LineSubset<INT>::count( const INT& i ) const noexcept { return find( i ) ? 1 : 0; }

template <typename INT>
bool LineSubset<INT>::find( const INT& i ) const noexcept
{

  auto itr = m_l.lower_bound( i );

  if( itr == m_l.end() ){

    return false;

  }

  return itr->second <= i;

}

template <typename INT>
pair<INT,INT> LineSubset<INT>::ConnectedComponentOf( const INT& i ) const noexcept
{

  auto itr = m_l.lower_bound( i );

  if( itr == m_l.end() ){

    return {i+1,i-1};

  }

  return itr->second <= i ? pair<INT,INT>{itr->second,itr->first} : pair<INT,INT>{i+1,i-1};

}

template <typename INT> inline const map<INT,INT>& LineSubset<INT>::GetConnectedComponent() const noexcept { return m_l; }
