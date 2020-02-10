// c:/Users/user/Documents/Programming/Error/IllegalCall/a.cpp

#include "../Header.hpp"
#include "a.hpp"

#include "../a_Body.hpp"

IllegalCall::~IllegalCall()
{

  g_OCCURRENCE_OF_ILLEGAL_CALL = false;

}

void ThrowIllegalCall( const char* const FILE , const int& LINE , const char* const FUNC )
{

  if( ! CHECK_ERR ){
    
    IndicateIllegalCall( FILE , LINE , FUNC );
    throw IllegalCall();

  } else {

    ERR_UNKNOWN( FILE , LINE , FUNC , "()" , "()" );

  }

  return;

}

void IndicateIllegalCall( const char* const FILE , const int& LINE , const char* const FUNC )
{

  g_OCCURRENCE_OF_ILLEGAL_CALL = true;

  IndicateError( FILE , LINE , FUNC , "()" , "()" );
  cout << "illegal call of the function `" << FUNC << "'" << endl;
  cout << endl;

  return;

}
