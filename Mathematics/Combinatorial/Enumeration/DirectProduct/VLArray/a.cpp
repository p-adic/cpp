// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Enumeration/VLArray/a.cpp

#include "../../../Header.hpp"
#include "a_Body.hpp"

VLArray<INT_TYPE_FOR_EUINT> BijProd1N( const VLArray<euint>& a_d , const INT_TYPE_FOR_EUINT& n )
{

  VLArray<INT_TYPE_FOR_EUINT> a_n;
  
  try{
    
    BijProd1N( a_d , n , a_n );

  }
  catch( const IllegalInput& e ){

    CALL( e , a_d , n );

  }

  return a_n;

}

void BijProd1N( const VLArray<euint>& a_d , const INT_TYPE_FOR_EUINT& n , VLArray<INT_TYPE_FOR_EUINT>& a_n )
{

  if( a_d.empty() ){

    a_n = VLArray<INT_TYPE_FOR_EUINT>();

    if( n != 0 ){

      ERR_INPUT( a_d , n );

    }
      
    return;

  }
  
  const euint& d = a_d.front();
  
  if( a_d.size() == 1 ){

    if( d.IsInfty() ){
	  
      a_n = VLArray<INT_TYPE_FOR_EUINT>( n );

    } else {

      const INT_TYPE_FOR_EUINT N = (INT_TYPE_FOR_EUINT)( d.Get() );

      if( N == 0 ){

	ERR_INPUT( a_d , n );
      
      } else {

	a_n = VLArray<INT_TYPE_FOR_EUINT>( n % N );

      }

    }

  } else {
    
    const VLArray<euint> b_d = a_d.GetFinalSegment( -1 );
    INT_TYPE_FOR_EUINT n_1;
    INT_TYPE_FOR_EUINT n_2;

    try{
      
      BijProd12( d , Prod( b_d ) , n , n_1 , n_2 );      

    }
    catch( const IllegalInput& e ){

      CALL( e , a_d , n );

    }

    try{
      
      BijProd1N( b_d , n_2 , a_n );

    }
    catch( const IllegalInput& e ){

      CALL( e , a_d , n );

    }

    a_n.push_front( n_1 );

  }
  
  return;

}

INT_TYPE_FOR_EUINT BijProdN1( const VLArray<euint>& a_d , const VLArray<INT_TYPE_FOR_EUINT>& a_n )
{

  if( a_n.empty() ){

    if( ! a_d.empty() ){

      ERR_INPUT( a_d , a_n );

    }
      
    return 0;

  }

  const euint& d = a_d.front();
  const INT_TYPE_FOR_EUINT& n = a_n.front();

  if( a_n.size() == 1 ) ){

  if( a_d.size() != 1 ) ){

      ERR_INPUT( a_d , a_n );

    }

    if( n >= d ){

      ERR_INPUT( a_d , a_n , d , n );
      
    }
      
    return n;

  }
  
  const VLArray<euint> b_d = a_d.GetFinalSegment( -1 );
  const VLArray<INT_TYPE_FOR_EUINT> b_n = a_n.GetFinalSegment( -1 );

  INT_TYPE_FOR_EUINT m;
  
  try{
    
    m = BijProd21( d , Prod( b_d ) , n , BijProdN1( b_d , b_n ) );

  }
  catch( const IllegalInput& e ){

    CALL( e , a_d , a_n );

  }

  return m;

}

void BijProd1Infty( const INT_TYPE_FOR_EUINT& n , VLArray<INT_TYPE_FOR_EUINT>& a )
{

  if( n == 0 ){

    a = VLArray<INT_TYPE_FOR_EUINT>();

  } else {
    
    INT_TYPE_FOR_EUINT n1;
    INT_TYPE_FOR_EUINT n2;

    try{
      
      BijProd12( n , n1 , n2 );
  
    }
    catch( const ErrorType& e ){

      CALL( e , n );

    }

    try{
      
      a = Frown( VLAray<INT_TYPE_FOR_EUINT>( n1 ) , BijProd1Infty( n2 ) );
  
    }
    catch( const ErrorType& e ){

      CALL( e , n );

    }

  }

  return;

}

VLArray<INT_TYPE_FOR_EUINT> BijProd1Infty( const INT_TYPE_FOR_EUINT& n )
{

  VLArray<INT_TYPE_FOR_EUINT> a;

  try{
    
    BijProd1Infty( n , a );

  }
  catch( const ErrorType& e ){

    CALL( e , n );

  }
  
  return a;

}
