// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Debug/a.hpp

#pragma once

#include "../../Debug/a.hpp"
#include "../../../../../../Utility/Set/Map/a.hpp"

template <typename INT>
class CompressedSortedSet :
  public VirtualBoundedLineSubset<INT,const int&,const INT&>
{

protected:
  vector<INT> m_sorted_coord;
  Map<INT,int> m_sorted_coord_inv;

public:
  inline CompressedSortedSet( const vector<INT>& query , const bool& output_mode = true );

private:
  inline bool InRange( const INT& i );
  inline constexpr const int& Normalise( const INT& i );
  inline constexpr const INT& Denormalise( const int& d );

};
