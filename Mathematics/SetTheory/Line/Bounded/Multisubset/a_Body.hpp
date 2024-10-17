// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename INT , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void AbstractBoundedLineMultiSubset<INT,RET_NOR,RET_DEN,DATA_STR>::insert( const INT& i , const INT& c ) { assert( this->InRange( i ) && c >= 0 ); this->m_ds.Add( this->Normalise( i ) , c ); }

template <typename INT , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void AbstractBoundedLineMultiSubset<INT,RET_NOR,RET_DEN,DATA_STR>::erase( const INT& i , const INT& c ) { assert( c >= 0 ); if( this->InRange( i ) ){ this->m_ds.Add( this->Normalise( i ) , -c ); } }

template <typename INT , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void AbstractBoundedLineMultiSubset<INT,RET_NOR,RET_DEN,DATA_STR>::EraseAll( const INT& i ) { if( this->InRange( i ) ){ this->m_ds.Set( this->Normalise( i ) , 0 ); } }

template <typename INT> inline BoundedLineMultiSubset<INT>::BoundedLineMultiSubset( const INT& lbound , const INT& ubound ) : BoundedLineSubset<INT>( lbound , ubound ) {}
