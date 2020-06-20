// c:/Users/user/Documents/Programming/Music/HaiChi/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"


uint HaiChi::GetNumberOfOnMei() const noexcept
{

  const Pitch* table[4];
  uint size = 0;
  
  for( uint i = 1 ; i < 4 ; i++ ){

    const Pitch& P = GetPitch( i );
    bool b = true;
      
    for( uint j = 0 ; j < size && b ; j++ ){

      if( *( table[j] ) == P ){

	b = false;

      }

    }

    if( b ){

      table[ size ] = &P;
      size++;
      
    }

  }

  return size;

}

bool HaiChi::CheckValidKaiMei( const Chou& N , const KaiMei& n ) noexcept
{

  const OnKai& s = N.GetOnKai();

  if( s == ChouOnKai() ){

    return true;

  }

  if( s == WaSeiTekiTanOnKai() ){

    return n == KaiMei::V();

  }
  
  if( s == ShiZenTanOnKai() ){

    return n != KaiMei::V();

  }


  ERR_CODE;  
  return false;

}


bool operator==( const HaiChi& C1 , const HaiChi& C2 ) noexcept
{

  for( uint i = 0 ; i < 4 ; i++ ){

    if( C1.GetPitch( i ) != C2.GetPitch( i ) ){

      return false;

    }
    
  }

  return true;

}
