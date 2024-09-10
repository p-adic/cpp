// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Multisubset/IntervalInsert/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Multisubset/IntervalInsert/a_Body.hpp"

template <typename INT> inline IntervalInsertCompressedSortedMultiSet<INT>::IntervalInsertCompressedSortedMultiSet( const vector<INT>& query ) : AbstractCompressedSortedSet<INT,IntervalAddBIT>( query ) , AbstractIntervalInsertBoundedLineMultiSubset<INT,const INT&,const INT&>() {}
