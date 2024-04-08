// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Factorisation/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT1 , typename INT2 , typename INT3>
void SetPrimeFactorisation( INT1 n , vector<INT2>& P , vector<INT3>& exponent )
{

  INT2 p = 2;

  if( n % p == 0 ){

    P.push_back( p );
    exponent.push_back( 1 );
    INT3& exponent_back = exponent.back();
    n /= p;
    
    while( n % p == 0 ){

      exponent_back++;
      n /= p;
      
    }

  }

  p++;

  while( p * p <= n ){

    if( n % p == 0 ){

      P.push_back( p );
      exponent.push_back( 1 );
      INT3& exponent_back = exponent.back();
      n /= p;
    
      while( n % p == 0 ){

	exponent_back++;
	n /= p;
      
      }

    }

    p += 2;

  }

  if( n != 1 ){

    P.push_back( n );
    exponent.push_back( 1 );
    
  }
  
  return;
  
}

template <typename INT , INT val_limit , int length_max , typename INT1 , typename INT2 , typename INT3>
void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT1 n , vector<INT2>& P , vector<INT3>& exponent )
{

  int i = 0;
  const int& length = prime.length();

  while( i < length ){

    const INT2& p = prime[i];

    if( p * p > n ){

      break;
      
    }
    
    if( n % p == 0 ){

      P.push_back( p );
      exponent.push_back( 1 );
      INT3& exponent_back = exponent.back();
    
      while( ( n /= p ) % p == 0 ){

	exponent_back++;
      
      }

    }
    
    i++;

  }

  if( n != 1 ){

    P.push_back( n );
    exponent.push_back( 1 );
    
  }
  
  return;

}

template <typename INT1 , typename INT2 , typename INT3 , typename INT4>
void SetPrimeFactorisation( INT1 n , vector<INT2>& P , vector<INT3>& exponent , vector<INT4>& P_power )
{

  INT2 p = 2;

  if( n % p == 0 ){

    P.push_back( p );
    exponent.push_back( 1 );
    P_power.push_back( p );
    INT3& exponent_back = exponent.back();
    INT4& P_power_back = P_power.back();
    n /= p;
    
    while( n % p == 0 ){

      exponent_back++;
      P_power_back *= p;
      n /= p;
      
    }

  }

  p++;

  while( p * p <= n ){

    if( n % p == 0 ){

      P.push_back( p );
      exponent.push_back( 1 );
      P_power.push_back( p );
      INT3& exponent_back = exponent.back();
      INT4& P_power_back = P_power.back();
      n /= p;
    
      while( n % p == 0 ){

	exponent_back++;
	P_power_back *= p;
	n /= p;
      
      }

    }

    p += 2;

  }

  if( n != 1 ){

    P.push_back( n );
    exponent.push_back( 1 );
    
  }
  
  return;

}

template <typename INT , INT val_limit , int length_max , typename INT1 , typename INT2 , typename INT3 , typename INT4>
void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT1 n , vector<INT2>& P , vector<INT3>& exponent , vector<INT4>& P_power )
{

  int i = 0;
  const int& length = prime.length();

  while( i < length ){

    const INT2& p = prime[i];

    if( p * p > n ){

      break;
      
    }

    if( n % p == 0 ){

      P.push_back( p );
      exponent.push_back( 1 );
      P_power.push_back( p );
      INT3& exponent_back = exponent.back();
      INT4& P_power_back = P_power.back();
      n /= p;
    
      while( n % p == 0 ){

	exponent_back++;
	P_power_back *= p;
	n /= p;
      
      }

    }

    p += 2;

  }

  if( n != 1 ){

    P.push_back( n );
    exponent.push_back( 1 );
    P_power.push_back( n );
    
  }
  
  return;

}

template <typename INT1 , typename INT2 , typename INT3 , int N>
void SetPrimeFactorisationBounded( INT1 n , INT2 ( &P )[N] , INT3 ( &exponent )[N] )
{

  INT2 p = 2;
  int L = 0;

  if( n % p == 0 ){

    P[L] = p;
    INT3& exponent_back = exponent[L];
    exponent_back = 1;
    n /= p;
    L++;
    
    while( n % p == 0 ){

      exponent_back++;
      n /= p;
      
    }

  }

  p++;

  while( p * p <= n ){

    if( n % p == 0 ){

      P[L] = p;
      INT3& exponent_back = exponent[L];
      exponent_back = 1;
      n /= p;
      L++;
    
      while( n % p == 0 ){

	exponent_back++;
	n /= p;
      
      }

    }

    p += 2;
    
  }

  return;

}

template <typename INT1 , typename INT2 , typename INT3 , typename INT4 , int N>
void SetPrimeFactorisationBounded( INT1 n , INT2 ( &P )[N] , INT3 ( &exponent )[N] , INT4 ( &P_power )[N] )
{
  
  INT2 p = 2;
  int L = 0;

  if( n % p == 0 ){

    P[L] = p;
    INT3& exponent_back = exponent[L];
    INT4& P_power_back = P_power[L];
    exponent_back = 1;
    P_power_back = p;
    n /= p;
    L++;
    
    while( n % p == 0 ){

      exponent_back++;
      P_power_back *= p;
      n /= p;
      
    }

  }

  p++;

  while( p * p <= n ){

    if( n % p == 0 ){

      P[L] = p;
      INT3& exponent_back = exponent[L];
      INT4& P_power_back = P_power[L];
      exponent_back = 1;
      P_power_back = p;
      n /= p;
      L++;
    
      while( n % p == 0 ){

	exponent_back++;
	P_power_back *= p;
	n /= p;
      
      }

    }

    p += 2;
    
  }

  return;
  
}
