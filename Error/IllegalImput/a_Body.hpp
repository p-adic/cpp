// c:/Users/user/Documents/Programming/Error/IllegalImput/a_Body.hpp

#pragma once

#include "a.hpp"

#include "../a_Body.hpp"

template <typename... Args>
void IndicateIllegalImput( const char* const FILE , const int& LINE , const char* const FUNC , const Args&... ARGS )
{

  g_OCCURRENCE_OF_ILLEGAL_IMPUT = true;

  IndicateError( FILE , LINE , FUNC , ARGS... );
  cout << "illegal imput to the function `" << FUNC << "'" << endl;
  cout << endl;

  return;
 
}

template <typename... Args>
void ThrowIllegalImput( const char* const FILE , const int& LINE , const char* const FUNC , const Args&... ARGS )
{

  if( ! CHECK_ERR ){

    IndicateIllegalImput( FILE , LINE , FUNC , ARGS... );
    throw IllegalImput();
    
  }

  return;

}
