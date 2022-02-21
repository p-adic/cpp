// c:/Users/user/Documents/Programming/Utility/VLArray/a_Alias.hpp

#pragma once
#include "../WrappedType/Int/a.hpp"
#include "../../Mathematics/SetTheory/EmptySet/a.hpp"

template <typename T>
using initialiser_list = initializer_list<T>;

template <typename T> class VLArray;

template <typename N , typename T> class VLMatrix_Body;

template <typename T>
class VLMatrix_Body<WrappedUInt<1>,T>
{

public:
  using type = VLArray<T>;

};

template <typename T>
class VLMatrix_Body<WrappedUInt<2>,T>
{

public:
  using type = VLArray<typename VLMatrix_Body<WrappedUInt<1>,T>::type>;

};

template <typename T>
class VLMatrix_Body<WrappedUInt<3>,T>
{

public:
  using type = VLArray<typename VLMatrix_Body<WrappedUInt<2>,T>::type>;

};

template <uint N , typename T>
using VLMatrix = typename VLMatrix_Body<WrappedUInt<N>,T>::type;
