// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Multisubset/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Multisubset/Debug/a_Body.hpp"

template <typename INT> inline CompressedSortedMultiSet<INT>::CompressedSortedMultiSet(  const vector<INT>& query ) : VirtualBoundedLineMultiSubset<INT,const int&,const INT&>() , m_sorted_coord() , m_sorted_coord_inv()
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
  
  static int count = 0;
  this->m_name = "CompressedSortedMultiSet" + to_string( count++ );
  this->m_ds.Initialise( int( S.size() ) , false );

  if( this->m_output_mode ){
    
    DERR( this->m_name , "をデバッグモードで実行します。" );

    static bool init = true;

    if( init ){

      init = true;
      DERR( "各処理の計算量がO(size)増えることに注意してください。" );

    }
    
    this->Display();
    DERR( "" );

  }
  
}

template <typename INT> inline bool CompressedSortedMultiSet<INT>::InRange( const INT& i ) { return m_sorted_coord_inv.count( i ) > 0; }
template <typename INT> inline const int& CompressedSortedMultiSet<INT>::Normalise( const INT& i ) { static const int exceptional = -1; return i < this->m_lbound || m_sorted_coord_inv.empty() ? exceptional : ( --m_sorted_coord_inv.upper_bound( i ) )->second; }
template <typename INT> inline const INT& CompressedSortedMultiSet<INT>::Denormalise( const int& d ) { return m_sorted_coord[d]; }
