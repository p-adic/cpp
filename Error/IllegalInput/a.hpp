// c:/Users/user/Documents/Programming/Error/IllegalInput/a.hpp

#pragma once

#include "a_Macro.hpp"

#include "../a.hpp"

class IllegalInput :
  public ErrorType
{

public:
  virtual ~IllegalInput();

};

template <typename... Args>
void IndicateIllegalInput( const char* const FILE , const int& LINE , const char* const FUNC , const Args&... );

template <typename... Args>
void ThrowIllegalInput( const char* const FILE , const int& LINE , const char* const FUNC , const Args&... );
