// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Guide/Array/Nest/a.hpp

#pragma once
#include "../../../../../../SetTheory/EmptySet/a.hpp"

template <typename T>
class IsNestedArrayType :
  public EmptySet
{

public:
  static constexpr const bool value = false;

};

template <typename Ret> class NestedArrayTypeOfComputableFunction;

template <typename Ret>
class IsNestedArrayType<NestedArrayTypeOfComputableFunction<Ret> > :
  public EmptySet
{

public:
  static constexpr const bool value = true;

};

