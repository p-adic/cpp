// Mod/a_Body.hpp

#pragma once
#include "a.hpp"

template <int M>
int Mod<M>::Residue( const int& n ) noexcept
{

  if( M == 0 ){

    return 0;

  }

  int M_copy;

  if( 0 <= M ){

    M_copy = M;

  } else {

    M_copy = -M;

  }

  if( n < 0 ){

    return Residue( n + M_copy );

  }
  
  if( M_copy <= n ){

    return Residue( n - M_copy );
    
  }

  return n;

}

template <int M>
uint Mod<M>::Residue( const uint& n ) noexcept
{

  if( M == 0 ){

    return 0;

  }

  uint M_copy;

  if( 0 <= M ){

    M_copy = (uint)M;
    
  } else {

    M_copy = (uint)( -M );

  }  

  if( M_copy <= n ){

    return Residue( n - M );

  }

  return n;
  
}

template <int M>
Mod<M>::Mod() noexcept : m_n( 0 ) , m_inv( M ){}

template <int M>
Mod<M>::Mod( const int& n ) noexcept : m_n( Residue( n ) ) , m_inv( 0 ){}

template <int M>
Mod<M>::Mod( const uint& n ) noexcept : Mod( (int)Residue( n ) ){}

template <int M>
Mod<M>::Mod( const Mod<M>& n ) noexcept : m_n( n.m_n ) , m_inv( 0 ){}

template <int M>
Mod<M>& Mod<M>::operator=( const int& n ) noexcept
{

  m_n = Residue( n );
  m_inv = 0;
  return *this;

}

template <int M>
Mod<M>& Mod<M>::operator=( const uint& n ) noexcept
{

  m_n = (int)Residue( n );
  m_inv = 0;
  return *this;

}

template <int M>
Mod<M>& Mod<M>::operator=( const Mod<M>& n ) noexcept
{

  m_n = n.m_n;
  m_inv = n.m_inv;
  return *this;

}

template <int M>
Mod<M>& Mod<M>::operator+=( const int& n ) noexcept
{

  m_n = Residue( m_n + n );
  m_inv = 0;
  return *this;

}

template <int M>
Mod<M>& Mod<M>::operator+=( const uint& n ) noexcept
{

  m_n = Residue( m_n + (int)n );
  m_inv = 0;
  return *this;

}

template <int M>
Mod<M>& Mod<M>::operator+=( const Mod<M>& n ) noexcept
{

  m_n = Residue( m_n + n.m_n );
  m_inv = 0;
  return *this;

}

template <int M>
Mod<M>& Mod<M>::operator-=( const int& n ) noexcept
{

  m_n = Residue( m_n - n );
  m_inv = 0;
  return *this;

}

template <int M>
Mod<M>& Mod<M>::operator-=( const uint& n ) noexcept
{

  m_n = Residue( m_n - (int)n );
  m_inv = 0;
  return *this;

}

template <int M>
Mod<M>& Mod<M>::operator-=( const Mod<M>& n ) noexcept
{

  m_n = Residue( m_n - n.m_n );
  return *this;
  
}

template <int M>
Mod<M>& Mod<M>::operator*=( const int& n ) noexcept
{

  m_n = Residue( m_n * n );
  m_inv = 0;
  return *this;

}

template <int M>
Mod<M>& Mod<M>::operator*=( const uint& n ) noexcept
{

  m_n = Residue( m_n * (int)n );
  m_inv = 0;
  return *this;

}

template <int M>
Mod<M>& Mod<M>::operator*=( const Mod<M>& n ) noexcept
{

  m_n = Residue( m_n * n.m_n );
  m_inv = Residue( m_inv * n.m_inv );
  return *this;

}

// âºëzä÷êîÇ»ÇÃÇ≈inlineéwíËÇµÇ»Ç¢ÅB
template <int M>
Mod<M>& Mod<M>::operator/=( const int& n )
{

  return operator/=( Mod<M>( n ) );

}

template <int M>
Mod<M>& Mod<M>::operator/=( const uint& n )
{

  return operator/=( Mod<M>( n ) );

}

template <int M>
Mod<M>& Mod<M>::operator/=( const Mod<M>& n )
{
  
  return operator*=( Inverse( n ) );
  
}

