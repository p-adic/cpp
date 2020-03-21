// c:/Users/user/Documents/Programming/Music/GoodWaOn/YonWaOn/a.hpp

#pragma once
#include "../../OnMei/a.hpp"

class YonWaOn
{

private:
  OnMei m_N0;
  OnMei m_N1;
  OnMei m_N2;
  OnMei m_N3;

public:
  inline YonWaOn( const OnMei& N0 , const OnMei& N1 , const OnMei& N2 , const OnMei& N3 ) noexcept;

  bool IsValid() const noexcept;
  
  inline string Display() const noexcept;
  const OnMei& GetOnMei( const uint& i ) const noexcept;

};

bool operator==( const YonWaOn& H1 , const YonWaOn& H2 ) noexcept;
inline bool operator!=( const YonWaOn& H1 , const YonWaOn& H2 ) noexcept;
