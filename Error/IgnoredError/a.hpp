// IgnoredError/a.hpp

#pragma once

#include "a_Macro.hpp"

#include "../a.hpp"

template <typename Variable_Names , typename... Args> void IndicateIgnoredError( const char* const FILE , const int& LINE , const char* const FUNC , const Variable_Names& VARIABLE_NAMES , const Args&... ARGS ) noexcept;
template <typename Variable_Names , typename... Args> void IndicateIgnoredError( const string& FILE , const int& LINE , const string& FUNC , const Variable_Names& VARIABLE_NAMES , const Args&... ARGS ) noexcept;
