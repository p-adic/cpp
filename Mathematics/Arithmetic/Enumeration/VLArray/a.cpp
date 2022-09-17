// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/VLArray/a.cpp

#pragma once
#include "../../../Header.hpp"
#include "a_Body.hpp"

#include "../../Dimension/VLArray/a_Body.hpp"

void BijSum1N( const VLArray<dim>& a_d , const INT_TYPE_FOR_DIM& n , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 )
{

  const dim d = Sum( a_d );
  INT_TYPE_FOR_DIM m = n;

  if( ! d.IsInfty() ){

    m = n % d.Get();
    
  }
  
  if( a_d.empty() ){

    ERR_IMPUT( a_d , n );
      
  }

  if( a_d.size() == 1 ){

    n_1 = 0;
    n_2 = m;
    return;

  }

  const VLArray<dim> b_d = a_d.GetFinalSegment( -1 );

  try{
    
    BijSum12( a_d.front() , Sum( b_d ) , m , n_1 , n_2 );

  }
  catch( const ErrorType& e ){

    CALL( e , a_d , n );

  }  

  if( n_1 == 0 ){

    return;

  } else {
    
    INT_TYPE_FOR_DIM n_3 = 0;

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

INT_TYPE_FOR_DIM BijSumN1( const VLArray<dim>& a_d , const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 )
{

  if( a_d.empty() ){

    ERR_IMPUT( a_d , n_1 , n_2 );
      
  }

  if( a_d.size() == 1 ){

    if( n_1 != 0 ){

      ERR_IMPUT( a_d , n_1 , n_2 );

    }

    return n_2;

  }

  const dim& d = a_d.front();
  const VLArray<dim> b_d = a_d.GetFinalSegment( -1 );

  if( n_1 == 0 ){

    try{
      
      return BijSum21( d , Sum( b_d ) , 0 , n_2 );

    }
    catch( const IllegalImput & e ){

      CALL( e , a_d , n_1 , n_2 );

    }

  }

  INT_TYPE_FOR_DIM n;

  try{
      
    n = BijSumN1( b_d , n_1 - 1 , n_2 ) ;

  }
  catch( const IllegalImput & e ){

    CALL( e , a_d , n_1 , n_2 );

  }
  
  try{
      
    return BijSum21( d, Sum( b_d ) , 1 , n );

  }
  catch( const IllegalImput & e ){

    CALL( e , a_d , n_1 , n_2 );

  }

  // É_É~Å[
  return BijSumN1( a_d , n_1 , n_2 );
    
}


VLArray<INT_TYPE_FOR_DIM> BijProd1N( const VLArray<dim>& a_d , const INT_TYPE_FOR_DIM& n )
{

  VLArray<INT_TYPE_FOR_DIM> a_n;
  
  try{
    
    BijProd1N( a_d , n , a_n );

  }
  catch( const IllegalImput& e ){

    CALL( e , a_d , n );

  }

  return a_n;

}

void BijProd1N( const VLArray<dim>& a_d , const INT_TYPE_FOR_DIM& n , VLArray<INT_TYPE_FOR_DIM>& a_n )
{

  if( a_d.empty() ){

    a_n = VLArray<INT_TYPE_FOR_DIM>();

    if( n != 0 ){

      ERR_IMPUT( a_d , n );

    }
      
    return;

  }
  
  const dim& d = a_d.front();
  
  if( a_d.size() == 1 ){

    if( d.IsInfty() ){
	  
      a_n = VLArray<INT_TYPE_FOR_DIM>( n );

    } else {

      const INT_TYPE_FOR_DIM N = (INT_TYPE_FOR_DIM)( d.Get() );

      if( N == 0 ){

	ERR_IMPUT( a_d , n );
      
      } else {

	a_n = VLArray<INT_TYPE_FOR_DIM>( n % N );

      }

    }

  } else {
    
    const VLArray<dim> b_d = a_d.GetFinalSegment( -1 );
    INT_TYPE_FOR_DIM n_1;
    INT_TYPE_FOR_DIM n_2;

    try{
      
      BijProd12( d , Prod( b_d ) , n , n_1 , n_2 );      

    }
    catch( const IllegalImput& e ){

      CALL( e , a_d , n );

    }

    try{
      
      BijProd1N( b_d , n_2 , a_n );

    }
    catch( const IllegalImput& e ){

      CALL( e , a_d , n );

    }

    a_n.push_front( n_1 );

  }
  
  return;

}

INT_TYPE_FOR_DIM BijProdN1( const VLArray<dim>& a_d , const VLArray<INT_TYPE_FOR_DIM>& a_n )
{

  if( a_n.empty() ){

    if( ! a_d.empty() ){

      ERR_IMPUT( a_d , a_n );

    }
      
    return 0;

  }

  const dim& d = a_d.front();
  const INT_TYPE_FOR_DIM& n = a_n.front();

  if( a_n.size() == 1 ) ){

  if( a_d.size() != 1 ) ){

      ERR_IMPUT( a_d , a_n );

    }

    if( n >= d ){

      ERR_IMPUT( a_d , a_n , d , n );
      
    }
      
    return n;

  }
  
  const VLArray<dim> b_d = a_d.GetFinalSegment( -1 );
  const VLArray<INT_TYPE_FOR_DIM> b_n = a_n.GetFinalSegment( -1 );

  INT_TYPE_FOR_DIM m;
  
  try{
    
    m = BijProd21( d , Prod( b_d ) , n , BijProdN1( b_d , b_n ) );

  }
  catch( const IllegalImput& e ){

    CALL( e , a_d , a_n );

  }

  return m;

}

void BijProd1Infty( const INT_TYPE_FOR_DIM& n , VLArray<INT_TYPE_FOR_DIM>& a )
{

  if( n == 0 ){

    a = VLArray<INT_TYPE_FOR_DIM>();

  } else {
    
    INT_TYPE_FOR_DIM n1;
    INT_TYPE_FOR_DIM n2;

    try{
      
      BijProd12( n , n1 , n2 );
  
    }
    catch( const ErrorType& e ){

      CALL( e , n );

    }

    try{
      
      a = Frown( VLAray<INT_TYPE_FOR_DIM>( n1 ) , BijProd1Infty( n2 ) );
  
    }
    catch( const ErrorType& e ){

      CALL( e , n );

    }

  }

  return;

}

VLArray<INT_TYPE_FOR_DIM> BijProd1Infty( const INT_TYPE_FOR_DIM& n )
{

  VLArray<INT_TYPE_FOR_DIM> a;

  try{
    
    BijProd1Infty( n , a );

  }
  catch( const ErrorType& e ){

    CALL( e , n );

  }
  
  return a;

}
