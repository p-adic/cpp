// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Multisubset/IntervalInsert/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Multisubset/IntervalInsert/Debug/a_Body.hpp"

template <typename INT> inline IntervalInsertCompressedSortedMultiSet<INT>::IntervalInsertCompressedSortedMultiSet( const vector<INT>& query ) : VirtualIntervalInsertBoundedLineMultiSubset<INT,const INT&,const INT&>()
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
  
  this->m_name = "IntervalInsertCompressedSortedMultiSet";
  this->m_ds.Initialise( this->m_ubound , false );
  DERR( this->m_name , "をデバッグモードで実行します。" );
  DERR( "各処理の計算量がO(size)増えることに注意してください。" );
  this->Display();
  DERR( "" );
  
}

template <typename INT> inline bool IntervalInsertCompressedSortedMultiSet<INT>::InRange( const INT& i ) { return m_sorted_coord_inv.count( i ) > 0; }
template <typename INT> inline const INT& IntervalInsertCompressedSortedMultiSet<INT>::Normalise( const INT& i ) { return m_sorted_coord_inv[i]; }
template <typename INT> inline const INT& IntervalInsertCompressedSortedMultiSet<INT>::Denormalise( const INT& d ) { return m_sorted_coord[d]; }
