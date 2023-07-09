// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Enumeration/DisjointUnion/VLArray/a.cpp

#pragma once
#include "../../../../Header.hpp"
#include "a_Body.hpp"

#include "../../../../Arithmetic/ExtendedNatural/VLArray/a_Body.hpp"

void BijSum1N( const VLArray<euint>& a_d , const INT_TYPE_FOR_EUINT& n , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 )
{

  const euint d = Sum( a_d );
  INT_TYPE_FOR_EUINT m = n;

  if( ! d.IsInfty() ){

    m = n % d.Get();
    
  }
  
  if( a_d.empty() ){

    ERR_INPUT( a_d , n );
      
  }

  if( a_d.size() == 1 ){

    n_1 = 0;
    n_2 = m;
    return;

  }

  const VLArray<euint> b_d = a_d.GetFinalSegment( -1 );

  try{
    
    BijSum12( a_d.front() , Sum( b_d ) , m , n_1 , n_2 );

  }
  catch( const ErrorType& e ){

    CALL( e , a_d , n );

  }  

  if( n_1 == 0 ){

    return;

  } else {
    
    INT_TYPE_FOR_EUINT n_3 = 0;

    try{
      
      BijSum1N( b_d , n_2 , n_1 , n_3 );

    }
    catch( const ErrorType& e ){

      CALL( e , a_d , n );

    }

    n_1++;
    n_2 = n_3;
    return;

  }

}

INT_TYPE_FOR_EUINT BijSumN1( const VLArray<euint>& a_d , const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 )
{

  if( a_d.empty() ){

    ERR_INPUT( a_d , n_1 , n_2 );
      
  }

  if( a_d.size() == 1 ){

    if( n_1 != 0 ){

      ERR_INPUT( a_d , n_1 , n_2 );

    }

    return n_2;

  }

  const euint& d = a_d.front();
  const VLArray<euint> b_d = a_d.GetFinalSegment( -1 );

  if( n_1 == 0 ){

    try{
      
      return BijSum21( d , Sum( b_d ) , 0 , n_2 );

    }
    catch( const IllegalInput & e ){

      CALL( e , a_d , n_1 , n_2 );

    }

  }

  INT_TYPE_FOR_EUINT n;

  try{
      
    n = BijSumN1( b_d , n_1 - 1 , n_2 ) ;

  }
  catch( const IllegalInput & e ){

    CALL( e , a_d , n_1 , n_2 );

  }
  
  try{
      
    return BijSum21( d, Sum( b_d ) , 1 , n );

  }
  catch( const IllegalInput & e ){

    CALL( e , a_d , n_1 , n_2 );

  }

  // É_É~Å[
  return BijSumN1( a_d , n_1 , n_2 );
    
}

