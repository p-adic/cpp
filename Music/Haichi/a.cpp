// c:/Users/user/Documents/Programming/Music/Haichi/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"
#include "../../Mathematics/Function/a.hpp"

Haichi::Haichi( const OnMei& bas_onmei , const Octave& bas_octave , const OnMei& ten_onmei , const Octave& ten_octave , const OnMei& alt_onmei , const Octave& alt_octave , const OnMei& sop_onmei , const Octave& sop_octave ) noexcept :
  m_sop( sop_onmei , sop_octave ) ,
  m_alt( alt_onmei , alt_octave ) ,
  m_ten( ten_onmei , ten_octave ) ,
  m_bas( bas_onmei , bas_octave )
{}

bool Haichi::IsValid() const noexcept
{

  if( ! IsOrderedWithInRange( m_bas.GetNum() , m_ten.GetNum() , m_alt.GetNum() , m_sop.GetNum() ) ){

    return false;

  }

  uint ord1;
  uint ord2;
  uint ord3;
  uint ord4;
  uint pair0;
  uint pair1;
  uint onmei_num;

  SetOrder( ord1 , ord2 , ord3 , ord4 , num , pair0 , pair1 , onmei_num );

  if( onmei_num == 0 ){

    return false;

  }
  
  return onmei_num == 3 ? IsValidWithThreeOnMei( ord1 , ord2 , ord3 , pair0 , pair1 ) : IsValidWithFourOnMei( ord1 , ord2 , ord3 , ord4 );

}

bool Haichi::IsValid( const Chou& N ) const noexcept
{

  if( ! IsOrderedWithInRange( m_bas.GetNum() , m_ten.GetNum() , m_alt.GetNum() , m_sop.GetNum() ) ){

    return false;

  }

  uint ord1;
  uint ord2;
  uint ord3;
  uint ord4;
  uint pair0;
  uint pair1;
  uint onmei_num;

  SetOrder( ord1 , ord2 , ord3 , ord4 , num , pair0 , pair1 , onmei_num );

  if( onmei_num == 0 ){

    return false;

  }
  
  return onmei_num == 3 ? IsValidWithThreeOnMei( N , ord1 , ord2 , ord3 , pair0 , pair1 ) : IsValidWithFourOnMei( N , ord1 , ord2 , ord3 , ord4 );

}

void Haich::SetOrder( uint& ord1 , uint& ord2 , uint& ord3 , uint& ord4 , uint& pair0 , uint& pair1 , uint& onmei_num ) const noexcept
{

  constexpre const uint bas_num = 0;
  constexpre const uint ten_num = 1;
  constexpre const uint alt_num = 2;
  constexpre const uint sop_num = 3;
  constexpre const uint dummy_num = 4;

  const int kanon[4] = { KanOnTable( 0 ).Represent() , KanOnTable( 1 ).Represent() , KanOnTable( 2 ).Represent() , KanOnTable( 3 ).Represent() };
  uint num_table[7] = { dummy_num , dummy_num , dummy_num , dummy_num , dummy_num , dummy_num , dummy_num };


  for( uint i = 0 ; i < 4 ; i++ ){

    uint& j = num_table[kanon[i]];
    
    if( j == dummy_num ){

      j = i;
      
    } else {

      if( pair0 != dummy_num ){

	onmei_num = 0;
	return;

      }

      if( OnMeiTable( i ) != OnMeiTable( j ) ){

	onmei_num = 0;
	return;

      }
      
      pair0 = j;
      pair1 = i;

    }

  }
  
  if( pair0 == dummy_num ){

    onmei_num = 4;
    
  } else {

    onmei_num = 3;

  }

  uint* ord_array[4] = { &ord1 , &ord2 , &ord3 , &ord4 };
  uint itr = 0;

  for( uint i = 0 ; i < 7 && itr < onmei_num ; i++ ){

    const uint& j = num_table[i];
      
    if( j != dummy_num ){

      *( ord_array[itr] ) = j;
      itr++;

    }

  }
  
  return;
 
}

