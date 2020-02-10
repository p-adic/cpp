// c:/Users/user/Documents/Programming/Error/IllegalCall/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

class IllegalCall:
  public ErrorType
{

public:
  virtual ~IllegalCall();

};

void ThrowIllegalCall( const char* const FILE , const int& LINE , const char* const FUNC );

void IndicateIllegalCall( const char* const FILE , const int& LINE , const char* const FUNC );
