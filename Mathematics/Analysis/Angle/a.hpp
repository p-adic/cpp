// Angle/a.hpp

#pragma once
#include "../../Arithmetic/Mod/a.hpp"

class Angle :
  public Mod<360>
{

public:
  static constexpr const float& pi = 3.1415926;
  
public:
  template <typename... ARGS> inline Angle( const ARGS&... args ) noexcept;

  Angle& operator=( const int& n ) noexcept;
  Angle& operator=( const uint& n ) noexcept;
  Angle& operator=( const Angle& n ) noexcept;
  Angle& operator/=( const int& n );
  Angle& operator/=( const uint& n );
  Angle& operator/=( const Angle& n );

  inline float Represent() const noexcept;
  
};

Angle operator/( const Angle& n0 , const int& n1 );
Angle operator/( const Angle& n0 , const uint& n1 );
Angle operator/( const Angle& n0 , const Angle& n1 );

float sin( const Angle& c );
float cos( const Angle& c );
