// c:/Users/user/Documents/Programming/Error/IllegalInput/a_Body.hpp

#pragma once

#include "a.hpp"

#include "../a_Body.hpp"

template <typename... Args>
void IndicateIllegalInput( const char* const FILE , const int& LINE , const char* const FUNC , const Args&... ARGS )
{

  g_OCCURRENCE_OF_ILLEGAL_INPUT = true;

  IndicateError( FILE , LINE , FUNC , ARGS... );
  cout << "illegal input to the function `" << FUNC << "'" << endl;
  cout << endl;

  return;
 
}

template <typename... Args>
void ThrowIllegalInput( const char* const FILE , const int& LINE , const char* const FUNC , const Args&... ARGS )
{

  if( ! CHECK_ERR ){

    IndicateIllegalInput( FILE , LINE , FUNC , ARGS... );
    throw IllegalInput();
    
  }

  return;

}
