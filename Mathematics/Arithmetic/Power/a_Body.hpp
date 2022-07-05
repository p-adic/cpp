// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/a_Body.hpp

#pragma once
#include "a.hpp"


template <typename T , typename UINT>
inline T Power( const T& t , const UINT& num , const T& init , const bool& init_is_unit , const bool& for_right_multiplication , const string& method ) { return method == "binary" ? PowerBinaryMethod<T,UINT>( t , num , init , init_is_unit , for_right_multiplication ) : PowerNormalMethod<T,UINT>( t , num , init , for_right_multiplication ); }

template <typename T , typename UINT> inline T PowerNormalMethod( const T& t , const UINT& num , const T& init , const bool& for_right_multiplication ) { return num == 0 ? init : ( for_right_multiplication ? PowerNormalMethod<T,UINT>( t , num - 1 , init ) * t : t * PowerNormalMethod<T,UINT>( t , num - 1 , init ) ); }

template <typename T , typename UINT>
T PowerBinaryMethod( const T& t , const UINT& num , const T& init , const bool& init_is_unit , const bool& for_right_multiplication )
{

  if( num == 0 ){
      
    return init;

  }

  // 2ã°‚ÌŒvŽZŒø—¦‰»‚Ì‚½‚ß‚É‘O‰ñ‚ÌŒvŽZŒ‹‰Ê‚ð‹L˜^
  static T t_prev{};
  static UINT d = 0;
  static UINT two_power = 1;

  if( t_prev != t ){

    t_prev = t;
    d = 0;
    two_power = 1;
    
  }

  while( num % ( two_power + two_power ) == 0 ){

    d++;
    two_power = two_power + two_power;

  }

  const UINT num_reduced = num - two_power;
  T power1 = Power2Power<T,UINT>( t , d );

  if( num_reduced == 0 && init_is_unit ){

    return power1;

  }
  
  T power2 = PowerBinaryMethod<T,UINT>( t , num_reduced , init , init_is_unit , for_right_multiplication );
  return for_right_multiplication ? power2 * power1 : power1 * power2;

}

// Power‚Ì2ã°‚Ö‚Ì•”•ª“ÁŽê‰»
template <typename T , typename UINT>
T Power2Power( const T& t , const UINT& d )
{

  if( d == 0 ){

    return t;

  }

  // Power‚ÌŒvŽZŒø—¦‰»‚Ì‚½‚ß‚É‘O‰ñ‚ÌŒvŽZŒ‹‰Ê‚ð‹L˜^
  static T t_prev{};
  static UINT d_prev = 0;
  static T power_prev{};

  if( t_prev != t ){

    t_prev = t;
    d_prev = 0;
    power_prev = t;
    
  }

  while( d != d_prev ){

    d_prev++;
    power_prev = power_prev * power_prev;

  }
  
  return power_prev;

}
