// c:/Users/user/Documents/Programming/Error/BreakPoint/a.hpp

#pragma once
#include "a_Macro.hpp"

class FlagCounter
{

private:
  uint m_i0;
  uint m_i1;
  uint m_count;
  bool m_b;

public:
  inline FlagCounter( const uint& i0 , const uint& i1 ) noexcept;
  inline void operator++( int ) noexcept;

  void Set( const uint& i0 , const uint& i1 ) noexcept;
  inline const uint& i0() const noexcept;
  inline const uint& i1() const noexcept;

  void CheckActive() noexcept;
  inline const bool& IsActive() const noexcept;
  
};

inline void BreakPoint() noexcept;

void CountCall( const uint& i0 = 0 ) noexcept;
template <typename... ARGS> void CountCall( const uint& i0 , const uint& i1 , const ARGS&... i2 ) noexcept;

inline bool CallFlagContainer( const bool& CalledForCheck ) noexcept;
template <typename... ARGS> bool CallFlagContainer( const bool& CalledForCheck , const uint& i0 , const uint& i1 , const ARGS&... i2 ) noexcept;
