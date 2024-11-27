// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/PAdic/a.hpp

#pragma once
#include "../../../Utility/VLArray/a.hpp"

#include "a_Alias.hpp"

template <INT_TYPE_FOR_ADIC_INT P , INT_TYPE_FOR_ADIC_INT LENGTH = 0>
class AdicInt
{

private:
  VLArray<INT_TYPE_FOR_ADIC_INT> m_expansion;
  INT_TYPE_FOR_ADIC_INT m_n;

public:
  inline AdicInt( const INT_TYPE_FOR_ADIC_INT& n ) noexcept;

  inline const VLArray<INT_TYPE_FOR_ADIC_INT>& GetExpansion() const noexcept;
  inline const INT_TYPE_FOR_ADIC_INT& GetValue() const noexcept;

  static const VLArray<INT_TYPE_FOR_ADIC_INT>& Expand( const INT_TYPE_FOR_ADIC_INT& n ) noexcept;

};
