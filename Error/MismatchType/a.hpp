// c:/Users/user/Documents/Programming/Error/MismatchType/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

class MismatchType :
  public ErrorType
{

public:
  virtual ~MismatchType();

};

template <typename... Args> void ThrowMismatchType( const char* const FILE , const int& LINE , const char* const FUNC );

template <typename... Args> void IndicateMismatchType( const char* const FILE , const int& LINE , const char* const FUNC );
