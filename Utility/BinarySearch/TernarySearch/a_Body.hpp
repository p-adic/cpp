// c:/Users/user/Documents/Programming/Utility/BinarySearch/TernarySearch/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename FUNC>
auto TernarySearch( ll l , ll r , FUNC f , const bool& minimise ) -> pair<ll,decltype( f( r ) )>
{

  static_assert( is_invocable_v<FUNC,const ll&> );
  assert( l <= r );
  ll m = ( l + r ) >> 1;
  auto L = f( l ) , M = f( m ) , R = f( r );

  while( l + 1 < m || m < r - 1 ){

    const ll l_sub = ( l + m ) >> 1 , r_sub = ( m + r ) >> 1;
    auto L_sub = f( l_sub ) , R_sub = f( r_sub );

    if( ( L_sub < M ) == minimise ){

      r = m , m = l_sub;
      R = move( M ) , M = move( L_sub );

    } else if( ( M < R_sub ) == minimise ){

      l = l_sub , r = r_sub;
      L = move( L_sub ) , R = move( R_sub );

    } else {

      l = m , m = r_sub;
      L = move( M ) , M = move( R_sub );

    }

  }

  if( ( L < M ) == minimise ){
    
    return { l , L };

  }

  if( ( M < R ) == minimise ){

    return { m , M };

  }

  return { r , R };

}
