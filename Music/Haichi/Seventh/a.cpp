// c:/Users/user/Documents/Programming/Music/Haichi/Seventh/a.cpp


#include "../../Header.hpp"
#include "a_Body.hpp"

void HaichiOfSeventh::SetValidity( const Chou& N , const KaiMei& n , const uint& bas_num , const uint& bas_octave , const uint& ten_num , const uint& ten_octave , const uint& alt_num , const uint& alt_octave , const uint& sop_num , const uint& sop_octave ) noexcept
{

  if( bas_num == 5 ){

    return;

  }

  if( ! IsNaturallyOrdered() ){

    return;

  }

  const uint num = GetNumberOfOnMei();

  if( num != 4 ){

    if( num != 3 ){

      return;

    }

    if( CheckHasDaiGoOn( bas_num , ten_num , alt_num , sop_num ) ){

      return;

    }
    
  }

  if( CheckValidKaiMei( N , n ) ){

    return;

  }

  if( CheckHasDoubleDaiSanOn( bas_num , ten_num , alt_num , sop_num ) ){

    if( n == KaiMei::V() ){

      return;

    }

    m_goodness = 3;
    m_valid = true;
    return;
      
  }

  m_goodness = 4;
  m_valid = true;
  return;

}

