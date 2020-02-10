// c:/Users/user/Documents/Programming/Error/UnknownError/a.hpp

#pragma once

#include "a_Macro.hpp"

#include "../a.hpp"

class UnknownError :
  public ErrorType
{};

template <typename... Args> void IndicateUnknownError( const char* const FILE , const int& LINE , const char* const FUNC , const Args&... ARGS );
template <typename... Args> void ThrowUnknownError( const char* const FILE , const int& LINE , const char* const FUNC , const Args&... ARGS );
