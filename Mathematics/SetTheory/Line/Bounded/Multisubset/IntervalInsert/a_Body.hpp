// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/IntervalInsert/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../../Debug/a_Body.hpp"
  #include "../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a_Body.hpp"
#else
  #include "../../a_Body.hpp"
  #include "../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/a_Body.hpp"
#endif

template <typename INT, template <typename...> typename DATA_STR> inline AbstractIntervalInsertBoundedLineMultiSubset<INT,DATA_STR>::AbstractIntervalInsertBoundedLineMultiSubset( const INT& lbound , const INT& ubound ) : 
#ifdef DEBUG
  AbstractBoundedLineSubset<INT,DATA_STR>( lbound , ubound , false ) {}
#else
  AbstractBoundedLineSubset<INT,DATA_STR>( lbound , ubound ) {}
#endif
  
template <typename INT, template <typename...> typename DATA_STR> inline void AbstractIntervalInsertBoundedLineMultiSubset<INT,DATA_STR>::insert( const INT& i , const int& c ) { assert( this->m_lbound <= i && i <= this->m_ubound ); this->m_ds.Add( i - this->m_lbound , c ); }

template <typename INT, template <typename...> typename DATA_STR> inline void AbstractIntervalInsertBoundedLineMultiSubset<INT,DATA_STR>::IntervalInsert( const INT& i_start , const INT& i_final , const int& c ) { assert( this->m_lbound <= i_start && i_final <= this->m_ubound ); this->m_ds.IntervalAdd( i_start - this->m_lbound , i_final - this->m_lbound , c ); }

template <typename INT, template <typename...> typename DATA_STR> inline void AbstractIntervalInsertBoundedLineMultiSubset<INT,DATA_STR>::erase( const INT& i , const int& c ) { assert( this->m_lbound <= i && i <= this->m_ubound ); this->m_ds.Add( i - this->m_lbound , -c ); }

template <typename INT, template <typename...> typename DATA_STR> inline void AbstractIntervalInsertBoundedLineMultiSubset<INT,DATA_STR>::EraseAll( const INT& i ) { assert( this->m_lbound <= i && i <= this->m_ubound ); this->m_ds.Set( i - this->m_lbound , 0 ); }

template <typename INT, template <typename...> typename DATA_STR> inline void AbstractIntervalInsertBoundedLineMultiSubset<INT,DATA_STR>::IntervalErase( const INT& i_start , const INT& i_final , const int& c ) { assert( this->m_lbound <= i_start && i_final <= this->m_ubound ); this->m_ds.IntervalAdd( i_start - this->m_lbound , i_final - this->m_lbound , -c ); }

