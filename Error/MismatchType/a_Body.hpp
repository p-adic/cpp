// c:/Users/user/Documents/Programming/Error/MismatchType/a_Body.hpp

#pragma once

#include "a.hpp"

#include "../UnknownError/a_Body.hpp"

template <typename... Args>
void ThrowMismatchType( const char* const FILE , const int& LINE , const char* const FUNC )
{

  if( ! CHECK_ERR ){
    
    IndicateMismatchType<Args...>( FILE , LINE , FUNC );
    throw MismatchType();
    
  } else {

    ERR_UNKNOWN( FILE , LINE , FUNC , to_string( typeid( Args )... ) );

  }

  return;

}

template <typename... Args>
void IndicateMismatchType( const char* const FILE , const int& LINE , const char* const FUNC )
{

  g_OCCURRENCE_OF_MISMATCH_TYPE = true;

  IndicateError( FILE , LINE , FUNC );
  cout << "Mismatch type in the function `" << FUNC << "'" << endl;
  
  cout << "The typenames are:" << endl;
  cout << "  " << to_string( typeid( Args )... ) << endl;
  cout << endl;

  return;

}
