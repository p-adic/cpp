// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Factorisation/a_Body.hpp

#pragma once
#include "a.hpp"


template <typename INT> pair<vector<INT>,vector<int>>
PrimeFactorisation( INT n )
{

  vector<INT> P{};
  vector<int> E{};
  INT p = 2;

  while( true ){

    if( n % p == 0 ){
      
      int e = 1;
    
      while( ( n /= p ) % p == 0 ){

	e++;
      
      }

      P.push_back( p );
      E.push_back( e );
      
    } else if( n / p < p ){

      break;

    }

    p += 1 + ( p > 2 );

  }

  if( n != 1 ){

    P.push_back( n );
    E.push_back( 1 );
    
  }
  
  return { move( P ) , move( E ) };
  
}

template <typename PE , typename INT>
auto PrimeFactorisation( const PE& pe , INT n ) -> enable_if_t<IsPE<PE>,pair<vector<int>,vector<int>>>
{

  vector<int> P{};
  vector<int> E{};
  const int& length = pe.length();

  for( int i = 0 ; i < length ; i++ ){

    auto& p = pe[i];
    
    if( n % p == 0 ){

      int e = 1;
    
      while( ( n /= p ) % p == 0 ){

	e++;
      
      }

      P.push_back( p );
      E.push_back( e );

    } else if( n / p < p ){

      break;

    }

  }

  if( n != 1 ){

    P.push_back( n );
    E.push_back( 1 );
    
  }
  
  return { move( P ) , move( E ) };

}

template <typename LD , typename INT>
auto PrimeFactorisation( const LD& ld , INT n ) -> enable_if_t<!IsPE<LD>,pair<vector<int>,vector<int>>>
{

  vector<int> P{};
  vector<int> E{};

  if( n > 1 ){

    P.push_back( ld[n] );
    E.push_back( 1 );
    n /= ld[n];

  }

  while( n > 1 ){

    if( P.back() != ld[n] ){

      P.push_back( ld[n] );
      E.push_back( 1 );

    } else {

      E.back()++;

    }
    
    n /= ld[n];

  }

  return { move( P ) , move( E ) };

}

template <typename INT>
tuple<vector<INT>,vector<int>,vector<INT>> PrimePowerFactorisation( INT n )
{

  vector<INT> P{};
  vector<int> E{};
  vector<INT> Q{};
  INT p = 2;

  while( true ){
    
    if( n % p == 0 ){

      int e = 1;
      INT q = p;
    
      while( ( n /= p ) % p == 0 ){

	e++;
	q *= p;
      
      }

      P.push_back( p );
      E.push_back( e );
      Q.push_back( q );

    } else if( n / p < p ){

      break;

    }

  }

  if( n != 1 ){

    P.push_back( n );
    E.push_back( 1 );
    Q.push_back( n );
    
  }
  
  return { move( P ) , move( E ) , move( Q ) };

}

template <typename PE , typename INT>
auto PrimePowerFactorisation( const PE& pe , INT n ) -> enable_if_t<IsPE<PE>,tuple<vector<int>,vector<int>,vector<INT>>>
{

  vector<int> P{};
  vector<int> E{};
  vector<INT> Q{};
  const int& length = pe.length();

  for( int i = 0 ; i < length ; i++ ){

    auto& p = pe[i];
    
    if( n % p == 0 ){

      int e = 1;
      INT q = p;
    
      while( ( n /= p ) % p == 0 ){

	e++;
	q *= p;
      
      }

      P.push_back( p );
      E.push_back( e );
      Q.push_back( q );

    } else if( n / p < p ){

      break;

    }

  }

  if( n != 1 ){

    P.push_back( n );
    E.push_back( 1 );
    Q.push_back( n );
    
  }
  
  return { move( P ) , move( E ) , move( Q ) };
  
}

template <typename LD , typename INT>
auto PrimePowerFactorisation( const LD& ld , INT n ) -> enable_if_t<!IsPE<LD>,tuple<vector<int>,vector<int>,vector<INT>>>
{

  vector<int> P{};
  vector<int> E{};
  vector<int> Q{};

  if( n > 1 ){

    P.push_back( ld[n] );
    E.push_back( 1 );
    Q.push_back( ld[n] );
    n /= ld[n];

  }

  while( n > 1 ){

    if( P.back() != ld[n] ){

      P.push_back( ld[n] );
      E.push_back( 1 );
      Q.push_back( ld[n] );

    } else {

      Q.back() *= ld[n];
      E.back()++;

    }
    
    n /= ld[n];

  }

  return { move( P ) , move( E ) , move( Q ) };

}

// 上では不使用だがどうせincludeする。
#include "../Enumeration/a_Body.hpp"
#include "../Enumeration/Heap/a_Body.hpp"
