// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Residue/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
INT Residue( const INT& M , const INT& n ) noexcept
{

  if( M == 0 ){

    return 0;

  }

  const INT M_abs = ( M > 0 ? M : -M );

  if( n < 0 ){

    const INT n_abs = -n;
    const INT res = n_abs % M_abs;
    return res == 0 ? res : M_abs - res;

  }

  return n % M_abs;

}
