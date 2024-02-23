// Angle/a.hpp

#pragma once
#include "../../Arithmetic/Mod/ConstexprModulo/a.hpp"

class Angle :
  public Mod<360>
{

public:
  static constexpr const float& pi = 3.1415926;
  
public:
  template <typename... ARGS> inline Angle( const ARGS&... args ) noexcept;
  inline Angle( const Angle& n ) noexcept;
  inline Angle( Angle&& n ) noexcept;

  inline Angle& operator=( const int& n ) noexcept;
  inline Angle& operator=( const Angle& n ) noexcept;
  inline Angle& operator=( Angle&& n ) noexcept;

  // Mod<360>Ç≈ÇÃäÑÇËéZÇ≈Ç»Ç≠intÇ≈ÇÃäÑÇËéZÇ≈Ç†ÇÈÇ±Ç∆Ç…íçà”
  inline Angle& operator/=( const int& n );
  inline Angle& operator/=( const Angle& n );

  inline float Represent() const noexcept;
  
};

inline Angle operator/( const Angle& n0 , const int& n1 );
inline Angle operator/( const Angle& n0 , const Angle& n1 );

inline float sin( const Angle& c );
inline float cos( const Angle& c );
