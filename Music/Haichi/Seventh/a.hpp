// c:/Users/user/Documents/Programming/Music/HaiChi/Seventh/a.hpp

#pragma once
#include "../a.hpp"

#include "../../WaOn/YonWaOn/Seventh/a.hpp"

class HaiChiOfSeventh :
  public Seventh , public HaiChi
{

private:
  bool m_valid;
  uint m_goodness;

public:
  inline HaiChiOfSeventh( const Chou& N , const KaiMei& n , const uint& bas_num , const uint& bas_octave , const uint& ten_num , const uint& ten_octave , const uint& alt_num , const uint& alt_octave , const uint& sop_num , const uint& sop_octave ) noexcept;

  void SetValidity( const Chou& N , const KaiMei& n , const uint& bas_num , const uint& bas_octave , const uint& ten_num , const uint& ten_octave , const uint& alt_num , const uint& alt_octave , const uint& sop_num , const uint& sop_octave ) noexcept;

  inline const OnMei& GetOnMei( const uint& i ) const noexcept;

};

