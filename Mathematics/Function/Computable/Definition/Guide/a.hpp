// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Guide/a.hpp

#pragma once
#include "../a.hpp"

// DEFÇ…égÇ§ÅB
template <typename T>
class DefinitionOfOperator_Body
{};

template <typename Ret, typename... Args>
class DefinitionOfOperator_Body<FunctionSymbol<Ret,Args...> >
{

public:
  using type = DefinitionOfComputableFunction<Ret,Args...>;

};

template <typename... Args>
class DefinitionOfOperator_Body<RelationSymbol<Args...> >
{

public:
  using type = DefinitionOfComputableFunction<bool,Args...>;

};

template <typename T>
using DefinitionOfOperator = typename DefinitionOfOperator_Body<T>::type;
