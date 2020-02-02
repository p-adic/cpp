// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

Pitch& Pitch::operator++() noexcept
{

  ++m_N;
  return *this;

}

Pitch& Pitch::operator--() noexcept
{

  --m_N;
  return *this;

}
