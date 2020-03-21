// c:/Users/user/Documents/Programming/Music/WaOn/SanWaOn/a.hpp

#pragma once
#include "../../OnMei/a.hpp"

class SanWaOn
{

private:
  OnMei m_N0;
  OnMei m_N1;
  OnMei m_N2;

public:
  inline SanWaOn( const OnMei& N0 , const OnMei& N1 , const OnMei& N2 ) noexcept;

  bool IsValid() const noexcept;
  
  inline string Display() const noexcept;
  const OnMei& GetOnMei( const uint& i ) const noexcept;

};

bool operator==( const SanWaOn& H1 , const SanWaOn& H2 ) noexcept;
inline bool operator!=( const SanWaOn& H1 , const SanWaOn& H2 ) noexcept;
