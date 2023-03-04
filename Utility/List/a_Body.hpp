// List/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Error/IllegalInput/a_Body.hpp"
#include "../../SFINAE/NonMemberFunction/Operator/Equality/a_Body.hpp"

template <typename T>
list<T> to_list() noexcept
{

  const list<T> ss;
  return ss;

}

template <typename T>
list<T> to_list( const T& x ) noexcept
{

  const T s[1] = { x };
  const list<T> ss( s , s + 1 );
  return ss;

}

template <typename T>
list<T> to_list( const T& x , const T& y ) noexcept
{

  const T s[2] = { x , y };
  const list<T> ss( s , s + 2 );
  return ss;

}

template <typename T>
list<T> to_list( const T& x , const T& y , const T& z ) noexcept
{

  const T s[3] = { x , y , z };
  const list<T> ss( s , s + 3 );
  return ss;

}

template <typename T>
list<T> copy( const uint& n , const T& x ) noexcept
{

  const list<T> ss( n , x );
  return ss;

}

template <typename T>
uint Length( const list<T>& ss ) noexcept
{

  uint i = 0;
  
  for( typename list<T>::const_iterator itr = ss.begin() , end = ss.end() ; itr != end ; itr++ ){

    i++;

  }
  
  return i;

}

template <typename T>
bool Length( const list<T>& ss , const uint& n ) noexcept
{

  typename list<T>::const_iterator itr = ss.begin() , end = ss.end();
  
  for( uint i = 0 ; i <= n ; i++ ){

    if( itr == end ){

      if( i == n ){

	return true;

      } else {

	goto LABEL;

      }

    }
      
    itr++;

  }

 LABEL:
  return false;

}

template <typename T>
bool Longer( const list<T>& ss , const uint& n ) noexcept
{

  uint m;
  return Longer( ss , n , m );

}

template <typename T>
bool Longer( const list<T>& ss , const uint& n , uint& m ) noexcept
{

  typename list<T>::const_iterator itr = ss.begin() , end = ss.end();
  
  for( uint i = 0 ; i <= n ; i++ ){

    if( itr == end ){

      m = i;
      return false;

    }
      
    itr++;

  }

  m = n+1;
  return true;

}

template <typename T>
bool LongerOrEqual( const list<T>& ss , const uint& n ) noexcept
{

  uint m;
  return Longer( ss , n , m ) || n == m;

}

template <typename T>
void Separate( const int& n , const list<T>& a , list<T>& a_1 , list<T>& a_2 )
{


  a_1 = Front( n , a );
  const int N = Length( a );

  if( N <= n || n <= -N ){

    a_2 = Back( 0 , a );

  } else {

    a_2 = Back( -n , a );

  }
    
}

template <typename T> list<T> Connect( const list<T>& a , const list<T>& b )
{

  list<T> c = a;
  c.insert( c.end() , b.begin() , b.end() );
  return c;

}

template <typename T> list<T> Front( const int& n , const list<T>& a )
{

  const int N = Length( a );

  int M;

  if( N <= n ){

    M = N;

  } else {
    
    if( 0 <= n ){

      M = n;
      
    } else {

      M = N + n;

    }

  }

  list<T> b{};
  typename list<T>::const_iterator itr = a.begin();

  for( int m = 1 ; m <= M ; m++ ){

    b.push_back( *itr );
    itr++;

  }

  return b;

}

template <typename T> list<T> Back( const int& n , const list<T>& a )
{

  const int N = Length( a );
  
  int M;

  if( N <= n ){

    M = N;

  } else {
    
    if( 0 <= n ){

      M = n;
      
    } else {

      M = N + n;

    }
  
  }

  list<T> b{};
  typename list<T>::const_iterator itr = a.end();

  for( int m = 1 ; m <= M ; m++ ){

    itr--;
    b.push_front( *itr );

  }

  return b;

}

template <typename T> const T& Access( const uint& n , const list<T>& a )
{
  
  typename list<T>::const_iterator itr = a.begin() , end = a.end();

  for( uint i = 0 ; i < n ; i++ ){

    if( itr == end ){

      ERR_INPUT( n , a , i );
	
    }

    itr++;

  }

  if( itr == end ){

    ERR_INPUT( n , a );
	
  }

  return *itr;

}

template <typename T>
bool CheckContain( const list<T>& a , const T& t )
{
  
  for( typename list<T>::const_iterator itr = a.begin() , end = a.end() ; itr != end ; itr++ ){

    if( Equal( *itr , t ) ){

      return true;

    }

  }
    
  return false;

}

template <typename T>
bool CheckReduced( const list<T>& a )
{
  
  for( typename list<T>::const_iterator itr1 = a.begin() , end = a.end() ; itr1 != end ; itr1++ ){

    for( typename list<T>::const_iterator itr2 = itr1 ; itr2 != end ; itr2++ ){

      if( Equal( *itr1 , *itr2 ) ){

	if( itr1 != itr2 ){
	  
	  return false;
	
	}

      }

    }
    
  }

  return true;

}

template <typename T>
list<T> Reduce( const list<T>& a )
{
  list<T> na;
  
  for( typename list<T>::const_iterator itr1 = a.begin() , end1 = a.end() ; itr1 != end1 ; itr1++ ){

    for( typename list<T>::const_iterator itr2 = na.begin() , end2 = na.end() ; itr2 != end2 ; itr2++ ){

      if( Equal( *itr1 , *itr2 ) ){

	goto LABEL;

      }
      
    }

    na.push_back( *itr1 );

  LABEL:
    ;
    
  }

  return na;

}
