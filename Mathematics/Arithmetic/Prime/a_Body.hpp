// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constexpr/a_Body.hpp"

template <typename INT>
const INT& GetPrime( const INT& i ) noexcept
{

  static vector<INT> P{ 2 , 3 , 5 , 7 , 11 };

  INT L = P.size();

  while( i >= L ){

    INT p = P.back() + 2;

    bool prime = false;

    while( ! prime ){

      prime = true;
    
      for( INT j = 0 ; j < L && prime ; j++ ){

	INT& Pj = P[j];
	prime = ( p % Pj != 0 );

	if( Pj * Pj >= p ){

	  j = L;
	
	}

      }

      if( ! prime ){

	p += 2;

      }

    }

    P.push_back( p );
    L++;

  }

  return P[i];

}

template <typename INT , INT N>
const INT& GetPrimeBounded( const INT& i )
{

  static INT P[N] = { 2 , 3 , 5 , 7 , 11 };

  INT L = 5;

  while( i >= L ){

    INT p = P[L - 1] + 2;

    bool prime = false;

    while( ! prime ){

      prime = true;
    
      for( INT j = 0 ; j < L && prime ; j++ ){

	INT& Pj = P[j];
	prime = ( p % Pj != 0 );

	if( Pj * Pj >= p ){

	  j = L;
	
	}

      }

      if( ! prime ){

	p += 2;

      }

    }

    P[L++] = p;

  }

  return P[i];

}

template <typename INT1 , typename INT2 , typename INT3>
void SetPrimeFactorisation( const INT1& n , vector<INT2>& P , vector<INT3>& exponent )
{

  INT1 n_copy = n;
  INT2 p = 2;

  if( n_copy % p == 0 ){

    P.push_back( p );
    exponent.push_back( 1 );
    INT3& exponent_back = exponent.back();
    n_copy /= p;
    
    while( n_copy % p == 0 ){

      exponent_back++;
      n_copy /= p;
      
    }

  }

  p++;

  while( p * p <= n_copy ){

    if( n_copy % p == 0 ){

      P.push_back( p );
      exponent.push_back( 1 );
      INT3& exponent_back = exponent.back();
      n_copy /= p;
    
      while( n_copy % p == 0 ){

	exponent_back++;
	n_copy /= p;
      
      }

    }

    p += 2;

  }

  if( n_copy != 1 ){

    P.push_back( n_copy );
    exponent.push_back( 1 );
    
  }
  
  return;
  
}

template <typename INT , INT val_limit , int length_max , typename INT1 , typename INT2 , typename INT3>
void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT1& n , vector<INT2>& P , vector<INT3>& exponent )
{

  INT1 n_copy = n;
  int i = 0;
  const int& length = prime.length();

  while( i < length ){

    const INT2& p = prime[i];

    if( p * p > n_copy ){

      break;
      
    }
    
    if( n_copy % p == 0 ){

      P.push_back( p );
      exponent.push_back( 1 );
      INT3& exponent_back = exponent.back();
    
      while( ( n_copy /= p ) % p == 0 ){

	exponent_back++;
      
      }

    }
    
    i++;

  }

  if( n_copy != 1 ){

    P.push_back( n_copy );
    exponent.push_back( 1 );
    
  }
  
  return;

}

template <typename INT1 , typename INT2 , typename INT3 , typename INT4>
void SetPrimeFactorisation( const INT1& n , vector<INT2>& P , vector<INT3>& exponent , vector<INT4>& P_power )
{

  INT1 n_copy = n;
  INT2 p = 2;

  if( n_copy % p == 0 ){

    P.push_back( p );
    exponent.push_back( 1 );
    P_power.push_back( p );
    INT3& exponent_back = exponent.back();
    INT4& P_power_back = P_power.back();
    n_copy /= p;
    
    while( n_copy % p == 0 ){

      exponent_back++;
      P_power_back *= p;
      n_copy /= p;
      
    }

  }

  p++;

  while( p * p <= n_copy ){

    if( n_copy % p == 0 ){

      P.push_back( p );
      exponent.push_back( 1 );
      P_power.push_back( p );
      INT3& exponent_back = exponent.back();
      INT4& P_power_back = P_power.back();
      n_copy /= p;
    
      while( n_copy % p == 0 ){

	exponent_back++;
	P_power_back *= p;
	n_copy /= p;
      
      }

    }

    p += 2;

  }

  if( n_copy != 1 ){

    P.push_back( n_copy );
    exponent.push_back( 1 );
    
  }
  
  return;

}

template <typename INT , INT val_limit , int length_max , typename INT1 , typename INT2 , typename INT3 , typename INT4>
void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT1& n , vector<INT2>& P , vector<INT3>& exponent , vector<INT4>& P_power )
{

  INT1 n_copy = n;
  int i = 0;
  const int& length = prime.length();

  while( i < length ){

    const INT2& p = prime[i];

    if( p * p > n_copy ){

      break;
      
    }

    if( n_copy % p == 0 ){

      P.push_back( p );
      exponent.push_back( 1 );
      P_power.push_back( p );
      INT3& exponent_back = exponent.back();
      INT4& P_power_back = P_power.back();
      n_copy /= p;
    
      while( n_copy % p == 0 ){

	exponent_back++;
	P_power_back *= p;
	n_copy /= p;
      
      }

    }

    p += 2;

  }

  if( n_copy != 1 ){

    P.push_back( n_copy );
    exponent.push_back( 1 );
    P_power.push_back( n_copy );
    
  }
  
  return;

}

template <typename INT1 , typename INT2 , typename INT3 , int N>
void SetPrimeFactorisationBounded( const INT1& n , INT2 ( &P )[N] , INT3 ( &exponent )[N] )
{

  INT1 n_copy = n;
  INT2 p = 2;
  int L = 0;

  if( n_copy % p == 0 ){

    P[L] = p;
    INT3& exponent_back = exponent[L];
    exponent_back = 1;
    n_copy /= p;
    L++;
    
    while( n_copy % p == 0 ){

      exponent_back++;
      n_copy /= p;
      
    }

  }

  p++;

  while( p * p <= n_copy ){

    if( n_copy % p == 0 ){

      P[L] = p;
      INT3& exponent_back = exponent[L];
      exponent_back = 1;
      n_copy /= p;
      L++;
    
      while( n_copy % p == 0 ){

	exponent_back++;
	n_copy /= p;
      
      }

    }

    p += 2;
    
  }

  return;

}

template <typename INT1 , typename INT2 , typename INT3 , typename INT4 , int N>
void SetPrimeFactorisationBounded( const INT1& n , INT2 ( &P )[N] , INT3 ( &exponent )[N] , INT4 ( &P_power )[N] )
{
  
  INT1 n_copy = n;
  INT2 p = 2;
  int L = 0;

  if( n_copy % p == 0 ){

    P[L] = p;
    INT3& exponent_back = exponent[L];
    INT4& P_power_back = P_power[L];
    exponent_back = 1;
    P_power_back = p;
    n_copy /= p;
    L++;
    
    while( n_copy % p == 0 ){

      exponent_back++;
      P_power_back *= p;
      n_copy /= p;
      
    }

  }

  p++;

  while( p * p <= n_copy ){

    if( n_copy % p == 0 ){

      P[L] = p;
      INT3& exponent_back = exponent[L];
      INT4& P_power_back = P_power[L];
      exponent_back = 1;
      P_power_back = p;
      n_copy /= p;
      L++;
    
      while( n_copy % p == 0 ){

	exponent_back++;
	P_power_back *= p;
	n_copy /= p;
      
      }

    }

    p += 2;
    
  }

  return;
  
}
