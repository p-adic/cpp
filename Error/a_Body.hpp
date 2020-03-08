// c:/Users/user/Documents/Programming/Error/a_Body.hpp

#pragma once
#include "a.hpp"

#include "FaultInCoding/a.hpp"

#include "BreakPoint/a_Body.hpp"
#include "Position/a_Body.hpp"
#include "../Utility/GlobalVariable/a_Body.hpp"

inline ErrorType::ErrorType( const ErrorType& e ) noexcept :  m_count( e.m_count ) , m_number( e.m_number ) { *m_number += 1u; }

// a.cppÇ≈íËã`Ç≥ÇÍÇƒÇ¢ÇÈÅB
void IndicateError_Body( const char* const FILE , const int& LINE , const char* const FUNC );

template <typename Arg1 , typename... Arg2>
void IndicateParameters( const string& VARIABLE_NAMES , const Arg1& ARG1 , const Arg2&... ARG2 ) noexcept
{
  
  if( sizeof...( ARG2 ) == 0 && ! CheckContain( VARIABLE_NAMES , "," ) ){
    
    cout << "      with a parameter `";
    
  } else {

    cout << "      with parameters `";

  }

  string s;
  IndicateArguments_Body( VARIABLE_NAMES , s , ARG1 , ARG2... );
  cout << s << "'" << endl;
  return;

}

template <typename Variable_Names , typename... Args>
void IndicateError( const char* const FILE , const int& LINE , const char* const FUNC , const Variable_Names& VARIABLE_NAMES , const Args&... ARGS )
{

  if( sizeof...( Args ) >= 1 ){

    IndicateError_Body( FILE , LINE , FUNC );
    IndicateParameters( to_string( VARIABLE_NAMES ) , ARGS... );
    cout << endl;

  } else {

    ThrowFaultInCoding( FILE , LINE , FUNC );

  }
  
  return;

}
