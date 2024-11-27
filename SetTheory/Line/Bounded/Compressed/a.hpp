// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/a.hpp

#pragma once
#include "../a.hpp"

#include "../../../../../Utility/Set/Map/a.hpp"

template <typename INT , template <typename...> typename DATA_STR>
class AbstractCompressedSortedSet :
  virtual public VirtualBoundedLineSubset<INT,const int&,const INT&,DATA_STR>
{

protected:
  vector<INT> m_sorted_coord;
  map<INT,int> m_sorted_coord_inv;

public:
  inline AbstractCompressedSortedSet( const vector<INT>& query );

protected:
  inline bool InRange( const INT& i );
  inline const int& Normalise( const INT& i );
  inline const INT& Denormalise( const int& d );

};

#include "a_Alias.hpp"
