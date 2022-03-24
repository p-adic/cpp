// c:/Users/user/Documents/Programming/Utility/String/VLArray/a.cpp

#include "../Header.hpp"
#include "a_body.hpp"

#include "../a_body.hpp"

VLArray<string> ToArrayOfLetters( const string& s )
{

  VLArray<string> a{};

  if( s == "" ){

    return a;

  }

  uint d;

  try{
    
    d = FirstBitOf( s );

  } catch( ErrorType& e ) {

    CALL_P( e , s );

  }
  
  const string first = s.substr( 0 , d );
  const string rest = s.substr( d , s.size() - d );

  a.push_back( first );
  a.Concatenate( ToArrayOfLetters( rest ) );
  return a;

}

void Separate( const string& s , const string& separator , VLArray<string>& a_front , VLArray<string>& a_back )
{

  try{
    
    a_front = ToArrayOfLetters( s );

  } catch( ErrorType& e ) {

    CALL_P( e , s , separator );

  }

  a_back = VLArray<string>();
  const uint size = s_front.size();
  
  for( uint i = 0 ; i < size ; i++ ){

    if( a[i] == separator ){

      while( size > i + 1 ){

	a_back.push_front( s_front.back() );
	a_front.pop_back();

      }

      a_front.pop_back();
      return;

    }

  }

  return;

}
