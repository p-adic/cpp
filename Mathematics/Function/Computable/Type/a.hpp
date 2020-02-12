// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/a.hpp

#pragma once
#include "../Expression/Condition/a.hpp"

class TypeOfComputableFunction
{

private:
  ConditionOfComputableFunction m_cond;
  
public:
  inline TypeOfComputableFunction();
  inline TypeOfComputableFunction( const ConditionOfComputableFunction& cond );

  inline void SetCondition( const ConditionOfComputableFunction& cond ) noexcept;
  inline const ConditionOfComputableFunction& GetCondition() const noexcept;

};
