// c:/Users/user/Documents/Programming/Error/IllegalAccess/a.hpp

#pragma once

#include "a_Macro.hpp"

#include "../a.hpp"
#include "../../Utility/SmartPointer/a.hpp"

class IllegalAccess :
  public ErrorType
{

protected:
  IllegalAccess() = default;

public:
  virtual ~IllegalAccess();

};

class NullAccess :
  public IllegalAccess
{

public:
  virtual ~NullAccess() = default;

};

class UninitialisedAccess :
  public IllegalAccess
{

public:
  virtual ~UninitialisedAccess() = default;

};

template <typename... Args> void ThrowNullAccess( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const Args&... );

template <typename... Args> void ThrowUninitialisedlAccess( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const Args&... );

template <typename... Args> void IndicateNullAccess( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const Args&... );

template <typename... Args> void IndicateUninitialisedAccess( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const Args&... );

template <typename T , typename... Args> T& Access( const char* const FILE , const int& LINE , const char* const FUNC ,const string& VARIABLE_NAMES , T* const & p , const Args&... );

template <typename T , typename... Args> T& Access( const char* const FILE , const int& LINE , const char* const FUNC , const string& VARIABLE_NAMES , const SmartPointer<T>& p , const Args&... ARGS );
