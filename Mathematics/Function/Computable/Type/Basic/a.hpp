// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Basic/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../a.hpp"
#include "../../../../SetTheory/EmptySet/a.hpp"

template <typename T>
class IsBasicType :
  public EmptySet
{

public:
  static constexpr const bool value = false;

};


DEFINITION_OF_IS_BASIC( void , Cdots );
DEFINITION_OF_IS_BASIC( int , Int );
DEFINITION_OF_IS_BASIC( bool , Bool );
DEFINITION_OF_IS_BASIC( string , String );

inline const int& infty() noexcept;

template <typename T> inline const TypeOfComputableFunction& BasicType();
