// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/IntervalInsert/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Multisubset/IntervalInsert/a_Body.hpp"

template <typename INT> inline IntervalInsertNonNegativeLineMultiSubset<INT>::IntervalInsertNonNegativeLineMultiSubset( const INT& ubound ) : AbstractNonNegativeLineSubset<INT,IntervalAddBIT>( ubound ) , AbstractIntervalInsertBoundedLineMultiSubset<INT,const INT&,const INT&>() {}
