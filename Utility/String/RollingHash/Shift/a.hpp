// c:/Users/user/Documents/Programming/Utility/String/RollingHash/Shift/a.hpp

#pragma once
#include "../a.hpp"

#ifdef DEBUG
  #include "../../../../Mathematics/Arithmetic/Mod/ConstexprModulo/Debug/a.hpp"
#else
  #include "../../../../Mathematics/Arithmetic/Mod/ConstexprModulo/a.hpp"
#endif

// ëfêîÇÃåÛï‚
// 999309403
// 999300121
// 999300017
template <typename MODINT = Mod<999309403> , typename INT = int , typename CODE = tuple<MODINT,MODINT,INT>>
class ShiftableRollingHash :
  public RollingHash<MODINT,INT,CODE>
{

private:
  MODINT m_power[26];

public:
  inline ShiftableRollingHash();

  inline CODE Shift( const Mod<26>& shift , CODE c ) const;

private:
  MODINT Twist( const ll& c );
  static MODINT GetPrimitiveRoot();
  
};

