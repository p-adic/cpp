// c:/Users/user/Documents/Programming/Error/FaultInCoding/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

class FaultInCoding :
  public ErrorType
{};

void IndicateFaultInCoding( const char* const FILE , const int& LINE , const char* const FUNC );
void ThrowFaultInCoding( const char* const FILE , const int& LINE , const char* const FUNC );
