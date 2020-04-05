// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/Variadic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../Expression/List/a_Body.hpp"

template <typename... Args> inline VariadicRelationSymbol<Args...>::VariadicRelationSymbol( const string& r , const VariableSymbol<Args>&... args ) : VariadicRelationSymbol( r , SeparatorOfComputableFunction( r , sizeof...( Args ) , true ) , args... ) {}

template <typename... Args> inline VariadicRelationSymbol<Args...>::VariadicRelationSymbol( const string& r , const SeparatorOfComputableFunction& s , const VariableSymbol<Args>&... args ) : RelationSymbol<Args...,void>( r , s , args... , LdotsSymbol() ) {}

template <typename... Args> template <typename... VA> inline ConditionOfComputableFunction VariadicRelationSymbol<Args...>::operator()( const ExpressionOfComputableFunction<Args>&... args , const ListExpressionOfComputableFunction<VA...>& va ) const { return ConditionOfComputableFunction( *this , args... , va ); }
