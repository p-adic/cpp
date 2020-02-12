// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Int/a.hpp

#pragma once
#include "../a.hpp"

class IntTypeOfComputableFunction :
  public TypeOfComputableFunction
{

private:
  int m_n;

public:
  inline IntTypeOfComputableFunction( const int& n ) noexcept;
  const int& GetValue() const noexcept;

};

#include "a_Alias.hpp"
