// c:/Users/user/Documents/Programming/Music/WaOn/YonWaOn/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

bool YonWaOn::IsValid() const noexcept
{

  if( m_N0 == m_N1 ){

    return false;

  }

  if( m_N1 == m_N2 ){

    return false;

  }

  if( m_N2 == m_N3 ){

    return false;

  }

  if( m_N3 == m_N0 ){

    return false;

  }

  if( m_N0 == m_N2 ){

    return false;

  }

  return m_N1 != m_N3;

}

const OnMei& YonWaOn::GetOnMei( const uint& i ) const noexcept
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

  if( i == 3 ){

    return m_N3;

  }

  return GetOnMei( i % 4 );

}

bool operator==( const YonWaOn& H1 , const YonWaOn& H2 ) noexcept
{

  const OnMei& N10 = H1.GetOnMei( 0 );
  const OnMei& N11 = H1.GetOnMei( 1 );
  const OnMei& N12 = H1.GetOnMei( 2 );
  const OnMei& N13 = H1.GetOnMei( 3 );
  const OnMei& N20 = H2.GetOnMei( 0 );
  const OnMei& N21 = H2.GetOnMei( 1 );
  const OnMei& N22 = H2.GetOnMei( 2 );
  const OnMei& N23 = H2.GetOnMei( 3 );
  const OnMei* pN2i0[4] = { &N20 , &N21 , &N22 , &N23 };

  for( uint i0 = 0 ; i0 < 4 ; i0++ ){

    if( N10 == *( pN2i0[i0] ) ){

      const OnMei* pN2i1[3] =
	{
	  
	  pN2i0[ ( i0 + 1 ) % 4 ] ,
	  pN2i0[ ( i0 + 2 ) % 4 ] ,
	  pN2i0[ ( i0 + 3 ) % 4 ]

	};
      
      for( uint i1 = 0 ; i1 < 3 ; i1++ ){

	if( N11 == *( pN2i1[i1] ) ){

	  const OnMei* pN2i2[2] =
	    {
	  
	      pN2i1[ ( i0 + 1 ) % 3 ] ,
	      pN2i1[ ( i0 + 2 ) % 3 ]

	    };
      
	  for( uint i2 = 0 ; i2 < 2 ; i2++ ){

	    if( N12 == *( pN2i2[i2] ) ){

	      if( N13 == *( pN2i2[ ( i2 + 1 ) % 2 ] ) ){
		
		return true;

	      }

	    }

	  }

	}

      }

    }

  }

  return false;

}
