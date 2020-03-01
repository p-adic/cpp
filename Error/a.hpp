// c:/Users/user/Documents/Programming/Error/a.hpp

#pragma once
#include "a_Macro.hpp" 

#include "BreakPoint/a.hpp"
#include "../Utility/SmartPointer/a.hpp"

class ErrorType
{

private:
  uint m_count;
  SmartPointer<uint> m_number;
  
protected:
  ErrorType() noexcept;
  virtual ~ErrorType();

public:
  ErrorType( const ErrorType& ) noexcept;

};

template <typename Arg1 , typename... Arg2> void IndicateParameters( const string& VARIABLE_NAMES , const Arg1& ARG1 , const Arg2&... ARG2 ) noexcept;

void IndicateError( const char* const FILE , const int& LINE , const char* const FUNC );
bool CheckError( const char* const FILE , const int& LINE , const char* const FUNC ) noexcept;

template <typename Variable_Names , typename... Args> void IndicateError( const char* const FILE , const int& LINE , const char* const FUNC , const Variable_Names& VARIABLE_NAMES , const Args&... ARGS );

#include "Position/a.hpp"
#include "Warning/a.hpp"
#include "../Utility/GlobalVariable/a.hpp"
#include "../Utility/Macro.hpp"
