#include "Header.hpp"
#include "a_Body.hpp"

#include <cxxabi.h>

// abi::__cxa_demangleによりデマングリング。メモリリークあり。
string to_string( const type_info& T ) noexcept
{

  int status;
  return to_string( abi::__cxa_demangle( T.name() , 0 , 0, &status ) );

}

string Sum( const list<string>& ss ) noexcept
{
  
  string s = "";
  for( list<string>::const_iterator itr = ss.begin() , end = ss.end() ; itr != end ; itr++ ){

    s += *itr;

  }

  return s;

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

static string FinalSegmentOf_Body( const string& s , const uint& n , uint& current_length );

string FinalSegmentOf( const string& s , const uint& n )
{

  uint current_length = 0;
  string s0;

  try{
    
    s0 = FinalSegmentOf_Body( s , n , current_length );

  } catch( ErrorType& e ) {

    CALL_P( e , s , n );

  }
  
  return s0;

}

static string FinalSegmentOf_Body( const string& s , const uint& n , uint& current_length )
{

  if( n == 0 ){

    return "";

  }

  if( s.empty() ){

    return "";
    
  }

  uint d;

  try{
    
    d = FirstBitOf( s );

  } catch( ErrorType& e ) {

    CALL_P( e , s , n , current_length );

  }
  
  const string first = s.substr( 0 , d );
  const string current_segment = FinalSegmentOf_Body( s.substr( d , s.size() - d ) , n , current_length );

  if( n == current_length ){

    return current_segment;

  }

  current_length++;
  return first + current_segment;

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

void Separate( const string& s , const string& separator , string& s_front , string& s_back ) noexcept
{

  const uint separator_length = separator.length();
  uint size = s.length();
    
  if( separator_length > 0 ){

    const uint d = separator_length - 1;
      
    if( size > d ){

      size -= d;

    } else {

      size = 0;
      
    }

  }
  
  for( uint i = 0 ; i < size ; i++ ){

    if( s.substr( i , separator_length ) == separator ){

      s_front = s.substr( 0 , i );
      s_back = s.substr( i );
      return;

    }

  }

  s_front = s;
  s_back = "";
  return;

}
