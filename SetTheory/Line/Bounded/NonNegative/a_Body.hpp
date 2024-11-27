// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename INT , template <typename...> typename DATA_STR> inline AbstractNonNegativeLineSubset<INT,DATA_STR>::AbstractNonNegativeLineSubset( const INT& ubound ) { assert( -1 <= ubound ); this->m_lbound = 0; this->m_ubound = ubound; this->m_ds.Initialise( int( this->m_ubound + 1 ) ); }

template <typename INT , template <typename...> typename DATA_STR> inline bool AbstractNonNegativeLineSubset<INT,DATA_STR>::InRange( const INT& i ) { return 0 <= i && i <= this->m_ubound; }
template <typename INT , template <typename...> typename DATA_STR> inline constexpr const INT& AbstractNonNegativeLineSubset<INT,DATA_STR>::Normalise( const INT& i ) { return i; }
template <typename INT , template <typename...> typename DATA_STR> inline constexpr const INT& AbstractNonNegativeLineSubset<INT,DATA_STR>::Denormalise( const INT& d ) { return d; }
