// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/OnDo/a.hpp

#pragma once
#include "../a.hpp"
#include "SetTouJi/a.hpp"

#include "a_Alias.hpp"

class OnDo
{

private:
  const SetTouJiOfOnDo& m_settouji;
  const DoSuu m_dosuu;
  const Mod<7> m_dosuu_mod;

public:
  inline OnDo( const Pitch& P1 , const Pitch& P2 ) noexcept;

  bool CheckKyouWaOnTei() const noexcept;
  bool CheckKyouWaOnTeiNonBottom() const noexcept;

  inline const SetTouJiOfOnDo& GetSetTouJi() const noexcept;
  inline const DoSuu& GetDoSuu() const noexcept;
  inline const Mod<7>& GetDoSuuMod() const noexcept;
  
  inline string Display() const noexcept;
  
private:
  inline OnDo( const int& D , const int& d ) noexcept;
  inline OnDo( const int& D , const int& d , const int& sign ) noexcept;
  inline OnDo( const ZeroIndexedDoSuu& D , const PitchDifference& d ) noexcept;

  inline static int PitchToAbsoluteDoSuu( const Pitch& P ) noexcept;
  inline static int ComputeSignedZeroIndexedDoSuu( const Pitch& P1 , const Pitch& P2 ) noexcept;
  inline static int ComputeSignedPitchDifference( const Pitch& P1 , const Pitch& P2 ) noexcept;

};

inline bool operator==( const OnDo& D1 , const OnDo& D2 ) noexcept;
inline bool operator!=( const OnDo& D1 , const OnDo& D2 ) noexcept;
