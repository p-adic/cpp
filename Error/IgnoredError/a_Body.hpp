// IgnoredError/a_Body.hpp

#pragma once

#include "a.hpp"

#include "../a_Body.hpp"

template <typename Variable_Names , typename... Args>
void IndicateIgnoredError( const char* const FILE , const int& LINE , const char* const FUNC , const Variable_Names& VARIABLE_NAMES , const Args&... ARGS ) noexcept
{

  IndicateIgnoredError( to_string( FILE ) , LINE , to_string( FUNC ) , VARIABLE_NAMES , ARGS... );
  return;
  
}

template <typename Variable_Names , typename... Args>
void IndicateIgnoredError( const string& FILE , const int& LINE , const string& FUNC , const Variable_Names& VARIABLE_NAMES , const Args&... ARGS ) noexcept
{

  if( g_OCCURRENCE_OF_ERR == false ){
    
    cout << "There is some error ignored at " << endl;
    IndicatePosition( POSITION );
    IndicateParameters( to_string( VARIABLE_NAMES ) , ARGS... );

  }
  
  return;

}
