// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Debug/a_Body.hpp"
#include "../../../../../../Utility/Set/Map/a_Body.hpp"

template <typename INT> inline CompressedSortedSet<INT>::CompressedSortedSet( const vector<INT>& query , const bool& output_mode ) : VirtualBoundedLineSubset<INT,const INT&,const INT&>()
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

  this->m_output_mode = output_mode;

  if( m_sorted_coord.empty() ){

    this->m_lbound = 0;
    this->m_ubound = -1;

  } else {

    this->m_lbound = m_sorted_coord.front();
    this->m_ubound = m_sorted_coord.back();

  }
  
  this->m_name = "CompressedSortedSet";
  this->m_ds.Initialise( int( S.size() ) , false );
  
  if( this->m_output_mode ){
    
    DERR( this->m_name , "をデバッグモードで実行します。" );
    DERR( "各処理の計算量がO(size)増えることに注意してください。" );
    this->Display();
    DERR( "" );

  }
  
}

template <typename INT> inline bool CompressedSortedSet<INT>::InRange( const INT& i ) { return m_sorted_coord_inv.count( i ) > 0; }
template <typename INT> inline constexpr const INT& CompressedSortedSet<INT>::Normalise( const INT& i ) { return m_sorted_coord_inv[i]; }
template <typename INT> inline constexpr const INT& CompressedSortedSet<INT>::Denormalise( const INT& d ) { return m_sorted_coord[d]; }
