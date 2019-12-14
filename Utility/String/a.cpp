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
