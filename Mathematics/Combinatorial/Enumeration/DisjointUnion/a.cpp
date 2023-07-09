// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Enumeration/DisjointUnion/a.cpp

#pragma once
#include "../../../Header.hpp"
#include "a_Body.hpp"

void BijSum12( const euint& d_1 , const euint& d_2, const INT_TYPE_FOR_EUINT& n , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 )
{

  if( d_1 == infty() && d_2 == infty() ){
    
    n_1 = n % 2;
    n_2 = n / 2;
    return;
      
  }

  if( d_1 != infty() && d_2 == infty() ){

    const INT_TYPE_FOR_EUINT N_1& = d_1.Get();

    if( N_1 > n ){

      n_1 = 0;
      n_2 = n;

    } else {

      n_1 = 1;
      n_2 = n - N_1;

    }
    
    return;
      
  }

  if( d_1 == infty() && d_2 != infty() ){

    const INT_TYPE_FOR_EUINT N_2 = to_int( d_2 );

    if( N_2 > n ){

      n_1 = 1;
      n_2 = n;

    } else {

      n_1 = 0;
      n_2 = n - N_2;

    }
    
    return;

  }

  const INT_TYPE_FOR_EUINT N_1 = to_int( d_1 );
  const INT_TYPE_FOR_EUINT N = n_1 + to_int( d_2 );

  if( N == 0 ){

    ERR_INPUT( d_1 , d_2 , n );

  }

  const INT_TYPE_FOR_EUINT m = n % N;
  
  if( N_1 > m ){

    n_1 = 0;
    n_2 = m;

  } else {

    n_1 = 1;
    n_2 = m - N_1;

  }

  return;

}

// BijSum12によるBijSum21(n_1,n_2)以下までの像の各成分の最大値を記録する。
static void BijSum21_Body( const euint& d_1 , const euint& d_2 , const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 , INT_TYPE_FOR_EUINT& m_1 , INT_TYPE_FOR_EUINT& m_2 );

INT_TYPE_FOR_EUINT BijSum21( const euint& d_1 , const euint& d_2 , const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 )
{

  INT_TYPE_FOR_EUINT m_1;
  INT_TYPE_FOR_EUINT m_2;

  try{
    
    BijSum21_Body( d_1 , d_2 , n_1 , n_2 , m_1 , m_2 );

  }
  catch( const IllegalInput & e ){

    CALL( e , d_1 , d_2 , n_1 , n_2 );

  }
  
  return m_1 + m_2 - 1;

}

static void BijSum21_Body( const euint& d_1 , const euint& d_2 , const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 , INT_TYPE_FOR_EUINT& m_1 , INT_TYPE_FOR_EUINT& m_2 )
{

  if( n_1 >= 2 ){
    
    ERR_INPUT( d_1 , d_2 , n_1 , n_2 );

  }

  if( d_1 == infty() && d_2 == infty() ){

    m_1 = n_2 + 1;
    m_2 = n_2;

    if( n_1 == 1 ){
	  
      m_2++;

    }
      
    return;
      
  }

  if( d_1 != infty() ){

    if( n_1 == 0 ){

      m_1 = n_2 + 1;
      m_2 = 0;

      if( n_2 >= d_1 ){

	ERR_INPUT( d_1 , d_2 , n_1 , n_2 );

      }

    } else {

      m_1 = to_int( d_1 );
      m_2 = n_2 + 1;

      if( d_2 != infty() ){

	if( n_2 >= d_2 ){

	  ERR_INPUT( d_1 , d_2 , n_1 , n_2 );
	
	}

      }

    }

    return;

  }

  if( n_1 == 0 ){

    m_1 = n_2 + 1;
    m_2 = to_int( d_2 );

  } else {

    m_1 = 0;
    m_2 = n_2 + 1;

    if( n_2 >= d_2 ){

      ERR_INPUT( d_1 , d_2 , n_1 , n_2 );
      
    }

  }

  return;

}
