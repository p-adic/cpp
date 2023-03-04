// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Dimension/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../../Error/IllegalInput/a_Body.hpp"

dim& dim::operator=( const dim& d ) noexcept
{

  m_d = d.m_d;
  m_is_infty = d.m_is_infty;
  return *this;

}

dim& dim::operator+=( const dim& d ) noexcept
{

  if( m_is_infty || d.m_is_infty ){
    
    *this = Generate_infty();
	  
  } else {
	
    m_d += d.m_d;
  
  }
  
  return *this;

}

dim& dim::operator-=( const dim& d )
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

dim& dim::operator*=( const dim& d )
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

      m_d *= d.m_d;
      
    }

  }

  return *this;

}

dim& dim::operator/=( const dim& d )
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

dim& dim::operator%=( const dim& d )
{

  if( m_is_infty || d.m_d == 0 || d.m_is_infty ){
	
    ERR_INPUT( *this , d );

  }

  m_d %= d.m_d;
  return *this;
  
}

const INT_TYPE_FOR_DIM& dim::Get() const
{

  if( m_is_infty ){

    ERR_INPUT( *this );
    
  }
  
  return m_d;
  
}

bool operator<=( const dim& d_1 , const dim& d_2 ) noexcept
{

  if( d_2.IsInfty() ){

    return true;

  }

  if( d_1.IsInfty() ){
    
    return false;

  }

  return d_1.Get() <= d_2.Get();

}

dim operator+( const dim& d_1 , const dim& d_2 ) noexcept
{

  dim d = d_1;
  d += d_2;
  return d;

}

dim operator-( const dim& d_1 , const dim& d_2 )
{

  dim d = d_1;
  d -= d_2;
  return d;

}

dim operator*( const dim& d_1 , const dim& d_2 )
{

  dim d = d_1;
  d *= d_2;
  return d;

}

dim operator/( const dim& d_1 , const dim& d_2 )
{

  dim d = d_1;
  d /= d_2;
  return d;

}

dim operator%( const dim& d_1 , const dim& d_2 )
{

  dim d = d_1;
  d %= d_2;
  return d;

}
