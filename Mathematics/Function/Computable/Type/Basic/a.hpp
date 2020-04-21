// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Basic/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../../../../SetTheory/EmptySet/a.hpp"

template <typename T>
class IsBasicType :
  public EmptySet
{

public:
  static constexpr const bool value = false;

};


DEFINITION_OF_IS_BASIC( void , \\cdots );
DEFINITION_OF_IS_BASIC( int , \\mathbb{Z} );
DEFINITION_OF_IS_BASIC( bool , BOOLIAN_SET_FOR_BASIC_TYPE );
DEFINITION_OF_IS_BASIC( string , \\textrm{String} );

inline const int& infty() noexcept;
