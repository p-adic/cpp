// WrappedInt/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Mathematics/SetTheory/Singleton/a_Body.hpp"

template <int i>
const int WrappedInt<i>::m_i = i;

template <uint i>
const uint WrappedUInt<i>::m_i = i;

template <int i>
int WrappedInt<i>::Get()
{

  return m_i;

}

template <uint i>
uint WrappedUInt<i>::Get()
{

  return m_i;

}

template <int i>
const WrappedInt<i>& Wrap()
{

  return Object<WrappedInt<i> >();

}

template <uint i>
const WrappedUInt<i>& WrapU()
{

  return Object<WrappedUInt<i> >();

}
