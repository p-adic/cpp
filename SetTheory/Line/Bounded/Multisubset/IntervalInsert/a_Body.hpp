// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/IntervalInsert/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#ifdef DEBUG
  #include "../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a_Body.hpp"
#else
  #include "../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/a_Body.hpp"
#endif

template <typename INT , typename RET_NOR , typename RET_DEN> inline void AbstractIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::IntervalInsert( const INT& i_start , const INT& i_final , const INT& c ) { assert( this->InRange( i_start ) && this->InRange( i_final ) && c >= 0 ); this->m_ds.IntervalAdd( this->Normalise( i_start ) , this->Normalise( i_final ) , c ); }
template <typename INT , typename RET_NOR , typename RET_DEN> inline void AbstractIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::IntervalErase( const INT& i_start , const INT& i_final , const INT& c ) { assert( this->InRange( i_start ) && this->InRange( i_final ) && c >= 0 ); this->m_ds.IntervalAdd( this->Normalise( i_start ) , this->Normalise( i_final ) , -c ); }

template <typename INT> inline IntervalInsertBoundedLineMultiSubset<INT>::IntervalInsertBoundedLineMultiSubset( const INT& lbound , const INT& ubound ) : AbstractBoundedLineSubset<INT,IntervalAddBIT>( lbound , ubound ) , AbstractIntervalInsertBoundedLineMultiSubset<INT,INT,INT>() {}
