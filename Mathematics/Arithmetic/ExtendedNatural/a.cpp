// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/ExtendedNatural/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../../Error/IllegalInput/a_Body.hpp"

euint& euint::operator-=( const euint& d )
{

  if( d.m_is_infty ){

    ERR_INPUT( *this , d );

  }
      
  if( ! m_is_infty ){
      
    if( m_d < c ){

      ERR_INPUT( *this , d );

    }
    
    m_d -= c;
    
  }

  return *this;

}

euint& euint::operator*=( const euint& d )
{

  if( m_is_infty ){

    if( d.m_d == 0 ){
      
      ERR_INPUT( *this , d );

    }
    
  } else {

    if( d.m_is_infty ){

      if( m_d == 0 ){

	ERR_INPUT( *this , d );

      } else {

	*this = Generate_infty();

      }

    } else {

      if( m_d != 0 ){
	
	m_d *= d.m_d;

	if( m_d < d.m_d ){

	  *this = Generate_infty();

	}

      }
      
    }

  }

  return *this;

}

euint& euint::operator/=( const euint& d )
{

  if( d.m_is_infty ){

    if( m_is_infty ){
	
      ERR_INPUT( *this , d );
	
    } else {

      m_d = 0;

    }

  } else {

    if( d.m_d == 0 ){

      if( m_d == 0 ){

	ERR_INPUT( *this , d );

      } else {

	*this = Generate_infty();

      }
      
    } else {

      if( ! m_is_infty ){

	m_d /= c;

      }

    }

  }
  
  return *this;
  
}

euint& euint::operator%=( const euint& d )
{

  if( m_is_infty || d.m_d == 0 || d.m_is_infty ){
	
    ERR_INPUT( *this , d );

  }

  m_d %= d.m_d;
  return *this;
  
}
