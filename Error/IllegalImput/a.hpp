// IllegalImput/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

class IllegalImput :
  public ErrorType
{

public:
  virtual ~IllegalImput();

};

template <typename... Args>
void IndicateIllegalImput( const char* const FILE , const int& LINE , const char* const FUNC , const Args&... );

template <typename... Args>
void ThrowIllegalImput( const char* const FILE , const int& LINE , const char* const FUNC , const Args&... );
