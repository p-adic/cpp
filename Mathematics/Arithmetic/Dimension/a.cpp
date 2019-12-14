// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Dimension/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../../Error/IllegalImput/a_Body.hpp"

const uint dim::m_infty = -1;

dim& dim::operator=( const dim& d )
{
  
  m_d = d.m_d;
  return *this;

}

dim& dim::operator+=( const dim& d )
{

  const uint& c = d.m_d;
  
  if( m_d == m_infty || c == m_infty ){
	  
    m_d = m_infty;
	  
  } else {
	
    m_d += c;
  
  }
  
  return *this;

}

dim& dim::operator-=( const dim& d )
{

  const uint& c = d.m_d;

  if( m_d < c || c == m_infty ){

    ERR_IMPUT( *this , d );

  }
      
  if( m_d != m_infty ){
      
    m_d -= c;
    
  }

  return *this;

}

dim& dim::operator*=( const dim& d )
{

  const uint& c = d.m_d;

  if( m_d == m_infty ){

    if( c == 0 ){
      
      ERR_IMPUT( *this , d );

    }
    
  } else {

    if( c == m_infty ){

      if( m_d == 0 ){

	ERR_IMPUT( *this , d );

      } else {

	m_d = m_infty;

      }

    } else {

      m_d *= c;
      
    }

  }

  return *this;

}

dim& dim::operator/=( const dim& d )
{

  const uint& c = d.m_d;
  
  if( c == m_infty ){

    if( m_d == m_infty ){
	
      ERR_IMPUT( *this , d );
	
    } else {

      m_d = 0;

    }

  } else {

    if( c == 0 ){

      if( m_d == 0 ){

	ERR_IMPUT( *this , d );

      } else {

	m_d = m_infty;

      }
      
    } else {

      if( m_d != m_infty ){

	m_d /= c;

      }

    }

  }
  
  return *this;
  
}

dim& dim::operator%=( const dim& d )
{

  const uint& c = d.m_d;
  
  if( m_d == m_infty || c == 0 || c == m_infty ){
	
    ERR_IMPUT( *this , d );

  }

  m_d %= c;
  
  return *this;
  
}

const uint& dim::Get() const
{

  if( IsInfty() ){

    ERR_IMPUT( *this );
    
  }
  
  return m_d;
  
}

string dim::Display() const
{

  if( m_d == m_infty ){

    return "\\infty";

  } else {

    return to_string( m_d );
    
  }

}

const dim* const dim::Generate_infty()
{

  return GLOBAL_CONSTANT( dim , "infty" , m_infty );

}

bool operator<=( const dim& d_1 , const dim& d_2 )
{

  if( CheckInfty( d_2 ) ){

    return true;

  }

  if( CheckInfty( d_1 ) ){
    
    return false;

  }

  return to_int( d_1 )<= to_int( d_2 );

}

dim operator+( const dim& d_1 , const dim& d_2 )
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

dim Sum( const list<dim>& a )
{

  dim d = 0;
  
  for( list<dim>::const_iterator itr = a.begin() ; itr != a.end() ; itr++ ){

    if( *itr == *infty() ){

      return *infty();

    } else {
	
      d += *itr;

    }

  }

  return d;

}

dim Prod( const list<dim>& a )
{

  dim d = 1;
  
  for( list<dim>::const_iterator itr = a.begin() , end = a.end() ; itr != end ; itr++ ){

    d *= *itr;

  }
  
  return d; 

}
