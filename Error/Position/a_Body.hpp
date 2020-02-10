// c:/Users/user/Documents/Programming/Error/Position/a_Body.hpp

#pragma once

#include "a.hpp"

#include "../a_Body.hpp"
#include "../../Utility/String/Normalised/a_Body.hpp"

template <typename Variable_Names , typename... Args>
void IndicateCall( const char* const FILE , const int& LINE , const char* const FUNC , const ErrorType& e , const Args&... ARGS )
{

  IndicateCall( to_string( FILE ) , LINE , to_string( FUNC ) , e , ARGS... );
  return;

}

// Position.cppÇ≈íËã`Ç≥ÇÍÇƒÇ¢ÇÈÅB
void IndicateCall_Body( const string& FILE , const int& LINE , const string& FUNC ) noexcept;

template <typename Variable_Names , typename... Args>
void IndicateCall( const string& FILE , const int& LINE , const string& FUNC , const ErrorType& e , const Variable_Names& VARIABLE_NAMES , const Args&... ARGS )
{

  IndicateCall_Body( to_string( FILE ) , LINE , to_string( FUNC ) );
  IndicateParameters( to_string_Constified( VARIABLE_NAMES ) , ARGS... );
  
  throw e;
  
  return;

}
