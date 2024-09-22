// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Multisubset/IntervalInsert/Debug/a_Body.hpp"

template <typename INT> inline IntervalInsertNonNegativeLineMultiSubset<INT>::IntervalInsertNonNegativeLineMultiSubset( const INT& ubound ) : VirtualIntervalInsertBoundedLineMultiSubset<INT,const INT&,const INT&>()
{

  assert( -1 <= ubound );
  this->m_lbound = 0;
  this->m_ubound = ubound;
  this->m_name = "IntervalInsertNonNegativeLineMultiSubset";
  this->m_ds.Initialise( this->m_ubound , false );
  DERR( this->m_name , "をデバッグモードで実行します。" );
  DERR( "各処理の計算量がO(size)増えることに注意してください。" );
  this->Display();
  DERR( "" );
  
}

template <typename INT> inline bool IntervalInsertNonNegativeLineMultiSubset<INT>::InRange( const INT& i ) { return 0 <= i && i <= this->m_ubound; }
template <typename INT> inline constexpr const INT& IntervalInsertNonNegativeLineMultiSubset<INT>::Normalise( const INT& i ) { return i; }
template <typename INT> inline constexpr const INT& IntervalInsertNonNegativeLineMultiSubset<INT>::Denormalise( const INT& d ) { return d; }
