// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Guide/Array/a.hpp

#pragma once
#include "../../../../../SetTheory/EmptySet/a.hpp"

template <typename T>
class IsArrayType :
  public EmptySet
{

public:
  static constexpr const bool value = false;

};

template <typename Ret> class ArrayTypeOfComputableFunction;

template <typename Ret>
class IsArrayType<ArrayTypeOfComputableFunction<Ret> > :
  public EmptySet
{

public:
  static constexpr const bool value = true;

};