template <int M>
Mod<M>& Mod<M>::operator%=( const int& n )
{

  m_n %= Residue( n );
  m_inv = 0;
  return *this;

}

template <int M>
Mod<M>& Mod<M>::operator%=( const uint& n )
{

  m_n %= (int)Residue( n );
  m_inv = 0;
  return *this;

}

template <int M>
Mod<M>& Mod<M>::operator%=( const Mod<M>& n )
{

  m_n %= n.m_n;
  m_inv = 0;
  return *this;

}

template <int M> inline const int& Mod<M>::Represent() const noexcept { return m_n; }

template <int M>
Mod<M>& Mod<M>::Power( const int& p ) noexcept
{

  int p_copy;

  if( 0 <= p ){

    p_copy = p;

  } else {

    p_copy = -p;
    Invert();

  }

  int m_n_copy = m_n;
  int m_inv_copy = m_inv;
  m_n = 1;
  m_inv = 1;

  for( int m = 0 ; m < p_copy ; m++ ){

    m_n *= m_n_copy;
    m_inv *= m_inv_copy;

  }

  return *this;

}

template <int M>
void Mod<M>::Invert() noexcept
{

  if( CheckInvertible() ){

    int i = m_inv;
    m_inv = m_n;
    m_n = i;

  } else {

    m_n = 0;

  }

  return;
  
}

template <int M>
bool Mod<M>::CheckInvertible() noexcept
{

  if( m_inv == 0 ){

    for( int i = 1 ; i < M ; i++ ){

      if( Residue( m_n * i ) == 1 ){

	m_inv = i;
	return true;
      
      }

    }

    m_inv = M;

  }

  return m_inv != M;
  
}

template <int M> inline bool Mod<M>::IsSmallerThan( const int& n ) const noexcept { return m_n < Residue( n ); }
template <int M> inline bool Mod<M>::IsBiggerThan( const int& n ) const noexcept { return m_n > Residue( n ); }

template <int M> inline bool operator==( const Mod<M>& n0 , const int& n1 ) noexcept { return !( n0 < n1 || n0 > n1 ); }
template <int M> inline bool operator==( const int& n0 , const Mod<M>& n1 ) noexcept { return !( n0 < n1 || n0 > n1 ); }
template <int M> inline bool operator==( const Mod<M>& n0 , const uint& n1 ) noexcept { return !( n0 < n1 || n0 > n1 ); }
template <int M> inline bool operator==( const uint& n0 , const Mod<M>& n1 ) noexcept { return !( n0 < n1 || n0 > n1 ); }
template <int M> inline bool operator==( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return !( n0 < n1 || n0 > n1 ); }

template <int M> inline bool operator!=( const Mod<M>& n0 , const int& n1 ) noexcept { return !( n0 == n1 ); }
template <int M> inline bool operator!=( const int& n0 , const Mod<M>& n1 ) noexcept { return !( n0 == n1 ); }
template <int M> inline bool operator!=( const Mod<M>& n0 , const uint& n1 ) noexcept { return !( n0 == n1 ); }
template <int M> inline bool operator!=( const uint& n0 , const Mod<M>& n1 ) noexcept { return !( n0 == n1 ); }
template <int M> inline bool operator!=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return !( n0 == n1 ); }

template <int M> inline bool operator<( const Mod<M>& n0 , const int& n1 ) noexcept { return n0.IsSmallerThan( n1 ); }
template <int M> inline bool operator<( const int& n0 , const Mod<M>& n1 ) noexcept { return n1.IsBiggerThan( n0 ); }
template <int M> inline bool operator<( const Mod<M>& n0 , const uint& n1 ) noexcept { return n0.IsSmallerThan( (int)n1 ); }
template <int M> inline bool operator<( const uint& n0 , const Mod<M>& n1 ) noexcept { return n1.IsBiggerThan( (int)n0 ); }
template <int M> inline bool operator<( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return n0.Represent() < n1.Represent(); }


