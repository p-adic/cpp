// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/Variadic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename... ARGS> inline VariadicRelationSymbol<ARGS...>::VariadicRelationSymbol( const string& r , const VariableSymbol<ARGS>&... args ) : RelationSymbol<ARGS...>( r , args... , LDOTS ) {}


template <typename... ARGS> template <typename... VA> inline ConditionOfComputableFunction VariadicRelationSymbol<ARGS...>::operator()( const ExpressionOfComputableFunction<ARGS>&... args , const ExpressionOfComputableFunction<VA>&... va ) const { return ConditionOfComputableFunction( *this , args... , va... ); }
