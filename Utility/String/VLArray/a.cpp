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

  VLArray<string> separator_copy;
  
  try{
    
    a_front = ToArrayOfLetters( s );
    separator_copy = ToArrayOfLetters( separator );

  } catch( ErrorType& e ) {

    CALL_P( e , s , separator );

  }

  a_back = VLArray<string>();
  const uint& size1 = a_front.size();
  const uint& size2 = separator_copy.size();
  
  for( uint i = 0 ; i + size2 < size1 + 1 ; i++ ){

    bool b = true;
    
    for( uint j = 0 ; j < size2 && b ; j++ ){

      if( a_front[ i + j ] != separator_copy[j] ){

	b = false;

      }

    }

    if( b ){

      while( i + size2 < size1 ){

	a_back.push_front( a_front.back() );
	a_front.pop_back();

      }

      while( i < size1 ){

	a_front.pop_back();

      }

      return;


    }

  }

  return;

}
