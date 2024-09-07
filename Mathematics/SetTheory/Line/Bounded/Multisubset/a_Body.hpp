// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../Debug/a_Body.hpp"
#else
  #include "../a_Body.hpp"
#endif

template <typename INT, template <typename...> typename DATA_STR> inline AbstractBoundedLineMultiSubset<INT,DATA_STR>::AbstractBoundedLineMultiSubset( const INT& lbound , const INT& ubound ) :
#ifdef DEBUG
  AbstractBoundedLineSubset<INT,DATA_STR>( lbound , ubound , false ) {}
#else
  AbstractBoundedLineSubset<INT,DATA_STR>( lbound , ubound ) {}
#endif

template <typename INT, template <typename...> typename DATA_STR> inline void AbstractBoundedLineMultiSubset<INT,DATA_STR>::insert( const INT& i , const int& c ) { assert( this->m_lbound <= i && i <= this->m_ubound && c >= 0 ); this->m_ds.Add( i - this->m_lbound , c ); }

template <typename INT, template <typename...> typename DATA_STR> inline void AbstractBoundedLineMultiSubset<INT,DATA_STR>::erase( const INT& i , const int& c ) { assert( this->m_lbound <= i && i <= this->m_ubound && c >= 0 ); this->m_ds.Add( i - this->m_lbound , -c ); }

template <typename INT, template <typename...> typename DATA_STR> inline void AbstractBoundedLineMultiSubset<INT,DATA_STR>::EraseAll( const INT& i ) { assert( this->m_lbound <= i && i <= this->m_ubound ); this->m_ds.Set( i - this->m_lbound , 0 ); }
