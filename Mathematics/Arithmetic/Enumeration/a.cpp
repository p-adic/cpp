// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../../Utility/List/a_Body.hpp"

// BijSum12によるBijSum21(n_1,n_2)以下までの像の各成分の最大値を記録する。
static void BijSum21_Body( const dim& d_1 , const dim& d_2 , const uint& n_1 , const uint& n_2 , uint& m_1 , uint& m_2 )
{

  if( n_1 >= 2 ){
    
    ERR_IMPUT( d_1 , d_2 , n_1 , n_2 );

  }

  if( d_1 == *infty() && d_2 == *infty() ){

    m_1 = n_2 + 1;
    m_2 = n_2;

    if( n_1 == 1 ){
	  
      m_2++;

    }
      
    return;
      
  }

  if( d_1 != *infty() ){

    if( n_1 == 0 ){

      m_1 = n_2 + 1;
      m_2 = 0;

      if( n_2 >= d_1 ){

	ERR_IMPUT( d_1 , d_2 , n_1 , n_2 );

      }

    } else {

      m_1 = to_int( d_1 );
      m_2 = n_2 + 1;

      if( d_2 != *infty() ){

	if( n_2 >= d_2 ){

	  ERR_IMPUT( d_1 , d_2 , n_1 , n_2 );
	
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

      ERR_IMPUT( d_1 , d_2 , n_1 , n_2 );
      
    }

  }

  return;

}

uint BijSum21( const dim& d_1 , const dim& d_2 , const uint& n_1 , const uint& n_2 )
{

  uint m_1;
  uint m_2;

  try{
    
    BijSum21_Body( d_1 , d_2 , n_1 , n_2 , m_1 , m_2 );

  }
  catch( const IllegalImput & e ){

    CALL( e , d_1 , d_2 , n_1 , n_2 );

  }
  
  return m_1 + m_2 - 1;

}

void BijSum12( const dim& d_1 , const dim& d_2, const uint& n , uint& n_1 , uint& n_2 )
{

  if( d_1 == *infty() && d_2 == *infty() ){
    
    n_1 = n % 2;
    n_2 = n / 2;
    return;
      
  }

  if( d_1 != *infty() && d_2 == *infty() ){

    const uint N_1 = to_int( d_1 );

    if( N_1 > n ){

      n_1 = 0;
      n_2 = n;

    } else {

      n_1 = 1;
      n_2 = n - N_1;

    }
    
    return;
      
  }

  if( d_1 == *infty() && d_2 != *infty() ){

    const uint N_2 = to_int( d_2 );

    if( N_2 > n ){

      n_1 = 1;
      n_2 = n;

    } else {

      n_1 = 0;
      n_2 = n - N_2;

    }
    
    return;

  }

  const uint N_1 = to_int( d_1 );
  const uint N = n_1 + to_int( d_2 );

  if( N == 0 ){

    ERR_IMPUT( d_1 , d_2 , n );

  }

  const uint m = n % N;
  
  if( N_1 > m ){

    n_1 = 0;
    n_2 = m;

  } else {

    n_1 = 1;
    n_2 = m - N_1;

  }

  return;

}

uint BijSumN1( const list<dim>& a_d , const uint& n_1 , const uint& n_2 )
{

  if( a_d.empty() ){

    ERR_IMPUT( a_d , n_1 , n_2 );
      
  }

  if( Length( a_d , 1 ) ){

    if( n_1 != 0 ){

      ERR_IMPUT( a_d , n_1 , n_2 );

    }

    return n_2;

  }

  const dim& d = a_d.front();  
  const list<dim> b_d = Back( -1 , a_d );

  if( n_1 == 0 ){

    try{
      
      return BijSum21( d , Sum( b_d ) , 0 , n_2 );

    }
    catch( const IllegalImput & e ){

      CALL( e , a_d , n_1 , n_2 );

    }

  }

  uint n;

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

  // ダミー
  return BijSumN1( a_d , n_1 , n_2 );
    
}

void BijSum1N( const list<dim>& a_d , const uint& n , uint& n_1 , uint& n_2 )
{

  const dim d = Sum( a_d );
  uint m = n;

  if( d != *infty() ){

    m = n % to_int( d );
    
  }
  
  if( a_d.empty() ){

    ERR_IMPUT( a_d , n );
      
  }

  if( Length( a_d , 1 ) ){

    n_1 = 0;
    n_2 = m;
    return;

  }

  const list<dim> b_d = Back( -1 , a_d );

  try{
    
    BijSum12( a_d.front() , Sum( b_d ) , m , n_1 , n_2 );

  }
  catch( const ErrorType& e ){

    CALL( e , a_d , n );

  }  

  if( n_1 == 0 ){

    return;

  } else {
    
    uint n_3 = 0;

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

uint BijProd21( const dim& d_1 , const dim& d_2 , const uint& n_1 , const uint& n_2 )
{

  if( d_1 == *infty() && d_2 == *infty() ){
      
    return ( ( n_1 + n_2 ) * ( n_1 + n_2 + 1 ) ) / 2 + n_2;

  }

  if( d_1 == *infty() && d_2 != *infty() ){

    const uint N_2 = to_int( d_2 );
      
    if( N_2 == 0 ){

      ERR_IMPUT( d_1 , d_2 , n_1 , n_2 );

    }
      
    return ( n_1 * N_2 ) + ( n_2 % N_2 ) ;
	
  }

  if( d_1 != *infty() && d_2 == *infty() ){

    const uint N_1 = to_int( d_1 );
      
    if( N_1 == 0 ){

      ERR_IMPUT( d_1 , d_2 , n_1 , n_2 );

    }

    return ( n_2 * N_1 ) + ( n_1 % N_1) ;

  }

  const uint N_1 = to_int( d_1 );
  const uint N_2 = to_int( d_2 );
      
  if( N_1 == 0 || N_2 == 0 ){

    ERR_IMPUT( d_1 , d_2 , n_1 , n_2 );
      
  }

  return ( ( n_2 % N_2 ) * N_1 ) + ( n_1 % N_1 ) ;

}

void BijProd12( const dim& d_1 , const dim& d_2 , const uint& n , uint& n_1 , uint& n_2 )
{

  if( d_1 == *infty() ){

    if( d_2 == *infty() ){
      
      uint i = 0;
    
      while( ( ( i + 1 ) * ( i + 2 ) ) / 2 <= n ){
	  
	i++;
	  
      }
    
      n_2 = n - ( i * ( i + 1 ) ) / 2;
      n_1 = i - n_2;
      return;
      
    } else {

      const uint& N_2 = to_int( d_2 );
      
      if( N_2 == 0 ){

	ERR_IMPUT( d_1 , d_2 , n );

      }
    
      n_1 = n / N_2;
      n_2 = n % N_2;
      return;

    }

  }

  const uint& N_1 = to_int( d_1 );

  if( N_1 == 0 ){

    ERR_IMPUT( d_1 , d_2 , n );

  }

  n_1 = n % N_1;

  if( d_2 == *infty() ){
    
    n_2 = n / N_1;

  } else {

    const uint& N_2 = to_int( d_2 );
    n_2 = ( n / N_1 ) % N_2;

  }
  
  return;

}

uint BijProdN1( const list<dim>& a_d , const list<uint>& a_n )
{

  if( a_n.empty() ){

    if( ! a_d.empty() ){

      ERR_IMPUT( a_d , a_n );

    }
      
    return 0;

  }

  const dim d = a_d.front();
  const uint n = a_n.front();

  if( Length( a_n , 1 ) ){

    if( ! Length( a_d , 1 ) ){

      ERR_IMPUT( a_d , a_n );

    }

    if( n >= d ){

      ERR_IMPUT( a_d , a_n , d , n );
      
    }
      
    return n;

  }
  
  const list<dim> b_d = Back( -1 , a_d );
  const list<uint> b_n = Back( -1 , a_n );

  uint m;
  
  try{
    
    m = BijProd21( d , Prod( b_d ) , n , BijProdN1( b_d , b_n ) );

  }
  catch( const IllegalImput& e ){

    CALL( e , a_d , a_n );

  }

  return m;

}

list<uint> BijProd1N( const list<dim>& a_d , const uint& n )
{

  list<uint> a_n;
  
  try{
    
    BijProd1N( a_d , n , a_n );

  }
  catch( const IllegalImput& e ){

    CALL( e , a_d , n );

  }

  return a_n;

}

void BijProd1N( const list<dim>& a_d , const uint& n , list<uint>& a_n )
{

  if( a_d.empty() ){

    a_n.clear();

    if( n != 0 ){

      ERR_IMPUT( a_d , n );

    }
      
    return;

  }
  
  dim d = a_d.front();
  
  if( Length( a_d , 1 ) ){

    if( d == *infty() ){
	  
      a_n = to_list( n );

    } else {

      const uint N = to_int( d );

      if( N == 0 ){

	ERR_IMPUT( a_d , n );
      
      } else {

	a_n = to_list( n % N );

      }

    }

  } else {
    
    const list<dim> b_d = Back( -1 , a_d );
    uint n_1;
    uint n_2;

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

list<uint> BijProd1Infty( const uint& n )
{

  list<uint> a;

  try{
    
    BijProd1Infty( n , a );

  }
  catch( const ErrorType& e ){

    CALL( e , n );

  }
  
  return a;

}

void BijProd1Infty( const uint& n , list<uint>& a )
{

  if( n == 0 ){

    a.clear();

  } else {
    
    uint n1;
    uint n2;

    try{
      
      BijProd12( n , n1 , n2 );
  
    }
    catch( const ErrorType& e ){

      CALL( e , n );

    }

    try{
      
      a = Connect( to_list( n1 ) , BijProd1Infty( n2 ) );
  
    }
    catch( const ErrorType& e ){

      CALL( e , n );

    }

  }

  return;

}
