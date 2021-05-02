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

  const unsigned char letter = s[0];
  const uint length = s.size();
  uint dlength;
  
  if( IsFirstHalfOfZenkaku( letter ) ){

    if( length < 2 ){

      ERR_IMPUT( s , n , length );

    }
    
    dlength = 2;

  } else {

    dlength = 1;

  }

  return s.substr( 0 , dlength ) + InitialSegmentOf( s.substr( dlength , length - dlength ) , n - 1 );

}

static string FinalSegmentOf_Body( const string& s , const uint& n , uint& current_length );

string FinalSegmentOf( const string& s , const uint& n )
{

  uint current_length = 0;
  return FinalSegmentOf_Body( s , n , current_length );

}

static string FinalSegmentOf_Body( const string& s , const uint& n , uint& current_length )
{

  if( n == 0 ){

    return "";

  }

  const uint d = FirstBitOf( s );
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
