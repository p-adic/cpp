// c:/Users/user/Documents/Programming/Music/Haichi/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"


uint Haichi::GetNumberOfOnMei() const noexcept
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

bool Haichi::CheckValidKaiMei( const Chou& N , const KaiMei& n ) noexcept
{

  if( N == ChouOnKai() ){

    return true;

  }

  if( N == WaSeiTekiTanOnKai() ){

    return n == KaiMei::V();

  }
  
  if( N == ShiZenTanOnKai() ){

    return n != KaiMei::V();

  }


  ERR_CODE;  
  return false;

}


bool operator==( const Haichi& C1 , const Haichi& C2 ) noexcept
{

  for( uint i = 0 ; i < 4 ; i++ ){

    if( C1.GetPitch( i ) != C2.GetPitch( i ) ){

      return false;

    }
    
  }

  return true;

}
