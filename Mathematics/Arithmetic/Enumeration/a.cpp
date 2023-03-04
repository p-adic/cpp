// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../../Utility/List/a_Body.hpp"

void BijSum12( const dim& d_1 , const dim& d_2, const INT_TYPE_FOR_DIM& n , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 )
{

  if( d_1 == infty() && d_2 == infty() ){
    
    n_1 = n % 2;
    n_2 = n / 2;
    return;
      
  }

  if( d_1 != infty() && d_2 == infty() ){

    const INT_TYPE_FOR_DIM N_1& = d_1.Get();

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

    const INT_TYPE_FOR_DIM N_2 = to_int( d_2 );

    if( N_2 > n ){

      n_1 = 1;
      n_2 = n;

    } else {

      n_1 = 0;
      n_2 = n - N_2;

    }
    
    return;

  }

  const INT_TYPE_FOR_DIM N_1 = to_int( d_1 );
  const INT_TYPE_FOR_DIM N = n_1 + to_int( d_2 );

  if( N == 0 ){

    ERR_INPUT( d_1 , d_2 , n );

  }

  const INT_TYPE_FOR_DIM m = n % N;
  
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
static void BijSum21_Body( const dim& d_1 , const dim& d_2 , const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 , INT_TYPE_FOR_DIM& m_1 , INT_TYPE_FOR_DIM& m_2 );

INT_TYPE_FOR_DIM BijSum21( const dim& d_1 , const dim& d_2 , const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 )
{

  INT_TYPE_FOR_DIM m_1;
  INT_TYPE_FOR_DIM m_2;

  try{
    
    BijSum21_Body( d_1 , d_2 , n_1 , n_2 , m_1 , m_2 );

  }
  catch( const IllegalInput & e ){

    CALL( e , d_1 , d_2 , n_1 , n_2 );

  }
  
  return m_1 + m_2 - 1;

}

static void BijSum21_Body( const dim& d_1 , const dim& d_2 , const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 , INT_TYPE_FOR_DIM& m_1 , INT_TYPE_FOR_DIM& m_2 )
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

void BijProd12( const dim& d_1 , const dim& d_2 , const INT_TYPE_FOR_DIM& n , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 )
{

  if( d_1 == infty() ){

    if( d_2 == infty() ){
      
      INT_TYPE_FOR_DIM i = 0;
    
      while( ( ( i + 1 ) * ( i + 2 ) ) / 2 <= n ){
	  
	i++;
	  
      }
    
      n_2 = n - ( i * ( i + 1 ) ) / 2;
      n_1 = i - n_2;
      return;
      
    } else {

      const INT_TYPE_FOR_DIM& N_2 = to_int( d_2 );
      
      if( N_2 == 0 ){

	ERR_INPUT( d_1 , d_2 , n );

      }
    
      n_1 = n / N_2;
      n_2 = n % N_2;
      return;

    }

  }

  const INT_TYPE_FOR_DIM& N_1 = to_int( d_1 );

  if( N_1 == 0 ){

    ERR_INPUT( d_1 , d_2 , n );

  }

  n_1 = n % N_1;

  if( d_2 == infty() ){
    
    n_2 = n / N_1;

  } else {

    const INT_TYPE_FOR_DIM& N_2 = to_int( d_2 );
    n_2 = ( n / N_1 ) % N_2;

  }
  
  return;

}

INT_TYPE_FOR_DIM BijProd21( const dim& d_1 , const dim& d_2 , const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 )
{

  if( d_1 == infty() && d_2 == infty() ){
      
    return ( ( n_1 + n_2 ) * ( n_1 + n_2 + 1 ) ) / 2 + n_2;

  }

  if( d_1 == infty() && d_2 != infty() ){

    const INT_TYPE_FOR_DIM N_2 = to_int( d_2 );
      
    if( N_2 == 0 ){

      ERR_INPUT( d_1 , d_2 , n_1 , n_2 );

    }
      
    return ( n_1 * N_2 ) + ( n_2 % N_2 ) ;
	
  }

  if( d_1 != infty() && d_2 == infty() ){

    const INT_TYPE_FOR_DIM N_1 = to_int( d_1 );
      
    if( N_1 == 0 ){

      ERR_INPUT( d_1 , d_2 , n_1 , n_2 );

    }

    return ( n_2 * N_1 ) + ( n_1 % N_1) ;

  }

  const INT_TYPE_FOR_DIM N_1 = to_int( d_1 );
  const INT_TYPE_FOR_DIM N_2 = to_int( d_2 );
      
  if( N_1 == 0 || N_2 == 0 ){

    ERR_INPUT( d_1 , d_2 , n_1 , n_2 );
      
  }

  return ( ( n_2 % N_2 ) * N_1 ) + ( n_1 % N_1 ) ;

}
