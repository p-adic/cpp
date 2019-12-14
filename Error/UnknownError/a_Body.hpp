// UnknownError/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename... Args>
void IndicateUnknownError( const char* const FILE , const int& LINE ,const char* const FUNC , const Args&... ARGS )
{

  IndicateError( FILE , LINE , FUNC , ARGS... );
  cout << "The cause is unknown." << endl;
  cout << endl;

  return;

}

template <typename... Args>
void ThrowUnknownError( const char* const FILE , const int& LINE ,const char* const FUNC , const Args&... ARGS )
{

  g_ALLIANCE_OF_OVERLAPPING = true;

  IndicateUnknownError( FILE , LINE , FUNC , ARGS... );
  
  throw UnknownError();

  return;


}
