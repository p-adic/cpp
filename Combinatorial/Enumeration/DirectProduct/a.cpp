// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Enumeration/DirectProduct/a.cpp

#pragma once
#include "../../../Header.hpp"
#include "a_Body.hpp"

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
