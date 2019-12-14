// Equality/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

DEFINITION_OF_NON_MEMBER_OPERATOR_TRUE( Equal , == );
DEFINITION_OF_NON_MEMBER_OPERATOR_FALSE( Equal , bool );

DECLARATION_OF_NON_MEMBER_OPERATOR( Invalid_ , Equal )
{

  return &t1 == &t2;

}
