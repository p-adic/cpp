// c:/Users/user/Documents/Programming/Utility/String/a.cpp

#include "Header.hpp"
#include "a_Body.hpp"

#include "VLArray/a_Body.hpp"
#include <cxxabi.h>

// abi::__cxa_demangleによりデマングリング。メモリリークあり。
string to_string( const type_info& T ) noexcept
{

  int status;
  return to_string( abi::__cxa_demangle( T.name() , 0 , 0, &status ) );

}

bool CheckContain( const string& s0 , const string& s1 ) noexcept
{

  return !( s0.find( s1 ) == string::npos );

}

bool CheckContainInt( const string& s ) noexcept
{

  for( int i = 0 ; i < 10 ; i++ ){

    if( CheckContain( s , to_string( i ) ) ){

      return true;

    }

  }

  return false;
  
}

bool Equal( const char* const& c0 , const char* const& c1 )
{

  const string s0 = c0;
  const string s1 = c1;

  return s0 == s1;

}

string InitialSegmentOf( const string& s , const uint& n )
{

  if( n == 0 ){

    return "";

  }

  uint d;

  try{
    
    d = FirstBitOf( s );

  } catch( ErrorType& e ) {

    CALL_P( e , s , n );

  }

  return s.substr( 0 , d ) + InitialSegmentOf( s.substr( d , s.size() - d ) , n - 1 );

}

string FinalSegmentOf( const string& s , const uint& n )
{

  VLArray<string> a;

  try{
    
    a = ToArrayOfLetters( s );

  } catch( ErrorType& e ) {

    CALL_P( e , s , n );

  }

  const uint& size = a.size();

  if( size < n ){

    ERR_IMPUT( s , n , a , size );

  }

  while( size > n ){

    a.pop_front();

  }
  
  return Sum( a );

}

uint FirstBitOf( const string& s )
{

  if( s == "" ){

    ERR_IMPUT( s );

  }
  
  const unsigned char letter = s[0];
  uint length = s.size();
  
  if( IsFirstHalfOfZenkaku( letter ) ){

    if( length < 2 ){

      ERR_IMPUT( s , length );

    }
    
    return 2;

  }

  return 1;

}

void Separate( const string& s , const string& separator , string& s_front , string& s_back )
{

  VLArray<string> a_front;
  VLArray<string> a_back;

  try{
    
    Separate( s , separator , a_front , a_back );

  } catch( ErrorType& e ) {

    CALL_P( e , s , separate );

  }

  s_front = Sum( a_front );
  s_back = Sum( a_back );
  return;

}
