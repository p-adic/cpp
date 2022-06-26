// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Power/a_Body.hpp"

template <INT_TYPE_FOR_MOD M>
INT_TYPE_FOR_MOD Mod<M>::Residue( const INT_TYPE_FOR_MOD& n ) noexcept
{

  if( M == 0 ){

    return 0;

  }

  const INT_TYPE_FOR_MOD M_abs = ( M >= 0 ? M : -M );

  if( n < 0 ){

    const INT_TYPE_FOR_MOD n_abs = -n;
    const INT_TYPE_FOR_MOD res = n_abs % M_abs;

    if( res == 0 ){

      return 0;

    }
    
    return M_abs - res;

  }

  return n % M_abs;

}

template <INT_TYPE_FOR_MOD M>
Mod<M>::Mod() noexcept : m_n( 0 ) , m_inv( M ){}

template <INT_TYPE_FOR_MOD M>
Mod<M>::Mod( const INT_TYPE_FOR_MOD& n ) noexcept : m_n( Residue( n ) ) , m_inv( 0 ){}

template <INT_TYPE_FOR_MOD M>
Mod<M>::Mod( const Mod<M>& n ) noexcept : m_n( n.m_n ) , m_inv( 0 ){}

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator=( const INT_TYPE_FOR_MOD& n ) noexcept { return operator=( Mod<M>( n ) ); }

template <INT_TYPE_FOR_MOD M>
Mod<M>& Mod<M>::operator=( const Mod<M>& n ) noexcept
{

  m_n = n.m_n;
  m_inv = n.m_inv;
  return *this;

}

