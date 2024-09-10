// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "../../../../../Utility/Set/Map/a_Body.hpp"

template <typename INT , template <typename...> typename DATA_STR> inline AbstractCompressedSortedSet<INT,DATA_STR>::AbstractCompressedSortedSet( const vector<INT>& query ) : m_sorted_coord() , m_sorted_coord_inv()
{

  set<INT> S{};
  
  for( auto& i : query ){

    S.insert( i );

  }

  m_sorted_coord.reserve( S.size() );

  for( auto& i : S ){

    m_sorted_coord_inv[i] = m_sorted_coord.size();
    m_sorted_coord.push_back( i );

  }

  if( m_sorted_coord.empty() ){

    this->m_lbound = 0;
    this->m_ubound = -1;

  } else {

    this->m_lbound = m_sorted_coord.front();
    this->m_ubound = m_sorted_coord.back();

  }

  this->m_ds.Initialise( int( S.size() ) );

}

template <typename INT , template <typename...> typename DATA_STR> inline bool AbstractCompressedSortedSet<INT,DATA_STR>::InRange( const INT& i ) { return m_sorted_coord_inv.count( i ) > 0; }
template <typename INT , template <typename...> typename DATA_STR> inline const INT& AbstractCompressedSortedSet<INT,DATA_STR>::Normalise( const INT& i ) { return m_sorted_coord_inv[i]; }
template <typename INT , template <typename...> typename DATA_STR> inline const INT& AbstractCompressedSortedSet<INT,DATA_STR>::Denormalise( const INT& d ) { return m_sorted_coord[d]; }

