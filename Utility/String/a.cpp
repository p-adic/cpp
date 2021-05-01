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

  const uint length = s.size();
  const unsigned char letter = s[0];
  
  if( IsFirstHalfOfZenkaku( letter ) ){

    if( length < 2 ){

      ERR_IMPUT( s , n , length );

    }
    
    return a.substr( 0 , 2 ) + GetInitialSegment( s.substr( 2 , length - 2 ) , n - 1 );

  }

  return a.substr( 0 , 1 ) + GetInitialSegment( s.substr( 1 , length - 1 ) , n - 1 );

}

static FinalSegmentOf_Body( const string& s , const uint& n , uint& current_length );

string FinalSegmentOf( const string& s , const uint& n )
{

  uint current_length = 0;
  return FinalSegmentOf_Body( s , n , current_length );

}

static FinalSegmentOf_Body( const string& s , const uint& n , uint& current_length )
{

  if( n == 0 ){

    return "";

  }

  uint length = s.size();
  uint dlength;
  const unsigned char letter = s[0];
  
  if( IsFirstHalfOfZenkaku( letter ) ){

    if( length < 2 ){

      ERR_IMPUT( s , n , length );

    }
    
    dlength = 2;

  } else {

    dlength = 1;

  }
  
  const string first = s.substr( 0 , dlength );
  const string current_segment = FinalSegmentOf_Body( s.substr( dlength , length - dlength ) , n , current_length );

  if( n == current_length ){

    return current_segment;

  }

  current_length++;
  return first + current_segment;

}
