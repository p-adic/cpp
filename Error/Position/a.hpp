// c:/Users/user/Documents/Programming/Error/Position/a.hpp

#pragma once

#include "a_Macro.hpp"

#include "../a.hpp"

void IndicatePosition( const char* const FILE , const int& LINE , const char* const FUNC ) noexcept;
void IndicatePosition( const string& FILE , const int& LINE , const string& FUNC ) noexcept;

template <typename Variable_Names , typename... Args> void IndicateCall( const char* const FILE , const int& LINE , const char* const FUNC , const ErrorType& e , const Args&... ARGS );
void IndicateCall( const string& FILE , const int& LINE , const string& FUNC , const ErrorType& e );
template <typename Variable_Names , typename... Args> void IndicateCall( const string& FILE , const int& LINE , const string& FUNC , const ErrorType& e , const Variable_Names& VARIABLE_NAMES , const Args&... ARGS );
