// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Debug/a.hpp

#pragma once

#include "../../Debug/a.hpp"
#include "../../../../../../Utility/Set/Map/a.hpp"

template <typename INT>
class CompressedLineSubset :
  public VirtualBoundedLineSubset<INT,const INT&,const INT&>
{

protected:
  vector<INT> m_sorted_coord;
  Map<INT,int> m_sorted_coord_inv;

public:
  inline CompressedLineSubset( const vector<INT>& query , const bool& output_mode = true );

private:
  inline bool InRange( const INT& i );
  inline constexpr const INT& Normalise( const INT& i );
  inline constexpr const INT& Denormalise( const INT& d );

};
