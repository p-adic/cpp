// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/DiscreteLog/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT1 , typename INT2 , typename INT3>
int DiscreteLog( INT1 x , INT2 base , const INT3& B )
{

  assert( B > 0 );
  ( x %= B ) < 0 ? x += B : x;

  if( x == 1 % B ){

    return 0;

  }
  
  ( base %= B ) < 0 ? base += B : base;

  int sqrtB = sqrt( B );

  while( ll( sqrtB ) * sqrtB < B ){

    sqrtB++;

  }

  assert( sqrtB < 1 << 15 );
  vector<int> base_power( sqrtB + 1 , 1 );
  unordered_set<int> base_power_x_inv{};
  base_power_x_inv.insert( x );

  for( int i = 1 ; i <= sqrtB ; i++ ){

    if( x == ( base_power[i] = ll( base_power[i-1] ) * base % B ) ){

      return i;

    }

    base_power_x_inv.insert( ll( base_power[i] ) * x % B );

  }

  int base_power_power = 1;
  int temp;

  for( int j = 1 ; j < sqrtB ; j++ ){

    if( base_power_x_inv.count( temp = ll( base_power_power ) * base_power[sqrtB] % B ) == 1 ){

      for( int i = 1 ; i <= sqrtB ; i++ ){

	if( ll( base_power_power ) * base_power[i] % B == x ){

	  return sqrtB * j + i;

	}

      }

    }

    base_power_power = temp;
  
  }

  return -1;

}
