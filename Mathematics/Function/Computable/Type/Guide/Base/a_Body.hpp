// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Guide/Base/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Valid/a_Body.hpp"
#include "../../a_Body.hpp"

#include "../../../Syntax/a_Body.hpp"

DEFINITION_OF_BASE_TYPE
(
 
 int ,
 IntString() ,
 EscapeString() + LbraceString() + SpaceString() + LdotsString() + CommaString() + SpaceString() + to_string( -2 ) + CommaString() + SpaceString() + to_string( -1 ) + CommaString() + SpaceString() + to_string( 0 ) + CommaString() + SpaceString() + to_string( 1 ) + CommaString() + SpaceString() + to_string( 2 ) + CommaString() + SpaceString() + LdotsString() + SpaceString() + EscapeString() + RbraceString()

 );

DEFINITION_OF_BASE_TYPE
(

 string ,
 StringString() ,
 EscapeString() + LbraceString() + SpaceString() + LdquoteString() + DquoteString() + CommaString() + SpaceString() + LdquoteString() + Plainise( "a" ) + DquoteString() + CommaString() + SpaceString() + LdquoteString() + Plainise( "b" ) + DquoteString() + CommaString() + SpaceString() + LdquoteString() + Plainise( "c" ) + DquoteString() + SpaceString() + LdotsString() + CommaString() + SpaceString() + LdquoteString() + Plainise( "aa" ) + DquoteString() + CommaString() + SpaceString() + LdquoteString() + Plainise( "ab" ) + DquoteString() + CommaString() + SpaceString() + LdquoteString() + Plainise( "ac" ) + DquoteString() + CommaString() + SpaceString() + LdotsString() + SpaceString() + EscapeString() + RbraceString()

 );

DEFINITION_OF_BASE_TYPE
(

 bool ,
 BoolString() ,
 EscapeString() + LbraceString() + SpaceString() + EscapeString() + SpaceString() + "b" + SpaceString() + InString() + SpaceString() + IntString() + SpaceString() + VertString() + SpaceString() + "b = 0" + SpaceString() + LorString() + SpaceString() + "b = 1" + SpaceString() + EscapeString() + SpaceString() + EscapeString() + RbraceString()

 );
