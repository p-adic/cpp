// c:/Users/user/Documents/Programming/Music/Haichi/Seventh/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "../../WaOn/YonWaOn/Seventh/a_Body.hpp"
#include "../../../Mathematics/Function/a.hpp"

inline HaichiOfSeventh::HaichiOfSeventh( const Chou& N , const KaiMei& n , const uint& bas_num , const uint& bas_octave , const uint& ten_num , const uint& ten_octave , const uint& alt_num , const uint& alt_octave , const uint& sop_num , const uint& sop_octave ) noexcept :
  Seventh( N , n ) ,
  Haichi( GetOnMei( bas_num ) , bas_octave , GetOnMei( ten_num ) , ten_octave , GetOnMei( alt_num ) , alt_octave , GetOnMei( sop_num ) , sop_octave ) ,
  m_valid( false ) ,
  m_goodness( 0 )
{

  SetValidity( N , n , bas_num , bas_octave , ten_num , ten_octave , alt_num , alt_octave , sop_num , sop_octave );
  
}

inline const OnMei& HaichiOfSeventh::GetOnMei( const uint& i ) const noexcept
{

  const ConstMemberFunctionPointerType<const OnMei&,Seventh> table[4] = { GetNeOn , GetDaiSanOn , GetDaiGoOn , GetDaiNanaOn };
  return ( this->*( table[ i % 4 ] ) )();
  
}

