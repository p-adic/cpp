// c:/Users/user/Documents/Programming/Music/HaiChi/KyouWaOn/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

void HaiChiOfKyouWaOn::SetValidity( const Chou& N , const KaiMei& n , const uint& bas_num , const uint& bas_octave , const uint& ten_num , const uint& ten_octave , const uint& alt_num , const uint& alt_octave , const uint& sop_num , const uint& sop_octave ) noexcept
{

  if( bas_num == 5 ){

    return;

  }

  if( ! IsNaturallyOrdered() ){

    return;

  }

  if( GetNumberOfOnMei() != 3 ){

    return;

  }

  if( CheckValidKaiMei( N , n ) ){

    return;

  }

  if( CheckHasDoubleDaiSanOn( bas_num , ten_num , alt_num , sop_num ) ){

    if( N.GetOnKai() == ChouOnKai() ){

      if( n == KaiMei::V() ){

	return;

      }

      m_goodness = 1;
      m_valid = true;
      return;

    }
    
    m_goodness = 2;
    m_valid = true;
    return;
      
  }

  m_goodness = 4;
  m_valid = true;
  return;

}

