// c:/Users/user/Documents/Programming/Utility/String/RollingHash/Shift/BiModule/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../Mathematics/Algebra/Monoid/Group/Module/BiModule/a.hpp"

// verify:
// https://yukicoder.me/submissions/1021517

// ShiftableRollingHashのコードの生成するモノイドのグロタンディーク化で得られる
// 非可換Z[Z/26Z]加群に相当する型。
template <typename MODINT = Mod<999309403> , typename INT = int , typename CODE = tuple<MODINT,MODINT,INT>>
class ShiftableRollingHashBiModule :
  public PointedSet<CODE> ,
  virtual public VirtualGroup<CODE> ,
  virtual public VirtualBiModule<Mod<26>,int,CODE>
{

private:
  const ShiftableRollingHash<MODINT,INT,CODE>* m_p_srh;

public:
  inline ShiftableRollingHashBiModule( const ShiftableRollingHash<MODINT,INT,CODE>& srh );

  inline CODE Product( CODE code0 , const CODE& code1 );
  inline CODE Transfer( const CODE& code );
  inline CODE LAction( const Mod<26>& l , CODE code );
  inline CODE RAction( CODE code , const int& r );

};
