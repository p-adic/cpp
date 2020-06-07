// c:/Users/user/Documents/Programming/Music/WaOn/YonWaOn/Seventh/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Chou/a.hpp"

class Seventh :
  public YonWaOn
{

public:
  inline Seventh( const Chou& N , const KaiMei& n ) noexcept;

  inline const OnMei& GetNeOn() const noexcept;
  inline const OnMei& GetDaiSanOn() const noexcept;
  inline const OnMei& GetDaiGoOn() const noexcept;
  inline const OnMei& GetDaiNanaOn() const noexcept;

};

inline bool operator==( const Seventh& H1 , const Seventh& H2 ) noexcept;
inline bool operator!=( const Seventh& H1 , const Seventh& H2 ) noexcept;
