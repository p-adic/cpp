// c:/Users/user/Documents/Programming/Utility/String/RollingHash/Module/a.hpp

#pragma once
#include "../../../../Mathematics/Algebra/Monoid/Group/Module/a.hpp"

template <typename MODINT , typename INT = int , typename CODE = tuple<MODINT,MODINT,INT>>
class RollingHashModule :
  public PointedSet<CODE> ,
  virtual public VirtualGroup<CODE> ,
  virtual public VirtualRSet<int,CODE>
{

public:
  inline RollingHashModule();

  inline CODE Product( CODE code0 , const CODE& code1 );
  inline CODE Transfer( const CODE& code );
  inline CODE Action( const int& r , CODE code );

};
