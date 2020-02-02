// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/OnDo/a.hpp

#pragma once
#include "../a.hpp"

#include "a_Macro.hpp"

class OnDo
{

private:
  const string& m_settouji;
  uint m_dosuu;
  uint m_dosuu_mod;

public:
  inline OnDo( const Pitch& P1 , const Pitch& P2 ) noexcept;

  bool CheckKyouWaOntei() const noexcept;
  bool CheckKyouWaOnteiNonBottom() const noexcept;
  
  inline string Display() const noexcept;
  
private:
  inline OnDo( const Pitch& P1 , const Pitch& P2 , const int& signed_dosuu ) noexcept;
  inline OnDo( const Pitch& P1 , const Pitch& P2 , const int& signed_dosuu , const bool& valid ) noexcept;
  
  inline OnDo( const uint& zero_indexed_dosuu , const int& pitch_difference ) noexcept;

  static int ComputeSignedDosuu( const Pitch& P1 , const Pitch& P2 ) noexcept;
  static uint ComputeZeroIndexedDosuu( const int& signed_dosuu , const bool& valid ) noexcept;
  static uint ComputePitchDifference( const Pitch& P1 , const Pitch& P2 , const bool& valid ) noexcept;
  static const string& ComputeSettouji( const uint& zero_indexed_dosuu , const int& pitch_difference ) noexcept;
  
  static const string& Kanzen() noexcept;
  static const string& Chou() noexcept;
  static const string& Tan() noexcept;
  static const string& Zou() noexcept;
  static const string& Gen() noexcept;
  static const string& JuuZou() noexcept;
  static const string& JuuGen() noexcept;

};
