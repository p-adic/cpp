// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/a_Alias.hpp

#pragma once

template <typename T>
using LineTypeForMatrix = VLArray<T>;
// vector�̕�����@�̌v�Z������
// template <typename T>
// using LineTypeForMatrix = vector<T>;

template <typename T>
using TableTypeForMatrix = LineTypeForMatrix<LineTypeForMatrix<T> >;

using SizeTypeForMatrix = uint;
// using SizeTypeForMatrix = ll;