// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/ValueMaximisation/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1015057 (CompressedGridValueMaximisation)

template <typename INT , typename U , typename MONOID , template <typename...> typename DATA_STR> U AbstractGridValueMaximisation( MONOID M , const INT& W , const vector<tuple<INT,INT,U>>& v , const bool& skippable = false );
template <typename INT , typename U> inline U GridValueMaximisation( const INT& W , const vector<tuple<INT,INT,U>>& v , const bool& skippable = false );
template <typename INT , typename U> inline U CompressedGridValueMaximisation( const vector<tuple<INT,INT,U>>& v , const bool& skippable = false );

