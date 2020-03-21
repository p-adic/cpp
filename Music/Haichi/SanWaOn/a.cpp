// c:/Users/user/Documents/Programming/Music/Haichi/SanWaOn/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

bool SanWaOn::IsValid() const noexcept
{

  if( m_N0 == m_N1 ){

    return false;

  }

  if( m_N1 == m_N2 ){

    return false;

  }

  return m_N2 != m_N1;

}

const OnMei& SanWaOn::GetOnMei( const uint& i ) const noexcept
{

  if( i == 0 ){

    return m_N0;

  }

  if( i == 1 ){

    return m_N1;

  }

  if( i == 2 ){

    return m_N2;

  }

  return GetOnMei( i % 3 );

}

bool operator==( const SanWaOn& H1 , const SanWaOn& H2 ) noexcept
{

  const OnMei& N10 = H1.GetOnMei( 0 );
  const OnMei& N11 = H1.GetOnMei( 1 );
  const OnMei& N12 = H1.GetOnMei( 2 );
  const OnMei& N20 = H2.GetOnMei( 0 );
  const OnMei& N21 = H2.GetOnMei( 1 );
  const OnMei& N22 = H2.GetOnMei( 2 );
  const OnMei* pN2i[3] = { &N20 , &N21 , &N22 };

  for( uint i = 0 ; i < 3 ; i++ ){

    if( N10 == *( pN2i[i] ) ){

      for( uint j = 1 ; j < 3 ; j++ ){

	if( N11 == *( pN2i[ ( i + j ) % 3 ] ) ){

	  if( N12 == *( pN2i[ ( i + j + 1 ) % 3 ] ) ){

	    return true;

	  }

	}

      }

    }

  }

  return false;

}
