// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Line/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../../Function/Variadic/a_Body.hpp"
#include "../../Relation/Variadic/a_Body.hpp"
#include "../../Expression/Condition/a_Body.hpp"

template <typename Ret> DEFINITION_OF_LIST( Ret );

template <typename Ret> inline LineOfDefinitionOfComputableFunction<Ret>::LineOfDefinitionOfComputableFunction( const LineOfDefinitionOfComputableFunction<void>& line ) : SyntaxOfComputableFunction( line.Get() ) {}

// IF
template <typename Ret> DEFINITION_OF_IF( Ret );
template <typename Ret> DEFINITION_OF_SUPPOSE( Ret );

  
// RETURN
template <typename Ret> inline LineOfDefinitionOfComputableFunction<Ret>::LineOfDefinitionOfComputableFunction( const ExpressionOfComputableFunction<Ret>& ret ) : SyntaxOfComputableFunction( "line" , "return" , ret.Get() ) {}
