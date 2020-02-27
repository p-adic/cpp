// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/OnDo/a.hpp

#pragma once
#include "../a.hpp"
#include "SetTouJi/a.hpp"

class OnDo
{

private:
  const SetTouJiOfOnDo& m_settouji;
  uint m_dosuu;
  uint m_dosuu_mod;

public:
  inline OnDo( const Pitch& P1 , const Pitch& P2 ) noexcept;

  bool CheckKyouWaOnTei() const noexcept;
  bool CheckKyouWaOnTeiNonBottom() const noexcept;
  
  inline string Display() const noexcept;
  
private:
  inline OnDo( const Pitch& P1 , const Pitch& P2 , const int& signed_dosuu ) noexcept;
  inline OnDo( const Pitch& P1 , const Pitch& P2 , const int& signed_dosuu , const bool& valid ) noexcept;
  
  inline OnDo( const uint& zero_indexed_dosuu , const int& pitch_difference ) noexcept;

  static int ComputeSignedDoSuu( const Pitch& P1 , const Pitch& P2 ) noexcept;
  static uint ComputeZeroIndexedDoSuu( const int& signed_dosuu , const bool& valid ) noexcept;
  static uint ComputePitchDifference( const Pitch& P1 , const Pitch& P2 , const bool& valid ) noexcept;

};