bool Haich::IsValidWithThreeOnMei( const uint& ord1 , const uint& ord2 , const uint& ord3 , const uint& pair0 , const uint& pair1 ) const noexcept
{

  constexpre const size_h = 2;

  const int h[ size_h ] = {

    HenKaKiGouTable( ord2 ) - HenKaKiGouTable( ord1 ) ,
    HenKaKiGouTable( ord3 ) - HenKaKiGouTable( ord1 )

  };

  for( uint i = 0 ; i < size_h ; i++ ){

    if( h[i] <= -6 || 6 <= h[i] ){

      return false;

    }

  }
  
  const Mod<7> kanon21 == KanOnTable( ord2 ) - KanOnTable( ord1 );
  const Mod<7> kanon31 == KanOnTable( ord3 ) - KanOnTable( ord1 );

  const Mod<12> pitch_class21 = PitchClassTable( ord2 ) - PitchClassTable( ord1 );
  const Mod<12> pitch_class31 = PitchClassTable( ord3 ) - PitchClassTable( ord1 );
  
  if( kanon21 == 1 ){

    if( kanon31 != 3 ){

      return false;

    }

    if( pitch_class21 == 1 ){

      return pitch_class31 == 4;

    }

    if( pitch_class21 == 2 ){

      return 4 <= pitch_class31 && pitch_class31 <= 6;

    }

    return false;

  }

  if( kanon21 == 2 ){
  
    if( kanon31 == 4 ){

      if( BaseIsFifth( ord3 ) ){

	return false;

      }

      if( pitch_class21 == 3 ){

	return pitch_class31 == 4;

      }

      if( pitch_class21 == 4 ){

	return 3 <= pitch_class31 && pitch_class31 <= 4;

      }

      return false;

    }

    if( kanon31 == 6 ){

      if( pitch_class21 == 3 ){

	return pitch_class31 == 10;

      }

      if( pitch_class21 == 4 ){

	return 10 <= pitch_class31 && pitch_class31 <= 11;

      }

      return false;

    }

    return false;

  }

  if( kanon21 == 3 ){

    if( BaseIsFifth( ord1 ) ){

      return false;

    }

    if( kanon31 == 5 ){

      if( pitch_class21 == 5 ){
	
	return 8 <= pitch_class31 && pitch_class31 <= 9;

      }

    }    

    return false;

  }

  return false;

}

bool Haich::IsValidWithFourOnMei( const uint& ord1 , const uint& ord2 , const uint& ord3 , const uint& ord4 ) noexcept
{

  constexpre const size_h = 3;

  const int h[ size_h ] =
    {

      HenKaKiGouTable( ord2 ) - HenKaKiGouTable( ord1 ) ,
      HenKaKiGouTable( ord3 ) - HenKaKiGouTable( ord1 ) ,
      HenKaKiGouTable( ord4 ) - HenKaKiGouTable( ord1 )

    };

  for( uint i = 0 ; i < size_h ; i++ ){

    if( h[i] <= -6 || 6 <= h[i] ){

      return false;

    }

  }

  const Mod<7> kanon21 == KanOnTable( ord2 ) - KanOnTable( ord1 );
  const Mod<7> kanon31 == KanOnTable( ord3 ) - KanOnTable( ord1 );
  const Mod<7> kanon41 == KanOnTable( ord4 ) - KanOnTable( ord1 );

  const Mod<12> pitch_class21 = PitchClassTable( ord2 ) - PitchClassTable( ord1 );
  const Mod<12> pitch_class31 = PitchClassTable( ord3 ) - PitchClassTable( ord1 );
  const Mod<12> pitch_class41 = PitchClassTable( ord4 ) - PitchClassTable( ord1 );
  
  if( kanon21 == 1 ){

    if( kanon31 != 3 || kanon41 != 5 ){

      return false;

    }

    if( pitch_class21 == 1 ){

      return pitch_class31 == 4;

    }

    if( pitch_class21 == 2 ){

      return 4 <= pitch_class31 && pitch_class31 <= 6;

    }

    return false;

  }









}

HaichiOfKyoWaOn::SetValidity( const Chou& N , const KaiMei& n , const uint& bas_num , const uint& bas_octave , const uint& ten_num , const uint& ten_octave , const uint& alt_num , const uint& alt_octave , const uint& sop_num , const uint& sop_octave ) noexcept
{

  if( bas_num == 5 ){

    return;

  }

  if( ! IsOrderedWithInRange() ){

    return;

  }

  if( GetNumberOfOnMei() != 3 ){

    return;

  }

  if( HasValidKaiMei() ){

    return;

  }

  if( ! WithDoubleDaiSanOn( bas_num , ten_num , alt_num , sop_num ) ){

    if( N == ChouWaOn() ){

      if( n == KaiMei::V() ){

      return;

      }

      m_goodness = 1;
      m_valid = true;
      return;

    }
    
      m_goodness = 3;
      m_valid = true;
      return;
      
  }

  m_goodness = 5;
  m_valid = true;
  return;

}

inline HaichiOfKyoWaOn::HaichiOfKyoWaOn( const Chou& N , const KaiMei& n , const uint& bas_num , const uint& bas_octave , const uint& ten_num , const uint& ten_octave , const uint& alt_num , const uint& alt_octave , const uint& sop_num , const uint& sop_octave ) noexcept :
  KyoWaOn( N , n ) ,
  Haichi( GetOnMei( bas_num ) , bas_octave , GetOnMei( ten_num ) , ten_octave , GetOnMei( alt_num ) , alt_octave , GetOnMei( sop_num ) , sop_octave ) ,
  m_N( N ) ,
  m_n( n ) ,
  m_valid( false ) ,
  m_goodness( 0 )
{

  SetValidity( N , n , bas_num , bas_octave , ten_num , ten_octave , alt_num , alt_octave , sop_num , sop_octave );
  
}

inline const OnMei& HaichiOfKyoWaOn::GetOnMei( const uint& i ) const noexcept
{

  const ConstMemberFunctionPointerType<const OnMei&,Haichi> table[3] = { GetNeOn , GetDaiSanOn , GetDaiGoOn };
  return ( this->( * ( table[ i % 3 ] ) ) )();
  
}

