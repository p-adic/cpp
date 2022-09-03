// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

const uint& GetPrime( const uint& i ) noexcept
{

  static vector<uint> P{ 2 , 3 , 5 , 7 , 11 };
  const uint L = P.size();

  if( i < L ){

    return P[i];

  }

  uint p = P.back() + 2;

  bool prime = false;

  while( ! prime ){

    prime = true;
    
    for( uint j = 0 ; j < L && prime ; j++ ){

      uint& Pj = P[j];
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
  return GetPrime( i );

}

void SetPrimeFactorisation( const uint& n , vector<uint>& P , vector<uint>& exponent )
{

  uint n_copy = n;
  uint p = 2;

  if( n_copy % p == 0 ){

    P.push_back( p );
    exponent.push_back( 1 );
    uint& exponent_back = exponent.back();
    n_copy /= p;
    
    while( n_copy % p == 0 ){

      exponent_back++;
      n_copy /= p;
      
    }

  }

  p++;

  while( n_copy != 1 ){

    if( n_copy % p == 0 ){

      P.push_back( p );
      exponent.push_back( 1 );
      uint& exponent_back = exponent.back();
      n_copy /= p;
    
      while( n_copy % p == 0 ){

	exponent_back++;
	n_copy /= p;
      
      }

    }

    p += 2;

    if( p * p > n_copy ){

      p = n_copy;

    }

  }

  return;
  
}

static void CheckExpressible( const uint& power , bool& expressible , const uint& s , const uint& i , const uint& j , bool& solved , uint& s0 , uint& s2 , const uint& p1 ) noexcept;
static void CheckSum( uint& s_copy , uint& subset_copy , uint& k , bool& rejected ) noexcept;
static void SetExpressibility( bool& expressible , uint& s_copy , const uint& s , uint& subset_copy , const uint& subset , uint& k , const uint& i , const uint& j ) noexcept;
static void CoutSum( uint& s_copy , uint& subset_copy , uint& k , const uint& s ) noexcept;
static void ShiftInterval( bool& solved , uint& s0 , const uint& s ,  uint& s2 , const uint& p1 ) noexcept;
static void ComputeMaximum( uint& j , uint& power , const uint& s0 , uint& s1 , const uint& i ) noexcept;
static void UpdatePrimeTable( bool& solved , uint& j , uint& power , uint& s0 , const uint& p0 , uint& p1 , const uint& i , uint& s1 , uint& s2 ) noexcept;

// èoìTÅFTORLEIV KLOVE, SUMS OF DISTINCT PRIMES, Nordisk Matematisk Tidskrift, Vol. 21, No. 4 (1974), pp. 138-140.
uint GetKloveSequence( const uint& i ) noexcept
{

  uint j = 0;
  uint power = 2;

  uint p0 = GetPrime( i );
  uint p1 = GetPrime( i + j + 1 );

  uint s0 = p0;
  uint s1 = p0;
  uint s2 = s0 + p1;

  bool solved = false;
  
  while( ! solved ){

    while( s0 < s1 && ! solved ){

      solved = true;

      for( uint s = s0 ; s < s2 && solved ; s++ ){

	bool expressible = false;
	CheckExpressible( power , expressible , s , i , j , solved , s0 , s2 , p1 );

      }

    }

    if( solved ){

      ComputeMaximum( j , power , s0 , s1 , i );
      
    } else {
      
      UpdatePrimeTable( solved , j , power , s0 , p0 , p1 , i , s1 , s2 );
      
    }

  }

  return s1;

}

void CheckExpressible( const uint& power , bool& expressible , const uint& s , const uint& i , const uint& j , bool& solved , uint& s0 , uint& s2 , const uint& p1 ) noexcept
{

  for( uint subset = power - 1 ; subset > 0 && ! expressible ; subset-- ){

    uint s_copy = s;
    uint subset_copy = subset;
    uint k = i + j;
    bool rejected = false;
	
    while( subset_copy > 0 && ! rejected ){

      CheckSum( s_copy , subset_copy , k , rejected );

    }

    rejected = ( s_copy != 0 ) || rejected;

    if( ! rejected ){

      SetExpressibility( expressible , s_copy , s , subset_copy , subset , k , i , j );
      CoutSum( s_copy , subset_copy , k , s );
	  
    }

  }

  if( ! expressible ){

    ShiftInterval( solved , s0 , s , s2 , p1 );

  }

  return;

}

void CheckSum( uint& s_copy , uint& subset_copy , uint& k , bool& rejected ) noexcept
{

  if( subset_copy % 2 == 1 ){

    uint p = GetPrime( k );
	    
    if( s_copy < p ){

      rejected = true;

    }

    s_copy -= p;

  }
	  
  subset_copy /= 2;
  k--;

  return;
  
}

void SetExpressibility( bool& expressible , uint& s_copy , const uint& s , uint& subset_copy , const uint& subset , uint& k , const uint& i , const uint& j ) noexcept
{

  expressible = true;

  s_copy = s;
  subset_copy = subset;
  k = i + j;

  return;

}

void CoutSum( uint& s_copy , uint& subset_copy , uint& k , const uint& s ) noexcept
{
  
  string equality = "";
	  
  while( subset_copy > 0 ){

    if( subset_copy % 2 == 1 ){

      uint p = GetPrime( k );
      s_copy -= p;

      if( equality == "" ){

	equality = to_string( p );

      } else {

	equality = to_string( p ) + "+" + equality;

      }

    }
	    
    subset_copy /= 2;
    k--;

  }

  equality = to_string( s ) + " = " + equality;
  cout << equality << endl;
  return;
  
}

void ShiftInterval( bool& solved , uint& s0 , const uint& s ,  uint& s2 , const uint& p1 ) noexcept
{

  cout << s << " is not expressible." << endl;
  solved = false;
  s0 = s + 1;
  s2 = s0 + p1;
  return;

}

void ComputeMaximum( uint& j , uint& power , const uint& s0 , uint& s1 , const uint& i ) noexcept
{

  s1 = s0 - 1;
  cout << "An upperbound is " << s1 << "." << endl;

  j = 1;
  power = 4;

  while( s1 > GetPrime( i + j ) + 1 ){

    j++;
    power *= 2;

  }

  bool expressible = true;

  for( uint s = s1 ; s > 0 && expressible ; s-- ){

    expressible = false;
	
    for( uint subset = power - 1 ; subset > 0 && ! expressible ; subset-- ){

      uint s_copy = s;
      uint subset_copy = subset;
      uint k = i + j;
      bool rejected = false;
	
      while( subset_copy > 0 && ! rejected ){

	CheckSum( s_copy , subset_copy , k , rejected );

      }

      rejected = ( s_copy != 0 ) || rejected;

      if( ! rejected ){

	SetExpressibility( expressible , s_copy , s , subset_copy , subset , k , i , j );
	CoutSum( s_copy , subset_copy , k , s );
	  
      }

    }

    if( ! expressible ){

      s1 = s;
      cout << s1 << " is not expressible." << endl;

    }

  }

  return;
  
}


void UpdatePrimeTable( bool& solved , uint& j , uint& power , uint& s0 , const uint& p0 ,  uint& p1 , const uint& i , uint& s1 , uint& s2 ) noexcept
{
  
  cout << "Add " << p1 << " to the prime table." <<  endl;
  solved = false;

  j++;
  power *= 2;
  
  s0 = p0;
  s1 += p1;

  p1 = GetPrime( i + j + 1 );
  s2 = s0 + p1;
  return;

}
