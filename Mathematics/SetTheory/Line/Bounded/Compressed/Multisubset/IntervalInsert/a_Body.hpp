// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Multisubset/IntervalInsert/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Multisubset/IntervalInsert/a_Body.hpp"

template <typename INT> inline IntervalInsertCompressedLineMultiSubset<INT>::IntervalInsertCompressedLineMultiSubset( const vector<INT>& query ) : AbstractCompressedLineSubset<INT,IntervalAddBIT>( query ) , AbstractIntervalInsertBoundedLineMultiSubset<INT,const INT&,const INT&>() {}
