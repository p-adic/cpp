// c:/Users/user/Documents/Programming/Music/Haichi/SanWaOn/KyouWaOn/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Chou/a.hpp"

class KyouWaOn :
  public SanWaOn
{

public:
  inline KyouWaOn( const Chou& N , const KaiMei& n ) noexcept;

  inline bool IsValid() const noexcept;
  
  inline const OnMei& GetNeOn() const noexcept;
  inline const OnMei& GetDaiSanOn() const noexcept;
  inline const OnMei& GetDaiGoOn() const noexcept;

};

inline bool operator==( const KyouWaOn& H1 , const KyouWaOn& H2 ) noexcept;
inline bool operator!=( const KyouWaOn& H1 , const KyouWaOn& H2 ) noexcept;
