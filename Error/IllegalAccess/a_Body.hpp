// c:/Users/user/Documents/Programming/Error/IllegalAccess/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../UnknownError/a_Body.hpp"
#include "../../Utility/SmartPointer/a_Body.hpp"

template <typename... Args>
void ThrowNullAccess( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const Args&... ARGS )
{

  if( ! CHECK_ERR ){
    
    IndicateNullAccess( FILE , LINE , FUNC , VARIABLE_NAMES , ARGS... );
    throw NullAccess();
    
  } else {

    ERR_UNKNOWN( FILE , LINE , FUNC , VARIABLE_NAMES , ARGS... );

  }

  return;

}

template <typename... Args>
void ThrowUninitialisedAccess( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const Args&... ARGS )
{

  if( ! CHECK_ERR ){
    
    IndicateUninitialisedAccess( FILE , LINE , FUNC , VARIABLE_NAMES , ARGS... );
    throw UninitialisedAccess();
    
  } else {

    ERR_UNKNOWN( FILE , LINE , FUNC , VARIABLE_NAMES , ARGS... );

  }

  return;

}

// a.cppで定義されている。
void IndicateNullAccess_Body( const string& FUNC );

inline void IndicateNullAccess_Body( const char* const FUNC ){ IndicateNullAccess_Body( to_string( FUNC ) );}

template <typename... Args>
void IndicateNullAccess( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const Args&... ARGS )
{

  g_OCCURRENCE_OF_ILLEGAL_ACCESS = true;

  IndicateError( FILE , LINE , FUNC , VARIABLE_NAMES , ARGS... );
  IndicateNullAccess_Body( FUNC );
  cout << endl;

  return;

}

// IllegalAccess.cppで定義されている。
void IndicateUninitialisedAccess_Body( const string& FUNC );

inline void IndicateUninitialisedAccess_Body( const char* const FUNC ){ IndicateUninitialisedAccess_Body( to_string( FUNC ) );}

template <typename... Args>
void IndicateUninitialisedAccess( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const Args&... ARGS )
{

  g_OCCURRENCE_OF_ILLEGAL_ACCESS = true;

  IndicateError( FILE , LINE , FUNC , VARIABLE_NAMES , ARGS... );
  IndicateUninitialisedAccess_Body( FUNC );
  cout << endl;

  return;

}

template <typename T , typename... Args>
T& Access( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , T* const & p , const Args&... ARGS )
{

  if( p == nullptr ){

    ThrowNullAccess( FILE , LINE , FUNC , VARIABLE_NAMES , p , ARGS... );
    
  }

  return *p;

}
template <typename T , typename... Args>
const T& Access( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const T* const & p , const Args&... ARGS )
{

  if( p == nullptr ){

    ThrowNullAccess( FILE , LINE , FUNC , VARIABLE_NAMES , p , ARGS... );
    
  }

  return *p;

}

template <typename T , typename... Args>
T& Access( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const SmartPointer<T>& p , const Args&... ARGS )
{

  if( p == nullptr ){

    ThrowNullAccess( FILE , LINE , FUNC , VARIABLE_NAMES , p , ARGS... );
    
  }

  return *p;

}