template <INT_TYPE_FOR_MOD M>
Mod<M>& Mod<M>::operator+=( const INT_TYPE_FOR_MOD& n ) noexcept
{

  m_n = Residue( m_n + n );
  m_inv = 0;
  return *this;

}

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator+=( const Mod<M>& n ) noexcept { return operator+=( n.m_n ); };

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator-=( const INT_TYPE_FOR_MOD& n ) noexcept { return operator+=( -n ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator-=( const Mod<M>& n ) noexcept { return operator-=( n.m_n ); }

template <INT_TYPE_FOR_MOD M>
Mod<M>& Mod<M>::operator*=( const INT_TYPE_FOR_MOD& n ) noexcept
{

  m_n = Residue( m_n * n );
  m_inv = 0;
  return *this;

}

template <INT_TYPE_FOR_MOD M>
Mod<M>& Mod<M>::operator*=( const Mod<M>& n ) noexcept
{

  m_n = Residue( m_n * n.m_n );

  if( m_inv == 0 || n.m_inv == 0 ){

    m_inv = 0;
    
  } else if( m_inv == M || n.m_inv == M ){

    m_inv = M;
    
  } else {

    Residue( m_inv * n.m_inv );

  }
  
  return *this;

}

// âºëzä÷êîÇ»ÇÃÇ≈inlineéwíËÇµÇ»Ç¢ÅB
template <INT_TYPE_FOR_MOD M>
Mod<M>& Mod<M>::operator/=( const INT_TYPE_FOR_MOD& n )
{

  return operator/=( Mod<M>( n ) );

}

template <INT_TYPE_FOR_MOD M>
Mod<M>& Mod<M>::operator/=( const Mod<M>& n )
{
  
  return operator*=( Inverse( n ) );
  
}

template <INT_TYPE_FOR_MOD M>
Mod<M>& Mod<M>::operator%=( const INT_TYPE_FOR_MOD& n )
{

  m_n %= Residue( n );
  m_inv = 0;
  return *this;

}

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator%=( const Mod<M>& n ) { return operator%=( n.m_n ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator++() noexcept { return operator+=( 1 ); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator++( int ) noexcept { return operator++(); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator--() noexcept { return operator-=( 1 ); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator--( int ) noexcept { return operator-=(); }

template <INT_TYPE_FOR_MOD M> inline const INT_TYPE_FOR_MOD& Mod<M>::Represent() const noexcept { return m_n; }

template <INT_TYPE_FOR_MOD M>
void Mod<M>::Invert() noexcept
{

  if( CheckInvertible() ){

    INT_TYPE_FOR_MOD i = m_inv;
    m_inv = m_n;
    m_n = i;

  } else {

    m_n = 0;

  }

  return;
  
}

template <INT_TYPE_FOR_MOD M>
bool Mod<M>::CheckInvertible() noexcept
{

  if( m_inv == 0 ){

    for( INT_TYPE_FOR_MOD i = 1 ; i < M ; i++ ){

      if( Residue( m_n * i ) == 1 ){

	m_inv = i;
	return true;
      
      }

    }

    m_inv = M;

  }

  return m_inv != M;
  
}

template <INT_TYPE_FOR_MOD M> inline bool Mod<M>::IsSmallerThan( const INT_TYPE_FOR_MOD& n ) const noexcept { return m_n < Residue( n ); }
template <INT_TYPE_FOR_MOD M> inline bool Mod<M>::IsBiggerThan( const INT_TYPE_FOR_MOD& n ) const noexcept { return m_n > Residue( n ); }

template <INT_TYPE_FOR_MOD M> inline bool operator==( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return n0 == Mod<M>( n1 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator==( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return Mod<M>( n0 ) == n0; }
template <INT_TYPE_FOR_MOD M> inline bool operator==( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return n0.Represent() == n1.Represent(); }

template <INT_TYPE_FOR_MOD M> inline bool operator!=( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return !( n0 == n1 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator!=( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return !( n0 == n1 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator!=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return !( n0 == n1 ); }

template <INT_TYPE_FOR_MOD M> inline bool operator<( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return n0.IsSmallerThan( n1 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator<( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return n1.IsBiggerThan( n0 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator<( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return n0.Represent() < n1.Represent(); }

template <INT_TYPE_FOR_MOD M> inline bool operator<=( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return !( n1 < n0 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator<=( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return !( n1 < n0 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator<=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return !( n1 < n0 ); }

template <INT_TYPE_FOR_MOD M> inline bool operator>( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return n1 < n0; }
template <INT_TYPE_FOR_MOD M> inline bool operator>( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return n1 < n0; }
template <INT_TYPE_FOR_MOD M> inline bool operator>( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return n1 < n0; }

template <INT_TYPE_FOR_MOD M> inline bool operator>=( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return !( n0 < n1 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator>=( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return !( n0 < n1 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator>=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return !( n0 < n1 ); }

template <INT_TYPE_FOR_MOD M>
Mod<M> operator+( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept
{

  auto n = n0;
  n += n1;
  return n;

}

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator+( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return n1 + n0; }

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator+( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return n0 + n1.Represent(); }

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator-( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return n0 + ( -n1 ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator-( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return Mod<M>( n0 - n1.Represent() ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator-( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return n0 - n1.Represent(); }

template <INT_TYPE_FOR_MOD M>
Mod<M> operator*( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept
{

  auto n = n0;
  n *= n1;
  return n;

}

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator*( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return n1 * n0; }

template <INT_TYPE_FOR_MOD M>
Mod<M> operator*( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept
{

  auto n = n0;
  n *= n1;
  return n;

}

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator/( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) { return n0 / Mod<M>( n1 ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator/( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) { return Mod<M>( n0 ) / n1; }

template <INT_TYPE_FOR_MOD M>
Mod<M> operator/( const Mod<M>& n0 , const Mod<M>& n1 )
{

  auto n = n0;
  n /= n1;
  return n;

}

template <INT_TYPE_FOR_MOD M>
Mod<M> operator%( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 )
{

  auto n = n0;
  n %= n1;
  return n;

}

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator%( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) { return Mod<M>( n0 ) % n1.Represent(); }

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator%( const Mod<M>& n0 , const Mod<M>& n1 ) { return n0 % n1.Represent(); }

template <INT_TYPE_FOR_MOD M>
Mod<M> Inverse( const Mod<M>& n )
{

  auto n_copy = n;
  n_copy.Invert();
  return n_copy;

}

template <INT_TYPE_FOR_MOD M>
Mod<M> Power( const Mod<M>& n , const INT_TYPE_FOR_MOD& p , const bool& is_binary_method )
{

  if( p >= 0 ){

    return Power<Mod<M>,INT_TYPE_FOR_MOD>( n , p , 1 , true , true , is_binary_method );

  }

  return Inverse( Power( n , -p , is_binary_method ) );

}

template <INT_TYPE_FOR_MOD M> inline Mod<M> Power( const Mod<M>& n , const Mod<M>& p , const bool& is_binary_method ) { return Power( n , p.Represent() , is_binary_method ); }
