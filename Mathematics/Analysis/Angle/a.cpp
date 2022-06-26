// c:/Users/user/Documents/Programming/Mathematics/Analysis/Angle/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

Angle& Angle::operator=( const int& n ) noexcept
{

  Mod<360>::operator=( n );
  return *this;

}

Angle& Angle::operator=( const Angle& n ) noexcept
{

  Mod<360>::operator=( n );
  return *this;

}

Angle& Angle::operator/=( const int& n )
{

  m_n /= Residue( n );
  m_inv = 0;
  return *this;

}

Angle& Angle::operator/=( const Angle& n )
{

  m_n /= n.m_n;
  m_inv = 0;
  return *this;
 
}

Angle operator/( const Angle& n0 , const int& n1 )
{

  auto n = n0;
  n /= n1;
  return n;

}

Angle operator/( const Angle& n0 , const Angle& n1 )
{

  auto n = n0;
  n /= n1;
  return n;

}