template <int M> inline bool operator<=( const Mod<M>& n0 , const int& n1 ) noexcept { return !( n1 < n0 ); }
template <int M> inline bool operator<=( const int& n0 , const Mod<M>& n1 ) noexcept { return !( n1 < n0 ); }
template <int M> inline bool operator<=( const Mod<M>& n0 , const uint& n1 ) noexcept { return !( n1 < n0 ); }
template <int M> inline bool operator<=( const uint& n0 , const Mod<M>& n1 ) noexcept { return !( n1 < n0 ); }
template <int M> inline bool operator<=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return !( n1 < n0 ); }

template <int M> inline bool operator>( const Mod<M>& n0 , const int& n1 ) noexcept { return n1 < n0; }
template <int M> inline bool operator>( const int& n0 , const Mod<M>& n1 ) noexcept { return n1 < n0; }
template <int M> inline bool operator>( const Mod<M>& n0 , const uint& n1 ) noexcept { return n1 < n0; }
template <int M> inline bool operator>( const uint& n0 , const Mod<M>& n1 ) noexcept { return n1 < n0; }
template <int M> inline bool operator>( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return n1 < n0; }

template <int M> inline bool operator>=( const Mod<M>& n0 , const int& n1 ) noexcept { return !( n0 < n1 ); }
template <int M> inline bool operator>=( const int& n0 , const Mod<M>& n1 ) noexcept { return !( n0 < n1 ); }
template <int M> inline bool operator>=( const Mod<M>& n0 , const uint& n1 ) noexcept { return !( n0 < n1 ); }
template <int M> inline bool operator>=( const uint& n0 , const Mod<M>& n1 ) noexcept { return !( n0 < n1 ); }
template <int M> inline bool operator>=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return !( n0 < n1 ); }

template <int M>
Mod<M> operator+( const Mod<M>& n0 , const int& n1 ) noexcept
{

  auto n = n0;
  n += n1;
  return n;

}

template <int M>
Mod<M> operator+( const Mod<M>& n0 , const uint& n1 ) noexcept
{

  auto n = n0;
  n += n1;
  return n;

}

template <int M>
Mod<M> operator+( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept
{

  auto n = n0;
  n += n1;
  return n;

}

template <int M>
Mod<M> operator-( const Mod<M>& n0 , const int& n1 ) noexcept
{

  auto n = n0;
  n -= n1;
  return n;

}

template <int M>
Mod<M> operator-( const Mod<M>& n0 , const uint& n1 ) noexcept
{

  auto n = n0;
  n -= n1;
  return n;

}

template <int M>
Mod<M> operator-( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept
{

  auto n = n0;
  n -= n1;
  return n;

}

template <int M>
Mod<M> operator*( const Mod<M>& n0 , const int& n1 ) noexcept
{

  auto n = n0;
  n *= n1;
  return n;

}

template <int M>
Mod<M> operator*( const Mod<M>& n0 , const uint& n1 ) noexcept
{

  auto n = n0;
  n *= n1;
  return n;

}

template <int M>
Mod<M> operator*( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept
{

  auto n = n0;
  n *= n1;
  return n;

}

template <int M>
Mod<M> operator/( const Mod<M>& n0 , const int& n1 )
{

  auto n = n0;
  n /= n1;
  return n;

}

template <int M>
Mod<M> operator/( const Mod<M>& n0 , const uint& n1 )
{

  auto n = n0;
  n /= n1;
  return n;

}

template <int M>
Mod<M> operator/( const Mod<M>& n0 , const Mod<M>& n1 )
{

  auto n = n0;
  n /= n1;
  return n;

}

template <int M>
Mod<M> operator%( const Mod<M>& n0 , const int& n1 )
{

  auto n = n0;
  n %= n1;
  return n;

}

template <int M>
Mod<M> operator%( const Mod<M>& n0 , const uint& n1 )
{

  auto n = n0;
  n %= n1;
  return n;

}

template <int M>
Mod<M> operator%( const Mod<M>& n0 , const Mod<M>& n1 )
{

  auto n = n0;
  n %= n1;
  return n;

}

template <int M>
Mod<M> Inverse( const Mod<M>& n )
{

  auto n_copy = n;
  n_copy.Invert();
  return n_copy;

}

template <int M>
Mod<M> Power( const Mod<M>& n , const int& p )
{

  auto n_copy = n;
  n_copy.Power( p );
  return n_copy;

}
